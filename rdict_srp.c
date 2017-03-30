/* rdict_srp.c - initw, insertw, deletew, lookupw */

#include <rpc/rpc.h>

#include "rdict.h"
char dict[DICTSIZ] [MAXWORD+1];
int  nwords = 0;
char result[DICTSIZ * MAXWORD + DICTSIZ + 1];

int initw() {
   nwords = 0;
   return 1;
}

int insertw (word)
char *word;
{
   int i;
   for (i=0; i<nwords; i++)
      if (strcmp (word, dict[i]) == 0)
         return 0;
   strcpy (dict[nwords], word);
   nwords++;
   return nwords;
}

int deletew (word)
char *word;
{
   int i;
   for (i=0; i<nwords; i++)
      if (strcmp (word, dict[i]) == 0) {
         nwords--;
         strcpy (dict[i], dict[nwords]);
         return 1;
      }
   return 0;
}

int lookupw (word)
char *word;
{
   int i;
   for (i=0; i<nwords; i++)
      if (strcmp (word, dict[i]) == 0)
         return 1;
   return 0;
}

int updatew (word, word2)
char *word, *word2;
{
   int i;
   for (i=0; i<nwords; i++)
      if (strcmp (word, dict[i]) == 0) {
         strcpy (dict[i], word2);
         return 1;
      }
   return 0;
}

int countw () {
      return nwords;
}

char * selectw() {
      int i;
      for (i = 0; i < nwords; i++){
            if (!i) {
                  strcpy( result, dict[i]);
                  strcat( result, "\n");
            } else {
                  strcat( result, dict[i]);
                  strcat( result, "\n");
            }
      }
      return result;
}