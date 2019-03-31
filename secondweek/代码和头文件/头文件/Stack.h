#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status {
    ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct SqStack {
    ElemType *elem;
    int top;
    int size;
} SqStack;

typedef struct StackNode {
    ElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct LinkStack {
    LinkStackPtr top;
    int count;
} LinkStack;

//˳��ջ
Status initStack(SqStack *s, int sizes);//��ʼ��

Status isEmptyStack(SqStack *s);//�п�

Status getTopStack(SqStack *s, ElemType *e);//��ȡջ��Ԫ��

Status clearStack(SqStack *s);//���ջ

Status destroyStack(SqStack *s);//����ջ

Status stackLength(SqStack *s, int *length);//ջ����

Status pushStack(SqStack *s, ElemType data);//��ջ

Status popStack(SqStack *s, ElemType *data);//��ջ

//��ջ
Status initLStack(LinkStack **s);//��ʼ��

Status isEmptyLStack(LinkStack *s);//�п�

Status getTopLStack(LinkStack *s, ElemType *e);//��ȡջ��Ԫ��

Status clearLStack(LinkStack *s);//���ջ

Status destroyLStack(LinkStack **s);//����ջ

Status LStackLength(LinkStack *s, int *length);//ջ����

Status pushLStack(LinkStack *s, ElemType data);//��ջ

Status popLStack(LinkStack *s, ElemType *data);//��ջ

//��װ����---������ջ
void menu();//����

Status input(ElemType* e);//������

Status input2(ElemType* str);//��ȡ������--0~9 +-/*()

void show(LinkStack *s);//��ʾջȫ��Ԫ��

void init(LinkStack *s);//��ʼ��

void isEmpty(LinkStack *s);//�п�

void getTop(LinkStack *s);//��ȡջ��Ԫ��

void clear(LinkStack *s);//���ջ

void destroy(LinkStack *s);//����ջ

void Length(LinkStack *s);//ջ����

void push(LinkStack *s);//��ջ

void pop(LinkStack *s);//��ջ

void count();//��������ջ�ռ����������--

int Priority(char ch);//�жϷ������ȼ�

#endif // STACK_H_INCLUDED