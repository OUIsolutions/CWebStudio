
#include "definition.c"

void add_callbacks(LuaCEmbed *main_obj){
    lua.add_callback(main_obj,"getargv",get_argv);
    lua.add_callback(main_obj,"exit",generate_exit);

}


int main(int argc,char *argv[]){
    argv_size = argc;
    argv_etries = argv;
    lua  = newLuaCEmbedNamespace();
    stack_module = newCTextStackModule();
    LuaCEmbed * main_obj = lua.newLuaEvaluation();
    lua.load_native_libs(main_obj);
    lua.load_lib_from_c(main_obj,load_luaDoTheWorld,"dtw");

    add_callbacks(main_obj);
    lua.evaluate(main_obj,lua_code);
    if(lua.has_errors(main_obj)){
        char *error = lua.get_error_message(main_obj);
        if(strcmp(error,"") != 0){
            printf("%s\n",error);
        }
        lua.free(main_obj);
        return lua_exit;
    }

    lua.free(main_obj);
    return 0;
}
