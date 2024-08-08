


#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdarg.h>

#include <errno.h>
#include <sys/file.h>
#include <sys/time.h>



#ifdef __linux__
#include <sys/wait.h>
  #include <dirent.h>
  #include <unistd.h>
#elif _WIN32
  #include <windows.h>
  #include <tchar.h>
  #include <wchar.h>
  #include <locale.h>
  #include <direct.h>
#endif

#ifndef cJSON__h
#include "dependencies/cJSON/cJSON.h"
#undef cJSON__h
#endif //cJSON__h

#ifndef SHA_256_H
#include "dependencies/sha256/sha-256.h"
#undef SHA_256_H
#endif  //SHA_256_H

#include "string_array/string_array.h"

#include "base64/base64.h"
#include "randonizer/randonizer.h"
#include "extras/extras.h"
#include "string_functions/string_functions.h"
#include "io/io.h"
#include "numeral_io/numeral_io.h"
#include "listage_wrappers/listage_wrappers.h"
#include "monodimension_listage/monodimension_listage.h"
#include "multidimension_listage/multidimension_listage.h"
#include "path/path.h"
#include "tree/declarations.h"

#include "lockers/declaration.h"

#include "transaction/declaration.h"
#include "resource/declaration.h"
#include "hash/hash.h"
#include "namespace/declaration.h"
