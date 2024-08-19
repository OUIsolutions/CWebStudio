

function private_cweb_get_elements_and_set_to_content(props) {
  if (!props.content[props.set_content_key]) {
    props.content[props.key_name] = [];
  }

  let content_array = props.content[props.key_name];
  let elements = document.querySelectorAll(props.query_selector);
  elements.forEach((element) => {
    let finalvalue = undefined;

    if (element.tagName === "INPUT" || element.tagName == "TEXTAREA") {
      finalvalue = element.value;
    } else {
      finalvalue = element.textContent;
    }

    if (props.convert_to_number) {
      finalvalue = parseFloat(finalvalue);
    }
    if (finalvalue) {
      content_array.unshift(finalvalue);
    }
  });
}
