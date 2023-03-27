#define DTW_CONCAT_PATH true
#define DTW_NOT_CONCAT_PATH false

struct DtwStringArray * dtw_list_files(const char *path, bool concat_path);
struct DtwStringArray * dtw_list_dirs(const char *path, bool concat_path);

struct DtwStringArray *  dtw_list_all(const char *path,  bool concat_path);