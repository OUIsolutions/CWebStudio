
#ifdef __linux__

bool private_dtw_verify_if_add(const int expected_type, int d_type);
bool private_dtw_verify_if_skip(struct dirent *entry);

#endif


#ifdef _WIN32

bool private_dtw_verify_if_add(const int expected_type, WIN32_FIND_DATAA entry);
bool private_dtw_verify_if_skip(WIN32_FIND_DATAA *entry);
#endif



struct DtwStringArray * dtw_list_basic(const char *path,int expected_type,bool concat_path);
 