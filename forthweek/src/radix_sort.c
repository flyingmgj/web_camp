//基数排序

#define RADIX_size 10   //十个桶，表示每一位的十个数字
#define KEYNUM 5     //整数位数
int getNumInPos(int num, int pos)//获取数字第pos位上的值
{
	int temp = 1;
	for(int i = 0;i<pos-1;i++){
		temp*=10;
	}
	return (num / temp)%10
}
void radix_sort(int* pDataArray, int iDataNum)//数据和数据的数量
{
    int *radixArrays[RADIX_size];    //十个桶
    for (int i = 0; i < RADIX_size; i++)
    {
        radixArrays[i] = new int[iDataNum];//分配空间
        radixArrays[i][0] = 0;    //index为0处记录这组数据的个数
    }

    for (int pos = 1; pos <= KEYNUM; pos++)    //从个位开始到第KEYNUM位
    {
        for (int i = 0; i < iDataNum; i++)    //分配过程
        {
            int num = getNumInPos(pDataArray[i], pos);//获取数字第pos位上的值
            int index = ++radixArrays[num][0];//计数位+1
            radixArrays[num][index] = pDataArray[i];//存储数字
        }

        for (int i = 0, j =0; i < RADIX_size; i++) //写回到原数组中，复位radixArrays
        {
            for (int k = 1; k <= radixArrays[i][0]; k++)
                pDataArray[j++] = radixArrays[i][k];
            radixArrays[i][0] = 0;
        }
    }
}