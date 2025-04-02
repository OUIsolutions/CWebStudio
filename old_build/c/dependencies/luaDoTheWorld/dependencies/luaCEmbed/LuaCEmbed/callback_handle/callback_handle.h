

int privateLuaCEmbed_main_callback_handler(lua_State  *L);

void private_LuaCEmbed_add_lib_callback(LuaCEmbed *self, const char *callback_name, LuaCEmbedResponse* (*callback)(LuaCEmbed *args),bool global_functions );

void private_LuaCEmbed_add_evaluation_callback(LuaCEmbed *self, const char *callback_name, LuaCEmbedResponse* (*callback)(LuaCEmbed *args) );

void LuaCEmbed_add_callback(LuaCEmbed *self, const char *callback_name, LuaCEmbedResponse* (*callback)(LuaCEmbed *args) );


void LuaCEmbed_add_global_callback(LuaCEmbed *self, const char *callback_name, LuaCEmbedResponse* (*callback)(LuaCEmbed *args));

