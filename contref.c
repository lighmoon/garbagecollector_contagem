#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void* pont;
    int contagem;
} alocado;

#define TAM_MAX 1000

static alocado ponteiros[TAM_MAX];
static int tam_pont = 0;

void* malloc2 (size_t peso){
    if(tam_pont == TAM_MAX){
        printf("\nLimite de alocacoes alcancado.\n");
        return NULL;
    }

    void* pont = malloc(peso);

    if (!pont){
        printf("\nErro ao alocar a memoria.\n");
        return NULL;
    }

    ponteiros[tam_pont].pont = pont;
    ponteiros[tam_pont].contagem = 1;
    tam_pont++;
    return pont;
}

void atrib2(void** pont_dest, void *novo) {

    //void **dest = pont_dest;
    //printf("\nfunc: pont: %p, dest:%p\n", pont_dest, *dest);

    if (*pont_dest != NULL) {
        for (int i = 0; i < tam_pont; i++) {  //for: passa por todos os ponteiros alocados
            if (ponteiros[i].pont == *pont_dest) {
                ponteiros[i].contagem--;

                if (ponteiros[i].contagem == 0) {  //se contagem for pra zero, libera
                    free(ponteiros[i].pont);
                    ponteiros[i] = ponteiros[tam_pont - 1]; // remove o bloco atual e ajusta
                    tam_pont--;
                }
                break;
            }
        }
    }

    *pont_dest = novo; //passa o ponteiro novo

    // incrementa o contador de referências do ponteiro novo
    if (novo != NULL) {
        for (int i = 0; i < tam_pont; i++) {
            if (ponteiros[i].pont == novo) {
                ponteiros[i].contagem++;
                break;
            }
        }
    }
}

void dump() {
    printf("\nEstado atual dos ponteiros:\n");
    for (int i = 0; i < tam_pont; i++) {
        printf("Bloco %d: Endereco=%p | Contagem=%d\n",
               i, ponteiros[i].pont, ponteiros[i].contagem);
    }
}

