## ShortCuts

You can also use shortcuts to set the search requirements as the same name of the id/class that you want to find.

```c

#include "CWebStudioOne.c"


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
    char *first_result_of_name = result_module.get_string_from_first_element_of_search(bridge,"name");

    //means some information were not provided or it's with the
    //wrong type
    if(bridge_module.has_errors(bridge))}{
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
            CTextScope(main_html, CTEXT_HEAD){}
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

    requirements.add_elements_by_id_setting_search_as_same_name(alert_bridge,"name");

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

```

This example demonstrates how to use shortcuts in HyDration.