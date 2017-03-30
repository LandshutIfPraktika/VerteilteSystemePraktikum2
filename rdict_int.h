#ifndef _RDICT_INT_H
#define _RDICT_INT_H

#include "rdict.h"
int initw();
int insertw(char *);
int deletew (char *);
int lookupw (char *);
int updatew (char *, char *);
int countw();
char * selectw();
manywords select2w();


#endif /* !_RDICT_INT_H */