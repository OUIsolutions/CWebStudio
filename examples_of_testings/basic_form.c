#include "../src/one.c"
#include <asm-generic/errno.h>


#define REPEAT_PASSWORD "repeat_password"
#define PASSWORD "password"
#define NAME "name"
#define EMAIL "email"
#define AUTENTICATION_BRIDGE "autentication bridge"
#define ERRROR_EMAIL "error_email"
#define ERROR_PASSWORD "error_password"
CwebNamespace cweb;
CTextStackModule stack;


void generate_error(CWebHyDrationBridge *bridge,const char *id, const char *message){
    CTextStack *error =  stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    CTextScope_format(error,"h4","id='erro_email' style='color:red;'"){
        stack.text(error,message);
    }
    cweb.hydration.actions.replace_element_by_id(bridge,id,error->rendered_text);
    stack.free(error);
}




void  autentication_bridge(CWebHyDrationBridge *bridge){

  CWebHyDrationSearchResult  * name =
  cweb.hydration.search_result.get_search_by_name(
      bridge, NAME
  );

  const char *name_str = cweb.hydration.search_result.get_string(name,0);
  CWebHyDrationSearchResult  * email =
  cweb.hydration.search_result.get_search_by_name(bridge, EMAIL);

  const char *email_str = cweb.hydration.search_result.get_string(email,0);

  CWebHyDrationSearchResult  * password = cweb.hydration.search_result.get_search_by_name(
      bridge, PASSWORD
  );
  const char *password_str = cweb.hydration.search_result.get_string(password,0);


  CWebHyDrationSearchResult  * repeated_password = cweb.hydration.search_result.get_search_by_name(bridge,REPEAT_PASSWORD);
  const char *repeated_password_str = cweb.hydration.search_result.get_string(repeated_password,0);
  CWebHydrationHandleErrors(bridge);


  CTextStack * parsed_email = stack.newStack_string(email_str);


  bool error_on_email = false;
  if(stack.index_of(parsed_email,"@") == -1){
      generate_error(bridge, ERRROR_EMAIL,"invalid email");
      error_on_email = true;
  }

  if(!error_on_email){
      cweb.hydration.actions.hide_element_by_id(bridge,ERRROR_EMAIL);
  }

  bool error_on_password = false;
  if(strlen(password_str) < 10){
      generate_error(bridge, ERROR_PASSWORD, "password size is lower then 10");
      error_on_password = true;
  }

  if(!error_on_password){
      if(strcmp(repeated_password_str, password_str) != 0){
          generate_error(bridge, ERROR_PASSWORD, "passwords are not equal");
          error_on_password = true;
      }

  }
  if(!error_on_password){
      cweb.hydration.actions.hide_element_by_id(bridge,"error_password");
  }

  if(!error_on_password && !error_on_email){
      cweb.hydration.actions.alert(bridge,"user subscribed");
  }

}




CwebHttpResponse *main_page(
    CwebHttpRequest *request,
    CWebHyDrationBridge *autentication_bridge
){

    CTextStack * text = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    CTextScope(text,CTEXT_HTML){
        CTextScope(text,CTEXT_HEAD){
            CTextScope_format(text, CTEXT_SCRIPT, "src='/hydration_script'");
        }

        CTextScope(text,CTEXT_BODY){
            //CWebHyDrationBridge_onfoccusout
                CTextScope(text,CTEXT_H4){
                stack.text(text,"type your name");
                }
                CTextScope_format(text,CTEXT_INPUT,"id='%s'",NAME){}

                CTextScope(text,CTEXT_H4){
                    stack.text(text,"type your name");
                }

                CTextScope_format(text,CTEXT_INPUT,"id='%s'",EMAIL){}

                CTextScope_format(text,CTEXT_H4,"id='%s' style='display:none;'",ERRROR_EMAIL){}


                CTextScope(text,CTEXT_H4){
                    stack.text(text,"type your password");
                }
                CTextScope_format(text,CTEXT_INPUT,"id='%s'",PASSWORD){}

                CTextScope(text,CTEXT_H4){
                    stack.text(text,"repeat password");
                }
                CTextScope_format(text,CTEXT_INPUT,"id='%s'",REPEAT_PASSWORD){}
                CTextScope_format(text,CTEXT_H4,"id='%s' style='display:none;'",ERROR_PASSWORD){}
                CTextScope(text,CTEXT_BR);
                CTextScope_format(text,"button",cweb.hydration.bridge.onclick(autentication_bridge,NULL)){
                    stack.text(text,"create user");
                }
        }
    }

    return  cweb.response.send_rendered_CTextStack_cleaning_memory(text,200);
}
CWebHyDrationBridge *  create_autentication_bridge(CWebHyDration *hydration){
    CWebHyDrationBridge *autentication_bridge_object = cweb.hydration.bridge.create_bridge(
        hydration,
        AUTENTICATION_BRIDGE,
        autentication_bridge
    );
   CWebHyDrationSearchRequirements * name =
   cweb.hydration.search_requirements.newSearchRequirements(autentication_bridge_object,NAME);
   cweb.hydration.search_requirements.add_elements_by_id(name,NAME);

   CWebHyDrationSearchRequirements * email =
   cweb.hydration.search_requirements.newSearchRequirements(autentication_bridge_object,EMAIL);
   cweb.hydration.search_requirements.add_elements_by_id(email,EMAIL);

   CWebHyDrationSearchRequirements * password =
   cweb.hydration.search_requirements.newSearchRequirements(autentication_bridge_object,PASSWORD);
   cweb.hydration.search_requirements.add_elements_by_id(password,PASSWORD);

   CWebHyDrationSearchRequirements * repeat_password =
   cweb.hydration.search_requirements.newSearchRequirements(autentication_bridge_object,REPEAT_PASSWORD);
   cweb.hydration.search_requirements.add_elements_by_id(repeat_password,REPEAT_PASSWORD);

  return autentication_bridge_object;
}


CwebHttpResponse *main_sever(CwebHttpRequest *request) {

    if(strcmp(request->route, "/terminate") == 0){
        cweb_kill_single_process_server();
        return cweb_send_text("app terminated ",200);
    }

    CWebHyDration *hydration = cweb.hydration.newCWebHyDration(request);
      CWebHyDrationBridge *autentication_bridge_object = create_autentication_bridge(hydration);

    CWebHydrationHandleTriggers(hydration);

    if(strcmp(request->route,"/hydration_script") == 0){
        return cweb.response.send_text(cweb.hydration.create_script(hydration),200);
    }
    return main_page(request,autentication_bridge_object);

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
