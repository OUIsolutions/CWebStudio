let private_cweb_actions_handlers = {
  alert: function (data) {
    alert(data["msg"]);
  },

  execute_script: function (data) {
    eval(data["code"]);
  },

  redirect: function (data) {
    window.location.href = data["url"];
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
  append_by_id: function (data) {
    let element = document.getElementById(data.id);
    if (!element) {
      return;
    }
    element.innerHTML += data.html;
  },

  hide_element_by_id: function (data) {
    let element = document.getElementById(data.id);
    if (!element) {
      return;
    }
    element.style.display = "none";
  },
  unhide_element_by_id: function (data) {
    let element = document.getElementById(data.id);
    if (!element) {
      return;
    }
    element.style.display = "show";
  },

  destroy_by_id: function (data) {
    let element = document.getElementById(data.id);
    if (element) {
      element.remove();
    }
  },
};
