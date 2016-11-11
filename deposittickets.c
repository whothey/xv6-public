#include "types.h"
#include "param.h"
#include "syscall.h"
#include "user.h"

int main(int argc, char *argv[])
{
  if (argc > 1) deposittickets(atoi(argv[1]));
  else {
    printf(1, "Assign the tickets to a next process\n");
    printf(1, "Use: %s tickets\n", argv[0]);
  }

  exit();
}
