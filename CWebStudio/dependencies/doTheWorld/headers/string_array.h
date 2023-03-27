
struct DtwStringArray {
  int size;         

  char **strings;       
  void (*set_value)(struct DtwStringArray *self,int index,const char *value);
  void (*add_string)(struct DtwStringArray *self,const char *string);
  void (*merge_string_array)(struct DtwStringArray *self, struct DtwStringArray *other);
  void (*represent)(struct DtwStringArray *self);
  void (*free_string_array)(struct DtwStringArray *self);
  int (*find_position)(struct DtwStringArray *self,const char *string);
}; // End the structure with a semicolon
int  private_dtw_find_position(struct DtwStringArray *self,const char *string);
void private_dtw_add_string(struct DtwStringArray *self,const char *string);
void private_dtw_merge_string_array(struct DtwStringArray *self, struct DtwStringArray *other);
void private_dtw_represent_string_array(struct DtwStringArray *self);
void private_dtw_free_string_array(struct DtwStringArray *self);
void private_dtw_set_value(struct DtwStringArray *self,int index,const char *value);

struct DtwStringArray * dtw_constructor_string_array();
