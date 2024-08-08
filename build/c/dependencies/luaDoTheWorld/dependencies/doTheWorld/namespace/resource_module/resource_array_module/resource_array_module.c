DtwResourceArrayModule newDtwResourceArrayModule(){
    DtwResourceArrayModule self = {0};
    self.append = DtwResourceArray_append;
    self.represent = DtwResourceArray_represent;
    self.get_by_name = DtwResourceArray_get_by_name;
    self.free = DtwResourceArray_free;
    return self;
}
