
#include "../src/one.c"

CwebNamespace cweb;
CTextStackModule stack;

void bridge_obj_number(CWebHyDrationBridge *bridge){

  /*
  printf("\nHello Word!");//Por que não aparece?
  
  bool is_number = cweb.hydration.args.is_arg_number(bridge, 0);

  if(is_number){
    short number = cweb.hydration.args.get_long_arg(bridge, 0);
    CWebHyDrationSearchResult *h2 = cweb.hydration.search_result.get_search_by_name(bridge, "window");
    printf("This is a number: %s", cweb.hydration.search_result.is_search_item_number(h2, 0)?"É um numero":"Não é um numero");

    CTextStack *html_h2 = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    CTextScope_format(html_h2, "h2", "id='window'"){
      stack.format(html_h2, "%hd", number);
    }

    cweb.hydration.actions.replace_element_by_id(bridge, "window", html_h2->rendered_text);
    bool is_number_result = cweb.hydration.search_result.is_search_item_number(h2, 0);
    if(is_number_result){
      cweb.hydration.actions.alert(bridge, "É um numero");
    }
    int number_in_window = (int)cweb.hydration.search_result.get_long(h2, 0);
    if(number_in_window){
      cweb.hydration.actions.alert(bridge, "Existe%d", number_in_window);
    }
  }
*/

}

CwebHttpResponse *page_main(CWebHyDrationBridge *bridge_obj_number_button, CWebHyDrationBridge *bridge_obj_simbol_result){

  CTextStack *html = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

  CTextScope(html, CTEXT_BODY){

    CTextScope_format(html, CTEXT_SCRIPT, "src='/main_script_hydration'");

    CTextScope_format(html, CTEXT_H1, "class='titulo'"){
      stack.format(html, "Calculator");
    }
    CTextScope_format(html, CTEXT_H2, "id='window'"){
      stack.format(html, "0");
    }
    CTextScope_format(html, CTEXT_BUTTON,cweb.hydration.bridge.onclick(bridge_obj_number_button, "%d", 1)){
      stack.format(html, "1");
    }
    CTextScope_format(html, CTEXT_BUTTON,cweb.hydration.bridge.onclick(bridge_obj_number_button, "%d", 2)){
      stack.format(html, "2");
    }
    CTextScope_format(html, CTEXT_BUTTON,cweb.hydration.bridge.onclick(bridge_obj_number_button, "%d", 3)){
      stack.format(html, "3");
    }
    CTextScope_format(html, CTEXT_BUTTON,cweb.hydration.bridge.onclick(bridge_obj_number_button, "%d", 4)){
      stack.format(html, "4");
    }
    CTextScope_format(html, CTEXT_BUTTON,cweb.hydration.bridge.onclick(bridge_obj_number_button, "%d", 5)){
      stack.format(html, "5");
    }
    CTextScope_format(html, CTEXT_BUTTON,cweb.hydration.bridge.onclick(bridge_obj_number_button, "%d", 6)){
      stack.format(html, "6");
    }
    CTextScope_format(html, CTEXT_BUTTON,cweb.hydration.bridge.onclick(bridge_obj_number_button, "%d", 7)){
      stack.format(html, "7");
    }
    CTextScope_format(html, CTEXT_BUTTON,cweb.hydration.bridge.onclick(bridge_obj_number_button, "%d", 8)){
      stack.format(html, "8");
    }
    CTextScope_format(html, CTEXT_BUTTON,cweb.hydration.bridge.onclick(bridge_obj_number_button, "%d", 9)){
      stack.format(html, "9");
    }
    CTextScope_format(html, CTEXT_BUTTON,cweb.hydration.bridge.onclick(bridge_obj_number_button, "%d", 0)){
      stack.format(html, "0");
    }
  }

  return cweb.response.send_rendered_CTextStack_cleaning_memory(html, 200);
}

CwebHttpResponse *main_server(CwebHttpRequest *rq){

  if(strcmp(rq->route, "/end") == 0){
    cweb_kill_single_process_server();
    return cweb.response.send_text("WebSite kill", 200);
  }

  CWebHyDration *hydration = cweb.hydration.newCWebHyDration(rq);
  CWebHyDrationBridge *bridge_obj_number_in_window = cweb.hydration.bridge.create_bridge(hydration, "Bridge_pencil_number_in_window", bridge_obj_number);
  CWebHyDrationBridge *bridge_obj_result_in_window;

  CWebHydrationHandleTriggers(hydration);

  if(strcmp(rq->route, "/main_script_hydration") == 0){
    return cweb.response.send_text(cweb.hydration.create_script(hydration), 200);
  }

  return page_main(bridge_obj_number_in_window, bridge_obj_result_in_window);
}

int main(){
  
  cweb = newCwebNamespace();
  stack = newCTextStackModule();

  CwebServer server = newCwebSever(3000, main_server);
  server.single_process = true;
  cweb.server.start(&server);
}
