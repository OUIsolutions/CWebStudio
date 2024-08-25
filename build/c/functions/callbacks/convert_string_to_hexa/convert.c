

#include "../unique.definition_requirements.h"

LuaCEmbedResponse *convert_string_to_hexa(LuaCEmbedTable *self,LuaCEmbed *args){
    long size;
    char *str = lua.args.get_raw_str(args, &size, 0);
    if(lua.has_errors(args)){
        char *msg  = lua.get_error_message(args);
        return lua.response.send_error(msg);
    }


    CTextStack *final = stack.newStack_string_empty();


    for(int i = 0; i < size; i++){
        char bytes[15] = {0};
        sprintf(bytes, "%d,", str[i]);
        stack.format(final, "%s", bytes);
    }

    LuaCEmbedResponse *response = lua.response.send_str(final->rendered_text);

    stack.free(final);

    return response;
}
