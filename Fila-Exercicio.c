#include <stdio.h>
#define MAX 10

typedef struct fila
{
    int inicio;
    int fim;
    int vetor[MAX];
} Fila;

// Inicializa a fila
Fila inicializarFila()
{
    Fila q;
    q.inicio = 0;
    q.fim = 0;
    return q;
}

// Verifica se a fila está vazia
int estahVazia(Fila q)
{
    return q.inicio == q.fim;
}

// Verifica se a fila está cheia
int estahCheia(Fila q)
{
    return ((q.fim + 1) % MAX) == q.inicio;
}

// Enfileira um elemento na fila
void enfileirar(Fila *q, int valor, int *erro)
{
    if (estahCheia(*q))
    {
        *erro = 1; // Fila cheia
    }
    else
    {
        q->vetor[q->fim] = valor;
        /*q->fim = (q->fim + 1) % MAX;*/
        q->fim++;
        *erro = 0; // Sucesso
    }
}

// Desenfileira um elemento da fila
int desenfileirar(Fila *q, int *erro)
{
    if (estahVazia(*q))
    {
        *erro = 1; // Fila vazia
        return -1;
    }
    else
    {
        int valor = q->vetor[q->inicio];
        /*q->inicio = (q->inicio + 1) % MAX;*/
        q->inicio++;
        *erro = 0; // Sucesso
        return valor;
    }
}

// Função para mostrar o conteúdo da fila
void mostraFila(Fila q)
{
    int i = q.inicio;
    printf("\nFila: ");
    while (i != q.fim)
    {
        printf("%d ", q.vetor[i]);
        /*i = (i + 1) % MAX;*/
        i++;
    }
    printf("\n");
}

// Função para encontrar um elemento na Fila
void encontrarElemento(Fila *q, int elemento)
{
    int count = 0;
    int i = q->inicio;
    printf("\nFila: ");
    while (i != q->fim)
    {
        if (elemento == q->vetor[i])
        {
            count++;
        }
        /*i = (i + 1) % MAX;*/
        i++;
    }
    printf("O Elemento %d aparece %d vezes na Fila", elemento, count);
    printf("\n");
}
int main()
{
    Fila q = inicializarFila();
    int erro, i, opcao, elemento;


    do {
        printf ("\n \n===== MENU DA FILA ====\n");
        printf ("1. Enfileirar elemento \n");
        printf ("2. Desenfileirar elemento \n");
        printf ("3. Mostrar conteúdo da fila \n");
        printf ("4. Encontrar elemento na fila \n");
        printf ("0. Sair \n");
        printf ("========================= \n");
            
        printf ("Escolha uma opção: ");
        scanf ("%d", &opcao);
        switch (opcao){
            case 1:
             // Enfileirando elementos
             printf ("\nDigite: ");
            scanf ("%d", &i);
            enfileirar(&q, i, &erro);
            if (erro) {
                printf("Fila Cheia! Não foi possível enfileirar %d\n", i);
            }

            break;
            case 2:
             // Desenfileirando elementos
            int valor = desenfileirar(&q, &erro);
            if (!erro){
                printf("Desenfileirado: %d\n", valor);
            }
            else{
                printf("Fila Vazia! Não foi possível desenfileirar\n");
            }

            break;
            case 3:
               mostraFila(q);
            break;
            case 4:
              printf ("Digite o elemento que deseja encontrar: ");
              scanf ("%d", &elemento);
              encontrarElemento(&q, elemento);
            break;
            case 0: 
                printf ("\nOperação finalizada.");
                break;
              
            default:
                printf ("\nOpção não encontrada");
                break;
        }
   
    }while (opcao != 0);
    
    return 0;
}