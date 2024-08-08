
#include "src/one.c"
CwebNamespace cweb;
CTextStackModule stack;
CWebHydrationNamespace hy;

CwebHttpResponse *main_sever(CwebHttpRequest *request) {

    CWebHyDration *hydration = hy.newHyDration(request);
    CWebHyDrationBridge *set_num = hy.create_bridge(hydration,"/set_num",NULL);
    hy.request_number_text_content_by_id(set_num, "num");

    if(hy.is_the_route(set_num)) {

        long num = hy.read_long(set_num,"num");
        long value = hy.read_long(set_num,"args0");
        if(hy.error(set_num)) {
            CwebHttpResponse *response = hy.generate_error_response(set_num);
            hy.free(hydration);
            return response;
        }

        CTextStack * text = newCTextStack(CTEXT_LINE_BREAKER,CTEXT_SEPARATOR);
        CText$Scope(text,CTEXT_H3,"id='num'"){
            stack.format(text,"%d",num + value);
        }

        hy.replace_element_by_id_with_ctext_stack_cleaning_memory(set_num,"num",text);
        CwebHttpResponse *response = hy.generate_response(set_num);
        return response;
    }


    CTextStack * text = stack.newStack(CTEXT_LINE_BREAKER,CTEXT_SEPARATOR);
    CTextScope(text,CTEXT_BODY){
        CTextScope(text,CTEXT_SCRIPT) {
           stack.format(text,hy.create_script(hydration));
        }
        CText$Scope(text,CTEXT_H3,"id='num'"){
            stack.text(text,"0");
        }
        CText$Scope(text,CTEXT_BUTTON,"onclick='%s'",hy.call(set_num,"1")){
             stack.text(text,"increment");
        }

        CText$Scope(text,CTEXT_BUTTON,"onclick='%s'",hy.call(set_num,"-1")){
            stack.text(text,"decrement");
        }


    }
    hy.free(hydration);
    return  cweb.response.send_rendered_CTextStack_cleaning_memory(text,200);
}


int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    stack = newCTextStackModule();
    hy = newCWebHydrationNamespace();
    struct CwebServer server = newCwebSever(5000, main_sever);
    cweb.server.start(&server);
    return 0;

}