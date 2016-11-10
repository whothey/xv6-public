#include "types.h"
#include "param.h"
#include "stat.h"
#include "syscall.h"
#include "user.h"

int main(int argc, char *argv[])
{
  if (argc > 1) deposittickets(atoi(argv[1]));
  else {
    printf(1, "Atribui um numero de tickets para o proximo processo a ser criado.\n");
    printf(1, "Uso: %s numero_tickets\n", argv[0]);
  }

  exit();
}
