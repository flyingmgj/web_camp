#include "qgsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void save() //生成并保存随机数
{
	FILE * fp;
	int num, size, *rander, i ,j = 0;
	if((fp=fopen("rand.txt","wb"))==NULL)// 以可写的方式打开当前目录下的.txt  
    {  
        printf("***不能打开此文件，请按任意键退出***\n");  
        exit(1);  
    }
	printf("请输入随机数个数:");
	scanf("%d",&size);
	//分配内存
	rander = (int *)malloc(size * sizeof(int));
	//遍历赋值
	for(i = 0; i < size; i++)
	{
		srand((unsigned)time(NULL)*i);
		num = rand()%1000;
		rander[i] = num;
		printf("%d\t",num);
		fprintf(fp,"%5d\n",rander[i]);		
	}
	system("pause");
	fclose(fp);
}

void load(int *rander, int size) //读取文件数据
{
	FILE * fp;
	int i = 0 ;
	if((fp=fopen("rand.txt","rb"))==NULL)// 以可写的方式打开当前目录下的.txt  
    {  
        printf("***不能打开此文件，请按任意键退出***\n");  
        exit(0);  

    }
	printf("正在加载随机数\n");
	while(!feof(fp) && i < size)
	{
		fscanf(fp,"%5d\n",rander[i++]);
	}
	printf("加载完成\n");
}

int main(){
	int num, a, size, *rander, i ,j = 0;\
	clock_t start, finish;
	double duration;
	printf("请输入测试所用的随机数个数:");
	scanf("%d",&size);
	rander = (int *)malloc(size * sizeof(int));
	for(i = 0; i < size; i++)
	{
		srand((unsigned)time(NULL)*i);
		num = rand()%1000;
		rander[i] = num;
//		printf("%d\t",num);	
	}
	printf("数据生成完毕，开始排序!\n");
/*	printf("开始测试插入排序\n");
	start = clock();
	insertSort(rander,size);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("插入排序用时:%.9lfs",duration);
*/	
/*	printf("开始测试归并排序\n");
	start = clock();
	MergeSort(rander,0,size-1,int *temp)
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("归并排序用时:%.9lfs",duration);
*/

/*	printf("开始测试快排\n");
	start = clock();
	QuickSort_Recursion(rander,0, size-1);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("快排用时:%.9lfs",duration);
*/	
/*	printf("开始测试快排非递归版\n");
	start = clock();
	QuickSort(rander,size);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("快排用时:%.9lfs",duration);
*/
	printf("开始测试快排非递归版\n");
	start = clock();
	QuickSort(rander,size);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("快排用时:%.9lfs",duration);

	return ;
}
