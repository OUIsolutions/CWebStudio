#include "src/one.c"

CwebNamespace cweb;
CTextStackModule stack;



void  ponte_de_login(CWebHyDrationBridge *ponte){

  CWebHyDrationSearchResult  * nome = cweb.hydration.search_result.get_search_by_name(ponte, "nome");//pegando por id
  const char *nome_str = cweb.hydration.search_result.get_string(nome,1);

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

      CText$Scope(email_error_msg,"h4","id='erro_email' style='color:red;'"){
          stack.text(email_error_msg,"email não é válido");
      }
      cweb.hydration.actions.replace_element_by_id(ponte,"erro_email",email_error_msg->rendered_text);
      email_em_erro = true;
  }


  bool senha_em_erro = false;
  if(!senha_em_erro){
      if(strcmp(senha_str, senha_repetida_str) != 0){
          CTextStack *erro_senhas_diferenes =  stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
          UniversalGarbage_add(garbage, stack.free,erro_senhas_diferenes);

          CText$Scope(erro_senhas_diferenes,"h4","id='erro_senha' style='color:red;'"){
              stack.text(erro_senhas_diferenes,"sehas não correspondem");
          }
          cweb.hydration.actions.replace_element_by_id(ponte,"erro_senha",erro_senhas_diferenes->rendered_text);
          senha_em_erro  = true;
      }
  }

  if(!senha_em_erro){
      if(strcmp(senha_str,"")==0 ||strcmp(senha_repetida_str,"")==0  ){
          CTextStack *erro_senhas_diferenes =  stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
          UniversalGarbage_add(garbage, stack.free,erro_senhas_diferenes);

          CText$Scope(erro_senhas_diferenes,"h4","id='erro_senha' style='color:red;'"){
              stack.text(erro_senhas_diferenes,"sehas não pode ser vazia");
          }
          cweb.hydration.actions.replace_element_by_id(ponte,"erro_senha",erro_senhas_diferenes->rendered_text);
          senha_em_erro  = true;
      }
  }

  if(!email_em_erro){
      cweb.hydration.actions.hide_element_by_id(ponte,"erro_email");
  }
  if(!senha_em_erro){
      cweb.hydration.actions.hide_element_by_id(ponte,"erro_senha");
  }

  if(!email_em_erro && !senha_em_erro){
      cweb.hydration.actions.alert(ponte,"%s foi cadastrado no sistema",nome_str);
  }


  stack.free(text);
}

CwebHttpResponse *pagina_principal(CwebHttpRequest *request,CWebHyDration *hydration,CWebHyDrationBridge *ponte_de_login_obj){
    CTextStack * text = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    CTextScope(text,CTEXT_BODY){
        CText$Scope(text, "script", "src='/hydration_script'");
        //CWebHyDrationBridge_onfoccusout

        CTextScope(text, "h4"){
            stack.text(text, "digite seu nome:");
        }
        CText$Scope(text, "input", " id='nome'");

        CTextScope(text, "h4"){
            stack.text(text, "digite seu email:");
        }
        CText$Scope(text, "input", " id='email'");
        CText$Scope(text,"h4","id='erro_email' style='color:red;display:none;'")

        CTextScope(text, "h4"){
            stack.text(text, "digite uma senha");
        }

        CTextScope(text, "br");

        CText$Scope(text, "input", "type='password' id='senha'");
        CTextScope(text, "h4"){
            stack.text(text, "repita a senha");
        }

        CText$Scope(text, "input", "type='password' id='repita_senha'");
        CTextScope(text, "br");

        CText$Scope(text,"h4","id='erro_senha' style='color:red;display:none;'")

        CTextScope(text, "br");

        CText$Scope(text, "button", cweb.hydration.bridge.onclick(ponte_de_login_obj,NULL)){
            stack.text(text,"validar ");
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
    CWebHyDrationBridge *ponte_de_login_obj = cweb.hydration.bridge.create_bridge(
        hydration, "ponte de login "
        , ponte_de_login
    );
    CWebHyDrationSearchRequirements *nome = cweb.hydration.search_requirements.newSearchRequirements(
        ponte_de_login_obj,"nome");
    cweb.hydration.search_requirements.add_elements_by_id(nome,"nome");

    CWebHyDrationSearchRequirements *email = cweb.hydration.search_requirements.newSearchRequirements(
        ponte_de_login_obj,"email");
    cweb.hydration.search_requirements.add_elements_by_id(email,"email");


    CWebHyDrationSearchRequirements *senha = cweb.hydration.search_requirements.newSearchRequirements(
        ponte_de_login_obj,"senha");
    cweb.hydration.search_requirements.add_elements_by_id(senha,"senha");

    CWebHyDrationSearchRequirements *repita_senha = cweb.hydration.search_requirements.newSearchRequirements(
        ponte_de_login_obj,"repita_senha");
    cweb.hydration.search_requirements.add_elements_by_id(repita_senha,"repita_senha");



    CWebHydrationHandleTriggers(hydration);

    if(strcmp(request->route,"/hydration_script") == 0){
        return cweb.response.send_text(cweb.hydration.create_script(hydration),200);
    }
    return pagina_principal(request,hydration,ponte_de_login_obj);

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
