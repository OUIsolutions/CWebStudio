#include "CWebStudioOne.c"

#define ALERT_BRIDGE "alert"

void alert_bridge_callback(CWebHyDrationBridge *bridge){
    CWebHyDrationBridge_alert(bridge, "you clicked in the button");
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
            CWebHyDrationBridge *alert_bridge = CWebHyDration_get_child_bridge(hydration, ALERT_BRIDGE);

            CTextScope_format(main_html, CTEXT_BUTTON, CWebHyDrationBridge_onclick(alert_bridge, NULL)){
                CTextStack_text(main_html, "click me");
            }
        }
    }
    return main_html;
}

CwebHttpResponse *main_server(CwebHttpRequest *request){
    CWebHyDration *hydration = newCWebHyDration(request);
    CWebHyDrationBridge *alert_bridge = CWebHyDration_create_bridge(hydration, ALERT_BRIDGE, alert_bridge_callback);
    
    if(CWebHyDration_is_the_trigger(hydration)){
        return CWebHydration_generate_response(hydration);
    }

    CTextStack *page = create_main_page(hydration);
    return cweb_send_rendered_CTextStack(page, 200);
}

int main(){
    CwebServer server = newCwebSever(3000, main_server);
    server.single_process = true;
    CwebServer_start(&server);
    return 0;
}