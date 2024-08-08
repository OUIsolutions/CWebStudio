
typedef struct {
    void (*add_primary_key)(DtwSchema *self, const char *primary_key);
    DtwSchema * (*sub_schema)(DtwSchema *self,const char *name);
}DtwSchemaModule;

DtwSchemaModule newDtwSchemaModule();