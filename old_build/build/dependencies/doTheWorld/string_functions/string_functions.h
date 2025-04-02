

char *dtw_concat_path(const char *path1, const char *path2);

DtwStringArray* private_dtw_remove_start_path(struct DtwStringArray *paths,const char *path_to_remove);

char *private_dtw_format_path(const char *path);

void private_dtw_remove_double_bars_from_string_array(struct DtwStringArray*path);

char * private_dtw_format_vaarg(const char *expresion, va_list args);

char *private_dtw_realoc_formatting(char *ptr,const char *format,...);

char *private_dtw_formatt(const char *format,...);

char * private_dtw_sub_str(const char *str, long start,long end);

int private_dtw_string_cmp(const void *a, const void *b);

bool dtw_is_string_at_point(
        const char *str,
        long str_size,
        const char *target,
        long target_size,
        long target_point
);

long  dtw_index_of_string(const char *str,const char *element);

bool dtw_starts_with(const char *string, const char *prefix);
bool dtw_ends_with(const char *string, const char *suffix);
char *private_dtw_replace_string_once(const char *target, const char *old_element, const char *new_element);
char* dtw_replace_string(const char *target, const char *old_element, const char *new_element);

char *private_dtw_change_beginning_of_string(const char *target,int start_element_to_remove_size, const char *new_element);

