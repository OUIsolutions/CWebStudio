
typedef struct CwebStringArray {
  int size;         

  char **strings;       
  void (*set_value)(struct CwebStringArray *self,int index,const char *value);
  void (*add_string)(struct CwebStringArray *self,const char *string);
  void (*merge_string_array)(struct CwebStringArray *self, struct CwebStringArray *other);
  void (*represent)(struct CwebStringArray *self);
  void (*free_string_array)(struct CwebStringArray *self);
  int (*find_position)(struct CwebStringArray *self,const char *string);
}CwebStringArray; // End the structure with a semicolon

struct CwebStringArray * newCwebStringArray();

int  CwebStringArray_find_position(struct CwebStringArray *self, const char *string);
void CwebStringArray_add(struct CwebStringArray *self, const char *string);
void CwebStringArray_merge(struct CwebStringArray *self, struct CwebStringArray *other);
void CwebStringArray_represent(struct CwebStringArray *self);
void CwebStringArray_free(struct CwebStringArray *self);
void CwebStringArray_set(struct CwebStringArray *self, int index, const char *value);

