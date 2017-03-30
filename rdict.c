/*rdict.c - main, nextin */

#include <rpc/rpc.h>
#include <stdio.h>
#include <ctype.h>

#include "rdict.h"

#define MAXLINE 80
#define RMACHINE  "localhost"

/* andere Server-Maschine: muss in /etc/hosts.allow konfiguriert werden */
/* #define RMACHINE "lux32" */

CLIENT *handle;

char * selectw();
manywords select2w();

int main (argc, argv)
int argc;
char *argv[];
{
   char word  [MAXWORD + 1];
   char word2 [MAXWORD + 1];
   char cmd;
   int wrdlen;
   int i;
   int length;
   char *res;
   manywords mw;


   handle = clnt_create (RMACHINE, RDICTPROG, RDICTVERS, "TCP");
   if (handle == 0) {
      printf ("Could not contact remote program.\n");
      exit(1);
   }
    printf ("Remote Program contacted successfully.\n");
    printf ("Enter Command out of    I i d l u c s S q\n");
   
   while (1) {
      wrdlen = nextin (&cmd, word, word2);
      if (wrdlen < 0) exit (0);
      /* printf ("Command in main %c\n", cmd);      */
      /* printf ("1. Command in main %s\n", word);  */
      /* printf ("2. Command in main %s\n", word2); */
      switch (cmd) {
         case 'I':
            initw();
            printf ("Dictionary initialized to empty.\n");
            break;
         case 'i':
            if (insertw (word))
               printf ("%s inserted.\n", word);
            else
               printf ("%s could not be inserted.\n", word);
            break;
         case 'd':
            if (deletew (word))
               printf ("%s deleted.\n", word);
            else
               printf ("%s could not be deleted.\n", word);
            break;
         case 'l':
            if (lookupw (word))
               printf ("%s was found.\n", word);
            else
               printf ("%s was not found.\n", word);
            break;
         case 'u':
            printf ("Client: Update is called.\n");
            if (updatew (word, word2))
               printf ("%s was updated to %s\n", word, word2);
            else
               printf ("Could not update %s.\n", word);
            break;
         case 'c':
            printf ("Client: Count is called.\n");
            printf ("current word count is: %d\n", countw());
            break;
         case 's':
            printf ("Client: Select is called.\n");
            res = selectw();
            printf ("all entries (string):\n%s\n", res);
            break;
         case 'S': 
            printf ("Client: Select2 is called.\n");
            mw = select2w();
            printf("all entries (list):\n");
            for(i=0; i<mw.words.words_len; i++){
                  printf("%s \n", mw.words.words_val[i]);
            }
            break;
         case 'q':
            printf ("program quits.\n");
            exit(0);
         default:
            printf ("command %c invalid.\n", cmd);
            break;
      }
   }
   return 0;
}

int nextin (cmd, word, word2)
char *cmd, *word, *word2;
{
   char command[MAXLINE];
   char tmp[10];
   //gets (command); // liest bis newline, also u.U. mehrere durch Leerzeichen getrennte Strings
   //fgets liest bis newline oder bis MAXLINE Bytes, also u.U. mehrere durch Leerzeichen getrennte Strings
   fgets (command, MAXLINE, stdin);
   sscanf (command, "%s %s %s", tmp, word, word2); // liest aus commannd in tmp, word, word2 hinein
   *cmd = tmp[0];
   return 0;
}


