#include <stdio.h>
#include<stdlib.h>
//define a parent_node
typedef struct bin_treenode
{
 char name;
 int value;
 bin_treenode *leftchild;
 bin_treenode *rightchild;   /* data */
}BTD;
//creat a new node 
BTD* c_treenode(int x,char cname)
{
    BTD *ptr0=(BTD*)malloc(sizeof(BTD));
    if(ptr0==NULL)
      {
        printf("创建失败，请检查源码！\n");
        exit(-1);
      }
    else
     {
        ptr0->value=x;
        ptr0->name=cname;
        ptr0->leftchild=NULL;
        ptr0->rightchild=NULL;
        return ptr0;
     }     
}
//creat a new tree
BTD* c_tree()
  {
    BTD* node1=c_treenode(1,'A');
    BTD* node2=c_treenode(2,'B');
    BTD* node3=c_treenode(3,'C');
    BTD* node4=c_treenode(4,'D');
    BTD* node5=c_treenode(5,'E');
    BTD* node6=c_treenode(6,'F');
    BTD* node7=c_treenode(7,'H');
    BTD* node8=c_treenode(8,'G');
    node1->leftchild=node2;
    node1->rightchild=node3;
    node2->leftchild=node4;
    node2->rightchild=node5;
    node3->leftchild=node6;
    node3->rightchild=node7;
    node4->leftchild=node8;
    return node1;
  }
  
  void forheadorder(BTD * p)
   {
    if(p!=nullptr)
      {
       printf("%c:%d\n",p->name,p->value);
       forheadorder(p->leftchild);
       forheadorder(p->rightchild);
      }
    else
      {
        printf("遍历完成或者为空节点\n");
        return;
      }
   }
 void midorder(BTD * p)
   {
    if(p!=nullptr)
      {
       
       forheadorder(p->leftchild);
       printf("%c:%d\n",p->name,p->value);
       forheadorder(p->rightchild);
      }
    else
      {
        printf("遍历完成或者为空节点\n");
        return;
      }
   }
 void tailorder(BTD * p)
   {
    if(p!=nullptr)
      {
       
       forheadorder(p->leftchild);
       forheadorder(p->rightchild);
       printf("%c:%d\n",p->name,p->value);
      }
    else
      {
        printf("遍历完成或者为空节点\n");
        return ;
      }
   }
   int main ()
   {
    printf("forheand:\n");
    forheadorder(c_tree());
    printf("\nmid:\n");
    midorder(c_tree());
    printf("\ntail:\n");
    tailorder(c_tree());
    return 0;
   }