
void private_ctext_generate_formated_text(
        struct CTextStack *stack,const char *format,va_list argptr){
    long  text_size = strlen(format);

    int i;
    for(i =0;i < text_size -1 ;i++){

        char single_test[3] = {format[i],format[i+1],'\0'};
        char double_test[4] = {0};


        if(i < text_size -2){
            strcpy(double_test,single_test);
            double_test[2] = format[i+2];
            double_test[3] = '\0';

        }

        if(strcmp(single_test,"%d") == 0) {
            char result[20] ={0};
            sprintf(result,"%ld", va_arg(argptr,long));
            CTextStack_text(stack,result);
            i+=1;
            continue;
        }

        if(strcmp(single_test,"%f") == 0) {
            char result_text[20]= {0};

            sprintf(result_text,"%lf", va_arg(argptr,double ));

            for(int t = 18; t > 0; t--){
                char current_char = result_text[t];
                if(current_char != '0' && current_char != '\0'){

                    if(current_char == '.'){
                        result_text[t+2]  = '\0';
                    }
                    else{
                        result_text[t+1]  = '\0';
                    }

                    break;
                }
            }
            CTextStack_text(stack,result_text);
            i+=1;
            continue;
        }

        else if(strcmp(single_test,"%c") == 0){
            char result = va_arg(argptr,int);
            char element[2] = {result,'\0'};
            CTextStack_text(stack,element);
            i+=1;
            continue;
        }


        else if(strcmp(single_test,"%b") == 0){
            bool value = va_arg(argptr,int);
            if(value){
                CTextStack_text(stack,"true");
            }else{
                CTextStack_text(stack,"false");
            }
            i+=1;
            continue;
        }

        else if(strcmp(double_test,"%sc") == 0){
            char *value = va_arg(argptr,char*);
            if(value){
                CTextStack_text(stack,value);
                free(value);
            }
            i+=2;
            continue;
        }

        else if(strcmp(single_test,"%s") == 0){
            const char *value = va_arg(argptr,const char*);
            if(value){
                CTextStack_text(stack,value);
            }

            i+=1;
            continue;
        }
        else if(strcmp(double_test,"%tc") == 0){
            struct CTextStack *new_stack = (struct  CTextStack*)va_arg(argptr,void *);
            if(new_stack){
                char *result = CTextStack_self_transform_in_string_and_self_clear(new_stack);
                CTextStack_text(stack,result);
                free(result);
            }
            i+=2;
            continue;
        }

        else if(strcmp(single_test,"%t") == 0){
            struct CTextStack *new_stack = (struct  CTextStack*)va_arg(argptr,void *);
            if(new_stack){
                CTextStack_text(stack,new_stack->rendered_text);
            }
            i+=1;
            continue;
        }

        char element[2] = {format[i],'\0'};
        CTextStack_text(stack,element);

        }



    if(text_size > 0 && text_size> i){
        char element[2] = {format[text_size-1],'\0'};
        CTextStack_text(stack,element);
    }

    va_end(argptr);
}


long private_CText_transform_index(long size , long value){
    long formated_value = value;

    if(formated_value >= size){
        formated_value = size;
    }

    if(formated_value  < 0){
        formated_value = size + (formated_value +1);
    }
    if(formated_value <0){
        formated_value = 0;
    }
    return formated_value;
}