
CwebDictModule newCwebDictModule(){
    CwebDictModule self = {0};
    self.newDict = newCwebDict;
    self.set = CwebDict_set;
    self.get = CwebDict_get;
    self.get_by_normalized_key = CwebDict_get_by_normalized_key;
    self.free = CwebDict_free;
    self.represent = CwebDict_represent;

    self.keyval = newCwebKeyValModule();
    return  self;
}