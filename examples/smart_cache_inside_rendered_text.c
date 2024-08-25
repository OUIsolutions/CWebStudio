#include "CWebStudio.h"
CwebNamespace cweb;

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    const char *lang = "en";
    const char *text = "text exemple";
    CTextStackModule  m = newCTextStackModule();
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    m.open_format(s,CTEXT_HTML,"lang=\"%s\"",lang);
        m.open(s,CTEXT_HEAD);

            char *fav_icon_link = cweb_smart_static_ref("favicon.ico");
            m.auto_close_format(s,CTEXT_LINK,"rel=\"shortcut icon\" href=\"%s\"",fav_icon_link);
            free(fav_icon_link);

        m.close(s,CTEXT_HEAD);
        m.open(s,CTEXT_BODY);

            char *img_link = cweb_smart_static_ref("my_image.png");
            m.auto_close_format(s,CTEXT_IMG,"src=\"%s\" width=\"200px\"",img_link);
            free(img_link);

        m.close(s,CTEXT_BODY);
    m.close(s,CTEXT_HTML);
    return cweb.response.send_rendered_CTextStack(s,200);

}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    CwebServer server = newCwebSever(5000, main_sever);
    cweb.server.start(&server);
    return 0;
}
