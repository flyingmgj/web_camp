#include "LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <windows.h>

/**************************************************************
 *    Prototype Realize Section
 **************************************************************/

/**
 *  @name        : void InitLQueue(LQueue **Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue **Q, DataType dt) {
	(*Q) = (LQueue *)malloc(sizeof(LQueue));
	(*Q)->data = dt;
	(*Q)->front = NULL;
	(*Q)->rear = NULL;
	(*Q)->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue **Q) {
	free(*Q);
	*Q = NULL; 
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q) {
	if(Q->length == 0) return TRUE;
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */

Status GetHeadLQueue(LQueue *Q, void *e) {
	if(IsEmptyLQueue(Q) == TRUE) return FALSE;
	memcpy(e,Q->front->data,Dsize(Q->data));
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){	
	return Q->length;
}
/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data) {
	Node *L =(Node *)malloc(sizeof(Node));
	L->data =(void *)malloc(Dsize(Q->data));
	if(!L || !(L->data)) { //����ʧ��
		return FALSE;
	}
	//��ȡ����
	memcpy(L->data,data,Dsize(Q->data));
	L->next = NULL;
	//���	
	if(IsEmptyLQueue(Q) == TRUE){
		Q->front = L;
	}else{
		Q->rear->next = L;
	}
	Q->rear = L;
	Q->length++;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q, void *data) {
	Node *p = NULL;
	//�ж��Ƿ�δ��
	if(IsEmptyLQueue(Q) == TRUE) {
		return FALSE;
	}
	//��ȡ����
	memcpy(data,Q->front,Dsize(Q->data));
	//����
	if(Q->length == 1) {
		Q->rear = NULL;
	}
	p = Q->front->next;
	free(Q->front);
	Q->front = p;
	Q->length++;
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q) {
	//����ѡ���ͷָ�뿪ʼ�ͷ�(Ҳ��������ͬʱ�ͷ�)
	Node *L = NULL;
	while(Q->length) {
		L = Q->front->next;
		free(Q->front);
		Q->length--;
		Q->front = L; 
	}
	Q->rear = NULL;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q, DataType dt)) {
	Node *L = Q->front;
	if(foo == NULL)return FALSE;
	while(L != NULL) {
		foo(L,Q->data);
		L = L ->next;
	}
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 *  @notice      : None
 */
void LPrint(void *q, DataType dt) { 
	int type = dt;
	switch(type) {
		case 1:
			printf("**%d**",*(int *)q);
			break;
		case 2:
			printf("**%lf**",*(double *)q);
			break;
		case 3:
			printf("**%f**",*(float *)q);
			break;
		default:
			printf("**%c**",*(char *)q);
			break;
	}
}

/*
 * �����������Ͷ�Ӧ�Ĵ�С	
 */
int Dsize(DataType dt) {
	int size = dt;
	switch(size)
	{
	case 1:
		return sizeof(int);
		break;
	case 2:
		return sizeof(double);
		break;
	case 3:
		return sizeof(float);
		break;
	default:
		return sizeof(char);
		break;
	}
}

//��װ������ʹ��-------------------------------------------------------------------
//---------------------------------------------------------------

Status input(char str[100]){//��ȡ�Ƿ����ںϷ��ַ���1~9 - .��
	int i = 0;
	int flag = 0 ; //С�������
	for(i=0;i<100;i++)str[i] = '\0';
	fflush(stdin);
	scanf("%s",str);
	fflush(stdin);
	while(str[i] != '\0' && str[i] != '\n') {
		//����
		if(str[i] == '-' && i != 0) {
			printf("��ʽ����!\n");
			return FALSE;
		}
		if((str[i] < '0' || str[i]> '9') && str[i] != '.') {
			printf("��ʽ����!\n");
			return FALSE;
		}
		i++;
	}

	return TRUE;
}

Status input2(char *str,void * e,int type) {	//�ַ���ת������
	int i; double d; float f; char c;
	char *endptr = NULL;
	switch(type) {
	case 1:
		c =(int)strtol(str,&endptr,10);
		memcpy(e,&c,Dsize(type));
		break;
	case 2:
		d = strtod(str,&endptr);
		memcpy(e,&d,Dsize(type));
		break;
	case 3:
		f = (float)strtod(str,&endptr);
		memcpy(e,&f,Dsize(type));	
		break;
	case 4:
		c = str[0];
		memcpy(e,&c,Dsize(type));
		break;
	}
	if(endptr != NULL){
		printf("�����ʽ����!\n");
		return FALSE;
	}
	return TRUE;
}

Status input3(int * e) {//������--��ȡ����
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
	return TRUE;
}


void menu(){ //�˵�����
	system("color F7");
	printf("\n");  
    printf("____|________________________________________________|\n");  
    printf("____|________________________________________________|\n");  
    printf("____|_______________���в�������_____________________|\n");  
    printf("____|************************************************|\n");
	printf("____|________________0���˳�_________________________|\n");    
    printf("____|________________1����ʼ������___________________|\n");  
    printf("____|________________2���ж��Ƿ�Ϊ��_________________|\n");  
    printf("____|________________3���鿴���г���_________________|\n");  
    printf("____|________________4���鿴��ͷ_____________________|\n");  
    printf("____|________________5����ն���_____________________|\n");  
    printf("____|________________6�����ٶ���_____________________|\n");
	printf("____|________________7�����_________________________|\n");
	printf("____|________________8������_________________________|\n");
	printf("____|________________9���鿴����Ԫ��_________________|\n");
    printf("____|************************************************|\n");  
    printf("____|________________________________________________|\n");
	printf("***ѡ����Ҫʹ�õĹ���,�����Ӧ����***\n:");     
    return ;  	
}
void init(LQueue **Q, DataType dt) {//��ʼ��
	if(*Q != NULL) {
		printf("�ö����Ѿ���ʼ������!\n");
		return ;
	}
	InitLQueue(Q,dt);
	printf("��ʼ���ɹ�!\n");
}
void Destory(LQueue **Q) {//������ջ 
	if(Exist(*Q) == FALSE) {
		printf("����δ��ʼ���޷�����!\n");
		return;
	}
	DestoryLQueue(Q);
	printf("���ٳɹ�!\n");
}
void IsEmpty(const LQueue *Q) {//�п�
	if(Exist(Q) == FALSE) {
		printf("����δ��ʼ��!\n");
		return;
	}
	if(IsEmptyLQueue(Q) == TRUE) {	
		printf("����Ϊ��!\n");
	}else {
		printf("���зǿ�!\n");
	}
}
void GetHead(LQueue *Q) {//��ȡͷԪ��
	void *e;
	if(Exist(Q) == FALSE) {
		printf("����δ��ʼ��!\n");
		return;
	}
	if(GetHeadLQueue(Q,e) == FALSE) {
		printf("������Ԫ��!\n");
		return;
	}else {
		LPrint(Q->front, Q->data);
	}
}
void Length(LQueue *Q) {//���г���
	if(Exist(Q) == FALSE) {
		printf("����δ��ʼ��!\n");
		return;
	}
	printf("���г���Ϊ��%d\n",LengthLQueue(Q));
}
void EQ(LQueue *Q) { //���
	void *data = NULL;
	int i;
	char str[100] = "\0";
	if(Exist(Q) == FALSE) {
		printf("����δ��ʼ��!\n");
		return;
	}
	//��ȡ����
	printf("����Ҫ���������(����)!\n");
	while(!input3(&i)){
			printf("�����ʽ����,����������\n");
	}
	data = &i;

//	while( input(&str) == FALSE || input2(str,data,Q->data) == FALSE){
//		printf("��������!\n");
//	}
	
	if(EnLQueue(Q, data) == FALSE) {
		printf("���ʧ��");
		return ;
	}
	printf("��ӳɹ�!\n");
}
void DQ(LQueue *Q) {	//����
	void *data = NULL;
	if(Exist(Q) == FALSE) {
		printf("����δ��ʼ��!\n");
		return;
	}else if( DeLQueue(Q, data) == FALSE ) {
		printf("�ն����޷�����");
		return;
	}
	printf("���ӳɹ�!\n");
}
void Clear(LQueue *Q) {	//��ն���
	if(Exist(Q) == FALSE) {
		printf("����δ��ʼ��!\n");
		return;
	}
	ClearLQueue(Q);
	printf("��ճɹ�!\n");
}
void Traverse(const LQueue *Q){	//�����������
	if(Exist(Q) == FALSE) {
		printf("����δ��ʼ��!\n");
		return;
	}
	printf("����ͷ��<---");
	TraverseLQueue(Q, LPrint);
	printf("<---����β��");
}

Status Exist(LQueue *Q) {	//�������Ƿ����
	if(	Q == NULL )return FALSE;
	return TRUE;
}