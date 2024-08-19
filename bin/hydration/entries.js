


function private_cweb_try_to_convert_to_number_or_number(number){
  let possible_conversion = parseFloat(number);
  if(possible_conversion){
    return  possible_conversion;
  }
  return number;
}

function private_cweb_get_session_storage_item(props) {
  if (!props.content[props.set_content_key]) {
    props.content[props.search_name] = [];
  }

  let content_array = props.content[props.search_name];
  let finalvalue = sessionStorage.getItem(props.name);
  if (!finalvalue) {
    return;
  }

  if (props.auto_convert) {
   finalvalue =private_cweb_try_to_convert_to_number_or_number(finalvalue);
  }


  if (finalvalue) {
    content_array.unshift(finalvalue);
  }
}

function private_cweb_get_elements_and_set_to_content(props) {
  if (!props.content[props.set_content_key]) {
    props.content[props.search_name] = [];
  }

  let content_array = props.content[props.search_name];
  let elements = document.querySelectorAll(props.query_selector);
  elements.forEach((element) => {
    let finalvalue = undefined;

    if (element.tagName === "INPUT" || element.tagName == "TEXTAREA") {
      finalvalue = element.value;
    } else {
      finalvalue = element.textContent;
    }

    if (props.auto_convert) {
    finalvalue =private_cweb_try_to_convert_to_number_or_number(finalvalue);
    }
  

    if (finalvalue) {
      content_array.unshift(finalvalue);
    }
  });
}
