

DtwRandonizerModule newDtwRandonizerModule(){
    DtwRandonizerModule self = {0};
    self.newRandonizer = newDtwRandonizer;
    self.generate_token =DtwRandonizer_generate_token;
    self.free = DtwRandonizer_free;
    return self;
}