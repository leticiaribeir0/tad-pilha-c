#include <stdio.h>
#include "tad_pilha.h"

int main() {
    int res;
    char entrada[30];
    pChar *p = criaPilha();
    if (!p)
        return -1;
    printf("Expressao numerica: \n");
    fgets(entrada, 30, stdin);

    res = verificarExpressao(p, entrada);
    if (res == 1)
        printf("BALANCEADA");
    else
        printf("DESBALANCEADA");

    liberaPilha(p);

    return 0;
}
