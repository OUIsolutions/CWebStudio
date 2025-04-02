

#define DTW_NOT_NUMERICAL -2
#define DTW_NOT_BOOL -3

long dtw_load_long_file_content_setting_error(const char *path,int *error);

long dtw_load_long_file_content(const char * path);

double dtw_load_double_file_content_setting_error(const char * path, int *error);

double dtw_load_double_file_content(const char * path);

bool dtw_load_bool_file_content_setting_error(const char * path, int *error);


bool dtw_load_bool_file_content(const char * path);


void dtw_write_long_file_content(const char *path, long value);

void dtw_write_bool_file_content(const char *path, bool value);

void dtw_write_double_file_content(const char *path,double value);

