

#define  CWebHydrationHandleErrors(bridge) \
    if(CWebHyDrationBridge_has_errors(bridge)){\
        return;\
    }

#define CWebHydrationHandleTriggers(hydration) \
    if(CWebHyDration_is_the_trigger(hydration)){\
        return CWebHydration_generate_response(hydration);\
    }
