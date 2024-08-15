
#include "src/one.c"

CwebNamespace cweb;
CTextStackModule stack;

void  ponte_imprime_texto(CWebHyDrationBridge *ponte){
  const char *valor = cweb.hydration.content.read_str(ponte, "valor");
  
  CWebHydrationHandleErrors(ponte);
  CTextStack * text = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

  CText$Scope(text, "h3", "id='response'"){
    stack.format(text, "Você digitou valor: %s", valor);
  }
  cweb.hydration.response.replace_element_by_id(ponte, "response", text->rendered_text);

  stack.free(text);
}

CwebHttpResponse *pagina_principal(CwebHttpRequest *request,CWebHyDration *hydration,CWebHyDrationBridge *imprime_texto){
    CTextStack * text = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    CTextScope(text,CTEXT_BODY){

        CText$Scope(text, "button", "id='valor' %s", cweb.hydration.call(imprime_texto, "onclick", NULL));
        CText$Scope(text,  "h3", "id='response'");
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
    CWebHyDrationBridge *ponte_imprime = cweb.hydration.create_bridge(hydration, "set num ", ponte_imprime_texto);
    //precisa desse id
    cweb.hydration.requirements.add_required_input_by_id(ponte_imprime, "valor");

    CWebHydrationHandleTriggers(hydration);

    if(strcmp(request->route,"/hydration_script") == 0){
        return cweb.response.send_text(cweb.hydration.create_script(hydration),200);
    }
    return pagina_principal(request,hydration,ponte_imprime);

}


int main(int argc, char *argv[]){


    cweb = newCwebNamespace();
    stack = newCTextStackModule();

    CwebServer server = newCwebSever(3001, main_sever);
    server.single_process = true;
    cweb.server.start(&server);
    return 0;

}
