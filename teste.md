### [src/config/hydratation/macros.app.h](/src/config/hydratation/macros.app.h):
### `#define CWEB_HYDRATION_DEFAULT_BODY_SIZE 5000`
- **description:** Defines the default body size for hydration in the CWEB framework.
- **value:** `5000` [The default size in bytes]
- **type:** `int` [The type of the constant]
- **usage:** Typically used to set the initial buffer size for hydration processes in CWEB applications.

### `#define CWEB_HYDRATION_CALBACK_HANDLER_ROUTE "/private_cweb_hydration_main_callback_handler"`
- **description:** Specifies the default route for the hydration callback handler in the CWEB framework.
- **value:** `"/private_cweb_hydration_main_callback_handler"` [The route path]
- **type:** `string` [The type of the constant]
- **usage:** Used to define the endpoint where hydration callbacks are processed in CWEB applications.
------------------------
### [src/config/hydratation/macros.callbacks.h](/src/config/hydratation/macros.callbacks.h):
### `#define PRIVATE_CWEB_HYDRATION_CALLBACK_KEY "callback"`
- **description:** Defines the key for the callback function in the hydration process.
- **value:** `"callback"`
- **type:** `string`
- **usage:** Used to identify the callback function in hydration-related operations.

### `#define PRIVATE_CWEB_HYDRATION_ARGS_KEY "args"`
- **description:** Defines the key for the arguments passed to the callback function in the hydration process.
- **value:** `"args"`
- **type:** `string`
- **usage:** Used to identify the arguments for the callback function in hydration-related operations.

### `#define PRIVATE_CWEB_HYDRATION_ID_KEY "id"`
- **description:** Defines the key for the identifier in the hydration process.
- **value:** `"id"`
- **type:** `string`
- **usage:** Used to identify elements or components in hydration-related operations.

### `#define PRIVATE_CWEB_HYDRATION_HTML_KEY "html"`
- **description:** Defines the key for the HTML content in the hydration process.
- **value:** `"html"`
- **type:** `string`
- **usage:** Used to identify HTML content in hydration-related operations.

### `#define PRIVATE_CWEB_HYDRATION_MENSSAGE_KEY "menssage"`
- **description:** Defines the key for messages in the hydration process. (Note: Typo in "menssage")
- **value:** `"menssage"`
- **type:** `string`
- **usage:** Used to identify messages in hydration-related operations.

### `#define PRIVATE_CWEB_HYDRATION_ALERT "private_cweb_alert"`
- **description:** Defines the macro for alert functionality in the hydration process.
- **value:** `"private_cweb_alert"`
- **type:** `string`
- **usage:** Used to trigger alerts in hydration-related operations.

### `#define PRIVATE_CWEB_HYDRATION_DESTROY_BY_ID "private_cweb_destroy_by_id"`
- **description:** Defines the macro for destroying elements by their ID in the hydration process.
- **value:** `"private_cweb_destroy_by_id"`
- **type:** `string`
- **usage:** Used to destroy elements identified by their ID in hydration-related operations.

### `#define PRIVATE_CWEB_HYDRATION_REPLACE_BY_ID "private_cweb_hydration_replace_by_id"`
- **description:** Defines the macro for replacing elements by their ID in the hydration process.
- **value:** `"private_cweb_hydration_replace_by_id"`
- **type:** `string`
- **usage:** Used to replace elements identified by their ID in hydration-related operations.
------------------------
### [src/config/hydratation/macros.errors.h](/src/config/hydratation/macros.errors.h):
### `#define CWEB_HYDRATION_NOT_BODY_JSON_PROVIDED 1`
- **description:** Error code indicating that a JSON body was not provided.
- **value:** `1`
- **message:** `"json body not provided"`

### `#define CWEB_HYDRATION_NOT_BODY_IS_NOT_OBJECT 2`
- **description:** Error code indicating that the provided JSON body is not an object.
- **value:** `2`
- **message:** `"json body not not object"`

### `#define CWEB_HYDRATION_NAME_NOT_PROVIDED 3`
- **description:** Error code indicating that the 'name' field is missing in the JSON body.
- **value:** `3`
- **message:** `"body['name'] not provided"`

### `#define CWEB_HYDRATION_NAME_NOT_STRING 4`
- **description:** Error code indicating that the 'name' field is not a string.
- **value:** `4`
- **message:** `"body['name'] its not string"`

### `#define CWEB_HYDRATION_ARGS_NOT_PROVIDED 5`
- **description:** Error code indicating that the 'args' field is missing in the JSON body.
- **value:** `5`
- **message:** `"body['args'] not provided"`

### `#define CWEB_HYDRATION_ARGS_NOT_ARRAY 6`
- **description:** Error code indicating that the 'args' field is not an array.
- **value:** `6`
- **message:** `"body['args'] its not array"`

### `#define CWEB_HYDRATION_CONTENT_NOT_PROVIDED 7`
- **description:** Error code indicating that the 'content' field is missing in the JSON body.
- **value:** `7`
- **message:** `"body['content'] not provided"`

### `#define CWEB_HYDRATION_CONTENT_NOT_OBJECT 8`
- **description:** Error code indicating that the 'content' field is not an object.
- **value:** `8`
- **message:** `"body['content'] not a object"`

### `#define CWEB_HYDRATION_CONTENT_KEY_NOT_PROVIDED 9`
- **description:** Error code indicating that a specific key is missing in the 'content' object.
- **value:** `9`
- **message:** `"body['content']['%s'] not provided at content"`

### `#define CWEB_HYDRATION_CONTENT_SEARCH_NOT_ARRAY 10`
- **description:** Error code indicating that a specific key in the 'content' object is not an array.
- **value:** `10`
- **message:** `"body['content']['%s'] is not of array"`

### `#define CWEB_HYDRATION_CONTENT_SEARCH_NOT_EXIST 11`
- **description:** Error code indicating that a search index does not exist.
- **value:** `11`
- **message:** `"search at index %d not exist"`

### `#define CWEB_HYDRATION_SEARCH_ITEM_NOT_EXIST 12`
- **description:** Error code indicating that a specific item in the search array does not exist.
- **value:** `12`
- **message:** `"body['content']['%s'][%d] not exist"`

### `#define CWEB_HYDRATION_SEARCH_ITEM_WRONG_TYPE 13`
- **description:** Error code indicating that a specific item in the search array has the wrong type.
- **value:** `13`
- **message:** `"body['content']['%s'][%d] its not of type %s"`

### `#define CWEB_HYDRATION_INDEX_ARGS_NOT_PROVIDED 14`
- **description:** Error code indicating that an argument at a specific index is missing.
- **value:** `14`
- **message:** `"body['args'][%d] not provided"`

### `#define CWEB_HYDRATION_INDEX_ARGS_WRONG_TYPE 15`
- **description:** Error code indicating that an argument at a specific index has the wrong type.
- **value:** `15`
- **message:** `"body['args'][%d] is not of type %s"`

### `#define CWEB_BRIDGE_NOT_FOUND 16`
- **description:** Error code indicating that a bridge with the specified name was not found.
- **value:** `16`
- **message:** `"bridge of name %s not found"`

### `#define CWEB_SEARCH_NOT_EXIST 17`
- **description:** Error code indicating that a search at a specific index does not exist.
- **value:** `17`
- **message:** `"search at index %d not exist"`

### `#define CWEB_HYDRATION_STRING "string"`
- **description:** String constant representing the type 'string'.
- **value:** `"string"`
- **usage:** Used to specify or check for string types.

### `#define CWEB_HYDRATION_BOOL "bool"`
- **description:** String constant representing the type 'bool'.
- **value:** `"bool"`
- **usage:** Used to specify or check for boolean types.

### `#define CWEB_HYDRATION_NUMBER "number"`
- **description:** String constant representing the type 'number'.
- **value:** `"number"`
- **usage:** Used to specify or check for numeric types.
------------------------
### [src/config/hydratation/macros.keys.h](/src/config/hydratation/macros.keys.h):
### `#define CWEB_HYDRATION_JSON_ERROR_CODE_KEY "error_code"`
- **description:** Defines the key for the error code in the hydration JSON.
- **value:** `"error_code"`
- **type:** `string`
- **usage:** Used to identify the error code field in JSON responses.

### `#define CWEB_HYDRATION_JSON_ERROR_MENSSAGE "error_menssage"`
- **description:** Defines the key for the error message in the hydration JSON.
- **value:** `"error_menssage"`
- **type:** `string`
- **usage:** Used to identify the error message field in JSON responses.

### `#define CWEB_HYDRATON_JSON_DATA "data"`
- **description:** Defines the key for the data field in the hydration JSON.
- **value:** `"data"`
- **type:** `string`
- **usage:** Used to identify the data field in JSON responses.

### `#define CWEB_HYDRATON_JSON_NAME "name"`
- **description:** Defines the key for the name field in the hydration JSON.
- **value:** `"name"`
- **type:** `string`
- **usage:** Used to identify the name field in JSON responses.

### `#define CWEB_HYDRATON_JSON_HTML "html"`
- **description:** Defines the key for the HTML content field in the hydration JSON.
- **value:** `"html"`
- **type:** `string`
- **usage:** Used to identify the HTML content field in JSON responses.

### `#define CWEB_HYDRATON_JSON_MSG "msg"`
- **description:** Defines the key for the message field in the hydration JSON.
- **value:** `"msg"`
- **type:** `string`
- **usage:** Used to identify the message field in JSON responses.

### `#define CWEB_HYDRATON_JSON_CODE "code"`
- **description:** Defines the key for the code field in the hydration JSON.
- **value:** `"code"`
- **type:** `string`
- **usage:** Used to identify the code field in JSON responses.

### `#define CWEB_HYDRATON_JSON_KEY "key"`
- **description:** Defines the key for the key field in the hydration JSON.
- **value:** `"key"`
- **type:** `string`
- **usage:** Used to identify the key field in JSON responses.

### `#define CWEB_HYDRATON_JSON_QUERY_SELECTOR "query_selector"`
- **description:** Defines the key for the query selector field in the hydration JSON.
- **value:** `"query_selector"`
- **type:** `string`
- **usage:** Used to identify the query selector field in JSON responses.

### `#define CWEB_HYDRATON_JSON_VALUE "value"`
- **description:** Defines the key for the value field in the hydration JSON.
- **value:** `"value"`
- **type:** `string`
- **usage:** Used to identify the value field in JSON responses.

### `#define CWEB_HYDRATION_JSON_URL "url"`
- **description:** Defines the key for the URL field in the hydration JSON.
- **value:** `"url"`
- **type:** `string`
- **usage:** Used to identify the URL field in JSON responses.

### `#define CWEB_HYDRATON_JSON_ARGS "args"`
- **description:** Defines the key for the arguments field in the hydration JSON.
- **value:** `"args"`
- **type:** `string`
- **usage:** Used to identify the arguments field in JSON responses.

### `#define CWEB_HYDRATON_JSON_CONTENT "content"`
- **description:** Defines the key for the content field in the hydration JSON.
- **value:** `"content"`
- **type:** `string`
- **usage:** Used to identify the content field in JSON responses.
------------------------
### [src/config/macros.request.h](/src/config/macros.request.h):
### `#define INVALID_HTTP -1`
- **description:** Represents an invalid HTTP status or error.
- **value:** `-1`
- **type:** `int`
- **usage:** Used to indicate an invalid HTTP-related operation or state.

### `#define MAX_HEADER_SIZE_CODE -2`
- **description:** Represents an error code for exceeding the maximum allowed header size.
- **value:** `-2`
- **type:** `int`
- **usage:** Used to indicate that the HTTP header size exceeds the permissible limit.

### `#define MAX_HEADER_LEN 20000`
- **description:** Defines the maximum length of an HTTP header in bytes.
- **value:** `20000`
- **type:** `int`
- **usage:** Used to set the upper limit for HTTP header sizes.

### `#define MAX_LINE_LEN MAX_HEADER_LEN / 2`
- **description:** Defines the maximum length of a line within an HTTP header, derived from `MAX_HEADER_LEN`.
- **value:** `10000` (since `MAX_HEADER_LEN` is 20000)
- **type:** `int`
- **usage:** Used to set the upper limit for line lengths within HTTP headers.

### `#define READ_ERROR -3`
- **description:** Represents an error encountered during a read operation.
- **value:** `-3`
- **type:** `int`
- **usage:** Used to indicate a failure in reading data.

### `#define MAX_CONTENT_SIZE -4`
- **description:** Represents an error code for exceeding the maximum allowed content size.
- **value:** `-4`
- **type:** `int`
- **usage:** Used to indicate that the content size exceeds the permissible limit.

### `#define UNDEFINED_CONTENT -5`
- **description:** Represents an error code for undefined or missing content.
- **value:** `-5`
- **type:** `int`
- **usage:** Used to indicate that the content is not defined or unavailable.

### `#define INVALID_JSON -6`
- **description:** Represents an error code for invalid JSON data.
- **value:** `-6`
- **type:** `int`
- **usage:** Used to indicate that the JSON data is malformed or invalid.

### `#define CWEB_UTF_DECREMENTER 64`
- **description:** A constant used for UTF-8 character decrement operations.
- **value:** `64`
- **type:** `int`
- **usage:** Used in UTF-8 character manipulation or decoding.

### `#define CWEB_C_NON_ASSCI_SIGIN -61`
- **description:** Represents a non-ASCII sign in the context of CWEB operations.
- **value:** `-61`
- **type:** `int`
- **usage:** Used to identify or handle non-ASCII characters in CWEB-related processes.
------------------------
### [src/config/macros.response.h](/src/config/macros.response.h):
### `#define CWEB_AUTO_SET_CONTENT NULL`
- **description:** Macro that sets the content to `NULL` automatically.
- **value:** `NULL`
- **usage:** Used to automatically set content to `NULL` in specific contexts.

### `#define CWEB_OK 200`
- **description:** HTTP status code for a successful request.
- **value:** `200`
- **usage:** Indicates that the request has succeeded.

### `#define CWEB_NOT_FOUND 404`
- **description:** HTTP status code for a resource not found.
- **value:** `404`
- **usage:** Indicates that the requested resource could not be found on the server.

### `#define CWEB_BAD_REQUEST 400`
- **description:** HTTP status code for a bad request.
- **value:** `400`
- **usage:** Indicates that the server cannot process the request due to client error.

### `#define CWEB_FORBIDDEN 403`
- **description:** HTTP status code for a forbidden request.
- **value:** `403`
- **usage:** Indicates that the server understands the request but refuses to authorize it.

### `#define CWEB_INTERNAL_SERVER_ERROR 500`
- **description:** HTTP status code for an internal server error.
- **value:** `500`
- **usage:** Indicates that the server encountered an unexpected condition that prevented it from fulfilling the request.
------------------------
### [src/cors/fdeclare.cors.h](/src/cors/fdeclare.cors.h):
### `void private_cweb_generate_cors_response(struct CwebHttpResponse *response)`
- **params:**
    - `struct CwebHttpResponse *response`: [Reference/pointer parameter representing the HTTP response to which CORS headers will be added]
- **returns:** `void` [This function does not return a value]
- **description:** This function is responsible for generating and adding Cross-Origin Resource Sharing (CORS) headers to the provided HTTP response. It ensures that the response includes the necessary headers to allow cross-origin requests from web applications.
------------------------
### [src/cors/fdefine.cors.c](/src/cors/fdefine.cors.c):
### `void private_cweb_generate_cors_response(struct CwebHttpResponse *response)`
**description:** This function generates a CORS (Cross-Origin Resource Sharing) response by adding necessary headers to the provided HTTP response object. It allows any origin and any method to access the resource.
- **params:**
    - `struct CwebHttpResponse *response`: A pointer to the HTTP response object to which the CORS headers will be added.
- **returns:** `void` (No return value)
- **preconditions:** The `response` object must be valid and properly initialized.
- **postconditions:** The `response` object will have the "Access-Control-Allow-Origin" and "Access-Control-Allow-Method" headers set to "*".
- **side_effects:** Modifies the `response` object by adding headers to it.
------------------------
### [src/dict/fdeclare.dict.h](/src/dict/fdeclare.dict.h):
### `CwebDict *newCwebDict()`
- **returns:** `CwebDict*` [A pointer to a newly created CwebDict instance]

### `void CwebDict_set(CwebDict *self, const char *key, const char *value)`
- **params:**
    - `CwebDict* self`: [The CwebDict instance to modify]
    - `const char* key`: [The key under which the value will be stored]
    - `const char* value`: [The value to be stored]
- **description:** [Sets a key-value pair in the CwebDict]

### `char *CwebDict_get(CwebDict *self, const char *key)`
- **params:**
    - `CwebDict* self`: [The CwebDict instance to query]
    - `const char* key`: [The key whose value is to be retrieved]
- **returns:** `char*` [The value associated with the key, or NULL if the key does not exist]

### `char *CwebDict_get_by_normalized_key(CwebDict *self, const char *key, const char *chars_to_remove)`
- **params:**
    - `CwebDict* self`: [The CwebDict instance to query]
    - `const char* key`: [The key whose value is to be retrieved]
    - `const char* chars_to_remove`: [Characters to remove from the key before lookup]
- **returns:** `char*` [The value associated with the normalized key, or NULL if the key does not exist]

### `void CwebDict_represent(CwebDict *dict)`
- **params:**
    - `CwebDict* dict`: [The CwebDict instance to represent]
- **description:** [Prints a representation of the CwebDict to the console]

### `void CwebDict_free(CwebDict *self)`
- **params:**
    - `CwebDict* self`: [The CwebDict instance to free]
- **description:** [Frees the memory allocated for the CwebDict instance]
------------------------
### [src/dict/fdefine.dict.c](/src/dict/fdefine.dict.c):
### `CwebDict *newCwebDict()`
**description:** Allocates and initializes a new `CwebDict` structure.
- **returns:** `CwebDict*` A pointer to the newly created `CwebDict` structure.
- **preconditions:** None.
- **postconditions:** The returned `CwebDict` has an empty keys/values array and size set to 0.
- **side_effects:** Allocates memory for the `CwebDict` and its keys/values array.

### `char *CwebDict_get_by_normalized_key(CwebDict *self, const char *key, const char *chars_to_remove)`
**description:** Retrieves a value from the dictionary by comparing a normalized version of the key.
- **params:**
    - `CwebDict *self`: The dictionary to search in.
    - `const char *key`: The key to search for.
    - `const char *chars_to_remove`: Characters to remove from the key for normalization.
- **returns:** `char*` The value associated with the normalized key, or `NULL` if not found.
- **preconditions:** The dictionary (`self`) must be initialized.
- **postconditions:** None.
- **side_effects:** Allocates and frees memory for normalized key strings during comparison.

### `void CwebDict_set(CwebDict *self, const char *key, const char *value)`
**description:** Adds or updates a key-value pair in the dictionary.
- **params:**
    - `CwebDict *self`: The dictionary to modify.
    - `const char *key`: The key to set.
    - `const char *value`: The value to associate with the key.
- **returns:** None.
- **preconditions:** The dictionary (`self`) must be initialized.
- **postconditions:** The dictionary contains the new key-value pair, and its size is incremented by 1.
- **side_effects:** Allocates memory for the new key-value pair and reallocates the keys/values array.

### `char *CwebDict_get(CwebDict *self, const char *key)`
**description:** Retrieves a value from the dictionary by its exact key.
- **params:**
    - `CwebDict *self`: The dictionary to search in.
    - `const char *key`: The exact key to search for.
- **returns:** `char*` The value associated with the key, or `NULL` if not found.
- **preconditions:** The dictionary (`self`) must be initialized.
- **postconditions:** None.
- **side_effects:** None.

### `void CwebDict_represent(CwebDict *dict)`
**description:** Prints the contents of the dictionary for debugging or representation purposes.
- **params:**
    - `CwebDict *dict`: The dictionary to represent.
- **returns:** None.
- **preconditions:** The dictionary (`dict`) must be initialized.
- **postconditions:** None.
- **side_effects:** Outputs the dictionary contents to the console.

### `void CwebDict_free(CwebDict *self)`
**description:** Frees all memory associated with the dictionary, including its keys and values.
- **params:**
    - `CwebDict *self`: The dictionary to free.
- **returns:** None.
- **preconditions:** The dictionary (`self`) must be initialized.
- **postconditions:** All memory associated with the dictionary is freed.
- **side_effects:** Deallocates memory for the dictionary, its keys, and values.
------------------------
### [src/dict/typesB.dict.h](/src/dict/typesB.dict.h):
### `typedef struct CwebDict`
- **description:** A structure representing a dictionary in the Cweb framework. It is used to store key-value pairs dynamically.
- **fields:**
    - `int size`: The number of key-value pairs currently stored in the dictionary.
    - `CwebKeyVal **keys_vals`: An array of pointers to `CwebKeyVal` structures, each representing a key-value pair in the dictionary.
------------------------
### [src/extras/fdeclare.extras.h](/src/extras/fdeclare.extras.h):
### `unsigned char *cweb_load_any_content(const char *path, int *size, bool *is_binary)`
- **params:**
    - `const char *path`: The path to the file to be loaded.
    - `int *size`: A pointer to store the size of the loaded content.
    - `bool *is_binary`: A pointer to store whether the content is binary.
- **returns:** `unsigned char *`: A pointer to the loaded content.

### `char *cweb_load_string_file_content(const char *path)`
- **params:**
    - `const char *path`: The path to the file to be loaded.
- **returns:** `char *`: A pointer to the loaded string content.

### `unsigned char *cweb_load_binary_content(const char *path, int *size)`
- **params:**
    - `const char *path`: The path to the file to be loaded.
    - `int *size`: A pointer to store the size of the loaded binary content.
- **returns:** `unsigned char *`: A pointer to the loaded binary content.

### `const char *cweb_generate_content_type(const char *file_name)`
- **params:**
    - `const char *file_name`: The name of the file for which to generate the content type.
- **returns:** `const char *`: The generated content type string.

### `char *private_cweb_convert_url_encoded_text(const char *text)`
- **params:**
    - `const char *text`: The URL-encoded text to convert.
- **returns:** `char *`: The decoded text.

### `char *private_CWeb_format_vaarg(const char *expression, va_list args)`
- **params:**
    - `const char *expression`: The format string.
    - `va_list args`: The variable arguments list.
- **returns:** `char *`: The formatted string.

### `char *private_CWeb_format(const char *expression, ...)`
- **params:**
    - `const char *expression`: The format string.
    - `...`: Variable arguments to be formatted.
- **returns:** `char *`: The formatted string.

### `char *private_cweb_convert_to_hexa(const char *data)`
- **params:**
    - `const char *data`: The data to convert to hexadecimal.
- **returns:** `char *`: The hexadecimal representation of the data.

### `CTextStack *private_cweb_create_ascii_code(const char *msg)`
- **params:**
    - `const char *msg`: The message to convert to ASCII code.
- **returns:** `CTextStack *`: A stack containing the ASCII code representation.
------------------------
### [src/extras/fdefine.extras.c](/src/extras/fdefine.extras.c):
### `unsigned char *cweb_load_any_content(const char *path, int *size, bool *is_binary)`
**description:** Loads the content of a file into memory, determining whether the content is binary or text.
- **params:**
    - `const char *path`: The path to the file to be loaded.
    - `int *size`: A pointer to store the size of the loaded content.
    - `bool *is_binary`: A pointer to a boolean indicating whether the content is binary (true) or text (false).
- **returns:** `unsigned char *`: A pointer to the loaded content, or NULL if the file could not be opened.
- **preconditions:** The file at `path` must exist and be readable.
- **postconditions:** The `size` and `is_binary` parameters are updated with the file's size and content type.
- **side_effects:** Allocates memory for the file content, which must be freed by the caller.

### `char *cweb_load_string_file_content(const char *path)`
**description:** Loads the content of a text file into memory as a null-terminated string.
- **params:**
    - `const char *path`: The path to the file to be loaded.
- **returns:** `char *`: A pointer to the loaded string, or NULL if the file could not be opened.
- **preconditions:** The file at `path` must exist and be readable.
- **postconditions:** The returned string is null-terminated.
- **side_effects:** Allocates memory for the file content, which must be freed by the caller.

### `unsigned char *cweb_load_binary_content(const char *path, int *size)`
**description:** Loads the content of a binary file into memory.
- **params:**
    - `const char *path`: The path to the file to be loaded.
    - `int *size`: A pointer to store the size of the loaded content.
- **returns:** `unsigned char *`: A pointer to the loaded content, or NULL if the file could not be opened.
- **preconditions:** The file at `path` must exist and be readable.
- **postconditions:** The `size` parameter is updated with the file's size.
- **side_effects:** Allocates memory for the file content, which must be freed by the caller.

### `const char *cweb_generate_content_type(const char *file_name)`
**description:** Determines the MIME content type based on the file extension.
- **params:**
    - `const char *file_name`: The name of the file (or path) to analyze.
- **returns:** `const char *`: A string representing the MIME type (e.g., "text/html").
- **preconditions:** The `file_name` must not be NULL.
- **postconditions:** Returns a valid MIME type string.
- **side_effects:** None.

### `char *private_cweb_convert_url_encoded_text(const char *text)`
**description:** Converts URL-encoded text into its original form.
- **params:**
    - `const char *text`: The URL-encoded text to convert.
- **returns:** `char *`: A pointer to the decoded text.
- **preconditions:** The `text` must not be NULL.
- **postconditions:** The returned string is null-terminated.
- **side_effects:** Allocates memory for the decoded text, which must be freed by the caller.

### `char *private_CWeb_format_vaarg(const char *expression, va_list args)`
**description:** Formats a string using a variable argument list.
- **params:**
    - `const char *expression`: The format string.
    - `va_list args`: The variable arguments to format.
- **returns:** `char *`: A pointer to the formatted string.
- **preconditions:** The `expression` must not be NULL.
- **postconditions:** The returned string is null-terminated.
- **side_effects:** Allocates memory for the formatted string, which must be freed by the caller.

### `char *private_CWeb_format(const char *expression, ...)`
**description:** Formats a string using variable arguments.
- **params:**
    - `const char *expression`: The format string.
    - `...`: The variable arguments to format.
- **returns:** `char *`: A pointer to the formatted string.
- **preconditions:** The `expression` must not be NULL.
- **postconditions:** The returned string is null-terminated.
- **side_effects:** Allocates memory for the formatted string, which must be freed by the caller.

### `char *private_cweb_convert_to_hexa(const char *data)`
**description:** Converts a string into its hexadecimal representation.
- **params:**
    - `const char *data`: The string to convert.
- **returns:** `char *`: A pointer to the hexadecimal string.
- **preconditions:** The `data` must not be NULL.
- **postconditions:** The returned string is null-terminated.
- **side_effects:** Allocates memory for the hexadecimal string, which must be freed by the caller.

### `CTextStack *private_cweb_create_assci_code(const char *msg)`
**description:** Creates an ASCII code representation of a string.
- **params:**
    - `const char *msg`: The string to convert.
- **returns:** `CTextStack *`: A pointer to the ASCII code representation.
- **preconditions:** The `msg` must not be NULL.
- **postconditions:** The returned `CTextStack` must be freed by the caller.
- **side_effects:** Allocates memory for the ASCII code representation.
------------------------
### [src/keyval/fdeclare.key_val.h](/src/keyval/fdeclare.key_val.h):
### `CwebKeyVal* newCwebKeyVal(const char *key, const char *value)`
- **params:**
    - `const char *key`: [Key for the key-value pair]
    - `const char *value`: [Value associated with the key]
- **returns:** `CwebKeyVal*` [A pointer to a new CwebKeyVal object]

### `void CwebKeyVal_represent(CwebKeyVal *self)`
- **params:**
    - `CwebKeyVal *self`: [Pointer to the CwebKeyVal object to represent]
- **returns:** `void` [No return value, represents the object]

### `void CwebKeyVal_free(CwebKeyVal *self)`
- **params:**
    - `CwebKeyVal *self`: [Pointer to the CwebKeyVal object to free]
- **returns:** `void` [No return value, frees the object]
------------------------
### [src/keyval/fdefine.key_val.c](/src/keyval/fdefine.key_val.c):
### `CwebKeyVal* newCwebKeyVal(const char *key, const char *value)`
**description:** Allocates and initializes a new `CwebKeyVal` structure with the given key and value.
- **params:**
    - `const char *key`: The key to be stored in the `CwebKeyVal` structure.
    - `const char *value`: The value associated with the key in the `CwebKeyVal` structure.
- **returns:** `CwebKeyVal*` A pointer to the newly allocated and initialized `CwebKeyVal` structure.
- **preconditions:** The `key` and `value` must be valid C strings.
- **postconditions:** The `CwebKeyVal` structure is allocated and contains copies of the `key` and `value`.
- **side_effects:** Memory is allocated for the `CwebKeyVal` structure and its `key` and `value` fields.

### `void CwebKeyVal_represent(CwebKeyVal *self)`
**description:** Prints the key and value of the `CwebKeyVal` structure to the standard output.
- **params:**
    - `CwebKeyVal *self`: A pointer to the `CwebKeyVal` structure to be represented.
- **returns:** `void` No return value.
- **preconditions:** The `self` pointer must be valid and point to an initialized `CwebKeyVal` structure.
- **postconditions:** The key and value are printed to the standard output.
- **side_effects:** Output to the standard output.

### `void CwebKeyVal_free(CwebKeyVal *self)`
**description:** Frees the memory allocated for the `CwebKeyVal` structure and its `key` and `value` fields.
- **params:**
    - `CwebKeyVal *self`: A pointer to the `CwebKeyVal` structure to be freed.
- **returns:** `void` No return value.
- **preconditions:** The `self` pointer must be valid and point to an allocated `CwebKeyVal` structure.
- **postconditions:** The memory for the `CwebKeyVal` structure and its `key` and `value` fields is freed.
- **side_effects:** Memory is deallocated.
------------------------
### [src/keyval/types.keyval.h](/src/keyval/types.keyval.h):
### `typedef struct CwebKeyVal`
- **description:** A structure representing a key-value pair, commonly used in associative data structures like dictionaries or hash tables.
- **original_type:** `struct CwebKeyVal`
- **fields:**
    - `char *key`: A pointer to a character array that holds the key of the key-value pair.
    - `char *value`: A pointer to a character array that holds the value associated with the key.
------------------------
### [src/macros/macros.debug.h](/src/macros/macros.debug.h):
### `#define cweb_print(...)`
- **description:** This macro is used for conditional printing based on whether `CWEB_DEBUG` is defined. When `CWEB_DEBUG` is defined, it expands to `printf(__VA_ARGS__)`, allowing debug messages to be printed. Otherwise, it expands to an empty statement, effectively disabling debug output.
- **params:**
    - `...`: Variadic arguments that are passed directly to `printf` when `CWEB_DEBUG` is defined.
- **returns:** This macro does not return a value; it either prints the formatted output or does nothing.
- **side_effects:** When `CWEB_DEBUG` is defined, it will print to stdout. When not defined, there are no side effects.
------------------------
### [src/request/request/fdeclare.request.h](/src/request/request/fdeclare.request.h):
### `CwebHttpRequest *newCwebHttpRequest(int socket)`
- **params:**
    - `int socket`: [The socket file descriptor used to create the HTTP request object]
- **returns:** `CwebHttpRequest*` [A pointer to a new HTTP request object]

### `unsigned char *CwebHttpRequest_read_content(CwebHttpRequest *self, long max_content_size)`
- **params:**
    - `CwebHttpRequest *self`: [Pointer to the HTTP request object]
    - `long max_content_size`: [Maximum size of content to read]
- **returns:** `unsigned char*` [A pointer to the content read from the request]

### `cJSON *CWebHttpRequest_read_cJSON(CwebHttpRequest *self, long max_content_size)`
- **params:**
    - `CwebHttpRequest *self`: [Pointer to the HTTP request object]
    - `long max_content_size`: [Maximum size of JSON content to read]
- **returns:** `cJSON*` [A pointer to the JSON object parsed from the request content]

### `CTextStack *CwebHttpRequest_create_empty_stack(CwebHttpRequest *self)`
- **params:**
    - `CwebHttpRequest *self`: [Pointer to the HTTP request object]
- **returns:** `CTextStack*` [A pointer to an empty text stack]

### `CTextStack *CwebHttpRequest_create_stack(CwebHttpRequest *self)`
- **params:**
    - `CwebHttpRequest *self`: [Pointer to the HTTP request object]
- **returns:** `CTextStack*` [A pointer to a text stack]

### `char *CwebHttpRequest_get_header(CwebHttpRequest *self, const char *key)`
- **params:**
    - `CwebHttpRequest *self`: [Pointer to the HTTP request object]
    - `const char *key`: [The header key to retrieve]
- **returns:** `char*` [A pointer to the value of the specified header]

### `char *CwebHttpRequest_get_param_by_sanitized_key(CwebHttpRequest *self, const char *key, const char *chars_to_remove)`
- **params:**
    - `CwebHttpRequest *self`: [Pointer to the HTTP request object]
    - `const char *key`: [The parameter key to retrieve]
    - `const char *chars_to_remove`: [Characters to remove from the key before lookup]
- **returns:** `char*` [A pointer to the value of the specified parameter after sanitization]

### `char *CwebHttpRequest_get_param(CwebHttpRequest *self, const char *key)`
- **params:**
    - `CwebHttpRequest *self`: [Pointer to the HTTP request object]
    - `const char *key`: [The parameter key to retrieve]
- **returns:** `char*` [A pointer to the value of the specified parameter]

### `char *CwebHttpRequest_get_header_by_normalized_key(CwebHttpRequest *self, const char *key, const char *chars_to_remove)`
- **params:**
    - `CwebHttpRequest *self`: [Pointer to the HTTP request object]
    - `const char *key`: [The header key to retrieve]
    - `const char *chars_to_remove`: [Characters to remove from the key before lookup]
- **returns:** `char*` [A pointer to the value of the specified header after normalization]

### `void CwebHttpRequest_set_route(CwebHttpRequest *self, const char *route)`
- **params:**
    - `CwebHttpRequest *self`: [Pointer to the HTTP request object]
    - `const char *route`: [The route to set for the request]

### `void CwebHttpRequest_add_header(CwebHttpRequest *self, const char *key, const char *value)`
- **params:**
    - `CwebHttpRequest *self`: [Pointer to the HTTP request object]
    - `const char *key`: [The header key to add]
    - `const char *value`: [The value of the header to add]

### `void CwebHttpRequest_add_param(CwebHttpRequest *self, const char *key, const char *value)`
- **params:**
    - `CwebHttpRequest *self`: [Pointer to the HTTP request object]
    - `const char *key`: [The parameter key to add]
    - `const char *value`: [The value of the parameter to add]

### `void CwebHttpRequest_set_method(CwebHttpRequest *self, const char *method)`
- **params:**
    - `CwebHttpRequest *self`: [Pointer to the HTTP request object]
    - `const char *method`: [The HTTP method to set for the request]

### `void CwebHttpRequest_set_content_string(CwebHttpRequest *self, const char *content)`
- **params:**
    - `CwebHttpRequest *self`: [Pointer to the HTTP request object]
    - `const char *content`: [The content string to set for the request]

### `void CwebHttpRequest_represent(CwebHttpRequest *self)`
- **params:**
    - `CwebHttpRequest *self`: [Pointer to the HTTP request object]

### `void CwebHttpRequest_free(CwebHttpRequest *self)`
- **params:**
    - `CwebHttpRequest *self`: [Pointer to the HTTP request object to free]
------------------------
### [src/request/request/fdefine.request.c](/src/request/request/fdefine.request.c):
```md
### `CwebHttpRequest *newCwebHttpRequest(int socket)`
**description:** Allocates and initializes a new `CwebHttpRequest` object with the given socket.
- **params:**
    - `int socket`: The socket to be associated with the request.
- **returns:** `CwebHttpRequest *` A pointer to the newly created `CwebHttpRequest` object.
- **preconditions:** The socket must be valid.
- **postconditions:** The `CwebHttpRequest` object is initialized with the socket, and dictionaries for params and headers are created.
- **side_effects:** Memory is allocated for the `CwebHttpRequest` object and its components.

### `unsigned char *CwebHttpRequest_read_content(CwebHttpRequest *self, long max_content_size)`
**description:** Reads the content of the HTTP request up to a specified maximum size.
- **params:**
    - `CwebHttpRequest *self`: Pointer to the `CwebHttpRequest` object.
    - `long max_content_size`: The maximum size of content to read.
- **returns:** `unsigned char *` The content of the request, or NULL if an error occurs.
- **preconditions:** The `self` pointer must be valid, and `max_content_size` must be non-negative.
- **postconditions:** If successful, the content is stored in `self->content` and URL-encoded data is processed if applicable.
- **side_effects:** May allocate memory for `self->content`, sets `self->content_error` if an error occurs, and may modify `self->params`.

### `cJSON *CWebHttpRequest_read_cJSON(CwebHttpRequest *self, long max_content_size)`
**description:** Reads and parses the content of the HTTP request as JSON.
- **params:**
    - `CwebHttpRequest *self`: Pointer to the `CwebHttpRequest` object.
    - `long max_content_size`: The maximum size of content to read.
- **returns:** `cJSON *` A pointer to the parsed JSON object, or NULL if an error occurs.
- **preconditions:** The `self` pointer must be valid, and `max_content_size` must be non-negative.
- **postconditions:** If successful, the JSON content is stored in `self->json`.
- **side_effects:** May allocate memory for `self->json`, sets `self->content_error` if an error occurs.

### `char *CwebHttpRequest_get_header(CwebHttpRequest *self, const char *key)`
**description:** Retrieves the value of a header from the request.
- **params:**
    - `CwebHttpRequest *self`: Pointer to the `CwebHttpRequest` object.
    - `const char *key`: The key of the header to retrieve.
- **returns:** `char *` The value of the header, or NULL if not found.
- **preconditions:** The `self` pointer must be valid, and `key` must be non-NULL.
- **postconditions:** None.
- **side_effects:** None.

### `char *CwebHttpRequest_get_param_by_sanitized_key(CwebHttpRequest *self, const char *key, const char *chars_to_remove)`
**description:** Retrieves the value of a parameter from the request, sanitizing the key.
- **params:**
    - `CwebHttpRequest *self`: Pointer to the `CwebHttpRequest` object.
    - `const char *key`: The key of the parameter to retrieve.
    - `const char *chars_to_remove`: Characters to remove from the key before lookup.
- **returns:** `char *` The value of the parameter, or NULL if not found.
- **preconditions:** The `self` pointer must be valid, and `key` must be non-NULL.
- **postconditions:** None.
- **side_effects:** None.

### `char *CwebHttpRequest_get_param(CwebHttpRequest *self, const char *key)`
**description:** Retrieves the value of a parameter from the request.
- **params:**
    - `CwebHttpRequest *self`: Pointer to the `CwebHttpRequest` object.
    - `const char *key`: The key of the parameter to retrieve.
- **returns:** `char *` The value of the parameter, or NULL if not found.
- **preconditions:** The `self` pointer must be valid, and `key` must be non-NULL.
- **postconditions:** None.
- **side_effects:** None.

### `char *CwebHttpRequest_get_header_by_normalized_key(CwebHttpRequest *self, const char *key, const char *chars_to_remove)`
**description:** Retrieves the value of a header from the request, normalizing the key.
- **params:**
    - `CwebHttpRequest *self`: Pointer to the `CwebHttpRequest` object.
    - `const char *key`: The key of the header to retrieve.
    - `const char *chars_to_remove`: Characters to remove from the key before lookup.
- **returns:** `char *` The value of the header, or NULL if not found.
- **preconditions:** The `self` pointer must be valid, and `key` must be non-NULL.
- **postconditions:** None.
- **side_effects:** None.

### `void CwebHttpRequest_set_route(CwebHttpRequest *self, const char *route)`
**description:** Sets the route for the HTTP request.
- **params:**
    - `CwebHttpRequest *self`: Pointer to the `CwebHttpRequest` object.
    - `const char *route`: The route to set.
- **returns:** None.
- **preconditions:** The `self` pointer must be valid, and `route` must be non-NULL.
- **postconditions:** The `self->route` is set to the provided route.
- **side_effects:** Memory is allocated for `self->route`.

### `void CwebHttpRequest_add_header(CwebHttpRequest *self, const char *key, const char *value)`
**description:** Adds a header to the HTTP request.
- **params:**
    - `CwebHttpRequest *self`: Pointer to the `CwebHttpRequest` object.
    - `const char *key`: The key of the header to add.
    - `const char *value`: The value of the header to add.
- **returns:** None.
- **preconditions:** The `self` pointer must be valid, and `key` and `value` must be non-NULL.
- **postconditions:** The header is added to `self->headers`.
- **side_effects:** None.

### `void CwebHttpRequest_add_param(CwebHttpRequest *self, const char *key, const char *value)`
**description:** Adds a parameter to the HTTP request.
- **params:**
    - `CwebHttpRequest *self`: Pointer to the `CwebHttpRequest` object.
    - `const char *key`: The key of the parameter to add.
    - `const char *value`: The value of the parameter to add.
- **returns:** None.
- **preconditions:** The `self` pointer must be valid, and `key` and `value` must be non-NULL.
- **postconditions:** The parameter is added to `self->params`.
- **side_effects:** None.

### `void CwebHttpRequest_set_method(CwebHttpRequest *self, const char *method)`
**description:** Sets the method for the HTTP request.
- **params:**
    - `CwebHttpRequest *self`: Pointer to the `CwebHttpRequest` object.
    - `const char *method`: The method to set.
- **returns:** None.
- **preconditions:** The `self` pointer must be valid, and `method` must be non-NULL.
- **postconditions:** The `self->method` is set to the provided method.
- **side_effects:** Memory is allocated for `self->method`.

### `void CwebHttpRequest_set_content_string(CwebHttpRequest *self, const char *content)`
**description:** Sets the content of the HTTP request from a string.
- **params:**
    - `CwebHttpRequest *self`: Pointer to the `CwebHttpRequest` object.
    - `const char *content`: The content string to set.
- **returns:** None.
- **preconditions:** The `self` pointer must be valid, and `content` must be non-NULL.
- **postconditions:** The `self->content` and `self->content_length` are set to the provided content.
- **side_effects:** Memory is allocated for `self->content`.

### `void CwebHttpRequest_represent(CwebHttpRequest *self)`
**description:** Prints a representation of the HTTP request to stdout.
- **params:**
    - `CwebHttpRequest *self`: Pointer to the `CwebHttpRequest` object.
- **returns:** None.
- **preconditions:** The `self` pointer must be valid.
- **postconditions:** None.
- **side_effects:** Output to stdout.

### `CTextStack *CwebHttpRequest_create_empty_stack(CwebHttpRequest *self)`
**description:** Creates an empty text stack associated with the HTTP request.
- **params:**
    - `CwebHttpRequest *self`: Pointer to the `CwebHttpRequest` object.
- **returns:** `CTextStack *` A pointer to the newly created empty text stack.
- **preconditions:** The `self` pointer must be valid.
- **postconditions:** The text stack is added to the garbage collector.
- **side_effects:** Memory is allocated for the text stack.

### `CTextStack *CwebHttpRequest_create_stack(CwebHttpRequest *self)`
**description:** Creates a new text stack associated with the HTTP request.
- **params:**
    - `CwebHttpRequest *self`: Pointer to the `CwebHttpRequest` object.
- **returns:** `CTextStack *` A pointer to the newly created text stack.
- **preconditions:** The `self` pointer must be valid.
- **postconditions:** The text stack is added to the garbage collector.
- **side_effects:** Memory is allocated for the text stack.

### `void CwebHttpRequest_free(CwebHttpRequest *self)`
**description:** Frees the memory allocated for the HTTP request and its components.
- **params:**
    - `CwebHttpRequest *self`: Pointer to the `CwebHttpRequest` object to free.
- **returns:** None.
- **preconditions:** The `self` pointer must be valid.
- **postconditions:** All memory associated with the `CwebHttpRequest` object is freed.
- **side_effects:** Memory is deallocated.
```
------------------------
### [src/request/request/typesC.request.h](/src/request/request/typesC.request.h):
### `typedef struct CwebHttpRequest`
- **description:** A structure representing an HTTP request in the Cweb framework.
- **fields:**
    - `char *url`: The URL of the request.
    - `int socket`: The socket used for the request.
    - `char *route`: The route part of the URL.
    - `char *method`: The HTTP method used (e.g., GET, POST).
    - `char *client_ip`: The IP address of the client making the request.
    - `int content_error`: Flag indicating if there was an error in the content.
    - `CwebDict *params`: A dictionary of request parameters.
    - `CwebDict *headers`: A dictionary of HTTP headers.
    - `int content_length`: The length of the request content.
    - `unsigned char *content`: The raw content of the request.
    - `cJSON *json`: JSON representation of the request content if applicable.
    - `void *hydratation`: Pointer to hydration data for the request.
    - `void *extra_args`: Pointer to any extra arguments passed with the request.
    - `UniversalGarbage *garbage`: Pointer to a garbage collector for managing memory.
------------------------
### [src/request/request_parser/fdeclare.request_parser.h](/src/request/request_parser/fdeclare.request_parser.h):
```md
### `void private_CwebHttpRequest_interpret_query_params(struct CwebHttpRequest *self, const char *query_params)`
- **params:**
    - `struct CwebHttpRequest *self`: [Pointer to the CwebHttpRequest object]
    - `const char *query_params`: [Pointer to the query parameters string]
- **returns:** `void` [No return value, modifies the object]

### `void CwebHttpRequest_set_url(struct CwebHttpRequest *self, const char *url)`
- **params:**
    - `struct CwebHttpRequest *self`: [Pointer to the CwebHttpRequest object]
    - `const char *url`: [Pointer to the URL string]
- **returns:** `void` [No return value, modifies the object]

### `int private_CwebHttpRequest_interpret_first_line(struct CwebHttpRequest *self, char *first_line)`
- **params:**
    - `struct CwebHttpRequest *self`: [Pointer to the CwebHttpRequest object]
    - `char *first_line`: [Pointer to the first line of the HTTP request]
- **returns:** `int` [Status code indicating success or failure]

### `int private_CwebHttpRequest_interpret_headders(struct CwebHttpRequest *self, struct CwebStringArray *line_headers)`
- **params:**
    - `struct CwebHttpRequest *self`: [Pointer to the CwebHttpRequest object]
    - `struct CwebStringArray *line_headers`: [Pointer to an array of header lines]
- **returns:** `int` [Status code indicating success or failure]

### `int CwebHttpRequest_parse_http_request(struct CwebHttpRequest *self)`
- **params:**
    - `struct CwebHttpRequest *self`: [Pointer to the CwebHttpRequest object]
- **returns:** `int` [Status code indicating success or failure of parsing the HTTP request]
```
------------------------
### [src/request/request_parser/fdefine.request_parser.c](/src/request/request_parser/fdefine.request_parser.c):
```md
### `void private_CwebHttpRequest_interpret_query_params(struct CwebHttpRequest *self, const char *query_params)`
**description:** Interprets the query parameters from a URL string and sets them in the `CwebHttpRequest` object's `params` dictionary.
- **params:**
    - `struct CwebHttpRequest *self`: Pointer to the `CwebHttpRequest` object where the query parameters will be stored.
    - `const char *query_params`: The query parameters string to be interpreted.
- **returns:** `void` Does not return a value.
- **preconditions:** `self` and `query_params` must be valid pointers.
- **postconditions:** The `params` dictionary in `self` will contain the interpreted query parameters.
- **side_effects:** May allocate memory for sanitized keys and values, which is freed before the function exits.

### `void CwebHttpRequest_set_url(struct CwebHttpRequest *self, const char *url)`
**description:** Sets the URL and extracts the route and query parameters from it.
- **params:**
    - `struct CwebHttpRequest *self`: Pointer to the `CwebHttpRequest` object where the URL will be set.
    - `const char *url`: The URL string to be set.
- **returns:** `void` Does not return a value.
- **preconditions:** `self` and `url` must be valid pointers.
- **postconditions:** `self->url` and `self->route` will be set, and query parameters will be interpreted if present.
- **side_effects:** Allocates memory for `self->url` and `self->route`.

### `int private_CwebHttpRequest_interpret_first_line(struct CwebHttpRequest *self, char *first_line)`
**description:** Interprets the first line of an HTTP request to extract the method and URL.
- **params:**
    - `struct CwebHttpRequest *self`: Pointer to the `CwebHttpRequest` object where the method and URL will be set.
    - `char *first_line`: The first line of the HTTP request.
- **returns:** `int` Returns 0 on success, or an error code if the first line is invalid.
- **preconditions:** `self` and `first_line` must be valid pointers.
- **postconditions:** `self->method` and `self->url` will be set if the first line is valid.
- **side_effects:** None.

### `int private_CwebHttpRequest_interpret_headders(struct CwebHttpRequest *self, struct CwebStringArray *line_headers)`
**description:** Interprets the headers of an HTTP request and adds them to the `CwebHttpRequest` object.
- **params:**
    - `struct CwebHttpRequest *self`: Pointer to the `CwebHttpRequest` object where the headers will be added.
    - `struct CwebStringArray *line_headers`: Array of strings containing the headers.
- **returns:** `int` Returns 0 on success, or an error code if headers are invalid or exceed size limits.
- **preconditions:** `self` and `line_headers` must be valid pointers.
- **postconditions:** Headers will be added to `self` if valid.
- **side_effects:** None.

### `bool private_cweb_is_valid_utf8(const unsigned char *data, size_t length)`
**description:** Checks if the given data is valid UTF-8.
- **params:**
    - `const unsigned char *data`: Pointer to the data to check.
    - `size_t length`: Length of the data.
- **returns:** `bool` Returns true if the data is valid UTF-8, false otherwise.
- **preconditions:** `data` must be a valid pointer.
- **postconditions:** None.
- **side_effects:** None.

### `int CwebHttpRequest_parse_http_request(struct CwebHttpRequest *self)`
**description:** Parses an HTTP request from the socket and sets the relevant fields in the `CwebHttpRequest` object.
- **params:**
    - `struct CwebHttpRequest *self`: Pointer to the `CwebHttpRequest` object to be populated.
- **returns:** `int` Returns 0 on success, or an error code if parsing fails.
- **preconditions:** `self` must be a valid pointer, and `self->socket` must be open.
- **postconditions:** `self` will contain the parsed HTTP request data.
- **side_effects:** May allocate memory for various fields in `self`.
```
------------------------
### [src/response/response/fdeclare.response.h](/src/response/response/fdeclare.response.h):
### `struct CwebHttpResponse *newCwebHttpResponse()`
- **params:** None
- **returns:** `struct CwebHttpResponse *` A new instance of CwebHttpResponse

### `char *CwebHttpResponse_generate_response(struct CwebHttpResponse *self)`
- **params:**
    - `struct CwebHttpResponse *self`: Pointer to the CwebHttpResponse instance
- **returns:** `char *` The generated HTTP response as a string

### `void CwebHttpResponse_free(struct CwebHttpResponse *self)`
- **params:**
    - `struct CwebHttpResponse *self`: Pointer to the CwebHttpResponse instance to be freed
- **returns:** None

### `void CwebHttpResponse_set_content(CwebHttpResponse *self, unsigned char *content, int content_length)`
- **params:**
    - `CwebHttpResponse *self`: Pointer to the CwebHttpResponse instance
    - `unsigned char *content`: The content to set in the response
    - `int content_length`: The length of the content
- **returns:** None

### `void CwebHttpResponse_add_header(CwebHttpResponse *self, const char *key, const char *value)`
- **params:**
    - `CwebHttpResponse *self`: Pointer to the CwebHttpResponse instance
    - `const char *key`: The header key to add
    - `const char *value`: The header value to add
- **returns:** None
------------------------
### [src/response/response/fdefine.response.c](/src/response/response/fdefine.response.c):
### `CwebHttpResponse *newCwebHttpResponse()`
**description:** Creates a new instance of `CwebHttpResponse`.
- **returns:** `CwebHttpResponse*` A pointer to the newly created `CwebHttpResponse` object.
- **postconditions:** The returned `CwebHttpResponse` object has a status code of 200, an empty headers dictionary, content length set to 0, and no content.
- **side_effects:** Allocates memory for the `CwebHttpResponse` object.

### `char *CwebHttpResponse_generate_response(struct CwebHttpResponse*self)`
**description:** Generates the HTTP response string based on the current state of the `CwebHttpResponse` object.
- **params:**
    - `struct CwebHttpResponse* self`: Pointer to the `CwebHttpResponse` object.
- **returns:** `char*` A string containing the HTTP response.
- **side_effects:** Allocates memory for the response string.

### `void CwebHttpResponse_free(struct CwebHttpResponse *self)`
**description:** Frees the memory allocated for the `CwebHttpResponse` object.
- **params:**
    - `struct CwebHttpResponse *self`: Pointer to the `CwebHttpResponse` object to be freed.
- **side_effects:** Deallocates memory for the `CwebHttpResponse` object and its components.

### `void CwebHttpResponse_set_content(struct CwebHttpResponse *self, unsigned char *content, int content_length)`
**description:** Sets the content of the `CwebHttpResponse` object.
- **params:**
    - `struct CwebHttpResponse *self`: Pointer to the `CwebHttpResponse` object.
    - `unsigned char *content`: The content to be set.
    - `int content_length`: The length of the content.
- **side_effects:** Allocates memory for the content and updates the object's state.

### `void CwebHttpResponse_add_header(struct CwebHttpResponse *self, const char *key, const char *value)`
**description:** Adds a header to the `CwebHttpResponse` object.
- **params:**
    - `struct CwebHttpResponse *self`: Pointer to the `CwebHttpResponse` object.
    - `const char *key`: The key of the header.
    - `const char *value`: The value of the header.
- **side_effects:** Modifies the headers dictionary of the `CwebHttpResponse` object.
------------------------
### [src/response/response/typesC.response.h](/src/response/response/typesC.response.h):
### `typedef struct CwebHttpResponse`
- **description:** A structure representing an HTTP response in the Cweb framework.
- **original_type:** `struct`
- **fields:**
    - `int status_code`: The HTTP status code of the response.
    - `struct CwebDict *headers`: A dictionary containing the HTTP headers of the response.
    - `int content_length`: The length of the content in bytes.
    - `bool exist_content`: A flag indicating whether content exists in the response.
    - `unsigned char *content`: The actual content of the HTTP response.
------------------------
### [src/response/response_functions/fdeclare.response_functions.h](/src/response/response_functions/fdeclare.response_functions.h):
### `CwebHttpResponse* cweb_send_any(const char *content_type, size_t content_length, unsigned char *content, int status_code)`
- **params:**
    - `const char *content_type`: The MIME type of the content.
    - `size_t content_length`: The length of the content in bytes.
    - `unsigned char *content`: The actual content to be sent.
    - `int status_code`: The HTTP status code to be returned.
- **returns:** `CwebHttpResponse*` A pointer to a `CwebHttpResponse` object containing the response.

### `CwebHttpResponse * cweb_send_json_string(const char *content, int status_code)`
- **params:**
    - `const char *content`: The JSON string to be sent.
    - `int status_code`: The HTTP status code to be returned.
- **returns:** `CwebHttpResponse*` A pointer to a `CwebHttpResponse` object containing the JSON response.

### `CwebHttpResponse * cweb_send_json_string_cleaning_memory(char *content, int status_code)`
- **params:**
    - `char *content`: The JSON string to be sent, which will be freed after use.
    - `int status_code`: The HTTP status code to be returned.
- **returns:** `CwebHttpResponse*` A pointer to a `CwebHttpResponse` object containing the JSON response.

### `CwebHttpResponse * cweb_send_cJSON(cJSON *content, int status_code)`
- **params:**
    - `cJSON *content`: The cJSON object to be sent.
    - `int status_code`: The HTTP status code to be returned.
- **returns:** `CwebHttpResponse*` A pointer to a `CwebHttpResponse` object containing the cJSON response.

### `CwebHttpResponse * cweb_send_cJSON_cleaning_memory(cJSON *content, int status_code)`
- **params:**
    - `cJSON *content`: The cJSON object to be sent, which will be freed after use.
    - `int status_code`: The HTTP status code to be returned.
- **returns:** `CwebHttpResponse*` A pointer to a `CwebHttpResponse` object containing the cJSON response.

### `CwebHttpResponse* cweb_send_any_cleaning_memory(const char *content_type, size_t content_length, unsigned char *content, int status_code)`
- **params:**
    - `const char *content_type`: The MIME type of the content.
    - `size_t content_length`: The length of the content in bytes.
    - `unsigned char *content`: The actual content to be sent, which will be freed after use.
    - `int status_code`: The HTTP status code to be returned.
- **returns:** `CwebHttpResponse*` A pointer to a `CwebHttpResponse` object containing the response.

### `CwebHttpResponse* cweb_send_rendered_CTextStack(struct CTextStack *stack, int status_code)`
- **params:**
    - `struct CTextStack *stack`: The CTextStack object to be rendered and sent.
    - `int status_code`: The HTTP status code to be returned.
- **returns:** `CwebHttpResponse*` A pointer to a `CwebHttpResponse` object containing the rendered response.

### `CwebHttpResponse* cweb_send_text(const char *content, int status_code)`
- **params:**
    - `const char *content`: The text content to be sent.
    - `int status_code`: The HTTP status code to be returned.
- **returns:** `CwebHttpResponse*` A pointer to a `CwebHttpResponse` object containing the text response.

### `CwebHttpResponse* cweb_send_text_cleaning_memory(char *content, int status_code)`
- **params:**
    - `char *content`: The text content to be sent, which will be freed after use.
    - `int status_code`: The HTTP status code to be returned.
- **returns:** `CwebHttpResponse*` A pointer to a `CwebHttpResponse` object containing the text response.

### `CwebHttpResponse* cweb_send_var_html(const char *content, int status_code)`
- **params:**
    - `const char *content`: The HTML content to be sent.
    - `int status_code`: The HTTP status code to be returned.
- **returns:** `CwebHttpResponse*` A pointer to a `CwebHttpResponse` object containing the HTML response.

### `CwebHttpResponse* cweb_send_var_html_cleaning_memory(char *content, int status_code)`
- **params:**
    - `char *content`: The HTML content to be sent, which will be freed after use.
    - `int status_code`: The HTTP status code to be returned.
- **returns:** `CwebHttpResponse*` A pointer to a `CwebHttpResponse` object containing the HTML response.

### `CwebHttpResponse* cweb_send_file(const char *file_path, const char *content_type, int status_code)`
- **params:**
    - `const char *file_path`: The path to the file to be sent.
    - `const char *content_type`: The MIME type of the file.
    - `int status_code`: The HTTP status code to be returned.
- **returns:** `CwebHttpResponse*` A pointer to a `CwebHttpResponse` object containing the file response.
------------------------
### [src/response/response_functions/fdefine.response_functions.c](/src/response/response_functions/fdefine.response_functions.c):
```md
### `CwebHttpResponse* cweb_send_any(const char *content_type, size_t content_length, unsigned char *content, int status_code)`
**description:** Creates and returns a `CwebHttpResponse` object with the specified content type, length, content, and status code.
- **params:**
    - `const char *content_type`: The MIME type of the content.
    - `size_t content_length`: The length of the content in bytes.
    - `unsigned char *content`: The actual content to be sent.
    - `int status_code`: The HTTP status code for the response.
- **returns:** `CwebHttpResponse*` A pointer to the created `CwebHttpResponse` object.
- **side_effects:** Allocates memory for the `CwebHttpResponse` object.

### `CwebHttpResponse * cweb_send_json_string(const char *content, int status_code)`
**description:** Sends a JSON string response with the specified content and status code.
- **params:**
    - `const char *content`: The JSON string to be sent.
    - `int status_code`: The HTTP status code for the response.
- **returns:** `CwebHttpResponse*` A pointer to the created `CwebHttpResponse` object.
- **side_effects:** Allocates memory for the `CwebHttpResponse` object.

### `CwebHttpResponse * cweb_send_json_string_cleaning_memory(char *content, int status_code)`
**description:** Sends a JSON string response and frees the memory of the content after sending.
- **params:**
    - `char *content`: The JSON string to be sent, which will be freed after use.
    - `int status_code`: The HTTP status code for the response.
- **returns:** `CwebHttpResponse*` A pointer to the created `CwebHttpResponse` object.
- **side_effects:** Allocates memory for the `CwebHttpResponse` object and frees the `content` memory.

### `CwebHttpResponse * cweb_send_cJSON(cJSON *content, int status_code)`
**description:** Sends a JSON response using a `cJSON` object, converting it to a string first.
- **params:**
    - `cJSON *content`: The `cJSON` object to be sent.
    - `int status_code`: The HTTP status code for the response.
- **returns:** `CwebHttpResponse*` A pointer to the created `CwebHttpResponse` object.
- **side_effects:** Allocates memory for the `CwebHttpResponse` object and for the rendered JSON string, which is freed after use.

### `CwebHttpResponse * cweb_send_cJSON_cleaning_memory(cJSON *content, int status_code)`
**description:** Sends a JSON response using a `cJSON` object and frees the `cJSON` object after sending.
- **params:**
    - `cJSON *content`: The `cJSON` object to be sent, which will be freed after use.
    - `int status_code`: The HTTP status code for the response.
- **returns:** `CwebHttpResponse*` A pointer to the created `CwebHttpResponse` object.
- **side_effects:** Allocates memory for the `CwebHttpResponse` object, renders the JSON string, frees the rendered string, and frees the `cJSON` object.

### `CwebHttpResponse* cweb_send_any_cleaning_memory(const char *content_type, size_t content_length, unsigned char *content, int status_code)`
**description:** Creates and returns a `CwebHttpResponse` object with the specified content type, length, content, and status code, then frees the content memory.
- **params:**
    - `const char *content_type`: The MIME type of the content.
    - `size_t content_length`: The length of the content in bytes.
    - `unsigned char *content`: The actual content to be sent, which will be freed after use.
    - `int status_code`: The HTTP status code for the response.
- **returns:** `CwebHttpResponse*` A pointer to the created `CwebHttpResponse` object.
- **side_effects:** Allocates memory for the `CwebHttpResponse` object and frees the `content` memory.

### `CwebHttpResponse* cweb_send_rendered_CTextStack(struct CTextStack *stack, int status_code)`
**description:** Sends the rendered text from a `CTextStack` object as an HTML response.
- **params:**
    - `struct CTextStack *stack`: The `CTextStack` object containing the text to be sent.
    - `int status_code`: The HTTP status code for the response.
- **returns:** `CwebHttpResponse*` A pointer to the created `CwebHttpResponse` object.
- **side_effects:** Allocates memory for the `CwebHttpResponse` object.

### `CwebHttpResponse* cweb_send_text(const char *content, int status_code)`
**description:** Sends a plain text response with the specified content and status code.
- **params:**
    - `const char *content`: The text to be sent.
    - `int status_code`: The HTTP status code for the response.
- **returns:** `CwebHttpResponse*` A pointer to the created `CwebHttpResponse` object.
- **side_effects:** Allocates memory for the `CwebHttpResponse` object.

### `CwebHttpResponse* cweb_send_text_cleaning_memory(char *content, int status_code)`
**description:** Sends a plain text response and frees the memory of the content after sending.
- **params:**
    - `char *content`: The text to be sent, which will be freed after use.
    - `int status_code`: The HTTP status code for the response.
- **returns:** `CwebHttpResponse*` A pointer to the created `CwebHttpResponse` object.
- **side_effects:** Allocates memory for the `CwebHttpResponse` object and frees the `content` memory.

### `CwebHttpResponse* cweb_send_var_html(const char *content, int status_code)`
**description:** Sends an HTML response with the specified content and status code.
- **params:**
    - `const char *content`: The HTML content to be sent.
    - `int status_code`: The HTTP status code for the response.
- **returns:** `CwebHttpResponse*` A pointer to the created `CwebHttpResponse` object.
- **side_effects:** Allocates memory for the `CwebHttpResponse` object.

### `CwebHttpResponse* cweb_send_var_html_cleaning_memory(char *content, int status_code)`
**description:** Sends an HTML response and frees the memory of the content after sending.
- **params:**
    - `char *content`: The HTML content to be sent, which will be freed after use.
    - `int status_code`: The HTTP status code for the response.
- **returns:** `CwebHttpResponse*` A pointer to the created `CwebHttpResponse` object.
- **side_effects:** Allocates memory for the `CwebHttpResponse` object and frees the `content` memory.

### `CwebHttpResponse* cweb_send_file(const char *file_path, const char *content_type, int status_code)`
**description:** Sends the content of a file as a response, with the specified content type and status code.
- **params:**
    - `const char *file_path`: The path to the file to be sent.
    - `const char *content_type`: The MIME type of the file, or NULL to auto-detect.
    - `int status_code`: The HTTP status code for the response.
- **returns:** `CwebHttpResponse*` A pointer to the created `CwebHttpResponse` object.
- **side_effects:** Allocates memory for the `CwebHttpResponse` object, reads the file content, and frees the file content memory. If the file is not found, it may attempt to send a 404 page or a custom message.
```
------------------------
### [src/server/globals.server.c](/src/server/globals.server.c):
### `static long long cweb_actual_request`
- **description:** Tracks the number of actual requests processed by the server.
- **type:** `long long`
- **initial_value:** `0`
- **usage:** Used to monitor the server's load and performance.

### `static long cweb_total_requests`
- **description:** Counts the total number of requests received by the server.
- **type:** `long`
- **initial_value:** `0`
- **usage:** Useful for statistics and logging purposes.

### `static bool private_cweb_end_server`
- **description:** Flag to indicate if the server should be shut down.
- **type:** `bool`
- **initial_value:** `false`
- **usage:** Used to control the server's lifecycle.

### `static const char* cweb_static_folder`
- **description:** Pointer to the path of the static folder used by the server.
- **type:** `const char*`
- **usage:** Specifies the directory where static files are served from.
------------------------
### [src/server/server/constructors/fdeclare.constructors.h](/src/server/server/constructors/fdeclare.constructors.h):
### `struct CwebServer newCwebSever(int port, CwebHttpResponse *(*request_handler)(CwebHttpRequest *request))`
- **params:**
    - `int port`: The port number on which the server will listen.
    - `CwebHttpResponse *(*request_handler)(CwebHttpRequest *request)`: A function pointer to the handler that processes incoming requests and returns a response.
- **returns:** `struct CwebServer` The newly created CwebServer instance.

### `int CwebServer_start(CwebServer *self)`
- **params:**
    - `CwebServer *self`: Pointer to the CwebServer instance to start.
- **returns:** `int` An integer indicating the success or failure of starting the server.
------------------------
### [src/server/server/constructors/fdefine.constructors.c](/src/server/server/constructors/fdefine.constructors.c):
### `CwebServer newCwebServer(int port, CwebHttpResponse *(*request_handler)(CwebHttpRequest *request))`
**description:** Initializes and returns a new CwebServer instance with specified port and request handler.
- **params:**
    - `int port`: The port number on which the server will listen.
    - `CwebHttpResponse *(*request_handler)(CwebHttpRequest *request)`: A function pointer to handle incoming requests, returning a response.
- **returns:** `CwebServer` A structure representing the initialized server.
- **preconditions:** The port must be available and valid.
- **postconditions:** The server is configured with default settings and ready to start.
- **side_effects:** Sets global variables and default server configurations.

### `int CwebServer_start(CwebServer *self)`
**description:** Starts the CwebServer based on the operating system.
- **params:**
    - `CwebServer *self`: Pointer to the CwebServer instance to start.
- **returns:** `int` Status code indicating success or failure of starting the server.
- **preconditions:** The CwebServer instance must be properly initialized.
- **postconditions:** The server is running and ready to accept connections.
- **side_effects:** Sets the static folder globally and may spawn multiple processes on Linux.
------------------------
### [src/server/server/multi_process/fdeclare.multi_process.h](/src/server/server/multi_process/fdeclare.multi_process.h):
### `void private_cweb_execute_request_in_safty_mode(CwebServer *self, int new_socket, const char *client_ip)`
- **params:**
    - `CwebServer *self`: [Pointer to the CwebServer instance]
    - `int new_socket`: [The new socket for the client connection]
    - `const char *client_ip`: [The IP address of the client]
- **returns:** `void` [No return value]

### `int private_CWebServer_run_server_in_multiprocess(CwebServer *self)`
- **params:**
    - `CwebServer *self`: [Pointer to the CwebServer instance]
- **returns:** `int` [Return value indicating success or failure of the server operation]
------------------------
### [src/server/server/multi_process/fdefine.multi_process.c](/src/server/server/multi_process/fdefine.multi_process.c):
```md
### `void private_cweb_execute_request_in_safty_mode(CwebServer *self, int new_socket, const char *client_ip)`
**description:** Executes a request in a safety mode by creating a new process to handle the request, ensuring that the main server process remains stable.
- **params:**
    - `CwebServer *self`: Pointer to the CwebServer instance managing the request.
    - `int new_socket`: The socket descriptor for the new connection.
    - `const char *client_ip`: The IP address of the client making the request.
- **returns:** `void` Does not return a value, as it uses fork to create a new process.
- **preconditions:** The `CwebServer` instance must be initialized and the `new_socket` must be valid.
- **postconditions:** The request is executed in a new process, and the original process continues to listen for new connections.
- **side_effects:** Creates a new process, potentially modifies global state related to request handling, and may perform I/O operations.

### `int private_CWebServer_run_server_in_multiprocess(CwebServer *self)`
**description:** Runs the CwebServer in a multi-process mode, handling multiple client connections concurrently.
- **params:**
    - `CwebServer *self`: Pointer to the CwebServer instance to run.
- **returns:** `int` Returns 0 on successful execution, non-zero otherwise.
- **preconditions:** The `CwebServer` instance must be initialized with necessary configurations.
- **postconditions:** The server continues to run and accept new connections until manually stopped or an error occurs.
- **side_effects:** Creates multiple processes, potentially modifies global state related to server operations, and performs I/O operations.
```
------------------------
### [src/server/server/request_execution/fdeclare.request_execution.h](/src/server/server/request_execution/fdeclare.request_execution.h):
### `void private_CWebServer_execute_request(CwebServer *self, int socket, const char *client_ip)`
- **params:**
    - `CwebServer *self`: [Pointer to the CwebServer instance]
    - `int socket`: [The socket file descriptor for the client connection]
    - `const char *client_ip`: [The IP address of the client]
- **returns:** `void` [This function does not return a value]
------------------------
### [src/server/server/request_execution/fdefine.request_execution.c](/src/server/server/request_execution/fdefine.request_execution.c):
### `void private_CWebServer_execute_request(CwebServer *self, int socket, const char *client_ip)`
**description:** Executes a web server request by parsing the HTTP request, generating a response, and sending it back to the client.
- **params:**
    - `CwebServer *self`: Pointer to the CwebServer instance handling the request.
    - `int socket`: The socket file descriptor used for communication with the client.
    - `const char *client_ip`: The IP address of the client making the request.
- **returns:** `void` No return value, the function performs operations and sends responses directly.
- **preconditions:** The socket must be valid and connected, and the CwebServer instance must be initialized.
- **postconditions:** The request is processed, and a response is sent back to the client through the socket.
- **side_effects:** Memory allocation and deallocation occur, and data is sent over the network.
------------------------
### [src/server/server/single_process/fdeclare.single_process.h](/src/server/server/single_process/fdeclare.single_process.h):
### `int private_CWebServer_run_server_in_single_process(CwebServer *self)`
- **params:**
    - `CwebServer* self`: [Pointer to the CwebServer instance]
- **returns:** `int` [Return value indicating success or failure of the server operation]
------------------------
### [src/server/server/single_process/fdefine.single_process.c](/src/server/server/single_process/fdefine.single_process.c):
### `int private_CWebServer_run_server_in_single_process(CwebServer *self)`
**description:** Runs the web server in a single process, handling all requests sequentially.
- **params:**
    - `CwebServer *self`: Pointer to the CwebServer instance that contains server configuration.
- **returns:** `int` Returns 0 on successful execution, 1 if an error occurs during server operation.
- **preconditions:** The CwebServer instance must be properly initialized with port and max_queue set.
- **postconditions:** The server will run until manually stopped or an error occurs.
- **side_effects:** This function will start listening on the specified port, accept client connections, and process requests. It may also print to stderr or stdout for logging purposes.
------------------------
### [src/server/server_functions/fdeclare.server_functions.h](/src/server/server_functions/fdeclare.server_functions.h):
### `void private_cweb_send_error_mensage(CwebHttpResponse *response, int socket)`
- **params:**
    - `CwebHttpResponse *response`: [Pointer to the HTTP response object]
    - `int socket`: [Socket file descriptor for sending the error message]
- **returns:** `void` [No return value]

### `void cweb_kill_single_process_server()`
- **params:**
- **returns:** `void` [No return value]

### `void cweb_set_static_folder(const char *folder)`
- **params:**
    - `const char *folder`: [Pointer to a string containing the path to the static folder]
- **returns:** `void` [No return value]

### `const char * cweb_get_static_folder()`
- **params:**
- **returns:** `const char *` [Pointer to a string containing the path to the static folder]

### `long cweb_get_total_requests()`
- **params:**
- **returns:** `long` [Total number of requests processed]

### `void private_cweb_treat_response(bool use_static, int new_socket)`
- **params:**
    - `bool use_static`: [Flag to indicate whether to use static content]
    - `int new_socket`: [New socket file descriptor for handling the response]
- **returns:** `void` [No return value]

### `void private_cweb_handle_child_termination(int signal)`
- **params:**
    - `int signal`: [Signal number received for child process termination]
- **returns:** `void` [No return value]
------------------------
### [src/server/server_functions/fdefine.server_functions.c](/src/server/server_functions/fdefine.server_functions.c):
```md
### `void private_cweb_treat_response(bool use_static, int new_socket)`
**description:** Handles the response for a new request, managing child processes and error responses.
- **params:**
    - `bool use_static`: Indicates whether to use static content for error responses.
    - `int new_socket`: The socket used for sending the response.
- **returns:** `void` Does not return a value.
- **preconditions:** A new request has been received and a child process is expected to be running.
- **postconditions:** The response is sent, and any child process errors are handled.
- **side_effects:** May fork new processes, use I/O operations, and modify global state.

### `void private_cweb_handle_child_termination(int signal)`
**description:** Manages the termination of child processes, updating the total number of requests.
- **params:**
    - `int signal`: The signal received indicating child process termination.
- **returns:** `void` Does not return a value.
- **preconditions:** A signal indicating child process termination has been received.
- **postconditions:** The total number of requests is updated.
- **side_effects:** May modify global state.

### `void private_cweb_send_error_mensage(CwebHttpResponse *response, int socket)`
**description:** Sends an error message over the specified socket.
- **params:**
    - `CwebHttpResponse *response`: The HTTP response containing the error message.
    - `int socket`: The socket to send the error message through.
- **returns:** `void` Does not return a value.
- **preconditions:** An error response has been prepared.
- **postconditions:** The error message is sent over the socket.
- **side_effects:** Performs I/O operations, frees memory.

### `void cweb_kill_single_process_server()`
**description:** Signals the server to stop running.
- **params:** None
- **returns:** `void` Does not return a value.
- **preconditions:** The server is running.
- **postconditions:** The server is signaled to stop.
- **side_effects:** Modifies global state.

### `void cweb_set_static_folder(const char *folder)`
**description:** Sets the static folder path for serving static content.
- **params:**
    - `const char *folder`: The path to the static folder.
- **returns:** `void` Does not return a value.
- **preconditions:** The folder path is valid.
- **postconditions:** The static folder path is set.
- **side_effects:** Modifies global state.

### `const char * cweb_get_static_folder()`
**description:** Retrieves the current static folder path.
- **params:** None
- **returns:** `const char *` The path to the static folder.
- **preconditions:** The static folder has been set.
- **postconditions:** None
- **side_effects:** None

### `long cweb_get_total_requests()`
**description:** Returns the total number of requests handled by the server.
- **params:** None
- **returns:** `long` The total number of requests.
- **preconditions:** None
- **postconditions:** None
- **side_effects:** None
```
------------------------
### [src/server/server_functions/globals.not_found.c](/src/server/server_functions/globals.not_found.c):
### `unsigned char private_cweb_404[]`
- **description:** Array containing HTML content for a 404 error page in Portuguese.
- **type:** `unsigned char[]`
- **initial_value:** Array of bytes representing HTML content.
- **usage:** Used to serve a custom 404 error page when a requested resource is not found.

### `unsigned char private_cweb_500[]`
- **description:** Array containing HTML content for a 500 error page in Portuguese.
- **type:** `unsigned char[]`
- **initial_value:** Array of bytes representing HTML content.
- **usage:** Used to serve a custom 500 error page when an internal server error occurs.
------------------------
### [src/server/typesD.server.h](/src/server/typesD.server.h):
### `typedef struct CwebServer`
- **description:** The CwebServer struct represents the configuration and state of a web server.
- **fields:**
    - `int port`: The port number on which the server listens for incoming connections.
    - `int function_timeout`: The timeout in seconds for server functions to complete.
    - `double client_timeout`: The timeout in seconds for client connections.
    - `int max_queue`: The maximum number of pending connections the server can handle.
    - `bool single_process`: (Linux only) Whether the server runs in a single process mode.
    - `long max_requests`: The maximum number of requests the server can handle before shutting down.
    - `bool allow_cors`: Whether the server allows Cross-Origin Resource Sharing.
    - `bool use_static`: Whether the server serves static files.
    - `const char *static_folder`: The directory path where static files are located.
    - `bool use_cache`: Whether the server uses caching for responses.
    - `CwebHttpResponse *(*request_handler)(CwebHttpRequest *request)`: A pointer to a function that handles incoming HTTP requests and returns an HTTP response.
------------------------
### [src/static/inline_inclusion/inline_inclusion/fdeclare.inline_inclusion.h](/src/static/inline_inclusion/inline_inclusion/fdeclare.inline_inclusion.h):
### `void private_cweb_load_file_and_include(CTextStack *code, CTextStack *src, privateCwebRecursionList *recursion_listage)`
- **params:**
    - `CTextStack *code`: [The stack where the code will be loaded into]
    - `CTextStack *src`: [The source stack from which the file content is read]
    - `privateCwebRecursionList *recursion_listage`: [A list to manage recursion in file inclusion]
- **returns:** `void` [No return value, modifies the `code` stack]

### `void private_cweb_generate_inline_inclusion(CTextStack *code, const char *content, long content_size, privateCwebRecursionList *recursion_listage, const char *filename)`
- **params:**
    - `CTextStack *code`: [The stack where the inline inclusion will be generated]
    - `const char *content`: [The content to be included inline]
    - `long content_size`: [The size of the content to be included]
    - `privateCwebRecursionList *recursion_listage`: [A list to manage recursion in file inclusion]
    - `const char *filename`: [The name of the file from which the content is sourced]
- **returns:** `void` [No return value, modifies the `code` stack]
------------------------
### [src/static/inline_inclusion/inline_inclusion/fdefine.inline_inclusion.c](/src/static/inline_inclusion/inline_inclusion/fdefine.inline_inclusion.c):
### `void private_cweb_load_file_and_include(CTextStack *code, CTextStack *src, privateCwebRecursionList *recursion_listage)`
**description:** Loads and includes the content of a file into the provided `code` stack, handling recursion to prevent circular dependencies.
- **params:**
    - `CTextStack *code`: The stack where the content will be included.
    - `CTextStack *src`: The source file name to be loaded.
    - `privateCwebRecursionList *recursion_listage`: A list to track recursive file inclusions.
- **returns:** `void`
- **preconditions:** The `src` stack should contain a valid file path.
- **postconditions:** The `code` stack will contain the content of the file, or an error message if the file could not be loaded or if there was a recursion collision.
- **side_effects:** May allocate memory for file content and free it after use.

### `void private_cweb_generate_inline_inclusion(CTextStack *code, const char *content, long content_size, privateCwebRecursionList *recursion_listage, const char *filename)`
**description:** Generates inline inclusions from the given content, handling recursive file inclusions.
- **params:**
    - `CTextStack *code`: The stack where the processed content will be added.
    - `const char *content`: The content to process for inline inclusions.
    - `long content_size`: The size of the content.
    - `privateCwebRecursionList *recursion_listage`: A list to track recursive file inclusions.
    - `const char *filename`: The name of the file being processed, used for recursion tracking.
- **returns:** `void`
- **preconditions:** The `content` should be a valid string, and `content_size` should match the length of `content`.
- **postconditions:** The `code` stack will contain the processed content with inline inclusions resolved, or error messages if there were issues with recursion or file loading.
- **side_effects:** May allocate memory for processing and free it after use.
------------------------
### [src/static/inline_inclusion/recursion_protection/recursion_element/fdeclare.recursion_element.h](/src/static/inline_inclusion/recursion_protection/recursion_element/fdeclare.recursion_element.h):
### `privateCwebRecursionElement * newPrivateCwebRecursionElement(const char *file, const char *included)`
- **params:**
    - `const char *file`: [The file name where the recursion element is defined]
    - `const char *included`: [The file name that is included in the recursion]
- **returns:** `privateCwebRecursionElement *` [A pointer to a newly created privateCwebRecursionElement]

### `void PrivateCwebRecursionElement_represent(privateCwebRecursionElement *self)`
- **params:**
    - `privateCwebRecursionElement *self`: [A pointer to the privateCwebRecursionElement to be represented]
- **returns:** `void` [This function does not return a value]

### `void PrivateCwebRecursionElement_free(privateCwebRecursionElement *self)`
- **params:**
    - `privateCwebRecursionElement *self`: [A pointer to the privateCwebRecursionElement to be freed]
- **returns:** `void` [This function does not return a value]
------------------------
### [src/static/inline_inclusion/recursion_protection/recursion_element/fdefine.recursion_element.c](/src/static/inline_inclusion/recursion_protection/recursion_element/fdefine.recursion_element.c):
### `privateCwebRecursionElement * newPrivateCwebRecursionElement(const char *file, const char *included)`
**description:** Allocates and initializes a new `privateCwebRecursionElement` with the provided file and included paths.
- **params:**
    - `const char *file`: The path of the file being processed.
    - `const char *included`: The path of the included file.
- **returns:** `privateCwebRecursionElement *` A pointer to the newly created `privateCwebRecursionElement`.
- **preconditions:** The input strings `file` and `included` must be valid and non-null.
- **postconditions:** A new `privateCwebRecursionElement` is allocated and initialized with the provided paths.
- **side_effects:** Memory allocation occurs, and the function may fail if memory is not available.

### `void PrivateCwebRecursionElement_represent(privateCwebRecursionElement *self)`
**description:** Prints a representation of the `privateCwebRecursionElement` to the standard output.
- **params:**
    - `privateCwebRecursionElement *self`: A pointer to the `privateCwebRecursionElement` to be represented.
- **returns:** `void`
- **preconditions:** `self` must be a valid pointer to an initialized `privateCwebRecursionElement`.
- **postconditions:** The representation of `self` is printed to the standard output.
- **side_effects:** Output to the standard output.

### `void PrivateCwebRecursionElement_free(privateCwebRecursionElement *self)`
**description:** Frees the memory allocated for a `privateCwebRecursionElement`.
- **params:**
    - `privateCwebRecursionElement *self`: A pointer to the `privateCwebRecursionElement` to be freed.
- **returns:** `void`
- **preconditions:** `self` must be a valid pointer to an initialized `privateCwebRecursionElement`.
- **postconditions:** The memory allocated for `self` is freed.
- **side_effects:** Memory deallocation occurs.
------------------------
### [src/static/inline_inclusion/recursion_protection/recursion_element/types.recursion_element.h](/src/static/inline_inclusion/recursion_protection/recursion_element/types.recursion_element.h):
### `typedef struct privateCwebRecursionElement`
- **description:** A structure used for managing recursion in Cweb operations.
- **fields:**
    - `char *file`: A pointer to a string representing the file path involved in the recursion.
    - `char *included`: A pointer to a string indicating whether the file has been included in the recursion process.
------------------------
### [src/static/inline_inclusion/recursion_protection/recursion_list/fdeclare.recursion_list.h](/src/static/inline_inclusion/recursion_protection/recursion_list/fdeclare.recursion_list.h):
### `privateCwebRecursionList * newprivateCwebRecursionList()`
- **params:** None
- **returns:** `privateCwebRecursionList *` [A new instance of privateCwebRecursionList]

### `privateCwebRecursionElement * privateCwebRecursionList_add_if_not_colide(privateCwebRecursionList *self, const char *file, const char *included)`
- **params:**
    - `privateCwebRecursionList *self`: [Pointer to the privateCwebRecursionList instance]
    - `const char *file`: [The file name to be added]
    - `const char *included`: [The included file name to check for collision]
- **returns:** `privateCwebRecursionElement *` [The added element if no collision, otherwise NULL]

### `void privateCwebRecursionList_represent(privateCwebRecursionList *self)`
- **params:**
    - `privateCwebRecursionList *self`: [Pointer to the privateCwebRecursionList instance]
- **returns:** None [Represents the list in some way, likely for debugging or logging]

### `void privateCwebRecursionList_free(privateCwebRecursionList *self)`
- **params:**
    - `privateCwebRecursionList *self`: [Pointer to the privateCwebRecursionList instance to be freed]
- **returns:** None [Frees the memory allocated for the list]
------------------------
### [src/static/inline_inclusion/recursion_protection/recursion_list/fdefine.recursion_list.c](/src/static/inline_inclusion/recursion_protection/recursion_list/fdefine.recursion_list.c):
### `privateCwebRecursionList * newprivateCwebRecursionList()`
**description:** Allocates and initializes a new `privateCwebRecursionList` structure.
- **returns:** `privateCwebRecursionList *` A pointer to the newly allocated and initialized `privateCwebRecursionList`.
- **preconditions:** None
- **postconditions:** The returned list is initialized with zero elements and allocated memory for the list structure and its elements array.
- **side_effects:** Allocates memory on the heap.

### `privateCwebRecursionElement * privateCwebRecursionList_add_if_not_colide(privateCwebRecursionList *self, const char *file, const char *included)`
**description:** Adds a new element to the list if it does not collide with existing elements based on file and included paths.
- **params:**
    - `privateCwebRecursionList *self`: Pointer to the list to which the element might be added.
    - `const char *file`: The file path to be checked for collision.
    - `const char *included`: The included file path to be checked for collision.
- **returns:** `privateCwebRecursionElement *` If a collision is found, returns the colliding element; otherwise, returns `NULL`.
- **preconditions:** `self` must be a valid pointer to an initialized `privateCwebRecursionList`.
- **postconditions:** If no collision, the list size is increased by one, and a new element is added.
- **side_effects:** May allocate memory on the heap if a new element is added.

### `void privateCwebRecursionList_represent(privateCwebRecursionList *self)`
**description:** Represents the contents of the list by calling a representation function on each element.
- **params:**
    - `privateCwebRecursionList *self`: Pointer to the list to be represented.
- **preconditions:** `self` must be a valid pointer to an initialized `privateCwebRecursionList`.
- **postconditions:** The contents of the list are represented through the `PrivateCwebRecursionElement_represent` function.
- **side_effects:** May output to stdout or another stream depending on `PrivateCwebRecursionElement_represent`.

### `void privateCwebRecursionList_free(privateCwebRecursionList *self)`
**description:** Frees the memory allocated for the list and its elements.
- **params:**
    - `privateCwebRecursionList *self`: Pointer to the list to be freed.
- **preconditions:** `self` must be a valid pointer to an initialized `privateCwebRecursionList`.
- **postconditions:** All memory associated with the list and its elements is freed.
- **side_effects:** Deallocates memory on the heap.
------------------------
### [src/static/inline_inclusion/recursion_protection/recursion_list/typesB.recursion_list.h](/src/static/inline_inclusion/recursion_protection/recursion_list/typesB.recursion_list.h):
### `typedef struct privateCwebRecursionList`
- **description:** A structure representing a list used for recursion in Cweb.
- **fields:**
    - `privateCwebRecursionElement **elements`: A pointer to an array of pointers to `privateCwebRecursionElement` structures, which are the elements of the list.
    - `int size`: An integer representing the current size of the list.
------------------------
### [src/static/smart_cache/fdeclare.smart_cache.h](/src/static/smart_cache/fdeclare.smart_cache.h):
### `char * private_cweb_smart_static_ref(CTextStack *src)`
- **params:**
    - `CTextStack *src`: [Pointer to a CTextStack object]
- **returns:** `char *` [A pointer to a static string]

### `char * cweb_smart_static_ref(const char *src)`
- **params:**
    - `const char *src`: [Pointer to a constant character string]
- **returns:** `char *` [A pointer to a static string]

### `CTextStack * private_cweb_change_smart_cache(CTextStack *content)`
- **params:**
    - `CTextStack *content`: [Pointer to a CTextStack object]
- **returns:** `CTextStack *` [A pointer to a modified CTextStack object]
------------------------
### [src/static/smart_cache/fdefine.smart_cache.c](/src/static/smart_cache/fdefine.smart_cache.c):
### `char * private_cweb_smart_static_ref(CTextStack *src)`
**description:** Generates a URL reference for static content with a cache-busting parameter based on the file's last modification time.
- **params:**
    - `CTextStack *src`: Pointer to a CTextStack containing the source path of the static file.
- **returns:** `char *` A dynamically allocated string containing the URL reference.
- **preconditions:** The `src` parameter must point to a valid CTextStack object.
- **postconditions:** The function returns a new string that must be freed by the caller.
- **side_effects:** Allocates memory for the returned string.

### `char * cweb_smart_static_ref(const char *src)`
**description:** Wrapper function that converts a C string to a CTextStack and calls `private_cweb_smart_static_ref`.
- **params:**
    - `const char *src`: A C string representing the source path of the static file.
- **returns:** `char *` A dynamically allocated string containing the URL reference.
- **preconditions:** The `src` parameter must be a valid C string.
- **postconditions:** The function returns a new string that must be freed by the caller.
- **side_effects:** Allocates memory for the returned string and frees the temporary CTextStack.

### `CTextStack * private_cweb_change_smart_cache(CTextStack *content)`
**description:** Processes a CTextStack to replace 'smart-cache' entries with dynamic URL references.
- **params:**
    - `CTextStack *content`: Pointer to a CTextStack containing the content to process.
- **returns:** `CTextStack *` A new CTextStack with processed content.
- **preconditions:** The `content` parameter must point to a valid CTextStack object.
- **postconditions:** Returns a new CTextStack that must be freed by the caller.
- **side_effects:** Allocates memory for the new CTextStack and may allocate memory for intermediate strings.
------------------------
### [src/static/static/fdeclare.static.h](/src/static/static/fdeclare.static.h):
### `CTextStack * private_cweb_format_filename(CTextStack *src)`
- **params:**
    - `CTextStack *src`: [Source CTextStack to be formatted]
- **returns:** `CTextStack *` [Formatted CTextStack]

### `CwebHttpResponse * private_cweb_treat_five_icon()`
- **params:**
    - None
- **returns:** `CwebHttpResponse *` [Response after treating the five icon]

### `char * private_cweb_aply_macro_modifiers_in_content(const char *content, long content_size)`
- **params:**
    - `const char *content`: [Content to apply macro modifiers to]
    - `long content_size`: [Size of the content]
- **returns:** `char *` [Modified content with macro modifiers applied]

### `char * cweb_aply_macro_modifiers_in_content(const char *content)`
- **params:**
    - `const char *content`: [Content to apply macro modifiers to]
- **returns:** `char *` [Modified content with macro modifiers applied]

### `char * cweb_aply_macro_modifiers_in_file(const char *filename)`
- **params:**
    - `const char *filename`: [Filename to apply macro modifiers to]
- **returns:** `char *` [Modified content from file with macro modifiers applied]

### `CwebHttpResponse * private_cweb_generate_static_response(struct CwebHttpRequest *request, bool use_cache)`
- **params:**
    - `struct CwebHttpRequest *request`: [HTTP request to generate a response for]
    - `bool use_cache`: [Whether to use caching for the response]
- **returns:** `CwebHttpResponse *` [Generated static HTTP response]
------------------------
### [src/static/static/fdefine.static.c](/src/static/static/fdefine.static.c):
```md
### `CTextStack * private_cweb_format_filename(CTextStack *src)`
**description:** Formats the filename based on whether it's a full path or not.
- **params:**
    - `CTextStack *src`: The source text stack containing the filename to format.
- **returns:** `CTextStack *` A new text stack with the formatted filename.
- **preconditions:** The `src` parameter must not be NULL.
- **postconditions:** The returned text stack contains the formatted filename.
- **side_effects:** Allocates memory for the new text stack.

### `CwebHttpResponse * private_cweb_treat_five_icon()`
**description:** Attempts to serve a favicon in various formats (ico, png, jpg) from the static folder.
- **returns:** `CwebHttpResponse *` A response with the favicon file if found, otherwise NULL.
- **preconditions:** The static folder path must be set.
- **postconditions:** If a file is found, it returns a response with the file; otherwise, it returns NULL.
- **side_effects:** Opens and closes file handles, may allocate memory for the response.

### `char * private_cweb_aply_macro_modifiers_in_content(const char *content, long content_size)`
**description:** Applies macro modifiers to the given content.
- **params:**
    - `const char *content`: The content to modify.
    - `long content_size`: The size of the content.
- **returns:** `char *` The modified content as a string.
- **preconditions:** The content must not be NULL.
- **postconditions:** The returned string contains the modified content.
- **side_effects:** Allocates memory for the new string, may free intermediate structures.

### `char * cweb_aply_macro_modifiers_in_content(const char *content)`
**description:** Applies macro modifiers to the given content, using the content's length.
- **params:**
    - `const char *content`: The content to modify.
- **returns:** `char *` The modified content as a string.
- **preconditions:** The content must not be NULL.
- **postconditions:** The returned string contains the modified content.
- **side_effects:** Allocates memory for the new string, may free intermediate structures.

### `char * cweb_aply_macro_modifiers_in_file(const char *filename)`
**description:** Applies macro modifiers to the content of a file.
- **params:**
    - `const char *filename`: The name of the file to process.
- **returns:** `char *` The modified content as a string if the file is not binary, otherwise NULL.
- **preconditions:** The filename must not be NULL and the file must exist.
- **postconditions:** If the file is not binary, the returned string contains the modified content.
- **side_effects:** Allocates memory for the new string, may free intermediate structures and the original content.

### `CwebHttpResponse * private_cweb_generate_static_response(struct CwebHttpRequest *request, bool use_cache)`
**description:** Generates a static response for a given request, handling favicon requests and static file serving.
- **params:**
    - `struct CwebHttpRequest *request`: The HTTP request to handle.
    - `bool use_cache`: Whether to use caching for the response.
- **returns:** `CwebHttpResponse *` A response with the static content or an error message.
- **preconditions:** The request must not be NULL.
- **postconditions:** Returns a response with the appropriate content or error message.
- **side_effects:** May open and close files, allocate memory for responses, and set cache headers.
```
------------------------
### [src/string_array/fdeclare.string_array.h](/src/string_array/fdeclare.string_array.h):
```md
### `CwebStringArray * newCwebStringArray()`
- **params:** None
- **returns:** `CwebStringArray *` A new instance of CwebStringArray

### `int CwebStringArray_find(struct CwebStringArray *self, const char *string)`
- **params:**
    - `struct CwebStringArray *self`: The instance of CwebStringArray to search in
    - `const char *string`: The string to find
- **returns:** `int` The index of the found string, or -1 if not found

### `void CwebStringArray_add(struct CwebStringArray *self, const char *string)`
- **params:**
    - `struct CwebStringArray *self`: The instance of CwebStringArray to add to
    - `const char *string`: The string to add
- **returns:** None

### `void CwebStringArray_add_getting_ownership(struct CwebStringArray *self, char *string)`
- **params:**
    - `struct CwebStringArray *self`: The instance of CwebStringArray to add to
    - `char *string`: The string to add, ownership is transferred
- **returns:** None

### `void CwebStringArray_merge(struct CwebStringArray *self, struct CwebStringArray *other)`
- **params:**
    - `struct CwebStringArray *self`: The instance of CwebStringArray to merge into
    - `struct CwebStringArray *other`: The instance of CwebStringArray to merge from
- **returns:** None

### `void CwebStringArray_represent(struct CwebStringArray *self)`
- **params:**
    - `struct CwebStringArray *self`: The instance of CwebStringArray to represent
- **returns:** None

### `void CwebStringArray_free(struct CwebStringArray *self)`
- **params:**
    - `struct CwebStringArray *self`: The instance of CwebStringArray to free
- **returns:** None

### `void CwebStringArray_set(struct CwebStringArray *self, int index, const char *value)`
- **params:**
    - `struct CwebStringArray *self`: The instance of CwebStringArray to set
    - `int index`: The index to set
    - `const char *value`: The value to set at the index
- **returns:** None
```
------------------------
### [src/string_array/fdefine.string_array.c](/src/string_array/fdefine.string_array.c):
```md
### `struct CwebStringArray * newCwebStringArray()`
**description:** Allocates and initializes a new `CwebStringArray` structure.
- **returns:** `struct CwebStringArray *` A pointer to the newly created `CwebStringArray`.
- **preconditions:** None.
- **postconditions:** The returned `CwebStringArray` has `size` set to 0 and `strings` initialized to an array of size 1.
- **side_effects:** Allocates memory for the structure and its `strings` array.

### `int CwebStringArray_find(struct CwebStringArray *self, const char *string)`
**description:** Searches for a given string within the `CwebStringArray`.
- **params:**
    - `struct CwebStringArray *self`: The `CwebStringArray` to search in.
    - `const char *string`: The string to search for.
- **returns:** `int` The index of the found string, or -1 if not found.
- **preconditions:** `self` must be a valid `CwebStringArray` pointer.
- **postconditions:** None.
- **side_effects:** None.

### `void CwebStringArray_set(struct CwebStringArray *self, int index, const char *value)`
**description:** Sets the value of a string at a given index in the `CwebStringArray`.
- **params:**
    - `struct CwebStringArray *self`: The `CwebStringArray` to modify.
    - `int index`: The index at which to set the string.
    - `const char *value`: The new string value to set.
- **preconditions:** `self` must be a valid `CwebStringArray` pointer, `index` must be within the bounds of the array.
- **postconditions:** The string at `index` is updated to `value`.
- **side_effects:** May reallocate memory for the string at `index`.

### `void CwebStringArray_add(struct CwebStringArray *self, const char *string)`
**description:** Adds a new string to the end of the `CwebStringArray`.
- **params:**
    - `struct CwebStringArray *self`: The `CwebStringArray` to add to.
    - `const char *string`: The string to add.
- **preconditions:** `self` must be a valid `CwebStringArray` pointer.
- **postconditions:** The `size` of `self` is incremented by 1, and the new string is added to the end of `strings`.
- **side_effects:** Reallocates memory for `strings` to accommodate the new string.

### `void CwebStringArray_add_getting_ownership(struct CwebStringArray *self, char *string)`
**description:** Adds a new string to the end of the `CwebStringArray`, taking ownership of the string.
- **params:**
    - `struct CwebStringArray *self`: The `CwebStringArray` to add to.
    - `char *string`: The string to add, ownership is transferred to the array.
- **preconditions:** `self` must be a valid `CwebStringArray` pointer, `string` must be a valid pointer.
- **postconditions:** The `size` of `self` is incremented by 1, and the new string is added to the end of `strings`.
- **side_effects:** Reallocates memory for `strings` to accommodate the new string, takes ownership of `string`.

### `void CwebStringArray_merge(struct CwebStringArray *self, struct CwebStringArray *other)`
**description:** Merges another `CwebStringArray` into the current one.
- **params:**
    - `struct CwebStringArray *self`: The `CwebStringArray` to merge into.
    - `struct CwebStringArray *other`: The `CwebStringArray` to merge from.
- **preconditions:** Both `self` and `other` must be valid `CwebStringArray` pointers.
- **postconditions:** All strings from `other` are added to `self`.
- **side_effects:** May reallocate memory for `strings` in `self` to accommodate the new strings.

### `void CwebStringArray_represent(struct CwebStringArray *self)`
**description:** Prints all strings in the `CwebStringArray` to stdout.
- **params:**
    - `struct CwebStringArray *self`: The `CwebStringArray` to represent.
- **preconditions:** `self` must be a valid `CwebStringArray` pointer.
- **postconditions:** None.
- **side_effects:** Outputs to stdout.

### `void CwebStringArray_free(struct CwebStringArray *self)`
**description:** Frees all memory associated with the `CwebStringArray`.
- **params:**
    - `struct CwebStringArray *self`: The `CwebStringArray` to free.
- **preconditions:** `self` must be a valid `CwebStringArray` pointer.
- **postconditions:** All memory allocated for `self` is freed.
- **side_effects:** Frees memory.
```
------------------------
### [src/string_array/types.string_array.h](/src/string_array/types.string_array.h):
### `typedef struct CwebStringArray`
- **description:** A structure representing an array of strings.
- **original_type:** `struct CwebStringArray`
- **fields:**
    - `int size`: The number of strings in the array.
    - `char **strings`: A pointer to an array of strings.
------------------------
### [src/strings/fdeclare.strings.h](/src/strings/fdeclare.strings.h):
### `char *cweb_parse_string_to_lower(const char *old_string)`
- **params:**
    - `const char *old_string`: [The input string to be converted to lowercase]
- **returns:** `char *` [A new string with all characters converted to lowercase]

### `char *cweb_parse_string_to_upper(const char *old_string)`
- **params:**
    - `const char *old_string`: [The input string to be converted to uppercase]
- **returns:** `char *` [A new string with all characters converted to uppercase]

### `char *cweb_normalize_string(const char *old_string, const char *invalid_chars)`
- **params:**
    - `const char *old_string`: [The input string to be normalized]
    - `const char *invalid_chars`: [A string containing characters to be removed or replaced during normalization]
- **returns:** `char *` [A new string with specified characters normalized]

### `bool cweb_starts_with(const char *string, const char *prefix)`
- **params:**
    - `const char *string`: [The string to check]
    - `const char *prefix`: [The prefix to look for at the start of the string]
- **returns:** `bool` [True if the string starts with the prefix, false otherwise]

### `char *cweb_replace_string_once(const char *target, const char *old_element, const char *new_element)`
- **params:**
    - `const char *target`: [The string in which to perform the replacement]
    - `const char *old_element`: [The substring to be replaced]
    - `const char *new_element`: [The substring to replace with]
- **returns:** `char *` [A new string with the first occurrence of `old_element` replaced by `new_element`]

### `char *cweb_replace_string(const char *target, const char *old_element, const char *new_element)`
- **params:**
    - `const char *target`: [The string in which to perform the replacement]
    - `const char *old_element`: [The substring to be replaced]
    - `const char *new_element`: [The substring to replace with]
- **returns:** `char *` [A new string with all occurrences of `old_element` replaced by `new_element`]
------------------------
### [src/strings/fdefine.strings.c](/src/strings/fdefine.strings.c):
```md
### `char *cweb_parse_string_to_lower(const char *old_string)`
**description:** Converts the input string to lowercase.
- **params:**
    - `const char *old_string`: The input string to be converted to lowercase.
- **returns:** `char *` A newly allocated string with all characters in lowercase.
- **preconditions:** `old_string` must be a null-terminated string.
- **postconditions:** The returned string is in lowercase and null-terminated.
- **side_effects:** Allocates memory which must be freed by the caller.

### `char *cweb_parse_string_to_upper(const char *old_string)`
**description:** Converts the input string to uppercase.
- **params:**
    - `const char *old_string`: The input string to be converted to uppercase.
- **returns:** `char *` A newly allocated string with all characters in uppercase.
- **preconditions:** `old_string` must be a null-terminated string.
- **postconditions:** The returned string is in uppercase and null-terminated.
- **side_effects:** Allocates memory which must be freed by the caller.

### `char *cweb_normalize_string(const char *old_string, const char *invalid_chars)`
**description:** Normalizes the input string by converting it to lowercase and removing specified invalid characters.
- **params:**
    - `const char *old_string`: The input string to be normalized.
    - `const char *invalid_chars`: A string containing characters to be removed from the normalized string.
- **returns:** `char *` A newly allocated string that is normalized.
- **preconditions:** Both `old_string` and `invalid_chars` must be null-terminated strings.
- **postconditions:** The returned string is in lowercase, contains no characters from `invalid_chars`, and is null-terminated.
- **side_effects:** Allocates memory which must be freed by the caller, and frees the intermediate lowercase string.

### `bool cweb_starts_with(const char *string, const char *prefix)`
**description:** Checks if the input string starts with the given prefix.
- **params:**
    - `const char *string`: The string to check.
    - `const char *prefix`: The prefix to look for at the start of the string.
- **returns:** `bool` True if `string` starts with `prefix`, false otherwise.
- **preconditions:** Both `string` and `prefix` must be null-terminated strings.
- **postconditions:** No changes to the input strings.
- **side_effects:** None.

### `char *private_cweb_replace_string_once(const char *target, const char *old_element, const char *new_element)`
**description:** Replaces the first occurrence of `old_element` in `target` with `new_element`.
- **params:**
    - `const char *target`: The string in which to perform the replacement.
    - `const char *old_element`: The substring to be replaced.
    - `const char *new_element`: The substring to replace with.
- **returns:** `char *` A newly allocated string with the first occurrence of `old_element` replaced by `new_element`.
- **preconditions:** All input strings must be null-terminated.
- **postconditions:** The returned string has the first occurrence of `old_element` replaced by `new_element` and is null-terminated.
- **side_effects:** Allocates memory which must be freed by the caller.

### `char *cweb_replace_string(const char *target, const char *old_element, const char *new_element)`
**description:** Replaces all occurrences of `old_element` in `target` with `new_element`.
- **params:**
    - `const char *target`: The string in which to perform the replacements.
    - `const char *old_element`: The substring to be replaced.
    - `const char *new_element`: The substring to replace with.
- **returns:** `char *` A newly allocated string with all occurrences of `old_element` replaced by `new_element`.
- **preconditions:** All input strings must be null-terminated.
- **postconditions:** The returned string has all occurrences of `old_element` replaced by `new_element` and is null-terminated.
- **side_effects:** Allocates memory which must be freed by the caller, and frees intermediate strings.
```
------------------------
