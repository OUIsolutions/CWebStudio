#include "../unique.declaration_requirements.h"

 CTextStack * newCTextStack(const char *line_breaker, const char *separator);

 CTextStack *newCTextStack_string(const char *starter);


 CTextStack *newCTextStack_string_format(const char *format, ...);


 CTextStack *newCTextStack_string_getting_ownership(const char *starter);

 CTextStack *newCTextStack_string_empty();
