#include <stdio.h>
#include <stdlib.h>
#include "my_func.c"
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
    printf("enter your string: \n");

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
    //printf("the Gematria Sequences is: %s\n",GematriaSequences(a,b));
    printf("Atbash Sequences: ");
    AtbashSequnces(a,b);
    printf("\n");
    printf("Anagram Sequences: ");
    AnagramSequences(a,b);
    printf("\n");
    return 0;
}
