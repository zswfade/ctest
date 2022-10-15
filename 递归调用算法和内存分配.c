//so we will test a recursion_cycle_call function
//this has a importance  for parameter ,it must become smaller ,it has a break of program
#include <stdio.h>
#include "malloc.h"
//this is rabitte reproduction,one stage is born,two stage is young ,three stage can reproduction of baby.
//so we can deduction f(n)=f(n-1)+f(n-2)
int function1 (int n)
{
   if (n==2||n==1)
          return 1;
    return function1(n-1)+function1(n-2);
 }
    //monkey eat peach  ,left 1 peach in 10 month ,everyday eat half of total plus one
    int peach(int c)
     {
        if(c==10)
          return 1;
        return (peach(c+1)+1)*2;
     }
     //n!
     int factioral(int n)
        {
            if(n==1)
             return 1;
             return (factioral(n-1)*n);
        }

//malloc and free,new and delete
#include "stdio.h"
 
#include "malloc.h"//malloc()函数被包含在malloc.h里面
 
 
int malloctest(void)
{
 
    char *a = NULL;//声明一个指向a的char*类型的指针
         
    a = (char*)malloc(100*sizeof(char));//使用malloc分配内存的首地址，然后赋值给a
 
    if(!a)//如果malloc失败，可以得到一些log，  此处返回条件判断错误，应为：if(NULL == a)
         
    {
        perror("malloc");
        return -1;
    }
 
    sprintf(a,"%s","HelloWorld\n");//"HelloWorld\n"写入a指向的地址
     
    printf("%s\n",a);
     
    free(a);//释放掉使用的内存地址
}
int main (void)
    {
        printf("functon1=%d\n",function1(12));
        printf("monkey has %d peachs! \n",peach(1));
        printf ("The factioral of 10 is %d \n",factioral(10));
        malloctest();
        return 0;
    }