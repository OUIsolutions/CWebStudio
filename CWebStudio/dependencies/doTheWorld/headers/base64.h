const char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


char *dtw_base64_encode(unsigned char *data, size_t input_length);


unsigned char *dtw_base64_decode(char *data, size_t input_length, size_t *output_length);


char *dtw_convert_binary_file_to_base64(const char *path);