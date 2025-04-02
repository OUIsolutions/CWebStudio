
typedef struct CWebHydrationArgsNamespace {

    bool   (*is_arg_null)(CWebHyDrationBridge *self,int index);
    int   (*get_args_size)(CWebHyDrationBridge *self);
    bool   (*is_arg_number)(CWebHyDrationBridge *self,int index);
    bool   (*is_arg_bool)(CWebHyDrationBridge *self,int index);
    bool   (*is_arg_string)(CWebHyDrationBridge *self,int index);
    double  (*get_double_arg)(CWebHyDrationBridge *self,int index);
    long  (*get_long_arg)(CWebHyDrationBridge *self,int index);
    bool  (*get_bool_arg)(CWebHyDrationBridge *self,int index);
    char* (*get_str_arg)(CWebHyDrationBridge *self,int index);
    cJSON * (*get_cJSON_arg)(CWebHyDrationBridge *self,int index);

}CWebHydrationArgsNamespace;
