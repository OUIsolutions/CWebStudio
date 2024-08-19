
#include "../uniq.declaration_requirements.h"


int  CWebHyDrationBridge_get_content_key_size(CWebHyDrationBridge *self,const char *key,...);

cJSON * private_CWebHyDrationBridge_get_content_at_index(CWebHyDrationBridge *self,int index,const char *key);

bool  CWebHyDrationBridge_content_exist_at_index(CWebHyDrationBridge *self,int index,const char *key,...);

bool  CWebHyDrationBridge_content_is_number_at_index(CWebHyDrationBridge *self,int index,const char *key,...);

bool  CWebHyDrationBridge_content_is_bool_at_index(CWebHyDrationBridge *self,int index,const char *key,...);

bool  CWebHyDrationBridge_content_is_string_at_index(CWebHyDrationBridge *self,int index,const char *key,...);

cJSON *   private_CWebHyDrationBridge_get_cJSON_element(
    CWebHyDrationBridge *self,
    int index,
    const char *key,
    cJSON_bool (*callback_verifier)(const cJSON * const item),
    const char *expected_type
);

double CWebHyDrationBridge_get_double_content(CWebHyDrationBridge *self,int  index, const char *key,...);

long  CWebHyDrationBridge_get_long_content(CWebHyDrationBridge *self,int index,const char *key,...);

bool  CWebHyDrationBridge_get_bool_content(CWebHyDrationBridge *self,int index,const char *key,...);

char*  CWebHyDrationBridge_get_str_content(CWebHyDrationBridge *self,int index, const char *key,...);
