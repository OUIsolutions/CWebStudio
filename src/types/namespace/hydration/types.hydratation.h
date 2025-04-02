//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.macros.h"
//silver_chain_scope_end

typedef struct CWebHydrationNamespace{
    CWebHyDration *(*newCWebHyDration)(CwebHttpRequest *request);
    bool (*is_the_trigger)(CWebHyDration *self);
    char *(*create_script)(CWebHyDration *self);
    CwebHttpResponse *(*generate_response)(CWebHyDration *self);
    CTextStack  * (*create_stack)(CWebHyDration *self);
    CTextStack  * (*create_empty_stack)(CWebHyDration *self);
    CWebHydrationBridgeNamespace bridge;
    CWebHydrationActionsNamespace actions;
    CWebHydrationSearchRequirementsNamespace search_requirements;
    CWebHydrationSearchResultNamespace search_result;
    CWebHydrationArgsNamespace args;
}CWebHydrationNamespace;

