
void interpret_raw_entrys(char *raw_entrys){
    //splite lines by "\r\n"
    struct DtwStringArray *lines = dtw_constructor_string_array();

    size_t raw_entrys_size = strlen(raw_entrys);
    char last_string[10000]= {0};
    int line_index = 0;
    int i = 0;
    
    while (true){

        if(
            raw_entrys[i]  == '\r' &&
            raw_entrys[i+1] == '\n' &&
            raw_entrys[i+2] == '\r' &&
            raw_entrys[i+3] == '\n'
        ){
            puts("identificou o fim do header");
            last_string[line_index] = '\0';
            lines->add_string(lines, last_string);

            break;
        }
        
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
        i++;

    }
    char teste[10000]= "";
    
    for(int i = 0; i < lines->size; i++){

        //cocacat ----------------------- into test
        strcat(teste, "----------------------------------\n");
        strcat(teste, lines->strings[i]);
        strcat(teste, "\n");

    }
    dtw_write_string_file_content("teste.txt", teste);
    /*
    puts("---Original---"); 
    printf("%s\n", raw_entrys);
    puts("---Geracao de linhas concluida---");
    for(int i = 0; i < lines->size; i++){
        puts("----------------------");
        printf("%s\n", lines->strings[i]);
    }
    */
   /*
    char *last_line = lines->strings[lines->size-2];
    printf("last line: %s\n", last_line);
    int content_length = 0;
    sscanf(last_line, "Content-Length: %d", &content_length);
    //iterate over the raw_entrys and get the content
    char *content = malloc(content_length);
    for(int i = 0; i < content_length; i++){
        content[i] = raw_entrys[raw_entrys_size - content_length + i];
    }
    printf("content: %s\n", content);
    */
    lines->free_string_array(lines);

}