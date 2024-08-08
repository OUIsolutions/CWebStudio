
function  private_cweb_replace_args_in_body(body,args){
    if(!args){
        return;
    }
    let counter = 0;
    args.forEach(e =>{
        let current_element = "args"+counter
        body[current_element] = e
    })
}

function private_cweb_replace_args(args,element){
    let formated = element
    let counter = 0;
    args.forEach(e =>{
        let current_element = "args"+counter
        formated = formated.replace(current_element,e.toString())
    })
    return formated;
}


function private_cweb_hydration_get_text_content_by_id (body,args,id){
    let new_id = private_cweb_replace_args(args,id);
    let element = document.getElementById(new_id);
    if(element){
        body[id] = element.textContent.toString();
    }
}
function private_cweb_hydration_number_get_text_content_by_id (body,args,id){
    let new_id = private_cweb_replace_args(args,id);
    let element = document.getElementById(new_id);
    if(element){
        body[id] = parseFloat(element.textContent.toString());
    }
}
