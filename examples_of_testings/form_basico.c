#include "../src/one.c"

CwebNamespace cweb;
CTextStackModule stack;



void  ponte_de_login(CWebHyDrationBridge *ponte){

    //cweb.hydration.actions.redirect(ponte, "google.com");

    //return;

  CWebHyDrationSearchResult  * nome = cweb.hydration.search_result.get_search_by_name(ponte, "nome");//pegando por id
  const char *nome_str = cweb.hydration.search_result.get_string(nome,0);

    printf("\n\t%s\n\n", nome_str);

  CWebHyDrationSearchResult  * email = cweb.hydration.search_result.get_search_by_name(ponte, "email");
  const char *email_str = cweb.hydration.search_result.get_string(email,0);

  CWebHyDrationSearchResult  * senha = cweb.hydration.search_result.get_search_by_name(ponte, "senha");
  const char *senha_str = cweb.hydration.search_result.get_string(senha,0);

  CWebHyDrationSearchResult  * senha_repetida = cweb.hydration.search_result.get_search_by_name(ponte, "repita_senha");
  const char *senha_repetida_str = cweb.hydration.search_result.get_string(senha_repetida,0);
  CWebHydrationHandleErrors(ponte);

  UniversalGarbage *garbage = newUniversalGarbage();
  CTextStack * text = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

  CTextStack * email_parseado = stack.newStack_string(email_str);
  UniversalGarbage_add(garbage, stack.free,email_parseado);
  bool email_em_erro = false;
  if(stack.index_of(email_parseado,"@") == -1){

      CTextStack *email_error_msg =  stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
      UniversalGarbage_add(garbage, stack.free,email_error_msg);

      CTextScope_format(email_error_msg,"h4","id='erro_email' style='color:red;'"){
          stack.text(email_error_msg,"email não é válido");
      }
      cweb.hydration.actions.replace_element_by_id(ponte,"erro_email",email_error_msg->rendered_text);
      email_em_erro = true;
  }



}


CwebHttpResponse *pagina_principal(
    CwebHttpRequest *request,
    CWebHyDration *hydration,
    CWebHyDrationBridge *ponte_adiciona_obj
){
    CTextStack * text = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    CTextScope(text,CTEXT_BODY){
        CTextScope_format(text, "script", "src='/hydration_script'");
        //CWebHyDrationBridge_onfoccusout
        CTextScope_format(text,"div", "id='base'"){

        }
        CTextScope_format(text,"button",cweb.hydration.bridge.onclick(ponte_adiciona_obj,NULL));

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
        hydration,
        "ponte de login ",
        ponte_de_login
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
