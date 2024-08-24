
#include "../src/one.c"

CwebNamespace cweb;
CTextStackModule stack;

CWebHydrationBridgeNamespace nome;

void bridge_set_operator(CWebHyDrationBridge *bridge){
    CWebHyDrationSearchResult *visor = cweb.hydration.search_result.get_search_by_name(
        bridge,
        "window"
    );
    char * visor_str = cweb.hydration.search_result.get_string(visor,0);

    char * operator_str = cweb.hydration.args.get_str_arg(bridge,0);


    CWebHydrationHandleErrors(bridge);


    cweb.hydration.actions.set_session_storage_data(bridge,"operator",operator_str);

    CTextStack *first_num_formmated = stack.newStack_string(visor_str);
    stack.self_replace(first_num_formmated,"\n","");
    stack.self_replace(first_num_formmated," ","");

    cweb.hydration.actions.set_session_storage_data(bridge,"first_num",first_num_formmated->rendered_text);

    CTextStack *html_h2 = stack.newStack_string_empty();
    CTextScope_format(html_h2, CTEXT_H2, "id='window'"){}
    cweb.hydration.actions.replace_element_by_id(bridge, "window", html_h2->rendered_text);
    stack.free(first_num_formmated);
    stack.free(html_h2);
}
void bridge_set_result(CWebHyDrationBridge *bridge){

    CWebHyDrationSearchResult *visor = cweb.hydration.search_result.get_search_by_name(
        bridge,
        "window"
    );
    long visor_num  = cweb.hydration.search_result.get_long(visor,0);

    CWebHyDrationSearchResult *first_num = cweb.hydration.search_result.get_search_by_name(
        bridge,
        "first_num"
    );
    long first_num_num = cweb.hydration.search_result.get_long(first_num,0);


    CWebHyDrationSearchResult *operator = cweb.hydration.search_result.get_search_by_name(
            bridge,
            "operator"
        );
    char * operator_str = cweb.hydration.search_result.get_string(operator,0);

    CWebHydrationHandleErrors(bridge);

    long result = 0;
    if(strcmp(operator_str, "+") == 0){
        result =first_num_num + visor_num;
    }

    if(strcmp(operator_str, "-") ==0 ){
        result =first_num_num - visor_num;
    }

    if(strcmp(operator_str, "x") == 0){
        result =first_num_num * visor_num;
    }

    if(strcmp(operator_str, "/")==0){
        result =first_num_num / visor_num;
    }

    CTextStack *html_h2 = stack.newStack_string_empty();

    CTextScope_format(html_h2, CTEXT_H2, "id='window'"){
      stack.format(html_h2, "%d",result);
    }
    cweb.hydration.actions.replace_element_by_id(bridge, "window", html_h2->rendered_text);
    stack.free(html_h2);

}

void bridge_write_number(CWebHyDrationBridge *bridge){

  CWebHyDrationSearchResult *visor = cweb.hydration.search_result.get_search_by_name(
      bridge,
      "window"
  );
  long num =cweb.hydration.args.get_long_arg(bridge,0);
  char * visor_str = cweb.hydration.search_result.get_string(visor,0);
  CWebHydrationHandleErrors(bridge);
  CTextStack *html_h2 = stack.newStack_string_empty();

  if(strlen(visor_str) > 10){
      return;;
  }
  CTextScope_format(html_h2, CTEXT_H2, "id='window'"){
    stack.format(html_h2, "%s%d",visor_str,num);
  }
  cweb.hydration.actions.replace_element_by_id(bridge, "window", html_h2->rendered_text);
  stack.free(html_h2);
}


CwebHttpResponse *page_main(

    CWebHyDrationBridge *bridge_obj_number_button,
    CWebHyDrationBridge *bridge_obj_set_operator,
    CWebHyDrationBridge *bridge_obj_set_result
){

  CTextStack *html = stack.newStack("", "");

  CTextScope(html, CTEXT_BODY){

    CTextScope_format(html, CTEXT_SCRIPT, "src='/main_script_hydration'");

    CTextScope(html, CTEXT_H1){
      stack.format(html, "Calculator");
    }

    CTextScope_format(html, CTEXT_H2, "id='window'"){}
    CTextScope_format(html, CTEXT_BUTTON,
        cweb.hydration.bridge.onclick(bridge_obj_number_button, "%d", 1)){
            stack.format(html, "1");
    }

    CTextScope_format(html, CTEXT_BUTTON,
        cweb.hydration.bridge.onclick(bridge_obj_number_button, "%d", 2)
    ){
      stack.format(html, "2");
    }
    CTextScope_format(html, CTEXT_BUTTON,
        cweb.hydration.bridge.onclick(bridge_obj_number_button, "%d", 3)
    ){
      stack.format(html, "3");
    }

    CTextScope(html,CTEXT_BR);

    CTextScope_format(html, CTEXT_BUTTON,
        cweb.hydration.bridge.onclick(bridge_obj_number_button, "%d", 4)
    ){
      stack.format(html, "4");
    }

    CTextScope_format(html, CTEXT_BUTTON,
        cweb.hydration.bridge.onclick(bridge_obj_number_button, "%d", 5))
    {
      stack.format(html, "5");
    }

    CTextScope_format(html, CTEXT_BUTTON,cweb.hydration.bridge.onclick(bridge_obj_number_button, "%d", 6)){
      stack.format(html, "6");
    }

    CTextScope(html,CTEXT_BR);


    CTextScope_format(html, CTEXT_BUTTON,cweb.hydration.bridge.onclick(bridge_obj_number_button, "%d", 7)){
      stack.format(html, "7");
    }
    CTextScope_format(html, CTEXT_BUTTON,cweb.hydration.bridge.onclick(bridge_obj_number_button, "%d", 8)){
      stack.format(html, "8");
    }
    CTextScope_format(html, CTEXT_BUTTON,cweb.hydration.bridge.onclick(bridge_obj_number_button, "%d", 9)){
      stack.format(html, "9");
    }

    CTextScope(html,CTEXT_BR);

    CTextScope_format(html, CTEXT_BUTTON,cweb.hydration.bridge.onclick(bridge_obj_number_button, "%d", 0)){
      stack.format(html, "0");
    }

    CTextScope_format(html, CTEXT_BUTTON,cweb.hydration.bridge.onclick(bridge_obj_set_operator, "'+'")){
          stack.format(html, "+");
    }

    CTextScope_format(html, CTEXT_BUTTON,cweb.hydration.bridge.onclick(bridge_obj_set_operator, "'-'")){
          stack.format(html, "-");
    }

    CTextScope_format(html, CTEXT_BUTTON,cweb.hydration.bridge.onclick(bridge_obj_set_operator, "'x'")){
          stack.format(html, "x");
    }

    CTextScope_format(html, CTEXT_BUTTON,cweb.hydration.bridge.onclick(bridge_obj_number_button, "'/'")){
          stack.format(html, "/");
    }

    CTextScope_format(html, CTEXT_BUTTON,cweb.hydration.bridge.onclick(bridge_obj_set_result, NULL)){
          stack.format(html, "=");
    }


  }

  return cweb.response.send_rendered_CTextStack_cleaning_memory(html, 200);
}

void create_window_requirements(CWebHyDrationBridge *bridge){
    CWebHyDrationSearchRequirements *window_obj_num =
      cweb.hydration.search_requirements.newSearchRequirements(
          bridge,
          "window"
    );
    cweb.hydration.search_requirements.add_elements_by_id_not_auto_converting(window_obj_num,"window");
}


CwebHttpResponse *main_server(CwebHttpRequest *rq){

  if(strcmp(rq->route, "/end") == 0){
    cweb_kill_single_process_server();
    return cweb.response.send_text("WebSite kill", 200);
  }

  CWebHyDration *hydration = cweb.hydration.newCWebHyDration(rq);
  CWebHyDrationBridge *bridge_obj_number_in_window =
  cweb.hydration.bridge.create_bridge(hydration,
      "Bridge_pencil_number_in_window",
      bridge_write_number
  );
  create_window_requirements(bridge_obj_number_in_window);

  CWebHyDrationBridge *bridge_operator =
    cweb.hydration.bridge.create_bridge(hydration,
      "bridge_operator",
      bridge_set_operator
  );

  create_window_requirements(bridge_operator);

  CWebHyDrationBridge *bridge_result_object =
  cweb.hydration.bridge.create_bridge(hydration,
      "bridge_result",
      bridge_set_result
  );
  CWebHyDrationSearchRequirements *window =
    cweb.hydration.search_requirements.newSearchRequirements(
        bridge_result_object,
        "window"
  );

  cweb.hydration.search_requirements.add_elements_by_id(
      window,"window"
  );


  CWebHyDrationSearchRequirements * first_num =
  cweb.hydration.search_requirements.newSearchRequirements(
      bridge_result_object,
      "first_num"
  );

  cweb.hydration.search_requirements.add_session_storage_item(
      first_num,
      "first_num"
  );

  CWebHyDrationSearchRequirements * operator =
  cweb.hydration.search_requirements.newSearchRequirements(
      bridge_result_object,"operator"
  );

  cweb.hydration.search_requirements.add_session_storage_item(
      operator,
      "operator"
  );


  CWebHydrationHandleTriggers(hydration);

  if(strcmp(rq->route, "/main_script_hydration") == 0){
    return cweb.response.send_text(cweb.hydration.create_script(hydration), 200);
  }

  return page_main(bridge_obj_number_in_window, bridge_operator,bridge_result_object);
}

int main(){

  cweb = newCwebNamespace();
  stack = newCTextStackModule();
  nome = cweb.hydration.bridge;

  CwebServer server = newCwebSever(3001, main_server);
  server.single_process = true;
  cweb.server.start(&server);
}
