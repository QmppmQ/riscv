/*************************************************************************
    > File Name: conv.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 18 Sep 2019 01:34:21 AM PDT
 ************************************************************************/

#include<stdio.h>

//#include<iostream>

 

int main()

{

//	int array[7][7] = { {1,1,1,1,1,1,1},{1,1,1,1,1,1,1},{1,1,1,1,1,1,1},{1,1,1,1,1,1,1},{1,1,1,1,1,1,1},{1,1,1,1,1,1,1},{1,1,1,1,1,1,1}};

	int array[4][4] = { {1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1} };
	int kernal[3][3] = { {1,1,1},{1,1,1},{1,1,1} };

	int out[3][3] = { 0 };

	int temp;

// 
//	for (int row = 1; row <= 3; row++)
//
//	{
//
//		for (int col = 1; col <= 3; col++)
//
//		{
//
//			array[row][col] = rand() % 256;
//
//		}
//
//	}
//
	
//
//	for (int row = 0; row < 5; row++)
//
//	{
//
//		for (int col = 0; col < 5; col++)
//
//		{
//
//			printf("%d ", array[row][col]);
//
//		}
//
//		printf("\n");
//
//	}
//
//	printf("\n\n\n");
//
// 

	
//
//	for (int a = 0; a < 3; a++)
//
//	{
//
//		for (int b = 0; b < 3; b++)
//
//		{
//
//			printf("%d ", kernal[a][b]);
//
//		}
//
//		printf("\n");
//
//	}
//
// 
//
	int row = 0;

	int col = 0;

	for (int ax = 1; ax <= 2; ax++)

	{

		for (int ay = 1; ay <= 2; ay++)

		{

			temp = array[ax - 1][ay - 1] * kernal[0][0] + array[ax - 1][ay] * kernal[0][1] + array[ax - 1][ay + 1] * kernal[0][2] +

				array[ax][ay - 1] * kernal[1][0] + array[ax][ay] * kernal[1][1] + array[ax][ay + 1] * kernal[1][2] +

				array[ax + 1][ay - 1] * kernal[2][0] + array[ax + 1][ay] * kernal[2][1] + array[ax + 1][ay + 1] * kernal[2][2];

			out[row][col] = temp;

			col++;

			if (col == 2)

			{

				col = 0;

				row++;

				if (row == 2)

				{

					row = 0;


				}

			}

		}

	}

 
//
//	printf("\n\n\n");
//
// 
//
//	for (int row = 0; row < 2; row++)
//
//	{
//
//		for (int col = 0; col < 2; col++)
//
//		{
//
//			printf("%d ", out[row][col]);
//
//		}
//
//		printf("\n");
//
//	}
//
// 
//
// 	while (1);

}

