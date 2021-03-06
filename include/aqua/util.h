#ifndef AQUA_UTIL_H
#define AQUA_UTIL_H

#include <stdlib.h>
#include "aqua.h"

EXPORT void a_fatal(char *error);
EXPORT void *a_malloc(size_t size);
EXPORT void *a_realloc(void *ptr, size_t newsize);
char *url_encode(char *str);
char *url_decode(char *str);

#endif
