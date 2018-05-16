#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static void sig_usr(int); /* one handler for both

signals */

int main(void){

FILE *fp;
int threshold = 15;
fp = fopen("pid_th", "w");
fprintf(fp,"%d\n", getpid());
fprintf(fp,"%d", threshold);
fclose(fp);

if (signal(SIGUSR1, sig_usr) == SIG_ERR)

  printf("can't catch SIGUSR1");

if (signal(SIGUSR2, sig_usr) == SIG_ERR)

  printf("can't catch SIGUSR2");

for ( ; ; )
  pause();

}

static void

sig_usr(int signo) { /* argument is signal number */

if (signo == SIGUSR1)

   printf("received SIGUSR1\n");

else if (signo == SIGUSR2)

   printf("received SIGUSR2\n");

else printf("received signal %d\n", signo);

return;

}
