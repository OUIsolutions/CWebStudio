

void bridge_obj_number(CWebHyDrationBridge *bridge){

  CWebHyDrationSearchResult *h2_name = cweb.hydration.search_result.get_search_by_name(bridge, "h2_name");
  CWebHyDrationSearchResult *input_name = cweb.hydration.search_result.get_search_by_name(bridge, "input_checkbox_add_or_subtract");
  int number_in_html = cweb.hydration.search_result.get_long(h2_name, 0);
  bool input_checkbox = cweb.hydration.search_result.get_bool(input_name, 0);

  bool is_number = cweb.hydration.args.is_arg_number(bridge, 0);

  if(is_number){
    int number = (int)cweb.hydration.args.get_long_arg(bridge, 0);//Não funciona com short

    CTextStack *html_h2 = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    CTextScope_format(html_h2, "h2", "id='window'"){
      stack.format(html_h2, "%d", input_checkbox?number_in_html-number:number_in_html+number);
    }

    cweb.hydration.actions.replace_element_by_id(bridge, "window", html_h2->rendered_text);
  }
}



