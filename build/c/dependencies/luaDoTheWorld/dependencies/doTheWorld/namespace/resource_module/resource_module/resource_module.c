
DtwResourceModule newDtwResourceModule(){
    DtwResourceModule self = {0};
    self.newResource = new_DtwResource;
    self.get_error_code = DtwResource_get_error_code;
    self.get_error_message = DtwResource_get_error_message;
    self.error = DtwResource_error;
    self.load = DtwResource_load;
    self.clear_errors = DtwResource_clear_errors;
    self.unload = DtwResource_unload;
    self.sub_resource = DtwResource_sub_resource;
    self.get_any_from_sub_resource = DtwResource_get_any_from_sub_resource;
    self.get_binary_from_sub_resource = DtwResource_get_binary_from_sub_resource;
    self.get_string_from_sub_resource = DtwResource_get_string_from_sub_resource;
    self.get_long_from_sub_resource = DtwResource_get_long_from_sub_resource;
    self.get_double_from_sub_resource = DtwResource_get_double_from_sub_resource;
    self.get_bool_from_sub_resource = DtwResource_get_bool_from_sub_resource;
    self.get_error_path = DtwResource_get_error_path;
    self.get_schema_values = DtwResource_get_schema_values;
    self.set_binary_in_sub_resource = DtwResource_set_binary_in_sub_resource;
    self.set_string_in_sub_resource = DtwResource_set_string_in_sub_resource;
    self.set_long_in_sub_resource = DtwResource_set_long_in_sub_resource;
    self.set_double_in_sub_resource = DtwResource_set_double_in_sub_resource;
    self.set_bool_in_sub_resource = DtwResource_set_bool_in_sub_resource;
    self.is_file = DtwResource_is_file;
    self.sub_resource_ensuring_not_exist = DtwResource_sub_resource_ensuring_not_exist;
    self.sub_resource_next = DtwResource_sub_resource_next;
    self.destroy_sub_resource = DtwResource_destroy_sub_resource;
    self.rename_sub_resource = DtwResource_rename_sub_resource;
    self.sub_resource_now  = DtwResource_sub_resource_now;
    self.sub_resource_now_in_unix = DtwResource_sub_resource_now_in_unix;
    self.sub_resource_random = DtwResource_sub_resource_random;
    self.set_binary_sha =DtwResource_set_binary_sha;
    self.set_string_sha = DtwResource_set_string_sha;
    self.set_any_in_sub_resource = DtwResource_set_any_in_sub_resource;
    self.set_binary_sha_in_sub_resource = DtwResource_set_binary_sha_in_sub_resource;
    self.set_string_sha_in_sub_resource = DtwResource_set_string_sha_in_sub_resource;

    self.new_schema_insertion = DtwResource_new_schema_insertion;
    self.find_by_name_id = DtwResource_find_by_name_id;
    self.find_by_primary_key_with_string = DtwResource_find_by_primary_key_with_string;
    self.find_by_primary_key_with_binary = DtwResource_find_by_primary_key_with_binary;
    self.dangerous_remove_schema_prop = DtwResource_dangerous_remove_schema_prop;
    self.dangerous_rename_schema_prop = DtwResource_dangerous_rename_schema_prop;
    self.newDatabaseSchema = DtwResource_newDatabaseSchema;

    self.lock =DtwResource_lock;
    self.unlock = DtwResource_unlock;
    self.destroy = DtwResource_destroy;

    self.get_any = DtwResource_get_any;
    self.get_string = DtwResource_get_string;
    self.get_binary = DtwResource_get_binary;
    self.get_double = DtwResource_get_double;
    self.get_long = DtwResource_get_long;
    self.get_bool = DtwResource_get_bool;

    self.set_any = DtwResource_set_any;
    self.set_binary = DtwResource_set_binary;
    self.set_string = DtwResource_set_string;
    self.set_long = DtwResource_set_long;
    self.set_double = DtwResource_set_double;
    self.set_bool = DtwResource_set_bool;


    self.list_names = DtwResource_list_names;
    self.size = DtwResource_size;
    self.type = DtwResource_type;
    self.type_in_str = DtwResource_type_in_str;
    self.commit =DtwResource_commit;
    self.represent = DtwResource_represent;
    self.rename = DtwResource_rename;
    self.free  = DtwResource_free;
    self.sub_resources = DtwResource_sub_resources;
    self.array = newDtwResourceArrayModule();

    return self;
}