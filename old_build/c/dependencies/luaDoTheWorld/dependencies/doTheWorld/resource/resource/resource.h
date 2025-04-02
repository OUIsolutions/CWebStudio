

typedef struct DtwResource{

    bool allow_transaction;
    bool use_locker_on_unique_values;


    privateDtwResourceRootProps *root_props;
    struct DtwResource *mother;
    char *name;
    char *path;




    //in the schema struct there is:
    //|/root
    //|/root/values
    //|root/values/element  <-----------------------------|
    //|root/values/element/pk_name ->any(write_point)     |
    //|root/values/element/element_prop ->any(write_point)|
    //|root/index                                         |
    //|root/index/pk_name/pk_sha ->txt  -------------------
    DtwSchema *attached_schema;
    DtwDatabaseSchema *datatabase_schema;
    struct DtwResource *values_resource;
    struct DtwResource *index_resource;
    int schema_type;

    bool loaded;
    bool is_binary;
    bool were_renamed;
    unsigned char *value_any;
    long value_size;
   
    //cache implementation
    bool cache_sub_resources;
    void *sub_resources;

}DtwResource;



