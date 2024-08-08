
LuaCEmbedResponse * resource_list(LuaCEmbedTable  *self,LuaCEmbed *args) {
    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResourceArray  *elements = DtwResource_sub_resources(resource);
    LuaCEmbedTable *response = LuaCembed_new_anonymous_table(args);
    for(int i = 0; i < elements->size; i++) {
        DtwResource*current = elements->resources[i];
        LuaCEmbedTable  *sub = raw_create_resource(args,current);
        LuaCEmbedTable_append_table(response,sub);
    }
    return LuaCEmbed_send_table(response);
}


LuaCEmbedResponse * resource_foreach(LuaCEmbedTable  *self,LuaCEmbed *args) {


    DtwResource  *resource = (DtwResource*)LuaCembedTable_get_long_prop(self,RESOURCE_POINTER);
    DtwResourceArray  *elements = DtwResource_sub_resources(resource);

    for(int i =0; i < elements->size; i++) {
        DtwResource *current = elements->resources[i];
        LuaCEmbedTable  *sub = raw_create_resource(args,current);
        LuaCEmbedTable *args_to_callback = LuaCembed_new_anonymous_table(args);
        LuaCEmbedTable_append_table(args_to_callback,sub);
        LuaCEmbed_run_args_lambda(args,0,args_to_callback,0);

    }
    return LuaCEmbed_send_table(self);

}