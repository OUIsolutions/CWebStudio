//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.dep_define.h"
//silver_chain_scope_end


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
