

DtwSchemaModule newDtwSchemaModule(){
    DtwSchemaModule  self = {0};
    self.sub_schema = DtwSchema_new_subSchema;
    self.add_primary_key = DtwSchema_add_primary_key;

    return  self;
}