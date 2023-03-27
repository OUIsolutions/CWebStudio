
bool dtw_starts_with(const char *string, const char *prefix);
bool dtw_ends_with(const char *string, const char *suffix);
char *private_dtw_replace_string_once(const char *target, const char *old_element, const char *new_element);
char* dtw_replace_string(const char *target, const char *old_element, const char *new_element);
char *private_dtw_change_beginning_of_string(const char *target,int start_element_to_remove_size, const char *new_element);
