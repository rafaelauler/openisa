#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
  int dia;
  int mes;
  int ano;
} data;

int
data_para_dias(data d) {
  int total = 0;
  total = (int)((double) (d.ano - 1) * 365.25f);
  switch (d.mes) {
  case 12:
    total += 30;
  case 11:
    total += 31;
  case 10:
    total += 30;
  case 9:
    total += 31;
  case 8:
    total += 31;
  case 7:
    total += 30;
  case 6:
    total += 31;
  case 5:
    total += 30;
  case 4:
    total += 31;
  case 3:
    total += 28;
  case 2:
    total += 31;
  default:
    break;
  }
  if (d.ano % 4 == 0 && d.mes > 2)
    total += 1;

  total += d.dia;
  return total;
}

int
main() {
  data inicio = {1, 1, 1};
  data fim = {1, 1, 1};

  printf("Calculadora de datas.\n");
  printf("Digite a data de início (DD/MM/AAAA): ");
  if (scanf("%d/%d/%d", &inicio.dia, &inicio.mes, &inicio.ano) != 3) {
    printf("\nEntrada incorreta.\n");
    exit(EXIT_FAILURE);
  }
  printf("Digite a data final (DD/MM/AAAA): ");
  if (scanf("%d/%d/%d", &fim.dia, &fim.mes, &fim.ano) != 3) {
    printf("\nEntrada incorreta.\n");
    exit(EXIT_FAILURE);
  }
  
  printf("A diferença é de %d dias.\n", data_para_dias(fim) -
         data_para_dias(inicio));
  exit(EXIT_SUCCESS);
}
