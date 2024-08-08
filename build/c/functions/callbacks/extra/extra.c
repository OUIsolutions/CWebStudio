#include "../unique.definition_requirements.h"


LuaCEmbedResponse * generate_exit(LuaCEmbed *args){
    int status = lua.args.get_long(args,0);
    if(lua.has_errors(args)){
        char *menssage = lua.get_error_message(args);
        return  lua.response.send_error(menssage);
    }
    lua_exit = status;
    return lua.response.send_error("");
}
