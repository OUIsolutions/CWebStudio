let private_cweb_response_handlers = {
  alert: function (data) {
    alert(data["message"]);
  },

  execute_script: function (data) {
    eval(data["code"]);
  },

  replace_element_by_id: function (data) {
    let element = document.getElementById(data.id);
    if (!element) {
      return;
    }
    element.insertAdjacentHTML("afterend", data.html);
    element.remove();
  },
  destroy_by_id: function (data) {
    let element = document.getElementById(args.id);
    if (element) {
      element.remove();
    }
  },
};
