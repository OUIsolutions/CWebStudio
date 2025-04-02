
#include "../unique.definition_requirements.h"

LuaCEmbedResponse *get_argv(LuaCEmbedTable *self,LuaCEmbed *args) {
    long element = lua.args.get_long(args,0);

    if(lua.has_errors(args)){
        char *menssage = lua.get_error_message(args);
        return  lua.response.send_error(menssage);
    }

    if(element >= argv_size){
        return NULL;
    }

    return lua.response.send_str(argv_etries[element]);
}
