
LuaCEmbedTable  *LuaCEmbedTable_new_sub_table_appending(LuaCEmbedTable *self){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_NULL



    //equivalent of: full_sub_table_name = {}
    long index= LuaCEmbedTable_get_listable_size(self) +1;
    char *full_sub_table_name = private_LuaCembed_format("%s_%d", self->global_name, index);
    lua_newtable(self->main_object->state);
    lua_setglobal(self->main_object->state,full_sub_table_name);


    //equivalent of: table[index] = full_sub_table_name
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushinteger(self->main_object->state,index);
    lua_getglobal(self->main_object->state,full_sub_table_name);
    lua_settable(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);

    LuaCEmbedTable  *possible = privateLuaCEmbedTableArray_find_by_internal_index(
            (privateLuaCEmbedTableArray *) self->sub_tables,
            index
    );

    if(possible){
        free(full_sub_table_name);
        PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
        return possible;
    }

    LuaCEmbedTable  *created = private_newLuaCembedTable(self->main_object, full_sub_table_name);
    created->index = index;

    privateLuaCEmbedTableArray_append(
            (privateLuaCEmbedTableArray*)self->sub_tables,
            created
    );

    free(full_sub_table_name);
    PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
    return created;
}

LuaCEmbedTable  *LuaCEmbedTable_get_sub_table_by_index(LuaCEmbedTable *self, long index){

    PRIVATE_LUA_CEMBED_TABLE_PROTECT_NULL


    long formatted_index = index + LUA_CEMBED_INDEX_DIF;

    lua_getglobal(self->main_object->state,self->global_name);
    int table_index = lua_gettop(self->main_object->state);
    long converted_index = privateLuaCEmbedTable_convert_index(self,formatted_index);
    int total = 1;

    lua_pushnil(self->main_object->state);
    while(lua_next(self->main_object->state,table_index)){
        if(total == converted_index){

            if(privateLuaCEmbedTable_ensure_type_with_index(self,converted_index,LUA_CEMBED_TABLE)){
                lua_pop(self->main_object->state,1);
                PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
                return NULL;
            }

            //equivalent of full_sub_table_name = table[index]
            char *full_sub_table_name = private_LuaCembed_format("%s_%d", self->global_name, index);
            lua_setglobal(self->main_object->state,full_sub_table_name);

            LuaCEmbedTable  *possible = privateLuaCEmbedTableArray_find_by_internal_index(
                    (privateLuaCEmbedTableArray *) self->sub_tables,
                    index
            );

            if(possible){
                free(full_sub_table_name);
                lua_pop(self->main_object->state,1);
                PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
                return possible;
            }

            LuaCEmbedTable  *created = private_newLuaCembedTable(self->main_object, full_sub_table_name);
            created->index = index;

            privateLuaCEmbedTableArray_append(
                    (privateLuaCEmbedTableArray*)self->sub_tables,
                    created
            );

            free(full_sub_table_name);
            lua_pop(self->main_object->state,1);
            PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
            return created;
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
            LuaCembed_convert_arg_code(LUA_CEMBED_TABLE)
    );
    PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
    return NULL;
}

void LuaCEmbedTable_set_sub_table_by_index(LuaCEmbedTable *self, long index,LuaCEmbedTable *sub_table){
    PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID


    char *possible_key = LuaCembedTable_get_key_by_index(self,index);
    if(possible_key){
        LuaCEmbedTable_set_sub_table_prop(self,possible_key,sub_table);
        PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
        return;
    }

    long formatted_index = index + LUA_CEMBED_INDEX_DIF;
    lua_getglobal(self->main_object->state,self->global_name);
    lua_pushinteger(self->main_object->state,formatted_index);
    lua_getglobal(self->main_object->state,sub_table->global_name);
    lua_settable(self->main_object->state,-3);
    lua_settop(self->main_object->state, 0);
    PRIVATE_LUA_CEMBED_TABLE_CLEAR_STACK
}
