
#include "definition.c"


void add_callbacks(LuaCEmbed *main_obj){


    LuaCEmbedTable * clib = lua.globals.new_table(main_obj,"clib");
    lua.tables.set_method(clib,"get_char",lua_get_char);
    lua.tables.set_method(clib,"getargv",get_argv);
    lua.tables.set_method(clib,"exit",generate_exit);
    lua.tables.set_method(clib,"print",custom_print);
    lua.tables.set_method(clib,"get_str_size",lua_get_str_size);
    lua.tables.set_method(clib,"system_with_status",system_function_with_status);
    lua.tables.set_method(clib,"system_with_string",system_with_text);
    lua.tables.set_method(clib,"indexof",lua_index_of);
    lua.tables.set_method(clib,"replace",lua_replace_string);
    lua.tables.set_method(clib,"trim",lua_trim);

}


int main(int argc,char *argv[]){
    argv_size = argc;
    argv_etries = argv;
    lua  = newLuaCEmbedNamespace();
    stack = newCTextStackModule();
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
