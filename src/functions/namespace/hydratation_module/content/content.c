#include "../uniq.definitions_requirements.h"

CWebHydrationContentNamespace newCWebHydrationContentNamespace(){
    CWebHydrationContentNamespace self = {0};
    self.read_double = CWebHyDrationBridge_read_double_content;
    self.read_long = CWebHyDrationBridge_read_long_content;
    self.read_bool = CWebHyDrationBridge_read_bool_content;
    self.read_str = CWebHyDrationBridge_read_str_content;
    return self;
}
