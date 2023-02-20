#ifndef task
#define task

#include "listitem.h"
#include "portmacro.h"
TCB_t task1;
TCB_t task2;
typedef void (*taskFunction)(void*);
typedef void* TaskHandle_t;
//初始化任务，也就是初始化任务控制块
static void InitNewTask(taskFunction pxTaskcode,//任务函数入口名称
	const char* pxTaskName,//任务名
	const int  stack_depth,//栈大小
	void* const paramerers,//任务参数
	TaskHandle_t* const pxCreatedTask,//任务句柄
	TCB_t* NewTcb)//任务控制块
{
	int* pxtopstack;
	long x;
	pxtopstack = NewTcb->pxStart_stack + (stack_depth-1);//获取栈顶指针
	pxtopstack = (int*)((unsigned int)pxtopstack&(~(unsigned int)(0x0007)));//8字节对齐
	for (x = 0; x <= TASK_NAME_LEN; x++)
	{
		NewTcb->task_name[x] = pxTaskName[x];
		if (pxTaskName[x] == 0x00)
			break;
	}
	NewTcb->task_name[TASK_NAME_LEN - 1] = '/0';
	vListInitialistItem(NewTcb->newListItem);
	NewTcb->newListItem->pvOwner = NewTcb;
	NewTcb->pxTopstack = NewTcb->pxTopstack - 8;//函数入口入栈，函数参数入栈，地址共8字节这个本来要调用函数，但是不方便，直接俄赋值了
	if (pxCreatedTask != nullptr)
		*pxCreatedTask = (TaskHandle_t)NewTcb;//返回函数控制块，栈顶指针就是指向函数名，所以后面会发西现新任务换成了栈顶指针
}
//初始化任务根节点
void InitTaskRoot_list(void)
{
	int priority;
	for (priority = 0; priority < (int)configMaxPriority; priority++)
		vListInitalist(&(Task_Ready_List[priority]));//函数参数为指针类型，所以要取根节点地址
}
#endif // !task
