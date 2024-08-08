

int LuaCEmbed_ensure_arg_exist(LuaCEmbed *self, private_lua_cembed_incremented_arg index){
    PRIVATE_LUA_CEMBED_PROTECT_NUM

    if(index > self->total_args){

        privateLuaCEmbed_raise_error_not_jumping(self, PRIVATE_LUA_CEMBED_ARG_NOT_PROVIDED,index,self->current_function);
        return LUA_CEMBED_GENERIC_ERROR;
    }
    return LUA_CEMBED_OK;

}

int private_LuaCEmbed_ensure_top_stack_arg_type(LuaCEmbed *self, int index,int arg_type) {
    PRIVATE_LUA_CEMBED_PROTECT_NUM
    int type = lua_type(self->state, -1);
    if (type != arg_type) {

        privateLuaCEmbed_raise_error_not_jumping(self,
             PRIVATE_LUA_CEMBED_ARG_WRONG_TYPE,
             index + LUA_CEMBED_INDEX_DIF,
             self->current_function,
             LuaCembed_convert_arg_code(type),
             LuaCembed_convert_arg_code(arg_type)
        );
        return LUA_CEMBED_GENERIC_ERROR;
    }

    return LUA_CEMBED_OK;

}

