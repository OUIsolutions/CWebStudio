## Static Files

Static files (javascript/css/html) can be referenced and returned in the static directory:

```html
    <img src="/static/captura2.png">
```

### Especial Static Files

#### static/favicon.(jpg|png|ico)
If you put a **static/favico.jpg** or **static/favico.png** or **static/favico.ico** into your static folder, it will automatically become the favicon.

#### static/404.html
If you put an **static/404.html** into your static file, it will be used when a 404 error occurs.

#### static/500.html
If you put an **static/500.html** into your static file, it will be used when an internal error occurs.

#### Custom Error Pages
To return a custom error page, place the <error_code>.html in the static directory. Creating a 500.html into the static directory, for example, will return this page when a 500 error occurs.

#### Smart Cache
Dynamic caching may be used inside HTML by using smart_cache:

```html
    <img src="smart-cache='file.png'">
```

#### Inline inclusion
It's also possible to generate inline inclusion with:

```html
    <div>
        inline-include='static/teste3.html'
    </div>
```

#### Smart Cache in Rendered Text
Smart caching with rendered text can be done with **private_cweb_smart_static_ref**:

```c
#include "CWebStudioOne.c"
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

```

These examples demonstrate how to handle static files and use smart caching.