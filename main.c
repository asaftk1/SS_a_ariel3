#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#define TXT 1024
#define WORD 30


int main()
{
    char* a = NULL;
    char* b = NULL;
    int i, j;
    char temp1, temp2;
    a = (char*)calloc(WORD,sizeof(char));
    b = (char*)calloc(TXT,sizeof(char));
    if(a == NULL || b == NULL){
        printf("EROR");
        exit(0);
    }
    for(i = 0; i < WORD;i++)
    {
        temp1 =getchar();
        a[i] = temp1;
        if(a[i]==' ' || a[i]== '\n' || a[i] =='\t')break;
    }
    a[i] ='\0';
    for(j =0; j<TXT ;j++)
    {
        temp2 =getchar();
        b[j] =  temp2;
        if(b[j] == '~')break;
    }
    b[j] = '\0';

    printf("Gematria Sequences: ");
    GematriaSequences(a,b);
    printf("\n");

    printf("Atbash Sequences: ");
    AtbashSequnces(a,b);
    printf("\n");

    printf("Anagram Sequences: ");
    AnagramSequences(a,b);
    free(a);
    free(b);
    return 0;
}
