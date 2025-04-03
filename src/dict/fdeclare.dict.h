//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.typesO.h"
//silver_chain_scope_end
CwebDict *newCwebDict();
void CwebDict_set(CwebDict *self, const  char *key, const char *value);
char *CwebDict_get(CwebDict *self, const char *key);

char *CwebDict_get_by_normalized_key(
  CwebDict *self,
  const char *key,
  const char *chars_to_remove
);

void CwebDict_represent(CwebDict *dict);
void CwebDict_free(CwebDict *self);