
#include "src/one.c"

CwebNamespace cweb;
CTextStackModule stack;
CWebHydrationNamespace hydration_module;
CWebHydrationBridgeNamespace bridge_module;
CWebHydrationActionsNamespace actions;
CWebHydrationSearchRequirementsNamespace requirements;
CWebHydrationSearchResultNamespace result_module;
CWebHydrationArgsNamespace hydration_args;

#define NUM_MODIFIER "nummodifier"


//components
void create_num_element(CTextStack *s, int value){
    CTextScope_format(s,CTEXT_H1,"id='num'"){
        stack.format(s,"%d",value);
    }
}

void num_modifier_bridge_callback(CWebHyDrationBridge * bridge){

    long num = result_module.get_long_from_first_element_of_search(bridge,"num");
    long num_to_increment = hydration_args.get_long_arg(bridge,0);
    //means some information were not provided or its with the
    //wrong type
    if(bridge_module.has_errors(bridge)){
        return;
    }

    long result = num + num_to_increment;
    CTextStack * created = bridge_module.create_stack(bridge);
    create_num_element(created, result);
    actions.replace_element_by_id(bridge,"num",created->rendered_text);
}



CTextStack *create_main_page(CWebHyDration *hydration){

    CTextStack  *main_html =  hydration_module.create_stack(hydration);

    CTextScope(main_html, CTEXT_HTML){
        CTextScope(main_html, CTEXT_HEAD){
            CTextScope(main_html, CTEXT_HEAD){}
        }
        CTextScope(main_html, CTEXT_BODY){

            CWebHyDrationBridge *num_modifier = bridge_module.get_child_bridge(
                hydration,NUM_MODIFIER
            );
            create_num_element(main_html, 0);

            CTextScope(main_html, CTEXT_BR){}

            CTextScope_format(main_html,CTEXT_BUTTON,
                bridge_module.onclick(num_modifier,"%d",-1)
            ){
                stack.text(main_html,"decrement");
            }

            CTextScope_format(main_html,CTEXT_BUTTON,
                bridge_module.onclick(num_modifier,"%d",1)
            ){
                stack.text(main_html,"increment");
            }

            //always ut the script on booton of  html
            CTextScope(main_html, CTEXT_SCRIPT){
                char *script_generation = hydration_module.create_script(hydration);
                stack.text(main_html,script_generation);
            }
        }
    }
    return main_html;
}

CwebHttpResponse *main_server(CwebHttpRequest *request){

    CWebHyDration *hydration = hydration_module.newCWebHyDration(request);
    CWebHyDrationBridge * num_bridge = bridge_module.create_bridge(
        hydration,
        NUM_MODIFIER,
        num_modifier_bridge_callback
    );

    requirements.add_elements_by_id_setting_search_as_same_name(num_bridge,"num");

    //if is
    if(hydration_module.is_the_trigger(hydration)){
        return hydration_module.generate_response(hydration);
    }

    CTextStack  *page =  create_main_page(hydration);
    return cweb.response.send_rendered_CTextStack(page,200);
}


int main(){

    cweb = newCwebNamespace();
    stack = newCTextStackModule();
    hydration_module = cweb.hydration;
    bridge_module = hydration_module.bridge;
    requirements = hydration_module.search_requirements;
    result_module  = hydration_module.search_result;
    hydration_args = hydration_module.args;
    actions = hydration_module.actions;
    CwebServer server = newCwebSever(3000, main_server);
    cweb.server.start(&server);
}
