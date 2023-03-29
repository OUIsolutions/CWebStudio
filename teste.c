#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc, char ** argv){

    int teste_val = 20;

    void teste(){
        teste_val = 10;
    };
    
    printf("teste %d\n", teste_val);
    teste();
    printf("teste %d\n", teste_val);


 
    return 0;
}