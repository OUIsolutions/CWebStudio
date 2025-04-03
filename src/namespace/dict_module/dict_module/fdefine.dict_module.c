//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.dep_define.h"
//silver_chain_scope_end

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
