

typedef struct{
    unsigned  char *content;
    bool clear_content;
    long size;
    bool is_binary;
    LuaCEmbedResponse  *error;
}Writeble;

Writeble  *create_writeble(LuaCEmbed *args,int index);

void Writeble_free(Writeble *self);