

void LuaCEmbed_set_global_string(LuaCEmbed *self, const char *name, const  char *value){
    PRIVATE_LUA_CEMBED_PROTECT_VOID

    lua_pushstring(self->state,value);
    lua_setglobal(self->state,name);
}
void LuaCEmbed_set_global_raw_string(LuaCEmbed *self, const char *name, const  char *value,long size){
    PRIVATE_LUA_CEMBED_PROTECT_VOID

    lua_pushlstring(self->state,value,size);
    lua_setglobal(self->state,name);
}


void LuaCEmbed_set_global_long(LuaCEmbed *self, const char *name, long long  value){
    PRIVATE_LUA_CEMBED_PROTECT_VOID

    lua_pushnumber(self->state,(double )value);
    lua_setglobal(self->state,name);
}

void LuaCEmbed_set_global_double(LuaCEmbed *self, const char *name, double value){
    PRIVATE_LUA_CEMBED_PROTECT_VOID

    lua_pushnumber(self->state,(double )value);
    lua_setglobal(self->state,name);
}

void LuaCEmbed_set_global_bool(LuaCEmbed *self, const char *name, bool value){
    PRIVATE_LUA_CEMBED_PROTECT_VOID
    lua_pushboolean(self->state,value);
    lua_setglobal(self->state,name);
}


void LuaCEmbed_set_global_table(LuaCEmbed *self, const char *name, LuaCEmbedTable *table){
    PRIVATE_LUA_CEMBED_PROTECT_VOID

    lua_getglobal(self->state,table->global_name);
    lua_setglobal(self->state,name);
}