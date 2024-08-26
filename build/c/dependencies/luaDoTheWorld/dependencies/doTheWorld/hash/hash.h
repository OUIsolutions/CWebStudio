

typedef  struct DtwHash{
    char *hash;
}DtwHash;


DtwHash * newDtwHash();

bool  DtwHash_digest_any(DtwHash *self,unsigned char *content,long size);

bool DtwHash_digest_string(DtwHash * self, const char *content);

void DtwHash_digest_long(DtwHash * self,long content);

void DtwHash_digest_double(DtwHash * self,double content);

void DtwHash_digest_bool(DtwHash * self,bool content);

bool  DtwHash_digest_file(DtwHash * self, const char *path);

bool DtwHash_digest_entity_last_modification(DtwHash * self, const char *path);

bool DtwHash_digest_folder_by_last_modification(DtwHash *self,const char *path);

bool DtwHash_digest_folder_by_content(DtwHash *self,const char *path);


bool DtwHash_digest_string_array(DtwHash *self,DtwStringArray *element);

bool DtwHash_digest_string_array_last_modifications(DtwHash *self,DtwStringArray *element);

bool DtwHash_digest_string_array_last_modifications_adding_name(DtwHash *self,DtwStringArray *element);


bool DtwHash_digest_string_array_content(DtwHash *self,DtwStringArray *element);

bool DtwHash_digest_string_array_content_adding_name(DtwHash *self,DtwStringArray *element);


void  DtwHash_free(DtwHash *self);

