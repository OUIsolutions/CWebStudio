
#include "../uniq.definitions_requirements.h"

bool CWebHyDration_error(CWebHyDrationBridge *self) {
    if(self->error) {
        return  true;
    }
    return  false;
}

const char * CWebHyDration_get_error_menssage(CWebHyDrationBridge *self) {
    return  self->error;
}

const char * CWebHyDration_get_error_key(CWebHyDrationBridge *self) {
    return  self->error_key;
}

int CWebHyDration_get_error_code(CWebHyDrationBridge *self) {
    return  self->error_type;
}

CwebHttpResponse * CWebHyDration_generate_error_response(CWebHyDrationBridge *self) {
    if(self->error_type == CWEB_HYDRATION_NOT_BODY_JSON_PROVIDED || self->error_type == CWEB_HYDRATION_KEY_NOT_PROVIDED) {
        return cweb_send_text(self->error,404);
    }
    return cweb_send_text(self->error,400);
}