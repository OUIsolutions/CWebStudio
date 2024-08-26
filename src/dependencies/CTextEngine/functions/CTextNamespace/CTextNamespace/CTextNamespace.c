
#include "../unique.definition_requirements.h"

CTextNamespace newCTextNamespace(){
    CTextNamespace self  = {0};
    self.stack = newCTextStackModule();
    self.array = newCTextArrayModule();
    return self;
}
