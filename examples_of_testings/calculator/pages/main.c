
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
    CTextScope_format(html, CTEXT_INPUT, "type='checkbox' id='input_add_or_subtract'"){
      stack.format(html, "substract");
    }
  }

  return cweb.response.send_rendered_CTextStack_cleaning_memory(html, 200);
}


