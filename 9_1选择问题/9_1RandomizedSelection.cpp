#include<stdio.h>
#include<stdlib.h>
/*
选择问题：
输入：一个包含n个（不同的）数的集合A 和一个数 i。1<=i<=n
输出：元素x 属于A ，他恰大于A中其他的 i-1 个元素

算法技巧：
和快速排序算法比较相似
快速排序分成A[p..q-1] 和A[q+1..r]
如果A[q]就是第i个元素，返回A[p]。
如果第i个元素在低区，递归在低区寻找。

使用范围：
速度快，期望时间短
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

int RandomizedSelect(int A[],int p,int r,int i)
{
	if(p==r)
		return A[p];

	int q = Partition(A,p,r);
	int k = q-p+1;
	if(i==k)
		return A[q];
	else if(i < k)
		return RandomizedSelect(A,p,q-1,i);
	else
		return RandomizedSelect(A,q+1,r,i-k);
}

int main()
{
	int arr[10] = {1,0,3,2,4,9,8,5,3,7};
	int num = RandomizedSelect(arr,0,9,1);
	printf("%d\n",num);
	return 0;
}
