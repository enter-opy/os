#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>
 
void main()
{
 char *lk="hi.txt";
 struct stat buf;
 stat(lk,&buf);
 int size=buf.st_size;
 printf("Size of file : %d\n",size); 
 printf("Time : %lo\n",buf.st_atime);
 printf("File ID :%lo\n",buf.st_ino);
}
 






































