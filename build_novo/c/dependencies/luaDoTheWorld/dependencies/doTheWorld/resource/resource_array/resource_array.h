


typedef struct DtwResourceArray{
    DtwResource **resources;
    long size;

}DtwResourceArray;

DtwResourceArray * newDtwResourceArray();

void DtwResourceArray_append(DtwResourceArray *self, DtwResource *element);


DtwResource * DtwResourceArray_get_by_name(DtwResourceArray *self, const char *name);

DtwResourceArray * DtwResource_get_schema_values(DtwResource *self);

DtwResourceArray * DtwResource_sub_resources(DtwResource *self);


void DtwResourceArray_represent(DtwResourceArray *self);

void DtwResourceArray_free(DtwResourceArray *self);

