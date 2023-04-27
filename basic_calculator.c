
#include "CWebStudio.h"

void create_num(struct CTextStack *stack, int  number){
    stack->$open(stack,BUTTON,"type=\"submit\" name=\"set_num\" value=\"%i\"",number);
                    stack->segment_format(stack,"%i",number);
    stack->close(stack,BUTTON);
}
void create_num_line(struct CTextStack *stack,int n1,int n2,int n3){
    stack->only$open(stack,BR,"");
    create_num(stack,n1);
    create_num(stack,n2);
    create_num(stack,n3);
}

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    int visor = 0;
    int acumulated = 0;

    //logic of the code 
    if(strcmp(request->route,"/button_pressed") == 0){

          char *str_visor = request->get_param(request,"visor");
          int visor_size = strlen(str_visor);

          char *button_pressed = request->get_param(request,"set_num");

        
          if( button_pressed != NULL){
               //realocates it
                if(visor_size < 9){
                    str_visor = realloc(str_visor,visor_size+strlen(button_pressed)+2);      
                    strcat(str_visor,button_pressed);                    
                }

          }

          visor = atoi(str_visor);

    }
    
    s->$open(s,HTML,"lang=\"en\"");
        s->open(s,HEAD);
            s->open(s,TITLE);
                s->text(s,"Basic Calculator");
            s->close(s,TITLE);
        s->close(s,HEAD);
        s->open(s,BODY);
            s->$open(s,FORM,"action=\"/button_pressed\" method=\"POST\" enctype=\"application/x-www-form-urlencoded\"");
                s->auto$close(s,INPUT,"type=\"hidden\" name=\"acumulated\" value=\"%i\"",acumulated);
                s->auto$close(s,INPUT,"type=\"text\" name=\"visor\" value=\"%i\"",visor);
                create_num_line(s,7,8,9);
                create_num_line(s,4,5,6);
                create_num_line(s,1,2,3);
                s->only$open(s,BR,"");
                create_num(s,0);
                s->auto$close(s,BR,"");  
                

            s->close(s,FORM);
        s->close(s,BODY);
    s->close(s,HTML);


    return cweb_send_rendered_CTextStack_cleaning_memory(s,200);
}

CWEB_START_MACRO(8080, main_sever)

