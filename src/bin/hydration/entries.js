let private_cweb_entrie_clojure_constructors = {
  get_text_by_id: function () {
    return function (args, content) {
      content[id] = document.getElementById(id).textContentnt.toString();
    };
  },

  get_text_number_by_id: function () {
    return function (args, content) {
      let text = document.getElementById(id).textContentnt.toString();
      content[id] = parseFloat(text);
    };
  },

  get_input_by_id: function () {
    return function (args, content) {
      content[id] = document.getElementById(id).value;
    };
  },

  get_input_number_by_id: function () {
    return function (args, content) {
      content[id] = parseFloat(document.getElementById(id).value);
    };
  },
};
