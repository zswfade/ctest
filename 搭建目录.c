#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <dir.h>

/*fouces on compile top languer,it will make catalogue path wrong */
// relative path ./file/good.txt
//absolutely path C:/file/good.txt
//fputs supported stream contral
int main(void)
  {   
    char filename[5][50];
    char content[5][50]={"good","bad","work","pitch","nidaye"};//if you want use chinese ,please switch GB2132
     FILE *fp;
     char (*p)[50]=filename;
     char (*q)[50]=content;
     char *b=".TXT";
     char a[10]="./file/";
     int i,n=0;
     printf("startwork\n");
     for (i=0;i<5;i++)
         {  int statue;
           strcpy(p[i],a);
           strcat(p[i],q[i]);
           strcat(p[i],b);
           printf("%s\n",p[i]);
           printf("%d----------------\n",i+1);
           statue=mkdir("file");
           if(!statue)
             {
              printf("文件创建失败");
             }
           if((fp=fopen(p[i],"w"))==NULL)
           {
              printf("打开文件失败,%s存在错误和文件不存在\n",p[i]);
              continue;//不在执行for作用域下面，改为下一轮for循环
           }
            statue=fputs(q[i],fp);
            if(statue)
               {
                printf("写入失败\n");
               }
            fclose(fp);
            printf("成功创建文件%s\n",p[i]);
            n++;
         }
         putchar(10);//换行ascii(10)
         printf("总共创建了%d个文件",n);
         putchar(10);
         putchar(10);
         //system("pause");
         return  0;
    }