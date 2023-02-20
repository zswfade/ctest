#ifndef task
#define task

#include "listitem.h"
#include "portmacro.h"
TCB_t task1;
TCB_t task2;
typedef void (*taskFunction)(void*);
typedef void* TaskHandle_t;
//��ʼ������Ҳ���ǳ�ʼ��������ƿ�
static void InitNewTask(taskFunction pxTaskcode,//�������������
	const char* pxTaskName,//������
	const int  stack_depth,//ջ��С
	void* const paramerers,//�������
	TaskHandle_t* const pxCreatedTask,//������
	TCB_t* NewTcb)//������ƿ�
{
	int* pxtopstack;
	long x;
	pxtopstack = NewTcb->pxStart_stack + (stack_depth-1);//��ȡջ��ָ��
	pxtopstack = (int*)((unsigned int)pxtopstack&(~(unsigned int)(0x0007)));//8�ֽڶ���
	for (x = 0; x <= TASK_NAME_LEN; x++)
	{
		NewTcb->task_name[x] = pxTaskName[x];
		if (pxTaskName[x] == 0x00)
			break;
	}
	NewTcb->task_name[TASK_NAME_LEN - 1] = '/0';
	vListInitialistItem(NewTcb->newListItem);
	NewTcb->newListItem->pvOwner = NewTcb;
	NewTcb->pxTopstack = NewTcb->pxTopstack - 8;//���������ջ������������ջ����ַ��8�ֽ��������Ҫ���ú��������ǲ����㣬ֱ�Ӷ�ֵ��
	if (pxCreatedTask != nullptr)
		*pxCreatedTask = (TaskHandle_t)NewTcb;//���غ������ƿ飬ջ��ָ�����ָ�����������Ժ���ᷢ���������񻻳���ջ��ָ��
}
//��ʼ��������ڵ�
void InitTaskRoot_list(void)
{
	int priority;
	for (priority = 0; priority < (int)configMaxPriority; priority++)
		vListInitalist(&(Task_Ready_List[priority]));//��������Ϊָ�����ͣ�����Ҫȡ���ڵ��ַ
}
#endif // !task
