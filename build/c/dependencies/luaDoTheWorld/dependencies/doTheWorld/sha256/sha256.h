
char * calc_sha_256_returning_string(const void *input, size_t len);
/*
    @param input: the string to be hashed
    @param len: the length of the string
    @return: the hash of the string
    @note: if the input string is NULL, the results are unpredictable
*/

void calc_sha_256_from_string(uint8_t hash[SIZE_OF_SHA_256_HASH], const char *input);
/*
    @param hash: the hash array, where the result is delivered
    @param input: the string to be hashed
    @note: if the input string is NULL, the results are unpredictable
*/

int calc_sha_256_from_file(uint8_t hash[SIZE_OF_SHA_256_HASH], const char *filename);
/*
    @param hash: the hash array, where the result is delivered
    @param filename: the name of the file to be hashed
    @return: 0 if the file was hashed successfully, -1 otherwise
*/

char * calc_sha_256_from_file_returning_string(const char *filename);
/*
    @param filename: the name of the file to be hashed
    @return: the hash of the file
    @note: if the filename is NULL, the return value is NULL
*/
char * sha256_open_file(const char *filename, int *size);
