#define PRIVATE_LUA_CEMBED_TABLE_PROTECT_VOID \
    if(!self){                          \
    return;                              \
    }

#define PRIVATE_LUA_CEMBED_TABLE_PROTECT_NUM \
    if(!self){                          \
    return LUA_CEMBED_GENERIC_ERROR;      \
    }

#define PRIVATE_LUA_CEMBED_TABLE_PROTECT_BOOL \
    if(!self){                          \
    return false;      \
    }

#define PRIVATE_LUA_CEMBED_TABLE_PROTECT_NULL \
    if(!self){                          \
    return NULL;      \
    }
