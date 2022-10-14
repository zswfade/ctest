
#include <stdio.h>
#include <string.h>
#include <stdarg.h> 
/*ANSI标准形式的声明方式，括号内的省略号表示可选参数*/ 
int demo( char * msg, ... ) 
{ 
       /*定义保存函数参数的结构*/
   va_list argp; 
   int argno = 0; 
   char *para; 
/*argp指向传入的第一个可选参数，msg是最后一个确定的参数*/ 
   va_start( argp, msg ); 
   while (1) 
       { 
        para = va_arg( argp, char*); 
           if ( strcmp( para, "") == 0 ) 
               break; 
           printf("Parameter #%d is: %s\n", argno, para); 
           argno++; 
} 
va_end( argp ); 
/*将argp置为NULL*/
return 0; 
}

//获取参数列表中的所有参数，并打印
void PrintInt(int cnt, ...) 
{ 
  int *temp = &cnt;
  //temp++;
  temp+=2;
  for (int i = 0; i < cnt; ++i) 
  { 
    printf("%d\n", *temp); 
    temp+=2; 
  } 
}
 void prtf(int x,int y,int z,int w)
  {
printf("%d\n", &x);
printf("%d\n", &y);
printf("%d\n", &z);
printf("%d\n", &w);
  }



  /*this is a main ,it`s only one */
int main(void)
{
    int a = 1; 
    int b = 2; 
    int c = 3; 
    int d = 4;
    PrintInt(4, a, b, c, d); 
    printf("\n");
    prtf(a,b,c,d);
    printf("demo\n");
    demo("DEMO", "This", "is", "a", "demo!", ""); 
    return 0;
}