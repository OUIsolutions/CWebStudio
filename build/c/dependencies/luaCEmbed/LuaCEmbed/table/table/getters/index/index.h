

char *LuaCembedTable_get_key_by_index(LuaCEmbedTable *self, long index);

bool LuaCembedTable_has_key_at_index(LuaCEmbedTable *self, long index);

long  LuaCEmbedTable_get_full_size(LuaCEmbedTable *self);

long  LuaCEmbedTable_get_listable_size(LuaCEmbedTable *self);


long  privateLuaCEmbedTable_convert_index(LuaCEmbedTable *self, private_lua_cembed_incremented_arg index);

int LuaCEmbedTable_get_type_by_index(LuaCEmbedTable *self, int index);

long long LuaCEmbedTable_get_long_by_index(LuaCEmbedTable *self, int index);

double LuaCEmbedTable_get_double_by_index(LuaCEmbedTable *self, int index);

char * LuaCEmbedTable_get_string_by_index(LuaCEmbedTable *self, int index);

bool LuaCEmbedTable_get_bool_by_index(LuaCEmbedTable *self, int index);


