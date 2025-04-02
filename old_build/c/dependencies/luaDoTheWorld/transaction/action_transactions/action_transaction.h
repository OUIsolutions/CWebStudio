
LuaCEmbedResponse  *action_transaction_get_transaction_type_code(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  *action_transaction_get_transaction_type(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  *action_transaction_get_content(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  *action_transaction_set_content(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  *action_transaction_set_source(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  *action_transaction_set_dest(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  *action_transaction_get_source(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  *action_transaction_get_dest(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedTable *raw_create_action_transaction(LuaCEmbed *args,DtwActionTransaction *transaction);
