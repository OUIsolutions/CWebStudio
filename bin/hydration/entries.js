function private_cweb_try_to_convert_to_number(possible_number) {
  let possible_conversion = parseFloat(possible_number);
  if (isNaN(possible_conversion)) {
    return possible_number;
  }

  return possible_conversion;
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
    if (finalvalue == "true") {
      finalvalue = true;
    } else if (finalvalue == "false") {
      finalvalue = false;
    } else {
      finalvalue = private_cweb_try_to_convert_to_number(finalvalue);
    }
  }

  if (finalvalue) {
    content_array.unshift(finalvalue);
  }
}

function private_cweb_get_elements_and_set_to_content(props) {
  if (!props.content[props.search_name]) {
    props.content[props.search_name] = [];
  }

  let content_array = props.content[props.search_name];
  let elements = document.querySelectorAll(props.query_selector);

  elements.forEach((element) => {
    let finalvalue = undefined;
    let auto_convert = props.auto_convert;
    if (element.type === "checkbox") {
      finalvalue = element.checked;
      auto_convert = false;
    } else if (element.tagName === "INPUT" || element.tagName === "TEXTAREA") {
      finalvalue = element.value;
    } else {
      finalvalue = element.textContent;
    }

    if (auto_convert) {
      finalvalue = private_cweb_try_to_convert_to_number(finalvalue);
    }
    content_array.push(finalvalue);
  });
}
