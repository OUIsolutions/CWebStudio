
#include "../src/one.c"

CwebNamespace cweb;
CTextStackModule stack;



void  ponte_de_adiciona(CWebHyDrationBridge *ponte){

    CTextStack * text = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    CTextScope(text, "div"){
        CTextScope(text,"h4"){
        stack.text(text,"digite um nome");
        }
        CTextScope(text,"input"){}
        CTextScope(text,"br"){}
    }

    printf("%s", text->rendered_text);
    cweb.hydration.actions.append_by_id(ponte,"element",text->rendered_text);
  stack.free(text);
}


CwebHttpResponse *pagina_principal(
    CwebHttpRequest *request,
    CWebHyDration *hydration,
    CWebHyDrationBridge *ponte_adiciona_obj){
    CTextStack * text = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    CTextScope(text,CTEXT_BODY){
        CTextScope_format(text, "script", "src='/hydration_script'");
        //CWebHyDrationBridge_onfoccusout
        CTextScope_format(text, "div","id='element'");

        CTextScope_format(text, "button",cweb.hydration.bridge.onclick(ponte_adiciona_obj, "%d, %d, \"%s\"", 1, 5, "Hello Word!")){
            stack.text(text,"adicionar item");
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
    CWebHyDrationBridge *ponte_de_adiciona_obj = cweb.hydration.bridge.create_bridge(
        hydration, "ponte adiciona "
        , ponte_de_adiciona
    );

    CWebHydrationHandleTriggers(hydration);

    if(strcmp(request->route,"/hydration_script") == 0){
        return cweb.response.send_text(cweb.hydration.create_script(hydration),200);
    }
    return pagina_principal(request,hydration,ponte_de_adiciona_obj);

}


int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    stack = newCTextStackModule();


    for(int i=3000;i < 4000;i++){
        CwebServer server = newCwebSever(i, main_sever);
        server.single_process = true;
     cweb.server.start(&server);
    }
    return 0;


}
