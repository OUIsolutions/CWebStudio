#include "multifile_locker/multifile_locker.h"
#ifdef __linux__
#include "flock_locker/declaration.h"
#endif
#include "locker/locker.h"