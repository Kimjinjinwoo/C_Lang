//�迭 ũ�� �Է� �޾Ƽ�
//�޸� �Ҵ�
//������ �Է��ϰ� ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int* pi = NULL;
	int size_;
	scanf("%d", &size_);

	pi = (int*)malloc(sizeof(int) * size_);

	for (int i = 0; i < size_; i++)
	{
		scanf("%d", pi + i);
	}

	
	if (pi == NULL)
	{
		printf("����");
		exit(1);
	}

	for (int i = 0; i < size_; i++)
	{

		printf("�ּҰ�: *pi = %p, ���� ��: p = %d\n", pi+i, *(pi+i));
	}

	

}