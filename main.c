#define CWEB_DEBUG
#include "CWebStudio/CwebStudioMain.c"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
 
     char *param = request->params->get_value(request->params, "name");
        if(param == NULL){
            return cweb_send_text(
                "Error 404",
                404
            );
        }

        char response[100];
        sprintf(response, "Hello %s", param);
        return cweb_send_text(
            response,
            200
        );

}
CWEB_START_MACRO(5000,main_sever);