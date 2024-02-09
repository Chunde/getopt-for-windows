#ifndef WINPOS_H
#define WINPOS_H

#include <stdio.h>
#include "getopt.h"

#ifdef _WIN32
#define S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)
#define strncasecmp _strnicmp
#define strcasecmp _stricmp
#endif

#ifdef	__cplusplus
extern "C" {
#endif

extern int getline(char **lineptr, size_t *n, FILE *stream);

#ifdef	__cplusplus
}
#endif

#endif // WINPOS_H