
char * dtw_generate_sha_from_file(const char *path);
char * dtw_generate_sha_from_string(const char *string);
long int dtw_get_file_last_motification_in_unix(const char *path);
char * dtw_convert_unix_time_to_string(long int unix_time);
char * dtw_get_file_last_motification_in_string(const char *path);
const char * private_dtw_convert_action_to_string(short action);
short private_dtw_convert_string_to_action(const char *action);
void private_dtw_add_end_bar_to_dirs_string_array(struct DtwStringArray * dirs);
char *dtw_concat_path(const char *path1, const char *path2);
