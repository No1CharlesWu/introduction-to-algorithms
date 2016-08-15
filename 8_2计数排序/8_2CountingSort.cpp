#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;

/*
��������
����n������Ԫ���е�ÿһ�����ǽ���0��k֮����������˴�kΪĳ��������
�����������������С�

�ؼ��ʣ�
�������� A[0..n-1];
length[A] = n;
����������� B[0..n-1];
�ṩ���´洢���� C[0..k];

�㷨���ɣ�
��ÿһ������Ԫ��x��ȷ����С��x��Ԫ�ظ�����
�Ϳ��԰�xֱ�ӷŵ�����������������е�λ���ϡ�
�Ƚ����� A[] ��Ԫ���Ը�������ʽ��������� C[] �У�Ȼ���ۼ����� C[] ��
�ٰ� C[] �е�Ԫ��������λ�÷ŵ� B[] �����С�

ʵ��ʹ�ã�
���������ǷǱȽ������㷨��
��������֪����Ԫ�ز���������ĳ����ʱ�����á�
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
