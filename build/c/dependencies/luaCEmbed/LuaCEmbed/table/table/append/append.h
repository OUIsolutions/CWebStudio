

void  LuaCEmbedTable_append_table(LuaCEmbedTable *self, LuaCEmbedTable *table);


void  LuaCEmbedTable_append_evaluation(LuaCEmbedTable *self, const char *code, ...);

void  LuaCEmbedTable_append_string(LuaCEmbedTable *self,  const char *value);

void  LuaCEmbedTable_append_long(LuaCEmbedTable *self,  long long  value);

void  LuaCEmbedTable_append_double(LuaCEmbedTable *self, double  value);

void  LuaCEmbedTable_append_bool(LuaCEmbedTable *self,  bool value);