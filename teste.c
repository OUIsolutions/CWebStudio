#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char *teste = malloc(1000);
    strcat(teste,"eai beleza\0");
    char *teste2 = teste;
    teste2+=1;
    printf("%s\n",teste2);
    free(teste);
    return 0;
}