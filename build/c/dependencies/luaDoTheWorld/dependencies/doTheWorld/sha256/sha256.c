char * calc_sha_256_returning_string(const void *input, size_t len)
{


    uint8_t hash[SIZE_OF_SHA_256_HASH];
    calc_sha_256(hash, input, len);
    char *hash_string = (char*)malloc(SIZE_OF_SHA_256_HASH * 2 + 1);
    for (unsigned int i = 0; i < SIZE_OF_SHA_256_HASH; i++) {
        sprintf(hash_string + i * 2, "%02x", hash[i]);
    }
    return hash_string;
}

void  calc_sha_256_from_string(uint8_t hash[SIZE_OF_SHA_256_HASH], const char *input)
{
    calc_sha_256(hash, input, strlen(input));

}

char * calc_sha_256_from_string_returning_string(const char *input)
{
    return calc_sha_256_returning_string(input, strlen(input));
}

int calc_sha_256_from_file(uint8_t hash[SIZE_OF_SHA_256_HASH], const char *filename)
{
    int size;
    char *content = sha256_open_file(filename, &size);
    if(content == NULL){
        return -1;
    }
    calc_sha_256(hash, content, size);
    free(content);
    return 0;
}

char * calc_sha_256_from_file_returning_string(const char *filename)
{
    int size;
    char *content = sha256_open_file(filename, &size);
    if(content == NULL){
        return NULL;
    }
    char *hash_string = calc_sha_256_returning_string(content, size);
    free(content);
    return hash_string;

}
char * sha256_open_file(const char *filename, int *size){
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }
    fseek(file,0,SEEK_END);
    *size = ftell(file);
    fseek(file,0,SEEK_SET);
    char *content = (char*)malloc(*size +1);
    fread(content,1,*size,file);
    fclose(file);
    return content;
}