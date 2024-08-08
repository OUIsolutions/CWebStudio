

LuaCEmbed * newLuaCEmbedEvaluation(){
    LuaCEmbed  *self = (LuaCEmbed*) malloc(sizeof (LuaCEmbed));
    *self = (LuaCEmbed){0};
    self->state = luaL_newstate();

    self->global_tables = (void*)newprivateLuaCEmbedTableArray();

    return self;
}
void LuaCEmbed_load_lib_from_c(LuaCEmbed *self,int (*callback)(lua_State *l),const char *name){
    int result = callback(self->state);
    if(result > 0){
        lua_setglobal(self->state,name);
    }
}





void LuaCembed_set_delete_function(LuaCEmbed *self,void (*delelte_function)(struct  LuaCEmbed *self)){
    self->delete_function = delelte_function;
}




void LuaCEmbed_set_timeout(int seconds){
    lua_cembed_timeout = seconds;
}

char * LuaCEmbed_get_error_message(LuaCEmbed *self){
    if(!self){
        return NULL;
    }

    return self->error_msg;
}
void LuaCEmbed_clear_errors(LuaCEmbed *self){
    if(!self){
        return;
    }

    if(self->error_msg){
        free(self->error_msg);
        self->error_msg = NULL;
    }
}
void * privateLuaCEmbed_get_current_table_array(LuaCEmbed *self){
    if(self->current_function){
       return  self->func_tables;
    }
    return self->global_tables;
}
void privateLuaCEmbed_raise_error_not_jumping(LuaCEmbed *self, const char *error_msg, ...){

    if(LuaCEmbed_has_errors(self)){
        return;
    }

    va_list args;
    va_start(args,error_msg);
    self->error_msg = private_LuaCembed_format_vaarg(error_msg, args);
    va_end(args);

}



bool LuaCEmbed_has_errors(LuaCEmbed *self){
    if(!self){
        return true;
    }

    if(self->error_msg){
        return  true;
    }

    return false;
}






void privata_LuaCEmbed_increment_stack_(LuaCEmbed *self){
    lua_getglobal(self->state,PRIVATE_LUA_CEMBED_STACK_LEVEL);
    int value = 0;
    if(lua_type(self->state,-1) == LUA_CEMBED_NUMBER){
        value =  lua_tonumber(self->state,-1);
    }
    int new_value = value+1;
    lua_pushinteger(self->state,new_value);
    lua_setglobal(self->state,PRIVATE_LUA_CEMBED_STACK_LEVEL);
    self->stack_leve =new_value;
}


void  privata_LuaCEmbed_decrement_stack(LuaCEmbed *self){
    lua_getglobal(self->state,PRIVATE_LUA_CEMBED_STACK_LEVEL);
    int value = 0;
    if(lua_type(self->state,-1) == LUA_CEMBED_NUMBER){
        value =  lua_tointeger(self->state,-1);
    }
    if(value> 0){
        int new_value = value -1;
        lua_pushinteger(self->state,new_value);
        lua_setglobal(self->state,PRIVATE_LUA_CEMBED_STACK_LEVEL);
        self->stack_leve = new_value;
    }

}

void privateLuaCEmbd_get_field_protected(LuaCEmbed *self,const char *name){
    bool old_field_proection = self->field_protection;
    self->field_protection = true;
    lua_getfield(self->state,-1,name);
    self->field_protection = old_field_proection;
}

void LuaCEmbed_free(LuaCEmbed *self){
    privateLuaCEmbedTableArray_free((privateLuaCEmbedTableArray*)self->global_tables);
    if(!self->is_lib){ //se for do próprio lua, o lua cuidará de limpar
        lua_close(self->state); // Fecha o estado Lua
    }
    if(self->error_msg){
        free(self->error_msg);
    }
    if(self->main_lib_table){
        free(self->main_lib_table);
    }
    free(self);
}
