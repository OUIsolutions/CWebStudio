

long lua_cembed_used_memory = 0;
long  lua_cembed_memory_limit = -1;

void LuaCEmbed_set_memory_limit(LuaCEmbed *self, double limit);


static void *private_LuaCembed_custom_allocator(void *ud, void *ptr, size_t osize, size_t nsize) ;

