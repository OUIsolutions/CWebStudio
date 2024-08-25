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
    actions.alert(bridge,"you clicked in the button");
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
    CWebHyDrationBridge *alert_bridge = bridge_module.create_bridge(
        hydration,
        ALERT_BRIDGE,
        alert_bridge_callback
    );
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
    server.single_process = true;
    cweb.server.start(&server);
}
