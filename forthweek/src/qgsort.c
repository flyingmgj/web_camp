#include "qgsort.h"
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <time.h>

//栈
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
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n){
	int i,j,v;
    for (i=1; i<n; i++) {
	//如果第i个元素小于第j个，则第j个向后移动
        for (v=a[i], j=i-1; j>=0 && v<a[j]; j--)
            a[j+1]=a[j];
        a[j+1]=v;
    }
}

/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp) {
	int i, j, m, n, k;
	//数据的初始化
	i = begin;
	j = mid + 1;
	m = mid;
	n = end;
	k = 0;
	temp = (int *)malloc(sizeof(int)*n);
	
	while( i < m && j <= n) { //将两个有序排序存储到承载指针内存块中
		if(a[j] <= a[j++])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}	
	//处理某一边拷贝完了，另一边还没拷贝完的情况
	while ( i <= m) { 
		temp[k++] = a[i++];
	}
	while ( j <= n) {  //
		temp[k++] = a[j++];
	}
	//承载指针内存块拷贝到数组中
	for(i = 0; i < k; i++) {
		a[begin + i ] = temp[i];
	}
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp) {
	if(begin < end) { //切分直到块为1即begin == last
		int mid = (begin + end) /2;
		MergeSort(a, begin, mid, temp);
		MergeSort(a, mid+1, end, temp);
		MergeArray(a, begin, mid, end,temp);
	}
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
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
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,int size) {
	int i, j, iStart, iLen, key;
	stStack stck;
	i = j = iStart = iLen = key = 0;
	
	if (size < 2) return;
	stck.iCount = 0 ;
	stck.stSort = NULL;

	//分配空间
	stck.stSort = (stSortFlag *)malloc(size * sizeof(stSortFlag));
	if(NULL == stck.stSort) {
		printf("分配空间失败");
		return ;
	}
	stck.stSort[stck.iCount].start = 0;
	stck.stSort[stck.iCount].len = size;
	++stck.iCount;

	/*
		用栈代替递归,每次用递归的时候均入栈
		每次运算的时候均出栈
		栈为空则完成排序
	*/
	while(stck.iCount) {
		--stck.iCount;//取一个排序--相当于出栈
		iStart = stck.stSort[stck.iCount].len;
		i = iStart;
		j = iStart + iLen - 1;

		//分割
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
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end) {
		int i = begin, j = end;
		int pivot = a[i];//选取基准值---并保存
		while( i < j ) {//基准值的切割--使得基准值左边均小于基准值，右边均大于基准值
		
			//右边开始遍历寻找比基准值小的数
			while(i < j && a[j] >= pivot) {
				j--;
			}
			//将寻找到的值填入上一次的坑位
			a[i] = a[j]; 
			//左边开始遍历寻找比基准值大的数
			while(i < j && a[i] <= pivot) {
				i++;
			}
			a[j] = a[i];
		}
		//此时 i == j 将基准值填入
		a[i] = pivot;
		return i;
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max) {
	int i, index, k;
	int * counter = (int *)malloc((max+1) * sizeof(int));
	int * b = (int *)malloc(size * sizeof(int));
	for(i = 0; i < max; i++) counter[i] = 0 ;//初始化为零
	for(i = 0; i < size; i++) counter[a[i]]++;//对应位加1
	for(i = 1; i < max; i++) counter[i] += counter[i-1];//叠加
	for(i = max - 1; i >= 0; i--) {	//反向填充
		k = a[i];
		index = counter[k]-1;
		b[index] = k;
		counter[k]--;
	}
	for(i = 0 ; i < size ;i++) a[i] = b[i]; 
}

int getNumInPos(int num, int pos)//获取数字第pos位上的值
{
	int temp = 1,i;
	for(i = 0; i<pos-1;i++){
		temp*=10;
	}
	return (num / temp)%10;
}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,int size) {
	const int RADIX_size = 10;
	const int KEYNUM = 5;
	int i, pos, j, k;
	int * radixArrays[10];    //十个桶
    for (i = 0; i < RADIX_size; i++)
    {
        radixArrays[i] = (int *)malloc(sizeof(int)*size);//分配空间
        radixArrays[i][0] = 0;    //index为0处记录这组数据的个数
    }

    for (pos = 1; pos <= KEYNUM; pos++)    //从个位开始到第KEYNUM位
    {
        for (i = 0; i < size; i++)    //分配过程
        {
            int num = getNumInPos(a[i], pos);//获取数字第pos位上的值
            int index = ++radixArrays[num][0];//计数位+1
            radixArrays[num][index] = a[i];//存储数字
        }

        for (i = 0, j =0; i < RADIX_size; i++) //写回到原数组中，复位radixArrays
        {
            for (k = 1; k <= radixArrays[i][0]; k++)
                a[j++] = radixArrays[i][k];
            radixArrays[i][0] = 0;
        }
    }
}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
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
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数-
 *  @param       : 数组指针a，数组长度size
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