
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

int  private_cweb_find_position(struct CwebStringArray *self,const char *string);
void private_cweb_add_string(struct CwebStringArray *self,const char *string);
void private_cweb_merge_string_array(struct CwebStringArray *self, struct CwebStringArray *other);
void private_cweb_represent_string_array(struct CwebStringArray *self);
void private_cweb_free_string_array(struct CwebStringArray *self);
void private_cweb_set_value(struct CwebStringArray *self,int index,const char *value);

struct CwebStringArray * cweb_constructor_string_array();
