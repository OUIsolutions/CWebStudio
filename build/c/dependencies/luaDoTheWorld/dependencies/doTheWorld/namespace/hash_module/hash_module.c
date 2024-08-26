

DtwHashModule newDtwHashModule(){
    DtwHashModule self = {0};
    self.newHash =newDtwHash;
    self.digest_any = DtwHash_digest_any;
    self.digest_string = DtwHash_digest_string;
    self.digest_long = DtwHash_digest_long;
    self.digest_double = DtwHash_digest_double;
    self.digest_bool = DtwHash_digest_bool;
    self.digest_file = DtwHash_digest_file;
    self.digest_entity_last_modification =DtwHash_digest_entity_last_modification;
    self.digest_string_array = DtwHash_digest_string_array;
    self.digest_string_array_last_modifications = DtwHash_digest_string_array_last_modifications;
    self.digest_string_array_last_modifications_adding_name = DtwHash_digest_string_array_last_modifications_adding_name;
    self.digest_string_array_content = DtwHash_digest_string_array_content;
    self.digest_string_array_content_adding_name = DtwHash_digest_string_array_content_adding_name;
    self.digest_folder_by_last_modification = DtwHash_digest_folder_by_last_modification;
    self.digest_folder_by_content = DtwHash_digest_folder_by_content;
    self.free = DtwHash_free;
    return self;
}