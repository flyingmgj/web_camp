/***************************************************************************************
 *    File Name                :    LQueue.h
 *    CopyRight                :
 *
 *    SYSTEM                    :   Mac OS
 *    Create Data                :    2019.4.2
 *    Author/Corportation        :  magee
 *
 *
 *--------------------------------Revision History--------------------------------------
 *    No    version        Data            Revised By            Item            Description
 *
 *
 ***************************************************************************************/

/**************************************************************
 *    Multi-Include-Prevent Section
 **************************************************************/
#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED
#include <stdio.h>
/**************************************************************
 *    Struct Define Section
 **************************************************************/
//链式队列结构
typedef enum
{
	Int=1, Double=2, Float=3, Char=4
}DataType;


typedef struct node
{
    void *data;                   //数据域指针
    struct node *next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node *front;                   //队头
    Node *rear;                    //队尾
    size_t length;            //队列长度
	DataType data;				//数据长度--用sizeof()来赋值
} LQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;
/**************************************************************
 *    Prototype Declare Section
 **************************************************************/

/**
 *  @name        : void InitLQueue(LQueue **Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue **Q, int size);

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue **Q);

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q);

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e);

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q);

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data);

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q, void *data);

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q);

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q));

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q,DataType dt);
/*
 * 计算数据类型对应的大小	
 */
int Dsize(DataType dt);

//分装函数的使用--------------------------------------

Status input(char *str);//获取是否属于合法（1~9 - .）
Status input2(char *str, void * e, int type);//字符串转化数字
Status input3(int * e);//字符串转整数

void menu(); //菜单界面
void init(LQueue **Q, DataType dt);//初始化
void Destory(LQueue **Q);//销毁链栈 
void IsEmpty(const LQueue *Q);//判空
void GetHead(LQueue *Q);//获取头元素
void Length(LQueue *Q);//队列长度
void EQ(LQueue *Q);//入队
void DQ(LQueue *Q);//出队
void Clear(LQueue *Q);//清空队列
void Traverse(const LQueue *Q);//遍历输出队列
Status Exist(LQueue *Q);//检测队列是否存在



/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // LQUEUE_H_INCLUDED