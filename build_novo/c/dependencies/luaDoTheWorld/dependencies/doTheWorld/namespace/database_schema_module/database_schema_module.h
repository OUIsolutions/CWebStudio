
typedef struct {
    DtwSchema * (*sub_schema)(DtwDatabaseSchema *self,const char *name);
}DtwDatabaseSchemaModule;

DtwDatabaseSchemaModule newDtwDatabaseSchemaModule();