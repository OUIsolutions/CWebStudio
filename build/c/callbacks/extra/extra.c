
LuaCEmbedResponse * generate_exit(LuaCEmbedTable *self,LuaCEmbed *args){

    printf("\x1b[0m"); //ressset color
    int status = lua.args.get_long(args,0);
    if(lua.has_errors(args)){
        char *menssage = lua.get_error_message(args);
        return  lua.response.send_error(menssage);
    }
    lua_exit = status;
    return lua.response.send_error("");
}

LuaCEmbedResponse * get_out_extension(LuaCEmbedTable *self,LuaCEmbed *args)
{
#ifdef __linux__
    return  lua.response.send_str("out");
#elif _WIN32
    return  lua.response.send_str("exe");
#endif

}

LuaCEmbedResponse * get_time(LuaCEmbedTable *self,LuaCEmbed *args){
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    char buffer[50] = {0};
    sprintf(buffer,"%ld.%ld",current_time.tv_sec,current_time.tv_usec);
    double value = -1;
    sscanf(buffer,"%lf",&value);
    return lua.response.send_double(value);
}
