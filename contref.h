#ifndef contref
#define contref

#include <stddef.h>

// Estrutura para rastrear ponteiros e contagem de referências
typedef struct {
    void *pont;
    int contagem;
} alocado;

// Tamanho máximo de alocações
#define TAM_MAX 1000

// Declaração de funções
void *malloc2(size_t peso);
void atrib2(void *pont_dest, void *src);
void dump(void);

#endif