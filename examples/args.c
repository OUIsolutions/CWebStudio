#include "CWebStudioOne.c"

#define ARGS_BRIDGE "args"

//components
void args_bridge_callback(CWebHyDrationBridge *bridge) {
    long size = CWebHyDrationBridge_get_args_size(bridge);
    for(int i = 0; i < size; i++) {
        if(CWebHyDrationBridge_is_arg_number(bridge, i)) {
            long value = CWebHyDrationBridge_get_long_arg(bridge, i);
            printf("arg %d: %ld\n", i, value);
        }
        if(CWebHyDrationBridge_is_arg_bool(bridge, i)) {
            bool value = CWebHyDrationBridge_get_bool_arg(bridge, i);
            printf("arg %d: %s\n", i, value ? "true" : "false");
        }
        if(CWebHyDrationBridge_is_arg_string(bridge, i)) {
            char *value = CWebHyDrationBridge_get_str_arg(bridge, i);
            printf("arg %d: %s\n", i, value);
        }
        if(CWebHyDrationBridge_is_arg_null(bridge, i)) {
            printf("arg %d: NULL\n", i);
        }
    }
    printf("====================================\n");
}

CTextStack *create_main_page(CWebHyDration *hydration) {
    CTextStack *main_html = CWebHyDration_create_stack(hydration);
    CTextScope(main_html, CTEXT_HTML) {
        CTextScope(main_html, CTEXT_HEAD) {
            CTextScope(main_html, CTEXT_HEAD) {}
        }
        CTextScope(main_html, CTEXT_BODY) {
            CWebHyDrationBridge *args_bridge = CWebHyDration_get_child_bridge(hydration, ARGS_BRIDGE);
            CTextScope(main_html, CTEXT_BR) {}
            CTextScope_format(main_html, CTEXT_BUTTON, CWebHyDrationBridge_onclick(args_bridge, "10,'second argument'")) {
                CTextStack_text(main_html, "number and string");
            }
            CTextScope_format(main_html, CTEXT_BUTTON, CWebHyDrationBridge_onclick(args_bridge, "10")) {
                CTextStack_text(main_html, "number ");
            }
            CTextScope_format(main_html, CTEXT_BUTTON, CWebHyDrationBridge_onclick(args_bridge, "true")) {
                CTextStack_text(main_html, "boolean");
            }
            CTextScope_format(main_html, CTEXT_BUTTON, CWebHyDrationBridge_onclick(args_bridge, "null,'second argument'")) {
                CTextStack_text(main_html, "null and string");
            }
            //always put the script on bottom of html
            CTextScope(main_html, CTEXT_SCRIPT) {
                char *script_generation = CWebHyDration_create_script(hydration);
                CTextStack_text(main_html, script_generation);
            }
        }
    }
    return main_html;
}

CwebHttpResponse *main_server(CwebHttpRequest *request) {
    CWebHyDration *hydration = newCWebHyDration(request);
    CWebHyDrationBridge *args_bridge = CWebHyDration_create_bridge(hydration, ARGS_BRIDGE, args_bridge_callback);
    //if is
    if(CWebHyDration_is_the_trigger(hydration)) {
        return CWebHydration_generate_response(hydration);
    }
    CTextStack *page = create_main_page(hydration);
    return cweb_send_rendered_CTextStack(page, 200);
}

int main() {
    CwebServer server = newCwebSever(3000, main_server);
    CwebServer_start(&server);
    return 0;
}