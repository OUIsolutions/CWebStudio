
typedef struct {


    int  (*size)(LuaCEmbed *self);
    int  (*get_type)(LuaCEmbed *self,int index);
    long long  (*get_long)(LuaCEmbed *self, int index);
    double (*get_double)(LuaCEmbed *self, int index);
    bool (*get_bool)(LuaCEmbed *self, int index);
    char * (*get_raw_str)(LuaCEmbed *self, long *size, int index);
    char * (*get_str)(LuaCEmbed *self, int index);
    LuaCEmbedTable  * (*get_table)(LuaCEmbed *self,int index);
    int  (*generate_arg_clojure_evalation)(LuaCEmbed *self,int index,const char *code,...);
    int  (*get_type_clojure_evalation)(LuaCEmbed *self,int index,const char *code,...);
    long long    (*get_long_arg_clojure_evalation)(LuaCEmbed *self,int index,const char *code,...);
    double (*get_double_arg_clojure_evalation)(LuaCEmbed *self,int index,const char *code,...);
    bool (*get_bool_arg_clojure_evalation)(LuaCEmbed *self,int index,const char *code,...);
    char* (*get_string_arg_clojure_evalation)(LuaCEmbed *self,int index,const char *code,...);
    LuaCEmbedTable* (*run_lambda)(LuaCEmbed *self, int index, LuaCEmbedTable *args_to_call,int total_returns);




} LuaCembedArgsModule;

LuaCembedArgsModule newLuaCembedArgsModule();