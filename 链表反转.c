#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <windows.h>

struct listnode 
  {
  	int data;
  	struct listnode *next;
  };
  typedef struct listnode stlistnode;
 
  stlistnode * reverselist(stlistnode *head,int m,int n)
    {  
    	stlistnode *first;
    	stlistnode *second;
    	stlistnode *tail;
    	stlistnode *cur;
    	stlistnode *temp;
    	if(head==NULL)
    	    return NULL;
    	 if(m==n)
    	     return head;
    	  second=head;
    	  while (--m)
    	    { first=second; //1.2.3.4.5
    	    	second=second->next;//2.3.4.5
    	    }
    	    tail=head;
    	  while(n--)
    	   {
    	   	tail=tail->next;
    	   }  
		   cur=tail;
    	   while(second!=cur)
    	   {
    	   	temp=second;//2.3.4.5     3.4.5    4.5
    	   	second->next=tail;//2.5     3.2.5    4.3.2.5
    	   	tail=second;//2.5             3.2.5   4.3.2.5
    	   	second=temp->next;//3.4.5      4.5   5
    	   }
    	   if (first)
    	    { 
			first->next=second;//1.4.3.2.5
    	     return head;
			 }
    	    else
    	      return second;//4.3.2.5
    }
    stlistnode * setvalue1(stlistnode * head,int a,...)
       {
       	 stlistnode *start;
       	/*stlistnode *next;
       	stlistnode *good;*/
       	va_list argp;
       	int x;
		start=head;
       	va_start(argp,a);
       	while (1)
       	  { 
			x=va_arg(argp,int); 
			if(x==0)
			    break;
       	  	start->data=x;
			printf("%d\n",start->data);
       	  	head=start->next;
       	  	}
		va_end(argp);
	    return head;
       	}
    int main(void)
      {
        stlistnode work;
        stlistnode *p=malloc(sizeof(work));
		printf("q/n\n");
        p=setvalue1(p,1,1,2,3,4,5);
        p=reverselist(p,2,4);
		Sleep(5);
        while(1)
          {
			if(*p==NULL)
			     break;
			printf("%d,",p->data);
          	p=p->next;
          	}
        return 0;
      	}