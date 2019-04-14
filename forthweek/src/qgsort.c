#include "qgsort.h"
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <time.h>

//ջ
typedef struct sortFlag
{
	int start;
	int len;
}stSortFlag;
typedef struct st_Stack
{
	int iCount;
	stSortFlag* stSort;
}stStack;

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ��������
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n){
	int i,j,v;
    for (i=1; i<n; i++) {
	//�����i��Ԫ��С�ڵ�j�������j������ƶ�
        for (v=a[i], j=i-1; j>=0 && v<a[j]; j--)
            a[j+1]=a[j];
        a[j+1]=v;
    }
}

/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp) {
	int i, j, m, n, k;
	//���ݵĳ�ʼ��
	i = begin;
	j = mid + 1;
	m = mid;
	n = end;
	k = 0;
	temp = (int *)malloc(sizeof(int)*n);
	
	while( i < m && j <= n) { //��������������洢������ָ���ڴ����
		if(a[j] <= a[j++])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}	
	//����ĳһ�߿������ˣ���һ�߻�û����������
	while ( i <= m) { 
		temp[k++] = a[i++];
	}
	while ( j <= n) {  //
		temp[k++] = a[j++];
	}
	//����ָ���ڴ�鿽����������
	for(i = 0; i < k; i++) {
		a[begin + i ] = temp[i];
	}
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a,int begin,int end,int *temp) {
	if(begin < end) { //�з�ֱ����Ϊ1��begin == last
		int mid = (begin + end) /2;
		MergeSort(a, begin, mid, temp);
		MergeSort(a, mid+1, end, temp);
		MergeArray(a, begin, mid, end,temp);
	}
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int *a, int begin, int end) {
	if(begin < end) {
		int i = Partition(a, begin, end);
		QuickSort_Recursion(a, begin, i-1);
		QuickSort_Recursion(a, i+1, end);
	}
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int *a,int size) {
	int i, j, iStart, iLen, key;
	stStack stck;
	i = j = iStart = iLen = key = 0;
	
	if (size < 2) return;
	stck.iCount = 0 ;
	stck.stSort = NULL;

	//����ռ�
	stck.stSort = (stSortFlag *)malloc(size * sizeof(stSortFlag));
	if(NULL == stck.stSort) {
		printf("����ռ�ʧ��");
		return ;
	}
	stck.stSort[stck.iCount].start = 0;
	stck.stSort[stck.iCount].len = size;
	++stck.iCount;

	/*
		��ջ����ݹ�,ÿ���õݹ��ʱ�����ջ
		ÿ�������ʱ�����ջ
		ջΪ�����������
	*/
	while(stck.iCount) {
		--stck.iCount;//ȡһ������--�൱�ڳ�ջ
		iStart = stck.stSort[stck.iCount].len;
		i = iStart;
		j = iStart + iLen - 1;

		//�ָ�
		i = Partition(a, i, j);
		if((i-iStart) > 1) { 
			stck.stSort[stck.iCount].len = i - iStart;
			stck.iCount++;
		}

		if((iStart + iLen-1-i) > 1) {
			stck.stSort[stck.iCount].start = i+1;
			stck.stSort[stck.iCount].len = iStart + iLen -i -1;
			stck.iCount++;
		}
	}

	if(NULL != stck.stSort) free(stck.stSort);
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end) {
		int i = begin, j = end;
		int pivot = a[i];//ѡȡ��׼ֵ---������
		while( i < j ) {//��׼ֵ���и�--ʹ�û�׼ֵ��߾�С�ڻ�׼ֵ���ұ߾����ڻ�׼ֵ
		
			//�ұ߿�ʼ����Ѱ�ұȻ�׼ֵС����
			while(i < j && a[j] >= pivot) {
				j--;
			}
			//��Ѱ�ҵ���ֵ������һ�εĿ�λ
			a[i] = a[j]; 
			//��߿�ʼ����Ѱ�ұȻ�׼ֵ�����
			while(i < j && a[i] <= pivot) {
				i++;
			}
			a[j] = a[i];
		}
		//��ʱ i == j ����׼ֵ����
		a[i] = pivot;
		return i;
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int *a, int size , int max) {
	int i, index, k;
	int * counter = (int *)malloc((max+1) * sizeof(int));
	int * b = (int *)malloc(size * sizeof(int));
	for(i = 0; i < max; i++) counter[i] = 0 ;//��ʼ��Ϊ��
	for(i = 0; i < size; i++) counter[a[i]]++;//��Ӧλ��1
	for(i = 1; i < max; i++) counter[i] += counter[i-1];//����
	for(i = max - 1; i >= 0; i--) {	//�������
		k = a[i];
		index = counter[k]-1;
		b[index] = k;
		counter[k]--;
	}
	for(i = 0 ; i < size ;i++) a[i] = b[i]; 
}

int getNumInPos(int num, int pos)//��ȡ���ֵ�posλ�ϵ�ֵ
{
	int temp = 1,i;
	for(i = 0; i<pos-1;i++){
		temp*=10;
	}
	return (num / temp)%10;
}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a,int size) {
	const int RADIX_size = 10;
	const int KEYNUM = 5;
	int i, pos, j, k;
	int * radixArrays[10];    //ʮ��Ͱ
    for (i = 0; i < RADIX_size; i++)
    {
        radixArrays[i] = (int *)malloc(sizeof(int)*size);//����ռ�
        radixArrays[i][0] = 0;    //indexΪ0����¼�������ݵĸ���
    }

    for (pos = 1; pos <= KEYNUM; pos++)    //�Ӹ�λ��ʼ����KEYNUMλ
    {
        for (i = 0; i < size; i++)    //�������
        {
            int num = getNumInPos(a[i], pos);//��ȡ���ֵ�posλ�ϵ�ֵ
            int index = ++radixArrays[num][0];//����λ+1
            radixArrays[num][index] = a[i];//�洢����
        }

        for (i = 0, j =0; i < RADIX_size; i++) //д�ص�ԭ�����У���λradixArrays
        {
            for (k = 1; k <= radixArrays[i][0]; k++)
                a[j++] = radixArrays[i][k];
            radixArrays[i][0] = 0;
        }
    }
}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size) {
	int p0, p2, p, temp;
	p = p0 = 0;
	p2 = size-1;
	while(p == p2) {
		if(a[p] == 0 && p != p0) {
			temp = a[p];
			a[p] = a[p0];
			a[p0] = temp;
			p0++;
		}else if(a[p] == p2) {
			temp = a[p];
			a[p] = a[p2];
			a[p2] = temp;
			p2--;
		}else {
			p++;
		}
	}
}

/**
 *  @name        : ����
 *  @description : ��һ�������������ҵ���K��/С����-
 *  @param       : ����ָ��a�����鳤��size
 */
int find(int * a, int order, int size) {
	int i,*b; 	
	if(size <= 0 || order > size || order <= 0) return -1;
	b = (int *)malloc(sizeof(int)*size);
	for(i = 0; i < size; i++) {
		b[i] = a[i];		
	}
	QuickSort(b,size);
	return b[order - 1];
}