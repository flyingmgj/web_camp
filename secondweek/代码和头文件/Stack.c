#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


//˳��ջ
Status initStack(SqStack *s, int sizes){  //��ʼ��
	// sizesֵ�ж�
	if(sizes <= 0 ) {
		return ERROR;
	}
	s->elem = (ElemType *)malloc(sizes*sizeof(ElemType));
	if(!s) return ERROR;
	s->size = sizes;
	//��ʾջ����Ԫ��
	s->top = -1;
   	return SUCCESS;
}

Status isEmptyStack(SqStack *s) {//�п�
	if(s == NULL || s->top == -1) return ERROR;
	return SUCCESS;
}
Status getTopStack(SqStack *s, ElemType *e)//��ȡջ��Ԫ��
{
	if( s->top == -1 || s ) return ERROR;
	*e = s->elem[s->top];
	return SUCCESS;
}

Status clearStack(SqStack *s) {//���ջ

	if(s->top == -1 || s == NULL) return ERROR;
	s->top = -1;
	return SUCCESS;
}

Status destroyStack(SqStack *s) {//����ջ
	if(s == NULL ) return ERROR;
	free(s->elem);
	s->elem = NULL;
	s->size = 0;
	s->top = -1;
	return SUCCESS;
}

Status stackLength(SqStack *s, int *length) {//ջ����
	if(s == NULL ) return ERROR;
	(*length) = s->top + 1;
	return SUCCESS;
}

Status pushStack(SqStack *s, ElemType data) {//��ջ
//�ж��Ƿ����
	if(s == NULL || (s->top + 1) >= s->size ) return ERROR;
	s->elem[++(s->top)] = data;
	return SUCCESS;
}

Status popStack(SqStack *s, ElemType *data) {//��ջ
//����Ƿ�Ϊ��
	if(s == NULL || s->top == -1 ) return ERROR;
	*data = s->elem[(s->top)--];
	return SUCCESS;
}


//��ջ
Status initLStack(LinkStack **s) {//��ʼ��
	*s = (LinkStack *)malloc(sizeof(LinkStack));
	if(!s) return ERROR;
//��ʼ������
	(*s)->top = NULL;
	(*s)->count = 0;
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s) {//�п�
	if(!s || s->count > 0 ) return ERROR;
	return SUCCESS;
}

Status getTopLStack(LinkStack *s, ElemType *e) {//��ȡջ��Ԫ��
	if(!s || s->count == 0) return ERROR;
	*e = s->top->data;
	return SUCCESS;
}

Status clearLStack(LinkStack *s) {//���ջ
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

Status destroyLStack(LinkStack **s) {//����ջ
	if( !(*s) || !clearStack(*s))return ERROR;
	free(*s);
	*s = NULL;
	return SUCCESS;
}
Status LStackLength(LinkStack *s, int *length) {//ջ����
	if(!s) return ERROR;
	*length = s->count;
	return SUCCESS;
}

Status pushLStack(LinkStack *s, ElemType data) {//��ջ
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

Status popLStack(LinkStack *s, ElemType *data) {//��ջ
	LinkStackPtr p;
	if(!s || !s->count) return ERROR;
	s->count--;
	p = s->top;
	*data = p->data;
	s->top = p->next;
	free(p);
	return SUCCESS;
}


//��װ����---������ջ
void menu(){	//����
	system("color 87");
	printf("\n");  
    printf("____|________________________________________________|\n");  
    printf("____|________________________________________________|\n");  
    printf("____|_________________ջ��������_____________________|\n");  
    printf("____|************************************************|\n");
	printf("____|________________0���˳�_________________________|\n");    
    printf("____|________________1����ʼ��ջ_____________________|\n");  
    printf("____|________________2���ж��Ƿ�Ϊ��ջ_______________|\n");  
    printf("____|________________3���鿴ջ_______________________|\n");  
    printf("____|________________4���鿴ջ��Ԫ��_________________|\n");  
    printf("____|________________5�����ջ_______________________|\n");  
    printf("____|________________6������ջ_______________________|\n");
	printf("____|________________7����ջ����ջ��_________________|\n");
	printf("____|________________8����ջ��ѹջ��_________________|\n");
//	printf("____|________________9����������_____________________|\n");
    printf("____|************************************************|\n");  
    printf("____|________________________________________________|\n");
	printf("***ѡ����Ҫʹ�õĹ���,�����Ӧ����***\n:");     
    return ;  
}

Status input(ElemType* e) {//������
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

Status input2(char str[]) {//��ȡ������--0~9 +-/*()
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

void show(LinkStack *s) {//��ʾջȫ��Ԫ��
	LinkStackPtr p = NULL;
	int i = 0;
	if(!s) {
		printf("\t��ջ��Ϣ!!!���ȳ�ʼ��һ��ջ\n");
		Sleep(500);
	}else if(!s->count) {
		printf("��ջ��һ����ջ!!!\n");
		Sleep(500);
	}else {
		p = s->top;
		printf("ջ��");
		while(p){
			printf("<--%d",p->data);
			p = p->next;
		}
		printf("<--ջ��\n");
		printf("2����˳�!!!");
		Sleep(2000);
		
	}
	return ;
}

void init(LinkStack **s){	//��ʼ��
	if((*s) != NULL) {
		printf("�Ѿ���ʼ����һ��ջ!!!\n");
	}else {
		if(!initLStack(s)) printf("��ʼ��ʧ��");
		else printf("��ʼ���ɹ�!!!\n");
	}
	Sleep(500);
}
void isEmpty(LinkStack *s) {//�п�
	if(isEmptyLStack(s) == SUCCESS) {
		printf("��ջΪ��ջ!!!\n");
		Sleep(500);
	}else {
		printf("��ջ�ǿջ�ջ������!!!\n");
		Sleep(500);
	}
}

void getTop(LinkStack *s) {//��ȡջ��Ԫ��
	int e = 0;
	if(!getTopLStack(s, &e)) {
		printf("��ȡʧ��!!!\n");
		Sleep(500);
	}else {
		printf("ջ��Ԫ��---%d\n",e);
		Sleep(500);
	}
}

void clear(LinkStack *s) {//���ջ
	if(clearLStack(s) == ERROR) {
		printf("��ջ�޷����!!!\n");
		Sleep(500);
	}else {
		printf("ջ�����!!!\n");
		Sleep(500);
	}
}


void destroy(LinkStack **s) {//����ջ
	if( !(*s) ||destroyLStack(s) == ERROR) {
		printf("δ��ʼ��ջ���޷����!!!\n");
		Sleep(500);
	}else {
		printf("ջ������!!!\n");
		Sleep(500);
	}
}

void Length(LinkStack *s) {//ջ����
	int a = 0;
	if(!LStackLength(s,&a) == ERROR) {
		printf("δ��ʼ��ջ,���ȳ�ʼ��һ��ջ!!!%d\n");
		Sleep(500);
	}else {
		printf("ջ�ĳ���Ϊ:%d!!!%d\n",a);
		Sleep(500);
	}
}

void push(LinkStack *s) {//��ջ
	int a = 0;
	if( s == NULL ) {
		printf("δ��ʼ��ջ,���ȳ�ʼ��һ��ջ!!!\n");
		Sleep(500);
	}else {
		printf("������Ҫ��ջ��Ԫ��(����)\n:");
		while(!input(&a)){
			printf("�����ʽ����!����������\n:");
		}
		printf("��ջ������Ϊ:%d\n",a);
		if(pushLStack(s, a)) {
			printf("��ջ�ɹ�!!\n");
		}else {
			printf("��ջʧ��!!");
		}
		Sleep(500);
	}
}
void pop(LinkStack *s) {//��ջ
	int a = 0;
	if(popLStack(s, &a) == ERROR) {
		printf("δ��ʼ��ջ��ջ����Ԫ��!!!\n");
		Sleep(500);
	}else {
		printf("��ջ������Ϊ:%d\n",a);
		Sleep(500);
	}
}

void count() {//��������ջ�ռ����������

//�������������ͳ�ʼ��
	LinkStack *s_num,*s_opt; //��ȡջָ��--���ֺ������
	char opt[100];
	int i = 0,tmp = 0;
	int num1, num2,opt1;
	num1 = num2 = opt1 = -1;
	s_num = s_opt = NULL;
	init(&s_num);//��ʼ��
	init(&s_opt);

//��ȡ���ʽ��У��
	printf("����������ʽ\n:");
	while(!input2(opt)) {
		printf("��������!!!\n");
		printf("�ַ�����0~9��+/*-()!!!\n");
		printf("+-/*��������ʹ��!!!\n");
		printf("��������Ҫƥ��!!!\n");
	}

//���ʽ����
	while(opt[i] != '\0' || isEmptyLStack(s_opt)) { //���ʽû���� �� ��������Ϊ��
		
		if(opt[i] >= '0' && opt[i] <= '9') { //����ֱ�ӽ�����ջ��
			tmp = tmp * 10 + opt[i] - '0'; //������������
			i++;
			if(opt[i] < '0' || opt[i] > '9') {
				pushLStack(s_num, tmp); //���ֽ�ջ
				tmp = 0;
			}
		}else { //������
			getTopLStack(s_opt, opt1);
			if (opt1 == '(' && opt[i] ==')')	//ֱ�ӳ�ջ�������㣬ջ��Ϊ'(' �����ʽΪ')'
			{
				popLStack(s_opt,&opt1);	//����ֱ�ӳ�ջ
				i++;
				continue;	//������һ��ѭ��
			}
			//	2����������ջ
			if ((isEmptyLStack(s_opt) == SUCCESS) 	//������ջΪ��
				|| (Priority(opt[i]) > Priority(opt1)) 	//���ʽ���������ȼ� > ջ�����������ȼ�
				|| ( num2 == '(' && opt[i] != ')' )) 	//ջ��Ϊ'(' ���ʽ��ǰֵ��Ϊ ')'
			{
				pushLStack(s_opt, opt[i]);
				i++;
				continue;	//������һ��ѭ��
			}
			//	2����������ջ����	
			if (Priority(opt[i]) <= Priority(opt1) 	//���ʽ���������ȼ� <= ջ�����������ȼ�
				|| (opt[i] == '0' && isEmptyLStack(s_opt) != SUCCESS) 	//���ʽΪ�� && ������ջ��Ϊ��
				|| opt[i] == ')')	//���ʽΪ')'
			{
				popLStack(s_num, &num1); //����ջ����ջ
				popLStack(s_num, &num2); //����ջ�ڶ������ֳ�ջ
				popLStack(s_opt, &opt1); //��ȡ������
				switch (opt1)	//�����������ǰ
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
	printf("���ʽ�Ľ��Ϊ%d\n", num1);
}

int Priority(char ch) {//�жϷ������ȼ�

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