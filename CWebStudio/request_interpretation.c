
void interpret_raw_entrys(char *raw_entrys){
    //splite lines by "\r\n"
    struct DtwStringArray *lines = dtw_constructor_string_array();
    int i;
    for (i = 0; i < strlen(raw_entrys); i++){
        if (raw_entrys[i] == '\r' && raw_entrys[i+1] == '\n')
        {
            raw_entrys[i] = '\0';
            lines->add_string(lines, raw_entrys);
            raw_entrys = raw_entrys + i + 2;
            i = 0;
        }
    }
    //extract the last num of lines
    for (int i = 0; i < lines->size; i++){
        puts("---------------------------------");
        printf("%s\n", lines->strings[i]);
    }

    puts("END OF LINES");
}