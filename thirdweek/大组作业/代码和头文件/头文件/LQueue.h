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
//��ʽ���нṹ
typedef enum
{
	Int=1, Double=2, Float=3, Char=4
}DataType;


typedef struct node
{
    void *data;                   //������ָ��
    struct node *next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node *front;                   //��ͷ
    Node *rear;                    //��β
    size_t length;            //���г���
	DataType data;				//���ݳ���--��sizeof()����ֵ
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
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue **Q, int size);

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue **Q);

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q);

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e);

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q);

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data);

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q, void *data);

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q);

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q));

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(void *q,DataType dt);
/*
 * �����������Ͷ�Ӧ�Ĵ�С	
 */
int Dsize(DataType dt);

//��װ������ʹ��--------------------------------------

Status input(char *str);//��ȡ�Ƿ����ںϷ���1~9 - .��
Status input2(char *str, void * e, int type);//�ַ���ת������
Status input3(int * e);//�ַ���ת����

void menu(); //�˵�����
void init(LQueue **Q, DataType dt);//��ʼ��
void Destory(LQueue **Q);//������ջ 
void IsEmpty(const LQueue *Q);//�п�
void GetHead(LQueue *Q);//��ȡͷԪ��
void Length(LQueue *Q);//���г���
void EQ(LQueue *Q);//���
void DQ(LQueue *Q);//����
void Clear(LQueue *Q);//��ն���
void Traverse(const LQueue *Q);//�����������
Status Exist(LQueue *Q);//�������Ƿ����



/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // LQUEUE_H_INCLUDED