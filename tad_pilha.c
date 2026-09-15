#include "tad_pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include "tad_pilha.h"

struct no {
    char caracter;
    noChar *prox;
};

struct pilha{
    noChar *topo;
};

pChar *criaPilha(){
    pChar *p=(pChar*)malloc(sizeof(pChar));
    if(!p)
        return NULL;
    p->topo=NULL;
    return p;
}

void push(pChar *p,char valor) {
    noChar *novoNo=(noChar*)malloc(sizeof(noChar));
    if(!novoNo)
        return ;
    novoNo->caracter=valor;
    novoNo->prox=p->topo;
    p->topo=novoNo;
    return ;
}

char pop(pChar *p){
    if (p->topo==NULL)
        return '\0';

    noChar *aux=p->topo;
    char valRetorno=aux->caracter;
    p->topo=aux->prox;
    free(aux);

    return valRetorno;
}


void esvazia(pChar *p) {
    while(p->topo!=NULL){
        pop(p);
    }
}

int pilhaVazia(pChar *p){
    if(p->topo==NULL)
        return 1;
    return 0;
}

//Função que verifica se a expressão matemática passada está balanceada
//Retorna 1 se estiver balanceada : todos os símbolos de abertura e fechamento estão balanceados
//Retorna 0 caso contrário
int verificarExpressao(pChar *p, char *expressao){
    int i=0;


    while(expressao[i] !='\0'){
        if(expressao[i]=='(' || expressao[i]=='[' || expressao[i]=='{'){
            push(p,expressao[i]);
        }
        else if(expressao[i]==')' || expressao[i]==']' || expressao[i]=='}'){
            if (p->topo == NULL)
                return 0;

            if((expressao[i]==')' && p->topo->caracter=='(') ||
                (expressao[i]=='}' && p->topo->caracter=='{') ||
                (expressao[i]==']' && p->topo->caracter=='[')) {
                pop(p);
                }
            else
                return 0;
        }
        i++;
    }
    if(p->topo == NULL)
        return 1;
    else
        return 0;
}

void liberaPilha(pChar *p){
    if (p==NULL)
        return;

    esvazia(p);
    free(p);
}
