function private_cweb_try_to_convert_to_number(possible_number) {
  let possible_conversion = parseFloat(possible_number);
  if (isNaN(possible_conversion)) {
    return possible_number;
  }

  return possible_conversion;
}

function private_cweb_get_session_storage_item(props) {
  let finalvalue = sessionStorage.getItem(props.name);

  if (!finalvalue) {
    return [];
  }
  if (props.auto_convert) {
    finalvalue = private_cweb_try_to_convert_to_number(finalvalue);
  }

  return [finalvalue];
}

function private_cweb_get_elements(props) {
  let elements = [...document.querySelectorAll(props.query_selector)];
  return elements.map((element) => {
    let finalvalue = undefined;

    if (element.type === "checkbox") {
      return element.checked;
    }

    if (element.tagName === "INPUT" || element.tagName === "TEXTAREA") {
      finalvalue = element.value;
    } else {
      finalvalue = element.textContent;
    }

    if (props.auto_convert) {
      finalvalue = private_cweb_try_to_convert_to_number(finalvalue);
    }

    return finalvalue;
  });
}
