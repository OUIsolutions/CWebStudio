

CwebStringArrayModule newCwebStringArrayModule(){
    CwebStringArrayModule self ={0};
    self.newStringArray = newCwebStringArray;
    self.set = CwebStringArray_set;
    self.add = CwebStringArray_add;
    self.merge = CwebStringArray_merge;
    self.represent = CwebStringArray_represent;
    self.find = CwebStringArray_find;
    self.free = CwebStringArray_free;
    return  self;
}
