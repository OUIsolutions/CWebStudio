#include "../uniq.definitions_requirements.h"

CWebHydrationArgsNamespace newCWebHydrationArgsNamespace(){
    CWebHydrationArgsNamespace self = {0};
    self.get_args_size  = CWebHyDrationBridge_get_args_size;
    self.is_arg_number = CWebHyDrationBridge_is_arg_number;
    self.is_arg_bool = CWebHyDrationBridge_is_arg_bool;
    self.is_arg_string  = CWebHyDrationBridge_is_arg_string;
    self.get_double_arg = CWebHyDrationBridge_get_double_arg;
    self.get_long_arg = CWebHyDrationBridge_get_long_arg;
    self.get_bool_arg = CWebHyDrationBridge_get_bool_arg;
    self.get_str_arg = CWebHyDrationBridge_get_str_arg;
    self.get_cJSON_arg  = CWebHyDrationBridge_get_cJSON_arg;
    return self;
}
