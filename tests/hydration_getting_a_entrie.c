
#include "../CWebStudio.h"


CwebNamespace cweb;
CTextStackModule stack;
CWebHydrationNamespace hydration_module;
CWebHydrationBridgeNamespace bridge_module;
CWebHydrationActionsNamespace actions;
CWebHydrationSearchRequirementsNamespace requirements;
CWebHydrationSearchResultNamespace result_module;
CWebHydrationArgsNamespace hydration_args;

#define ALERT_BRIDGE "alert"


void alert_bridge_callback(CWebHyDrationBridge * bridge){
    CWebHyDrationSearchResult * name = result_module.get_search_by_name(bridge,"name");
    char *first_result_of_name = result_module.get_string(name,0);

    //means some information were not provided or its with the
    //wrong type
    if(bridge_module.has_errors(bridge)){
        return;
    }
    bool name_its_empty =strcmp(first_result_of_name,"") ==0;
    bool name_its_filled = !name_its_empty;
    if(name_its_empty){
        actions.alert(bridge,"you did not typed your name");
    }
    if(name_its_filled){
        actions.alert(bridge,"hello %s",first_result_of_name);

    }
}


CTextStack *create_main_page(CWebHyDration *hydration){

    CTextStack  *main_html =  hydration_module.create_stack(hydration);

    CTextScope(main_html, CTEXT_HTML){
        CTextScope(main_html, CTEXT_HEAD){
            CTextScope(main_html, CTEXT_HEAD){
                CTextScope(main_html, CTEXT_SCRIPT){
                    char *script_generation = hydration_module.create_script(hydration);
                    stack.text(main_html,script_generation);
                }
            }
        }
        CTextScope(main_html, CTEXT_BODY){

            CWebHyDrationBridge *alert_bridge = bridge_module.get_child_bridge(
                hydration,ALERT_BRIDGE
            );
            CTextScope_format(main_html, CTEXT_INPUT," placeholder='type your name' id='name'")
            CTextScope(main_html, CTEXT_BR){}
            CTextScope_format(main_html,CTEXT_BUTTON,
                bridge_module.onclick(alert_bridge,NULL)
            ){
                stack.text(main_html,"click me");
            }

        }
    }
    return main_html;
}

CwebHttpResponse *main_server(CwebHttpRequest *request){

    CWebHyDration *hydration = hydration_module.newCWebHyDration(request);
    CWebHyDrationBridge * alert_bridge = bridge_module.create_bridge(
        hydration,
        ALERT_BRIDGE,
        alert_bridge_callback
    );

    CWebHyDrationSearchRequirements *name =
    requirements.newSearchRequirements(alert_bridge,"name");
    requirements.add_elements_by_id(name,"name");

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
