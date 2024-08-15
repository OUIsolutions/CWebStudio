
#include "src/dependencies/declaration.h"
#include "src/functions/declarations.h"
#include "src/one.c"
#include "src/types/string_array.h"
#include <string.h>


CwebNamespace cweb;
CTextStackModule stack;


void  gatilho_set_num(CWebHyDrationBridge *ponte){
    long num = cweb.hydration.content.read_long(ponte,"num");
    long value = cweb.hydration.args.read_long(ponte,0);
    CWebHydrationHandleErrors(ponte);
    CTextStack * text = newCTextStack(CTEXT_LINE_BREAKER,CTEXT_SEPARATOR);
    CText$Scope(text,CTEXT_H3,"id='num'"){
        stack.format(text,"%d",num + value);
    }
    cweb.hydration.response.replace_element_by_id(ponte,"num",text->rendered_text);
    stack.free(text);
}


CwebHttpResponse *pagina_principal(CwebHttpRequest *request,CWebHyDration *hydration,CWebHyDrationBridge *set_num){
    CTextStack * text = stack.newStack(CTEXT_LINE_BREAKER,CTEXT_SEPARATOR);
    CTextScope(text,CTEXT_BODY){


        CText$Scope(text,CTEXT_H3,"id='num'"){
            stack.text(text,"0");
        }
        CText$Scope(text, CTEXT_SCRIPT,"src='hydration_script'");

        CText$Scope(text,CTEXT_BUTTON,"onclick='%s'",
                cweb.hydration.call(set_num,"1")
        ){
             stack.text(text,"increment");
        }
        CText$Scope(text,CTEXT_BUTTON,"onclick='%s'",cweb.hydration.call(set_num,"-1")){
            stack.text(text,"decrement");
        }
    }
    //CwebStringArray_add;
    return  cweb.response.send_rendered_CTextStack_cleaning_memory(text,200);
}

CwebHttpResponse *main_sever(CwebHttpRequest *request) {

    if(strcmp(request->route, "/termina") == 0){
        cweb_kill_single_process_server();
        return cweb_send_text("app terminado",200);
    }

    CWebHyDration *hydration = cweb.hydration.newCWebHyDration(request);
    CWebHyDrationBridge *ponte_set_num = cweb.hydration.create_bridge(hydration, "set num ",gatilho_set_num);
    //precisa desse id
    cweb.hydration.requirements.add_required_text_number_by_id(ponte_set_num, "num");
    CWebHydrationHandleTriggers(hydration);

    if(strcmp(request->route,"/hydration_script") == 0){
        return cweb.response.send_text(cweb.hydration.create_script(hydration),200);
    }
    return pagina_principal(request,hydration,ponte_set_num);

}


int main(int argc, char *argv[]){


    cweb = newCwebNamespace();
    stack = newCTextStackModule();

    CwebServer server = newCwebSever(3001, main_sever);
    server.single_process = true;
    cweb.server.start(&server);
    return 0;

}
