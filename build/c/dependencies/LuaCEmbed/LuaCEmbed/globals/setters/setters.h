
void LuaCEmbed_set_global_string(LuaCEmbed *self, const char *name, const  char *value);

void LuaCEmbed_set_global_raw_string(LuaCEmbed *self, const char *name, const  char *value,long size);

void LuaCEmbed_set_global_long(LuaCEmbed *self, const char *name, long long  value);

void LuaCEmbed_set_global_double(LuaCEmbed *self, const char *name, double value);

void LuaCEmbed_set_global_bool(LuaCEmbed *self, const char *name, bool value);

void LuaCEmbed_set_global_table(LuaCEmbed *self, const char *name, LuaCEmbedTable *table);
