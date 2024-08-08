
#include "../uniq.declaration_requirements.h"

int privateCWebHyDration_read_json(CWebHyDrationBridge *self);

const char * CWebHyDration_read_string(CWebHyDrationBridge *self,const char *name,...);

long CWebHyDration_read_long(CWebHyDrationBridge *self,const char *name,...);

double CWebHyDration_read_double(CWebHyDrationBridge *self,const char *name,...);

bool  CWebHyDration_read_bool(CWebHyDrationBridge *self,const char *name,...);

bool  CWebHyDration_exist(CWebHyDrationBridge *self,const char *name,...);
