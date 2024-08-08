
int private_LuaCemb_internal_free(lua_State *L){
    LuaCEmbed  *self = (LuaCEmbed*)lua_touserdata(L, lua_upvalueindex(1));
    if(self->delete_function){
        self->delete_function(self);
    }
    LuaCEmbed_free(self);
    return 0;
}
LuaCEmbed * newLuaCEmbedLib(lua_State *state){
    LuaCEmbed  *self = (LuaCEmbed*) malloc(sizeof (LuaCEmbed));
    *self = (LuaCEmbed){0};

    self->state = state;

    self->lib_identifier = 0;

    lua_getglobal(self->state,PRIVATE_LUA_CEMBED_TOTAL_LIBS);
    if(lua_type(self->state,-1) == LUA_CEMBED_NIL){
        self->lib_identifier  = lua_tointeger(self->state,-1);
    }

    self->lib_identifier +=1;

    self->main_lib_table = private_LuaCembed_format(PRIVATE_LUA_CEMBED_MAIN_LIB_TABLE_NAME__,self->lib_identifier);

    lua_pushinteger(self->state,self->lib_identifier);
    lua_setglobal(self->state,PRIVATE_LUA_CEMBED_TOTAL_LIBS);


    self->is_lib = true;
    self->global_tables = (void*)newprivateLuaCEmbedTableArray();


    UniversalGarbage  *garbage = newUniversalGarbage();
    char *lib_meta_table = private_LuaCembed_format(PRIVATE_LUA_CEMBED_MAIN_META_TABLE__,self->lib_identifier);
    UniversalGarbage_add_simple(garbage,lib_meta_table);
    //creating the metatable
    luaL_newmetatable(self->state, lib_meta_table);
    //seting the clojure key
    lua_pushstring(self->state,PRIVATE_LUA_CEMBED_DEL_PREFIX);
    //set self as first clojure argument
    lua_pushlightuserdata(self->state,(void*)self);
    lua_pushcclosure(self->state,private_LuaCemb_internal_free,1);
    lua_settable(self->state, -3);


    char *lib_main_table = private_LuaCembed_format(PRIVATE_LUA_CEMBED_MAIN_LIB_TABLE_NAME__,self->lib_identifier);
    UniversalGarbage_add_simple(garbage,lib_main_table);
    //creating the global table to store the elements
    lua_newtable(self->state);
    lua_setglobal(self->state,lib_main_table);
    luaL_setmetatable(self->state, lib_meta_table);

    UniversalGarbage_free(garbage);
    return  self;
}

int LuaCembed_perform(LuaCEmbed *self){
    PRIVATE_LUA_CEMBED_PROTECT_NUM

    char *lib_main_table = private_LuaCembed_format(PRIVATE_LUA_CEMBED_MAIN_LIB_TABLE_NAME__,self->lib_identifier);
    lua_getglobal(self->state,lib_main_table);
    free(lib_main_table);
    return 1;
}
