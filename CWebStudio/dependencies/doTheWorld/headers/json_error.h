#define DTW_JSON_ERROR_CODE_OK 0
#define DTW_JSON_TYPE_ERROR 1
#define DTW_JSON_SYNTAX_ERROR 2
#define DTW_JSON_REQUIRED_KEY_ERROR 3
#define DTW_JSON_REQUIRED_VALUE_ERROR 4
#define DTW_JSON_NOT_FOUND_ERROR 5
#define DTW_ACTION_ERROR -1
struct DtWJsonError {
    int code;
    int position;
    const char *menssage;
    void (*free_json_error)(struct DtWJsonError *self);
    void (*represent)(struct DtWJsonError *self);

};
struct DtWJsonError * private_dtw_json_error_constructor();
struct DtWJsonError * dtw_validate_json_tree(char *content);
void private_represent_json_error(struct DtWJsonError *self);
void private_free_json_error(struct DtWJsonError *self);
