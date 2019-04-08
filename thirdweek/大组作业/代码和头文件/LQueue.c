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
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
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
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue **Q) {
	free(*Q);
	*Q = NULL; 
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q) {
	if(Q->length == 0) return TRUE;
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */

Status GetHeadLQueue(LQueue *Q, void *e) {
	if(IsEmptyLQueue(Q) == TRUE) return FALSE;
	memcpy(e,Q->front->data,Dsize(Q->data));
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){	
	return Q->length;
}
/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data) {
	Node *L =(Node *)malloc(sizeof(Node));
	L->data =(void *)malloc(Dsize(Q->data));
	if(!L || !(L->data)) { //分配失败
		return FALSE;
	}
	//获取数据
	memcpy(L->data,data,Dsize(Q->data));
	L->next = NULL;
	//入队	
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
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q, void *data) {
	Node *p = NULL;
	//判断是否未空
	if(IsEmptyLQueue(Q) == TRUE) {
		return FALSE;
	}
	//获取数据
	memcpy(data,Q->front,Dsize(Q->data));
	//出队
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
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q) {
	//这里选择从头指针开始释放(也可以两端同时释放)
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
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
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
 *    @description : 操作函数
 *    @param         q 指针q
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
 * 计算数据类型对应的大小	
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

//分装函数的使用-------------------------------------------------------------------
//---------------------------------------------------------------

Status input(char str[100]){//获取是否属于合法字符（1~9 - .）
	int i = 0;
	int flag = 0 ; //小数点个数
	for(i=0;i<100;i++)str[i] = '\0';
	fflush(stdin);
	scanf("%s",str);
	fflush(stdin);
	while(str[i] != '\0' && str[i] != '\n') {
		//符号
		if(str[i] == '-' && i != 0) {
			printf("格式错误!\n");
			return FALSE;
		}
		if((str[i] < '0' || str[i]> '9') && str[i] != '.') {
			printf("格式错误!\n");
			return FALSE;
		}
		i++;
	}

	return TRUE;
}

Status input2(char *str,void * e,int type) {	//字符串转化数字
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
		printf("输入格式有误!\n");
		return FALSE;
	}
	return TRUE;
}

Status input3(int * e) {//输入检测--获取数字
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


void menu(){ //菜单界面
	system("color F7");
	printf("\n");  
    printf("____|________________________________________________|\n");  
    printf("____|________________________________________________|\n");  
    printf("____|_______________队列操作测试_____________________|\n");  
    printf("____|************************************************|\n");
	printf("____|________________0、退出_________________________|\n");    
    printf("____|________________1、初始化队列___________________|\n");  
    printf("____|________________2、判断是否为空_________________|\n");  
    printf("____|________________3、查看队列长度_________________|\n");  
    printf("____|________________4、查看队头_____________________|\n");  
    printf("____|________________5、清空队列_____________________|\n");  
    printf("____|________________6、销毁队列_____________________|\n");
	printf("____|________________7、入队_________________________|\n");
	printf("____|________________8、出队_________________________|\n");
	printf("____|________________9、查看队列元素_________________|\n");
    printf("____|************************************************|\n");  
    printf("____|________________________________________________|\n");
	printf("***选择你要使用的功能,输入对应数字***\n:");     
    return ;  	
}
void init(LQueue **Q, DataType dt) {//初始化
	if(*Q != NULL) {
		printf("该队列已经初始化过了!\n");
		return ;
	}
	InitLQueue(Q,dt);
	printf("初始化成功!\n");
}
void Destory(LQueue **Q) {//销毁链栈 
	if(Exist(*Q) == FALSE) {
		printf("队列未初始化无法销毁!\n");
		return;
	}
	DestoryLQueue(Q);
	printf("销毁成功!\n");
}
void IsEmpty(const LQueue *Q) {//判空
	if(Exist(Q) == FALSE) {
		printf("队列未初始化!\n");
		return;
	}
	if(IsEmptyLQueue(Q) == TRUE) {	
		printf("队列为空!\n");
	}else {
		printf("队列非空!\n");
	}
}
void GetHead(LQueue *Q) {//获取头元素
	void *e;
	if(Exist(Q) == FALSE) {
		printf("队列未初始化!\n");
		return;
	}
	if(GetHeadLQueue(Q,e) == FALSE) {
		printf("队列无元素!\n");
		return;
	}else {
		LPrint(Q->front, Q->data);
	}
}
void Length(LQueue *Q) {//队列长度
	if(Exist(Q) == FALSE) {
		printf("队列未初始化!\n");
		return;
	}
	printf("队列长度为：%d\n",LengthLQueue(Q));
}
void EQ(LQueue *Q) { //入队
	void *data = NULL;
	int i;
	char str[100] = "\0";
	if(Exist(Q) == FALSE) {
		printf("队列未初始化!\n");
		return;
	}
	//获取数据
	printf("输入要插入的数据(整数)!\n");
	while(!input3(&i)){
			printf("输入格式错误,请重新输入\n");
	}
	data = &i;

//	while( input(&str) == FALSE || input2(str,data,Q->data) == FALSE){
//		printf("重新输入!\n");
//	}
	
	if(EnLQueue(Q, data) == FALSE) {
		printf("入队失败");
		return ;
	}
	printf("入队成功!\n");
}
void DQ(LQueue *Q) {	//出队
	void *data = NULL;
	if(Exist(Q) == FALSE) {
		printf("队列未初始化!\n");
		return;
	}else if( DeLQueue(Q, data) == FALSE ) {
		printf("空队列无法出队");
		return;
	}
	printf("出队成功!\n");
}
void Clear(LQueue *Q) {	//清空队列
	if(Exist(Q) == FALSE) {
		printf("队列未初始化!\n");
		return;
	}
	ClearLQueue(Q);
	printf("清空成功!\n");
}
void Traverse(const LQueue *Q){	//遍历输出队列
	if(Exist(Q) == FALSE) {
		printf("队列未初始化!\n");
		return;
	}
	printf("队列头部<---");
	TraverseLQueue(Q, LPrint);
	printf("<---队列尾部");
}

Status Exist(LQueue *Q) {	//检测队列是否存在
	if(	Q == NULL )return FALSE;
	return TRUE;
}