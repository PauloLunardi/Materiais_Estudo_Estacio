#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
  char nome[30];
  int idade;
} Pessoa;

typedef struct {
  Pessoa Itens[MAX];
  int topo;
} Pilha;



int pilhaVazia(Pilha *p) {
  return p->topo == -1;
}

int pilhaCheia(Pilha *p) {
  return p->topo == MAX - 1;
}

void push(Pilha *p, Pessoa nova) {
  if(pilhaCheia(p)) {
    printf("Pilha cheia, não é possivel inserir.\n");
    return;
  }
  p->topo++;
  p->itens[p->topo] = nova;
}

  void pop(Pilha *p, Pessoa *removida) {
    if(pilhaVazia(p)) {
      printf("Pilha vazia, não é possivel remover.\n");
      return;
    }
    *removida = p->itens[p->topo];
    p->topo--;

void peek(pilha *p, pessoa * visualizada) {
  if (pilhaVazia(p)) {
    printf("Pilha vazia, Não há nada para olhar.\n");
    return;
  }
  *visualizada = p->itens[p->topo];
}

void mostrarPilha(Pilha *p) {
  printf("Pilha (topo -> base): \n");
  for (int i = p->topo; i >= 0; i--) {
    printf("[%s, %d]\n", p->itens[i].nome, p->itens[i]. idade);
  }
  printf("\n");
}

int main() {
  Pilha p;
  inicializarPilha(&p);

  Pessoa a = {"Ana", 22};
  Pessoa b = {"Beatriz", 23};
  Pessoa c = {"Carol", 24};

  push(&p, a);
  push(&p, b);
  push(&p, c);

  mostrarPilha(&p);

  Pessoa Removida;
  pop(&p, &removida);
  printf("Removida: %s, %d\n, removido.nome, removida.idade);

  mostrarPilha(&p);

  Pessoa topo;
  peek(&p, &topo);
  printf("Topo atual: %s, %d\n", topo.nome, topo.idade);

  return 0;

}


      

