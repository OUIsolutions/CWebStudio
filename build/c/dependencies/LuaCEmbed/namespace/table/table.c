

LuaCembedTableModule newLuaCembedTableModule(){
    LuaCembedTableModule self ={0};

    self.append_string = LuaCEmbedTable_append_string;
    self.append_bool = LuaCEmbedTable_append_bool;
    self.append_double = LuaCEmbedTable_append_double;
    self.append_long = LuaCEmbedTable_append_long;
    self.append_table = LuaCEmbedTable_append_table;
    self.append_evaluation = LuaCEmbedTable_append_evaluation;

    self.insert_string_at_index = LuaCEmbedTable_insert_string_at_index;
    self.insert_double_at_index = LuaCEmbedTable_insert_double_at_index;
    self.insert_long_at_index = LuaCEmbedTable_insert_long_at_index;
    self.insert_table_at_index = LuaCEmbedTable_insert_table_at_index;

    self.set_evaluation_prop = LuaCEmbedTable_set_evaluation_prop;
    self.set_method = LuaCEmbedTable_set_method;
    self.set_method = LuaCEmbedTable_set_method;
    self.set_bool_prop = LuaCEmbedTable_set_bool_prop;
    self.set_double_prop = LuaCEmbedTable_set_double_prop;
    self.set_long_prop = LuaCEmbedTable_set_long_prop;
    self.set_string_prop = LuaCEmbedTable_set_string_prop;

    self.get_sub_table_prop = LuaCEmbedTable_get_sub_table_by_key;
    self.new_sub_table_prop = LuaCEmbedTable_new_sub_table_by_key;
    self.set_sub_table_prop = LuaCEmbedTable_set_sub_table_prop;
    self.new_anonymous_table = LuaCembed_new_anonymous_table;

    self.set_sub_table_by_index = LuaCEmbedTable_set_sub_table_by_index;
    self.get_bool_prop = LuaCembedTable_get_bool_prop;
    self.get_double_prop = LuaCembedTable_get_double_prop;
    self.get_long_prop = LuaCembedTable_get_long_prop;
    self.get_string_prop = LuaCembedTable_get_string_prop;
    self.get_type_prop = LuaCEmbedTable_get_type_prop;
    self.destroy_prop = LuaCembedTable_destroy_prop;

    self.set_long_by_index = LuaCEmbedTable_set_long_by_index;
    self.set_bool_by_index= LuaCEmbedTable_set_bool_by_index;
    self.set_double_by_index =LuaCEmbedTable_set_double_by_index;
    self.set_string_by_index = LuaCEmbedTable_set_string_by_index;
    self.set_evaluation_by_index = LuaCEmbedTable_set_evaluation_by_index;

    self.get_listable_size = LuaCEmbedTable_get_listable_size;

    self.new_sub_table_appending = LuaCEmbedTable_new_sub_table_appending;
    self.has_key = LuaCembedTable_has_key_at_index;
    self.get_key_by_index = LuaCembedTable_get_key_by_index;
    self.get_size = LuaCEmbedTable_get_full_size;
    self.get_type_by_index = LuaCEmbedTable_get_type_by_index;
    self.get_long_by_index = LuaCEmbedTable_get_long_by_index;
    self.get_double_by_index = LuaCEmbedTable_get_double_by_index;
    self.get_bool_by_index = LuaCEmbedTable_get_bool_by_index;
    self.get_string_by_index= LuaCEmbedTable_get_string_by_index;
    self.get_sub_table_by_index = LuaCEmbedTable_get_sub_table_by_index;
    return self;
}
