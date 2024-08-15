async function private_cweb_send_to_server(name, args, content) {
  let body = [name, args, content];
  let props = {
    method: "POST",
    body: JSON.stringify(body),
  };
  const ROUTE = "/private_cweb_hydration_main_callback_handler";
  let result = await fetch(ROUTE, props);
  console.log(result);
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
