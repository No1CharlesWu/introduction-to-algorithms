#include<stdio.h>
#include<stdlib.h>
/*
ѡ�����⣺
���룺һ������n������ͬ�ģ����ļ���A ��һ���� i��1<=i<=n
�����Ԫ��x ����A ����ǡ����A�������� i-1 ��Ԫ��

�㷨���ɣ�
�Ϳ��������㷨�Ƚ�����
��������ֳ�A[p..q-1] ��A[q+1..r]
���A[q]���ǵ�i��Ԫ�أ�����A[p]��
�����i��Ԫ���ڵ������ݹ��ڵ���Ѱ�ҡ�

ʹ�÷�Χ��
�ٶȿ죬����ʱ���
*/

//������A[p..r]�ķָ�
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
