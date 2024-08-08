
unsigned char *DtwResource_get_any(DtwResource *self, long *size, bool *is_binary);


unsigned char *DtwResource_get_any_from_sub_resource(DtwResource *self, long *size, bool *is_binary,const char *format,...);

unsigned char *DtwResource_get_binary(DtwResource *self, long *size);

unsigned char *DtwResource_get_binary_from_sub_resource(DtwResource *self, long *size,const char *format,...);

char *DtwResource_get_string(DtwResource *self);

char *DtwResource_get_string_from_sub_resource(DtwResource *self,const char *format,...);


long DtwResource_get_long(DtwResource *self);



long DtwResource_get_long_from_sub_resource(DtwResource *self,const char *format,...);


double DtwResource_get_double(DtwResource *self);

double DtwResource_get_double_from_sub_resource(DtwResource *self,const char *format,...);

bool DtwResource_get_bool(DtwResource *self);

bool DtwResource_get_bool_from_sub_resource(DtwResource *self,const char *format,...);
