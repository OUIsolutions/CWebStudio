
CwebServerModule newCwebServerModule(){
    CwebServerModule self = {0};
    self.newServer = newCwebSever;
    self.start = CwebServer_start;
    return self;
}