void DtwResource_set_binary_in_sub_resource(DtwResource *self,const char *key, unsigned char *element, long size);


void DtwResource_set_binary_sha_in_sub_resource(DtwResource *self, const char *key, unsigned  char *value, long size);


void DtwResource_set_string_sha_in_sub_resource(DtwResource *self, const char *key, const char *value);

void DtwResource_set_string_in_sub_resource(DtwResource *self, const char *key, const  char *element);

void DtwResource_set_long_in_sub_resource(DtwResource *self, const char *key, long element);

void DtwResource_set_double_in_sub_resource(DtwResource *self, const char *key, double element);

void DtwResource_set_bool_in_sub_resource(DtwResource *self,const char *key, bool element);
