

#include "CWebStudio/CwebStudioMain.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    const char *lang = "en";
    const char *text = "text exemple";
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    s->$open(s,HTML,"lang=\"%s\"",lang);
        s->open(s,HEAD);
            char *fav_icon_link = smart_static_ref("favicon.ico");
            s->auto$close(s,LINK,"rel=\"shortcut icon\" href=\"%s\"",fav_icon_link);
            free(fav_icon_link);
        s->close(s,HEAD);
        s->open(s,BODY);
            char *img_link = smart_static_ref("my_image.png");
            s->auto$close(s,IMG,"src=\"%s\" width=\"200px\"",img_link);
            free(img_link);

        s->close(s,BODY);
    s->close(s,HTML);
    return cweb_send_rendered_CTextStack_cleaning_memory(s,200);
    
}
int main(){
    for(int x = 3000 ; x < 4000;x++){

     struct CwebSever *sever = newCwebSever(x, main_sever);
     sever->start(sever);
     sever->free(sever);
    }
}
