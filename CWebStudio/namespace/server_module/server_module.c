
CwebServerModule newCwebServerModule(){
    CwebServerModule self = {0};
    self.newServer = newCwebSever;
    self.start = CwebServer_start;
    self.free = CwebServer_free;
    return self;
}