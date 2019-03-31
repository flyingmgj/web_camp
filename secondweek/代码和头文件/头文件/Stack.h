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

//顺序栈
Status initStack(SqStack *s, int sizes);//初始化

Status isEmptyStack(SqStack *s);//判空

Status getTopStack(SqStack *s, ElemType *e);//获取栈顶元素

Status clearStack(SqStack *s);//清空栈

Status destroyStack(SqStack *s);//销毁栈

Status stackLength(SqStack *s, int *length);//栈长度

Status pushStack(SqStack *s, ElemType data);//入栈

Status popStack(SqStack *s, ElemType *data);//弹栈

//链栈
Status initLStack(LinkStack **s);//初始化

Status isEmptyLStack(LinkStack *s);//判空

Status getTopLStack(LinkStack *s, ElemType *e);//获取栈顶元素

Status clearLStack(LinkStack *s);//清空栈

Status destroyLStack(LinkStack **s);//销毁栈

Status LStackLength(LinkStack *s, int *length);//栈长度

Status pushLStack(LinkStack *s, ElemType data);//入栈

Status popLStack(LinkStack *s, ElemType *data);//弹栈

//包装函数---采用链栈
void menu();//界面

Status input(ElemType* e);//输入检测

Status input2(ElemType* str);//获取输入检测--0~9 +-/*()

void show(LinkStack *s);//显示栈全部元素

void init(LinkStack *s);//初始化

void isEmpty(LinkStack *s);//判空

void getTop(LinkStack *s);//获取栈顶元素

void clear(LinkStack *s);//清空栈

void destroy(LinkStack *s);//销毁栈

void Length(LinkStack *s);//栈长度

void push(LinkStack *s);//入栈

void pop(LinkStack *s);//弹栈

void count();//单独开辟栈空间的四则运算--

int Priority(char ch);//判断符号优先级

#endif // STACK_H_INCLUDED