#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void InsertionSort(int arr[],int n);
int main()
{
	int arr[10] = {1,0,3,2,4,9,8,5,3,7};
	InsertionSort(arr,10);

	for(int i = 0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
/*
插入排序算法：
输入：未排序的数组，数组元素的个数
输出：升序排列的数组

算法技巧：
把数组分成A[1..j-1]和A[j..n]两部分，其中第一部分为已排序，第二部分未排序
key为待排序元素
比较key和数组A[1..j-1]的元素，将比key大的元素向后推送，将key插入其中。

使用范围:
排序个数较少的数组，速度较快，如果数据较大时不可使用
*/
void InsertionSort(int arr[],int n)
{
	int i,j;
	int key;
	for(j = 1;j<n;j++)
	{
		key = arr[j];
		i = j-1;
		while(i>=0&&arr[i]>key)
		{
			arr[i+1] = arr[i];
			i--;
		}
		arr[i+1] = key;
	}
}
