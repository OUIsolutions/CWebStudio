LuaCEmbedResponse * transaction_commit(LuaCEmbedTable *self,LuaCEmbed *args);


LuaCEmbedResponse * transaction_delete(LuaCEmbedTable *self,LuaCEmbed *args);

void  private_transaction_add_base_methods(LuaCEmbedTable *self,DtwTransaction *transaction);


LuaCEmbedResponse * transaction_new_transaction(LuaCEmbed *args);