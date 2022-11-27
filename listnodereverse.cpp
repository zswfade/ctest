// listnodereverse.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <stdarg.h>
struct listnode
{
    int data;
    struct listnode* next;
};
typedef struct listnode stlistnode;
/*使用va_list必须声明需要操作的参数个数，不然会一直访问下去，从右向左入栈，甚至访问不存在的地址*/
stlistnode* setvaluelistnode(stlistnode* head,int b, int a, ...)
{
    stlistnode* temp;
    stlistnode* curr=head;
   // stlistnode* next;
    //stlistnode* tail;
    va_list argp;//指针变量
    int x;
    /*if (head == NULL)
        return NULL;*/
    va_start(argp,b);//读取参数起始指针地址,这个有个bug，就是vc++和c99还有标准main是不一样的，可自行体会
    x = va_arg(argp, int);//读取参数地址argp+int类型存储地址偏移的参数值
    if (x == 0)
        return head;
    head->data = x;
    while (--b)
    {
        x = va_arg(argp,int);
        if (argp == NULL)
            break;
        temp = (stlistnode*)malloc(sizeof(stlistnode));
        head->next = temp;
        temp->data = x;
        temp->next = NULL;

        head = temp;
    }
    va_end(argp);
  return curr;
}
stlistnode* reverselistnode(stlistnode* head, int m, int n)
{
    stlistnode* temp = NULL;
    stlistnode* curr = head;//当前地址
    stlistnode* next = NULL;//链表反转前半段
    stlistnode* mhead = head;//开始反转地址
    stlistnode* tail = head;//链表反转后半段
    stlistnode* temp1=NULL;//重新构造的链表，需要将前半段连起来
    
    if ( (head == NULL) || (m==n))
              return head;
    while (--m)
    {
        next = mhead;//保存翻转前半段
        mhead = mhead->next;
    }
    while (n--)
    {
        tail = tail->next;
    }
    temp1 = tail;
    while (mhead != tail)
    {
        temp = mhead->next;
        mhead->next = temp1;//空地址赋值会报异常，这个给该怎么处理呢？他是个局部变量，分配个地址？
        //temp1 = (stlistnode*)malloc(sizeof(stlistnode));
        temp1 = mhead;
        mhead = temp;
    }
    /*free(temp1);//把temp1指向的地址全释放了
    temp1 = NULL;*/
    if (next)
    {
        curr->next = temp1;
        return curr;
    }
    return temp1;
}
int main()
{
    stlistnode work = {20,NULL};
    stlistnode* p = (stlistnode*)malloc(sizeof(stlistnode)),*temp;
    p = setvaluelistnode(p, 6, 1, 2, 3, 4, 5, 6);
    p = reverselistnode(p,2,4);
    temp = p;
    while (temp)
    {
        std::cout << temp->data;
        temp = temp->next;
    }
    std::cout << std::endl;
    std::cout << "Hello World!\n";
    free(p);
    p = NULL;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
