#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


//顺序栈
Status initStack(SqStack *s, int sizes){  //初始化
	// sizes值判断
	if(sizes <= 0 ) {
		return ERROR;
	}
	s->elem = (ElemType *)malloc(sizes*sizeof(ElemType));
	if(!s) return ERROR;
	s->size = sizes;
	//表示栈中无元素
	s->top = -1;
   	return SUCCESS;
}

Status isEmptyStack(SqStack *s) {//判空
	if(s == NULL || s->top == -1) return ERROR;
	return SUCCESS;
}
Status getTopStack(SqStack *s, ElemType *e)//获取栈顶元素
{
	if( s->top == -1 || s ) return ERROR;
	*e = s->elem[s->top];
	return SUCCESS;
}

Status clearStack(SqStack *s) {//清空栈

	if(s->top == -1 || s == NULL) return ERROR;
	s->top = -1;
	return SUCCESS;
}

Status destroyStack(SqStack *s) {//销毁栈
	if(s == NULL ) return ERROR;
	free(s->elem);
	s->elem = NULL;
	s->size = 0;
	s->top = -1;
	return SUCCESS;
}

Status stackLength(SqStack *s, int *length) {//栈长度
	if(s == NULL ) return ERROR;
	(*length) = s->top + 1;
	return SUCCESS;
}

Status pushStack(SqStack *s, ElemType data) {//入栈
//判断是否溢出
	if(s == NULL || (s->top + 1) >= s->size ) return ERROR;
	s->elem[++(s->top)] = data;
	return SUCCESS;
}

Status popStack(SqStack *s, ElemType *data) {//弹栈
//检测是否为空
	if(s == NULL || s->top == -1 ) return ERROR;
	*data = s->elem[(s->top)--];
	return SUCCESS;
}


//链栈
Status initLStack(LinkStack **s) {//初始化
	*s = (LinkStack *)malloc(sizeof(LinkStack));
	if(!s) return ERROR;
//初始化数据
	(*s)->top = NULL;
	(*s)->count = 0;
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s) {//判空
	if(!s || s->count > 0 ) return ERROR;
	return SUCCESS;
}

Status getTopLStack(LinkStack *s, ElemType *e) {//获取栈顶元素
	if(!s || s->count == 0) return ERROR;
	*e = s->top->data;
	return SUCCESS;
}

Status clearLStack(LinkStack *s) {//清空栈
	LinkStackPtr p = NULL;
	if(s == NULL) {
		return ERROR;
	}
	s->count = 0;
	while(s->top) {
		p = s->top;
		s->top = p->next;
		free(p);
	}
	return SUCCESS;
}

Status destroyLStack(LinkStack **s) {//销毁栈
	if( !(*s) || !clearStack(*s))return ERROR;
	free(*s);
	*s = NULL;
	return SUCCESS;
}
Status LStackLength(LinkStack *s, int *length) {//栈长度
	if(!s) return ERROR;
	*length = s->count;
	return SUCCESS;
}

Status pushLStack(LinkStack *s, ElemType data) {//入栈
	LinkStackPtr p = NULL;
	if(!s) return ERROR;
	p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = data;
	if(!p) return ERROR;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
	
}

Status popLStack(LinkStack *s, ElemType *data) {//弹栈
	LinkStackPtr p;
	if(!s || !s->count) return ERROR;
	s->count--;
	p = s->top;
	*data = p->data;
	s->top = p->next;
	free(p);
	return SUCCESS;
}


//包装函数---采用链栈
void menu(){	//界面
	system("color 87");
	printf("\n");  
    printf("____|________________________________________________|\n");  
    printf("____|________________________________________________|\n");  
    printf("____|_________________栈操作测试_____________________|\n");  
    printf("____|************************************************|\n");
	printf("____|________________0、退出_________________________|\n");    
    printf("____|________________1、初始化栈_____________________|\n");  
    printf("____|________________2、判断是否为空栈_______________|\n");  
    printf("____|________________3、查看栈_______________________|\n");  
    printf("____|________________4、查看栈顶元素_________________|\n");  
    printf("____|________________5、清空栈_______________________|\n");  
    printf("____|________________6、销毁栈_______________________|\n");
	printf("____|________________7、出栈（弹栈）_________________|\n");
	printf("____|________________8、入栈（压栈）_________________|\n");
//	printf("____|________________9、四则运算_____________________|\n");
    printf("____|************************************************|\n");  
    printf("____|________________________________________________|\n");
	printf("***选择你要使用的功能,输入对应数字***\n:");     
    return ;  
}

Status input(ElemType* e) {//输入检测
	int i = 0;
	int a = 0;
	int minus = 1;
	char str[1000] = "\0";
	fflush(stdin);	  
	scanf("%s",&str);
	fflush(stdin);
	while(str[i] != '\0' && str[i] != '\n '){
		if(i == 0 && str[0] == '-') {minus*=-1; i++;continue;}
		if(str[i] > '9' || str[i] < '0') {
			return ERROR;
		}		
		a = a*10 + str[i] -'0'; 
		i++;
	}
	*e = a*minus;
	return SUCCESS;
}

Status input2(char str[]) {//获取输入检测--0~9 +-/*()
	int i = 0;
	fflush(stdin);	  
	scanf("%s",str);
	fflush(stdin);
	while(str[i] != '\0' && str[i] != '\n'){
		if(str[i] < '(' && str[i] > '9' && str[i] == '.') { 
			return ERROR;
		}		
		i++;
	}
	return SUCCESS;
}

void show(LinkStack *s) {//显示栈全部元素
	LinkStackPtr p = NULL;
	int i = 0;
	if(!s) {
		printf("\t无栈信息!!!请先初始化一个栈\n");
		Sleep(500);
	}else if(!s->count) {
		printf("该栈是一个空栈!!!\n");
		Sleep(500);
	}else {
		p = s->top;
		printf("栈顶");
		while(p){
			printf("<--%d",p->data);
			p = p->next;
		}
		printf("<--栈底\n");
		printf("2秒后退出!!!");
		Sleep(2000);
		
	}
	return ;
}

void init(LinkStack **s){	//初始化
	if((*s) != NULL) {
		printf("已经初始化了一个栈!!!\n");
	}else {
		if(!initLStack(s)) printf("初始化失败");
		else printf("初始化成功!!!\n");
	}
	Sleep(500);
}
void isEmpty(LinkStack *s) {//判空
	if(isEmptyLStack(s) == SUCCESS) {
		printf("该栈为空栈!!!\n");
		Sleep(500);
	}else {
		printf("该栈非空或栈不存在!!!\n");
		Sleep(500);
	}
}

void getTop(LinkStack *s) {//获取栈顶元素
	int e = 0;
	if(!getTopLStack(s, &e)) {
		printf("获取失败!!!\n");
		Sleep(500);
	}else {
		printf("栈顶元素---%d\n",e);
		Sleep(500);
	}
}

void clear(LinkStack *s) {//清空栈
	if(clearLStack(s) == ERROR) {
		printf("空栈无法清除!!!\n");
		Sleep(500);
	}else {
		printf("栈已清除!!!\n");
		Sleep(500);
	}
}


void destroy(LinkStack **s) {//销毁栈
	if( !(*s) ||destroyLStack(s) == ERROR) {
		printf("未初始化栈，无法清除!!!\n");
		Sleep(500);
	}else {
		printf("栈已销毁!!!\n");
		Sleep(500);
	}
}

void Length(LinkStack *s) {//栈长度
	int a = 0;
	if(!LStackLength(s,&a) == ERROR) {
		printf("未初始化栈,清先初始化一个栈!!!%d\n");
		Sleep(500);
	}else {
		printf("栈的长度为:%d!!!%d\n",a);
		Sleep(500);
	}
}

void push(LinkStack *s) {//入栈
	int a = 0;
	if( s == NULL ) {
		printf("未初始化栈,清先初始化一个栈!!!\n");
		Sleep(500);
	}else {
		printf("请输入要入栈的元素(整数)\n:");
		while(!input(&a)){
			printf("输入格式有误!请重新输入\n:");
		}
		printf("入栈的数字为:%d\n",a);
		if(pushLStack(s, a)) {
			printf("入栈成功!!\n");
		}else {
			printf("入栈失败!!");
		}
		Sleep(500);
	}
}
void pop(LinkStack *s) {//弹栈
	int a = 0;
	if(popLStack(s, &a) == ERROR) {
		printf("未初始化栈或栈中无元素!!!\n");
		Sleep(500);
	}else {
		printf("出栈的数字为:%d\n",a);
		Sleep(500);
	}
}

void count() {//单独开辟栈空间的四则运算

//初期数据声明和初始化
	LinkStack *s_num,*s_opt; //获取栈指针--数字和运算符
	char opt[100];
	int i = 0,tmp = 0;
	int num1, num2,opt1;
	num1 = num2 = opt1 = -1;
	s_num = s_opt = NULL;
	init(&s_num);//初始化
	init(&s_opt);

//获取表达式和校验
	printf("输入四则表达式\n:");
	while(!input2(opt)) {
		printf("输入有误!!!\n");
		printf("字符包括0~9，+/*-()!!!\n");
		printf("+-/*不能连续使用!!!\n");
		printf("左右括号要匹配!!!\n");
	}

//表达式运算
	while(opt[i] != '\0' || isEmptyLStack(s_opt)) { //表达式没结束 或 操作符不为空
		
		if(opt[i] >= '0' && opt[i] <= '9') { //数字直接进数字栈中
			tmp = tmp * 10 + opt[i] - '0'; //连续数字问题
			i++;
			if(opt[i] < '0' || opt[i] > '9') {
				pushLStack(s_num, tmp); //数字进栈
				tmp = 0;
			}
		}else { //操作符
			getTopLStack(s_opt, opt1);
			if (opt1 == '(' && opt[i] ==')')	//直接出栈，不计算，栈顶为'(' ，表达式为')'
			{
				popLStack(s_opt,&opt1);	//括号直接出栈
				i++;
				continue;	//继续下一次循环
			}
			//	2、操作符进栈
			if ((isEmptyLStack(s_opt) == SUCCESS) 	//操作符栈为空
				|| (Priority(opt[i]) > Priority(opt1)) 	//表达式操作符优先级 > 栈顶操作符优先级
				|| ( num2 == '(' && opt[i] != ')' )) 	//栈顶为'(' 表达式当前值不为 ')'
			{
				pushLStack(s_opt, opt[i]);
				i++;
				continue;	//继续下一次循环
			}
			//	2、操作符出栈计算	
			if (Priority(opt[i]) <= Priority(opt1) 	//表达式操作符优先级 <= 栈顶操作符优先级
				|| (opt[i] == '0' && isEmptyLStack(s_opt) != SUCCESS) 	//表达式为空 && 操作符栈不为空
				|| opt[i] == ')')	//表达式为')'
			{
				popLStack(s_num, &num1); //数字栈顶出栈
				popLStack(s_num, &num2); //数字栈第二个数字出栈
				popLStack(s_opt, &opt1); //获取操作符
				switch (opt1)	//后出的数字在前
				{
					
					case '+':
						pushLStack(s_num, num2 + num1);
						break;
					case '-':
						pushLStack(s_num, num2 - num1);
						break;
					case '*':
						pushLStack(s_num, num2 * num1);
						break;
					case '/':
						pushLStack(s_num, num2 / num1);
						break;
				}	  
			}
		}
	}
	getTopLStack(s_num, num1);
	printf("表达式的结果为%d\n", num1);
}

int Priority(char ch) {//判断符号优先级

	switch (ch)
	{
		case '(':
			return 3;
		case '*':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
		default :
			return 0;
	}
}