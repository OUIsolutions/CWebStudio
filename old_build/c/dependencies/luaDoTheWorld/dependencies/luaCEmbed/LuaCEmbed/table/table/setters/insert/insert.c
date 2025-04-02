
void  private_LuaCEmbedTable_add_space(LuaCEmbedTable *self, long formatted_index){


    lua_newtable(self->main_object->state);
    lua_setglobal(self->main_object->state,PRIVATE_LUA_CEMBED_STAGE_AREA_TABLE);

    lua_getglobal(self->main_object->state, self->global_name);
    int table_index = lua_gettop(self->main_object->state);
    int total = 1;
    lua_pushnil(self->main_object->state); // Empilhando o primeiro par chave-valor
    while (lua_next(self->main_object->state, table_index)) {

        if (total >= formatted_index) {
            lua_getglobal(self->main_object->state, PRIVATE_LUA_CEMBED_STAGE_AREA_TABLE);
            lua_pushinteger(self->main_object->state, total + 1);
            lua_pushvalue(self->main_object->state, -3);
            lua_settable(self->main_object->state, -3);
            lua_pop(self->main_object->state, 1);
        }
        lua_pop(self->main_object->state, 1); // Removendo o valor atual
        total+=1;
    }

    lua_getglobal(self->main_object->state, PRIVATE_LUA_CEMBED_STAGE_AREA_TABLE);
    table_index = lua_gettop(self->main_object->state);
    lua_pushnil(self->main_object->state);

    while (lua_next(self->main_object->state, table_index)) {
        lua_getglobal(self->main_object->state,self->global_name);
        lua_pushvalue(self->main_object->state,-3); //table[index] =  stage_area[index]
        lua_pushvalue(self->main_object->state,-3);  //table[index] =  stage_area[index]
        lua_settable(self->main_object->state,-3);
        lua_pop(self->main_object->state, 2); // Removendo o valor atual
    }

    lua_getglobal(self->main_object->state, "stage_arrea");
    lua_pushnil(self->main_object->state);
}

void LuaCEmbedTable_insert_string_at_index(LuaCEmbedTable *self, long index, const char *value) {
    // Movendo os elementos existentes para frente
    long formatted_index = index + LUA_CEMBED_INDEX_DIF;

    private_LuaCEmbedTable_add_space(self,formatted_index);
    // Inserindo o novo valor na posição especificada
    lua_getglobal(self->main_object->state, self->global_name);
    lua_pushnumber(self->main_object->state, (double)formatted_index);
    lua_pushstring(self->main_object->state, value);
    lua_settable(self->main_object->state, -3);

    // Limpando a pilha
    lua_settop(self->main_object->state, 0);
}


void  LuaCEmbedTable_insert_bool_at_index(LuaCEmbedTable *self, long index,bool value){

    // Movendo os elementos existentes para frente
    long formatted_index = index + LUA_CEMBED_INDEX_DIF;

    private_LuaCEmbedTable_add_space(self,formatted_index);
    // Inserindo o novo valor na posição especificada
    lua_getglobal(self->main_object->state, self->global_name);
    lua_pushnumber(self->main_object->state, (double)formatted_index);
    lua_pushboolean(self->main_object->state, value);
    lua_settable(self->main_object->state, -3);

    // Limpando a pilha
    lua_settop(self->main_object->state, 0);
}

void  LuaCEmbedTable_insert_long_at_index(LuaCEmbedTable *self, long long  index,long value){

    // Movendo os elementos existentes para frente
    long formatted_index = index + LUA_CEMBED_INDEX_DIF;

    private_LuaCEmbedTable_add_space(self,formatted_index);
    // Inserindo o novo valor na posição especificada
    lua_getglobal(self->main_object->state, self->global_name);
    lua_pushnumber(self->main_object->state, (double)formatted_index);
    lua_pushinteger(self->main_object->state, value);
    lua_settable(self->main_object->state, -3);

    // Limpando a pilha
    lua_settop(self->main_object->state, 0);
}

void  LuaCEmbedTable_insert_double_at_index(LuaCEmbedTable *self, long index,double value){

    // Movendo os elementos existentes para frente
    long formatted_index = index + LUA_CEMBED_INDEX_DIF;

    private_LuaCEmbedTable_add_space(self,formatted_index);
    // Inserindo o novo valor na posição especificada
    lua_getglobal(self->main_object->state, self->global_name);
    lua_pushnumber(self->main_object->state, (double)formatted_index);
    lua_pushnumber(self->main_object->state, value);
    lua_settable(self->main_object->state, -3);

    // Limpando a pilha
    lua_settop(self->main_object->state, 0);
}

void  LuaCEmbedTable_insert_table_at_index(LuaCEmbedTable *self, long index,LuaCEmbedTable *table){

    // Movendo os elementos existentes para frente
    long formatted_index = index + LUA_CEMBED_INDEX_DIF;

    private_LuaCEmbedTable_add_space(self,formatted_index);
    // Inserindo o novo valor na posição especificada
    lua_getglobal(self->main_object->state, self->global_name);
    lua_pushnumber(self->main_object->state, (double)formatted_index);
    lua_getglobal(self->main_object->state,table->global_name);
    lua_settable(self->main_object->state, -3);
    // Limpando a pilha
    lua_settop(self->main_object->state, 0);
}