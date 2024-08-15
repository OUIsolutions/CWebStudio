#include "../uniq.definitions_requirements.h"

CWebHydrationArgsNamespace newCWebHydrationArgsNamespace(){
    CWebHydrationArgsNamespace self = {0};
    self.read_double = CWebHyDrationBridge_read_double_arg;
    self.read_long = CWebHyDrationBridge_read_long_arg;
    self.read_bool = CWebHyDrationBridge_read_bool_arg;
    self.read_str = CWebHyDrationBridge_read_str_arg;
    return self;
}
