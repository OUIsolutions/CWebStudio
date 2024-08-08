


int privateLuaCEmbedTable_ensure_type_with_key(LuaCEmbedTable *self, const char *name, int expected_type){
    if(!self){
        return LUA_CEMBED_GENERIC_ERROR;
    }

    int type = lua_type(self->main_object->state,-1);
    if(type == expected_type){
        return  LUA_CEMBED_OK;
    }
    privateLuaCEmbed_raise_error_not_jumping(
            self->main_object,
            PRIVATE_LUA_CEMBED_WRONG_TYPE_PROPETY,
            name,
            self->global_name,
            LuaCembed_convert_arg_code(type),
            LuaCembed_convert_arg_code(expected_type)
    );
    return LUA_CEMBED_GENERIC_ERROR;
}

int privateLuaCEmbedTable_ensure_type_with_index(LuaCEmbedTable *self, long index, int expected_type){
    if(!self){
        return LUA_CEMBED_GENERIC_ERROR;
    }

    int type = lua_type(self->main_object->state,-1);
    if(type == expected_type){
        return  LUA_CEMBED_OK;
    }
    privateLuaCEmbed_raise_error_not_jumping(
            self->main_object,
            PRIVATE_LUA_CEMBED_WRONG_TYPE_INDEX,
            index,
            self->global_name,
            LuaCembed_convert_arg_code(type),
            LuaCembed_convert_arg_code(expected_type)
    );
    return LUA_CEMBED_GENERIC_ERROR;
}