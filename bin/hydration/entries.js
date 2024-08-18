let private_cweb_entrie_clojure_constructors = {

  get_all_elements_by_tag_name: function (tag, name) {
  },

  get_all_elements_number_by_tag_name: function (tag, name) {
  },

  get_all_elements_input_by_tag_name: function (tag, name) {
  },

  get_all_elements_input_number_by_tag_name: function (tag, name) {
  },


  get_all_elements_text_with_corresponding_id: function (id) {
    return this.
  },

  get_text_number_by_id: function (id) {
    return function (args, content) {
      let text = document.getElementById(id).textContent;
      content[id] = parseFloat(text);
    };
  },

  get_input_by_id: function (id) {
    return function (args, content) {
      content[id] = document.getElementById(id).value;
    };
  },

  get_input_number_by_id: function (id) {
    return function (args, content) {
      content[id] = parseFloat(document.getElementById(id).value);
    };
  },
};
