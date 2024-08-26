
void private_dtw_remove_double_bars_from_string_array(struct DtwStringArray*path){
    for(int i =0;i< path->size;i++){
        char *buffer = private_dtw_format_path(path->strings[i]);
        free(path->strings[i]);
        path->strings[i] = buffer;
    }
}

char *dtw_concat_path(const char *path1, const char *path2){

    if(!path1){
        return strdup(path2);
    }

    if(!path2){
        return strdup(path1);
    }

    char *path = (char *)malloc(strlen(path1) + strlen(path2) + 3);

    if(dtw_ends_with(path1, "/") || dtw_ends_with(path1, "\\")){
        sprintf(path,"%s%s",path1,path2);

    }
    else{
        sprintf(path,"%s/%s",path1,path2);

    }
    return path;
}

char * private_dtw_format_vaarg(const char *expresion, va_list args){

    va_list args_copy;
    va_copy(args_copy, args);
    long required_size = vsnprintf(NULL, 0,expresion,args_copy);
    va_end(args_copy);
    char *buffer = (char*)malloc(sizeof(char) * required_size + 2);
    vsnprintf(buffer,sizeof (char) * required_size+1,expresion,args);
    return buffer;
}

char *private_dtw_format_path(const char *path){
    int path_size = (int)strlen(path);
    char *buffer = (char*)malloc((path_size+2) * sizeof(char));
    int buffer_size = 0;
    bool already_concatened = false;
    for(long i = 0; i < path_size;i++){
        char current_char = path[i];

        bool is_a_divisor =current_char == '\\' || current_char == '/';

        if(is_a_divisor && already_concatened){
            continue;
        }
        if(is_a_divisor){
#ifdef __linux
            buffer[buffer_size] = '/';
#else
            buffer[buffer_size] = '\\';
#endif
            buffer_size+=1;
            already_concatened = true;
            continue;
        }

        already_concatened = false;
        buffer[buffer_size] = current_char;
        buffer_size+=1;

    }
    buffer[buffer_size] = '\0';
    return buffer;
}


char * private_dtw_sub_str(const char *str, long start,long end){
    long size = end - start;
    char *value = (char*)malloc(size+ 2);

    for(long i = 0; i <size; i++){
        value[i] = str[i+start];
    }
    value[size] = '\0';
    return value;
}


bool dtw_starts_with(const char *string, const char *prefix){
    if(!string || !prefix){
        return false;
    }
    if(strncmp(string, prefix, strlen(prefix)) == 0){
        return true;
    }
    return false;
}

bool dtw_ends_with(const char *string, const char *suffix){
    if(strlen(string) < strlen(suffix)){
        return false;
    }
    if(strcmp(string + strlen(string) - strlen(suffix), suffix) == 0){
        return true;
    }
    return false;
}

char *private_dtw_replace_string_once(const char *target, const char *old_element, const char *new_element) {

    const char *pos = strstr(target, old_element);

    int size_of_old_element = (int)strlen(old_element);
    int size_of_new_element = (int)strlen(new_element);
    // Allocate memory for the new string
    char *result = (char *)malloc(strlen(target) + size_of_new_element - size_of_old_element + 1);

    // Copy the part of the original string before the old substring
    strncpy(result, target, pos - target);

    // Copy the new substring to the result string
    strcpy(result + (pos - target), new_element);

    // Copy the rest of the original string after the old substring
    strcpy(result + (pos - target) + size_of_new_element, pos + size_of_old_element);

    return result;

    

}

char* dtw_replace_string(const char *target, const char *old_element, const char *new_element) {
    char *result = (char *)malloc(strlen(target) + 1);
    strcpy(result, target);
    char *temp = NULL;
    while (strstr(result, old_element) != NULL) {
        temp = private_dtw_replace_string_once(result, old_element, new_element);
        free(result);
        result = temp;
    }
    return result;
}



char *private_dtw_change_beginning_of_string(const char *target,int start_element_to_remove_size, const char *new_element) {
    int target_size = (int)strlen(target);
    int new_element_size = (int)strlen(new_element);
    char *result = (char *)malloc(target_size- start_element_to_remove_size + new_element_size   +2);
    strcpy(result, new_element);
    char *new_target = (char *)malloc(target_size - start_element_to_remove_size + 2);
    strcpy(new_target, target + start_element_to_remove_size);
    strcat(result, new_target);
    free(new_target);
    return result;
}



char *private_dtw_realoc_formatting(char *ptr,const char *format,...){

    va_list args;
    va_start(args, format);
    char *value = private_dtw_format_vaarg(format,args);
    va_end(args);
    if(ptr){
        free(ptr);
    }

    return value;
}
char *private_dtw_formatt(const char *format,...){

    va_list args;
    va_start(args, format);
    char *value = private_dtw_format_vaarg(format,args);
    va_end(args);
    return value;
}
bool dtw_is_string_at_point(
        const char *str,
        long str_size,
        const char *target,
        long target_size,
        long target_point
        ){

    if(target_size + target_point > str_size){
        return false;
    }
    for(long i = 0; i < target_size; i++ ){
        char current_char = target[i];
        char char_to_compare = str[i+target_point];
        if(current_char != char_to_compare){
            return  false;
        }
    }
    return true;
}

long  dtw_index_of_string(const char *str,const char *element){
    long str_size = (long)strlen(str);
    long element_size = (long)strlen(element);

    for(int i = 0; i <str_size; i++){
        if(dtw_is_string_at_point(str,str_size,element,element_size,i)){
            return i;
        }
    }
    return -1;
}

double private_dtw_convert_string_to_number(const char *num, bool *its_a_number){

    long size_num = strlen(num);

    if(size_num == 0){
        *its_a_number = false;
        return -1;
    }

    bool dot_found = false;

    for(int i = 0; i < size_num; i++){
        char current = num[i];

        if(current == '.'){
            if(i == 0 || dot_found || i == size_num - 1){
                *its_a_number = false;
                return -1;
            }

            dot_found = true;
            continue;
        }

        if(current == '0'){
            continue;
        }

        if(current == '1'){
            continue;
        }

        if(current == '2'){
            continue;
        }

        if(current == '3'){
            continue;
        }

        if(current == '4'){
            continue;
        }

        if(current == '5'){
            continue;
        }

        if(current == '6'){
            continue;
        }

        if(current == '7'){
            continue;
        }

        if(current == '8'){
            continue;
        }

        if(current == '9'){
            continue;
        }

        *its_a_number = false;

        return -1;
    }

    *its_a_number = true;

    return atof(num);


}