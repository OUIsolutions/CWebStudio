


bool DtwResource_error(DtwResource *self);

int DtwResource_get_error_code(DtwResource *self);


char * DtwResource_get_error_message(DtwResource *self);

char * DtwResource_get_error_path(DtwResource *self);

void  DtwResource_clear_errors(DtwResource *self);


void  private_DtwResource_raise_error(DtwResource *self, int error_code, const char *format,...);

void DtwResource_rename(DtwResource *self,const char *new_name);

void DtwResource_rename_sub_resource(DtwResource *self,const char *old_name,const  char *new_name);

int DtwResource_lock(DtwResource *self);

void DtwResource_unlock(DtwResource *self);


void DtwResource_commit(DtwResource *self);

long DtwResource_size(DtwResource *self);



DtwStringArray *DtwResource_list_names(DtwResource *self);

int DtwResource_type(DtwResource *self);

bool DtwResource_is_file(DtwResource *self);


const char * DtwResource_type_in_str(DtwResource *self);

void DtwResource_represent(DtwResource *self);
