
#include "CWebStudio.h"

void create_num(struct CTextStack *stack, int  number){
    stack->$open(stack,BUTTON,"type=\"submit\" name=\"set_num\" value=\"%i\"",number);
                    stack->segment_format(stack,"%i",number);
    stack->close(stack,BUTTON);
}


void create_operator(struct CTextStack *stack, const  char *operator){
    stack->$open(stack,BUTTON,"type=\"submit\" name=\"set_operator\" value=\"%s\"",operator);
                    stack->segment_format(stack,"%s",operator);
    stack->close(stack,BUTTON);
}


void create_num_line(struct CTextStack *stack,int n1,int n2,int n3){
    stack->only$open(stack,BR,"");
    create_num(stack,n1);
    create_num(stack,n2);
    create_num(stack,n3);
}


 struct CTextStack * create_interface(const char *visor,const  char *acumulated,const char *operator){
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    s->$open(s,HTML,"lang=\"en\"");
        s->open(s,HEAD);
            s->open(s,TITLE);
                s->text(s,"Basic Calculator");
            s->close(s,TITLE);
            s->open(s,STYLE);
                s->text(s,"input{width:190px;height:30px;}");
                s->text(s,"button{width:60px;height:30px;}");
                s->text(s,".equal{width:90px;height:30px; background-color: #4CAF50;}");  
                s->text(s,".delete{width:90px;height:30px; background-color: #f44336;}");
                //add border radios 
                s->text(s,"*{border-radius: 4px;}");
            s->close(s,STYLE);
        s->close(s,HEAD);
        s->open(s,BODY);
            s->$open(s,FORM,"action=\"/button_pressed\" method=\"POST\" ");
                s->auto$close(s,INPUT,"type=\"hidden\" name=\"operator\" value=\"%s\"",operator);
                s->auto$close(s,INPUT,"type=\"hidden\" name=\"acumulated\" value=\"%s\"",acumulated);
                s->auto$close(s,INPUT,"type=\"text\" name=\"visor\" value=\"%s\"",visor);
                create_num_line(s,7,8,9);
                create_num_line(s,4,5,6);
                create_num_line(s,1,2,3);
                s->only$open(s,BR,"");
                create_num(s,0);

                create_operator(s,"+");
                create_operator(s,"-");
                s->auto$close(s,BR,"");  
                create_operator(s,"*");
                create_operator(s,"/");
                
                s->only$open(s,BR,"");
              
                s->$open(s,BUTTON,"type=\"submit\" class=\"delete\"  name=\"delete\" value=\"%s\"","Delete");
                    s->segment_format(s,"%s","Delete");
                s->close(s,BUTTON);


                s->$open(s,BUTTON,"type=\"submit\" class=\"equal\" name=\"equal\" value=\"%s\"","=");
                    s->segment_format(s,"%s","=");
                s->close(s,BUTTON);
                

            s->close(s,FORM);
        s->close(s,BODY);
    s->close(s,HTML);
    return s;
 }
int total_request = 0;


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    
    if(total_request == 10){
        request->free(request);
        exit(0);
    }

    char *visor = malloc(10);
    char *acumulated = malloc(10);
    char *operator = malloc(10);

    strcpy(visor,"");
    strcpy(acumulated,"");
    strcpy(operator,"");
    
        
    //logic of the code 
    
    
    if(strcmp(request->route,"/button_pressed") == 0){


        strcpy(visor,request->get_param(request,"visor"));
        strcpy(acumulated,request->get_param(request,"acumulated"));
        strcpy(operator,request->get_param(request,"operator"));
        //means that the user pressed a number

        //means that a  number button were clicked
        char *number_button = request->get_param(request,"set_num");
        if( number_button != NULL){
               //realocates it

                int visor_size = strlen(visor);
                if(visor_size < 9){
                    visor = (char*)realloc(visor,visor_size+strlen(number_button)+2);      
                    strcat(visor,number_button);                    
                }      
        }

        // means that the delete button were clicked
        char *delete_button = request->get_param(request,"delete");
        if(delete_button != NULL){
            strcpy(visor,"");
            strcpy(acumulated,"");
            strcpy(operator,"");
    
        }

        //means that a operator button were clicked
        char *operator_button = request->get_param(request,"set_operator");
        if(operator_button != NULL){
            acumulated = visor;
            operator = operator_button;
            strcpy(visor,"");
        }

        char * equal_button = request->get_param(request,"equal");

        if(equal_button != NULL){
            visor = (char*)realloc(visor,10);
        
            if(strcmp(operator,"+") == 0){
                int result = atoi(acumulated) + atoi(visor);
                sprintf(visor,"%i",result);
            }
            if(strcmp(operator,"-") == 0){
                int result = atoi(acumulated) - atoi(visor);
                sprintf(visor,"%i",result);
            }
            if(strcmp(operator,"*") == 0){
                int result = atoi(acumulated) * atoi(visor);
                sprintf(visor,"%i",result);
            }
            if(strcmp(operator,"/") == 0){
                int result = atoi(acumulated) / atoi(visor);
                sprintf(visor,"%i",result);
            }
            strcpy(acumulated,"");
            strcpy(operator,"");
        }
        
    }
    
    struct CTextStack *stack = create_interface(visor,acumulated,operator);
    free(visor);
    free(acumulated);
    free(operator);
    return cweb_send_rendered_CTextStack_cleaning_memory(
        stack,
        200
    );
}

int main(){
    
    cweb_run_server(
        8081,
        main_sever,
        CWEB_DEFAULT_TIMEOUT,
        CWEB_DEFAULT_MAX_BODY,
        CWEB_DANGEROUS_SINGLE_PROCESS
    );

}

