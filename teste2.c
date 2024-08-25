
#include "CWebStudio.h"


CwebNamespace cweb;
CTextStackModule stack;

CwebHttpResponse *main_sever(CwebHttpRequest *request) {

    if(strcmp(request->route, "/termina") == 0){
        cweb_kill_single_process_server();
        return cweb_send_text("app terminado",200);
    }

    CWebHyDration *hydration = cweb.hydration.newHyDration(request);
    CWebHyDrationBridge *set_num = cweb.hydration.create_bridge(hydration,"/set_num",NULL);
    cweb.hydration.request_number_text_content_by_id(set_num, "num");

    if(cweb.hydration.is_the_route(set_num)) {

        long num = cweb.hydration.read_long(set_num,"num");
        long value = cweb.hydration.read_long(set_num,"args0");

        if(cweb.hydration.error(set_num)){
            CwebHttpResponse *response = cweb.hydration.generate_error_response(set_num);
            return response;
        }

        CTextStack * text = newCTextStack(CTEXT_LINE_BREAKER,CTEXT_SEPARATOR);
        CText$Scope(text,CTEXT_H3,"id='num'"){
            stack.format(text,"%d",num + value);
        }

        cweb.hydration.replace_element_by_id_with_ctext_stack_cleaning_memory(set_num,"num",text);

        CwebHttpResponse *response = cweb.hydration.generate_response(set_num);
        return response;
    }


    CTextStack * text = stack.newStack(CTEXT_LINE_BREAKER,CTEXT_SEPARATOR);
    CTextScope(text,CTEXT_BODY){
        CTextScope(text,CTEXT_SCRIPT) {
           stack.format(text,cweb.hydration.create_script(hydration));
        }
        CText$Scope(text,CTEXT_H3,"id='num'"){
            stack.text(text,"0");
        }
        CText$Scope(text,CTEXT_BUTTON,"onclick='%s'",cweb.hydration.call(set_num,"1")){
             stack.text(text,"increment");
        }

        CText$Scope(text,CTEXT_BUTTON,"onclick='%s'",cweb.hydration.call(set_num,"-1")){
            stack.text(text,"decrement");
        }


    }
    return  cweb.response.send_rendered_CTextStack_cleaning_memory(text,200);
}


int main(int argc, char *argv[]){


    cweb = newCwebNamespace();
    stack = newCTextStackModule();

    CwebServer server = newCwebSever(3004, main_sever);
    cweb.server.start(&server);
    return 0;

}
