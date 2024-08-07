
#include "../uniq.declaration_requirements.h"

char *cweb_parse_string_to_lower(const char *old_string);

char *cweb_parse_string_to_upper(const char *old_string);

char *cweb_normalize_string(const char *old_string,const char *invalid_chars);

bool cweb_starts_with(const char *string, const char *prefix);

char *cweb_replace_string_once(const char *target, const char *old_element, const char *new_element);

char* cweb_replace_string(const char *target, const char *old_element, const char *new_element);
