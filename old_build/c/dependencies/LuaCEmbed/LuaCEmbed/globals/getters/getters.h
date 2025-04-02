

int LuaCEmbed_get_global_type(LuaCEmbed *self,const char *name);

long long  LuaCEmbed_get_global_long(LuaCEmbed *self,const char *name);

double LuaCEmbed_get_global_double(LuaCEmbed *self,const char *name);

bool LuaCEmbed_get_global_bool(LuaCEmbed *self,const char *name);

char * LuaCEmbed_get_global_string(LuaCEmbed *self,const char *name);

char * LuaCEmbed_get_global_raw_string(LuaCEmbed *self,const char *name,long *size);


LuaCEmbedTable * LuaCembed_new_anonymous_table(LuaCEmbed *self);

LuaCEmbedTable* LuaCEmbed_run_global_lambda(LuaCEmbed *self, const char *name, LuaCEmbedTable *args_to_call, int total_returns);

LuaCEmbedTable * LuaCembed_get_global_table(LuaCEmbed *self, const char *name);

LuaCEmbedTable * LuaCembed_new_global_table(LuaCEmbed *self, const char *name);
