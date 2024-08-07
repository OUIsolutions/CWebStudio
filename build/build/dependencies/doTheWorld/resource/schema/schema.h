

#define DTW_SCHEMA_DEFAULT_VALUES_NAME "value"
#define DTW_SCHEMA_DEFAULT_INDEX_NAME "index"



typedef struct DtwSchema{


    const char *value_name;
    const char *index_name;

    char *name;
    struct DtwSchema **sub_schemas;
    int size;
    DtwStringArray  *primary_keys;
}DtwSchema;

DtwSchema *private_newDtwSchema(const char *name);

DtwSchema * privateDtwSchema_get_sub_schema(DtwSchema *self,const char *name);


DtwSchema * (DtwSchema_new_subSchema)(DtwSchema *self,const char *name);

void DtwSchema_add_primary_key(DtwSchema *self,const char *name);

void private_newDtwSchema_free(DtwSchema *self);
