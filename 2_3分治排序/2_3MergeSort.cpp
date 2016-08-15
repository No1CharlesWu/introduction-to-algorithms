#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<iostream>
using namespace std;

void Merge(int arr[],int p,int q,int r);//合并算法
void MergeSort(int arr[],int p,int r);//合并排序

int main()
{
	int arr[10] = {3,1,5,7,8,2,4,0,9,6};
	int arr2[11] = {1,3,5,7,8,2,4,0,10,9,6};

	MergeSort(arr,1,10);
	MergeSort(arr2,1,11);

	for(int i = 0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

	for(int i = 0;i<11;i++)
	{
		printf("%d ",arr2[i]);
	}
	printf("\n");

	return 0;
}

/*
分治排序算法：
输入：未排序的数组，数组元素的个数
输出：升序排序的数组

算法技巧：
分治排序分为三部分：
1.分解：将原问题分解成一系列子问题。
2.解决：用递归的方法，解决子问题。
3.合并：将子问题的结果合并成原问题的解。

合并排序的关键是：
对已排序的两个子数组进行合并：将一段A[p..q]和A[p+1..r]已排序的数组分解。
							  分解成两个数组。使用比较排序的方法合并。

使用递归的方法。

使用范围：排列大型数组。
*/
void Merge(int arr[],int p,int q,int r)//合并算法
{
	int i,j,k;
	int n1 = q-p+1;
	int n2 = r-q;
	int *L = new int[n1+1];		//开辟左右两个数组
	int *R = new int[n2+1];

	for(i = 0;i<n1;i++) 	L[i] = arr[p+i-1];//将arr[p..r] 赋值给左右数组L，R
	for(j = 0;j<n2;j++)     R[j] = arr[q+j];
	L[n1] = INT_MAX;			//将数组最后一位用无穷大代替，简化代码
	R[n2] = INT_MAX;

	for(i = j = 0,k = p-1;k<r;k++)
	{
		if(L[i] <= R[j])		//比较排序			
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
	}
	delete []L;					//删除数组释放内存
	delete []R;
}
void MergeSort(int arr[],int p,int r)//合并排序
{
	int q;
	if(p<r)
	{
		q = (p+r)/2;
		MergeSort(arr,p,q);
		MergeSort(arr,q+1,r);
		Merge(arr,p,q,r);
	}
}

