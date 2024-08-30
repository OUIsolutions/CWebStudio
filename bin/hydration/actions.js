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
  remove_session_storage_data: function (data) {
    sessionStorage.removeItem(data["key"]);
  },
  add_cookie_with_time: function (data) {
    let expires = "";
    if (data.days) {
      const date = new Date();
      date.setTime(date.getTime() + data.days * 24 * 60 * 60 * 1000);
      expires = "; expires=" + date.toUTCString();
    }
    document.cookie =
      data.name + "=" + (data.value || "") + expires + "; path=/";
  },
  add_cookie: function (data) {
    document.cookie = data.name + "=" + (data.value || "") + "; path=/";
  },
  delet_cookie: function (name) {
    document.cookie = name + "=; Max-Age=-99999999;";
  },
  replace_element_by_query_selector: function (data) {
    let element = document.querySelector(data.query_selector);
    if (!element) {
      return;
    }
    element.insertAdjacentHTML("afterend", data.html);
    element.remove();
  },

  append_by_query_selector: function (data) {
    let element = document.querySelector(data.query_selector);
    if (!element) {
      return;
    }
    element.innerHTML += data.html;
  },

  hide_element_by_query_selector: function (data) {
    let element = document.querySelector(data.query_selector);
    if (!element) {
      return;
    }
    element.style.display = "none";
  },
  unhide_element_by_query_selector: function (data) {
    let element = document.querySelector(data.query_selector);
    if (!element) {
      return;
    }
    element.style.display = "show";
  },

  destroy_by_query_selector: function (data) {
    let element = document.querySelector(data.query_selector);
    if (element) {
      element.remove();
    }
  },

  log: function (data) {
    console.log(data.message);
  },

  warn: function (data) {
    console.warn(data.message);
  },

  error: function (data) {
    console.error(data.message);
  },

  clear: function (data) {
    console.clear();
  },

  add_class_by_query_selector: function (data) {
    let element = document.querySelector(data.query_selector);
    if (!element) {
      return;
    }
    element.classList.add(data.class_name);
  },

  remove_class_by_query_selector: function (data) {
    let element = document.querySelector(data.query_selector);
    if (!element) {
      return;
    }
    element.classList.remove(data.class_name);
  },

  add_class_by_id: function (data) {
    let element = document.getElementById(data.id);
    if (!element) {
      return;
    }
    element.classList.add(data.class_name);
  },

  remove_class_by_id: function (data) {
    let element = document.getElementById(data.id);
    if (!element) {
      return;
    }
    element.classList.remove(data.class_name);
  },
};
