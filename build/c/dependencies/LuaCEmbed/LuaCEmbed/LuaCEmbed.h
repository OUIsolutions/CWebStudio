
typedef struct LuaCEmbed{
    lua_State *state;
    const char *current_function;
    bool is_lib;
    int total_args;
    char *error_msg;
    void (*delete_function)(struct  LuaCEmbed *self);
    void *global_tables;
    void *func_tables;
    int lib_identifier;
    int stack_leve;
    char *main_lib_table;
    bool field_protection;
}LuaCEmbed;

int lua_cembed_timeout = -1;
LuaCEmbed  *global_current_lua_embed_object;

