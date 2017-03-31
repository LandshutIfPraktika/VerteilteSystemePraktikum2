/* rdict_cif.c - initw, insertw, deletew, lookupw, ... */

#include <rpc/rpc.h>
#include <stdio.h>
#include "rdict.h"

extern CLIENT *handle;
static int *ret;
static char ** result;
static manywords * mw;

int initw() {
   ret = initw_1 (0, handle);
   return ret==0 ? 0 : *ret;
}

int insertw(word)
char *word;
{
   char **arg;
   arg = &word;
   ret = insertw_1(arg, handle);
   return ret==0 ? 0 : *ret;
}

int deletew (word)
char *word;
{
   char **arg;
   arg = &word;
   ret = deletew_1 (arg, handle);
   return ret==0 ? 0 : *ret;
}

int lookupw (word)
char *word;
{
   char **arg;
   arg = &word;
   ret = lookupw_1 (arg, handle);
   return ret==0 ? 0 : *ret;
}

int updatew (word, word2)
char *word, *word2;
{
   struct upd arguments, *arg;
   arguments.upd_old = word;
   arguments.upd_new = word2;
   arg = &arguments;
   ret = updatew_1 (arg, handle);
   return ret==0 ? 0 : *ret;
}

int countw (){
    ret = countw_1(0, handle);
    return ret==NULL ? 0 : *ret;
}

char * selectw (){
    result = selectw_1(0, handle);
    return * result;
}

manywords select2w (){
    mw = select2w_1(0, handle);
    return * mw;
}