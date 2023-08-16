
CwebNamespace newCwebNamespace(){
    CwebNamespace self = {0};
    self.dict =newCwebDictModule();
    self.request = newCwebRequestModule();
    self.response  = newCwebHttpResponseModule();
    return self;
}