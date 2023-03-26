
void interpret_raw_entrys(char *raw_entrys){
    //splite lines by "\r\n"
    struct DtwStringArray *lines = dtw_constructor_string_array();

    size_t raw_entrys_size = strlen(raw_entrys);
    char last_string[1000]= "";
    int line_index = 0;
    for (int i = 0; i < raw_entrys_size; i++){
        if (raw_entrys[i] == '\r' && raw_entrys[i+1] == '\n'){
            last_string[line_index] = '\0';
            lines->add_string(lines, last_string);
            line_index=0;
            i++;
        }
        else{
            last_string[line_index] = raw_entrys[i];
            line_index++;
        }    
    }
    puts("---Original---"); 
    printf("%s\n", raw_entrys);
    puts("---Geracao de linhas concluida---");
    for(int i = 0; i < lines->size; i++){
        puts("----------------------");
        printf("%s\n", lines->strings[i]);
    }
    
    lines->free_string_array(lines);

}