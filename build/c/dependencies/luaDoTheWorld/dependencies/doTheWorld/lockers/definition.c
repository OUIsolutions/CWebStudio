
#include "multifile_locker/multifile_locker.c"
#ifdef __linux__
    #include "flock_locker/definition.c"
#endif

#include "locker/locker.c"