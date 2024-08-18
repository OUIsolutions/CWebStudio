let private_cweb_bridges = {};

async function private_cweb_send_to_server(name, args, content) {
  let body = { name: name, args: args, content: content };
  let props = {
    method: "POST",
    body: JSON.stringify(body),
  };
  const ROUTE = "/private_cweb_hydration_main_callback_handler";
  let result = await fetch(ROUTE, props);
  let actions = await result.json();
  actions.forEach(function (item) {
    try {
      let response_action = private_cweb_response_handlers[item.name];
      if (!response_action) {
        throw Error("response " + item.name + "its not a action");
      }

      response_action(item.data);
    } catch (error) {
      console.log(error);
    }
  });
}

function private_cweb_handle_required_data(callback, args, content) {
  callback(args, content);
}
/*
private_cweb_bridges["inc number"] = async function (args) {
  let content = {};
  private_cweb_handle_required_data(function (args, content) {}, args, content);
  await private_cweb_send_to_server("inc number", args, content);
};
*/
