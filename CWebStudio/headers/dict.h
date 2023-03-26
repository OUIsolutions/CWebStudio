

struct CwebDict {
  int size;
  struct CwebKeyVal **keys_vals;
  void (*set_key)(struct CwebDict *dict, char *key, char *value);
  char*(*get_value)(struct CwebDict *dict, char *key);
  void (*free)(struct CwebDict *dict);
  void (*represent)(struct CwebDict *dict);
};



struct CwebDict *cweb_create_dict();
void private_cweb_dict_set(struct CwebDict *dict, char *key, char *value);
char *private_cweb_dict_get(struct CwebDict *dict, char *key);
void private_cweb_dict_represent(struct CwebDict *dict);
void private_cweb_free_dict(struct CwebDict *dict);
