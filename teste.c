#include "CWebStudio.h"

CwebNamespace cweb;



typedef struct {
    char *nome;
    int idade;
} Usuario;


Usuario teste(){
    Usuario usuario = {0};
    usuario.nome = "mateus ";
    usuario.nome ="aaaa";
    usuario.idade = 27;
    return usuario;
}



int main(int argc, char *argv[]){
    char *resposta = teste().nome;
    printf("%s\n",resposta);
}
