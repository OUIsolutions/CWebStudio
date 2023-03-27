

char *dtw_base64_encode(unsigned char *data, size_t input_length){
    size_t output_length = 4 * ((input_length + 2) / 3);

    char *encoded_data = (char *)malloc(output_length + 1);

    if (encoded_data == NULL) return NULL;

    size_t i, j;
    for (i = 0, j = 0; i < input_length; ) {
        unsigned char b0 = i < input_length ? data[i++] : 0;
        unsigned char b1 = i < input_length ? data[i++] : 0;
        unsigned char b2 = i < input_length ? data[i++] : 0;

        unsigned char b = b0 >> 2;
        encoded_data[j++] = base64_table[b];

        b = (b0 << 4) & 0x3F;
        b |= b1 >> 4;
        encoded_data[j++] = base64_table[b];

        b = (b1 << 2) & 0x3F;
        b |= b2 >> 6;
        encoded_data[j++] = i <= input_length + 1 ? base64_table[b] : '=';

        b = b2 & 0x3F;
        encoded_data[j++] = i <= input_length ? base64_table[b] : '=';
    }

    encoded_data[j] = '\0';
    return encoded_data;
}


unsigned char *dtw_base64_decode(char *data, size_t input_length, size_t *output_length){
    if (input_length % 4 != 0) return NULL;

    *output_length = input_length / 4 * 3;
    if (data[input_length - 1] == '=') (*output_length)--;
    if (data[input_length - 2] == '=') (*output_length)--;

    unsigned char *decoded_data = (unsigned char*) malloc(*output_length);
    if (decoded_data == NULL) return NULL;

    size_t i, j;
    for (i = 0, j = 0; i < input_length; ) {
        unsigned char b0 = data[i] == '=' ? 0 & i++ : strchr(base64_table, data[i++]) - base64_table;
        unsigned char b1 = data[i] == '=' ? 0 & i++ : strchr(base64_table, data[i++]) - base64_table;
        unsigned char b2 = data[i] == '=' ? 0 & i++ : strchr(base64_table, data[i++]) - base64_table;
        unsigned char b3 = data[i] == '=' ? 0 & i++ : strchr(base64_table, data[i++]) - base64_table;

        unsigned char b = (b0 << 2) | (b1 >> 4);
        decoded_data[j++] = b;

        if (j < *output_length) {
            b = (b1 << 4) | (b2 >> 2);
            decoded_data[j++] = b;
        }
        if (j < *output_length) {
            b = (b2 << 6) | b3;
            decoded_data[j++] = b;
        }
    }

    return decoded_data;
}

char *dtw_convert_binary_file_to_base64(const char *path){
     int size;
     unsigned char *data  = dtw_load_binary_content(path, &size);
    char *b64   = dtw_base64_encode(data, size);
    free(data);
    return b64;
}