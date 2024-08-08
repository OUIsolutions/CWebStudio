#include "../unique.definition_requirements.h"

LuaCEmbedResponse * system_function_with_status(LuaCEmbedTable *self,LuaCEmbed *args){
    char *command = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *msg  = lua.get_error_message(args);
        return lua.response.send_error(msg);
    }
    int result = system(command);
    return lua.response.send_long(result);
}

LuaCEmbedResponse *system_with_text(LuaCEmbedTable *self,LuaCEmbed *args){

    char *comand = lua.args.get_str(args,0);
    if(lua.has_errors(args)){
        char *error_msg = lua.get_error_message(args);
        return  lua.response.send_error(error_msg);
    }

    FILE *fp = popen(comand, "r");
    if (fp == NULL) {
        return  lua.response.send_error("fail to run the comand");
    }


    CTextStack *final =stack.newStack_string_empty();
    char path[1035] ={0};

    while (fgets(path, sizeof(path), fp) != NULL) {
        stack.format(final,"%s",path);
    }

    /* close */
    pclose(fp);

    LuaCEmbedResponse *response = lua.response.send_raw_string(final->rendered_text,final->size);
    stack.free(final);
    return  response;
}

LuaCEmbedResponse *custom_print(LuaCEmbedTable *self,LuaCEmbed *args){

    int size = lua.args.size(args);
    for(int i = 0; i < size; i++){
        int type = lua.args.get_type(args,i);
        if(type == lua.types.NUMBER){
            printf("%lf",lua.args.get_double(args,i));
        }
        if(type == lua.types.STRING){
            printf("%s",lua.args.get_str(args,i));
        }
        if(type == lua.types.BOOL){
            char *bool_str = lua.args.get_bool(args,i) ? "true":"false";
            printf("%s",bool_str);
        }

        if(type == lua.types.NILL){
            printf("nil");
        }
    }
    return NULL;
}
