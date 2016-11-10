#include "types.h"
#include "stat.h"
#include "syscall.h"
#include "user.h"
#include "rand.h"

// Limit of tickets
#define TLIMIT 500

// Limit of loops
#define LIMIT  400

void nop() {
  // Must do something like "print nothing" due agressive loop optimizations
  printf(1, "");
  return;
}

int main(int argc, char *argv[])
{
  int pid = 0;
  unsigned int i, j, k, nprocesses, n, t;

  if (argc > 1)
    nprocesses = atoi(argv[1]);
  else
    nprocesses = 10;

  printf(1, "Hello! I'm PID %d, the Scheduler Tester with %d tickets!\n", getpid(), gettickets());
  printf(1, "\nYou could send me parameters in this way:\n");
  printf(1, "    %s nprocesses [p0ticket, p1ticket, p2ticket, ...]\n", argv[0]);
  printf(1, "    nprocesses: number of forks that will be created\n");
  printf(1, "    [p0ticket, ...]: tickets that will be binded to processes, if there is not enough I'll randomize some for you.\n");

  printf(1, "\nNow I'm going to start %d processes and bind your tickets for them...\n\n", nprocesses);

  for (n = 0, t = 0; n < nprocesses; n++) {
    if (t < (argc - 1))
      pid = fork(atoi(argv[2 + t++]));
    else
      pid = fork(fastrand() % (TLIMIT + 100));

    if (pid < 0) printf(1, "Fork failed!");

    if (pid == 0) break;
  }

  if (pid == 0) {
    printf(1, "PID %d has started with %d tickets!\n", getpid(), gettickets());

    for (i = 0; i < LIMIT; i++)
      for (j = 0; j < LIMIT; j++)
        for (k = 0; k < LIMIT; k++) nop();

    printf(1, "PID %d has ended! (%d)\n", getpid(), gettickets());
  }

  if (pid > 0) {
    for (n = 0; n < nprocesses; n++) wait();

    printf(1, "Test finished\n", getpid());
  }

  exit();
}
