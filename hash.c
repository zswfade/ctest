#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int * findnumber(int *array)
    {
        int hash[100001]={0};
        int *arr=(int *)malloc(sizeof(array));
        int count=0;
        for(int i=0;i<sizeof(array);i++)
             {  
               printf("%d\n",hash[array[i]]);
                hash[array[i]]++;
             }
      for(int i=0;i<sizeof(array);i++)
             {
                if(hash[array[i]]==1)
                     {
                        arr[count]=array[i];
                        printf("%d\n",arr[count]);
                        count++;
                     }
             }  
       printf("%d %d %d \n",arr[0],arr[1],arr[2]);
       return arr;  
    }
    //focus on this
    void testfun()
      {
         int arr1[20]={0,1,123,34,23};
         int *p=NULL;
         p=arr1;
         int *n=0,*z=0;
         int elementnumber=0;
         z=p;
         //n=_msize(p)/sizeof(int);//_msize只能获得malloc和new 的内存大小，直接赋值的数组指针大小不能获得
         printf("p:%d\n",sizeof(p));
         printf("*p:%d\n",sizeof(*p));
         printf("&p:%d\n",sizeof(&p));
         printf("arr:%d\n",sizeof(arr1));
         printf("*p:%d\n",*p);
          printf("p[2]:%d\n",p[2]);
          printf("p[20]:%d\n",p[20]);
          printf("&p:%d\n",&p);
          printf("*(p+1):%d\n",*(p+1));
          while (*p!=' ')//字符串回车判定，数组不可用,/0字符串回车
             {
                 p++;
                 n=p;
             }
          elementnumber=n-z;
          printf("n:%d\n",n);
          printf("z:%d\n",z);
          printf("&n:%d\n",&n);
          printf("&z:%d\n",&z);
          printf("*n:%d\n",*n);
          printf("*z:%d\n",*z);
          printf("elementnumber:%d\n",elementnumber);
          printf("elementnumber/4:%d\n",elementnumber/4);
      }
    int main()
      {
         //int array3[10];
        int array1[7]={1,2,3,4,3,2,6};
        //array1=(int *)malloc(sizeof(array3));d=new int[10];
        int arry2[sizeof(array1)/4];
        int*p=NULL;
        printf("%d\n",sizeof(array1)/4);
        p=findnumber(array1);
        printf("%d %d %d \n",p[0],p[1],p[2]);
        testfun();
        //system("pause");
      }