

long  LuaCEmbedTable_get_full_size(LuaCEmbedTable *self){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_NUM



    lua_getglobal(self->main_object->state,self->global_name);
    int index = lua_gettop(self->main_object->state);
    long total = 0;

    lua_pushnil(self->main_object->state);
    while(lua_next(self->main_object->state,index)){
        total+=1;
        lua_pop(self->main_object->state,1);
    }

    PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
    return total;
}

long  LuaCEmbedTable_get_listable_size(LuaCEmbedTable *self){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_NUM

    lua_getglobal(self->main_object->state,self->global_name);
    return (long)lua_rawlen(self->main_object->state,-1);
}


long  privateLuaCEmbedTable_convert_index(LuaCEmbedTable *self, private_lua_cembed_incremented_arg index){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_NUM

    if(index >= 0){
        return  index;
    }

    return LuaCEmbedTable_get_full_size(self) + index;
}

int LuaCEmbedTable_get_type_by_index(LuaCEmbedTable *self, int index){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_NUM

    long formatted_index = index + LUA_CEMBED_INDEX_DIF;

    lua_getglobal(self->main_object->state,self->global_name);
    int table_index = lua_gettop(self->main_object->state);
    long converted_index = privateLuaCEmbedTable_convert_index(self,formatted_index);
    int total = 1;
    lua_pushnil(self->main_object->state);
    while(lua_next(self->main_object->state,table_index)){
        if(total == converted_index){
            int type = lua_type(self->main_object->state,-1);
            lua_pop(self->main_object->state,1);
            PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
            return type;
        }
        lua_pop(self->main_object->state,1);
        total+=1;

    }
    PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
    return LUA_CEMBED_NOT_FOUND;
}
char *LuaCembedTable_get_key_by_index(LuaCEmbedTable *self, long index){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_NULL

    long formatted_index = index + LUA_CEMBED_INDEX_DIF;

    lua_getglobal(self->main_object->state,self->global_name);
    int table_index = lua_gettop(self->main_object->state);
    long converted_index = privateLuaCEmbedTable_convert_index(self,formatted_index);
    int total = 1;
    lua_pushnil(self->main_object->state);
    while(lua_next(self->main_object->state,table_index)){

        if(total == converted_index){
            if(lua_type(self->main_object->state,-2) != LUA_CEMBED_STRING ){
                lua_pop(self->main_object->state,1);
                PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
                return NULL;
            }
            char* result = (char*)lua_tostring(self->main_object->state,-2);
            lua_pop(self->main_object->state,1);
            PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
            return result;
        }

        lua_pop(self->main_object->state,1);
        total+=1;

    }
    PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
    return NULL;
}
bool LuaCembedTable_has_key_at_index(LuaCEmbedTable *self, long index){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_BOOL
    lua_settop(self->main_object->state,0);

    long formatted_index = index + LUA_CEMBED_INDEX_DIF;

    lua_getglobal(self->main_object->state,self->global_name);
    int table_index = lua_gettop(self->main_object->state);
    long converted_index = privateLuaCEmbedTable_convert_index(self,formatted_index);
    int total = 1;
    lua_pushnil(self->main_object->state);
    while(lua_next(self->main_object->state,table_index)){
        if(total == converted_index){
            bool has_key =lua_type(self->main_object->state,-2) == LUA_CEMBED_STRING;
            lua_pop(self->main_object->state,1);
            PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
            return has_key;
        }

        lua_pop(self->main_object->state,1);
        total+=1;
    }
    PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
    return false;
}

long long  LuaCEmbedTable_get_long_by_index(LuaCEmbedTable *self, int index){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_NUM
    lua_settop(self->main_object->state,0);

    int formatted_index = index + LUA_CEMBED_INDEX_DIF;

    lua_getglobal(self->main_object->state,self->global_name);
    int table_index = lua_gettop(self->main_object->state);
    long converted_index = privateLuaCEmbedTable_convert_index(self,formatted_index);
    int total = 1;

    lua_pushnil(self->main_object->state);
    while(lua_next(self->main_object->state,table_index)){
        if(total == converted_index){
            if(privateLuaCEmbedTable_ensure_type_with_index(self,converted_index,LUA_CEMBED_NUMBER)){
                lua_pop(self->main_object->state,1);
                PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
                return LUA_CEMBED_GENERIC_ERROR;
            }
            long result = (long)lua_tonumber(self->main_object->state,-1);
            lua_pop(self->main_object->state,1);
            PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
            return result;
        }

        lua_pop(self->main_object->state,1);
        total+=1;

    }

    privateLuaCEmbed_raise_error_not_jumping(
            self->main_object,
            PRIVATE_LUA_CEMBED_WRONG_TYPE_INDEX,
            index,
            self->global_name,
            LuaCembed_convert_arg_code(LUA_CEMBED_NIL),
            LuaCembed_convert_arg_code(LUA_CEMBED_NUMBER)
    );
    PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
    return LUA_CEMBED_GENERIC_ERROR;
}

double LuaCEmbedTable_get_double_by_index(LuaCEmbedTable *self, int index){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_NUM

    int formatted_index = index + LUA_CEMBED_INDEX_DIF;

    lua_getglobal(self->main_object->state,self->global_name);
    int table_index = lua_gettop(self->main_object->state);
    long converted_index = privateLuaCEmbedTable_convert_index(self,formatted_index);
    int total = 1;
    lua_pushnil(self->main_object->state);
    while(lua_next(self->main_object->state,table_index)){
        if(total == converted_index){
            if(privateLuaCEmbedTable_ensure_type_with_index(self,converted_index,LUA_CEMBED_NUMBER)){
                lua_pop(self->main_object->state,1);
                PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
                return LUA_CEMBED_GENERIC_ERROR;
            }
            double result = (double )lua_tonumber(self->main_object->state,-1);
            lua_pop(self->main_object->state,1);
            PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
            return result;
        }
        lua_pop(self->main_object->state,1);
        total+=1;

    }

    privateLuaCEmbed_raise_error_not_jumping(
            self->main_object,
            PRIVATE_LUA_CEMBED_WRONG_TYPE_INDEX,
            index,
            self->global_name,
            LuaCembed_convert_arg_code(LUA_CEMBED_NIL),
            LuaCembed_convert_arg_code(LUA_CEMBED_NUMBER)
    );
    PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
    return LUA_CEMBED_GENERIC_ERROR;
}

char * LuaCEmbedTable_get_string_by_index(LuaCEmbedTable *self, int index){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_NULL

    int formatted_index = index + LUA_CEMBED_INDEX_DIF;

    lua_getglobal(self->main_object->state,self->global_name);
    int table_index = lua_gettop(self->main_object->state);
    long converted_index = privateLuaCEmbedTable_convert_index(self,formatted_index);
    int total = 1;
    lua_pushnil(self->main_object->state);
    while(lua_next(self->main_object->state,table_index)){
        if(total == converted_index){
            if(privateLuaCEmbedTable_ensure_type_with_index(self,converted_index,LUA_CEMBED_STRING)){
                lua_pop(self->main_object->state,1);
                PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
                return NULL;
            }
            char * result = (char*)lua_tostring(self->main_object->state,-1);
            lua_pop(self->main_object->state,1);
            PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
            return result;
        }
        lua_pop(self->main_object->state,1);
        total+=1;

    }

    privateLuaCEmbed_raise_error_not_jumping(
            self->main_object,
            PRIVATE_LUA_CEMBED_WRONG_TYPE_INDEX,
            index,
            self->global_name,
            LuaCembed_convert_arg_code(LUA_CEMBED_NIL),
            LuaCembed_convert_arg_code(LUA_CEMBED_STRING)
    );
    PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
    return NULL;
}

bool LuaCEmbedTable_get_bool_by_index(LuaCEmbedTable *self, int index){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_BOOL

    int formatted_index = index + LUA_CEMBED_INDEX_DIF;
    lua_getglobal(self->main_object->state,self->global_name);
    int table_index = lua_gettop(self->main_object->state);
    long converted_index = privateLuaCEmbedTable_convert_index(self,formatted_index);
    int total = 1;
    lua_pushnil(self->main_object->state);
    while(lua_next(self->main_object->state,table_index)){
        if(total == converted_index){
            if(privateLuaCEmbedTable_ensure_type_with_index(self,converted_index,LUA_CEMBED_BOOL)){
                lua_pop(self->main_object->state,1);
                PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
                return LUA_CEMBED_GENERIC_ERROR;
            }
            bool result = lua_toboolean(self->main_object->state,-1);
            lua_pop(self->main_object->state,1);
            PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
            return result;
        }
        lua_pop(self->main_object->state,1);
        total+=1;

    }

    privateLuaCEmbed_raise_error_not_jumping(
            self->main_object,
            PRIVATE_LUA_CEMBED_WRONG_TYPE_INDEX,
            converted_index,
            self->global_name,
            LuaCembed_convert_arg_code(LUA_CEMBED_NIL),
            LuaCembed_convert_arg_code(LUA_CEMBED_BOOL)
    );
    PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
    return LUA_CEMBED_GENERIC_ERROR;
}