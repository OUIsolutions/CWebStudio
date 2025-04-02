
LuaCEmbedResponse *path_changed(LuaCEmbedTable *self,LuaCEmbed *args);


LuaCEmbedResponse *path_add_start_dir(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_add_end_dir(LuaCEmbedTable *self,LuaCEmbed *args);


LuaCEmbedResponse *path_get_dir(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_get_extension(LuaCEmbedTable *self,LuaCEmbed *args);


LuaCEmbedResponse *path_get_name(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_get_only_name(LuaCEmbedTable *self,LuaCEmbed *args);


LuaCEmbedResponse *path_get_full_path(LuaCEmbedTable *self,LuaCEmbed *args);


LuaCEmbedResponse *path_to_string(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_set_name(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_set_only_name(LuaCEmbedTable *self,LuaCEmbed *args);


LuaCEmbedResponse *path_set_extension(LuaCEmbedTable *self,LuaCEmbed *args);


LuaCEmbedResponse *path_set_dir(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_set_path(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_replace_dirs(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_get_total_dirs(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_get_sub_dirs_from_index(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_insert_dir_at_index(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_remove_sub_dir_at_index(LuaCEmbedTable *self,LuaCEmbed *args);


LuaCEmbedResponse *path_insert_dir_after(LuaCEmbedTable *self,LuaCEmbed *args);


LuaCEmbedResponse *path_insert_dir_before(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_remove_sub_dirs_at(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedResponse *path_unpack(LuaCEmbedTable *self,LuaCEmbed *args);


LuaCEmbedResponse *path_delete(LuaCEmbedTable *self,LuaCEmbed *args);

LuaCEmbedTable *raw_create_path(LuaCEmbed *args,DtwPath *path);


LuaCEmbedTable *create_path_reference(LuaCEmbed *args,DtwPath *path);


LuaCEmbedResponse *create_path(LuaCEmbed *args);

