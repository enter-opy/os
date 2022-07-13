#include<stdio.h>
#include<unistd.h>
#include <sys/stat.h>

int main()
{
 char path[20];#include <sys/stat.h>
 struct stat *buf;
 buf=(struct stat *)malloc(sizeof(struct stat));
 
