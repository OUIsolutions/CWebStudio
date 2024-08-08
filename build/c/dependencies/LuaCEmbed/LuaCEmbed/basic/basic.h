


LuaCEmbed * newLuaCEmbedEvaluation();


int private_LuaCemb_internal_free(lua_State *L);

void LuaCEmbed_load_lib_from_c(LuaCEmbed *self,int (*callback)(lua_State *l),const char *name);

void LuaCEmbed_load_native_libs(LuaCEmbed *self);

void LuaCembed_set_delete_function(LuaCEmbed *self,void (*delelte_function)(struct  LuaCEmbed *self));

char * LuaCEmbed_get_error_message(LuaCEmbed *self);


bool LuaCEmbed_has_errors(LuaCEmbed *self);

void LuaCEmbed_clear_errors(LuaCEmbed *self);

void privateLuaCEmbd_get_field_protected(LuaCEmbed *self,const char *name);

void privateLuaCEmbed_raise_error_not_jumping(LuaCEmbed *self, const char *error, ...);

void * privateLuaCEmbed_get_current_table_array(LuaCEmbed *self);


void LuaCEmbed_set_timeout(int seconds);



void  privata_LuaCEmbed_increment_stack_(LuaCEmbed *self);


void  privata_LuaCEmbed_decrement_stack(LuaCEmbed *self);

void LuaCEmbed_free(LuaCEmbed *self);


