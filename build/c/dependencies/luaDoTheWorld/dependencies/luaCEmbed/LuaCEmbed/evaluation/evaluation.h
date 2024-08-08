

#ifdef _WIN32
VOID CALLBACK TimerHandler(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
#else 

void private_LuaCembed_handle_timeout(int signum);

#endif 

int privateLuaCEmbed_start_func_evaluation(lua_State *state);

int LuaCEmbed_evaluate(LuaCEmbed *self, const char *code, ...);

int LuaCEmbed_evaluete_file(LuaCEmbed *self, const char *file);


int private_LuaCEmbed_ensure_evaluation_type(LuaCEmbed *self,int type);

int private_LuaCEmbed_evaluate_puting_on_top_of_stack(LuaCEmbed *self,const char *code, va_list args);

char * LuaCEmbed_get_evaluation_string(LuaCEmbed *self,const char *code, ...);


int  LuaCEmbed_get_evaluation_type(LuaCEmbed *self,const char *code, ...);


long LuaCEmbed_get_evaluation_table_size(LuaCEmbed *self,const char *code, ...);

long long  LuaCEmbed_get_evaluation_long(LuaCEmbed *self,const char *code, ...);

double LuaCEmbed_get_evaluation_double(LuaCEmbed *self,const char *code, ...);

bool LuaCEmbed_get_evaluation_bool(LuaCEmbed *self,const char *code, ...);


