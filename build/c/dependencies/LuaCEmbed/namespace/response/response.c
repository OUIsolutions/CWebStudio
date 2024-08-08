

LuaCEmbedResponseModule newLuaCEmbedResponseModule(){
    LuaCEmbedResponseModule self = {0};
    self.send_multi_return = LuaCEmbed_send_multi_return;
    self.send_str = LuaCEmbed_send_str;
    self.send_str_reference = LuaCEmbed_send_str_reference;
    self.send_raw_string = LuaCEmbed_send_raw_string;
    self.send_raw_string_reference = LuaCEmbed_send_raw_string_reference;
    self.send_bool = LuaCEmbed_send_bool;
    self.send_double = LuaCEmbed_send_double;
    self.send_evaluation_function =  LuaCEmbed_send_evaluation;
    self.send_long = LuaCEmbed_send_long;
    self.send_table = LuaCEmbed_send_table;
    self.send_error = LuaCEmbed_send_error;
    return  self;
}
