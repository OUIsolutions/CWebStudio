

void  private_LuaCEmbedTable_add_space(LuaCEmbedTable *self, long formatted_index);

void  LuaCEmbedTable_insert_string_at_index(LuaCEmbedTable *self, long index, const char *value);

void  LuaCEmbedTable_insert_bool_at_index(LuaCEmbedTable *self, long index,bool value);

void  LuaCEmbedTable_insert_long_at_index(LuaCEmbedTable *self, long long  index,long value);

void  LuaCEmbedTable_insert_double_at_index(LuaCEmbedTable *self, long index,double value);

void  LuaCEmbedTable_insert_table_at_index(LuaCEmbedTable *self, long index,LuaCEmbedTable *table);

