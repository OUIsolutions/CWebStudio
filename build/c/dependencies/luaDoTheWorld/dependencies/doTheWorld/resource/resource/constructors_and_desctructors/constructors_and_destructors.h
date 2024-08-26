

DtwResource *new_DtwResource(const char *path);

DtwResource * DtwResource_sub_resource(DtwResource *self,const  char *format, ...);

DtwResource * DtwResource_sub_resource_ensuring_not_exist(DtwResource *self,const  char *format, ...);

void DtwResource_free(DtwResource *self);