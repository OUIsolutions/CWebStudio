
CTextStack * private_cweb_format_filename(CTextStack *src){
    bool full_path = CTextStack_starts_with(src,cweb_static_folder);

    if(full_path){
        return  newCTextStack_string(src->rendered_text);
    }
    else{
        return  newCTextStack_string_format("%s/%t",cweb_static_folder,src);
    }

}

CwebHttpResponse * private_cweb_treat_five_icon(){


    char possible_ico_path[1000] = {0};
    sprintf(possible_ico_path,"%s/favicon.ico",cweb_static_folder);
    FILE  *possible_ico_file = fopen(possible_ico_path,"rb");
    if(possible_ico_file){
        fclose(possible_ico_file);
        return cweb_send_file(possible_ico_path,CWEB_AUTO_SET_CONTENT,200);
    }


    char possible_png_path[1000] = {0};
    sprintf(possible_png_path,"%s/favicon.png",cweb_static_folder);
    FILE  *possible_png_file = fopen(possible_png_path,"rb");
    if(possible_png_file){
        fclose(possible_png_file);
        return cweb_send_file(possible_png_path,CWEB_AUTO_SET_CONTENT,200);
    }

    char possible_jpg_path[1000] = {0};
    sprintf(possible_jpg_path,"%s/favicon.png",cweb_static_folder);
    FILE  *possible_jpg_file = fopen(possible_jpg_path,"rb");
    if(possible_jpg_file){
        fclose(possible_jpg_file);
        return cweb_send_file(possible_jpg_path,CWEB_AUTO_SET_CONTENT,200);
    }
    return NULL;


}

CwebHttpResponse * private_cweb_generate_static_response(struct CwebHttpRequest *request,bool use_cache){


    bool is_faviocon_route = strcmp(request->route,"/favicon.ico")== 0;
    if(is_faviocon_route){
        return private_cweb_treat_five_icon();
    }


    if(!cweb_starts_with(request->route,"/static")){
        return  NULL;
    }

    char *full_path = NULL;


    char *param_path = CwebHttpRequest_get_param(request,"path");


    if(param_path){
        full_path = param_path;
    }


    if(!param_path){
        full_path = request->route;
        int  base_route_size = (int)strlen("/static");
        int min_size = base_route_size +2;


        if(strlen(full_path) < min_size){
            return NULL;
        }
        full_path+= base_route_size;
    }

    const int MAX_PATH = 900;
    if(strlen(full_path) > MAX_PATH){
        return NULL;
    }

    char formated_full_path[2000] = {0};
    sprintf(formated_full_path,"%s/%s",cweb_static_folder,full_path);

    char *security_path = cweb_replace_string(formated_full_path,"../","");
    int size;
    bool is_binary;
    unsigned char *content = cweb_load_any_content(security_path,&size,&is_binary);

    if(content == NULL){

        char not_found_html_page_path[1100] ={0};
        sprintf(not_found_html_page_path,"%s/404.html",cweb_static_folder);
        char *not_found_html_page = cweb_load_string_file_content(not_found_html_page_path);
        if(not_found_html_page != NULL){
            free(security_path);
            return cweb_send_var_html_cleaning_memory(not_found_html_page,404);

        }

        char menssage[1100] = {0};
        sprintf(menssage,"File %s not found",security_path);
        struct CwebHttpResponse* response =  cweb_send_text(menssage, CWEB_NOT_FOUND);
        free(security_path);

        return response;
    }

    if(!is_binary){
        CTextStack *inclusion = newCTextStack_string_empty();
        private_cweb_generate_inline_inclusion(inclusion,(const char*)content,size);

        char *new_content = private_cweb_change_smart_cache((const char*)inclusion->rendered_text);
        CTextStack_free(inclusion);

        free(content);
        size = strlen(new_content);
        content = (unsigned char*)new_content;
    }

    char *content_type  = (char*)cweb_generate_content_type(security_path);

    struct CwebHttpResponse * response = cweb_send_any_cleaning_memory(content_type,size,content,200);


    if(use_cache){
        char *unix_cache = CwebHttpRequest_get_param(request,"unix-cache");
        if(unix_cache){
            char response_code[50] = "";
            sprintf(response_code, "public, max-age=31536000, immutable");
            CwebHttpResponse_add_header(response,"cache-control", response_code);
        }
    }

    free(security_path);
    return response;



}