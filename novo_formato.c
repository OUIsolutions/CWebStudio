
#include "src/one.c"


CwebNamespace cweb;
CTextStackModule stack;


void  gatilho_set_num(CWebHyDrationBridge *ponte){
    long num = cweb.hydration.body.read_long(ponte,"num");
    long value = cweb.hydration.args.read_long(ponte,0);
    CWebHydrationHandleErrors(ponte);
    CTextStack * text = newCTextStack(CTEXT_LINE_BREAKER,CTEXT_SEPARATOR);
    CText$Scope(text,CTEXT_H3,"id='num'"){
        stack.format(text,"%d",num + value);
    }
    cweb.hydration.replace_element_by_id_with_ctext_stack_cleaning_memory(ponte,"num",text);
}


CwebHttpResponse *pagina_principal(CwebHttpRequest *request,CWebHyDration *hydration,CWebHyDrationBridge *set_num){
    CTextStack * text = stack.newStack(CTEXT_LINE_BREAKER,CTEXT_SEPARATOR);
    CTextScope(text,CTEXT_BODY){

        CTextScope(text,CTEXT_SCRIPT) {
           stack.format(text,cweb.hydration.create_script(hydration));
        }

        CText$Scope(text,CTEXT_H3,"id='num'"){
            stack.text(text,"0");
        }

        CText$Scope(text,CTEXT_BUTTON,"onclick='%s'",
                cweb.hydration.call(set_num,"1")
        ){
             stack.text(text,"increment");
        }
        CText$Scope(text,CTEXT_BUTTON,"onclick='%s'",cweb.hydration.call(set_num,"-1")){
            stack.text(text,"decrement");
        }
    }
    return  cweb.response.send_rendered_CTextStack_cleaning_memory(text,200);
}

CwebHttpResponse *main_sever(CwebHttpRequest *request) {

    if(strcmp(request->route, "/termina") == 0){
        cweb_kill_single_process_server();
        return cweb_send_text("app terminado",200);
    }

    CWebHyDration *hydration = cweb.hydration.newHyDration(request);
    CWebHyDrationBridge *ponte_set_num = cweb.hydration.create_bridge(hydration,gatilho_set_num,"set num ");
    cweb.hydration.request_number_text_content_by_id(ponte_set_num, "num");
    CWebHydrationHandleTriggers(hydration);


    return pagina_principal(request,hydration,ponte_set_num);

}


int main(int argc, char *argv[]){


    cweb = newCwebNamespace();
    stack = newCTextStackModule();

    CwebServer server = newCwebSever(3000, main_sever);
    cweb.server.start(&server);
    return 0;

}
