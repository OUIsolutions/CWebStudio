How to create an Graphic Calculator using CWEB Studio

In These Tutorial ,you will learn how to create an total function calculator only with Cweb Studio, (No Javascript knowledge Required) 
Please Follow All The tutorial steps, and you will be able to create your own calculator

### Step 1: Installing Cweb Studio
Go to : https://github.com/OUIsolutions/CWebStudio
Download the **CWebStudio.h**  file and paste in your project folder.
Create an file called **main.c**  and imports the library 

~~~c
#include "CWebStudio.h"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
   
    return cweb_send_text("Calculator",200);
}

CWEB_START_MACRO(5000, main_sever)
~~~
copile and run the code above, and
Go to your browser and type: http://localhost:5000
if you see the text "Calculator" you have installed Cweb Studio correctly


### Understanding basic web Concepts
The first thing that you have to understand, that, diferent than CLI/DESKTOP Aplications
Web Aplications are Stateless , witch means its impossible, to store programn states 
in variable, so, there is just 3 ways for making an aplication works.



1 You store the state of aplications in an database or in an markup language like XML or JSON 


2 You store the state of aplications in the client side, using cookies/localstorage 

3 You store the state of aplications in same document, using an hidden input 


We are going to use the 3 method, because its the most simple way for making an calculator


### Retriving client Input
Every input , its associated with an "name", the name value can be retrived using the method
    **request->get_param**
the code bellow , creates an basic form with a input and an button to send the data 
Please Runs The Code and reads it for you understand how it works

~~~c
#include "CWebStudio.h"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    

    char *a = request->get_param(request,"a");
    if(a != NULL){
        printf("a= %s\n",a);
    }

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    s->open(s,HTML);
            s->$open(s,FORM,"action=\"/\"");
                s->auto$close(s,INPUT,"name=\"a\"");
                s->open(s,BUTTON);
                    s->segment_text(s,"Send");
                s->close(s,BUTTON);
            s->close(s,FORM);
    s->close(s,HTML);

    return cweb_send_rendered_CTextStack_cleaning_memory(
        s,
        200
    );
}

CWEB_START_MACRO(5000, main_sever)

~~~

### Retriving witch button was pressed 
For retriving witch button was pressed you must associate an "name" with an button, an pass
it value in the "value" area, with it we can capture the information with,  **request->get_param** method 

~~~c
#include "CWebStudio.h"
struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    


    char *button = request->get_param(request,"button");
    if(button != NULL){
        printf("Button pressed: %s\n",button);
    }

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    s->open(s,HTML);
            s->$open(s,FORM,"action=\"/\"");
                s->$open(s,BUTTON,"name=\"button\" value=\"A\"");
                    s->segment_format(s,"%s","Button A");
                s->close(s,BUTTON);

                s->$open(s,BUTTON,"name=\"button\" value=\"B\"");
                    s->segment_format(s,"%s","Button B");
                s->close(s,BUTTON);

            s->close(s,FORM);
    s->close(s,HTML);

    return cweb_send_rendered_CTextStack_cleaning_memory(
        s,
        200
    );
}

CWEB_START_MACRO(5000, main_sever)

~~~
## Creating The interface 
Our Interface will be composed with 3 inputs , to store the follow data:


1 The Visor: Responsible for storing the data in the visor 


2 The Acumulated: Responsible for storing the acumulated number when (*/+-) is pressed
these input will be hidden


3 The Operator: Responssible for storing the operator when (*/+-) is pressed
these input will be hidden


we will create an function called **create_interface** responsable to create the 
interface, with the 3 inputs

Runs these and you will see an calculator with no functionality
~~~c
#include "CWebStudio.h"

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
    

    struct CTextStack *stack = create_interface("123","0","+");

    return cweb_send_rendered_CTextStack_cleaning_memory(
        stack,
        200
    );

}

CWEB_START_MACRO(5000,main_sever)

~~~

### Creating the logical part of the calculator

The Logical Part will consist in verify if some button were pressed 
by verifiy if route is **/button_pressed** , after it ,makes the operation
based on each button 

For buttons , concating the value of the button to the visor 

For operators , storing the operator and the acumulated value and cleaning the visor 

For equal , making the operation based on the acumulated value , the operator and the visor 

For delete , cleaning the visor 


### Final Code
~~~c

#include "CWebStudio.h"



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
                    visor = (char*)realloc(visor,visor_size+strlen(number_button)+2);      
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

CWEB_START_MACRO(5000,main_sever)

~~~



