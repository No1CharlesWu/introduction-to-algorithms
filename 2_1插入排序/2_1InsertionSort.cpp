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
���������㷨��
���룺δ��������飬����Ԫ�صĸ���
������������е�����

�㷨���ɣ�
������ֳ�A[1..j-1]��A[j..n]�����֣����е�һ����Ϊ�����򣬵ڶ�����δ����
keyΪ������Ԫ��
�Ƚ�key������A[1..j-1]��Ԫ�أ�����key���Ԫ��������ͣ���key�������С�

ʹ�÷�Χ:
����������ٵ����飬�ٶȽϿ죬������ݽϴ�ʱ����ʹ��
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
