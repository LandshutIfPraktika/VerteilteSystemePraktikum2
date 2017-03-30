/* rdict_sif.c - init_1, insert_1, delete_1, lookup_1 */

/*
#undef __STDC__
#undef __cpluplus
*/

#include <rpc/rpc.h>
#include "rdict.h"


static int retcode;
static char * result;
static manywords mw;

// this is fucking important !!!!!!!!!!!!
char * selectw();
manywords select2w();

int *initw_1_svc(dummy, handle)
void *dummy;
struct svc_req *handle;
{
   retcode = initw();
   return &retcode;
}

int *insertw_1_svc (w, handle)
char **w;
struct svc_req *handle;
{
   retcode = insertw(*w);
   return &retcode;
}

int *deletew_1_svc (w, handle)
char **w;
struct svc_req *handle;
{
   retcode = deletew(*w);
   return &retcode;
}

int *lookupw_1_svc (w, handle)
char **w;
struct svc_req *handle;
{
   retcode = lookupw(*w);
   return &retcode;
}

int *updatew_1_svc (s, handle)
struct upd *s;
struct svc_req *handle;
{
   retcode = updatew(s->upd_old, s->upd_new);
   return &retcode;
}

int *countw_1_svc (dummy, handle)
void *dummy;
struct svc_req *handle;
{
    retcode = countw();
    return &retcode;
}

char ** selectw_1_svc ( dummy, handle)
void * dummy;
struct svc_req * handle;
{ 
    result = selectw();
    return &result;
}

manywords * select2w_1_svc(dummy, handle)
void * dummy;
struct svc_req * handle;
{ 
    mw = select2w();
    return &mw;
}

