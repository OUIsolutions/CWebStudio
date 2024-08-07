
#ifndef cJSON__h
#define cJSON__h
#include "dependencies/cJSON/cJSON.c"
#endif //cJSON__h

#undef true
#define true 1

#undef false
#define false 0


#ifndef SHA_256_H
#define SHA_256_H
#include "dependencies/sha256/sha-256.c"
#endif  //SHA_256_H



#include "base64/base64.c"
#include "randonizer/randonizer.c"
#include "extras/extras.c"
#include "string_functions/string_functions.c"
#include "io/io.c"
#include "numeral_io/numeral_io.c"
#include "listage_wrappers/listage_wrappers.c"
#include "monodimension_listage/monodimension_listage_linux.c"
#include "monodimension_listage/monodimension_listage_win32.c"
#include "multidimension_listage/multidimension_listage.c"
#include "path/path.c"
#include "path/setters.c"
#include "path/getters.c"
#include "path/index_dirs.c"
#include "string_array/string_array.c"
#include "tree/definitions.h"

#include "lockers/definition.h"

#include "resource/definition.h"
#include "transaction/definition.h"
#include "hash/hash.c"
#include "namespace/definition.h"






