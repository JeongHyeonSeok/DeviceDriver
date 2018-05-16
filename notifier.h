#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

char threshold[5];
char pid[5];
FILE *fp;

void sig(int battery)
{
fp = fopen("pid_th", "r");
fgets(pid,10,fp);
fgets(threshold,10,fp);
fclose(fp);

if(battery < atoi(threshold) )
	kill(atoi(pid), SIGUSR1);
else
	kill(atoi(pid), SIGUSR2);
return;
}
