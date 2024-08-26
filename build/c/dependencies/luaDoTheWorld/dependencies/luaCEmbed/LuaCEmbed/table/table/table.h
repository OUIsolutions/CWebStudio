

typedef struct {
    LuaCEmbed  *main_object;
    char *prop_name;
    char  *global_name;
    void *sub_tables;
    long index;

}LuaCEmbedTable;
