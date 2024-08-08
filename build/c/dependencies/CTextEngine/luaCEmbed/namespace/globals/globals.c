

LuaCEmbedGlobalModule newLuaCEmbedGlobalModule(){
    LuaCEmbedGlobalModule self = {0};
    self.ensure_type = LuaCEmbed_ensure_global_type;
    self.get_double = LuaCEmbed_get_global_double;
    self.get_string = LuaCEmbed_get_global_string;
    self.get_long = LuaCEmbed_get_global_long;
    self.get_raw_string = LuaCEmbed_get_global_raw_string;
    self.set_raw_string = LuaCEmbed_set_global_raw_string;
    self.get_bool = LuaCEmbed_get_global_bool;
    self.get_type = LuaCEmbed_get_global_type;
    self.run_global_lambda = LuaCEmbed_run_global_lambda;
    self.set_table = LuaCEmbed_set_global_table;
    self.set_string = LuaCEmbed_set_global_string;
    self.set_bool = LuaCEmbed_set_global_bool;
    self.set_double = LuaCEmbed_set_global_double;
    self.set_long = LuaCEmbed_set_global_long;
    self.new_table = LuaCembed_new_global_table;
    self.get_table = LuaCembed_get_global_table;

    return self;
}