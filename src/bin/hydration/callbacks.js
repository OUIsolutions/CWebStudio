

let private_cweb_callbacks = {}

private_cweb_callbacks.private_cweb_alert = function (args){
    alert(args.menssage);
}


private_cweb_callbacks.private_cweb_destroy_by_id = function (args){
    let element = document.getElementById(args.id);
    if(element){
        element.remove();
    }
}




private_cweb_callbacks.private_cweb_hydration_replace_by_id = function (args){
    let element = document.getElementById(args.id);
    if(!element){
        return ;
    }
    element.insertAdjacentHTML("afterend",args.html);
    element.remove();
}
