

#define DTW_NOT_MIMIFY 1
#define DTW_MIMIFY 2

#define DTW_NOT_LOAD 1
#define DTW_LOAD 2

#define DTW_HIDE 1
#define DTW_INCLUDE 2

typedef struct DtwTreeProps{
   int minification;
   int content;
   int path_atributes;
   int hadware_data;
   int content_data;
   int ignored_elements;

}DtwTreeProps;



DtwTreeProps DtwTreeProps_format_props(DtwTreeProps props);
