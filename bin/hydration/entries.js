let private_cweb_entrie_clojure_constructors = {


  get_all_elements_by_query_selector: function (query_selector, set_content_key) {
  
    return function (args, content) {

      if(!content[set_content_key]){
        content[set_content_key] = []
      }
      
      let elements = document.querySelectorAll(query_selector);
      elements.forEach(function (element) {
        console.log(element);
      });
    };
  
  },


  get_all_elements_by_query_selector_converting_to_nummber: function (
    tag,
    name,
  ) {},
};
