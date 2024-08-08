
DtwStringArrayModule newDtwStringArrayModule(){
    DtwStringArrayModule self = {0};
    self.newStringArray = newDtwStringArray;
    self.set_value = DtwStringArray_set_value;
    self.append = DtwStringArray_append;
    self.pop = DtwStringArray_pop;
    self.merge = DtwStringArray_merge;
    self.represent = DtwStringArray_represent;
    self.find_position = DtwStringArray_find_position;
    self.sort = DtwStringArray_sort;
    self.free =DtwStringArray_free;
    return self;
}