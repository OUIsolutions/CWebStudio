
struct CwebHttpResponse * private_cweb_treat_five_icon(struct CwebHttpRequest *request){

    if(strcmp(request->route,"/favicon.ico")== 0){

        int size = 0;
        unsigned char *content;


        content = cweb_load_binary_content("static/favicon.ico", &size);
        if(content != NULL){
            return cweb_send_any_cleaning_memory("image/x-icon",size,content, 200);
        }

        content = cweb_load_binary_content("static/favicon.png", &size);
        if(content != NULL){
            return cweb_send_any_cleaning_memory("image/x-icon",size,content, 200);
        }


        content = cweb_load_binary_content("static/favicon.jpg", &size);
        if(content != NULL){
             return cweb_send_any_cleaning_memory("image/x-icon",size,content, 200);
        }

        return cweb_send_text("",404);

    }
    return NULL;
}

struct CwebHttpResponse * private_cweb_generate_static_response(struct CwebHttpRequest *request){

    struct CwebHttpResponse * icon_response = private_cweb_treat_five_icon(request);

    if(icon_response !=  NULL){
        return icon_response;
    }

    if(cweb_starts_with(request->route,"/static")){

        char *full_path = request->route;
        full_path+=1;

        char *path = request->get_param(request,"path");
        if(path != NULL){
            full_path = path;
        }
        char *securyt_path = cweb_replace_string(full_path,"../","");
        struct CwebHttpResponse * response = cweb_send_file(securyt_path,CWEB_AUTO_SET_CONTENT,200);
        free(securyt_path);
        return response;
    }
    return NULL;



}