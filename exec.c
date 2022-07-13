#include<unistd.h>
int main(void)
{
 char *pgname="./fork";
 char *args[]={pgname,"-lh","/home/s4d2",NULL};
 
 execvp(pgname,args);
 return 0;
}
