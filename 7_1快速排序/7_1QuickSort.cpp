#include<stdlib.h>
#include<stdio.h>
/*
快速排序：
输入：未排序的数组，要排序数组元素的起始下标和结束下标
输出：生序排列的数组

算法技巧：
和合并排序比较相似
1.分解：将数组A[p..r]分成L[p..q-1] 和R[p+1..r] 两块。其中L[]都小于A[q]，R[]都大于A[q]。
2.解决：通过递归调用快速排序
3.合并：无需合并！！

Partition 是快速排序的精髓：
以A[r]为主元，将大于A[r]的和小于A[r]的分割。

使用范围：
简单通俗易懂。
快速排序通常是用于排序的最佳使用选择，因为其平均性能相当好
它还能够进行就地排序，在虚拟环境中也能很好的工作
*/

//对数组A[p..r]的分割
int Partition(int A[],int p,int r)
{
	int x = A[r];
	int i = p-1;
	int j;
	for(j = p;j<=r-1;j++)
	{
		if(A[j]<x)
		{
			i++;
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	int temp = A[i+1];
	A[i+1] = A[r];
	A[r] = temp;
	
	return i+1;
}
//快速排序
void QuickSort(int A[],int p,int r)
{
	if(p<r)
	{
		int q = Partition(A,p,r);
		QuickSort(A,p,q-1);
		QuickSort(A,q+1,r);
	}
}


int main()
{
	int arr[10] = {1,0,3,2,4,9,8,5,3,7};
	QuickSort(arr,0,9);

	for(int i = 0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
