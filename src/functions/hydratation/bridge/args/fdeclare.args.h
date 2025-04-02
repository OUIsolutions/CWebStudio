//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../../imports/imports.types.h"
//silver_chain_scope_end


int   CWebHyDrationBridge_get_args_size(CWebHyDrationBridge *self);

bool private_cweb_hydration_type_verifier(CWebHyDrationBridge *self,int index,cJSON_bool (*callback_verifier)( cJSON * item));

bool   CWebHyDrationBridge_is_arg_number(CWebHyDrationBridge *self,int index);

bool   CWebHyDrationBridge_is_arg_bool(CWebHyDrationBridge *self,int index);

bool   CWebHyDrationBridge_is_arg_null(CWebHyDrationBridge *self,int index);

bool   CWebHyDrationBridge_is_arg_string(CWebHyDrationBridge *self,int index);

cJSON *privateCWebHyDration_get_arg_index(CWebHyDrationBridge *self,int index,cJSON_bool (*callback_verifier)( cJSON * item),const char *expected_type);

double  CWebHyDrationBridge_get_double_arg(CWebHyDrationBridge *self,int index);

long  CWebHyDrationBridge_get_long_arg(CWebHyDrationBridge *self,int index);

bool  CWebHyDrationBridge_get_bool_arg(CWebHyDrationBridge *self,int index);

char* CWebHyDrationBridge_get_str_arg(CWebHyDrationBridge *self,int index);

cJSON * CWebHyDrationBridge_get_cJSON_arg(CWebHyDrationBridge *self,int index);
