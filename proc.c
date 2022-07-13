 #include<stdio.h>
 #include <sys/types.h>
 #include <unistd.h>
 void test(int n)
 {
  if(fork()==0)
  {
   for(int i=0;i<=n;i+=2)
     printf("%d\t",i);
  }
  else
  {
   for(int i=1;i<=n;i+=2)
    printf("%d\t",i);
    
  }
  printf("\nProcess ID:%d\n",getppid());
 }
 

 int main()
 {
  int n;
  printf("Enter limit : \n");
  scanf("%d",&n);
  test(n);
  return 0;
 }
