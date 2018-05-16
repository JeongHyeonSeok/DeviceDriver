#include <stdio.h>
#include <stdlib.h>
#include "notifier.h"

int main()
{
FILE *fp;
char battery[3];

for(;;)
{
fp=fopen("battery","r");
fscanf(fp,"%s",battery);
printf("battery:%s\n",battery);
sig(atoi(battery));
sleep(3);
}
fclose(fp);
return 0;
}
