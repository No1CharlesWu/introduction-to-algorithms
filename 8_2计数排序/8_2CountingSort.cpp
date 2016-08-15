#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;

/*
计数排序：
假设n个输入元素中的每一个都是介于0到k之间的整数，此处k为某个整数。
输出：升序排序的数列。

关键词：
输入数组 A[0..n-1];
length[A] = n;
存放排序结果的 B[0..n-1];
提供领事存储区的 C[0..k];

算法技巧：
对每一个输入元素x，确定出小于x的元素个数。
就可以把x直接放到它在最终输出数组中的位置上。
先将数组 A[] 的元素以个数的形式存放在数组 C[] 中，然后累加数组 C[] 。
再把 C[] 中的元素以最终位置放到 B[] 数组中。

实际使用：
计数排序是非比较排序算法。
适用于已知输入元素不超过最大的某个数时，可用。
*/

void CountingSort(int A[],int B[],int n,int k)
{
	int *C = new int[k+1];
	for(int j = 0;j<=k;j++)
	{
		C[j] = 0;
	}
	for(int j = 0;j<n;j++)
	{
		C[A[j]]++;
	}
	for(int i=1;i<=k;i++)
	{
		C[i] = C[i] +C[i-1];
	}
	for(int i = n-1;i>=0;i--)
	{
		B[C[A[i]]-1] = A[i];
		C[A[i]]--;
	}
}

int main()
{
	int arr[10] = {3,5,3,1,2,99,3,0,3,100};
	int B[10];
	CountingSort(arr,B,10,100);

	for(int i = 0;i<10;i++)
		printf("%d ",B[i]);
	printf("\n");
	return 0;
}
