

int private_LuaCembed_run_code_with_args(LuaCEmbed *self,int index,const char *code,va_list args);

int privateLuaCembed_ensure_arg_evaluation_type(LuaCEmbed *self,int index,int expected_type);

int LuaCEmbed_get_type_clojure_evalation(LuaCEmbed *self,int index,const char *code,...);

int LuaCEmbed_generate_arg_clojure_evalation(LuaCEmbed *self,int index,const char *code,...);

long long LuaCEmbed_get_long_arg_clojure_evalation(LuaCEmbed *self,int index,const char *code,...);


double LuaCEmbed_get_double_arg_clojure_evalation(LuaCEmbed *self,int index,const char *code,...);

bool LuaCEmbed_get_bool_arg_clojure_evalation(LuaCEmbed *self,int index,const char *code,...);

char* LuaCEmbed_get_string_arg_clojure_evalation(LuaCEmbed *self,int index,const char *code,...);

