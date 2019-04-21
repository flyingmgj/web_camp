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
 *  @description : 构造空二叉树T
 *  @param       : 二叉树根结点T
 */
 Status InitBiTree(BiTree *T) {
	 (*T) = (BiTree) malloc (sizeof(BiTNode));
	 if(*T) return ERROR; //分配失败
	 //初始化数据
	 (*T)->lchild = (*T)->rchild = NULL;
	 (*T)->data = 0;
	 return SUCCESS;
 }


/**
 *  @name        : Status DestroyBiTree(BiTree T);
 *  @description : 摧毁二叉树T
 *  @param       : 二叉树根结点T
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
 *  @description : 构造二叉树T
 *  @param       : 二叉树根结点T, 二叉树先序遍历字符串definition
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

    if(x == '+' || x == '-' || x == '*' || x == '/')//是操作符。前缀表达式的最后一个字符一定是操作数，所以下面的递归会停止。 
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
 *  @description : 先序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
 */
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e)) {
	visit(T->data);
	if(T->lchild != NULL)PreOrderTraverse(T->lchild,visit(T->lchild->data));	
	if(T->rchild != NULL)PreOrderTraverse(T->rchild,visit(T->rchild->data));
	return SUCCESS;
}

/**
 *  @name        : Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));	
 *  @description : 中序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
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
 *  @description : 后序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
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
 *  @description : 层序遍历二叉树T
 *  @param       : 二叉树根结点T, 对结点的操作函数visit
 */
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e)) {
	struct queue q1;        //创建队列
	struct BiTNode* p;     //临时结点指针
    q1.s=&q1.node[0];       //初始化队列
    q1.e=&q1.node[0];
    in(&q1,T);              //根节点入队
    while(q1.e!=q1.s)       //判断队列是否为空
    {
        p = out(&q1);           //出队
        printf("%d ",p->data);      //访问结点
        if(p->lchild != NULL)          
            in(&q1,p->lchild);        //左儿子入队
        if(p->rchild != NULL)
            in(&q1,p->rchild);       //右儿子入队
    }
}
/**
 *  @name        : int Value(BiTree T);
 *  @description : 对构造出的前缀表达式二叉树求值
 *  @param       : 二叉树根结点T
 *  @note        : 可在结点结构体中设置个Tag值标志数字与操作符来构造二叉树，
 *                 可根据需要自行增加操作.
 */
int Value(BiTree T) { 
	if(T->data <= '9' && T->data >= '0') { //数字
		return T->data - '0';
	}else  //符号处理
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