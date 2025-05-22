#include "CWebStudioOne.c"


#define NUM_MODIFIER "num modifier"


//components
void create_num_element(CTextStack *s, int value){
    CTextScope_format(s,CTEXT_H1,"id='num'"){
        CTextStack_format(s,"%d",value);
    }
}

void num_modifier_bridge_callback(CWebHyDrationBridge * bridge){

    long num = CWebHyDrationBridge_get_long_from_first_element_of_search(bridge,"num");
    long num_to_increment = CWebHyDrationBridge_get_long_arg(bridge,0);
    //means some information were not provided or its with the
    //wrong type
    if(CWebHyDrationBridge_has_errors(bridge)){
        return;
    }

    long result = num + num_to_increment;
    CTextStack * created = CWebHyDrationBridge_create_stack(bridge);
    create_num_element(created, result);
    CWebHyDrationBridge_replace_element_by_id(bridge,"num",created->rendered_text);
}



CTextStack *create_main_page(CWebHyDration *hydration){

    CTextStack  *main_html =  CWebHyDration_create_stack(hydration);

    CTextScope(main_html, CTEXT_HTML){
        CTextScope(main_html, CTEXT_HEAD){
            CTextScope(main_html, CTEXT_HEAD){}
        }
        CTextScope(main_html, CTEXT_BODY){

            CWebHyDrationBridge *num_modifier = CWebHyDration_get_child_bridge(
                hydration,NUM_MODIFIER
            );
            create_num_element(main_html, 0);

            CTextScope(main_html, CTEXT_BR){}

            CTextScope_format(main_html,CTEXT_BUTTON,
                CWebHyDrationBridge_onclick(num_modifier,"%d",-1)
            ){
                CTextStack_text(main_html,"decrement");
            }

            CTextScope_format(main_html,CTEXT_BUTTON,
                CWebHyDrationBridge_onclick(num_modifier,"%d",1)
            ){
                CTextStack_text(main_html,"increment");
            }

            //always put the script on bottom of html
            CTextScope(main_html, CTEXT_SCRIPT){
                char *script_generation = CWebHyDration_create_script(hydration);
                CTextStack_text(main_html,script_generation);
            }
        }
    }
    return main_html;
}

CwebHttpResponse *main_server(CwebHttpRequest *request){


    CWebHyDration *hydration = newCWebHyDration(request);
    CWebHyDrationBridge * num_bridge = CWebHyDration_create_bridge(
        hydration,
        NUM_MODIFIER,
        num_modifier_bridge_callback
    );

    CWebHyDrationBridge_add_elements_by_id_setting_search_as_same_name(num_bridge,"num");

    //if is
    if(CWebHyDration_is_the_trigger(hydration)){
        return CWebHyDration_generate_response(hydration);
    }

    CTextStack  *page =  create_main_page(hydration);
    return cweb_send_rendered_CTextStack(page,200);
}


int main(){
    CwebServer server = newCwebSever(3000, main_server);
    CwebServer_start(&server);
}