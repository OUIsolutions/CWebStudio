

LuaCEmbedResponse *locker_unlock(LuaCEmbedTable *self,LuaCEmbed *args) {
    char *filename = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)) {
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }
    DtwLocker *locker = (DtwLocker*)LuaCembedTable_get_long_prop(self,LOCKER_POINTER);
    DtwLocker_unlock(locker,filename);
    return LuaCEmbed_send_table(self);
}

LuaCEmbedResponse *locker_lock(LuaCEmbedTable *self,LuaCEmbed *args) {
    char *filename = LuaCEmbed_get_str_arg(args,0);
    if(LuaCEmbed_has_errors(args)) {
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error(error_msg);
    }
    DtwLocker *locker = (DtwLocker*)LuaCembedTable_get_long_prop(self,LOCKER_POINTER);
    if(DtwLocker_lock(locker,filename)) {
        return LuaCEmbed_send_bool(false);
    }
    return LuaCEmbed_send_bool(true);
}


LuaCEmbedResponse *locker_delete(LuaCEmbedTable *self,LuaCEmbed *args) {
    DtwLocker *locker = (DtwLocker*)LuaCembedTable_get_long_prop(self,LOCKER_POINTER);
    DtwLocker_free(locker);
    return  NULL;
}

LuaCEmbedResponse *create_locker(LuaCEmbed *args) {
    DtwLocker *locker = newDtwLocker();
    LuaCEmbedTable *self = LuaCembed_new_anonymous_table(args);
    LuaCEmbedTable_set_long_prop(self,LOCKER_POINTER,(long long)locker);
    LuaCEmbedTable_set_method(self,DELETE_METHOD,locker_delete);
    LuaCEmbedTable_set_method(self,LOCKER_LOCK_METHOD,locker_lock);
    LuaCEmbedTable_set_method(self,UNLOCK_METHOD,locker_unlock);
    return LuaCEmbed_send_table(self);
}