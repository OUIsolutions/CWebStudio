
typedef struct DtwStringArray {
  int size;

  char **strings;



}DtwStringArray;

// End the structure with a semicolon
int  DtwStringArray_find_position(struct DtwStringArray *self, const char *string);


void DtwStringArray_append_getting_ownership(struct DtwStringArray *self, char *string);

void DtwStringArray_append(struct DtwStringArray *self, const char *string);

void DtwStringArray_pop(struct DtwStringArray *self, int position);

void DtwStringArray_merge(struct DtwStringArray *self, struct DtwStringArray *other);
void DtwStringArray_represent(struct DtwStringArray *self);
void DtwStringArray_free(struct DtwStringArray *self);

int private_dtw_string_cmp(const void *a, const void *b);
void DtwStringArray_sort(struct DtwStringArray *self);

void DtwStringArray_set_value(struct DtwStringArray *self, int index, const char *value);

struct DtwStringArray * newDtwStringArray();

char * privateDtwStringArray_append_if_not_included(DtwStringArray *self,char *value);

struct DtwStringArray * DtwStringArray_clone(DtwStringArray *self);

