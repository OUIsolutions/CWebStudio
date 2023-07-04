

typedef struct CwebDict {
  int size;
  struct CwebKeyVal **keys_vals;
  void (*set)(struct CwebDict *dict,const char *key,const char *value);
  char*(*get_value)(struct CwebDict *dict,const char *key);
  char*(*find_value_by_normalized_key)(struct CwebDict *dict,const char *key,const char *chars_to_remove);
  void (*free)(struct CwebDict *dict);
  void (*represent)(struct CwebDict *dict);
}CwebDict;



struct CwebDict *cweb_create_dict();
void private_cweb_dict_set(struct CwebDict *self,const  char *key,const char *value);
char *private_cweb_dict_get(struct CwebDict *self,const char *key);

char *private_cweb_find_value_by_normalized_key(
  struct CwebDict *self,
  const char *key,
  const char *chars_to_remove
);

void private_cweb_dict_represent(struct CwebDict *dict);
void private_cweb_free_dict(struct CwebDict *self);
