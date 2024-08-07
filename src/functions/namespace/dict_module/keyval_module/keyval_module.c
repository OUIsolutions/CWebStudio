
#include "../uniq.definitions_requirements.h"


CwebKeyValModule newCwebKeyValModule(){
    CwebKeyValModule self = {0};
    self.represent = CwebKeyVal_represent;
    self.free = CwebKeyVal_free;

    return self;
}
