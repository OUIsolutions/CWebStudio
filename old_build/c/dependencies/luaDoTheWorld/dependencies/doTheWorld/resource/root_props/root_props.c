

privateDtwResourceRootProps *private_newDtwResourceRootProps(){
    privateDtwResourceRootProps *self  = (privateDtwResourceRootProps*) malloc(sizeof (privateDtwResourceRootProps));
    *self = (privateDtwResourceRootProps){0};
    self->transaction = newDtwTransaction();
    self->randonizer = newDtwRandonizer();
    self->locker = newDtwLocker();
    self->error_code = DTW_RESOURCE_OK;

    return self;
}


void privateDtwResourceRootProps_free(privateDtwResourceRootProps *self){
    DtwTransaction_free(self->transaction);
    DtwRandonizer_free(self->randonizer);
    DtwLocker_free(self->locker);
    if(self->error_path){
        free(self->error_path);
    }

    if(self->error_message){
        free(self->error_message);
    }



    free(self);
}