
DtwJsonTransactionErrorModule newDtwJsonTransactionErrorModule(){
    DtwJsonTransactionErrorModule self = {0};
    self.represent = DtwJsonTransactionError_represent;
    self.free = DtwJsonTransactionError_free;
    return self;
}