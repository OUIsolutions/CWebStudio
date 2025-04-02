
#define PRIVATE_DTW_SCHEMA_ROOT  1
#define PRIVATE_DTW_SCHEMA_VALUE 2
#define PRIVATE_DTW_SCHEMA_ELEMENT 3
#define PRIVATE_DTW_SCHEMA_ELEMENT_PROP 4
#define PRIVATE_DTW_SCHEMA_INDEX 5
#define PRIVATE_DTW_SCHEMA_PK_FOLDER 6
#define PRIVATE_DTW_SCHEMA_PK_VALUE 7

bool private_DtwResource_its_a_pk(DtwResource *self);

void privateDtwResource_ensure_its_possible_to_sub_resource(DtwResource *self);

DtwResource * DtwResource_new_schema_insertion(DtwResource *self);

DtwResource  *DtwResource_find_by_name_id(DtwResource *self, const char *name);

DtwResource * DtwResource_find_by_primary_key_with_binary(DtwResource *self, const char *primary_key, unsigned  char *value, long size);

DtwResource * DtwResource_find_by_primary_key_with_string(DtwResource *self, const char *key, const char *value);

void DtwResource_dangerous_remove_schema_prop(DtwResource*self,const char *prop);

void DtwResource_dangerous_rename_schema_prop(DtwResource*self,const char *prop,const char *new_name);



DtwDatabaseSchema * DtwResource_newDatabaseSchema(DtwResource *self);
