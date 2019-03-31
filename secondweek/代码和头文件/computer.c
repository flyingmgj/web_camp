#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int bool;
//��������ջ--�ڵ�
typedef struct Stack_num
{
	int num;
	struct Stack_num *next;
}Stack_num,*LinkStack_num_ptr;
//��������ջ
typedef struct LinkStack_num
{
	struct Stack_num* top;
	int count;
}LinkStack_num;
//�������ջ--�ڵ�
typedef struct Stack_opt
{
	char opt;
	struct Stack_opt *next;
}Stack_opt,*LinkStack_opt_ptr;

//�������ջ
typedef struct LinkStack_opt
{
	struct Stack_opt* top;
	int count;
}LinkStack_opt;

//������ջ
bool Push_num(LinkStack_num *S,int e)
{
	LinkStack_num_ptr s=(LinkStack_num_ptr)malloc(sizeof(Stack_num));
	s->num=e;
	s->next=S->top;
	S->top=s;
	S->count++;
	return OK;
} 

//���ֳ�ջ
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
//���Ž�ջ
bool Push_opt(LinkStack_opt *S,char e)
{
	LinkStack_opt_ptr s=(LinkStack_opt_ptr)malloc(sizeof(Stack_opt));
	s->opt=e;
	s->next=S->top;
	S->top=s;
	S->count++;
	return OK;
 }
//���ų�ջ
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
//���ȼ��жϺ���
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
//���ʽ��ȡ
bool input2(char str[1000])//��ȡ������--0~9 +-/*()
{	
	int i = 0;
	fflush(stdin);	  
	scanf("%s",str);
	fflush(stdin);
	while(str[i] != '\0'){
		if(str[i] < '(' || str[i] > '9' || str[i] == '.') {
			printf("ֻ������ĺϷ��ַ�����0~9 +-*/()\n"); 
			return ERROR;
		}		
		i++;
	}
	return OK;
}

bool check(char str[1000])//У��
{	
	int i = 0 ;
	int flag = 0; //��ʶ�������Ƿ�ƥ��
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
				printf("���ʽ���Ϸ�!!!\n");
				return ERROR;
			}
			continue;
		}else if(str[i] == '(')
		{
			if(((i != 0 && str[i-1] >= '0' && str[i-1] <= '9')|| (str[i+1] != '\0' && str[i+1] < '0' )) && i != 0 && str[i] != '('&& str[i+1] != '\0' && str[i+1] != ')')
			{
				printf("���ʽ��������ʹ�ò��Ϸ�!!!\n");
				return ERROR;
			}
			i++;
			flag++;
			continue;
		}else if(str[i] == ')')
		{ 
			if(	( i != 0 && str[i-1] < '0' )	|| (str[i+1] != '\0' && str[i+1] >= '0' && str[i+1] <= '9')) 
			{
				printf("���ʽ���ұ�����ʹ�ò��Ϸ�!!!\n");
				return ERROR;
			}
			flag--;
			i++;
		}
	}
	if(flag){
		printf("�������Ų�ƥ��!\n");
		return ERROR;
	}
	return OK;
}

void show1(LinkStack_num *s)	//��ʾ����ջȫ��Ԫ��
{
	LinkStack_num_ptr p = NULL;
	p = s->top;
	printf("����ջ:[");
	while(p)
	{
		printf("\"%d\",",p->num);
		p = p->next;
	}
		printf("]\t");		
	return ;
}

void show2(LinkStack_opt *s)	//��ʾ����ջȫ��Ԫ��
{
	LinkStack_opt_ptr p = NULL;
	p = s->top;
	printf("����ջ:[");
	while(p)
	{
		printf("\"%c\",",p->opt);
		p = p->next;
	}
		printf("]\t");		
	return ;
}

void show(char *s,int i)	//���ʽ
{
	if(s[i] != '\0' &&( i==0 || s[i-1] !='\0' ))
	printf("���ʽ:[%s]\n",s+i);		
	return ;
}


int main()
{
//���ݵ������ͳ�ʼ��
	char opt[1000];
	int i=0,tmp=0;
	char option;
	int num1,num2;
//����ջ�ĳ�ʼ��
	LinkStack_num* stack_num=(LinkStack_num*)malloc(sizeof(LinkStack_num));
	LinkStack_opt* stack_opt=(LinkStack_opt*)malloc(sizeof(LinkStack_opt));;
	stack_num->top=NULL;
	stack_num->count=0;
	stack_opt->top=NULL;
	stack_opt->count=0;
	
	printf("������ʽ: \n");
//	scanf("%s",opt);//��ȡ����---��Ҫ�Ż�

	while(!(input2(opt) && check(opt))) {}

	show1(stack_num);show2(stack_opt);show(opt,i);
	while(opt[i]!='\0'||stack_opt->top!=NULL)	//ջ�Ľ�������Ϊ��������ʽ�ҷ���ջ��Ԫ��
	{
		if(opt[i]>='0'&&opt[i]<='9') //��ȡ����--ֱ��������--�����������---
		{
			tmp = tmp*10+opt[i]-'0';//�����ۼ�

			i++;
			if(opt[i]<'0'||opt[i]>'9')//�����һλ�Ƿ�Ϊ����λ--����tmp
			{
				Push_num(stack_num,tmp);
				printf("��ջ����:");
				show1(stack_num);show2(stack_opt);show(opt,i);
				tmp = 0;
			}
		}
		else //����λ
		{
			//���1   ����ջΪ�� �����ջ��Ϊ'('�� ��ǰ���Ų�Ϊ'('------��ջ
			if(stack_opt->top==NULL||(stack_opt->top->opt=='('&&opt[i]!=')')||Priority(opt[i])>Priority(stack_opt->top->opt))
			{
				Push_opt(stack_opt,opt[i]);
				i++;
				printf("��ջ����:");
				show1(stack_num);show2(stack_opt);show(opt,i);
				continue;
			}
			//���2:()
			if(stack_opt->top->opt=='('&&opt[i]==')')
			{
				char temp;
				Pop_opt(stack_opt,&temp);
				i++;
				printf("()ƥ���������:");
				show1(stack_num);show2(stack_opt);show(opt,i);
				continue;
			}
			//���3:�����Ž�ջ �������ŷǷ���ջ��Ԫ||���������ջ����Ԫ��||���ȼ�С�ڵ���ջ��Ԫ��-------��Ҫ��ջ
			if((opt[i]=='\0'&&stack_opt->top!=NULL)||opt[i]==')'&&stack_opt->top->opt!='('||Priority(opt[i])<=Priority(stack_opt->top->opt))
			{
				Pop_opt(stack_opt,&option);//��ջ--�������ֲ���
				switch(option)
				{
					case '+':
						{
							Pop_num(stack_num,&num1);
							printf("��ջ����:\n");
							show1(stack_num);show2(stack_opt);show(opt,i);
							Pop_num(stack_num,&num2);
							printf("��ջ����:\n");
							show1(stack_num);show2(stack_opt);show(opt,i);
							Push_num(stack_num,(num1+num2));
							printf("��ջ����:");
							show1(stack_num);show2(stack_opt);show(opt,i);
							break;
						}
					case '-':
						{
							Pop_num(stack_num,&num1);
							printf("��ջ����:\n");
							show1(stack_num);show2(stack_opt);show(opt,i);
							Pop_num(stack_num,&num2);
							printf("��ջ����:\n");
							show1(stack_num);show2(stack_opt);show(opt,i);
							Push_num(stack_num,(num2-num1));
							printf("��ջ����:");
							show1(stack_num);show2(stack_opt);show(opt,i);
							break;
						}	
					case '*':
						{
							Pop_num(stack_num,&num1);
							printf("��ջ����:\n");
							show1(stack_num);show2(stack_opt);show(opt,i);
							Pop_num(stack_num,&num2);
							printf("��ջ����:\n");
							show1(stack_num);show2(stack_opt);show(opt,i);
							Push_num(stack_num,(num1*num2));
							printf("��ջ����:");
							show1(stack_num);show2(stack_opt);show(opt,i);
							break;
						}	
					case '/':
						{
							Pop_num(stack_num,&num1);
							printf("��ջ����:\n");
							show1(stack_num);show2(stack_opt);show(opt,i);
							Pop_num(stack_num,&num2);
							printf("��ջ����:\n");
							show1(stack_num);show2(stack_opt);show(opt,i);
							Push_num(stack_num,(num2/num1));
							printf("��ջ����:");
							show1(stack_num);show2(stack_opt);show(opt,i);
							break;
						}
				}
	
				 
			}
		}
	}
	printf("\nresult : %d\n",stack_num->top->num);
	printf("��ȡһ���ַ����˳�\n:");
	getchar();getchar();	
}
