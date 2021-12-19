#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TXT 1024
#define WORD 30
int gematria(char s){
    int counter =1;
    if(s<'a' || s>'z')return counter =0;
    for(char i ='a'; i<= 'z'; ++i){
        if(i != s)counter++;
        else return counter;
    }
}
int StringGematriaFullValue(char* s){
    int sum =0, counter =0;
    for(int i = 0; i < strlen(s); i++,counter++){
        for(char j = 'a'; j <= 'z'; j++){
            s[counter] = tolower(s[counter]);
            if(j == s[counter]) sum += gematria(s[counter]);
            if(s[counter] == '\t' || s[counter] == '\n' )return sum;
        }
    }
    return sum;
}

void GematriaSequences(char* a,char* b){
    int wordGematriaValue = StringGematriaFullValue(a);
    char* c, *temp;
    c = (char*)malloc(WORD*sizeof(char));
    temp = (char*)calloc(WORD,sizeof(char));
    int i, sum=0, counter=0;
    for(i = 0; i<strlen(b); i++){
        if(b[i] == '0'||b[i] == '1'||b[i] == '2'||b[i] == '3'||b[i] == '4'||b[i] == '5'||b[i] == '6'||b[i] == '7'||b[i] == '8'||b[i] == '9')i++;
        sum += gematria(b[i]);
        c[counter] = b[i];
        counter++;

        if(sum == wordGematriaValue){
            strcat(temp,c);
            strcat(temp,"~");
            free(c);
            c= (char*) malloc(TXT*sizeof (char));
            counter = 0;
            sum =0;
            i--;

        }
        else if(sum > wordGematriaValue){
            free(c);
            c= (char*) malloc(TXT*sizeof (char));
            counter=0;
            sum=0;
        }
        
    }
    temp[strlen(temp)-1]= '\0';
        printf("%s",temp);
        free(c);
        free(temp);
}


char* Atbash(char* a){
    int i=0;
    char* str;
    str = (char*)malloc(WORD*sizeof(char));

    while(a[i]!='\0')
    {
        if(!((a[i]>=0&&a[i]<65)||(a[i]>90&&a[i]<97)||(a[i]>122&&a[i]<=127)))
        {
            if(a[i]>='A'&&a[i]<='Z')
                str[i] = 'Z'+'A'-a[i];

            if(a[i]>='a'&&a[i]<='z')
                str[i] = 'z'+'a'-a[i];
        }
        i++;
    }
    str[i] = '\0';

    return str;
}

char* reversAtbash(char* a){
    char* str;
    str = (char*)malloc(WORD*sizeof(char));
    char temp;
    int i, len;
    len = strlen(a);
    for (i = 0; i < len/2; i++)
    {

        temp = a[i];
        str[i] = a[len - i - 1];
        str[len - i - 1] = temp;
    }
    str[len] = '\0';
    return str;
}

void AtbashSequnces(char* a, char* b){
    char* check, *temp ,*temp2, *temp3;
    int j;
    check = (char*)malloc(WORD*sizeof(char));
    temp = Atbash(a);
    temp2 = reversAtbash(temp);
    temp3 = (char*)calloc(TXT,sizeof(char));
    // printf("%ld\n",strlen(b));
    for(int i = 0; i<strlen(b);i++){
        while(temp[0] != b[i]&&temp2[0] != b[i] && i<strlen(b))i++;
        for(j = 0; j<strlen(a);j++) {
            check[j] = b[i];
            i++;
        }
        check[j]= '\0';
        if(!strcmp(temp,check)||!strcmp(temp2,check))
        {
            strcat(temp3,check);
            strcat(temp3,"~");
           // printf("%s~",check);
            free(check);
            check = (char*)malloc(WORD*sizeof(char));
            i = (i- strlen(a));
        }
        else
        {
            free(check);
            check = (char*)malloc(WORD*sizeof(char));
            i = (i-strlen(a));
            //printf("%d\n",i);
        }
    }
    free(check);
    temp3[strlen(temp3)-1]= '\0';
    printf("%s",temp3);
    free(temp2);
    free(temp3);

}
//swap function
void swap(char *a, char *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// bubble sort function
void bubbleSort(char array[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++) if (array[j] > array[j+1])
                swap(&array[j], &array[j+1]);
}

void AnagramSequences(char* a, char*b){
    //bubbleSort(b,strlen(b));
    int i,j;
    char* temp;
    temp = (char*)malloc(TXT*sizeof(char));
    char* temp2;
    temp2 = (char*)malloc(TXT*sizeof(char));
    char* temp3;
    temp3 = (char*)calloc(TXT,sizeof(char));
    for(i = 0; i<strlen(b); i++){
        for(j=0; j<strlen(a); j++){
            if(b[i]== ' ')i++;
            temp[j] = b[i];
            i++;
        }
        temp[j]='\0';
        strcpy(temp2,temp);
        bubbleSort(temp,strlen(temp));
        if(!strcmp(temp,a))
        {
            strcat(temp3,temp2);
            strcat(temp3,"~");
            //printf("%s~",temp2);
            free(temp);
            temp = (char*)malloc(TXT*sizeof(char));
            i = (i-strlen(a));
        }
        else
        {
            free(temp);
            temp = (char*)malloc(TXT*sizeof(char));
            i = (i-strlen(a));
        }
    }
    temp3[strlen(temp3)-1] = '\0';
    printf("%s",temp3);
}

