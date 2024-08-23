
#include "main.h"

CwebHttpResponse *main_server(CwebHttpRequest *rq){

  if(strcmp(rq->route, "/end") == 0){
    cweb_kill_single_process_server();
    return cweb.response.send_text("WebSite kill", 200);
  }

  CWebHyDration *hydration = cweb.hydration.newCWebHyDration(rq);
  CWebHyDrationBridge *bridge_obj_number_in_window = cweb.hydration.bridge.create_bridge(hydration, "Bridge_pencil_number_in_window", bridge_obj_number);
  CWebHyDrationBridge *bridge_obj_result_in_window;

  CWebHyDrationSearchRequirements *h2_element_from_name = cweb.hydration.search_requirements.newSearchRequirements(bridge_obj_number_in_window, "h2_name");
  cweb.hydration.search_requirements.add_elements_by_id(h2_element_from_name, "window");

  CWebHyDrationSearchRequirements *input_checkbox_add_or_subtract = cweb.hydration.search_requirements.newSearchRequirements(bridge_obj_number_in_window, "input_checkbox_add_or_subtract");
  cweb.hydration.search_requirements.add_elements_by_id(input_checkbox_add_or_subtract, "input_add_or_subtract");

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
