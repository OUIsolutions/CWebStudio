## Full Runnable Example

```c

#include "CWebStudioOne.c"

#define ALERT_BRIDGE "alert"

void alert_bridge_callback(CWebHyDrationBridge * bridge){
    CWebHyDrationSearchResult * name = CWebHyDrationBridge_get_search_by_name(bridge, "name");
    char *first_result_of_name = CWebHyDrationSearchResult_get_string(name, 0);

    //means some information were not provided or it's with the
    //wrong type
    if(CWebHyDrationBridge_has_errors(bridge)){
        return;
    }
    bool name_its_empty = strcmp(first_result_of_name, "") == 0;
    bool name_its_filled = !name_its_empty;
    if(name_its_empty){
        CWebHyDrationBridge_alert(bridge, "you did not typed your name");
    }
    if(name_its_filled){
        CWebHyDrationBridge_alert(bridge, "hello %s", first_result_of_name);
    }
}

CTextStack *create_main_page(CWebHyDration *hydration){
    CTextStack *main_html = CWebHyDration_create_stack(hydration);

    CTextScope(main_html, CTEXT_HTML){
        CTextScope(main_html, CTEXT_HEAD){
            CTextScope(main_html, CTEXT_HEAD){
                CTextScope(main_html, CTEXT_SCRIPT){
                    char *script_generation = CWebHyDration_create_script(hydration);
                    CTextStack_text(main_html, script_generation);
                }
            }
        }
        CTextScope(main_html, CTEXT_BODY){
            CWebHyDrationBridge *alert_bridge = CWebHyDration_get_child_bridge(
                hydration, ALERT_BRIDGE
            );
            CTextScope_format(main_html, CTEXT_INPUT, " placeholder='type your name' id='name'");
            CTextScope(main_html, CTEXT_BR){}
            CTextScope_format(main_html, CTEXT_BUTTON,
                CWebHyDrationBridge_onclick(alert_bridge, NULL)
            ){
                CTextStack_text(main_html, "click me");
            }
        }
    }
    return main_html;
}

CwebHttpResponse *main_server(CwebHttpRequest *request){
    CWebHyDration *hydration = newCWebHyDration(request);
    CWebHyDrationBridge *alert_bridge = CWebHyDration_create_bridge(
        hydration,
        ALERT_BRIDGE,
        alert_bridge_callback
    );

    CWebHyDrationSearchRequirements *name = CWebHyDrationBridge_newSearchRequirements(alert_bridge, "name");
    CWebHyDrationBridge_add_elements_by_id_setting_search_as_same_name(alert_bridge, "name");

    //if is
    if(CWebHyDration_is_the_trigger(hydration)){
        return CWebHyDration_generate_response(hydration);
    }

    CTextStack *page = create_main_page(hydration);
    return cweb_send_rendered_CTextStack(page, 200);
}

int main(){
    CwebServer server = newCwebSever(3000, main_server);
    CwebServer_start(&server);
}

```

This example demonstrates a full runnable example of using HyDration.