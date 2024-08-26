
#include "../CWebStudio.h"


CwebNamespace cweb;
CTextStackModule stack;
CWebHydrationNamespace hydration_module;
CWebHydrationBridgeNamespace bridge_module;
CWebHydrationActionsNamespace actions;
CWebHydrationSearchRequirementsNamespace requirements;
CWebHydrationSearchResultNamespace result_module;
CWebHydrationArgsNamespace hydration_args;

#define ARGS_BRIDGE "args"


//components

void args_bridge_callback(CWebHyDrationBridge * bridge){

    long size = hydration_args.get_args_size(bridge);
    for(int i = 0; i < size;i++){

        if(hydration_args.is_arg_number(bridge,i)){
        long value = hydration_args.get_long_arg(bridge,i);
            printf("arg %d: %ld\n",i,value);
        }

        if(hydration_args.is_arg_bool(bridge,i)){
            bool value = hydration_args.get_bool_arg(bridge,i);
            printf("arg %d: %s\n",i,value ? "true":"false");
        }

        if(hydration_args.is_arg_string(bridge,i)){
            char *value = hydration_args.get_str_arg(bridge,i);
            printf("arg %d: %s\n",i,value);
        }
        if(hydration_args.is_arg_null(bridge,i)){
            printf("arg %d: NULL\n",i);
        }

    }
    printf("====================================\n");
}



CTextStack *create_main_page(CWebHyDration *hydration){

    CTextStack  *main_html =  hydration_module.create_stack(hydration);

    CTextScope(main_html, CTEXT_HTML){
        CTextScope(main_html, CTEXT_HEAD){
            CTextScope(main_html, CTEXT_HEAD){}
        }
        CTextScope(main_html, CTEXT_BODY){

            CWebHyDrationBridge *args_bridge = bridge_module.get_child_bridge(
                hydration,ARGS_BRIDGE
            );

            CTextScope(main_html, CTEXT_BR){}

            CTextScope_format(main_html,CTEXT_BUTTON,
                bridge_module.onclick(args_bridge,"10,'second argument'")
            ){
                stack.text(main_html,"number and string");
            }
            CTextScope_format(main_html,CTEXT_BUTTON,
                bridge_module.onclick(args_bridge,"10")
            ){
                stack.text(main_html,"number ");
            }

            CTextScope_format(main_html,CTEXT_BUTTON,
                bridge_module.onclick(args_bridge,"true")
            ){
                stack.text(main_html,"boolean");
            }

            CTextScope_format(main_html,CTEXT_BUTTON,
                bridge_module.onclick(args_bridge,"null,'second argument'")
            ){
                stack.text(main_html,"null and string");
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
    CWebHyDrationBridge * args_brige = bridge_module.create_bridge(
        hydration,
        ARGS_BRIDGE,
        args_bridge_callback
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
    cweb.server.start(&server);
}
