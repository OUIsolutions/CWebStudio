let private_cweb_actions_handlers = {
  alert: function (data) {
    alert(data["msg"]);
  },

  execute_script: function (data) {
    eval(data["code"]);
  },

  set_session_storage: function (data) {
    sessionStorage.setItem(data["key"], data["value"]);
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
    let element = document.getElementById(data.id);
    if (element) {
      element.remove();
    }
  },
};
