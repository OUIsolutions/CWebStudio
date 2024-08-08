//
// Created by mateusmoutinho on 22/05/24.
//
LuaCEmbedResponse * resource_new_schema(LuaCEmbedTable  *self, LuaCEmbed *args);

LuaCEmbedResponse * resource_try_new_schema(LuaCEmbedTable  *self, LuaCEmbed *args);


LuaCEmbedResponse  * Resource_new_insertion(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedResponse  * Resource_try_new_insertion(LuaCEmbedTable *self, LuaCEmbed *args);


LuaCEmbedResponse  * get_resource_match_schema_by_primary_key(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedResponse  * try_get_resource_match_schema_by_primary_key(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedResponse  * get_resource_by_name_id(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedResponse  * try_get_resource_by_name_id(LuaCEmbedTable *self, LuaCEmbed *args);

LuaCEmbedResponse  * dangerous_rename_schema_prop(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  * try_dangerous_rename_schema_prop(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  * dangerous_remove_schema_prop(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse  * try_dangerous_remove_schema_prop(LuaCEmbedTable *self,LuaCEmbed *args);

