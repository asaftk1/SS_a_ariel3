#include <stdio.h>
#include <stdlib.h>
#include "func.c"
#define TXT 1024
#define WORD 30


int main()
{
    char* a = NULL;
    char* b = NULL;
    
    a = (char*)malloc((WORD)*sizeof(char));
    b = (char*)malloc(TXT*sizeof(char));
    printf("enter your string: \n");
    scanf("%[^\n]%*c", a);
    scanf("%[^\n]%*c", b);

    
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