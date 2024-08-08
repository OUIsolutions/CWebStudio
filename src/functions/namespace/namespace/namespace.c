#include "../uniq.definitions_requirements.h"

CwebNamespace newCwebNamespace(){
    CwebNamespace self = {0};
    self.dict = newCwebDictModule();
    self.request = newCwebRequestModule();
    self.response = newCwebHttpResponseModule();
    self.server = newCwebServerModule();
    self.string_array = newCwebStringArrayModule();
    self.hydration = newCWebHydrationNamespace();
    return self;
}

