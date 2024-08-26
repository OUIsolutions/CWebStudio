let private_cweb_bridges = {};

function private_cweb_convert_assci(asciiList) {
  return asciiList.map((code) => String.fromCharCode(code)).join("");
}

async function private_cweb_call_bridge_with_assic(
  bridge_name_assci,
  bridge_args_assci,
) {
  let bridgename_converted = private_cweb_convert_assci(bridge_name_assci);
  let bridge_args_converted = private_cweb_convert_assci(bridge_args_assci);
  let current_bridge = private_cweb_bridges[bridgename_converted];
  let code = "current_bridge([" + bridge_args_converted + "])";

  eval(code);
}

async function private_cweb_send_to_server(name, args, content) {
  let body = { name: name, args: args, content: content };
  let props = {
    method: "POST",
    body: JSON.stringify(body),
  };
  const ROUTE = "/private_cweb_hydration_main_callback_handler";
  let result = await fetch(ROUTE, props);
  let actions = await result.json();
  if (!result.ok) {
    console.log(actions);
    return;
  }
  actions.forEach(function (item) {
    try {
      let response_action = private_cweb_actions_handlers[item.name];
      if (!response_action) {
        throw Error("response " + item.name + "its not a action");
      }

      response_action(item.data);
    } catch (error) {
      console.log(error);
    }
  });
}

function private_cweb_handle_required_data(callback, args, content, name) {
  let result = undefined;
  try {
    result = callback(args);
  } catch (error) {
    console.log(error);
    return;
  }

  if (!Array.isArray(result)) {
    result = [result];
  }

  if (!content[name]) {
    content[name] = [];
  }
  content[name] = content[name].concat(result);
}
