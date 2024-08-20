
#include "src/functions/declarations.h"
#include "src/one.c"

CwebNamespace cweb;
CTextStackModule stack;

void  ponte_de_validacao(CWebHyDrationBridge *ponte){

  CWebHyDrationSearchResult  * nome = cweb.hydration.search_result.get_search_by_name(ponte, "nome");
  const char *nome_str = cweb.hydration.search_result.get_string(nome,0);

  CWebHyDrationSearchResult  * email = cweb.hydration.search_result.get_search_by_name(ponte, "email");
  const char *email_str = cweb.hydration.search_result.get_string(email,0);

  CWebHyDrationSearchResult  * senha = cweb.hydration.search_result.get_search_by_name(ponte, "senha");
  const char *senha_str = cweb.hydration.search_result.get_string(senha,0);



  CWebHydrationHandleErrors(ponte);
  CTextStack * text = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

  CText$Scope(text, "h3", "id='response'"){
    stack.format(text, "Você digitou valor: %s", valor);
  }

  cweb.hydration.actions.replace_element_by_id(ponte, "response", text->rendered_text);
  cweb.hydration.actions.alert(ponte, "Msg");

  stack.free(text);
}

CwebHttpResponse *pagina_principal(CwebHttpRequest *request,CWebHyDration *hydration,CWebHyDrationBridge *imprime_texto){
    CTextStack * text = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    CTextScope(text,CTEXT_BODY){
        CText$Scope(text, "script", "src='/hydration_script'");
        //CWebHyDrationBridge_onfoccusout
        CText$Scope(text, "h4", "digite seu nome:");
        CText$Scope(text, "input", " id='nome'");
        CText$Scope(text, "h4", "digite seu email:");
        CText$Scope(text, "input", " id='email'");
        CText$Scope(text, "button", "validar");
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
    CWebHyDrationBridge *ponte_imprime = cweb.hydration.bridge.create_bridge(hydration, "set num ", ponte_imprime_texto);
    //precisa desse id

    CWebHyDrationSearchRequirements *valor =  cweb.hydration.search_requirements.newSearchRequirements(
        ponte_imprime,
        "valor"
    );
    cweb.hydration.search_requirements.add_elements_by_id(valor, "valor");

    CWebHydrationHandleTriggers(hydration);

    if(strcmp(request->route,"/hydration_script") == 0){
        return cweb.response.send_text(cweb.hydration.create_script(hydration),200);
    }
    return pagina_principal(request,hydration,ponte_imprime);

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
