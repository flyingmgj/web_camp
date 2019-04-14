#include "qgsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void save() //���ɲ����������
{
	FILE * fp;
	int num, size, *rander, i ,j = 0;
	if((fp=fopen("rand.txt","wb"))==NULL)// �Կ�д�ķ�ʽ�򿪵�ǰĿ¼�µ�.txt  
    {  
        printf("***���ܴ򿪴��ļ����밴������˳�***\n");  
        exit(1);  
    }
	printf("���������������:");
	scanf("%d",&size);
	//�����ڴ�
	rander = (int *)malloc(size * sizeof(int));
	//������ֵ
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

void load(int *rander, int size) //��ȡ�ļ�����
{
	FILE * fp;
	int i = 0 ;
	if((fp=fopen("rand.txt","rb"))==NULL)// �Կ�д�ķ�ʽ�򿪵�ǰĿ¼�µ�.txt  
    {  
        printf("***���ܴ򿪴��ļ����밴������˳�***\n");  
        exit(0);  

    }
	printf("���ڼ��������\n");
	while(!feof(fp) && i < size)
	{
		fscanf(fp,"%5d\n",rander[i++]);
	}
	printf("�������\n");
}

int main(){
	int num, a, size, *rander, i ,j = 0;\
	clock_t start, finish;
	double duration;
	printf("������������õ����������:");
	scanf("%d",&size);
	rander = (int *)malloc(size * sizeof(int));
	for(i = 0; i < size; i++)
	{
		srand((unsigned)time(NULL)*i);
		num = rand()%1000;
		rander[i] = num;
//		printf("%d\t",num);	
	}
	printf("����������ϣ���ʼ����!\n");
/*	printf("��ʼ���Բ�������\n");
	start = clock();
	insertSort(rander,size);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("����������ʱ:%.9lfs",duration);
*/	
/*	printf("��ʼ���Թ鲢����\n");
	start = clock();
	MergeSort(rander,0,size-1,int *temp)
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("�鲢������ʱ:%.9lfs",duration);
*/

/*	printf("��ʼ���Կ���\n");
	start = clock();
	QuickSort_Recursion(rander,0, size-1);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("������ʱ:%.9lfs",duration);
*/	
/*	printf("��ʼ���Կ��ŷǵݹ��\n");
	start = clock();
	QuickSort(rander,size);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("������ʱ:%.9lfs",duration);
*/
	printf("��ʼ���Կ��ŷǵݹ��\n");
	start = clock();
	QuickSort(rander,size);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("������ʱ:%.9lfs",duration);

	return ;
}
