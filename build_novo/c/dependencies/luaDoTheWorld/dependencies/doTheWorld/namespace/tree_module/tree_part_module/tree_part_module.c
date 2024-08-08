

DtwTreePartModule newDtwTreePartModule(){
    DtwTreePartModule self ={0};
    self.newPart = newDtwTreePart;
    self.newPartEmpty = newDtwTreePartEmpty;
    self.newPartLoading = newDtwTreePartLoading;
    self.get_content_string_by_reference = DtwTreePart_get_content_string_by_reference;
    self.get_content_binary_by_reference = DtwTreePart_get_content_binary_by_reference;
    self.get_content_sha = DtwTreePart_get_content_sha;
    self.set_any_content = DtwTreePart_set_any_content;
    self.set_string_content = DtwTreePart_set_string_content;
    self.set_binary_content = DtwTreePart_set_binary_content;
    self.load_content_from_hardware =DtwTreePart_load_content_from_hardware;
    self.free_content = DtwTreePart_free_content;
    self.represent =DtwTreePart_represent;
    self.hardware_remove = DtwTreePart_hardware_remove;
    self.hardware_write = DtwTreePart_hardware_write;
    self.hardware_modify = DtwTreePart_hardware_modify;
    self.hardware_commit =DtwTreePart_hardware_commit;

    self.free = DtwTreePart_free;
    self.self_copy = DtwTreePart_self_copy;


    return self;
}
