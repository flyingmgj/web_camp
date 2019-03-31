#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int bool;
//定义数字栈--节点
typedef struct Stack_num
{
	int num;
	struct Stack_num *next;
}Stack_num,*LinkStack_num_ptr;
//定义数字栈
typedef struct LinkStack_num
{
	struct Stack_num* top;
	int count;
}LinkStack_num;
//定义符号栈--节点
typedef struct Stack_opt
{
	char opt;
	struct Stack_opt *next;
}Stack_opt,*LinkStack_opt_ptr;

//定义符号栈
typedef struct LinkStack_opt
{
	struct Stack_opt* top;
	int count;
}LinkStack_opt;

//数字入栈
bool Push_num(LinkStack_num *S,int e)
{
	LinkStack_num_ptr s=(LinkStack_num_ptr)malloc(sizeof(Stack_num));
	s->num=e;
	s->next=S->top;
	S->top=s;
	S->count++;
	return OK;
} 

//数字出栈
bool Pop_num(LinkStack_num *S,int *e)
{
	LinkStack_num_ptr p;
	if(S->top==NULL)
	{
		return ERROR;
	}
	*e=S->top->num;
	p=S->top;
	S->top=S->top->next;
	free(p);
	S->count--;
	return OK; 
}
//符号进栈
bool Push_opt(LinkStack_opt *S,char e)
{
	LinkStack_opt_ptr s=(LinkStack_opt_ptr)malloc(sizeof(Stack_opt));
	s->opt=e;
	s->next=S->top;
	S->top=s;
	S->count++;
	return OK;
 }
//符号出栈
bool Pop_opt(LinkStack_opt *S,char *e)
{
	LinkStack_opt_ptr p;
	if(S->top==NULL)
	{
		return ERROR;
	}
	*e=S->top->opt;
	p=S->top;
	S->top=S->top->next;
	free(p);
	S->count--;
	return OK; 
}
//优先级判断函数
int Priority(char ch)
{
	switch(ch)
	{
		case '(':
			return 3;
		case '*':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
		default:
			return 0;
	}
}
//表达式获取
bool input2(char str[1000])//获取输入检测--0~9 +-/*()
{	
	int i = 0;
	fflush(stdin);	  
	scanf("%s",str);
	fflush(stdin);
	while(str[i] != '\0'){
		if(str[i] < '(' || str[i] > '9' || str[i] == '.') {
			printf("只能输入的合法字符包括0~9 +-*/()\n"); 
			return ERROR;
		}		
		i++;
	}
	return OK;
}

bool check(char str[1000])//校验
{	
	int i = 0 ;
	int flag = 0; //标识左括号是否被匹配
	while(str[i] != '\0') 
	{
		if(	str[i] >= '0' && str[i] <= '9')
		{
			i++;
			continue;
		}else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			i++;
			if( (str[i] <= '9' && str[i] >= '0') || str[i] == '(')
			{
				continue;
			}
			else 
			{
				printf("表达式不合法!!!\n");
				return ERROR;
			}
			continue;
		}else if(str[i] == '(')
		{
			if(((i != 0 && str[i-1] >= '0' && str[i-1] <= '9')|| (str[i+1] != '\0' && str[i+1] < '0' )) && i != 0 && str[i] != '('&& str[i+1] != '\0' && str[i+1] != ')')
			{
				printf("表达式的左括号使用不合法!!!\n");
				return ERROR;
			}
			i++;
			flag++;
			continue;
		}else if(str[i] == ')')
		{ 
			if(	( i != 0 && str[i-1] < '0' )	|| (str[i+1] != '\0' && str[i+1] >= '0' && str[i+1] <= '9')) 
			{
				printf("表达式的右边括号使用不合法!!!\n");
				return ERROR;
			}
			flag--;
			i++;
		}
	}
	if(flag){
		printf("左右括号不匹配!\n");
		return ERROR;
	}
	return OK;
}

void show1(LinkStack_num *s)	//显示数字栈全部元素
{
	LinkStack_num_ptr p = NULL;
	p = s->top;
	printf("数字栈:[");
	while(p)
	{
		printf("\"%d\",",p->num);
		p = p->next;
	}
		printf("]\t");		
	return ;
}

void show2(LinkStack_opt *s)	//显示符号栈全部元素
{
	LinkStack_opt_ptr p = NULL;
	p = s->top;
	printf("符号栈:[");
	while(p)
	{
		printf("\"%c\",",p->opt);
		p = p->next;
	}
		printf("]\t");		
	return ;
}

void show(char *s,int i)	//表达式
{
	if(s[i] != '\0' &&( i==0 || s[i-1] !='\0' ))
	printf("表达式:[%s]\n",s+i);		
	return ;
}


int main()
{
//数据的声明和初始化
	char opt[1000];
	int i=0,tmp=0;
	char option;
	int num1,num2;
//两个栈的初始化
	LinkStack_num* stack_num=(LinkStack_num*)malloc(sizeof(LinkStack_num));
	LinkStack_opt* stack_opt=(LinkStack_opt*)malloc(sizeof(LinkStack_opt));;
	stack_num->top=NULL;
	stack_num->count=0;
	stack_opt->top=NULL;
	stack_opt->count=0;
	
	printf("输入表达式: \n");
//	scanf("%s",opt);//获取部分---需要优化

	while(!(input2(opt) && check(opt))) {}

	show1(stack_num);show2(stack_opt);show(opt,i);
	while(opt[i]!='\0'||stack_opt->top!=NULL)	//栈的结束条件为遍历完表达式且符号栈无元素
	{
		if(opt[i]>='0'&&opt[i]<='9') //获取数字--直遇到符号--否则继续遍历---
		{
			tmp = tmp*10+opt[i]-'0';//数字累加

			i++;
			if(opt[i]<'0'||opt[i]>'9')//检测下一位是否为符号位--重置tmp
			{
				Push_num(stack_num,tmp);
				printf("入栈操作:");
				show1(stack_num);show2(stack_opt);show(opt,i);
				tmp = 0;
			}
		}
		else //符号位
		{
			//情况1   符号栈为空 或符号栈顶为'('且 当前符号不为'('------进栈
			if(stack_opt->top==NULL||(stack_opt->top->opt=='('&&opt[i]!=')')||Priority(opt[i])>Priority(stack_opt->top->opt))
			{
				Push_opt(stack_opt,opt[i]);
				i++;
				printf("入栈操作:");
				show1(stack_num);show2(stack_opt);show(opt,i);
				continue;
			}
			//情况2:()
			if(stack_opt->top->opt=='('&&opt[i]==')')
			{
				char temp;
				Pop_opt(stack_opt,&temp);
				i++;
				printf("()匹配抵消操作:");
				show1(stack_num);show2(stack_opt);show(opt,i);
				continue;
			}
			//情况3:右括号进栈 且左括号非符号栈顶元||遍历完符号栈还有元素||优先级小于等于栈顶元素-------需要出栈
			if((opt[i]=='\0'&&stack_opt->top!=NULL)||opt[i]==')'&&stack_opt->top->opt!='('||Priority(opt[i])<=Priority(stack_opt->top->opt))
			{
				Pop_opt(stack_opt,&option);//出栈--进行数字操作
				switch(option)
				{
					case '+':
						{
							Pop_num(stack_num,&num1);
							printf("出栈操作:\n");
							show1(stack_num);show2(stack_opt);show(opt,i);
							Pop_num(stack_num,&num2);
							printf("出栈操作:\n");
							show1(stack_num);show2(stack_opt);show(opt,i);
							Push_num(stack_num,(num1+num2));
							printf("入栈操作:");
							show1(stack_num);show2(stack_opt);show(opt,i);
							break;
						}
					case '-':
						{
							Pop_num(stack_num,&num1);
							printf("出栈操作:\n");
							show1(stack_num);show2(stack_opt);show(opt,i);
							Pop_num(stack_num,&num2);
							printf("出栈操作:\n");
							show1(stack_num);show2(stack_opt);show(opt,i);
							Push_num(stack_num,(num2-num1));
							printf("入栈操作:");
							show1(stack_num);show2(stack_opt);show(opt,i);
							break;
						}	
					case '*':
						{
							Pop_num(stack_num,&num1);
							printf("出栈操作:\n");
							show1(stack_num);show2(stack_opt);show(opt,i);
							Pop_num(stack_num,&num2);
							printf("出栈操作:\n");
							show1(stack_num);show2(stack_opt);show(opt,i);
							Push_num(stack_num,(num1*num2));
							printf("入栈操作:");
							show1(stack_num);show2(stack_opt);show(opt,i);
							break;
						}	
					case '/':
						{
							Pop_num(stack_num,&num1);
							printf("出栈操作:\n");
							show1(stack_num);show2(stack_opt);show(opt,i);
							Pop_num(stack_num,&num2);
							printf("出栈操作:\n");
							show1(stack_num);show2(stack_opt);show(opt,i);
							Push_num(stack_num,(num2/num1));
							printf("入栈操作:");
							show1(stack_num);show2(stack_opt);show(opt,i);
							break;
						}
				}
	
				 
			}
		}
	}
	printf("\nresult : %d\n",stack_num->top->num);
	printf("获取一个字符后退出\n:");
	getchar();getchar();	
}
