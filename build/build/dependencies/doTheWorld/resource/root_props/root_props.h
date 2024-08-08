#define DTW_RESOURCE_ELEMENT_IS_NULL -1
#define DTW_RESOURCE_OK 0
#define DTW_RESOURCE_ELEMENT_NOT_EXIST 1
#define DTW_RESOURCE_ELEMENT_NOT_BOOL 2
#define DTW_RESOURCE_ELEMENT_NOT_LONG 3
#define DTW_RESOURCE_ELEMENT_NOT_DOUBLE 4
#define DTW_RESOURCE_ELEMENT_NOT_STRING 5
#define DTW_RESOURCE_PRIMARY_KEY_ALREADY_EXIST 6
#define DTW_RESOURCE_PRIMARY_KEY_CANNOT_HAVE_SUB_RESOURCE 7
#define DTW_IMPOSSIBLE_TO_RENAME_A_PRIMARY_KEY 8
#define DTW_RESOURCE_RENAMED_RESOURCE_CANNOT_HAVE_SONS 9
#define DTW_RESOURCE_IMPSSIBLE_TO_ADD_INSERTION_OUTSIDE_ROOT_SCHEMA 10
#define DTW_RESOURCE_IMPOSSIBLE_TO_ADD_SUB_RESOURCE_INSIDE_SCHEMA_STRUCT 11
#define DTW_RESOURCE_ONLY_ROOT_SCHEMA_CAN_FIND_BY_ID_OR_PK 12
#define DTW_RESOURCE_ONLY_ROOT_SCHEMA_HAVE_SCHEMA_VALUES 13
#define DTW_RESOURCE_ONLY_ROOT_SCHEMA_CANN_MODIFY_SCHEMA_PROPS 14

typedef struct {
    DtwTransaction  *transaction;
    DtwRandonizer  *randonizer;
    DtwLocker *locker;
    bool is_writing_schema;
    int error_code;
    char *error_path;
    char *error_message;
    
}privateDtwResourceRootProps;

privateDtwResourceRootProps *private_newDtwResourceRootProps();


void privateDtwResourceRootProps_free(privateDtwResourceRootProps *self);

