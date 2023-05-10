
#include "CWebStudio/CwebStudioMain.h"





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
                //Inputs ------------------------------------------------------------------------------
                s->auto$close(s,INPUT,"type=\"hidden\" name=\"operator\" value=\"%s\"",operator);
                s->auto$close(s,INPUT,"type=\"hidden\" name=\"acumulated\" value=\"%s\"",acumulated);
                s->auto$close(s,INPUT,"type=\"text\" name=\"visor\" value=\"%s\"",visor);
                
                //Numbers ------------------------------------------------------------------------------
                s->only$open(s,BR,"");
                s->$open(s,BUTTON,"type=\"submit\" name=\"set_num\" value=\"7\"");
                    s->segment_text(s,"7");
                s->close(s,BUTTON);
                s->$open(s,BUTTON,"type=\"submit\" name=\"set_num\" value=\"8\"");
                    s->segment_text(s,"8");
                s->close(s,BUTTON);
                s->$open(s,BUTTON,"type=\"submit\" name=\"set_num\" value=\"9\"");
                    s->segment_text(s,"9");
                s->close(s,BUTTON);
                s->only$open(s,BR,"");

                s->$open(s,BUTTON,"type=\"submit\" name=\"set_num\" value=\"4\"");
                    s->segment_text(s,"4");
                s->close(s,BUTTON);
                s->$open(s,BUTTON,"type=\"submit\" name=\"set_num\" value=\"5\"");
                    s->segment_text(s,"5");
                s->close(s,BUTTON);
                s->$open(s,BUTTON,"type=\"submit\" name=\"set_num\" value=\"6\"");
                    s->segment_text(s,"6");
                s->close(s,BUTTON);
                s->only$open(s,BR,"");

          
                s->$open(s,BUTTON,"type=\"submit\" name=\"set_num\" value=\"1\"");
                    s->segment_text(s,"1");
                s->close(s,BUTTON);
                s->$open(s,BUTTON,"type=\"submit\" name=\"set_num\" value=\"2\"");
                    s->segment_text(s,"2");
                s->close(s,BUTTON);
                s->$open(s,BUTTON,"type=\"submit\" name=\"set_num\" value=\"3\"");
                    s->segment_text(s,"3");
                s->close(s,BUTTON);
                s->only$open(s,BR,"");


                s->$open(s,BUTTON,"type=\"submit\" name=\"set_num\" value=\"0\"");
                    s->segment_text(s,"0");
                s->close(s,BUTTON);

                //Operators ------------------------------------------------------------------------------
                s->$open(s,BUTTON,"type=\"submit\" name=\"set_operator\" value=\"+\"");
                    s->segment_text(s,"+");
                s->close(s,BUTTON);

                s->$open(s,BUTTON,"type=\"submit\" name=\"set_operator\" value=\"-\"");
                    s->segment_text(s,"-");
                s->close(s,BUTTON);
                s->auto$close(s,BR,"");
    
                s->$open(s,BUTTON,"type=\"submit\" name=\"set_operator\" value=\"*\"");
                    s->segment_text(s,"x");
                s->close(s,BUTTON);

                s->$open(s,BUTTON,"type=\"submit\" name=\"set_operator\" value=\"/\"");
                    s->segment_text(s,"/");
                s->close(s,BUTTON);


                s->only$open(s,BR,"");

                //Delete and equal ------------------------------------------------------------------------------
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


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    
    
     char *visor = malloc(10);
    char *acumulated = malloc(10);
    char *operator = malloc(10);

    strcpy(visor,"");
    strcpy(acumulated,"");
    strcpy(operator,"");
    
        
    //logic of the code 
    
    
    if(strcmp(request->route,"/button_pressed") == 0){

        char *user_visor = request->get_param(request,"visor");
        strcpy(visor,user_visor);
        char *user_acumulated = request->get_param(request,"acumulated");
        strcpy(acumulated,user_acumulated);

        char *user_operator = request->get_param(request,"operator"); 
        strcpy(operator,user_operator);

        char *number_button = request->get_param(request,"set_num");
        //means that a  number button were clicked
        if( number_button != NULL){
               
                int visor_size = strlen(visor);
                if(visor_size < 9){
                    //realocates the visor
      
                    //concatenates the number to the visor
                    strcat(visor,number_button);                    
                }      
        }


        char *delete_button = request->get_param(request,"delete");
        // means that the delete button were clicked
        if(delete_button != NULL){
            //clears the visor
            strcpy(visor,"");
            strcpy(acumulated,"");
            strcpy(operator,"");

        }


        char *operator_button = request->get_param(request,"set_operator");
        //means that a operator button were clicked
        if(operator_button != NULL){
            //stores the acumulated value
            strcpy(acumulated,visor);
            //stores the operator
            strcpy(operator,operator_button);
            //clears the visor
            strcpy(visor,"");
        }

        char * equal_button = request->get_param(request,"equal");
        //means that the equal button were clicked
        if(equal_button != NULL){
            
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

CWEB_START_MACRO(5001,main_sever)
