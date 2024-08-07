#include "keyval.h"

#ifndef PRIVATE_CWEB_HTTP_DICT_TYPES
#define PRIVATE_CWEB_HTTP_DICT_TYPES

typedef struct CwebDict {
  int size;
  CwebKeyVal **keys_vals;

}CwebDict;

#endif //PRIVATE_CWEB_HTTP_DICT_TYPES