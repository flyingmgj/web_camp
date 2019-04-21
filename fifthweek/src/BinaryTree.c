#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct queue
{
    struct BiTNode node[100];
    struct BiTNode* s;
    struct BiTNode* e;
};

/**
 *  @name        : Status InitBiTree(BiTree T);
 *  @description : ����ն�����T
 *  @param       : �����������T
 */
 Status InitBiTree(BiTree *T) {
	 (*T) = (BiTree) malloc (sizeof(BiTNode));
	 if(*T) return ERROR; //����ʧ��
	 //��ʼ������
	 (*T)->lchild = (*T)->rchild = NULL;
	 (*T)->data = 0;
	 return SUCCESS;
 }


/**
 *  @name        : Status DestroyBiTree(BiTree T);
 *  @description : �ݻٶ�����T
 *  @param       : �����������T
 */
Status DestroyBiTree(BiTree T) {
	if(T != NULL) {
		DestroyBiTree(T->lchild);
		DestroyBiTree(T->rchild);
		free(T);
		T = NULL;
	}
	return SUCCESS;
}

/**
 *  @name        : Status CreateBiTree(BiTree T, char* definition);
 *  @description : ���������T
 *  @param       : �����������T, ��������������ַ���definition
 */
Status CreateBiTree(BiTree *T, char* definition) {
	int i = 1;
	char x = '\0';
	x = definition[0];
	definition[0] = '\0';
	if(x == '\0') return SUCCESS;
	
    (*T) = (BiTree)malloc(sizeof(BiTNode));
    (*T)->data = x;
    (*T)->lchild = NULL;
    (*T)->rchild = NULL;

    if(x == '+' || x == '-' || x == '*' || x == '/')//�ǲ�������ǰ׺���ʽ�����һ���ַ�һ���ǲ���������������ĵݹ��ֹͣ�� 
    { 		
		while(definition[i] == '+' || definition[i] == '-' ||
			definition[i] == '*' || definition[i] == '/') i++;
		CreateBiTree(&(*T)->rchild,&definition[2*i]);
		CreateBiTree(&(*T)->lchild,&definition[1]);

    }
	return SUCCESS;
}

/**
 *  @name        : Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e)) {
	visit(T->data);
	if(T->lchild != NULL)PreOrderTraverse(T->lchild,visit(T->lchild->data));	
	if(T->rchild != NULL)PreOrderTraverse(T->rchild,visit(T->rchild->data));
	return SUCCESS;
}

/**
 *  @name        : Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));	
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e)) {
/*	if( T != NULL) {
		visit(T->data);
		InOrderTraverse(T->lchild,visit);
		InOrderTraverse(T->rchild,visit);
	}
	return SUCCESS;
*/
	if(T->lchild != NULL)PreOrderTraverse(T->lchild,visit(T->lchild->data));
	visit(T->data);
	if(T->rchild != NULL)PreOrderTraverse(T->rchild,visit(T->rchild->data));
	return SUCCESS;
}


/**
 *  @name        : Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e)));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e)) {
	if(T->lchild != NULL)PreOrderTraverse(T->lchild,visit(T->lchild->data));
	visit(T->data);
	if(T->rchild != NULL)PreOrderTraverse(T->rchild,visit(T->rchild->data));
	return SUCCESS;
}

void in(struct queue* a,struct BiTNode* b)
{
    *a->e = *b;
    a->e++; 
}
struct BiTNode* out(struct queue* a)
{
    struct BiTNode *tmp=(struct BiTNode*)malloc(sizeof(struct BiTNode));
    *tmp = *a->s;
    a->s++;
    return tmp;
}

/**
 *  @name        : Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e)) {
	struct queue q1;        //��������
	struct BiTNode* p;     //��ʱ���ָ��
    q1.s=&q1.node[0];       //��ʼ������
    q1.e=&q1.node[0];
    in(&q1,T);              //���ڵ����
    while(q1.e!=q1.s)       //�ж϶����Ƿ�Ϊ��
    {
        p = out(&q1);           //����
        printf("%d ",p->data);      //���ʽ��
        if(p->lchild != NULL)          
            in(&q1,p->lchild);        //��������
        if(p->rchild != NULL)
            in(&q1,p->rchild);       //�Ҷ������
    }
}
/**
 *  @name        : int Value(BiTree T);
 *  @description : �Թ������ǰ׺���ʽ��������ֵ
 *  @param       : �����������T
 *  @note        : ���ڽ��ṹ�������ø�Tagֵ��־������������������������
 *                 �ɸ�����Ҫ�������Ӳ���.
 */
int Value(BiTree T) { 
	if(T->data <= '9' && T->data >= '0') { //����
		return T->data - '0';
	}else  //���Ŵ���
		switch(T->data) {
				case '+':
					return Value(T->lchild) + Value(T->rchild);
				case '-':
					return Value(T->lchild) - Value(T->rchild);
				case '*':
					return Value(T->lchild) * Value(T->rchild);
				case '/':
					return Value(T->lchild) / Value(T->rchild);
				default :
					break;
		}
}