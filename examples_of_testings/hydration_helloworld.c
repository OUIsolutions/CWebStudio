#include "../src/one.c"

CwebNamespace cweb;
CTextStackModule stack;
CWebHydrationNamespace hydration;
CWebHydrationBridgeNamespace bridge;
CWebHydrationSearchRequirementsNamespace requirements;
CWebHydrationSearchResultNamespace result;
CWebHydrationArgsNamespace hydration_args;

CTextStack *main_page(CWebHyDration *hydration){

}

CwebHttpResponse *main_server(CwebHttpRequest *request){


}

int main(){

    cweb = newCwebNamespace();
    stack = newCTextStackModule();
    hydration = cweb.hydration;
    bridge = hydration.bridge;
    requirements = hydration.search_requirements;
    result  = hydration.search_result;
    hydration_args = hydration.args;

}
