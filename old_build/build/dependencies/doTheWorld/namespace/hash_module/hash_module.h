
typedef struct DtwHashModule{
    DtwHash * (*newHash)();
    bool  (*digest_any)(DtwHash *self,unsigned char *content,long size);
    bool (*digest_string)(DtwHash * self, const char *content);
    void (*digest_long)(DtwHash * self,long content);
    void (*digest_double)(DtwHash * self,double content);
    void (*digest_bool)(DtwHash * self,bool content);
    bool  (*digest_file)(DtwHash * self, const char *path);
    bool  (*digest_entity_last_modification)(DtwHash * self, const char *path);
    bool (*digest_string_array)(DtwHash *self,DtwStringArray *element);
    bool (*digest_string_array_last_modifications)(DtwHash *self,DtwStringArray *element);
    bool (*digest_string_array_last_modifications_adding_name)(DtwHash *self,DtwStringArray *element);
    bool (*digest_string_array_content)(DtwHash *self,DtwStringArray *element);
    bool (*digest_string_array_content_adding_name)(DtwHash *self,DtwStringArray *element);
    bool (*digest_folder_by_last_modification)(DtwHash *self,const char *path);
    bool (*digest_folder_by_content)(DtwHash *self,const char *path);
    void  (*free)(DtwHash *self);

}DtwHashModule;

DtwHashModule newDtwHashModule();