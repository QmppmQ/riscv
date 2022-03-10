#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
//#include "cnn.h"
//mat.h
#define MaxPool 1
#pragma once
#ifndef __MAT_
#define __MAT_

#define full 0
#define same 1
#define valid 2

typedef struct Mat2DSize {
	int c; // w
	int r; // h
}nSize;


int** transpose_matrix(int **input, int c, int r);

int* conv_noreshape(int **in_addr,int **wt,int m);

void MaxPooling_noreshape(int** output,int* input,int inputSize,int bias);

void addmat_1d(int* res, int* mat1, int* mat2, int m);

void conv23(int model,int *addr);
void wb23(int *addr);
void w_wb(int rank, int value);
void max_pooling();
void mp_wb(int *addr);
void mp_ri(int *addr);
void relu(int bias);



#endif

//cnn.h
// conv layer
typedef struct convolutional_layer {
	

	//w is a 4d matrix, kernel_size*kernel_size*inChannels*outChannels*	
	int**** mapData;
	//b
	int* basicData;
	// the input of active function输入矩阵
	int*** v;
	// the output of active function输出矩阵
	int*** y;
}CovLayer;

// pooling layer
typedef struct pooling_layer {
	
	//the output data
	int*** y;
}PoolLayer;

// full connect layer
typedef struct fc_layer {
	

	int** wData; // w(inputNum*outputNum)
	int* basicData;   //b(outputNum)
	int* y;

}FcLayer;
typedef struct fl_layer {
	
	int** v;
	int* y;

}FlLayer;

// output layer
typedef struct out_layer {
	
	int** wData; // w(inputNum*outputNum)
	int* basicData;   //b(outputNum)
	int* outputdata;
}OutLayer;


int activation_relu(int input, int bas);
int activation_no_relu(int input, int bas);
void MaxPooling(int** output, nSize outputSize, int** input, nSize inputSize, int kernel_size, int stride);
void read_file_fc(char* filename, int a, int b, FcLayer* fc);
void read_file_out(char* filename, int a, int b, OutLayer* fc);
void read_file_conv(char* filename, int a, int b, int c, int d, CovLayer* conv);
int** read_image(char* filename);
int*** input(int** inputData, char* Filename, int inputWidth, int inputHeight, int kernel_size, int inChannels, int outChannels);
int*** conv(int*** inputData, char* Filename, int inputWidth, int inputHeight, int kernel_size, int inChannels, int outChannels);
int*** pool(int*** inputData, int inputWidth, int inputHeight, int poolType, int kernel_size, int inChannels, int outChannels, int stride);
int* flatten(int*** inputData, int inputWeight, int inputHeight, int inChannels, int outputNum);
int* fc(int* inputData, char* filename, int inputNum, int outputNum);
void* output(int* inputData, char* filename, int inputNum, int outputNum, char* filename1);
//mat.c
//将乘结果累加
void addmat_1d(int* res, int* mat1, int* mat2, int m)
{
	for (int i = 0; i < m; i++)
	{
			res[i] = mat1[i] + mat2[i];
	}
}

int* conv_noreshape(int **in_addr,int **wt,int m) {
	int w = m;
	int **b;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			w_wb(3*i+j+1,wt[i][j]);
		}
	}
	int balance_num;
	if(m%2==0){
		;
	}
	else{
		b = (int**)malloc((m+1) * sizeof(int*));
		for (int i = 0; i < m+1; i++){
			b[i] = (int*)malloc((m+1) * sizeof(int));
		}
		for(int i=0; i<m; i++){
			for(int j=0; j<m; j++){
				b[i][j] = in_addr[i][j];
			}
			// if(i>1){
			// 	balance_num = -(wt[0][0]*b[i-2][m-2] + wt[0][1]*b[i-2][m-1] + \
			// 	wt[0][2]*b[i-2][m] + wt[1][0]*b[i-1][m-2] + wt[1][1]*b[i-1][m-1] +\
			// 	wt[1][2]*b[i-1][m] + wt[2][0]*b[i][m-2] + wt[2][1]*b[i][m-1])-1000000;
			// 	b[i][m] = balance_num/wt[2][2];
			// }
			// else{
				b[i][m] = 0;
			// }

		}
		for(int k=0; k<m+1; k++){
			// if(k>1){
			// 	balance_num = -(wt[0][0]*b[m-2][k-2] + wt[0][1]*b[m-2][k-1] + \
			// 	wt[0][2]*b[m-2][k] + wt[1][0]*b[m-1][k-2] + wt[1][1]*b[m-1][k-1] +\
			// 	wt[1][2]*b[m-1][k] + wt[2][0]*b[m][k-2] + wt[2][1]*b[m][k-1])-1000000;
			// 	b[m][k]=balance_num/wt[2][2];
			// }
			// else{
				b[m][k] = 0;
			// }
		}
	}

	if(m%2==0){}
	else{
		w = m+1;
	}

	int row_step = (w - 4) / 2 +1 ;
	int col_step = row_step;
	int* a = (int*)malloc(16*row_step*col_step * sizeof(int));
	int x;
	if(m%2==0){
		for(int i=0; i<2*col_step; i+=2){
			for(int j=0;j<2*row_step;j+=2){
				x = 8*(j+row_step*i);
				a[x] = in_addr[i][j];
				a[1+x] = in_addr[i][j+1];
				a[2+x] = in_addr[i][j+2];
				a[3+x] = in_addr[i][j+3];
				a[4+x] = in_addr[i+1][j];
				a[5+x] = in_addr[i+1][j+1];
				a[6+x] = in_addr[i+1][j+2];
				a[7+x] = in_addr[i+1][j+3];
				a[8+x] = in_addr[i+2][j];
				a[9+x] = in_addr[i+2][j+1];
				a[10+x] = in_addr[i+2][j+2];
				a[11+x] = in_addr[i+2][j+3];
				a[12+x] = in_addr[i+3][j];
				a[13+x] = in_addr[i+3][j+1];
				a[14+x] = in_addr[i+3][j+2];
				a[15+x] = in_addr[i+3][j+3];
			}
		}
	}
	else{
		for(int i=0; i<2*col_step; i+=2){
			for(int j=0;j<2*row_step;j+=2){
				x = 8*(j+row_step*i);
				a[x] = b[i][j];
				a[1+x] = b[i][j+1];
				a[2+x] = b[i][j+2];
				a[3+x] = b[i][j+3];
				a[4+x] = b[i+1][j];
				a[5+x] = b[i+1][j+1];
				a[6+x] = b[i+1][j+2];
				a[7+x] = b[i+1][j+3];
				a[8+x] = b[i+2][j];
				a[9+x] = b[i+2][j+1];
				a[10+x] = b[i+2][j+2];
				a[11+x] = b[i+2][j+3];
				a[12+x] = b[i+3][j];
				a[13+x] = b[i+3][j+1];
				a[14+x] = b[i+3][j+2];
				a[15+x] = b[i+3][j+3];
			}
		}
	}

	int* c = (int*)malloc((w-2)*(w-2) * sizeof(int));
	int *pc = &c[0];

	int *addr = &a[0];

	for(int j=0;j<row_step*col_step;j++){
			if((j%row_step)==0){
				conv23(0,addr+16*j);
			}
			else{
				conv23(1,addr+16*j);
			}
			wb23(pc+4*j);
	}
	int y,z;
	if(m%2!=0){
		for(int i=1; i<(w-2)/2+1;i++){
			z = (w-2)*2*i;
			y = (w-2)*(w-4)+4*i;
			*(pc+z-3)=-1000000;
			*(pc+z-1)=-1000000;
			*(pc+y-2) = -1000000;
			*(pc+y-1) = -1000000;
		}
	}

	return c;
}

int** transpose_matrix(int** input, int c, int r)
{
	int** output;
	output = (int**)malloc(sizeof(int*) * r);
	int i, j, k;
	for (i = 0; i < r; i++)
	{
		output[i] = (int*)malloc(sizeof(int) * c);
		for (j = 0; j < c; j++)
		{
			output[i][j] = input[j][i];
		}
	}
	return output;
}
int activation_relu(int input, int bias)
{
	int temp = input + bias;
	return (temp > 0) ? temp : 0;
}


void MaxPooling(int** output, nSize outputSize, int** input, nSize inputSize, int kernel_size, int stride)
{
	int i, j, m, n;
	int t_m, t_n;
	t_m = t_n = 0;
	int sum;
	int count = 0;

	for (i = 0; i < outputSize.r; i++)
	{
		for (j = 0; j < outputSize.c; j++)
		{
			sum = 0.0;

			for (m = t_m; m < (t_m + kernel_size); m++)
			{
				for (n = t_n; n < (t_n + kernel_size); n++)
				{
					if (m > (inputSize.r - 1) || n > (inputSize.c - 1));
					else
					{
						if (sum < input[m][n])
						{
							sum = input[m][n];
						}
					}
				}
			}
			output[i][j] = sum;
			t_n = t_n + stride;
		}
		t_m = t_m + stride;
		t_n = 0;
	}
}

// void MaxPooling(int** output, nSize outputSize, int** input, nSize inputSize, int kernel_size, int stride){
// 	// int maxpool_s;
// 	// int maxpool_e;
// 	// int padding_s;
// 	// int padding_e;
// 	// int reshape1_s;
// 	// int reshape1_e;
// 	// int reshape2_s;
// 	// int reshape2_e;
// 	int null;
// 	int in1=0;
// 	int in2=0;
// 	// __asm__ __volatile__(
// 	// "rdcycle %[rdcycle]"
// 	// :[rdcycle] "=r"(maxpool_s)
// 	// );
// 	int m = inputSize.c;
// 	int *a;
// 	int *c;
// 	if(m%2==0){
// 		a = (int*)malloc(m*m * sizeof(int));
// 		c = (int*)malloc((m/2)*(m/2) * sizeof(int));
// 	}
// 	else{
// 		a = (int*)malloc((m+1)*(m+1) * sizeof(int));
// 		c = (int*)malloc(((m+1)/2)*((m+1)/2) * sizeof(int));
// 	}
// 	int *addr_in = &a[0];
// 	int *addr_out = &c[0];
// 	int **b;
// 	int y;
	

// 	if(m%2 == 0){
// 		// __asm__ __volatile__(
// 		// "rdcycle %[rdcycle]"
// 		// :[rdcycle] "=r"(reshape1_s)
// 		// );
// 		for(int i=0; i<m; i+=2){
// 			for(int j=0;j<m;j+=2){
// 				y = 2*(i*m/2+j);
// 				a[y] = input[i][j];
// 				a[y+1] = input[i][j+1];
// 				a[y+2] = input[i+1][j];
// 				a[y+3] = input[i+1][j+1];
// 			}
// 		}
// 		// __asm__ __volatile__(
// 		// "rdcycle %[rdcycle]"
// 		// :[rdcycle] "=r"(reshape1_e)
// 		// );
// 	}
// 	else{
// 		m = m+1;
// 		// __asm__ __volatile__(
// 		// "rdcycle %[rdcycle]"
// 		// :[rdcycle] "=r"(padding_s)
// 		// );
// 		b = (int**)malloc(m * sizeof(int*));
// 		for (int i = 0; i < m; i++){
// 			b[i] = (int*)malloc(m * sizeof(int));
// 		}	
// 		for(int i=0; i<m-1; i++){
// 			for(int j=0; j<m-1; j++){
// 				b[i][j] = input[i][j];
// 			}
// 			b[i][m-1] = 0;
// 		}
// 		for(int k=0; k<m; k++){
// 			b[m-1][k] = 0;
// 		}
// 		// __asm__ __volatile__(
// 		// "rdcycle %[rdcycle]"
// 		// :[rdcycle] "=r"(padding_e)
// 		// );
// 		// __asm__ __volatile__(
// 		// "rdcycle %[rdcycle]"
// 		// :[rdcycle] "=r"(reshape2_s)
// 		// );
// 		for(int i=0; i<m; i+=2){
// 			for(int j=0;j<m;j+=2){
// 				y = 2*(i*(m)/2+j);
// 				a[y] = b[i][j];
// 				a[y+1] = b[i][j+1];
// 				a[y+2] = b[i+1][j];
// 				a[y+3] = b[i+1][j+1];
// 			}
// 		}
// 		// __asm__ __volatile__(
// 		// "rdcycle %[rdcycle]"
// 		// :[rdcycle] "=r"(reshape2_e)
// 		// );
// 	}
// 	for(int i=0; i<(m/2)*(m/2);i++){
// 		mp_ri(addr_in+4*i);
// 		// relu();
// 		__asm__ __volatile__(
// 		"addi zero,zero,0\n"
// 		".insn r 0x77, 3, 0, %[null], %[in1], %[in2]"
// 		:[null] "=r"(null)
// 		:[in1]"r"(in1),[in2]"r"(in2)
// 		);
// 		// max_pooling();
// 		__asm__ __volatile__(
// 		"addi zero,zero,0\n"
// 		".insn r 0x77, 2, 0, %[null], %[in1], %[in2]"
// 		:[null] "=r"(null)
// 		:[in1]"r"(in1),[in2]"r"(in2)
// 		);
// 		mp_wb(addr_out+i);
// 	}

// 	for(int i=0; i<m/2; i++){
// 		for(int j=0;j<m/2;j++){
// 			output[i][j] = c[i*(m/2)+j];
// 		}
// 	}
// 	// __asm__ __volatile__(
// 	// "rdcycle %[rdcycle]"
// 	// :[rdcycle] "=r"(maxpool_e)
// 	// );
// 	// printf("maxpool cycle=%d\n",maxpool_e-maxpool_s);
// 	// printf("padding cycle=%d\n",padding_e-padding_s);
// 	// printf("reshape1 cycle=%d\n",reshape1_e-reshape1_s);
// 	// printf("reshape2 cycle=%d\n",reshape2_e-reshape2_s);
// }

void MaxPooling_noreshape(int** output,int* input,int inputSize,int bias){

	int m = inputSize;
	int *c = (int*)malloc((m/2)*(m/2) * sizeof(int));
	int *addr_in = &input[0];
	int *addr_out = &c[0];
	for(int i=0; i<(m/2)*(m/2);i++){
		mp_ri(addr_in+4*i);
		max_pooling();
		// relu(bias);
		mp_wb(addr_out+i);
	}

	for(int i=0; i<m/2; i++){
		for(int j=0;j<m/2;j++){
			output[i][j] = c[i*(m/2)+j];
		}
	}
}

int** read_image(char* filename)
{
	// FILE* file;
	// file = fopen(filename, "rb");//test

	int w=28;
	int h=28;
	// fread(&w, sizeof(int), 1, file);
	// fread(&h, sizeof(int), 1, file);
	// fprintf(stderr, "image size w = %d, image size h =  %d \n", w, h);

	// int i, j, k;

	// int** image_data = (int**)malloc(sizeof(int*) * w);
	// int temp[28];

	// for (i = 0; i < w; i++)
	// {
	// 	image_data[i] = (int*)malloc(sizeof(int) * h);

	// 	fread(temp, sizeof(int), h, file);
	// 	for (j = 0; j < h; j++)
	// 	{

	// 		image_data[i][j] = temp[j] / 255.0;

	// 		//printf("%f\n", image_data[i][j]);
	// 	}
	// 	//printf("\n");
	// }
	// //printf("\n");
	// fclose(file);

	int** input_data;
	input_data = (int**)malloc(w * sizeof(int*));
	for (int i=0; i<28 ;i++){
		input_data[i] = (int*)malloc(h * sizeof(int));
	};



	int** input_data_temp;
		input_data_temp = (int**)malloc(sizeof(int*)*28);
	for (int i=0; i<28 ;i++){
		input_data_temp[i] = (int*)malloc(sizeof(int)*28);
	};
	int input_data_temp_mx[28][28]={{188,172,188,188,145,184,176,152,180,149,137,168,231,133,152,152,141,117,109,137,137,101,82,66,66,58,54,54},\
{207,145,152,156,145,160,188,180,141,188,156,176,125,133,117,152,121,113,105,98,109,101,70,78,62,62,50,47},\
{192,164,156,137,172,200,129,145,121,109,152,152,160,121,125,109,90,113,113,109,98,86,70,74,58,66,54,47},\
{168,168,160,137,172,149,145,121,156,164,156,121,168,149,86,117,105,125,94,117,74,70,74,47,70,66,66,43},\
{172,235,207,149,133,141,149,184,156,125,247,86,129,117,101,105,94,101,66,78,74,62,47,47,47,62,86,50},\
{180,152,137,180,145,172,98,160,113,125,160,125,101,137,113,98,117,113,62,70,54,54,62,54,35,58,58,58},\
{192,141,164,196,164,172,133,168,121,86,141,129,141,109,172,94,121,105,109,66,94,54,47,39,43,70,54,47},\
{164,184,152,168,133,152,129,196,129,113,125,172,180,137,784,772,117,94,117,86,86,58,39,54,23,54,50,58},\
{152,129,149,168,200,215,180,196,160,819,815,788,807,796,800,780,164,90,133,105,66,86,66,54,70,78,62,43},\
{152,145,219,137,533,815,827,823,823,819,788,792,207,784,784,776,125,105,74,117,101,98,74,58,62,62,58,54},\
{152,164,160,109,807,811,815,803,807,800,152,117,117,105,784,756,117,62,74,82,78,94,82,70,50,66,66,58},\
{160,160,137,125,643,380,145,137,141,149,94,121,145,450,752,741,86,98,101,90,78,94,78,74,98,62,86,47},\
{176,141,149,168,129,141,113,164,168,196,145,152,149,372,768,682,109,98,82,101,90,113,90,70,62,62,74,62},\
{156,129,160,145,184,145,156,121,133,125,168,113,121,341,788,231,125,82,145,109,78,90,113,62,62,74,82,105},\
{137,180,141,141,200,258,176,145,721,721,301,674,600,160,780,121,90,82,66,94,94,94,98,105,86,94,70,70},\
{172,172,137,172,541,823,823,819,807,807,803,788,788,780,788,768,760,745,756,749,756,749,756,749,745,192,62,62},\
{180,121,176,168,156,266,203,223,392,741,788,658,800,792,784,776,768,768,756,752,752,749,752,733,733,98,58,74},\
{180,149,149,121,129,137,133,137,152,160,145,137,160,784,796,129,172,164,121,145,125,117,109,98,98,90,70,50},\
{188,168,149,141,129,141,176,125,149,149,117,188,505,803,796,133,121,223,141,105,203,105,74,82,78,74,82,54},\
{152,160,196,203,145,160,164,141,176,121,156,137,415,800,796,113,121,98,74,70,82,90,74,78,78,74,82,70},\
{156,133,152,156,176,133,137,109,133,129,121,117,168,792,780,149,113,90,94,74,105,113,86,109,101,82,54,70},\
{196,156,145,137,160,149,152,125,109,109,105,98,121,756,764,156,101,98,90,90,94,101,94,90,82,90,78,78},\
{156,168,156,180,133,125,160,129,176,156,78,113,101,113,156,117,101,101,121,117,125,101,101,94,78,78,101,50},\
{141,152,152,113,156,168,152,152,223,105,145,133,109,168,121,129,101,101,125,101,125,129,117,125,78,109,82,82},\
{149,125,117,145,176,156,141,137,137,149,156,137,105,145,82,141,109,117,90,86,90,200,90,90,86,86,188,137},\
{168,188,172,152,164,172,125,133,164,137,160,149,117,137,94,101,113,125,109,113,90,196,125,105,74,86,74,101},\
{184,160,152,145,168,133,149,137,145,125,156,129,113,121,117,121,113,129,94,94,141,133,160,164,141,105,145,82},\
{203,184,164,168,152,149,149,176,164,141,125,121,117,172,207,164,156,101,109,101,90,101,133,101,101,94,90,98}};

	for(int i=0;i<28;i++){
		for(int j=0;j<28;j++){
			input_data_temp[i][j] = input_data_temp_mx[i][j];
		}
	}


	input_data = transpose_matrix(input_data_temp, w, h);

	return input_data;
}

int*** input(int**inputData, char* Filename, int inputWidth, int inputHeight, int kernel_size, int inChannels, int outChannels)
{

	int i, j, c, r;
	int** mapout;
	
	CovLayer* covL = (CovLayer*)malloc(sizeof(CovLayer));
	covL->mapData = (int****)malloc(outChannels * sizeof(int***));

	for (i = (outChannels - 1); i != (-1); i--)
	{
		covL->mapData[i] = (int***)malloc(inChannels * sizeof(int**));

		for (j = (inChannels - 1); j != (-1); j--)
		{
			covL->mapData[i][j] = (int**)malloc(kernel_size * sizeof(int*));

			for (r = (kernel_size - 1); r != (-1); r--)
			{
				covL->mapData[i][j][r] = (int*)malloc(kernel_size * sizeof(int));
				//intf("mapdata= %p\n", covL->mapData[i][j][r][c]);
			}
		}
	}
	covL->basicData = (int*)malloc(outChannels * sizeof(int));
	int outW = inputWidth - kernel_size + 1;
	int outH = inputHeight - kernel_size + 1;

	covL->v = (int***)malloc(sizeof(int**) * (outChannels));
	covL->y = (int***)malloc(sizeof(int**) * (outChannels));

	int outW_p,outH_p;
	if(outW%2==0){
		outW_p = outW/2; 
		outH_p = outH/2;
	}
	else{
		outW_p = (outW+1)/2;
		outH_p = (outH+2)/2;
	}
	for (j = (outChannels - 1); j != (-1); j--)
	{
		covL->v[j] = (int**)malloc(sizeof(int*) * outH_p);
		covL->y[j] = (int**)malloc(sizeof(int*) * outH_p);
		for (r = 0; r < outH_p; r++)
		{
			covL->v[j][r] = (int*)calloc(outW_p, sizeof(int));
			covL->y[j][r] = (int*)calloc(outW_p, sizeof(int));
		}
	}
	//read_file_conv(Filename, outChannels, inChannels, kernel_size, kernel_size, covL);
	covL->mapData[0][0][0][0]=209;
covL->mapData[0][0][0][1]=-149;
covL->mapData[0][0][0][2]=-238;
covL->mapData[0][0][1][0]=419;
covL->mapData[0][0][1][1]=63;
covL->mapData[0][0][1][2]=-173;
covL->mapData[0][0][2][0]=67;
covL->mapData[0][0][2][1]=314;
covL->mapData[0][0][2][2]=-7;
covL->mapData[1][0][0][0]=-490;
covL->mapData[1][0][0][1]=-246;
covL->mapData[1][0][0][2]=-133;
covL->mapData[1][0][1][0]=-268;
covL->mapData[1][0][1][1]=-3;
covL->mapData[1][0][1][2]=402;
covL->mapData[1][0][2][0]=-481;
covL->mapData[1][0][2][1]=-88;
covL->mapData[1][0][2][2]=306;
covL->mapData[2][0][0][0]=-236;
covL->mapData[2][0][0][1]=190;
covL->mapData[2][0][0][2]=148;
covL->mapData[2][0][1][0]=257;
covL->mapData[2][0][1][1]=37;
covL->mapData[2][0][1][2]=79;
covL->mapData[2][0][2][0]=332;
covL->mapData[2][0][2][1]=266;
covL->mapData[2][0][2][2]=74;
covL->mapData[3][0][0][0]=-51;
covL->mapData[3][0][0][1]=198;
covL->mapData[3][0][0][2]=117;
covL->mapData[3][0][1][0]=-248;
covL->mapData[3][0][1][1]=217;
covL->mapData[3][0][1][2]=91;
covL->mapData[3][0][2][0]=-240;
covL->mapData[3][0][2][1]=27;
covL->mapData[3][0][2][2]=265;
covL->mapData[4][0][0][0]=174;
covL->mapData[4][0][0][1]=-6;
covL->mapData[4][0][0][2]=-227;
covL->mapData[4][0][1][0]=118;
covL->mapData[4][0][1][1]=289;
covL->mapData[4][0][1][2]=437;
covL->mapData[4][0][2][0]=-39;
covL->mapData[4][0][2][1]=-215;
covL->mapData[4][0][2][2]=-77;
covL->mapData[5][0][0][0]=-178;
covL->mapData[5][0][0][1]=-502;
covL->mapData[5][0][0][2]=-284;
covL->mapData[5][0][1][0]=241;
covL->mapData[5][0][1][1]=122;
covL->mapData[5][0][1][2]=-133;
covL->mapData[5][0][2][0]=87;
covL->mapData[5][0][2][1]=428;
covL->mapData[5][0][2][2]=231;
// covL->basicData[0]=-36;
// covL->basicData[1]=21;
// covL->basicData[2]=-8;
// covL->basicData[3]=-3;
// covL->basicData[4]=1;
// covL->basicData[5]=0;

// covL->basicData={-36,21,-8,-3,1,0};
	int convL_basicData[6] = {-36,21,-8,-3,1,0};
	// int convL_mapData[6][1][3][3] = 
	for(int i=0; i<6; i++){
		covL->basicData[i] = convL_basicData[i];
	}

	nSize kernel_size1 = { kernel_size,kernel_size };
	nSize inSize = { inputWidth,inputHeight };
	nSize outSize = { outW,outH };
	//test_tag
	
	int* mapout_1d = (int*)malloc(outW*outH * sizeof(int));
	int** addmat_out = (int**)malloc(outChannels * sizeof(int*));
	for(int m=0; m<outChannels; m++){
		addmat_out[m] = (int*)malloc(outW*outH * sizeof(int));
	}
	
	nSize outSize_pool = { outW_p,outH_p };
	int relu_s = 0;
	int relu_e = 0;
	int div_s = 0;
	int div_e = 0;
	for (i = 0; i < (outChannels); i++)
	{
		for (j = 0; j < (inChannels); j++)
		{
			mapout_1d = conv_noreshape(inputData,covL->mapData[i][j],inputWidth);
			addmat_1d(addmat_out[i],addmat_out[i],mapout_1d,outW*outH);
		}
		MaxPooling_noreshape(covL->v[i],addmat_out[i],outW,covL->basicData[i]);
		for (r = 0; r < outW_p; r++)
		{
			for (c = 0; c < outH_p; c++)
			{
				covL->y[i][r][c] = activation_relu(covL->v[i][r][c], covL->basicData[i]);
				covL->y[i][r][c] = covL->y[i][r][c]>>10;
			}
		}
	}

	for (i = (outChannels - 1); i != (-1); i--)
	{
		for (j = (inChannels - 1); j != (-1); j--)
		{
			for (r = (kernel_size - 1); r != (-1); r--)
			{
				free(covL->mapData[i][j][r]);
			}
			free(covL->mapData[i][j]);
		}
		free(covL->mapData[i]);
	}
	free(covL->mapData);
	for (j = (outChannels - 1); j != (-1); j--)
	{
		for (r = 0; r < outH_p; r++)
		{
			free(covL->v[j][r]);
		}
		free(covL->v[j]);
	}
	free(covL->v);
	free(covL->basicData);

	return covL->y;
}
int*** conv(int*** inputData, char* Filename, int inputWidth, int inputHeight, int kernel_size, int inChannels, int outChannels)
{

	int** mapout;
	int i, j, c, r;

	CovLayer* covL = (CovLayer*)malloc(sizeof(CovLayer));//��ʼ��������
	covL->mapData = (int****)malloc(outChannels * sizeof(int***));

	for (i = (outChannels - 1); i != (-1); i--)
	{
		covL->mapData[i] = (int***)malloc(inChannels * sizeof(int**));

		for (j = (inChannels - 1); j != (-1); j--)
		{
			covL->mapData[i][j] = (int**)malloc(kernel_size * sizeof(int*));

			for (r = (kernel_size - 1); r != (-1); r--)
			{
				covL->mapData[i][j][r] = (int*)malloc(kernel_size * sizeof(int));
			}
		}
	}

	covL->basicData = (int*)malloc(outChannels * sizeof(int));
	
	int outW = inputWidth - kernel_size + 1;
	int outH = inputHeight - kernel_size + 1;
	int outW_p,outH_p;
	if(outW%2==0){
		outW_p = outW/2; 
		outH_p = outH/2;
	}
	else{
		outW_p = (outW+1)/2;
		outH_p = (outH+2)/2;
	}
	covL->v = (int***)malloc(sizeof(int**) * (outChannels));
	covL->y = (int***)malloc(sizeof(int**) * (outChannels));

	for (j = (outChannels - 1); j != (-1); j--)
	{
		covL->v[j] = (int**)malloc(sizeof(int*) * outH_p);
		covL->y[j] = (int**)malloc(sizeof(int*) * outH_p);
		for (r = 0; r < outH_p; r++)
			//for (r = outH-1; r != (-1); r--)
		{
			covL->v[j][r] = (int*)calloc(outW_p, sizeof(int));
			covL->y[j][r] = (int*)calloc(outW_p, sizeof(int));
		}
	}


	//read_file_conv(Filename, outChannels, inChannels, kernel_size, kernel_size, covL);
// covL->mapData[0][0][0][0]=-300;
// covL->mapData[0][0][0][1]=-21;
// covL->mapData[0][0][0][2]=-161;
// covL->mapData[0][0][1][0]=-106;
// covL->mapData[0][0][1][1]=50;
// covL->mapData[0][0][1][2]=-95;
// covL->mapData[0][0][2][0]=-101;
// covL->mapData[0][0][2][1]=-44;
// covL->mapData[0][0][2][2]=1;
// covL->mapData[0][1][0][0]=172;
// covL->mapData[0][1][0][1]=8;
// covL->mapData[0][1][0][2]=-124;
// covL->mapData[0][1][1][0]=-31;
// covL->mapData[0][1][1][1]=129;
// covL->mapData[0][1][1][2]=-208;
// covL->mapData[0][1][2][0]=-26;
// covL->mapData[0][1][2][1]=-47;
// covL->mapData[0][1][2][2]=-216;
// covL->mapData[0][2][0][0]=-65;
// covL->mapData[0][2][0][1]=72;
// covL->mapData[0][2][0][2]=237;
// covL->mapData[0][2][1][0]=113;
// covL->mapData[0][2][1][1]=-22;
// covL->mapData[0][2][1][2]=140;
// covL->mapData[0][2][2][0]=127;
// covL->mapData[0][2][2][1]=46;
// covL->mapData[0][2][2][2]=85;
// covL->mapData[0][3][0][0]=-48;
// covL->mapData[0][3][0][1]=108;
// covL->mapData[0][3][0][2]=-61;
// covL->mapData[0][3][1][0]=50;
// covL->mapData[0][3][1][1]=3;
// covL->mapData[0][3][1][2]=-157;
// covL->mapData[0][3][2][0]=115;
// covL->mapData[0][3][2][1]=-57;
// covL->mapData[0][3][2][2]=-181;
// covL->mapData[0][4][0][0]=-185;
// covL->mapData[0][4][0][1]=-66;
// covL->mapData[0][4][0][2]=69;
// covL->mapData[0][4][1][0]=-8;
// covL->mapData[0][4][1][1]=175;
// covL->mapData[0][4][1][2]=9;
// covL->mapData[0][4][2][0]=166;
// covL->mapData[0][4][2][1]=50;
// covL->mapData[0][4][2][2]=76;
// covL->mapData[0][5][0][0]=308;
// covL->mapData[0][5][0][1]=107;
// covL->mapData[0][5][0][2]=20;
// covL->mapData[0][5][1][0]=64;
// covL->mapData[0][5][1][1]=-87;
// covL->mapData[0][5][1][2]=-154;
// covL->mapData[0][5][2][0]=-82;
// covL->mapData[0][5][2][1]=-422;
// covL->mapData[0][5][2][2]=-141;
// covL->mapData[1][0][0][0]=104;
// covL->mapData[1][0][0][1]=-2;
// covL->mapData[1][0][0][2]=-213;
// covL->mapData[1][0][1][0]=178;
// covL->mapData[1][0][1][1]=-151;
// covL->mapData[1][0][1][2]=-291;
// covL->mapData[1][0][2][0]=-13;
// covL->mapData[1][0][2][1]=-190;
// covL->mapData[1][0][2][2]=26;
// covL->mapData[1][1][0][0]=164;
// covL->mapData[1][1][0][1]=202;
// covL->mapData[1][1][0][2]=-177;
// covL->mapData[1][1][1][0]=-163;
// covL->mapData[1][1][1][1]=-171;
// covL->mapData[1][1][1][2]=135;
// covL->mapData[1][1][2][0]=244;
// covL->mapData[1][1][2][1]=333;
// covL->mapData[1][1][2][2]=152;
// covL->mapData[1][2][0][0]=-61;
// covL->mapData[1][2][0][1]=-212;
// covL->mapData[1][2][0][2]=-180;
// covL->mapData[1][2][1][0]=228;
// covL->mapData[1][2][1][1]=-186;
// covL->mapData[1][2][1][2]=80;
// covL->mapData[1][2][2][0]=67;
// covL->mapData[1][2][2][1]=188;
// covL->mapData[1][2][2][2]=252;
// covL->mapData[1][3][0][0]=208;
// covL->mapData[1][3][0][1]=-149;
// covL->mapData[1][3][0][2]=-51;
// covL->mapData[1][3][1][0]=-115;
// covL->mapData[1][3][1][1]=-276;
// covL->mapData[1][3][1][2]=60;
// covL->mapData[1][3][2][0]=-19;
// covL->mapData[1][3][2][1]=21;
// covL->mapData[1][3][2][2]=33;
// covL->mapData[1][4][0][0]=-41;
// covL->mapData[1][4][0][1]=0;
// covL->mapData[1][4][0][2]=-56;
// covL->mapData[1][4][1][0]=114;
// covL->mapData[1][4][1][1]=-2;
// covL->mapData[1][4][1][2]=72;
// covL->mapData[1][4][2][0]=-118;
// covL->mapData[1][4][2][1]=-103;
// covL->mapData[1][4][2][2]=114;
// covL->mapData[1][5][0][0]=93;
// covL->mapData[1][5][0][1]=3;
// covL->mapData[1][5][0][2]=315;
// covL->mapData[1][5][1][0]=-404;
// covL->mapData[1][5][1][1]=-334;
// covL->mapData[1][5][1][2]=301;
// covL->mapData[1][5][2][0]=-226;
// covL->mapData[1][5][2][1]=149;
// covL->mapData[1][5][2][2]=77;
// covL->mapData[2][0][0][0]=-123;
// covL->mapData[2][0][0][1]=-147;
// covL->mapData[2][0][0][2]=-107;
// covL->mapData[2][0][1][0]=57;
// covL->mapData[2][0][1][1]=168;
// covL->mapData[2][0][1][2]=-39;
// covL->mapData[2][0][2][0]=12;
// covL->mapData[2][0][2][1]=127;
// covL->mapData[2][0][2][2]=86;
// covL->mapData[2][1][0][0]=104;
// covL->mapData[2][1][0][1]=126;
// covL->mapData[2][1][0][2]=124;
// covL->mapData[2][1][1][0]=-62;
// covL->mapData[2][1][1][1]=40;
// covL->mapData[2][1][1][2]=-132;
// covL->mapData[2][1][2][0]=-274;
// covL->mapData[2][1][2][1]=-247;
// covL->mapData[2][1][2][2]=-174;
// covL->mapData[2][2][0][0]=-13;
// covL->mapData[2][2][0][1]=55;
// covL->mapData[2][2][0][2]=80;
// covL->mapData[2][2][1][0]=162;
// covL->mapData[2][2][1][1]=15;
// covL->mapData[2][2][1][2]=-202;
// covL->mapData[2][2][2][0]=-82;
// covL->mapData[2][2][2][1]=79;
// covL->mapData[2][2][2][2]=86;
// covL->mapData[2][3][0][0]=8;
// covL->mapData[2][3][0][1]=35;
// covL->mapData[2][3][0][2]=134;
// covL->mapData[2][3][1][0]=108;
// covL->mapData[2][3][1][1]=95;
// covL->mapData[2][3][1][2]=36;
// covL->mapData[2][3][2][0]=-96;
// covL->mapData[2][3][2][1]=-52;
// covL->mapData[2][3][2][2]=212;
// covL->mapData[2][4][0][0]=-188;
// covL->mapData[2][4][0][1]=30;
// covL->mapData[2][4][0][2]=-142;
// covL->mapData[2][4][1][0]=-84;
// covL->mapData[2][4][1][1]=-113;
// covL->mapData[2][4][1][2]=-105;
// covL->mapData[2][4][2][0]=267;
// covL->mapData[2][4][2][1]=170;
// covL->mapData[2][4][2][2]=175;
// covL->mapData[2][5][0][0]=14;
// covL->mapData[2][5][0][1]=36;
// covL->mapData[2][5][0][2]=-82;
// covL->mapData[2][5][1][0]=-161;
// covL->mapData[2][5][1][1]=-61;
// covL->mapData[2][5][1][2]=65;
// covL->mapData[2][5][2][0]=73;
// covL->mapData[2][5][2][1]=33;
// covL->mapData[2][5][2][2]=384;
// covL->mapData[3][0][0][0]=37;
// covL->mapData[3][0][0][1]=-16;
// covL->mapData[3][0][0][2]=-6;
// covL->mapData[3][0][1][0]=-20;
// covL->mapData[3][0][1][1]=103;
// covL->mapData[3][0][1][2]=17;
// covL->mapData[3][0][2][0]=-395;
// covL->mapData[3][0][2][1]=-707;
// covL->mapData[3][0][2][2]=-446;
// covL->mapData[3][1][0][0]=85;
// covL->mapData[3][1][0][1]=217;
// covL->mapData[3][1][0][2]=221;
// covL->mapData[3][1][1][0]=95;
// covL->mapData[3][1][1][1]=-12;
// covL->mapData[3][1][1][2]=-389;
// covL->mapData[3][1][2][0]=-276;
// covL->mapData[3][1][2][1]=-106;
// covL->mapData[3][1][2][2]=150;
// covL->mapData[3][2][0][0]=222;
// covL->mapData[3][2][0][1]=36;
// covL->mapData[3][2][0][2]=152;
// covL->mapData[3][2][1][0]=-216;
// covL->mapData[3][2][1][1]=185;
// covL->mapData[3][2][1][2]=114;
// covL->mapData[3][2][2][0]=-262;
// covL->mapData[3][2][2][1]=-284;
// covL->mapData[3][2][2][2]=-293;
// covL->mapData[3][3][0][0]=67;
// covL->mapData[3][3][0][1]=44;
// covL->mapData[3][3][0][2]=22;
// covL->mapData[3][3][1][0]=283;
// covL->mapData[3][3][1][1]=294;
// covL->mapData[3][3][1][2]=-159;
// covL->mapData[3][3][2][0]=135;
// covL->mapData[3][3][2][1]=-108;
// covL->mapData[3][3][2][2]=-245;
// covL->mapData[3][4][0][0]=-69;
// covL->mapData[3][4][0][1]=123;
// covL->mapData[3][4][0][2]=101;
// covL->mapData[3][4][1][0]=-21;
// covL->mapData[3][4][1][1]=94;
// covL->mapData[3][4][1][2]=-34;
// covL->mapData[3][4][2][0]=-570;
// covL->mapData[3][4][2][1]=-300;
// covL->mapData[3][4][2][2]=-325;
// covL->mapData[3][5][0][0]=217;
// covL->mapData[3][5][0][1]=16;
// covL->mapData[3][5][0][2]=-50;
// covL->mapData[3][5][1][0]=-13;
// covL->mapData[3][5][1][1]=235;
// covL->mapData[3][5][1][2]=-344;
// covL->mapData[3][5][2][0]=592;
// covL->mapData[3][5][2][1]=592;
// covL->mapData[3][5][2][2]=414;
// covL->mapData[4][0][0][0]=-26;
// covL->mapData[4][0][0][1]=8;
// covL->mapData[4][0][0][2]=284;
// covL->mapData[4][0][1][0]=-24;
// covL->mapData[4][0][1][1]=171;
// covL->mapData[4][0][1][2]=185;
// covL->mapData[4][0][2][0]=322;
// covL->mapData[4][0][2][1]=0;
// covL->mapData[4][0][2][2]=-502;
// covL->mapData[4][1][0][0]=-77;
// covL->mapData[4][1][0][1]=253;
// covL->mapData[4][1][0][2]=349;
// covL->mapData[4][1][1][0]=-336;
// covL->mapData[4][1][1][1]=-61;
// covL->mapData[4][1][1][2]=243;
// covL->mapData[4][1][2][0]=253;
// covL->mapData[4][1][2][1]=227;
// covL->mapData[4][1][2][2]=-26;
// covL->mapData[4][2][0][0]=-241;
// covL->mapData[4][2][0][1]=-303;
// covL->mapData[4][2][0][2]=46;
// covL->mapData[4][2][1][0]=66;
// covL->mapData[4][2][1][1]=-212;
// covL->mapData[4][2][1][2]=199;
// covL->mapData[4][2][2][0]=-19;
// covL->mapData[4][2][2][1]=-107;
// covL->mapData[4][2][2][2]=-375;
// covL->mapData[4][3][0][0]=-70;
// covL->mapData[4][3][0][1]=15;
// covL->mapData[4][3][0][2]=156;
// covL->mapData[4][3][1][0]=-83;
// covL->mapData[4][3][1][1]=-72;
// covL->mapData[4][3][1][2]=181;
// covL->mapData[4][3][2][0]=152;
// covL->mapData[4][3][2][1]=-369;
// covL->mapData[4][3][2][2]=-218;
// covL->mapData[4][4][0][0]=48;
// covL->mapData[4][4][0][1]=-300;
// covL->mapData[4][4][0][2]=57;
// covL->mapData[4][4][1][0]=-158;
// covL->mapData[4][4][1][1]=-229;
// covL->mapData[4][4][1][2]=266;
// covL->mapData[4][4][2][0]=-59;
// covL->mapData[4][4][2][1]=-61;
// covL->mapData[4][4][2][2]=-501;
// covL->mapData[4][5][0][0]=-862;
// covL->mapData[4][5][0][1]=-32;
// covL->mapData[4][5][0][2]=-136;
// covL->mapData[4][5][1][0]=138;
// covL->mapData[4][5][1][1]=-251;
// covL->mapData[4][5][1][2]=122;
// covL->mapData[4][5][2][0]=107;
// covL->mapData[4][5][2][1]=-93;
// covL->mapData[4][5][2][2]=373;
// covL->mapData[5][0][0][0]=255;
// covL->mapData[5][0][0][1]=257;
// covL->mapData[5][0][0][2]=30;
// covL->mapData[5][0][1][0]=58;
// covL->mapData[5][0][1][1]=99;
// covL->mapData[5][0][1][2]=83;
// covL->mapData[5][0][2][0]=-35;
// covL->mapData[5][0][2][1]=78;
// covL->mapData[5][0][2][2]=117;
// covL->mapData[5][1][0][0]=-211;
// covL->mapData[5][1][0][1]=-66;
// covL->mapData[5][1][0][2]=98;
// covL->mapData[5][1][1][0]=-194;
// covL->mapData[5][1][1][1]=-88;
// covL->mapData[5][1][1][2]=-44;
// covL->mapData[5][1][2][0]=8;
// covL->mapData[5][1][2][1]=88;
// covL->mapData[5][1][2][2]=21;
// covL->mapData[5][2][0][0]=50;
// covL->mapData[5][2][0][1]=68;
// covL->mapData[5][2][0][2]=-84;
// covL->mapData[5][2][1][0]=-132;
// covL->mapData[5][2][1][1]=-144;
// covL->mapData[5][2][1][2]=4;
// covL->mapData[5][2][2][0]=152;
// covL->mapData[5][2][2][1]=130;
// covL->mapData[5][2][2][2]=15;
// covL->mapData[5][3][0][0]=98;
// covL->mapData[5][3][0][1]=276;
// covL->mapData[5][3][0][2]=-66;
// covL->mapData[5][3][1][0]=12;
// covL->mapData[5][3][1][1]=2;
// covL->mapData[5][3][1][2]=151;
// covL->mapData[5][3][2][0]=106;
// covL->mapData[5][3][2][1]=107;
// covL->mapData[5][3][2][2]=28;
// covL->mapData[5][4][0][0]=67;
// covL->mapData[5][4][0][1]=121;
// covL->mapData[5][4][0][2]=-16;
// covL->mapData[5][4][1][0]=121;
// covL->mapData[5][4][1][1]=41;
// covL->mapData[5][4][1][2]=58;
// covL->mapData[5][4][2][0]=-187;
// covL->mapData[5][4][2][1]=103;
// covL->mapData[5][4][2][2]=-58;
// covL->mapData[5][5][0][0]=162;
// covL->mapData[5][5][0][1]=65;
// covL->mapData[5][5][0][2]=195;
// covL->mapData[5][5][1][0]=-54;
// covL->mapData[5][5][1][1]=145;
// covL->mapData[5][5][1][2]=2;
// covL->mapData[5][5][2][0]=209;
// covL->mapData[5][5][2][1]=-168;
// covL->mapData[5][5][2][2]=-112;
// covL->mapData[6][0][0][0]=-214;
// covL->mapData[6][0][0][1]=-95;
// covL->mapData[6][0][0][2]=-260;
// covL->mapData[6][0][1][0]=-30;
// covL->mapData[6][0][1][1]=-156;
// covL->mapData[6][0][1][2]=27;
// covL->mapData[6][0][2][0]=239;
// covL->mapData[6][0][2][1]=140;
// covL->mapData[6][0][2][2]=289;
// covL->mapData[6][1][0][0]=-531;
// covL->mapData[6][1][0][1]=-875;
// covL->mapData[6][1][0][2]=137;
// covL->mapData[6][1][1][0]=463;
// covL->mapData[6][1][1][1]=132;
// covL->mapData[6][1][1][2]=-43;
// covL->mapData[6][1][2][0]=540;
// covL->mapData[6][1][2][1]=546;
// covL->mapData[6][1][2][2]=-53;
// covL->mapData[6][2][0][0]=-183;
// covL->mapData[6][2][0][1]=-183;
// covL->mapData[6][2][0][2]=-285;
// covL->mapData[6][2][1][0]=77;
// covL->mapData[6][2][1][1]=22;
// covL->mapData[6][2][1][2]=-345;
// covL->mapData[6][2][2][0]=162;
// covL->mapData[6][2][2][1]=-80;
// covL->mapData[6][2][2][2]=-248;
// covL->mapData[6][3][0][0]=-249;
// covL->mapData[6][3][0][1]=2;
// covL->mapData[6][3][0][2]=248;
// covL->mapData[6][3][1][0]=1;
// covL->mapData[6][3][1][1]=3;
// covL->mapData[6][3][1][2]=-321;
// covL->mapData[6][3][2][0]=68;
// covL->mapData[6][3][2][1]=230;
// covL->mapData[6][3][2][2]=75;
// covL->mapData[6][4][0][0]=-173;
// covL->mapData[6][4][0][1]=36;
// covL->mapData[6][4][0][2]=164;
// covL->mapData[6][4][1][0]=75;
// covL->mapData[6][4][1][1]=15;
// covL->mapData[6][4][1][2]=-196;
// covL->mapData[6][4][2][0]=83;
// covL->mapData[6][4][2][1]=-50;
// covL->mapData[6][4][2][2]=-122;
// covL->mapData[6][5][0][0]=436;
// covL->mapData[6][5][0][1]=320;
// covL->mapData[6][5][0][2]=-679;
// covL->mapData[6][5][1][0]=139;
// covL->mapData[6][5][1][1]=165;
// covL->mapData[6][5][1][2]=63;
// covL->mapData[6][5][2][0]=-200;
// covL->mapData[6][5][2][1]=-164;
// covL->mapData[6][5][2][2]=141;
// covL->mapData[7][0][0][0]=-12;
// covL->mapData[7][0][0][1]=-32;
// covL->mapData[7][0][0][2]=226;
// covL->mapData[7][0][1][0]=-95;
// covL->mapData[7][0][1][1]=103;
// covL->mapData[7][0][1][2]=109;
// covL->mapData[7][0][2][0]=-39;
// covL->mapData[7][0][2][1]=140;
// covL->mapData[7][0][2][2]=166;
// covL->mapData[7][1][0][0]=72;
// covL->mapData[7][1][0][1]=108;
// covL->mapData[7][1][0][2]=446;
// covL->mapData[7][1][1][0]=22;
// covL->mapData[7][1][1][1]=-83;
// covL->mapData[7][1][1][2]=173;
// covL->mapData[7][1][2][0]=-162;
// covL->mapData[7][1][2][1]=-69;
// covL->mapData[7][1][2][2]=81;
// covL->mapData[7][2][0][0]=-294;
// covL->mapData[7][2][0][1]=-103;
// covL->mapData[7][2][0][2]=207;
// covL->mapData[7][2][1][0]=-162;
// covL->mapData[7][2][1][1]=96;
// covL->mapData[7][2][1][2]=-25;
// covL->mapData[7][2][2][0]=-56;
// covL->mapData[7][2][2][1]=290;
// covL->mapData[7][2][2][2]=69;
// covL->mapData[7][3][0][0]=236;
// covL->mapData[7][3][0][1]=146;
// covL->mapData[7][3][0][2]=52;
// covL->mapData[7][3][1][0]=78;
// covL->mapData[7][3][1][1]=208;
// covL->mapData[7][3][1][2]=-69;
// covL->mapData[7][3][2][0]=75;
// covL->mapData[7][3][2][1]=229;
// covL->mapData[7][3][2][2]=164;
// covL->mapData[7][4][0][0]=-173;
// covL->mapData[7][4][0][1]=-112;
// covL->mapData[7][4][0][2]=-95;
// covL->mapData[7][4][1][0]=-155;
// covL->mapData[7][4][1][1]=-94;
// covL->mapData[7][4][1][2]=195;
// covL->mapData[7][4][2][0]=-10;
// covL->mapData[7][4][2][1]=-8;
// covL->mapData[7][4][2][2]=249;
// covL->mapData[7][5][0][0]=-369;
// covL->mapData[7][5][0][1]=-133;
// covL->mapData[7][5][0][2]=-400;
// covL->mapData[7][5][1][0]=134;
// covL->mapData[7][5][1][1]=-386;
// covL->mapData[7][5][1][2]=-87;
// covL->mapData[7][5][2][0]=40;
// covL->mapData[7][5][2][1]=-130;
// covL->mapData[7][5][2][2]=-168;
// covL->mapData[8][0][0][0]=-255;
// covL->mapData[8][0][0][1]=-30;
// covL->mapData[8][0][0][2]=-87;
// covL->mapData[8][0][1][0]=68;
// covL->mapData[8][0][1][1]=172;
// covL->mapData[8][0][1][2]=120;
// covL->mapData[8][0][2][0]=-102;
// covL->mapData[8][0][2][1]=-202;
// covL->mapData[8][0][2][2]=-73;
// covL->mapData[8][1][0][0]=-122;
// covL->mapData[8][1][0][1]=-210;
// covL->mapData[8][1][0][2]=-315;
// covL->mapData[8][1][1][0]=-421;
// covL->mapData[8][1][1][1]=-585;
// covL->mapData[8][1][1][2]=-315;
// covL->mapData[8][1][2][0]=-398;
// covL->mapData[8][1][2][1]=-562;
// covL->mapData[8][1][2][2]=-157;
// covL->mapData[8][2][0][0]=131;
// covL->mapData[8][2][0][1]=-170;
// covL->mapData[8][2][0][2]=82;
// covL->mapData[8][2][1][0]=121;
// covL->mapData[8][2][1][1]=28;
// covL->mapData[8][2][1][2]=118;
// covL->mapData[8][2][2][0]=-199;
// covL->mapData[8][2][2][1]=60;
// covL->mapData[8][2][2][2]=97;
// covL->mapData[8][3][0][0]=-167;
// covL->mapData[8][3][0][1]=-119;
// covL->mapData[8][3][0][2]=57;
// covL->mapData[8][3][1][0]=-99;
// covL->mapData[8][3][1][1]=-36;
// covL->mapData[8][3][1][2]=246;
// covL->mapData[8][3][2][0]=-22;
// covL->mapData[8][3][2][1]=214;
// covL->mapData[8][3][2][2]=3;
// covL->mapData[8][4][0][0]=50;
// covL->mapData[8][4][0][1]=-96;
// covL->mapData[8][4][0][2]=-51;
// covL->mapData[8][4][1][0]=-48;
// covL->mapData[8][4][1][1]=261;
// covL->mapData[8][4][1][2]=83;
// covL->mapData[8][4][2][0]=289;
// covL->mapData[8][4][2][1]=193;
// covL->mapData[8][4][2][2]=23;
// covL->mapData[8][5][0][0]=-85;
// covL->mapData[8][5][0][1]=-36;
// covL->mapData[8][5][0][2]=238;
// covL->mapData[8][5][1][0]=256;
// covL->mapData[8][5][1][1]=372;
// covL->mapData[8][5][1][2]=172;
// covL->mapData[8][5][2][0]=219;
// covL->mapData[8][5][2][1]=241;
// covL->mapData[8][5][2][2]=69;
covL->basicData[0]=-30;
covL->basicData[1]=-8;
covL->basicData[2]=-126;
covL->basicData[3]=1;
covL->basicData[4]=-14;
covL->basicData[5]=-51;
covL->basicData[6]=-4;
covL->basicData[7]=-51;
covL->basicData[8]=2;


	int covL_mapdata[9][6][3][3] = {{{{-300,-21,-161},{-106,50,-95},{-101,-44,1}},{{172,8,-124},{-31,129,-208},{-26,-47,-216}},{{-65,72,237},{113,-22,140},{127,46,85}},{{-48,108,-61},{50,3,-157},{115,-57,-181}},{{-185,-66,69},{-8,175,9},{166,50,76}},{{308,107,20},{64,-87,-154},{-82,-422,-141}}},{{{104,-2,-213},{178,-151,-291},{-13,-190,26}},{{164,202,-177},{-163,-171,135},{244,333,152}},{{-61,-212,-180},{228,-186,80},{67,188,252}},{{208,-149,-51},{-115,-276,60},{-19,21,33}},{{-41,0,-56},{114,-2,72},{-118,-103,114}},{{93,3,315},{-404,-334,301},{-226,149,77}}},{{{-123,-147,-107},{57,168,-39},{12,127,86}},{{104,126,124},{-62,40,-132},{-274,-247,-174}},{{-13,55,80},{162,15,-202},{-82,79,86}},{{8,35,134},{108,95,36},{-96,-52,212}},{{-188,30,-142},{-84,-113,-105},{267,170,175}},{{14,36,-82},{-161,-61,65},{73,33,384}}},{{{37,-16,-6},{-20,103,17},{-395,-707,-446}},{{85,217,221},{95,-12,-389},{-276,-106,150}},{{222,36,152},{-216,185,114},{-262,-284,-293}},{{67,44,22},{283,294,-159},{135,-108,-245}},{{-69,123,101},{-21,94,-34},{-570,-300,-325}},{{217,16,-50},{-13,235,-344},{592,592,414}}},{{{-26,8,284},{-24,171,185},{322,0,-502}},{{-77,253,349},{-336,-61,243},{253,227,-26}},{{-241,-303,46},{66,-212,199},{-19,-107,-375}},{{-70,15,156},{-83,-72,181},{152,-369,-218}},{{48,-300,57},{-158,-229,266},{-59,-61,-501}},{{-862,-32,-136},{138,-251,122},{107,-93,373}}},{{{255,257,30},{58,99,83},{-35,78,117}},{{-211,-66,98},{-194,-88,-44},{8,88,21}},{{50,68,-84},{-132,-144,4},{152,130,15}},{{98,276,-66},{12,2,151},{106,107,28}},{{67,121,-16},{121,41,58},{-187,103,-58}},{{162,65,195},{-54,145,2},{209,-168,-112}}},{{{-214,-95,-260},{-30,-156,27},{239,140,289}},{{-531,-875,137},{463,132,-43},{540,546,-53}},{{-183,-183,-285},{77,22,-345},{162,-80,-248}},{{-249,2,248},{1,3,-321},{68,230,75}},{{-173,36,164},{75,15,-196},{83,-50,-122}},{{436,320,-679},{139,165,63},{-200,-164,141}}},{{{-12,-32,226},{-95,103,109},{-39,140,166}},{{72,108,446},{22,-83,173},{-162,-69,81}},{{-294,-103,207},{-162,96,-25},{-56,290,69}},{{236,146,52},{78,208,-69},{75,229,164}},{{-173,-112,-95},{-155,-94,195},{-10,-8,249}},{{-369,-133,-400},{134,-386,-87},{40,-130,-168}}},{{{-255,-30,-87},{68,172,120},{-102,-202,-73}},{{-122,-210,-315},{-421,-585,-315},{-398,-562,-157}},{{131,-170,82},{121,28,118},{-199,60,97}},{{-167,-119,57},{-99,-36,246},{-22,214,3}},{{50,-96,-51},{-48,261,83},{289,193,23}},{{-85,-36,238},{256,372,172},{219,241,69}}}};
	for(int i=0;i<9;i++){
		for(int j=0;j<6;j++){
			for(int k=0;k<3;k++){
				for(int l=0;l<3;l++){
					covL->mapData[i][j][k][l] = covL_mapdata[i][j][k][l];
				}
			}
		}
	}
	nSize kernel_size1 = { kernel_size,kernel_size };
	nSize inSize = { inputWidth,inputHeight };
	nSize outSize = { outW,outH };
	
	int* mapout_1d = (int*)malloc(2*outH_p*2*outW_p * sizeof(int));
	int** addmat_out = (int**)malloc(outChannels * sizeof(int*));
	for(int m=0; m<outChannels; m++){
		addmat_out[m] = (int*)malloc(2*outH_p*2*outW_p * sizeof(int));
	}
	
	nSize outSize_pool = { outW_p,outH_p };
	int relu_s = 0;
	int relu_e = 0;
	for (i = 0; i < (outChannels); i++)
	{
		for (j = 0; j < (inChannels); j++)
		{
			mapout_1d = conv_noreshape(inputData[j],covL->mapData[i][j],inputWidth);
			addmat_1d(addmat_out[i],addmat_out[i],mapout_1d,2*outH_p*2*outW_p);
		}
		MaxPooling_noreshape(covL->v[i],addmat_out[i],2*outH_p,covL->basicData[i]);
		for (r = 0; r < outH_p; r++)
		{
			for (c = 0; c < outW_p; c++)
			{
				covL->y[i][r][c] = activation_relu(covL->v[i][r][c], covL->basicData[i]);
				covL->y[i][r][c] = covL->y[i][r][c]>>10;
			}
		}
	}


	for (i = (outChannels - 1); i != (-1); i--)
	{
		for (j = (inChannels - 1); j != (-1); j--)
		{
			for (r = (kernel_size - 1); r != (-1); r--)
			{
				free(covL->mapData[i][j][r]);	
			}
			free(covL->mapData[i][j]);
		}
		free(covL->mapData[i]);
	}
	free(covL->mapData);
	for (j = (outChannels - 1); j != (-1); j--)
	{
		for (r = 0; r < outH_p; r++)
		{
			free(covL->v[j][r]);
		}
		free(covL->v[j]);
	}
	free(covL->v);
	free(covL->basicData);

	return covL->y;
}
int*** pool(int*** inputData, int inputWidth, int inputHeight, int poolType, int kernel_size, int inChannels, int outChannels, int stride)
{

	int i;
	int count = 0;
	int outW, outH;
	if (stride == 2)
	{
		outW = ((inputWidth % 2 == 0) ? 0 : 1) + inputWidth / kernel_size;
		outH = ((inputHeight % 2 == 0) ? 0 : 1) + inputHeight / kernel_size;
	}
	else
	{
		outW = (inputWidth - kernel_size) / stride + 1;
		outH = (inputHeight - kernel_size) / stride + 1;
	}
	int outputWidth = outW;//12
	int outputHeight = outH;//12
	int j, r;

	PoolLayer* poolL = (PoolLayer*)malloc(sizeof(PoolLayer));
	poolL->y = (int***)malloc(outChannels * sizeof(int**));
	for (j = (outChannels - 1); j != (-1); j--)
	{
		poolL->y[j] = (int**)malloc(outH * sizeof(int*));
		for (r = (outH - 1); r != (-1); r--)
		{
			poolL->y[j][r] = (int*)calloc(outW, sizeof(int));
		}
	}

	nSize inSize = { inputWidth,inputHeight };
	nSize outSize = { outputWidth,outputHeight };

	for (i = 0; i < outChannels; i++)
	{
		MaxPooling(poolL->y[i], outSize, inputData[i], inSize, kernel_size, stride);
		count++;
	}
	return poolL->y;
}

int* flatten(int ***inputData,int inputWidth,int inputHeight,int inChannels,int outputNum)
{
	int i,j,r,c;
	int temp = 0;

	FlLayer* Fl = (FlLayer*)malloc(sizeof(FlLayer));
	int w = inputWidth * inputHeight;
	Fl->v = (int**)malloc(inChannels * sizeof(int*));
	for (i = (inChannels - 1); i != (-1); i--)
	{
		Fl->v[i]=(int*)calloc(w,sizeof(int));
	}
	Fl->y = (int*)calloc(outputNum,sizeof(int));

	nSize inSize = { inputWidth,inputHeight };	
	int k = 0;
	int l = 0;

	for (j = 0; j < inChannels; j++)//16
	{
		
		for (r = 0; r < inSize.r; r++)
		{
			
			for (c = 0; c < inSize.c; c++)
			{
				Fl->v[j][l] = inputData[j][r][c];
				
				l++;
			}
		}
		l = 0;
	}


	for (int p = 0; p < inChannels; p++)
	{
		for (int d = p; d < w; d++)
		{
			temp = Fl->v[p][d];
			Fl->v[p][d] = Fl->v[d][p];
			Fl->v[d][p] = temp;
			
			
		}
	}
	for (int p = 0; p < inChannels; p++)
	{
		for (int d = 0; d < w; d++)
		{
			
			Fl->y[k] = Fl->v[p][d];
			//printf(" Fl->y[%d]= %f\n", k, Fl->y[k]);
			k++;
		}
	}

	for (i = (inChannels - 1); i != (-1); i--)
	{
		free(Fl->v[i]);
	}
	free(Fl->v);

	return Fl->y;
}
int* fc(int* inputData, char* filename, int inputNum, int outputNum)
{
	int i, j, k;
	FcLayer* FcL = (FcLayer*)malloc(sizeof(FcLayer));
	FcL->wData = (int**)malloc(outputNum * sizeof(int*));
	for (i = (outputNum - 1); i != (-1); i--)
	{
		FcL->wData[i] = (int*)calloc(inputNum, sizeof(int));
	}
	FcL->basicData = (int*)calloc(outputNum, sizeof(int));
	FcL->y = (int*)calloc(outputNum, sizeof(int));


	//read_file_fc(filename, outputNum, inputNum, FcL);
	FcL->wData[0][0]=131;
FcL->wData[0][1]=-212;
FcL->wData[0][2]=99;
FcL->wData[0][3]=109;
FcL->wData[0][4]=65;
FcL->wData[0][5]=-103;
FcL->wData[0][6]=-425;
FcL->wData[0][7]=69;
FcL->wData[0][8]=78;
FcL->wData[0][9]=-357;
FcL->wData[0][10]=-66;
FcL->wData[0][11]=204;
FcL->wData[0][12]=341;
FcL->wData[0][13]=-344;
FcL->wData[0][14]=144;
FcL->wData[0][15]=-110;
FcL->wData[0][16]=-220;
FcL->wData[0][17]=87;
FcL->wData[0][18]=-38;
FcL->wData[0][19]=-172;
FcL->wData[0][20]=-43;
FcL->wData[0][21]=83;
FcL->wData[0][22]=200;
FcL->wData[0][23]=150;
FcL->wData[0][24]=-153;
FcL->wData[0][25]=-187;
FcL->wData[0][26]=27;
FcL->wData[0][27]=-66;
FcL->wData[0][28]=33;
FcL->wData[0][29]=-89;
FcL->wData[0][30]=-53;
FcL->wData[0][31]=61;
FcL->wData[0][32]=76;
FcL->wData[0][33]=-200;
FcL->wData[0][34]=141;
FcL->wData[0][35]=28;
FcL->wData[0][36]=-101;
FcL->wData[0][37]=84;
FcL->wData[0][38]=137;
FcL->wData[0][39]=102;
FcL->wData[0][40]=-28;
FcL->wData[0][41]=-21;
FcL->wData[0][42]=88;
FcL->wData[0][43]=-148;
FcL->wData[0][44]=101;
FcL->wData[0][45]=37;
FcL->wData[0][46]=311;
FcL->wData[0][47]=-203;
FcL->wData[0][48]=-198;
FcL->wData[0][49]=-38;
FcL->wData[0][50]=57;
FcL->wData[0][51]=-121;
FcL->wData[0][52]=118;
FcL->wData[0][53]=-162;
FcL->wData[0][54]=26;
FcL->wData[0][55]=-118;
FcL->wData[0][56]=259;
FcL->wData[0][57]=-114;
FcL->wData[0][58]=50;
FcL->wData[0][59]=-164;
FcL->wData[0][60]=163;
FcL->wData[0][61]=121;
FcL->wData[0][62]=174;
FcL->wData[0][63]=57;
FcL->wData[0][64]=269;
FcL->wData[0][65]=200;
FcL->wData[0][66]=-185;
FcL->wData[0][67]=-124;
FcL->wData[0][68]=62;
FcL->wData[0][69]=86;
FcL->wData[0][70]=85;
FcL->wData[0][71]=84;
FcL->wData[0][72]=196;
FcL->wData[0][73]=226;
FcL->wData[0][74]=77;
FcL->wData[0][75]=-1;
FcL->wData[0][76]=-169;
FcL->wData[0][77]=-15;
FcL->wData[0][78]=143;
FcL->wData[0][79]=-78;
FcL->wData[0][80]=185;
FcL->wData[1][0]=-89;
FcL->wData[1][1]=-42;
FcL->wData[1][2]=25;
FcL->wData[1][3]=-213;
FcL->wData[1][4]=-178;
FcL->wData[1][5]=242;
FcL->wData[1][6]=15;
FcL->wData[1][7]=251;
FcL->wData[1][8]=-116;
FcL->wData[1][9]=-114;
FcL->wData[1][10]=71;
FcL->wData[1][11]=45;
FcL->wData[1][12]=141;
FcL->wData[1][13]=-347;
FcL->wData[1][14]=121;
FcL->wData[1][15]=-158;
FcL->wData[1][16]=-25;
FcL->wData[1][17]=217;
FcL->wData[1][18]=-174;
FcL->wData[1][19]=26;
FcL->wData[1][20]=79;
FcL->wData[1][21]=351;
FcL->wData[1][22]=200;
FcL->wData[1][23]=-346;
FcL->wData[1][24]=-17;
FcL->wData[1][25]=61;
FcL->wData[1][26]=250;
FcL->wData[1][27]=-204;
FcL->wData[1][28]=-35;
FcL->wData[1][29]=70;
FcL->wData[1][30]=74;
FcL->wData[1][31]=53;
FcL->wData[1][32]=111;
FcL->wData[1][33]=134;
FcL->wData[1][34]=133;
FcL->wData[1][35]=167;
FcL->wData[1][36]=119;
FcL->wData[1][37]=171;
FcL->wData[1][38]=-134;
FcL->wData[1][39]=-199;
FcL->wData[1][40]=7;
FcL->wData[1][41]=-257;
FcL->wData[1][42]=71;
FcL->wData[1][43]=104;
FcL->wData[1][44]=-147;
FcL->wData[1][45]=116;
FcL->wData[1][46]=149;
FcL->wData[1][47]=-132;
FcL->wData[1][48]=47;
FcL->wData[1][49]=-90;
FcL->wData[1][50]=256;
FcL->wData[1][51]=-106;
FcL->wData[1][52]=59;
FcL->wData[1][53]=137;
FcL->wData[1][54]=15;
FcL->wData[1][55]=-49;
FcL->wData[1][56]=-131;
FcL->wData[1][57]=-35;
FcL->wData[1][58]=323;
FcL->wData[1][59]=-121;
FcL->wData[1][60]=164;
FcL->wData[1][61]=-68;
FcL->wData[1][62]=-211;
FcL->wData[1][63]=-143;
FcL->wData[1][64]=-262;
FcL->wData[1][65]=-50;
FcL->wData[1][66]=-124;
FcL->wData[1][67]=211;
FcL->wData[1][68]=26;
FcL->wData[1][69]=-207;
FcL->wData[1][70]=260;
FcL->wData[1][71]=-252;
FcL->wData[1][72]=-130;
FcL->wData[1][73]=-346;
FcL->wData[1][74]=108;
FcL->wData[1][75]=-34;
FcL->wData[1][76]=28;
FcL->wData[1][77]=-7;
FcL->wData[1][78]=-178;
FcL->wData[1][79]=16;
FcL->wData[1][80]=-170;
FcL->wData[2][0]=88;
FcL->wData[2][1]=-23;
FcL->wData[2][2]=146;
FcL->wData[2][3]=250;
FcL->wData[2][4]=501;
FcL->wData[2][5]=-70;
FcL->wData[2][6]=186;
FcL->wData[2][7]=102;
FcL->wData[2][8]=16;
FcL->wData[2][9]=98;
FcL->wData[2][10]=65;
FcL->wData[2][11]=-91;
FcL->wData[2][12]=-5;
FcL->wData[2][13]=-74;
FcL->wData[2][14]=-100;
FcL->wData[2][15]=34;
FcL->wData[2][16]=166;
FcL->wData[2][17]=-230;
FcL->wData[2][18]=181;
FcL->wData[2][19]=108;
FcL->wData[2][20]=136;
FcL->wData[2][21]=-605;
FcL->wData[2][22]=99;
FcL->wData[2][23]=-81;
FcL->wData[2][24]=39;
FcL->wData[2][25]=62;
FcL->wData[2][26]=-99;
FcL->wData[2][27]=-171;
FcL->wData[2][28]=138;
FcL->wData[2][29]=-64;
FcL->wData[2][30]=41;
FcL->wData[2][31]=-73;
FcL->wData[2][32]=-103;
FcL->wData[2][33]=-199;
FcL->wData[2][34]=-85;
FcL->wData[2][35]=78;
FcL->wData[2][36]=225;
FcL->wData[2][37]=17;
FcL->wData[2][38]=394;
FcL->wData[2][39]=-196;
FcL->wData[2][40]=-296;
FcL->wData[2][41]=-90;
FcL->wData[2][42]=-179;
FcL->wData[2][43]=17;
FcL->wData[2][44]=201;
FcL->wData[2][45]=-27;
FcL->wData[2][46]=42;
FcL->wData[2][47]=76;
FcL->wData[2][48]=295;
FcL->wData[2][49]=53;
FcL->wData[2][50]=-157;
FcL->wData[2][51]=152;
FcL->wData[2][52]=-11;
FcL->wData[2][53]=260;
FcL->wData[2][54]=-12;
FcL->wData[2][55]=-511;
FcL->wData[2][56]=159;
FcL->wData[2][57]=67;
FcL->wData[2][58]=-120;
FcL->wData[2][59]=-58;
FcL->wData[2][60]=-139;
FcL->wData[2][61]=332;
FcL->wData[2][62]=-107;
FcL->wData[2][63]=-256;
FcL->wData[2][64]=-391;
FcL->wData[2][65]=203;
FcL->wData[2][66]=197;
FcL->wData[2][67]=-15;
FcL->wData[2][68]=10;
FcL->wData[2][69]=8;
FcL->wData[2][70]=-77;
FcL->wData[2][71]=88;
FcL->wData[2][72]=-148;
FcL->wData[2][73]=-220;
FcL->wData[2][74]=-316;
FcL->wData[2][75]=211;
FcL->wData[2][76]=-240;
FcL->wData[2][77]=-35;
FcL->wData[2][78]=89;
FcL->wData[2][79]=-240;
FcL->wData[2][80]=-20;
FcL->wData[3][0]=46;
FcL->wData[3][1]=49;
FcL->wData[3][2]=-109;
FcL->wData[3][3]=-746;
FcL->wData[3][4]=-259;
FcL->wData[3][5]=272;
FcL->wData[3][6]=-172;
FcL->wData[3][7]=26;
FcL->wData[3][8]=-171;
FcL->wData[3][9]=105;
FcL->wData[3][10]=48;
FcL->wData[3][11]=140;
FcL->wData[3][12]=-104;
FcL->wData[3][13]=-358;
FcL->wData[3][14]=-10;
FcL->wData[3][15]=-55;
FcL->wData[3][16]=130;
FcL->wData[3][17]=-54;
FcL->wData[3][18]=-302;
FcL->wData[3][19]=-35;
FcL->wData[3][20]=44;
FcL->wData[3][21]=995;
FcL->wData[3][22]=-194;
FcL->wData[3][23]=-21;
FcL->wData[3][24]=-214;
FcL->wData[3][25]=-20;
FcL->wData[3][26]=51;
FcL->wData[3][27]=-285;
FcL->wData[3][28]=-131;
FcL->wData[3][29]=351;
FcL->wData[3][30]=-148;
FcL->wData[3][31]=-57;
FcL->wData[3][32]=261;
FcL->wData[3][33]=-329;
FcL->wData[3][34]=289;
FcL->wData[3][35]=165;
FcL->wData[3][36]=-179;
FcL->wData[3][37]=-201;
FcL->wData[3][38]=3;
FcL->wData[3][39]=-24;
FcL->wData[3][40]=-183;
FcL->wData[3][41]=83;
FcL->wData[3][42]=39;
FcL->wData[3][43]=-52;
FcL->wData[3][44]=88;
FcL->wData[3][45]=129;
FcL->wData[3][46]=-196;
FcL->wData[3][47]=-164;
FcL->wData[3][48]=285;
FcL->wData[3][49]=140;
FcL->wData[3][50]=28;
FcL->wData[3][51]=-159;
FcL->wData[3][52]=73;
FcL->wData[3][53]=-133;
FcL->wData[3][54]=-97;
FcL->wData[3][55]=54;
FcL->wData[3][56]=335;
FcL->wData[3][57]=-62;
FcL->wData[3][58]=191;
FcL->wData[3][59]=-161;
FcL->wData[3][60]=-129;
FcL->wData[3][61]=23;
FcL->wData[3][62]=-84;
FcL->wData[3][63]=-80;
FcL->wData[3][64]=95;
FcL->wData[3][65]=218;
FcL->wData[3][66]=58;
FcL->wData[3][67]=-112;
FcL->wData[3][68]=127;
FcL->wData[3][69]=-39;
FcL->wData[3][70]=3;
FcL->wData[3][71]=118;
FcL->wData[3][72]=71;
FcL->wData[3][73]=15;
FcL->wData[3][74]=87;
FcL->wData[3][75]=-126;
FcL->wData[3][76]=-33;
FcL->wData[3][77]=-122;
FcL->wData[3][78]=127;
FcL->wData[3][79]=242;
FcL->wData[3][80]=-66;
FcL->wData[4][0]=72;
FcL->wData[4][1]=68;
FcL->wData[4][2]=-103;
FcL->wData[4][3]=66;
FcL->wData[4][4]=-295;
FcL->wData[4][5]=-46;
FcL->wData[4][6]=-344;
FcL->wData[4][7]=6;
FcL->wData[4][8]=102;
FcL->wData[4][9]=156;
FcL->wData[4][10]=-16;
FcL->wData[4][11]=76;
FcL->wData[4][12]=-149;
FcL->wData[4][13]=-1;
FcL->wData[4][14]=136;
FcL->wData[4][15]=120;
FcL->wData[4][16]=114;
FcL->wData[4][17]=79;
FcL->wData[4][18]=-156;
FcL->wData[4][19]=-140;
FcL->wData[4][20]=-191;
FcL->wData[4][21]=188;
FcL->wData[4][22]=-123;
FcL->wData[4][23]=-183;
FcL->wData[4][24]=-81;
FcL->wData[4][25]=-36;
FcL->wData[4][26]=90;
FcL->wData[4][27]=-168;
FcL->wData[4][28]=-104;
FcL->wData[4][29]=-118;
FcL->wData[4][30]=69;
FcL->wData[4][31]=255;
FcL->wData[4][32]=28;
FcL->wData[4][33]=278;
FcL->wData[4][34]=123;
FcL->wData[4][35]=10;
FcL->wData[4][36]=-11;
FcL->wData[4][37]=-136;
FcL->wData[4][38]=-299;
FcL->wData[4][39]=78;
FcL->wData[4][40]=89;
FcL->wData[4][41]=-125;
FcL->wData[4][42]=-208;
FcL->wData[4][43]=33;
FcL->wData[4][44]=-273;
FcL->wData[4][45]=70;
FcL->wData[4][46]=-71;
FcL->wData[4][47]=-206;
FcL->wData[4][48]=-510;
FcL->wData[4][49]=-223;
FcL->wData[4][50]=-6;
FcL->wData[4][51]=-76;
FcL->wData[4][52]=-6;
FcL->wData[4][53]=-332;
FcL->wData[4][54]=66;
FcL->wData[4][55]=-54;
FcL->wData[4][56]=-96;
FcL->wData[4][57]=9;
FcL->wData[4][58]=5;
FcL->wData[4][59]=283;
FcL->wData[4][60]=344;
FcL->wData[4][61]=-218;
FcL->wData[4][62]=89;
FcL->wData[4][63]=85;
FcL->wData[4][64]=460;
FcL->wData[4][65]=161;
FcL->wData[4][66]=-59;
FcL->wData[4][67]=86;
FcL->wData[4][68]=-170;
FcL->wData[4][69]=216;
FcL->wData[4][70]=250;
FcL->wData[4][71]=279;
FcL->wData[4][72]=241;
FcL->wData[4][73]=12;
FcL->wData[4][74]=156;
FcL->wData[4][75]=2;
FcL->wData[4][76]=55;
FcL->wData[4][77]=-4;
FcL->wData[4][78]=-17;
FcL->wData[4][79]=162;
FcL->wData[4][80]=84;
FcL->wData[5][0]=-116;
FcL->wData[5][1]=-283;
FcL->wData[5][2]=-41;
FcL->wData[5][3]=177;
FcL->wData[5][4]=188;
FcL->wData[5][5]=-401;
FcL->wData[5][6]=-183;
FcL->wData[5][7]=-207;
FcL->wData[5][8]=-101;
FcL->wData[5][9]=149;
FcL->wData[5][10]=38;
FcL->wData[5][11]=265;
FcL->wData[5][12]=184;
FcL->wData[5][13]=97;
FcL->wData[5][14]=63;
FcL->wData[5][15]=-147;
FcL->wData[5][16]=-123;
FcL->wData[5][17]=-58;
FcL->wData[5][18]=32;
FcL->wData[5][19]=82;
FcL->wData[5][20]=80;
FcL->wData[5][21]=-341;
FcL->wData[5][22]=-16;
FcL->wData[5][23]=-109;
FcL->wData[5][24]=-94;
FcL->wData[5][25]=0;
FcL->wData[5][26]=221;
FcL->wData[5][27]=-136;
FcL->wData[5][28]=-14;
FcL->wData[5][29]=161;
FcL->wData[5][30]=-445;
FcL->wData[5][31]=-26;
FcL->wData[5][32]=252;
FcL->wData[5][33]=165;
FcL->wData[5][34]=-169;
FcL->wData[5][35]=130;
FcL->wData[5][36]=-175;
FcL->wData[5][37]=-262;
FcL->wData[5][38]=115;
FcL->wData[5][39]=5;
FcL->wData[5][40]=-74;
FcL->wData[5][41]=163;
FcL->wData[5][42]=174;
FcL->wData[5][43]=42;
FcL->wData[5][44]=109;
FcL->wData[5][45]=-7;
FcL->wData[5][46]=-293;
FcL->wData[5][47]=-64;
FcL->wData[5][48]=-7;
FcL->wData[5][49]=365;
FcL->wData[5][50]=-162;
FcL->wData[5][51]=-91;
FcL->wData[5][52]=-282;
FcL->wData[5][53]=-20;
FcL->wData[5][54]=74;
FcL->wData[5][55]=147;
FcL->wData[5][56]=19;
FcL->wData[5][57]=123;
FcL->wData[5][58]=19;
FcL->wData[5][59]=-156;
FcL->wData[5][60]=-75;
FcL->wData[5][61]=174;
FcL->wData[5][62]=-76;
FcL->wData[5][63]=-21;
FcL->wData[5][64]=35;
FcL->wData[5][65]=-150;
FcL->wData[5][66]=209;
FcL->wData[5][67]=-76;
FcL->wData[5][68]=304;
FcL->wData[5][69]=-118;
FcL->wData[5][70]=78;
FcL->wData[5][71]=69;
FcL->wData[5][72]=-287;
FcL->wData[5][73]=50;
FcL->wData[5][74]=-175;
FcL->wData[5][75]=-230;
FcL->wData[5][76]=190;
FcL->wData[5][77]=150;
FcL->wData[5][78]=128;
FcL->wData[5][79]=88;
FcL->wData[5][80]=62;
FcL->wData[6][0]=-90;
FcL->wData[6][1]=132;
FcL->wData[6][2]=165;
FcL->wData[6][3]=156;
FcL->wData[6][4]=-40;
FcL->wData[6][5]=11;
FcL->wData[6][6]=301;
FcL->wData[6][7]=-28;
FcL->wData[6][8]=-1;
FcL->wData[6][9]=77;
FcL->wData[6][10]=-177;
FcL->wData[6][11]=6;
FcL->wData[6][12]=161;
FcL->wData[6][13]=168;
FcL->wData[6][14]=-237;
FcL->wData[6][15]=-39;
FcL->wData[6][16]=-212;
FcL->wData[6][17]=258;
FcL->wData[6][18]=156;
FcL->wData[6][19]=-102;
FcL->wData[6][20]=116;
FcL->wData[6][21]=97;
FcL->wData[6][22]=33;
FcL->wData[6][23]=66;
FcL->wData[6][24]=274;
FcL->wData[6][25]=-23;
FcL->wData[6][26]=-91;
FcL->wData[6][27]=170;
FcL->wData[6][28]=-8;
FcL->wData[6][29]=-310;
FcL->wData[6][30]=50;
FcL->wData[6][31]=-130;
FcL->wData[6][32]=-162;
FcL->wData[6][33]=0;
FcL->wData[6][34]=-103;
FcL->wData[6][35]=-301;
FcL->wData[6][36]=-30;
FcL->wData[6][37]=318;
FcL->wData[6][38]=-157;
FcL->wData[6][39]=-155;
FcL->wData[6][40]=98;
FcL->wData[6][41]=-59;
FcL->wData[6][42]=118;
FcL->wData[6][43]=223;
FcL->wData[6][44]=-269;
FcL->wData[6][45]=-101;
FcL->wData[6][46]=146;
FcL->wData[6][47]=-36;
FcL->wData[6][48]=-9;
FcL->wData[6][49]=209;
FcL->wData[6][50]=21;
FcL->wData[6][51]=137;
FcL->wData[6][52]=64;
FcL->wData[6][53]=2;
FcL->wData[6][54]=-113;
FcL->wData[6][55]=-170;
FcL->wData[6][56]=141;
FcL->wData[6][57]=-167;
FcL->wData[6][58]=156;
FcL->wData[6][59]=114;
FcL->wData[6][60]=-30;
FcL->wData[6][61]=143;
FcL->wData[6][62]=92;
FcL->wData[6][63]=169;
FcL->wData[6][64]=129;
FcL->wData[6][65]=62;
FcL->wData[6][66]=-119;
FcL->wData[6][67]=-137;
FcL->wData[6][68]=186;
FcL->wData[6][69]=60;
FcL->wData[6][70]=-306;
FcL->wData[6][71]=103;
FcL->wData[6][72]=-164;
FcL->wData[6][73]=361;
FcL->wData[6][74]=-114;
FcL->wData[6][75]=32;
FcL->wData[6][76]=-291;
FcL->wData[6][77]=258;
FcL->wData[6][78]=-177;
FcL->wData[6][79]=49;
FcL->wData[6][80]=34;
FcL->wData[7][0]=-193;
FcL->wData[7][1]=-422;
FcL->wData[7][2]=-277;
FcL->wData[7][3]=-246;
FcL->wData[7][4]=162;
FcL->wData[7][5]=25;
FcL->wData[7][6]=5;
FcL->wData[7][7]=-226;
FcL->wData[7][8]=-237;
FcL->wData[7][9]=190;
FcL->wData[7][10]=-191;
FcL->wData[7][11]=99;
FcL->wData[7][12]=-230;
FcL->wData[7][13]=-84;
FcL->wData[7][14]=-52;
FcL->wData[7][15]=256;
FcL->wData[7][16]=13;
FcL->wData[7][17]=-232;
FcL->wData[7][18]=-219;
FcL->wData[7][19]=71;
FcL->wData[7][20]=106;
FcL->wData[7][21]=64;
FcL->wData[7][22]=-16;
FcL->wData[7][23]=230;
FcL->wData[7][24]=72;
FcL->wData[7][25]=-86;
FcL->wData[7][26]=-186;
FcL->wData[7][27]=-21;
FcL->wData[7][28]=37;
FcL->wData[7][29]=-215;
FcL->wData[7][30]=-176;
FcL->wData[7][31]=-391;
FcL->wData[7][32]=176;
FcL->wData[7][33]=-120;
FcL->wData[7][34]=199;
FcL->wData[7][35]=137;
FcL->wData[7][36]=142;
FcL->wData[7][37]=131;
FcL->wData[7][38]=39;
FcL->wData[7][39]=83;
FcL->wData[7][40]=2;
FcL->wData[7][41]=-92;
FcL->wData[7][42]=-133;
FcL->wData[7][43]=155;
FcL->wData[7][44]=51;
FcL->wData[7][45]=65;
FcL->wData[7][46]=-252;
FcL->wData[7][47]=-48;
FcL->wData[7][48]=243;
FcL->wData[7][49]=-178;
FcL->wData[7][50]=-132;
FcL->wData[7][51]=-90;
FcL->wData[7][52]=261;
FcL->wData[7][53]=154;
FcL->wData[7][54]=-49;
FcL->wData[7][55]=3;
FcL->wData[7][56]=205;
FcL->wData[7][57]=143;
FcL->wData[7][58]=-73;
FcL->wData[7][59]=50;
FcL->wData[7][60]=57;
FcL->wData[7][61]=-114;
FcL->wData[7][62]=178;
FcL->wData[7][63]=-31;
FcL->wData[7][64]=149;
FcL->wData[7][65]=-137;
FcL->wData[7][66]=-142;
FcL->wData[7][67]=-492;
FcL->wData[7][68]=-142;
FcL->wData[7][69]=58;
FcL->wData[7][70]=18;
FcL->wData[7][71]=-19;
FcL->wData[7][72]=-203;
FcL->wData[7][73]=-310;
FcL->wData[7][74]=-147;
FcL->wData[7][75]=-343;
FcL->wData[7][76]=102;
FcL->wData[7][77]=-453;
FcL->wData[7][78]=107;
FcL->wData[7][79]=-56;
FcL->wData[7][80]=-200;
FcL->wData[8][0]=161;
FcL->wData[8][1]=80;
FcL->wData[8][2]=-75;
FcL->wData[8][3]=121;
FcL->wData[8][4]=-10;
FcL->wData[8][5]=64;
FcL->wData[8][6]=-122;
FcL->wData[8][7]=188;
FcL->wData[8][8]=-183;
FcL->wData[8][9]=-78;
FcL->wData[8][10]=-187;
FcL->wData[8][11]=-194;
FcL->wData[8][12]=-125;
FcL->wData[8][13]=-72;
FcL->wData[8][14]=-133;
FcL->wData[8][15]=-151;
FcL->wData[8][16]=-89;
FcL->wData[8][17]=45;
FcL->wData[8][18]=64;
FcL->wData[8][19]=-175;
FcL->wData[8][20]=13;
FcL->wData[8][21]=-154;
FcL->wData[8][22]=-120;
FcL->wData[8][23]=-51;
FcL->wData[8][24]=80;
FcL->wData[8][25]=12;
FcL->wData[8][26]=-12;
FcL->wData[8][27]=-169;
FcL->wData[8][28]=-51;
FcL->wData[8][29]=-147;
FcL->wData[8][30]=175;
FcL->wData[8][31]=23;
FcL->wData[8][32]=-54;
FcL->wData[8][33]=-12;
FcL->wData[8][34]=-124;
FcL->wData[8][35]=141;
FcL->wData[8][36]=88;
FcL->wData[8][37]=-26;
FcL->wData[8][38]=-18;
FcL->wData[8][39]=172;
FcL->wData[8][40]=3;
FcL->wData[8][41]=-199;
FcL->wData[8][42]=170;
FcL->wData[8][43]=86;
FcL->wData[8][44]=33;
FcL->wData[8][45]=187;
FcL->wData[8][46]=-65;
FcL->wData[8][47]=-1;
FcL->wData[8][48]=38;
FcL->wData[8][49]=-12;
FcL->wData[8][50]=-125;
FcL->wData[8][51]=-63;
FcL->wData[8][52]=-63;
FcL->wData[8][53]=-13;
FcL->wData[8][54]=122;
FcL->wData[8][55]=168;
FcL->wData[8][56]=-206;
FcL->wData[8][57]=-57;
FcL->wData[8][58]=-34;
FcL->wData[8][59]=-58;
FcL->wData[8][60]=-128;
FcL->wData[8][61]=-116;
FcL->wData[8][62]=120;
FcL->wData[8][63]=153;
FcL->wData[8][64]=-174;
FcL->wData[8][65]=166;
FcL->wData[8][66]=80;
FcL->wData[8][67]=27;
FcL->wData[8][68]=-153;
FcL->wData[8][69]=29;
FcL->wData[8][70]=-139;
FcL->wData[8][71]=-78;
FcL->wData[8][72]=105;
FcL->wData[8][73]=-39;
FcL->wData[8][74]=11;
FcL->wData[8][75]=-9;
FcL->wData[8][76]=-58;
FcL->wData[8][77]=-159;
FcL->wData[8][78]=-4;
FcL->wData[8][79]=-16;
FcL->wData[8][80]=-41;
FcL->wData[9][0]=-128;
FcL->wData[9][1]=170;
FcL->wData[9][2]=-362;
FcL->wData[9][3]=247;
FcL->wData[9][4]=16;
FcL->wData[9][5]=-205;
FcL->wData[9][6]=-379;
FcL->wData[9][7]=-74;
FcL->wData[9][8]=94;
FcL->wData[9][9]=79;
FcL->wData[9][10]=-27;
FcL->wData[9][11]=-85;
FcL->wData[9][12]=15;
FcL->wData[9][13]=164;
FcL->wData[9][14]=-154;
FcL->wData[9][15]=-88;
FcL->wData[9][16]=169;
FcL->wData[9][17]=-121;
FcL->wData[9][18]=-129;
FcL->wData[9][19]=-347;
FcL->wData[9][20]=-21;
FcL->wData[9][21]=-252;
FcL->wData[9][22]=47;
FcL->wData[9][23]=-121;
FcL->wData[9][24]=99;
FcL->wData[9][25]=-42;
FcL->wData[9][26]=-126;
FcL->wData[9][27]=162;
FcL->wData[9][28]=299;
FcL->wData[9][29]=-225;
FcL->wData[9][30]=-133;
FcL->wData[9][31]=-206;
FcL->wData[9][32]=-65;
FcL->wData[9][33]=-536;
FcL->wData[9][34]=-38;
FcL->wData[9][35]=0;
FcL->wData[9][36]=35;
FcL->wData[9][37]=303;
FcL->wData[9][38]=103;
FcL->wData[9][39]=-245;
FcL->wData[9][40]=157;
FcL->wData[9][41]=-150;
FcL->wData[9][42]=77;
FcL->wData[9][43]=279;
FcL->wData[9][44]=97;
FcL->wData[9][45]=228;
FcL->wData[9][46]=104;
FcL->wData[9][47]=158;
FcL->wData[9][48]=-211;
FcL->wData[9][49]=-287;
FcL->wData[9][50]=-106;
FcL->wData[9][51]=-295;
FcL->wData[9][52]=282;
FcL->wData[9][53]=109;
FcL->wData[9][54]=103;
FcL->wData[9][55]=-358;
FcL->wData[9][56]=69;
FcL->wData[9][57]=91;
FcL->wData[9][58]=82;
FcL->wData[9][59]=-103;
FcL->wData[9][60]=-515;
FcL->wData[9][61]=261;
FcL->wData[9][62]=-15;
FcL->wData[9][63]=-101;
FcL->wData[9][64]=-447;
FcL->wData[9][65]=-219;
FcL->wData[9][66]=222;
FcL->wData[9][67]=128;
FcL->wData[9][68]=75;
FcL->wData[9][69]=-305;
FcL->wData[9][70]=-217;
FcL->wData[9][71]=167;
FcL->wData[9][72]=-379;
FcL->wData[9][73]=-208;
FcL->wData[9][74]=186;
FcL->wData[9][75]=329;
FcL->wData[9][76]=406;
FcL->wData[9][77]=143;
FcL->wData[9][78]=242;
FcL->wData[9][79]=-208;
FcL->wData[9][80]=325;
FcL->wData[10][0]=-87;
FcL->wData[10][1]=121;
FcL->wData[10][2]=66;
FcL->wData[10][3]=-74;
FcL->wData[10][4]=23;
FcL->wData[10][5]=-127;
FcL->wData[10][6]=-174;
FcL->wData[10][7]=-274;
FcL->wData[10][8]=27;
FcL->wData[10][9]=109;
FcL->wData[10][10]=79;
FcL->wData[10][11]=-252;
FcL->wData[10][12]=-132;
FcL->wData[10][13]=98;
FcL->wData[10][14]=84;
FcL->wData[10][15]=-48;
FcL->wData[10][16]=5;
FcL->wData[10][17]=-131;
FcL->wData[10][18]=-35;
FcL->wData[10][19]=-25;
FcL->wData[10][20]=33;
FcL->wData[10][21]=-264;
FcL->wData[10][22]=86;
FcL->wData[10][23]=108;
FcL->wData[10][24]=-135;
FcL->wData[10][25]=5;
FcL->wData[10][26]=69;
FcL->wData[10][27]=-42;
FcL->wData[10][28]=20;
FcL->wData[10][29]=67;
FcL->wData[10][30]=-107;
FcL->wData[10][31]=-105;
FcL->wData[10][32]=83;
FcL->wData[10][33]=-173;
FcL->wData[10][34]=365;
FcL->wData[10][35]=14;
FcL->wData[10][36]=-54;
FcL->wData[10][37]=-264;
FcL->wData[10][38]=122;
FcL->wData[10][39]=-10;
FcL->wData[10][40]=-6;
FcL->wData[10][41]=-44;
FcL->wData[10][42]=-37;
FcL->wData[10][43]=-35;
FcL->wData[10][44]=121;
FcL->wData[10][45]=29;
FcL->wData[10][46]=56;
FcL->wData[10][47]=-120;
FcL->wData[10][48]=-443;
FcL->wData[10][49]=3;
FcL->wData[10][50]=-23;
FcL->wData[10][51]=97;
FcL->wData[10][52]=-149;
FcL->wData[10][53]=69;
FcL->wData[10][54]=60;
FcL->wData[10][55]=-28;
FcL->wData[10][56]=-142;
FcL->wData[10][57]=102;
FcL->wData[10][58]=25;
FcL->wData[10][59]=-147;
FcL->wData[10][60]=-252;
FcL->wData[10][61]=97;
FcL->wData[10][62]=-105;
FcL->wData[10][63]=18;
FcL->wData[10][64]=16;
FcL->wData[10][65]=146;
FcL->wData[10][66]=39;
FcL->wData[10][67]=216;
FcL->wData[10][68]=-12;
FcL->wData[10][69]=-1;
FcL->wData[10][70]=98;
FcL->wData[10][71]=-79;
FcL->wData[10][72]=-74;
FcL->wData[10][73]=16;
FcL->wData[10][74]=-10;
FcL->wData[10][75]=61;
FcL->wData[10][76]=-2;
FcL->wData[10][77]=-40;
FcL->wData[10][78]=-111;
FcL->wData[10][79]=155;
FcL->wData[10][80]=85;
FcL->wData[11][0]=49;
FcL->wData[11][1]=-83;
FcL->wData[11][2]=-165;
FcL->wData[11][3]=1;
FcL->wData[11][4]=-135;
FcL->wData[11][5]=-185;
FcL->wData[11][6]=-173;
FcL->wData[11][7]=103;
FcL->wData[11][8]=-33;
FcL->wData[11][9]=-81;
FcL->wData[11][10]=-41;
FcL->wData[11][11]=-107;
FcL->wData[11][12]=-1;
FcL->wData[11][13]=-140;
FcL->wData[11][14]=116;
FcL->wData[11][15]=172;
FcL->wData[11][16]=-131;
FcL->wData[11][17]=26;
FcL->wData[11][18]=-212;
FcL->wData[11][19]=176;
FcL->wData[11][20]=-111;
FcL->wData[11][21]=83;
FcL->wData[11][22]=-139;
FcL->wData[11][23]=-110;
FcL->wData[11][24]=200;
FcL->wData[11][25]=-195;
FcL->wData[11][26]=8;
FcL->wData[11][27]=-137;
FcL->wData[11][28]=3;
FcL->wData[11][29]=-9;
FcL->wData[11][30]=106;
FcL->wData[11][31]=119;
FcL->wData[11][32]=14;
FcL->wData[11][33]=-208;
FcL->wData[11][34]=-50;
FcL->wData[11][35]=-163;
FcL->wData[11][36]=-135;
FcL->wData[11][37]=-99;
FcL->wData[11][38]=163;
FcL->wData[11][39]=-209;
FcL->wData[11][40]=21;
FcL->wData[11][41]=2;
FcL->wData[11][42]=32;
FcL->wData[11][43]=-162;
FcL->wData[11][44]=-87;
FcL->wData[11][45]=60;
FcL->wData[11][46]=-131;
FcL->wData[11][47]=-161;
FcL->wData[11][48]=-73;
FcL->wData[11][49]=-152;
FcL->wData[11][50]=-207;
FcL->wData[11][51]=121;
FcL->wData[11][52]=95;
FcL->wData[11][53]=1;
FcL->wData[11][54]=-32;
FcL->wData[11][55]=37;
FcL->wData[11][56]=-204;
FcL->wData[11][57]=-168;
FcL->wData[11][58]=-134;
FcL->wData[11][59]=22;
FcL->wData[11][60]=-138;
FcL->wData[11][61]=-32;
FcL->wData[11][62]=-92;
FcL->wData[11][63]=66;
FcL->wData[11][64]=149;
FcL->wData[11][65]=-54;
FcL->wData[11][66]=-189;
FcL->wData[11][67]=-166;
FcL->wData[11][68]=17;
FcL->wData[11][69]=148;
FcL->wData[11][70]=-74;
FcL->wData[11][71]=-1;
FcL->wData[11][72]=-233;
FcL->wData[11][73]=46;
FcL->wData[11][74]=-146;
FcL->wData[11][75]=174;
FcL->wData[11][76]=213;
FcL->wData[11][77]=110;
FcL->wData[11][78]=1;
FcL->wData[11][79]=-146;
FcL->wData[11][80]=70;
FcL->wData[12][0]=-109;
FcL->wData[12][1]=-56;
FcL->wData[12][2]=-29;
FcL->wData[12][3]=-325;
FcL->wData[12][4]=34;
FcL->wData[12][5]=221;
FcL->wData[12][6]=293;
FcL->wData[12][7]=115;
FcL->wData[12][8]=-90;
FcL->wData[12][9]=7;
FcL->wData[12][10]=193;
FcL->wData[12][11]=-344;
FcL->wData[12][12]=-544;
FcL->wData[12][13]=295;
FcL->wData[12][14]=-289;
FcL->wData[12][15]=309;
FcL->wData[12][16]=181;
FcL->wData[12][17]=-608;
FcL->wData[12][18]=479;
FcL->wData[12][19]=116;
FcL->wData[12][20]=1;
FcL->wData[12][21]=-442;
FcL->wData[12][22]=82;
FcL->wData[12][23]=70;
FcL->wData[12][24]=107;
FcL->wData[12][25]=279;
FcL->wData[12][26]=-267;
FcL->wData[12][27]=66;
FcL->wData[12][28]=208;
FcL->wData[12][29]=148;
FcL->wData[12][30]=219;
FcL->wData[12][31]=6;
FcL->wData[12][32]=45;
FcL->wData[12][33]=-437;
FcL->wData[12][34]=122;
FcL->wData[12][35]=36;
FcL->wData[12][36]=-312;
FcL->wData[12][37]=-281;
FcL->wData[12][38]=106;
FcL->wData[12][39]=-175;
FcL->wData[12][40]=-233;
FcL->wData[12][41]=-82;
FcL->wData[12][42]=-516;
FcL->wData[12][43]=78;
FcL->wData[12][44]=187;
FcL->wData[12][45]=67;
FcL->wData[12][46]=20;
FcL->wData[12][47]=38;
FcL->wData[12][48]=106;
FcL->wData[12][49]=-257;
FcL->wData[12][50]=-101;
FcL->wData[12][51]=1;
FcL->wData[12][52]=-136;
FcL->wData[12][53]=184;
FcL->wData[12][54]=-41;
FcL->wData[12][55]=151;
FcL->wData[12][56]=-198;
FcL->wData[12][57]=-22;
FcL->wData[12][58]=-173;
FcL->wData[12][59]=-171;
FcL->wData[12][60]=22;
FcL->wData[12][61]=-8;
FcL->wData[12][62]=-56;
FcL->wData[12][63]=-66;
FcL->wData[12][64]=-274;
FcL->wData[12][65]=-39;
FcL->wData[12][66]=83;
FcL->wData[12][67]=416;
FcL->wData[12][68]=-174;
FcL->wData[12][69]=-620;
FcL->wData[12][70]=138;
FcL->wData[12][71]=-396;
FcL->wData[12][72]=-115;
FcL->wData[12][73]=111;
FcL->wData[12][74]=215;
FcL->wData[12][75]=26;
FcL->wData[12][76]=-77;
FcL->wData[12][77]=60;
FcL->wData[12][78]=-99;
FcL->wData[12][79]=4;
FcL->wData[12][80]=58;
FcL->wData[13][0]=-172;
FcL->wData[13][1]=-262;
FcL->wData[13][2]=-109;
FcL->wData[13][3]=451;
FcL->wData[13][4]=567;
FcL->wData[13][5]=78;
FcL->wData[13][6]=161;
FcL->wData[13][7]=65;
FcL->wData[13][8]=-4;
FcL->wData[13][9]=144;
FcL->wData[13][10]=-72;
FcL->wData[13][11]=-336;
FcL->wData[13][12]=-146;
FcL->wData[13][13]=417;
FcL->wData[13][14]=7;
FcL->wData[13][15]=85;
FcL->wData[13][16]=237;
FcL->wData[13][17]=-268;
FcL->wData[13][18]=152;
FcL->wData[13][19]=248;
FcL->wData[13][20]=-58;
FcL->wData[13][21]=-212;
FcL->wData[13][22]=68;
FcL->wData[13][23]=72;
FcL->wData[13][24]=0;
FcL->wData[13][25]=125;
FcL->wData[13][26]=-254;
FcL->wData[13][27]=-43;
FcL->wData[13][28]=264;
FcL->wData[13][29]=96;
FcL->wData[13][30]=198;
FcL->wData[13][31]=-4;
FcL->wData[13][32]=-50;
FcL->wData[13][33]=292;
FcL->wData[13][34]=-63;
FcL->wData[13][35]=-39;
FcL->wData[13][36]=-142;
FcL->wData[13][37]=-140;
FcL->wData[13][38]=333;
FcL->wData[13][39]=-10;
FcL->wData[13][40]=-15;
FcL->wData[13][41]=-67;
FcL->wData[13][42]=-16;
FcL->wData[13][43]=-92;
FcL->wData[13][44]=302;
FcL->wData[13][45]=-160;
FcL->wData[13][46]=164;
FcL->wData[13][47]=44;
FcL->wData[13][48]=50;
FcL->wData[13][49]=33;
FcL->wData[13][50]=102;
FcL->wData[13][51]=-107;
FcL->wData[13][52]=-252;
FcL->wData[13][53]=305;
FcL->wData[13][54]=106;
FcL->wData[13][55]=123;
FcL->wData[13][56]=93;
FcL->wData[13][57]=40;
FcL->wData[13][58]=87;
FcL->wData[13][59]=-26;
FcL->wData[13][60]=185;
FcL->wData[13][61]=-78;
FcL->wData[13][62]=173;
FcL->wData[13][63]=-36;
FcL->wData[13][64]=-117;
FcL->wData[13][65]=-381;
FcL->wData[13][66]=-110;
FcL->wData[13][67]=269;
FcL->wData[13][68]=-128;
FcL->wData[13][69]=-119;
FcL->wData[13][70]=77;
FcL->wData[13][71]=-114;
FcL->wData[13][72]=-28;
FcL->wData[13][73]=18;
FcL->wData[13][74]=-43;
FcL->wData[13][75]=250;
FcL->wData[13][76]=104;
FcL->wData[13][77]=116;
FcL->wData[13][78]=-41;
FcL->wData[13][79]=-98;
FcL->wData[13][80]=3;
FcL->wData[14][0]=-59;
FcL->wData[14][1]=76;
FcL->wData[14][2]=-30;
FcL->wData[14][3]=327;
FcL->wData[14][4]=-165;
FcL->wData[14][5]=-38;
FcL->wData[14][6]=-122;
FcL->wData[14][7]=-239;
FcL->wData[14][8]=251;
FcL->wData[14][9]=-58;
FcL->wData[14][10]=-199;
FcL->wData[14][11]=95;
FcL->wData[14][12]=4;
FcL->wData[14][13]=269;
FcL->wData[14][14]=354;
FcL->wData[14][15]=21;
FcL->wData[14][16]=-85;
FcL->wData[14][17]=111;
FcL->wData[14][18]=-177;
FcL->wData[14][19]=-183;
FcL->wData[14][20]=-267;
FcL->wData[14][21]=-668;
FcL->wData[14][22]=348;
FcL->wData[14][23]=375;
FcL->wData[14][24]=261;
FcL->wData[14][25]=-144;
FcL->wData[14][26]=-40;
FcL->wData[14][27]=-29;
FcL->wData[14][28]=179;
FcL->wData[14][29]=196;
FcL->wData[14][30]=-45;
FcL->wData[14][31]=-92;
FcL->wData[14][32]=-51;
FcL->wData[14][33]=-72;
FcL->wData[14][34]=-146;
FcL->wData[14][35]=-48;
FcL->wData[14][36]=166;
FcL->wData[14][37]=150;
FcL->wData[14][38]=8;
FcL->wData[14][39]=161;
FcL->wData[14][40]=272;
FcL->wData[14][41]=-191;
FcL->wData[14][42]=-108;
FcL->wData[14][43]=81;
FcL->wData[14][44]=182;
FcL->wData[14][45]=137;
FcL->wData[14][46]=263;
FcL->wData[14][47]=247;
FcL->wData[14][48]=-151;
FcL->wData[14][49]=-345;
FcL->wData[14][50]=-183;
FcL->wData[14][51]=-212;
FcL->wData[14][52]=-16;
FcL->wData[14][53]=-252;
FcL->wData[14][54]=28;
FcL->wData[14][55]=73;
FcL->wData[14][56]=-25;
FcL->wData[14][57]=9;
FcL->wData[14][58]=-108;
FcL->wData[14][59]=-67;
FcL->wData[14][60]=-7;
FcL->wData[14][61]=163;
FcL->wData[14][62]=113;
FcL->wData[14][63]=-93;
FcL->wData[14][64]=89;
FcL->wData[14][65]=-80;
FcL->wData[14][66]=-96;
FcL->wData[14][67]=236;
FcL->wData[14][68]=-115;
FcL->wData[14][69]=-102;
FcL->wData[14][70]=94;
FcL->wData[14][71]=-86;
FcL->wData[14][72]=-86;
FcL->wData[14][73]=27;
FcL->wData[14][74]=-59;
FcL->wData[14][75]=208;
FcL->wData[14][76]=137;
FcL->wData[14][77]=132;
FcL->wData[14][78]=-12;
FcL->wData[14][79]=-162;
FcL->wData[14][80]=-32;
FcL->wData[15][0]=-60;
FcL->wData[15][1]=160;
FcL->wData[15][2]=89;
FcL->wData[15][3]=142;
FcL->wData[15][4]=-74;
FcL->wData[15][5]=100;
FcL->wData[15][6]=126;
FcL->wData[15][7]=-30;
FcL->wData[15][8]=109;
FcL->wData[15][9]=127;
FcL->wData[15][10]=-63;
FcL->wData[15][11]=-5;
FcL->wData[15][12]=1;
FcL->wData[15][13]=-147;
FcL->wData[15][14]=45;
FcL->wData[15][15]=70;
FcL->wData[15][16]=-36;
FcL->wData[15][17]=142;
FcL->wData[15][18]=33;
FcL->wData[15][19]=160;
FcL->wData[15][20]=3;
FcL->wData[15][21]=64;
FcL->wData[15][22]=17;
FcL->wData[15][23]=74;
FcL->wData[15][24]=23;
FcL->wData[15][25]=-146;
FcL->wData[15][26]=209;
FcL->wData[15][27]=-123;
FcL->wData[15][28]=-147;
FcL->wData[15][29]=-24;
FcL->wData[15][30]=-31;
FcL->wData[15][31]=-75;
FcL->wData[15][32]=165;
FcL->wData[15][33]=-105;
FcL->wData[15][34]=34;
FcL->wData[15][35]=-158;
FcL->wData[15][36]=112;
FcL->wData[15][37]=222;
FcL->wData[15][38]=157;
FcL->wData[15][39]=177;
FcL->wData[15][40]=39;
FcL->wData[15][41]=-75;
FcL->wData[15][42]=308;
FcL->wData[15][43]=-216;
FcL->wData[15][44]=106;
FcL->wData[15][45]=-55;
FcL->wData[15][46]=-175;
FcL->wData[15][47]=139;
FcL->wData[15][48]=-200;
FcL->wData[15][49]=126;
FcL->wData[15][50]=349;
FcL->wData[15][51]=32;
FcL->wData[15][52]=-176;
FcL->wData[15][53]=126;
FcL->wData[15][54]=-128;
FcL->wData[15][55]=-359;
FcL->wData[15][56]=-55;
FcL->wData[15][57]=-93;
FcL->wData[15][58]=11;
FcL->wData[15][59]=54;
FcL->wData[15][60]=236;
FcL->wData[15][61]=-265;
FcL->wData[15][62]=-121;
FcL->wData[15][63]=-138;
FcL->wData[15][64]=431;
FcL->wData[15][65]=25;
FcL->wData[15][66]=-48;
FcL->wData[15][67]=-166;
FcL->wData[15][68]=34;
FcL->wData[15][69]=149;
FcL->wData[15][70]=-130;
FcL->wData[15][71]=132;
FcL->wData[15][72]=208;
FcL->wData[15][73]=49;
FcL->wData[15][74]=-248;
FcL->wData[15][75]=-21;
FcL->wData[15][76]=-573;
FcL->wData[15][77]=-57;
FcL->wData[15][78]=-351;
FcL->wData[15][79]=171;
FcL->wData[15][80]=-71;
FcL->wData[16][0]=-15;
FcL->wData[16][1]=-34;
FcL->wData[16][2]=43;
FcL->wData[16][3]=108;
FcL->wData[16][4]=52;
FcL->wData[16][5]=-149;
FcL->wData[16][6]=44;
FcL->wData[16][7]=-138;
FcL->wData[16][8]=193;
FcL->wData[16][9]=35;
FcL->wData[16][10]=97;
FcL->wData[16][11]=-97;
FcL->wData[16][12]=34;
FcL->wData[16][13]=-39;
FcL->wData[16][14]=150;
FcL->wData[16][15]=153;
FcL->wData[16][16]=115;
FcL->wData[16][17]=-61;
FcL->wData[16][18]=309;
FcL->wData[16][19]=-51;
FcL->wData[16][20]=91;
FcL->wData[16][21]=-10;
FcL->wData[16][22]=-96;
FcL->wData[16][23]=165;
FcL->wData[16][24]=263;
FcL->wData[16][25]=-22;
FcL->wData[16][26]=-201;
FcL->wData[16][27]=164;
FcL->wData[16][28]=-21;
FcL->wData[16][29]=-24;
FcL->wData[16][30]=-271;
FcL->wData[16][31]=109;
FcL->wData[16][32]=-171;
FcL->wData[16][33]=13;
FcL->wData[16][34]=-109;
FcL->wData[16][35]=108;
FcL->wData[16][36]=2;
FcL->wData[16][37]=32;
FcL->wData[16][38]=-231;
FcL->wData[16][39]=-144;
FcL->wData[16][40]=-2;
FcL->wData[16][41]=33;
FcL->wData[16][42]=3;
FcL->wData[16][43]=152;
FcL->wData[16][44]=35;
FcL->wData[16][45]=-22;
FcL->wData[16][46]=-235;
FcL->wData[16][47]=-166;
FcL->wData[16][48]=-38;
FcL->wData[16][49]=52;
FcL->wData[16][50]=-115;
FcL->wData[16][51]=-105;
FcL->wData[16][52]=137;
FcL->wData[16][53]=171;
FcL->wData[16][54]=49;
FcL->wData[16][55]=97;
FcL->wData[16][56]=189;
FcL->wData[16][57]=-65;
FcL->wData[16][58]=179;
FcL->wData[16][59]=-129;
FcL->wData[16][60]=-127;
FcL->wData[16][61]=218;
FcL->wData[16][62]=285;
FcL->wData[16][63]=-94;
FcL->wData[16][64]=223;
FcL->wData[16][65]=21;
FcL->wData[16][66]=14;
FcL->wData[16][67]=-68;
FcL->wData[16][68]=296;
FcL->wData[16][69]=34;
FcL->wData[16][70]=84;
FcL->wData[16][71]=-48;
FcL->wData[16][72]=134;
FcL->wData[16][73]=209;
FcL->wData[16][74]=-133;
FcL->wData[16][75]=-54;
FcL->wData[16][76]=-181;
FcL->wData[16][77]=-92;
FcL->wData[16][78]=-71;
FcL->wData[16][79]=134;
FcL->wData[16][80]=-10;
FcL->wData[17][0]=63;
FcL->wData[17][1]=-29;
FcL->wData[17][2]=-70;
FcL->wData[17][3]=4;
FcL->wData[17][4]=-218;
FcL->wData[17][5]=106;
FcL->wData[17][6]=-95;
FcL->wData[17][7]=193;
FcL->wData[17][8]=85;
FcL->wData[17][9]=4;
FcL->wData[17][10]=-250;
FcL->wData[17][11]=210;
FcL->wData[17][12]=16;
FcL->wData[17][13]=-256;
FcL->wData[17][14]=146;
FcL->wData[17][15]=81;
FcL->wData[17][16]=102;
FcL->wData[17][17]=-131;
FcL->wData[17][18]=3;
FcL->wData[17][19]=-214;
FcL->wData[17][20]=167;
FcL->wData[17][21]=276;
FcL->wData[17][22]=-73;
FcL->wData[17][23]=120;
FcL->wData[17][24]=72;
FcL->wData[17][25]=-84;
FcL->wData[17][26]=116;
FcL->wData[17][27]=42;
FcL->wData[17][28]=-114;
FcL->wData[17][29]=32;
FcL->wData[17][30]=-28;
FcL->wData[17][31]=-202;
FcL->wData[17][32]=139;
FcL->wData[17][33]=-156;
FcL->wData[17][34]=189;
FcL->wData[17][35]=-53;
FcL->wData[17][36]=-64;
FcL->wData[17][37]=339;
FcL->wData[17][38]=-169;
FcL->wData[17][39]=-132;
FcL->wData[17][40]=7;
FcL->wData[17][41]=26;
FcL->wData[17][42]=243;
FcL->wData[17][43]=2;
FcL->wData[17][44]=-45;
FcL->wData[17][45]=25;
FcL->wData[17][46]=-96;
FcL->wData[17][47]=138;
FcL->wData[17][48]=-24;
FcL->wData[17][49]=-209;
FcL->wData[17][50]=102;
FcL->wData[17][51]=-173;
FcL->wData[17][52]=225;
FcL->wData[17][53]=-183;
FcL->wData[17][54]=82;
FcL->wData[17][55]=56;
FcL->wData[17][56]=-160;
FcL->wData[17][57]=8;
FcL->wData[17][58]=-49;
FcL->wData[17][59]=188;
FcL->wData[17][60]=-62;
FcL->wData[17][61]=230;
FcL->wData[17][62]=-295;
FcL->wData[17][63]=42;
FcL->wData[17][64]=-182;
FcL->wData[17][65]=-108;
FcL->wData[17][66]=-329;
FcL->wData[17][67]=112;
FcL->wData[17][68]=32;
FcL->wData[17][69]=21;
FcL->wData[17][70]=-26;
FcL->wData[17][71]=-178;
FcL->wData[17][72]=-9;
FcL->wData[17][73]=-353;
FcL->wData[17][74]=-89;
FcL->wData[17][75]=124;
FcL->wData[17][76]=89;
FcL->wData[17][77]=-35;
FcL->wData[17][78]=-63;
FcL->wData[17][79]=-218;
FcL->wData[17][80]=-36;
FcL->wData[18][0]=86;
FcL->wData[18][1]=-282;
FcL->wData[18][2]=24;
FcL->wData[18][3]=373;
FcL->wData[18][4]=10;
FcL->wData[18][5]=-156;
FcL->wData[18][6]=106;
FcL->wData[18][7]=41;
FcL->wData[18][8]=-123;
FcL->wData[18][9]=66;
FcL->wData[18][10]=163;
FcL->wData[18][11]=109;
FcL->wData[18][12]=15;
FcL->wData[18][13]=-130;
FcL->wData[18][14]=79;
FcL->wData[18][15]=-92;
FcL->wData[18][16]=87;
FcL->wData[18][17]=-42;
FcL->wData[18][18]=28;
FcL->wData[18][19]=79;
FcL->wData[18][20]=-13;
FcL->wData[18][21]=-293;
FcL->wData[18][22]=-2;
FcL->wData[18][23]=-216;
FcL->wData[18][24]=-211;
FcL->wData[18][25]=95;
FcL->wData[18][26]=124;
FcL->wData[18][27]=116;
FcL->wData[18][28]=188;
FcL->wData[18][29]=-82;
FcL->wData[18][30]=188;
FcL->wData[18][31]=4;
FcL->wData[18][32]=-312;
FcL->wData[18][33]=169;
FcL->wData[18][34]=-163;
FcL->wData[18][35]=-236;
FcL->wData[18][36]=227;
FcL->wData[18][37]=186;
FcL->wData[18][38]=6;
FcL->wData[18][39]=-68;
FcL->wData[18][40]=269;
FcL->wData[18][41]=-14;
FcL->wData[18][42]=-69;
FcL->wData[18][43]=146;
FcL->wData[18][44]=-196;
FcL->wData[18][45]=-116;
FcL->wData[18][46]=-5;
FcL->wData[18][47]=66;
FcL->wData[18][48]=-178;
FcL->wData[18][49]=126;
FcL->wData[18][50]=68;
FcL->wData[18][51]=115;
FcL->wData[18][52]=-60;
FcL->wData[18][53]=193;
FcL->wData[18][54]=108;
FcL->wData[18][55]=-142;
FcL->wData[18][56]=29;
FcL->wData[18][57]=-52;
FcL->wData[18][58]=-51;
FcL->wData[18][59]=46;
FcL->wData[18][60]=-20;
FcL->wData[18][61]=-124;
FcL->wData[18][62]=-44;
FcL->wData[18][63]=120;
FcL->wData[18][64]=180;
FcL->wData[18][65]=104;
FcL->wData[18][66]=129;
FcL->wData[18][67]=-98;
FcL->wData[18][68]=222;
FcL->wData[18][69]=-64;
FcL->wData[18][70]=-220;
FcL->wData[18][71]=163;
FcL->wData[18][72]=414;
FcL->wData[18][73]=75;
FcL->wData[18][74]=-250;
FcL->wData[18][75]=192;
FcL->wData[18][76]=32;
FcL->wData[18][77]=-55;
FcL->wData[18][78]=197;
FcL->wData[18][79]=-52;
FcL->wData[18][80]=84;
FcL->wData[19][0]=-16;
FcL->wData[19][1]=30;
FcL->wData[19][2]=-45;
FcL->wData[19][3]=51;
FcL->wData[19][4]=-6;
FcL->wData[19][5]=165;
FcL->wData[19][6]=111;
FcL->wData[19][7]=21;
FcL->wData[19][8]=93;
FcL->wData[19][9]=-226;
FcL->wData[19][10]=178;
FcL->wData[19][11]=25;
FcL->wData[19][12]=-226;
FcL->wData[19][13]=183;
FcL->wData[19][14]=-199;
FcL->wData[19][15]=-233;
FcL->wData[19][16]=99;
FcL->wData[19][17]=-93;
FcL->wData[19][18]=76;
FcL->wData[19][19]=-22;
FcL->wData[19][20]=36;
FcL->wData[19][21]=-153;
FcL->wData[19][22]=65;
FcL->wData[19][23]=-73;
FcL->wData[19][24]=-163;
FcL->wData[19][25]=-140;
FcL->wData[19][26]=182;
FcL->wData[19][27]=-68;
FcL->wData[19][28]=-178;
FcL->wData[19][29]=53;
FcL->wData[19][30]=111;
FcL->wData[19][31]=-115;
FcL->wData[19][32]=0;
FcL->wData[19][33]=-68;
FcL->wData[19][34]=-1;
FcL->wData[19][35]=78;
FcL->wData[19][36]=-191;
FcL->wData[19][37]=-165;
FcL->wData[19][38]=-218;
FcL->wData[19][39]=-94;
FcL->wData[19][40]=20;
FcL->wData[19][41]=-168;
FcL->wData[19][42]=-211;
FcL->wData[19][43]=-198;
FcL->wData[19][44]=115;
FcL->wData[19][45]=-193;
FcL->wData[19][46]=-106;
FcL->wData[19][47]=-163;
FcL->wData[19][48]=163;
FcL->wData[19][49]=53;
FcL->wData[19][50]=140;
FcL->wData[19][51]=-155;
FcL->wData[19][52]=21;
FcL->wData[19][53]=75;
FcL->wData[19][54]=-169;
FcL->wData[19][55]=-109;
FcL->wData[19][56]=-226;
FcL->wData[19][57]=22;
FcL->wData[19][58]=87;
FcL->wData[19][59]=-72;
FcL->wData[19][60]=-1;
FcL->wData[19][61]=70;
FcL->wData[19][62]=88;
FcL->wData[19][63]=-123;
FcL->wData[19][64]=14;
FcL->wData[19][65]=131;
FcL->wData[19][66]=-41;
FcL->wData[19][67]=-85;
FcL->wData[19][68]=-79;
FcL->wData[19][69]=-7;
FcL->wData[19][70]=-123;
FcL->wData[19][71]=-129;
FcL->wData[19][72]=146;
FcL->wData[19][73]=57;
FcL->wData[19][74]=-22;
FcL->wData[19][75]=-190;
FcL->wData[19][76]=179;
FcL->wData[19][77]=-156;
FcL->wData[19][78]=-88;
FcL->wData[19][79]=-168;
FcL->wData[19][80]=-162;
FcL->wData[20][0]=23;
FcL->wData[20][1]=-62;
FcL->wData[20][2]=-202;
FcL->wData[20][3]=-364;
FcL->wData[20][4]=93;
FcL->wData[20][5]=37;
FcL->wData[20][6]=-187;
FcL->wData[20][7]=125;
FcL->wData[20][8]=16;
FcL->wData[20][9]=14;
FcL->wData[20][10]=23;
FcL->wData[20][11]=124;
FcL->wData[20][12]=-39;
FcL->wData[20][13]=-225;
FcL->wData[20][14]=-183;
FcL->wData[20][15]=-38;
FcL->wData[20][16]=87;
FcL->wData[20][17]=-273;
FcL->wData[20][18]=-90;
FcL->wData[20][19]=-44;
FcL->wData[20][20]=37;
FcL->wData[20][21]=390;
FcL->wData[20][22]=42;
FcL->wData[20][23]=-72;
FcL->wData[20][24]=28;
FcL->wData[20][25]=-140;
FcL->wData[20][26]=20;
FcL->wData[20][27]=-164;
FcL->wData[20][28]=213;
FcL->wData[20][29]=170;
FcL->wData[20][30]=-248;
FcL->wData[20][31]=-141;
FcL->wData[20][32]=119;
FcL->wData[20][33]=-461;
FcL->wData[20][34]=59;
FcL->wData[20][35]=-7;
FcL->wData[20][36]=-50;
FcL->wData[20][37]=78;
FcL->wData[20][38]=-35;
FcL->wData[20][39]=-238;
FcL->wData[20][40]=-69;
FcL->wData[20][41]=273;
FcL->wData[20][42]=33;
FcL->wData[20][43]=114;
FcL->wData[20][44]=182;
FcL->wData[20][45]=51;
FcL->wData[20][46]=73;
FcL->wData[20][47]=-11;
FcL->wData[20][48]=170;
FcL->wData[20][49]=-269;
FcL->wData[20][50]=-40;
FcL->wData[20][51]=-36;
FcL->wData[20][52]=82;
FcL->wData[20][53]=-121;
FcL->wData[20][54]=88;
FcL->wData[20][55]=-110;
FcL->wData[20][56]=254;
FcL->wData[20][57]=156;
FcL->wData[20][58]=246;
FcL->wData[20][59]=-131;
FcL->wData[20][60]=-185;
FcL->wData[20][61]=37;
FcL->wData[20][62]=8;
FcL->wData[20][63]=-112;
FcL->wData[20][64]=-131;
FcL->wData[20][65]=-36;
FcL->wData[20][66]=143;
FcL->wData[20][67]=145;
FcL->wData[20][68]=124;
FcL->wData[20][69]=101;
FcL->wData[20][70]=-39;
FcL->wData[20][71]=74;
FcL->wData[20][72]=-72;
FcL->wData[20][73]=-129;
FcL->wData[20][74]=54;
FcL->wData[20][75]=85;
FcL->wData[20][76]=182;
FcL->wData[20][77]=36;
FcL->wData[20][78]=164;
FcL->wData[20][79]=-72;
FcL->wData[20][80]=202;
FcL->wData[21][0]=99;
FcL->wData[21][1]=-3;
FcL->wData[21][2]=296;
FcL->wData[21][3]=-67;
FcL->wData[21][4]=304;
FcL->wData[21][5]=-113;
FcL->wData[21][6]=-41;
FcL->wData[21][7]=-56;
FcL->wData[21][8]=65;
FcL->wData[21][9]=-188;
FcL->wData[21][10]=-148;
FcL->wData[21][11]=51;
FcL->wData[21][12]=-15;
FcL->wData[21][13]=-18;
FcL->wData[21][14]=23;
FcL->wData[21][15]=68;
FcL->wData[21][16]=-197;
FcL->wData[21][17]=145;
FcL->wData[21][18]=224;
FcL->wData[21][19]=155;
FcL->wData[21][20]=18;
FcL->wData[21][21]=-28;
FcL->wData[21][22]=141;
FcL->wData[21][23]=378;
FcL->wData[21][24]=77;
FcL->wData[21][25]=59;
FcL->wData[21][26]=-205;
FcL->wData[21][27]=-151;
FcL->wData[21][28]=-62;
FcL->wData[21][29]=152;
FcL->wData[21][30]=186;
FcL->wData[21][31]=357;
FcL->wData[21][32]=-76;
FcL->wData[21][33]=251;
FcL->wData[21][34]=-49;
FcL->wData[21][35]=69;
FcL->wData[21][36]=-151;
FcL->wData[21][37]=-378;
FcL->wData[21][38]=48;
FcL->wData[21][39]=190;
FcL->wData[21][40]=-257;
FcL->wData[21][41]=237;
FcL->wData[21][42]=-198;
FcL->wData[21][43]=-171;
FcL->wData[21][44]=116;
FcL->wData[21][45]=196;
FcL->wData[21][46]=-23;
FcL->wData[21][47]=-279;
FcL->wData[21][48]=188;
FcL->wData[21][49]=251;
FcL->wData[21][50]=-20;
FcL->wData[21][51]=47;
FcL->wData[21][52]=-162;
FcL->wData[21][53]=81;
FcL->wData[21][54]=73;
FcL->wData[21][55]=225;
FcL->wData[21][56]=372;
FcL->wData[21][57]=-160;
FcL->wData[21][58]=24;
FcL->wData[21][59]=-60;
FcL->wData[21][60]=62;
FcL->wData[21][61]=35;
FcL->wData[21][62]=-55;
FcL->wData[21][63]=24;
FcL->wData[21][64]=370;
FcL->wData[21][65]=95;
FcL->wData[21][66]=-262;
FcL->wData[21][67]=-70;
FcL->wData[21][68]=-60;
FcL->wData[21][69]=258;
FcL->wData[21][70]=99;
FcL->wData[21][71]=8;
FcL->wData[21][72]=-46;
FcL->wData[21][73]=143;
FcL->wData[21][74]=58;
FcL->wData[21][75]=-373;
FcL->wData[21][76]=36;
FcL->wData[21][77]=-169;
FcL->wData[21][78]=123;
FcL->wData[21][79]=211;
FcL->wData[21][80]=-130;
FcL->wData[22][0]=-165;
FcL->wData[22][1]=-52;
FcL->wData[22][2]=-147;
FcL->wData[22][3]=142;
FcL->wData[22][4]=-85;
FcL->wData[22][5]=-22;
FcL->wData[22][6]=-83;
FcL->wData[22][7]=-230;
FcL->wData[22][8]=-160;
FcL->wData[22][9]=-186;
FcL->wData[22][10]=-164;
FcL->wData[22][11]=-226;
FcL->wData[22][12]=113;
FcL->wData[22][13]=-13;
FcL->wData[22][14]=-208;
FcL->wData[22][15]=-65;
FcL->wData[22][16]=-51;
FcL->wData[22][17]=-183;
FcL->wData[22][18]=173;
FcL->wData[22][19]=7;
FcL->wData[22][20]=-176;
FcL->wData[22][21]=86;
FcL->wData[22][22]=-77;
FcL->wData[22][23]=-187;
FcL->wData[22][24]=-192;
FcL->wData[22][25]=130;
FcL->wData[22][26]=-60;
FcL->wData[22][27]=131;
FcL->wData[22][28]=-21;
FcL->wData[22][29]=-154;
FcL->wData[22][30]=-74;
FcL->wData[22][31]=-39;
FcL->wData[22][32]=-193;
FcL->wData[22][33]=-113;
FcL->wData[22][34]=29;
FcL->wData[22][35]=-61;
FcL->wData[22][36]=-252;
FcL->wData[22][37]=-88;
FcL->wData[22][38]=47;
FcL->wData[22][39]=-97;
FcL->wData[22][40]=114;
FcL->wData[22][41]=100;
FcL->wData[22][42]=138;
FcL->wData[22][43]=-12;
FcL->wData[22][44]=-62;
FcL->wData[22][45]=-121;
FcL->wData[22][46]=-6;
FcL->wData[22][47]=35;
FcL->wData[22][48]=-88;
FcL->wData[22][49]=80;
FcL->wData[22][50]=174;
FcL->wData[22][51]=-113;
FcL->wData[22][52]=-3;
FcL->wData[22][53]=-19;
FcL->wData[22][54]=-90;
FcL->wData[22][55]=69;
FcL->wData[22][56]=-103;
FcL->wData[22][57]=-80;
FcL->wData[22][58]=-123;
FcL->wData[22][59]=-168;
FcL->wData[22][60]=-195;
FcL->wData[22][61]=24;
FcL->wData[22][62]=105;
FcL->wData[22][63]=-244;
FcL->wData[22][64]=68;
FcL->wData[22][65]=73;
FcL->wData[22][66]=-104;
FcL->wData[22][67]=151;
FcL->wData[22][68]=94;
FcL->wData[22][69]=65;
FcL->wData[22][70]=112;
FcL->wData[22][71]=153;
FcL->wData[22][72]=-226;
FcL->wData[22][73]=11;
FcL->wData[22][74]=-137;
FcL->wData[22][75]=-29;
FcL->wData[22][76]=180;
FcL->wData[22][77]=40;
FcL->wData[22][78]=-155;
FcL->wData[22][79]=-66;
FcL->wData[22][80]=-233;
FcL->wData[23][0]=79;
FcL->wData[23][1]=-133;
FcL->wData[23][2]=139;
FcL->wData[23][3]=78;
FcL->wData[23][4]=91;
FcL->wData[23][5]=253;
FcL->wData[23][6]=147;
FcL->wData[23][7]=125;
FcL->wData[23][8]=-103;
FcL->wData[23][9]=-74;
FcL->wData[23][10]=192;
FcL->wData[23][11]=4;
FcL->wData[23][12]=-17;
FcL->wData[23][13]=-222;
FcL->wData[23][14]=51;
FcL->wData[23][15]=178;
FcL->wData[23][16]=95;
FcL->wData[23][17]=-294;
FcL->wData[23][18]=301;
FcL->wData[23][19]=247;
FcL->wData[23][20]=169;
FcL->wData[23][21]=225;
FcL->wData[23][22]=18;
FcL->wData[23][23]=-56;
FcL->wData[23][24]=39;
FcL->wData[23][25]=38;
FcL->wData[23][26]=119;
FcL->wData[23][27]=-265;
FcL->wData[23][28]=-228;
FcL->wData[23][29]=87;
FcL->wData[23][30]=39;
FcL->wData[23][31]=262;
FcL->wData[23][32]=5;
FcL->wData[23][33]=-96;
FcL->wData[23][34]=146;
FcL->wData[23][35]=-111;
FcL->wData[23][36]=213;
FcL->wData[23][37]=-362;
FcL->wData[23][38]=140;
FcL->wData[23][39]=79;
FcL->wData[23][40]=-484;
FcL->wData[23][41]=74;
FcL->wData[23][42]=-158;
FcL->wData[23][43]=-181;
FcL->wData[23][44]=332;
FcL->wData[23][45]=77;
FcL->wData[23][46]=-142;
FcL->wData[23][47]=-98;
FcL->wData[23][48]=15;
FcL->wData[23][49]=178;
FcL->wData[23][50]=-151;
FcL->wData[23][51]=109;
FcL->wData[23][52]=-179;
FcL->wData[23][53]=-22;
FcL->wData[23][54]=-175;
FcL->wData[23][55]=245;
FcL->wData[23][56]=41;
FcL->wData[23][57]=-58;
FcL->wData[23][58]=-90;
FcL->wData[23][59]=-103;
FcL->wData[23][60]=338;
FcL->wData[23][61]=-112;
FcL->wData[23][62]=116;
FcL->wData[23][63]=-126;
FcL->wData[23][64]=82;
FcL->wData[23][65]=196;
FcL->wData[23][66]=-50;
FcL->wData[23][67]=242;
FcL->wData[23][68]=60;
FcL->wData[23][69]=4;
FcL->wData[23][70]=324;
FcL->wData[23][71]=-139;
FcL->wData[23][72]=2;
FcL->wData[23][73]=170;
FcL->wData[23][74]=97;
FcL->wData[23][75]=-170;
FcL->wData[23][76]=-70;
FcL->wData[23][77]=-152;
FcL->wData[23][78]=100;
FcL->wData[23][79]=130;
FcL->wData[23][80]=-19;
FcL->wData[24][0]=-30;
FcL->wData[24][1]=-121;
FcL->wData[24][2]=173;
FcL->wData[24][3]=358;
FcL->wData[24][4]=71;
FcL->wData[24][5]=124;
FcL->wData[24][6]=-77;
FcL->wData[24][7]=222;
FcL->wData[24][8]=123;
FcL->wData[24][9]=-372;
FcL->wData[24][10]=-107;
FcL->wData[24][11]=-42;
FcL->wData[24][12]=175;
FcL->wData[24][13]=93;
FcL->wData[24][14]=93;
FcL->wData[24][15]=128;
FcL->wData[24][16]=-10;
FcL->wData[24][17]=20;
FcL->wData[24][18]=-3;
FcL->wData[24][19]=-154;
FcL->wData[24][20]=109;
FcL->wData[24][21]=-49;
FcL->wData[24][22]=162;
FcL->wData[24][23]=78;
FcL->wData[24][24]=123;
FcL->wData[24][25]=177;
FcL->wData[24][26]=158;
FcL->wData[24][27]=126;
FcL->wData[24][28]=142;
FcL->wData[24][29]=-31;
FcL->wData[24][30]=193;
FcL->wData[24][31]=-63;
FcL->wData[24][32]=66;
FcL->wData[24][33]=-186;
FcL->wData[24][34]=-108;
FcL->wData[24][35]=301;
FcL->wData[24][36]=-31;
FcL->wData[24][37]=141;
FcL->wData[24][38]=62;
FcL->wData[24][39]=-158;
FcL->wData[24][40]=-320;
FcL->wData[24][41]=33;
FcL->wData[24][42]=-137;
FcL->wData[24][43]=-160;
FcL->wData[24][44]=182;
FcL->wData[24][45]=47;
FcL->wData[24][46]=7;
FcL->wData[24][47]=147;
FcL->wData[24][48]=241;
FcL->wData[24][49]=-186;
FcL->wData[24][50]=-160;
FcL->wData[24][51]=-100;
FcL->wData[24][52]=9;
FcL->wData[24][53]=157;
FcL->wData[24][54]=-125;
FcL->wData[24][55]=-174;
FcL->wData[24][56]=187;
FcL->wData[24][57]=29;
FcL->wData[24][58]=128;
FcL->wData[24][59]=12;
FcL->wData[24][60]=-563;
FcL->wData[24][61]=90;
FcL->wData[24][62]=-176;
FcL->wData[24][63]=-169;
FcL->wData[24][64]=67;
FcL->wData[24][65]=140;
FcL->wData[24][66]=121;
FcL->wData[24][67]=270;
FcL->wData[24][68]=0;
FcL->wData[24][69]=-203;
FcL->wData[24][70]=14;
FcL->wData[24][71]=68;
FcL->wData[24][72]=-236;
FcL->wData[24][73]=48;
FcL->wData[24][74]=22;
FcL->wData[24][75]=-15;
FcL->wData[24][76]=-36;
FcL->wData[24][77]=118;
FcL->wData[24][78]=163;
FcL->wData[24][79]=-67;
FcL->wData[24][80]=-51;
FcL->wData[25][0]=-404;
FcL->wData[25][1]=-119;
FcL->wData[25][2]=149;
FcL->wData[25][3]=478;
FcL->wData[25][4]=126;
FcL->wData[25][5]=-13;
FcL->wData[25][6]=-70;
FcL->wData[25][7]=-311;
FcL->wData[25][8]=89;
FcL->wData[25][9]=362;
FcL->wData[25][10]=-116;
FcL->wData[25][11]=-219;
FcL->wData[25][12]=336;
FcL->wData[25][13]=212;
FcL->wData[25][14]=-45;
FcL->wData[25][15]=119;
FcL->wData[25][16]=105;
FcL->wData[25][17]=-37;
FcL->wData[25][18]=147;
FcL->wData[25][19]=-85;
FcL->wData[25][20]=82;
FcL->wData[25][21]=108;
FcL->wData[25][22]=133;
FcL->wData[25][23]=-272;
FcL->wData[25][24]=95;
FcL->wData[25][25]=48;
FcL->wData[25][26]=-97;
FcL->wData[25][27]=111;
FcL->wData[25][28]=-19;
FcL->wData[25][29]=-331;
FcL->wData[25][30]=-103;
FcL->wData[25][31]=-477;
FcL->wData[25][32]=13;
FcL->wData[25][33]=26;
FcL->wData[25][34]=80;
FcL->wData[25][35]=73;
FcL->wData[25][36]=146;
FcL->wData[25][37]=-76;
FcL->wData[25][38]=78;
FcL->wData[25][39]=-139;
FcL->wData[25][40]=165;
FcL->wData[25][41]=-40;
FcL->wData[25][42]=47;
FcL->wData[25][43]=177;
FcL->wData[25][44]=24;
FcL->wData[25][45]=-221;
FcL->wData[25][46]=-323;
FcL->wData[25][47]=4;
FcL->wData[25][48]=-180;
FcL->wData[25][49]=-134;
FcL->wData[25][50]=25;
FcL->wData[25][51]=-233;
FcL->wData[25][52]=94;
FcL->wData[25][53]=-97;
FcL->wData[25][54]=-50;
FcL->wData[25][55]=-8;
FcL->wData[25][56]=-155;
FcL->wData[25][57]=-23;
FcL->wData[25][58]=0;
FcL->wData[25][59]=31;
FcL->wData[25][60]=-237;
FcL->wData[25][61]=4;
FcL->wData[25][62]=-29;
FcL->wData[25][63]=18;
FcL->wData[25][64]=-180;
FcL->wData[25][65]=-165;
FcL->wData[25][66]=60;
FcL->wData[25][67]=57;
FcL->wData[25][68]=45;
FcL->wData[25][69]=-150;
FcL->wData[25][70]=160;
FcL->wData[25][71]=-116;
FcL->wData[25][72]=-91;
FcL->wData[25][73]=-123;
FcL->wData[25][74]=-100;
FcL->wData[25][75]=247;
FcL->wData[25][76]=285;
FcL->wData[25][77]=-161;
FcL->wData[25][78]=311;
FcL->wData[25][79]=-137;
FcL->wData[25][80]=51;
FcL->wData[26][0]=-83;
FcL->wData[26][1]=-42;
FcL->wData[26][2]=132;
FcL->wData[26][3]=-330;
FcL->wData[26][4]=175;
FcL->wData[26][5]=-65;
FcL->wData[26][6]=168;
FcL->wData[26][7]=62;
FcL->wData[26][8]=67;
FcL->wData[26][9]=182;
FcL->wData[26][10]=-104;
FcL->wData[26][11]=-8;
FcL->wData[26][12]=-229;
FcL->wData[26][13]=33;
FcL->wData[26][14]=185;
FcL->wData[26][15]=-164;
FcL->wData[26][16]=114;
FcL->wData[26][17]=49;
FcL->wData[26][18]=158;
FcL->wData[26][19]=115;
FcL->wData[26][20]=268;
FcL->wData[26][21]=-84;
FcL->wData[26][22]=41;
FcL->wData[26][23]=40;
FcL->wData[26][24]=-79;
FcL->wData[26][25]=119;
FcL->wData[26][26]=19;
FcL->wData[26][27]=-54;
FcL->wData[26][28]=-129;
FcL->wData[26][29]=43;
FcL->wData[26][30]=-127;
FcL->wData[26][31]=102;
FcL->wData[26][32]=-64;
FcL->wData[26][33]=173;
FcL->wData[26][34]=23;
FcL->wData[26][35]=-193;
FcL->wData[26][36]=118;
FcL->wData[26][37]=-262;
FcL->wData[26][38]=-331;
FcL->wData[26][39]=-111;
FcL->wData[26][40]=17;
FcL->wData[26][41]=164;
FcL->wData[26][42]=-306;
FcL->wData[26][43]=-46;
FcL->wData[26][44]=-28;
FcL->wData[26][45]=-197;
FcL->wData[26][46]=-110;
FcL->wData[26][47]=-325;
FcL->wData[26][48]=-67;
FcL->wData[26][49]=233;
FcL->wData[26][50]=56;
FcL->wData[26][51]=-127;
FcL->wData[26][52]=-74;
FcL->wData[26][53]=-16;
FcL->wData[26][54]=-51;
FcL->wData[26][55]=45;
FcL->wData[26][56]=124;
FcL->wData[26][57]=-165;
FcL->wData[26][58]=111;
FcL->wData[26][59]=-105;
FcL->wData[26][60]=220;
FcL->wData[26][61]=-127;
FcL->wData[26][62]=121;
FcL->wData[26][63]=49;
FcL->wData[26][64]=138;
FcL->wData[26][65]=69;
FcL->wData[26][66]=-21;
FcL->wData[26][67]=-10;
FcL->wData[26][68]=166;
FcL->wData[26][69]=48;
FcL->wData[26][70]=86;
FcL->wData[26][71]=117;
FcL->wData[26][72]=120;
FcL->wData[26][73]=328;
FcL->wData[26][74]=-154;
FcL->wData[26][75]=-372;
FcL->wData[26][76]=-362;
FcL->wData[26][77]=60;
FcL->wData[26][78]=-246;
FcL->wData[26][79]=137;
FcL->wData[26][80]=-496;
FcL->wData[27][0]=100;
FcL->wData[27][1]=48;
FcL->wData[27][2]=72;
FcL->wData[27][3]=101;
FcL->wData[27][4]=75;
FcL->wData[27][5]=-225;
FcL->wData[27][6]=-404;
FcL->wData[27][7]=86;
FcL->wData[27][8]=-156;
FcL->wData[27][9]=-161;
FcL->wData[27][10]=-12;
FcL->wData[27][11]=-142;
FcL->wData[27][12]=16;
FcL->wData[27][13]=-2;
FcL->wData[27][14]=284;
FcL->wData[27][15]=-274;
FcL->wData[27][16]=74;
FcL->wData[27][17]=94;
FcL->wData[27][18]=-208;
FcL->wData[27][19]=-67;
FcL->wData[27][20]=-35;
FcL->wData[27][21]=186;
FcL->wData[27][22]=196;
FcL->wData[27][23]=131;
FcL->wData[27][24]=-205;
FcL->wData[27][25]=33;
FcL->wData[27][26]=-87;
FcL->wData[27][27]=-1;
FcL->wData[27][28]=-137;
FcL->wData[27][29]=-53;
FcL->wData[27][30]=-3;
FcL->wData[27][31]=250;
FcL->wData[27][32]=-6;
FcL->wData[27][33]=-73;
FcL->wData[27][34]=138;
FcL->wData[27][35]=163;
FcL->wData[27][36]=17;
FcL->wData[27][37]=96;
FcL->wData[27][38]=-126;
FcL->wData[27][39]=159;
FcL->wData[27][40]=14;
FcL->wData[27][41]=55;
FcL->wData[27][42]=363;
FcL->wData[27][43]=-217;
FcL->wData[27][44]=210;
FcL->wData[27][45]=66;
FcL->wData[27][46]=-107;
FcL->wData[27][47]=-137;
FcL->wData[27][48]=-267;
FcL->wData[27][49]=139;
FcL->wData[27][50]=-87;
FcL->wData[27][51]=60;
FcL->wData[27][52]=17;
FcL->wData[27][53]=-125;
FcL->wData[27][54]=-106;
FcL->wData[27][55]=-21;
FcL->wData[27][56]=227;
FcL->wData[27][57]=107;
FcL->wData[27][58]=43;
FcL->wData[27][59]=119;
FcL->wData[27][60]=246;
FcL->wData[27][61]=9;
FcL->wData[27][62]=50;
FcL->wData[27][63]=-209;
FcL->wData[27][64]=111;
FcL->wData[27][65]=119;
FcL->wData[27][66]=126;
FcL->wData[27][67]=-269;
FcL->wData[27][68]=-67;
FcL->wData[27][69]=247;
FcL->wData[27][70]=-8;
FcL->wData[27][71]=272;
FcL->wData[27][72]=-31;
FcL->wData[27][73]=-6;
FcL->wData[27][74]=-88;
FcL->wData[27][75]=-129;
FcL->wData[27][76]=112;
FcL->wData[27][77]=83;
FcL->wData[27][78]=286;
FcL->wData[27][79]=145;
FcL->wData[27][80]=88;
FcL->wData[28][0]=-98;
FcL->wData[28][1]=36;
FcL->wData[28][2]=309;
FcL->wData[28][3]=69;
FcL->wData[28][4]=210;
FcL->wData[28][5]=186;
FcL->wData[28][6]=-187;
FcL->wData[28][7]=178;
FcL->wData[28][8]=71;
FcL->wData[28][9]=3;
FcL->wData[28][10]=-136;
FcL->wData[28][11]=85;
FcL->wData[28][12]=-38;
FcL->wData[28][13]=-198;
FcL->wData[28][14]=-138;
FcL->wData[28][15]=-108;
FcL->wData[28][16]=-32;
FcL->wData[28][17]=-204;
FcL->wData[28][18]=205;
FcL->wData[28][19]=111;
FcL->wData[28][20]=-90;
FcL->wData[28][21]=-68;
FcL->wData[28][22]=-18;
FcL->wData[28][23]=-157;
FcL->wData[28][24]=63;
FcL->wData[28][25]=83;
FcL->wData[28][26]=-198;
FcL->wData[28][27]=-79;
FcL->wData[28][28]=-215;
FcL->wData[28][29]=293;
FcL->wData[28][30]=130;
FcL->wData[28][31]=-15;
FcL->wData[28][32]=129;
FcL->wData[28][33]=219;
FcL->wData[28][34]=-112;
FcL->wData[28][35]=19;
FcL->wData[28][36]=-175;
FcL->wData[28][37]=-145;
FcL->wData[28][38]=202;
FcL->wData[28][39]=-114;
FcL->wData[28][40]=-284;
FcL->wData[28][41]=28;
FcL->wData[28][42]=-89;
FcL->wData[28][43]=-34;
FcL->wData[28][44]=244;
FcL->wData[28][45]=-107;
FcL->wData[28][46]=-79;
FcL->wData[28][47]=180;
FcL->wData[28][48]=82;
FcL->wData[28][49]=231;
FcL->wData[28][50]=-158;
FcL->wData[28][51]=204;
FcL->wData[28][52]=-282;
FcL->wData[28][53]=46;
FcL->wData[28][54]=-11;
FcL->wData[28][55]=196;
FcL->wData[28][56]=183;
FcL->wData[28][57]=27;
FcL->wData[28][58]=-29;
FcL->wData[28][59]=-175;
FcL->wData[28][60]=499;
FcL->wData[28][61]=-223;
FcL->wData[28][62]=119;
FcL->wData[28][63]=-56;
FcL->wData[28][64]=83;
FcL->wData[28][65]=135;
FcL->wData[28][66]=-101;
FcL->wData[28][67]=157;
FcL->wData[28][68]=77;
FcL->wData[28][69]=87;
FcL->wData[28][70]=325;
FcL->wData[28][71]=152;
FcL->wData[28][72]=-19;
FcL->wData[28][73]=114;
FcL->wData[28][74]=-110;
FcL->wData[28][75]=9;
FcL->wData[28][76]=267;
FcL->wData[28][77]=287;
FcL->wData[28][78]=210;
FcL->wData[28][79]=7;
FcL->wData[28][80]=121;
FcL->wData[29][0]=0;
FcL->wData[29][1]=129;
FcL->wData[29][2]=-204;
FcL->wData[29][3]=135;
FcL->wData[29][4]=-236;
FcL->wData[29][5]=150;
FcL->wData[29][6]=188;
FcL->wData[29][7]=-221;
FcL->wData[29][8]=63;
FcL->wData[29][9]=-165;
FcL->wData[29][10]=87;
FcL->wData[29][11]=-126;
FcL->wData[29][12]=-100;
FcL->wData[29][13]=117;
FcL->wData[29][14]=13;
FcL->wData[29][15]=-74;
FcL->wData[29][16]=-12;
FcL->wData[29][17]=2;
FcL->wData[29][18]=-4;
FcL->wData[29][19]=143;
FcL->wData[29][20]=3;
FcL->wData[29][21]=120;
FcL->wData[29][22]=-13;
FcL->wData[29][23]=-217;
FcL->wData[29][24]=-56;
FcL->wData[29][25]=-1;
FcL->wData[29][26]=-103;
FcL->wData[29][27]=-196;
FcL->wData[29][28]=43;
FcL->wData[29][29]=169;
FcL->wData[29][30]=13;
FcL->wData[29][31]=-106;
FcL->wData[29][32]=-126;
FcL->wData[29][33]=-213;
FcL->wData[29][34]=19;
FcL->wData[29][35]=-104;
FcL->wData[29][36]=54;
FcL->wData[29][37]=65;
FcL->wData[29][38]=-129;
FcL->wData[29][39]=119;
FcL->wData[29][40]=-186;
FcL->wData[29][41]=-137;
FcL->wData[29][42]=113;
FcL->wData[29][43]=-87;
FcL->wData[29][44]=49;
FcL->wData[29][45]=-255;
FcL->wData[29][46]=-142;
FcL->wData[29][47]=145;
FcL->wData[29][48]=-170;
FcL->wData[29][49]=-215;
FcL->wData[29][50]=-218;
FcL->wData[29][51]=-10;
FcL->wData[29][52]=174;
FcL->wData[29][53]=-91;
FcL->wData[29][54]=-165;
FcL->wData[29][55]=107;
FcL->wData[29][56]=80;
FcL->wData[29][57]=-76;
FcL->wData[29][58]=168;
FcL->wData[29][59]=153;
FcL->wData[29][60]=-169;
FcL->wData[29][61]=-50;
FcL->wData[29][62]=20;
FcL->wData[29][63]=188;
FcL->wData[29][64]=87;
FcL->wData[29][65]=-104;
FcL->wData[29][66]=-258;
FcL->wData[29][67]=-206;
FcL->wData[29][68]=-64;
FcL->wData[29][69]=-217;
FcL->wData[29][70]=37;
FcL->wData[29][71]=-186;
FcL->wData[29][72]=1;
FcL->wData[29][73]=-162;
FcL->wData[29][74]=178;
FcL->wData[29][75]=-35;
FcL->wData[29][76]=-132;
FcL->wData[29][77]=-181;
FcL->wData[29][78]=187;
FcL->wData[29][79]=-80;
FcL->wData[29][80]=175;
FcL->wData[30][0]=-103;
FcL->wData[30][1]=90;
FcL->wData[30][2]=225;
FcL->wData[30][3]=-483;
FcL->wData[30][4]=273;
FcL->wData[30][5]=112;
FcL->wData[30][6]=506;
FcL->wData[30][7]=41;
FcL->wData[30][8]=41;
FcL->wData[30][9]=90;
FcL->wData[30][10]=-63;
FcL->wData[30][11]=16;
FcL->wData[30][12]=-31;
FcL->wData[30][13]=-22;
FcL->wData[30][14]=-143;
FcL->wData[30][15]=199;
FcL->wData[30][16]=143;
FcL->wData[30][17]=-132;
FcL->wData[30][18]=294;
FcL->wData[30][19]=208;
FcL->wData[30][20]=162;
FcL->wData[30][21]=-29;
FcL->wData[30][22]=-98;
FcL->wData[30][23]=-219;
FcL->wData[30][24]=85;
FcL->wData[30][25]=36;
FcL->wData[30][26]=14;
FcL->wData[30][27]=243;
FcL->wData[30][28]=40;
FcL->wData[30][29]=12;
FcL->wData[30][30]=152;
FcL->wData[30][31]=-29;
FcL->wData[30][32]=-220;
FcL->wData[30][33]=-2;
FcL->wData[30][34]=-60;
FcL->wData[30][35]=-174;
FcL->wData[30][36]=-229;
FcL->wData[30][37]=-44;
FcL->wData[30][38]=-110;
FcL->wData[30][39]=-93;
FcL->wData[30][40]=160;
FcL->wData[30][41]=175;
FcL->wData[30][42]=251;
FcL->wData[30][43]=127;
FcL->wData[30][44]=-243;
FcL->wData[30][45]=234;
FcL->wData[30][46]=130;
FcL->wData[30][47]=77;
FcL->wData[30][48]=488;
FcL->wData[30][49]=261;
FcL->wData[30][50]=-37;
FcL->wData[30][51]=102;
FcL->wData[30][52]=123;
FcL->wData[30][53]=5;
FcL->wData[30][54]=-120;
FcL->wData[30][55]=-87;
FcL->wData[30][56]=2;
FcL->wData[30][57]=-6;
FcL->wData[30][58]=141;
FcL->wData[30][59]=6;
FcL->wData[30][60]=-206;
FcL->wData[30][61]=95;
FcL->wData[30][62]=-16;
FcL->wData[30][63]=-187;
FcL->wData[30][64]=15;
FcL->wData[30][65]=-155;
FcL->wData[30][66]=211;
FcL->wData[30][67]=-168;
FcL->wData[30][68]=166;
FcL->wData[30][69]=48;
FcL->wData[30][70]=-211;
FcL->wData[30][71]=132;
FcL->wData[30][72]=119;
FcL->wData[30][73]=392;
FcL->wData[30][74]=-58;
FcL->wData[30][75]=69;
FcL->wData[30][76]=-269;
FcL->wData[30][77]=-184;
FcL->wData[30][78]=40;
FcL->wData[30][79]=-136;
FcL->wData[30][80]=1;
FcL->wData[31][0]=-164;
FcL->wData[31][1]=-113;
FcL->wData[31][2]=-103;
FcL->wData[31][3]=-499;
FcL->wData[31][4]=-357;
FcL->wData[31][5]=51;
FcL->wData[31][6]=187;
FcL->wData[31][7]=134;
FcL->wData[31][8]=-186;
FcL->wData[31][9]=121;
FcL->wData[31][10]=118;
FcL->wData[31][11]=67;
FcL->wData[31][12]=69;
FcL->wData[31][13]=-421;
FcL->wData[31][14]=-319;
FcL->wData[31][15]=50;
FcL->wData[31][16]=50;
FcL->wData[31][17]=-149;
FcL->wData[31][18]=312;
FcL->wData[31][19]=133;
FcL->wData[31][20]=70;
FcL->wData[31][21]=592;
FcL->wData[31][22]=-420;
FcL->wData[31][23]=-455;
FcL->wData[31][24]=-45;
FcL->wData[31][25]=-18;
FcL->wData[31][26]=44;
FcL->wData[31][27]=11;
FcL->wData[31][28]=-58;
FcL->wData[31][29]=-59;
FcL->wData[31][30]=-111;
FcL->wData[31][31]=-19;
FcL->wData[31][32]=97;
FcL->wData[31][33]=183;
FcL->wData[31][34]=106;
FcL->wData[31][35]=-132;
FcL->wData[31][36]=-134;
FcL->wData[31][37]=6;
FcL->wData[31][38]=-127;
FcL->wData[31][39]=-41;
FcL->wData[31][40]=143;
FcL->wData[31][41]=20;
FcL->wData[31][42]=389;
FcL->wData[31][43]=-140;
FcL->wData[31][44]=320;
FcL->wData[31][45]=-114;
FcL->wData[31][46]=22;
FcL->wData[31][47]=28;
FcL->wData[31][48]=4;
FcL->wData[31][49]=160;
FcL->wData[31][50]=137;
FcL->wData[31][51]=297;
FcL->wData[31][52]=-65;
FcL->wData[31][53]=134;
FcL->wData[31][54]=128;
FcL->wData[31][55]=-395;
FcL->wData[31][56]=-135;
FcL->wData[31][57]=7;
FcL->wData[31][58]=-78;
FcL->wData[31][59]=40;
FcL->wData[31][60]=310;
FcL->wData[31][61]=-16;
FcL->wData[31][62]=-12;
FcL->wData[31][63]=195;
FcL->wData[31][64]=-35;
FcL->wData[31][65]=75;
FcL->wData[31][66]=91;
FcL->wData[31][67]=-105;
FcL->wData[31][68]=-46;
FcL->wData[31][69]=-49;
FcL->wData[31][70]=17;
FcL->wData[31][71]=85;
FcL->wData[31][72]=99;
FcL->wData[31][73]=-39;
FcL->wData[31][74]=-144;
FcL->wData[31][75]=-328;
FcL->wData[31][76]=-332;
FcL->wData[31][77]=24;
FcL->wData[31][78]=-50;
FcL->wData[31][79]=147;
FcL->wData[31][80]=27;
FcL->wData[32][0]=9;
FcL->wData[32][1]=7;
FcL->wData[32][2]=79;
FcL->wData[32][3]=83;
FcL->wData[32][4]=-240;
FcL->wData[32][5]=44;
FcL->wData[32][6]=-137;
FcL->wData[32][7]=-104;
FcL->wData[32][8]=197;
FcL->wData[32][9]=62;
FcL->wData[32][10]=9;
FcL->wData[32][11]=113;
FcL->wData[32][12]=216;
FcL->wData[32][13]=-87;
FcL->wData[32][14]=134;
FcL->wData[32][15]=-145;
FcL->wData[32][16]=-200;
FcL->wData[32][17]=-93;
FcL->wData[32][18]=-109;
FcL->wData[32][19]=-169;
FcL->wData[32][20]=7;
FcL->wData[32][21]=29;
FcL->wData[32][22]=181;
FcL->wData[32][23]=1;
FcL->wData[32][24]=-45;
FcL->wData[32][25]=-77;
FcL->wData[32][26]=135;
FcL->wData[32][27]=73;
FcL->wData[32][28]=-30;
FcL->wData[32][29]=99;
FcL->wData[32][30]=51;
FcL->wData[32][31]=-28;
FcL->wData[32][32]=-10;
FcL->wData[32][33]=55;
FcL->wData[32][34]=183;
FcL->wData[32][35]=-11;
FcL->wData[32][36]=77;
FcL->wData[32][37]=59;
FcL->wData[32][38]=220;
FcL->wData[32][39]=-45;
FcL->wData[32][40]=219;
FcL->wData[32][41]=-133;
FcL->wData[32][42]=48;
FcL->wData[32][43]=-308;
FcL->wData[32][44]=-78;
FcL->wData[32][45]=131;
FcL->wData[32][46]=160;
FcL->wData[32][47]=-157;
FcL->wData[32][48]=-18;
FcL->wData[32][49]=39;
FcL->wData[32][50]=238;
FcL->wData[32][51]=18;
FcL->wData[32][52]=-48;
FcL->wData[32][53]=-51;
FcL->wData[32][54]=-187;
FcL->wData[32][55]=15;
FcL->wData[32][56]=-125;
FcL->wData[32][57]=89;
FcL->wData[32][58]=-177;
FcL->wData[32][59]=181;
FcL->wData[32][60]=319;
FcL->wData[32][61]=-153;
FcL->wData[32][62]=65;
FcL->wData[32][63]=191;
FcL->wData[32][64]=-61;
FcL->wData[32][65]=-40;
FcL->wData[32][66]=73;
FcL->wData[32][67]=-594;
FcL->wData[32][68]=129;
FcL->wData[32][69]=98;
FcL->wData[32][70]=-12;
FcL->wData[32][71]=116;
FcL->wData[32][72]=-60;
FcL->wData[32][73]=85;
FcL->wData[32][74]=44;
FcL->wData[32][75]=-220;
FcL->wData[32][76]=-269;
FcL->wData[32][77]=86;
FcL->wData[32][78]=-92;
FcL->wData[32][79]=-129;
FcL->wData[32][80]=-55;
FcL->wData[33][0]=-58;
FcL->wData[33][1]=-127;
FcL->wData[33][2]=68;
FcL->wData[33][3]=5;
FcL->wData[33][4]=259;
FcL->wData[33][5]=94;
FcL->wData[33][6]=-156;
FcL->wData[33][7]=-216;
FcL->wData[33][8]=190;
FcL->wData[33][9]=41;
FcL->wData[33][10]=-113;
FcL->wData[33][11]=218;
FcL->wData[33][12]=122;
FcL->wData[33][13]=302;
FcL->wData[33][14]=93;
FcL->wData[33][15]=104;
FcL->wData[33][16]=108;
FcL->wData[33][17]=277;
FcL->wData[33][18]=-57;
FcL->wData[33][19]=11;
FcL->wData[33][20]=-45;
FcL->wData[33][21]=14;
FcL->wData[33][22]=-188;
FcL->wData[33][23]=21;
FcL->wData[33][24]=-37;
FcL->wData[33][25]=55;
FcL->wData[33][26]=-77;
FcL->wData[33][27]=72;
FcL->wData[33][28]=23;
FcL->wData[33][29]=-117;
FcL->wData[33][30]=400;
FcL->wData[33][31]=157;
FcL->wData[33][32]=-176;
FcL->wData[33][33]=405;
FcL->wData[33][34]=-4;
FcL->wData[33][35]=190;
FcL->wData[33][36]=17;
FcL->wData[33][37]=-156;
FcL->wData[33][38]=13;
FcL->wData[33][39]=191;
FcL->wData[33][40]=68;
FcL->wData[33][41]=-12;
FcL->wData[33][42]=5;
FcL->wData[33][43]=-84;
FcL->wData[33][44]=-24;
FcL->wData[33][45]=-138;
FcL->wData[33][46]=137;
FcL->wData[33][47]=-103;
FcL->wData[33][48]=-102;
FcL->wData[33][49]=-61;
FcL->wData[33][50]=-128;
FcL->wData[33][51]=53;
FcL->wData[33][52]=-21;
FcL->wData[33][53]=-132;
FcL->wData[33][54]=90;
FcL->wData[33][55]=424;
FcL->wData[33][56]=191;
FcL->wData[33][57]=143;
FcL->wData[33][58]=-79;
FcL->wData[33][59]=-55;
FcL->wData[33][60]=-40;
FcL->wData[33][61]=-293;
FcL->wData[33][62]=241;
FcL->wData[33][63]=224;
FcL->wData[33][64]=149;
FcL->wData[33][65]=-95;
FcL->wData[33][66]=-124;
FcL->wData[33][67]=290;
FcL->wData[33][68]=104;
FcL->wData[33][69]=153;
FcL->wData[33][70]=65;
FcL->wData[33][71]=-127;
FcL->wData[33][72]=-133;
FcL->wData[33][73]=71;
FcL->wData[33][74]=125;
FcL->wData[33][75]=-228;
FcL->wData[33][76]=139;
FcL->wData[33][77]=118;
FcL->wData[33][78]=198;
FcL->wData[33][79]=39;
FcL->wData[33][80]=140;
FcL->wData[34][0]=67;
FcL->wData[34][1]=177;
FcL->wData[34][2]=90;
FcL->wData[34][3]=-370;
FcL->wData[34][4]=12;
FcL->wData[34][5]=25;
FcL->wData[34][6]=-7;
FcL->wData[34][7]=144;
FcL->wData[34][8]=-41;
FcL->wData[34][9]=-161;
FcL->wData[34][10]=57;
FcL->wData[34][11]=164;
FcL->wData[34][12]=-159;
FcL->wData[34][13]=115;
FcL->wData[34][14]=64;
FcL->wData[34][15]=49;
FcL->wData[34][16]=36;
FcL->wData[34][17]=-169;
FcL->wData[34][18]=-47;
FcL->wData[34][19]=66;
FcL->wData[34][20]=-49;
FcL->wData[34][21]=-213;
FcL->wData[34][22]=193;
FcL->wData[34][23]=213;
FcL->wData[34][24]=10;
FcL->wData[34][25]=-3;
FcL->wData[34][26]=53;
FcL->wData[34][27]=-136;
FcL->wData[34][28]=48;
FcL->wData[34][29]=-33;
FcL->wData[34][30]=-396;
FcL->wData[34][31]=-185;
FcL->wData[34][32]=244;
FcL->wData[34][33]=-751;
FcL->wData[34][34]=152;
FcL->wData[34][35]=-43;
FcL->wData[34][36]=27;
FcL->wData[34][37]=-48;
FcL->wData[34][38]=-11;
FcL->wData[34][39]=-243;
FcL->wData[34][40]=-26;
FcL->wData[34][41]=165;
FcL->wData[34][42]=-162;
FcL->wData[34][43]=-141;
FcL->wData[34][44]=-160;
FcL->wData[34][45]=265;
FcL->wData[34][46]=80;
FcL->wData[34][47]=-46;
FcL->wData[34][48]=50;
FcL->wData[34][49]=-229;
FcL->wData[34][50]=51;
FcL->wData[34][51]=41;
FcL->wData[34][52]=55;
FcL->wData[34][53]=-106;
FcL->wData[34][54]=-41;
FcL->wData[34][55]=-360;
FcL->wData[34][56]=211;
FcL->wData[34][57]=16;
FcL->wData[34][58]=190;
FcL->wData[34][59]=-46;
FcL->wData[34][60]=-779;
FcL->wData[34][61]=228;
FcL->wData[34][62]=-85;
FcL->wData[34][63]=-194;
FcL->wData[34][64]=-104;
FcL->wData[34][65]=190;
FcL->wData[34][66]=97;
FcL->wData[34][67]=123;
FcL->wData[34][68]=28;
FcL->wData[34][69]=-194;
FcL->wData[34][70]=-117;
FcL->wData[34][71]=-9;
FcL->wData[34][72]=-121;
FcL->wData[34][73]=191;
FcL->wData[34][74]=-35;
FcL->wData[34][75]=242;
FcL->wData[34][76]=-145;
FcL->wData[34][77]=-41;
FcL->wData[34][78]=52;
FcL->wData[34][79]=-108;
FcL->wData[34][80]=136;
FcL->wData[35][0]=-246;
FcL->wData[35][1]=273;
FcL->wData[35][2]=52;
FcL->wData[35][3]=-495;
FcL->wData[35][4]=-252;
FcL->wData[35][5]=76;
FcL->wData[35][6]=-134;
FcL->wData[35][7]=32;
FcL->wData[35][8]=-72;
FcL->wData[35][9]=48;
FcL->wData[35][10]=133;
FcL->wData[35][11]=91;
FcL->wData[35][12]=-129;
FcL->wData[35][13]=48;
FcL->wData[35][14]=21;
FcL->wData[35][15]=-67;
FcL->wData[35][16]=43;
FcL->wData[35][17]=-73;
FcL->wData[35][18]=12;
FcL->wData[35][19]=-55;
FcL->wData[35][20]=-5;
FcL->wData[35][21]=94;
FcL->wData[35][22]=33;
FcL->wData[35][23]=110;
FcL->wData[35][24]=-19;
FcL->wData[35][25]=47;
FcL->wData[35][26]=-194;
FcL->wData[35][27]=-52;
FcL->wData[35][28]=24;
FcL->wData[35][29]=133;
FcL->wData[35][30]=146;
FcL->wData[35][31]=86;
FcL->wData[35][32]=166;
FcL->wData[35][33]=96;
FcL->wData[35][34]=140;
FcL->wData[35][35]=107;
FcL->wData[35][36]=-237;
FcL->wData[35][37]=-12;
FcL->wData[35][38]=-84;
FcL->wData[35][39]=45;
FcL->wData[35][40]=-139;
FcL->wData[35][41]=-144;
FcL->wData[35][42]=124;
FcL->wData[35][43]=30;
FcL->wData[35][44]=204;
FcL->wData[35][45]=165;
FcL->wData[35][46]=99;
FcL->wData[35][47]=-84;
FcL->wData[35][48]=105;
FcL->wData[35][49]=-461;
FcL->wData[35][50]=-132;
FcL->wData[35][51]=-192;
FcL->wData[35][52]=170;
FcL->wData[35][53]=-69;
FcL->wData[35][54]=116;
FcL->wData[35][55]=138;
FcL->wData[35][56]=-121;
FcL->wData[35][57]=-92;
FcL->wData[35][58]=-66;
FcL->wData[35][59]=14;
FcL->wData[35][60]=-81;
FcL->wData[35][61]=82;
FcL->wData[35][62]=-147;
FcL->wData[35][63]=39;
FcL->wData[35][64]=-83;
FcL->wData[35][65]=-164;
FcL->wData[35][66]=69;
FcL->wData[35][67]=112;
FcL->wData[35][68]=3;
FcL->wData[35][69]=89;
FcL->wData[35][70]=138;
FcL->wData[35][71]=-55;
FcL->wData[35][72]=-144;
FcL->wData[35][73]=55;
FcL->wData[35][74]=70;
FcL->wData[35][75]=-128;
FcL->wData[35][76]=117;
FcL->wData[35][77]=35;
FcL->wData[35][78]=57;
FcL->wData[35][79]=156;
FcL->wData[35][80]=80;
FcL->wData[36][0]=-77;
FcL->wData[36][1]=207;
FcL->wData[36][2]=-251;
FcL->wData[36][3]=-395;
FcL->wData[36][4]=-478;
FcL->wData[36][5]=199;
FcL->wData[36][6]=-22;
FcL->wData[36][7]=130;
FcL->wData[36][8]=87;
FcL->wData[36][9]=-22;
FcL->wData[36][10]=168;
FcL->wData[36][11]=16;
FcL->wData[36][12]=-204;
FcL->wData[36][13]=-98;
FcL->wData[36][14]=-207;
FcL->wData[36][15]=115;
FcL->wData[36][16]=55;
FcL->wData[36][17]=-236;
FcL->wData[36][18]=-8;
FcL->wData[36][19]=-184;
FcL->wData[36][20]=-39;
FcL->wData[36][21]=189;
FcL->wData[36][22]=90;
FcL->wData[36][23]=4;
FcL->wData[36][24]=227;
FcL->wData[36][25]=-136;
FcL->wData[36][26]=35;
FcL->wData[36][27]=240;
FcL->wData[36][28]=20;
FcL->wData[36][29]=132;
FcL->wData[36][30]=-286;
FcL->wData[36][31]=-187;
FcL->wData[36][32]=141;
FcL->wData[36][33]=-775;
FcL->wData[36][34]=410;
FcL->wData[36][35]=-45;
FcL->wData[36][36]=-146;
FcL->wData[36][37]=373;
FcL->wData[36][38]=-216;
FcL->wData[36][39]=-254;
FcL->wData[36][40]=416;
FcL->wData[36][41]=-271;
FcL->wData[36][42]=254;
FcL->wData[36][43]=93;
FcL->wData[36][44]=-81;
FcL->wData[36][45]=-44;
FcL->wData[36][46]=206;
FcL->wData[36][47]=-8;
FcL->wData[36][48]=-172;
FcL->wData[36][49]=-417;
FcL->wData[36][50]=278;
FcL->wData[36][51]=69;
FcL->wData[36][52]=296;
FcL->wData[36][53]=-75;
FcL->wData[36][54]=-226;
FcL->wData[36][55]=-285;
FcL->wData[36][56]=-337;
FcL->wData[36][57]=44;
FcL->wData[36][58]=-107;
FcL->wData[36][59]=259;
FcL->wData[36][60]=-119;
FcL->wData[36][61]=-142;
FcL->wData[36][62]=-123;
FcL->wData[36][63]=72;
FcL->wData[36][64]=-277;
FcL->wData[36][65]=-69;
FcL->wData[36][66]=-81;
FcL->wData[36][67]=33;
FcL->wData[36][68]=28;
FcL->wData[36][69]=-427;
FcL->wData[36][70]=183;
FcL->wData[36][71]=-72;
FcL->wData[36][72]=-144;
FcL->wData[36][73]=-138;
FcL->wData[36][74]=-64;
FcL->wData[36][75]=158;
FcL->wData[36][76]=2;
FcL->wData[36][77]=9;
FcL->wData[36][78]=-221;
FcL->wData[36][79]=-95;
FcL->wData[36][80]=48;
FcL->wData[37][0]=-62;
FcL->wData[37][1]=-220;
FcL->wData[37][2]=-128;
FcL->wData[37][3]=-187;
FcL->wData[37][4]=144;
FcL->wData[37][5]=-142;
FcL->wData[37][6]=-133;
FcL->wData[37][7]=-222;
FcL->wData[37][8]=30;
FcL->wData[37][9]=9;
FcL->wData[37][10]=-90;
FcL->wData[37][11]=-227;
FcL->wData[37][12]=157;
FcL->wData[37][13]=11;
FcL->wData[37][14]=-182;
FcL->wData[37][15]=81;
FcL->wData[37][16]=179;
FcL->wData[37][17]=147;
FcL->wData[37][18]=126;
FcL->wData[37][19]=145;
FcL->wData[37][20]=6;
FcL->wData[37][21]=-211;
FcL->wData[37][22]=-59;
FcL->wData[37][23]=3;
FcL->wData[37][24]=-78;
FcL->wData[37][25]=166;
FcL->wData[37][26]=-167;
FcL->wData[37][27]=-217;
FcL->wData[37][28]=-121;
FcL->wData[37][29]=-49;
FcL->wData[37][30]=-190;
FcL->wData[37][31]=142;
FcL->wData[37][32]=191;
FcL->wData[37][33]=-181;
FcL->wData[37][34]=-168;
FcL->wData[37][35]=201;
FcL->wData[37][36]=-232;
FcL->wData[37][37]=44;
FcL->wData[37][38]=-153;
FcL->wData[37][39]=-128;
FcL->wData[37][40]=93;
FcL->wData[37][41]=141;
FcL->wData[37][42]=-34;
FcL->wData[37][43]=-104;
FcL->wData[37][44]=169;
FcL->wData[37][45]=-11;
FcL->wData[37][46]=58;
FcL->wData[37][47]=-11;
FcL->wData[37][48]=-191;
FcL->wData[37][49]=-10;
FcL->wData[37][50]=-45;
FcL->wData[37][51]=54;
FcL->wData[37][52]=85;
FcL->wData[37][53]=-142;
FcL->wData[37][54]=-189;
FcL->wData[37][55]=62;
FcL->wData[37][56]=-220;
FcL->wData[37][57]=50;
FcL->wData[37][58]=54;
FcL->wData[37][59]=-128;
FcL->wData[37][60]=52;
FcL->wData[37][61]=-22;
FcL->wData[37][62]=-132;
FcL->wData[37][63]=-4;
FcL->wData[37][64]=-182;
FcL->wData[37][65]=-47;
FcL->wData[37][66]=-23;
FcL->wData[37][67]=-149;
FcL->wData[37][68]=36;
FcL->wData[37][69]=-89;
FcL->wData[37][70]=-10;
FcL->wData[37][71]=25;
FcL->wData[37][72]=-122;
FcL->wData[37][73]=-178;
FcL->wData[37][74]=-70;
FcL->wData[37][75]=-189;
FcL->wData[37][76]=42;
FcL->wData[37][77]=-242;
FcL->wData[37][78]=148;
FcL->wData[37][79]=-95;
FcL->wData[37][80]=20;
FcL->wData[38][0]=134;
FcL->wData[38][1]=-45;
FcL->wData[38][2]=-52;
FcL->wData[38][3]=-79;
FcL->wData[38][4]=-161;
FcL->wData[38][5]=2;
FcL->wData[38][6]=-255;
FcL->wData[38][7]=169;
FcL->wData[38][8]=-161;
FcL->wData[38][9]=-171;
FcL->wData[38][10]=85;
FcL->wData[38][11]=-188;
FcL->wData[38][12]=-150;
FcL->wData[38][13]=-48;
FcL->wData[38][14]=69;
FcL->wData[38][15]=274;
FcL->wData[38][16]=37;
FcL->wData[38][17]=20;
FcL->wData[38][18]=78;
FcL->wData[38][19]=-150;
FcL->wData[38][20]=61;
FcL->wData[38][21]=30;
FcL->wData[38][22]=9;
FcL->wData[38][23]=18;
FcL->wData[38][24]=-116;
FcL->wData[38][25]=60;
FcL->wData[38][26]=-280;
FcL->wData[38][27]=11;
FcL->wData[38][28]=41;
FcL->wData[38][29]=172;
FcL->wData[38][30]=-32;
FcL->wData[38][31]=265;
FcL->wData[38][32]=212;
FcL->wData[38][33]=-135;
FcL->wData[38][34]=270;
FcL->wData[38][35]=288;
FcL->wData[38][36]=64;
FcL->wData[38][37]=-201;
FcL->wData[38][38]=157;
FcL->wData[38][39]=95;
FcL->wData[38][40]=-50;
FcL->wData[38][41]=55;
FcL->wData[38][42]=-58;
FcL->wData[38][43]=-198;
FcL->wData[38][44]=226;
FcL->wData[38][45]=-48;
FcL->wData[38][46]=-127;
FcL->wData[38][47]=78;
FcL->wData[38][48]=44;
FcL->wData[38][49]=-11;
FcL->wData[38][50]=29;
FcL->wData[38][51]=73;
FcL->wData[38][52]=17;
FcL->wData[38][53]=55;
FcL->wData[38][54]=71;
FcL->wData[38][55]=-158;
FcL->wData[38][56]=59;
FcL->wData[38][57]=-20;
FcL->wData[38][58]=-115;
FcL->wData[38][59]=86;
FcL->wData[38][60]=-155;
FcL->wData[38][61]=-49;
FcL->wData[38][62]=44;
FcL->wData[38][63]=-26;
FcL->wData[38][64]=56;
FcL->wData[38][65]=78;
FcL->wData[38][66]=10;
FcL->wData[38][67]=-218;
FcL->wData[38][68]=-238;
FcL->wData[38][69]=-31;
FcL->wData[38][70]=-179;
FcL->wData[38][71]=-71;
FcL->wData[38][72]=139;
FcL->wData[38][73]=-163;
FcL->wData[38][74]=84;
FcL->wData[38][75]=-7;
FcL->wData[38][76]=-143;
FcL->wData[38][77]=78;
FcL->wData[38][78]=6;
FcL->wData[38][79]=44;
FcL->wData[38][80]=53;
FcL->wData[39][0]=-89;
FcL->wData[39][1]=6;
FcL->wData[39][2]=116;
FcL->wData[39][3]=204;
FcL->wData[39][4]=-97;
FcL->wData[39][5]=-135;
FcL->wData[39][6]=9;
FcL->wData[39][7]=-143;
FcL->wData[39][8]=30;
FcL->wData[39][9]=-197;
FcL->wData[39][10]=78;
FcL->wData[39][11]=-44;
FcL->wData[39][12]=-610;
FcL->wData[39][13]=285;
FcL->wData[39][14]=359;
FcL->wData[39][15]=89;
FcL->wData[39][16]=92;
FcL->wData[39][17]=85;
FcL->wData[39][18]=-102;
FcL->wData[39][19]=154;
FcL->wData[39][20]=-202;
FcL->wData[39][21]=-531;
FcL->wData[39][22]=-137;
FcL->wData[39][23]=-176;
FcL->wData[39][24]=145;
FcL->wData[39][25]=-121;
FcL->wData[39][26]=-102;
FcL->wData[39][27]=25;
FcL->wData[39][28]=21;
FcL->wData[39][29]=-61;
FcL->wData[39][30]=-201;
FcL->wData[39][31]=-6;
FcL->wData[39][32]=165;
FcL->wData[39][33]=-76;
FcL->wData[39][34]=-156;
FcL->wData[39][35]=-126;
FcL->wData[39][36]=82;
FcL->wData[39][37]=-97;
FcL->wData[39][38]=-23;
FcL->wData[39][39]=145;
FcL->wData[39][40]=55;
FcL->wData[39][41]=136;
FcL->wData[39][42]=-141;
FcL->wData[39][43]=41;
FcL->wData[39][44]=-54;
FcL->wData[39][45]=-80;
FcL->wData[39][46]=50;
FcL->wData[39][47]=-33;
FcL->wData[39][48]=-292;
FcL->wData[39][49]=37;
FcL->wData[39][50]=-71;
FcL->wData[39][51]=161;
FcL->wData[39][52]=-121;
FcL->wData[39][53]=-123;
FcL->wData[39][54]=-66;
FcL->wData[39][55]=58;
FcL->wData[39][56]=-118;
FcL->wData[39][57]=-216;
FcL->wData[39][58]=64;
FcL->wData[39][59]=40;
FcL->wData[39][60]=62;
FcL->wData[39][61]=-66;
FcL->wData[39][62]=94;
FcL->wData[39][63]=70;
FcL->wData[39][64]=24;
FcL->wData[39][65]=47;
FcL->wData[39][66]=94;
FcL->wData[39][67]=143;
FcL->wData[39][68]=94;
FcL->wData[39][69]=-115;
FcL->wData[39][70]=-197;
FcL->wData[39][71]=125;
FcL->wData[39][72]=59;
FcL->wData[39][73]=114;
FcL->wData[39][74]=-59;
FcL->wData[39][75]=85;
FcL->wData[39][76]=-23;
FcL->wData[39][77]=222;
FcL->wData[39][78]=3;
FcL->wData[39][79]=110;
FcL->wData[39][80]=142;
FcL->wData[40][0]=-30;
FcL->wData[40][1]=19;
FcL->wData[40][2]=49;
FcL->wData[40][3]=-143;
FcL->wData[40][4]=-42;
FcL->wData[40][5]=-66;
FcL->wData[40][6]=125;
FcL->wData[40][7]=50;
FcL->wData[40][8]=-125;
FcL->wData[40][9]=-76;
FcL->wData[40][10]=-222;
FcL->wData[40][11]=78;
FcL->wData[40][12]=-153;
FcL->wData[40][13]=-25;
FcL->wData[40][14]=-148;
FcL->wData[40][15]=-153;
FcL->wData[40][16]=150;
FcL->wData[40][17]=-50;
FcL->wData[40][18]=-35;
FcL->wData[40][19]=168;
FcL->wData[40][20]=-137;
FcL->wData[40][21]=90;
FcL->wData[40][22]=-59;
FcL->wData[40][23]=153;
FcL->wData[40][24]=-164;
FcL->wData[40][25]=-115;
FcL->wData[40][26]=-55;
FcL->wData[40][27]=-109;
FcL->wData[40][28]=159;
FcL->wData[40][29]=-214;
FcL->wData[40][30]=82;
FcL->wData[40][31]=-41;
FcL->wData[40][32]=-216;
FcL->wData[40][33]=81;
FcL->wData[40][34]=43;
FcL->wData[40][35]=-196;
FcL->wData[40][36]=28;
FcL->wData[40][37]=25;
FcL->wData[40][38]=-87;
FcL->wData[40][39]=-36;
FcL->wData[40][40]=-203;
FcL->wData[40][41]=-208;
FcL->wData[40][42]=-54;
FcL->wData[40][43]=34;
FcL->wData[40][44]=227;
FcL->wData[40][45]=-181;
FcL->wData[40][46]=-174;
FcL->wData[40][47]=-86;
FcL->wData[40][48]=-171;
FcL->wData[40][49]=42;
FcL->wData[40][50]=-50;
FcL->wData[40][51]=147;
FcL->wData[40][52]=-47;
FcL->wData[40][53]=-71;
FcL->wData[40][54]=-35;
FcL->wData[40][55]=-112;
FcL->wData[40][56]=-211;
FcL->wData[40][57]=-226;
FcL->wData[40][58]=133;
FcL->wData[40][59]=47;
FcL->wData[40][60]=-91;
FcL->wData[40][61]=142;
FcL->wData[40][62]=66;
FcL->wData[40][63]=17;
FcL->wData[40][64]=-123;
FcL->wData[40][65]=-153;
FcL->wData[40][66]=8;
FcL->wData[40][67]=-177;
FcL->wData[40][68]=-180;
FcL->wData[40][69]=120;
FcL->wData[40][70]=-104;
FcL->wData[40][71]=-1;
FcL->wData[40][72]=-175;
FcL->wData[40][73]=-181;
FcL->wData[40][74]=-104;
FcL->wData[40][75]=-5;
FcL->wData[40][76]=-173;
FcL->wData[40][77]=108;
FcL->wData[40][78]=-84;
FcL->wData[40][79]=-73;
FcL->wData[40][80]=2;
FcL->wData[41][0]=-156;
FcL->wData[41][1]=-179;
FcL->wData[41][2]=-194;
FcL->wData[41][3]=-42;
FcL->wData[41][4]=244;
FcL->wData[41][5]=71;
FcL->wData[41][6]=228;
FcL->wData[41][7]=-177;
FcL->wData[41][8]=121;
FcL->wData[41][9]=115;
FcL->wData[41][10]=-83;
FcL->wData[41][11]=235;
FcL->wData[41][12]=262;
FcL->wData[41][13]=231;
FcL->wData[41][14]=178;
FcL->wData[41][15]=-35;
FcL->wData[41][16]=-165;
FcL->wData[41][17]=102;
FcL->wData[41][18]=9;
FcL->wData[41][19]=109;
FcL->wData[41][20]=167;
FcL->wData[41][21]=193;
FcL->wData[41][22]=68;
FcL->wData[41][23]=-44;
FcL->wData[41][24]=-100;
FcL->wData[41][25]=-76;
FcL->wData[41][26]=-57;
FcL->wData[41][27]=163;
FcL->wData[41][28]=111;
FcL->wData[41][29]=44;
FcL->wData[41][30]=-82;
FcL->wData[41][31]=236;
FcL->wData[41][32]=-174;
FcL->wData[41][33]=285;
FcL->wData[41][34]=-80;
FcL->wData[41][35]=142;
FcL->wData[41][36]=-188;
FcL->wData[41][37]=-360;
FcL->wData[41][38]=188;
FcL->wData[41][39]=175;
FcL->wData[41][40]=287;
FcL->wData[41][41]=-218;
FcL->wData[41][42]=214;
FcL->wData[41][43]=-57;
FcL->wData[41][44]=-106;
FcL->wData[41][45]=39;
FcL->wData[41][46]=133;
FcL->wData[41][47]=-134;
FcL->wData[41][48]=427;
FcL->wData[41][49]=356;
FcL->wData[41][50]=-24;
FcL->wData[41][51]=-95;
FcL->wData[41][52]=206;
FcL->wData[41][53]=137;
FcL->wData[41][54]=142;
FcL->wData[41][55]=-102;
FcL->wData[41][56]=-147;
FcL->wData[41][57]=140;
FcL->wData[41][58]=-53;
FcL->wData[41][59]=-39;
FcL->wData[41][60]=152;
FcL->wData[41][61]=-258;
FcL->wData[41][62]=132;
FcL->wData[41][63]=-7;
FcL->wData[41][64]=180;
FcL->wData[41][65]=-37;
FcL->wData[41][66]=244;
FcL->wData[41][67]=-439;
FcL->wData[41][68]=45;
FcL->wData[41][69]=196;
FcL->wData[41][70]=-401;
FcL->wData[41][71]=127;
FcL->wData[41][72]=138;
FcL->wData[41][73]=-69;
FcL->wData[41][74]=31;
FcL->wData[41][75]=210;
FcL->wData[41][76]=-220;
FcL->wData[41][77]=22;
FcL->wData[41][78]=-168;
FcL->wData[41][79]=-184;
FcL->wData[41][80]=-102;
FcL->wData[42][0]=-103;
FcL->wData[42][1]=95;
FcL->wData[42][2]=78;
FcL->wData[42][3]=14;
FcL->wData[42][4]=-90;
FcL->wData[42][5]=-56;
FcL->wData[42][6]=437;
FcL->wData[42][7]=64;
FcL->wData[42][8]=177;
FcL->wData[42][9]=116;
FcL->wData[42][10]=-57;
FcL->wData[42][11]=99;
FcL->wData[42][12]=-254;
FcL->wData[42][13]=77;
FcL->wData[42][14]=-111;
FcL->wData[42][15]=273;
FcL->wData[42][16]=305;
FcL->wData[42][17]=-222;
FcL->wData[42][18]=189;
FcL->wData[42][19]=11;
FcL->wData[42][20]=-202;
FcL->wData[42][21]=-126;
FcL->wData[42][22]=139;
FcL->wData[42][23]=69;
FcL->wData[42][24]=87;
FcL->wData[42][25]=124;
FcL->wData[42][26]=-38;
FcL->wData[42][27]=145;
FcL->wData[42][28]=131;
FcL->wData[42][29]=67;
FcL->wData[42][30]=279;
FcL->wData[42][31]=-139;
FcL->wData[42][32]=78;
FcL->wData[42][33]=-100;
FcL->wData[42][34]=29;
FcL->wData[42][35]=58;
FcL->wData[42][36]=82;
FcL->wData[42][37]=124;
FcL->wData[42][38]=23;
FcL->wData[42][39]=30;
FcL->wData[42][40]=43;
FcL->wData[42][41]=-89;
FcL->wData[42][42]=-578;
FcL->wData[42][43]=121;
FcL->wData[42][44]=-214;
FcL->wData[42][45]=30;
FcL->wData[42][46]=47;
FcL->wData[42][47]=76;
FcL->wData[42][48]=8;
FcL->wData[42][49]=-348;
FcL->wData[42][50]=-8;
FcL->wData[42][51]=-74;
FcL->wData[42][52]=44;
FcL->wData[42][53]=-43;
FcL->wData[42][54]=146;
FcL->wData[42][55]=255;
FcL->wData[42][56]=-290;
FcL->wData[42][57]=-109;
FcL->wData[42][58]=-212;
FcL->wData[42][59]=-198;
FcL->wData[42][60]=-233;
FcL->wData[42][61]=-84;
FcL->wData[42][62]=-323;
FcL->wData[42][63]=14;
FcL->wData[42][64]=-85;
FcL->wData[42][65]=16;
FcL->wData[42][66]=-144;
FcL->wData[42][67]=392;
FcL->wData[42][68]=-81;
FcL->wData[42][69]=-82;
FcL->wData[42][70]=227;
FcL->wData[42][71]=-458;
FcL->wData[42][72]=-258;
FcL->wData[42][73]=-204;
FcL->wData[42][74]=45;
FcL->wData[42][75]=-75;
FcL->wData[42][76]=9;
FcL->wData[42][77]=-27;
FcL->wData[42][78]=-175;
FcL->wData[42][79]=34;
FcL->wData[42][80]=52;
FcL->wData[43][0]=-60;
FcL->wData[43][1]=146;
FcL->wData[43][2]=-48;
FcL->wData[43][3]=69;
FcL->wData[43][4]=-170;
FcL->wData[43][5]=-15;
FcL->wData[43][6]=233;
FcL->wData[43][7]=-120;
FcL->wData[43][8]=108;
FcL->wData[43][9]=67;
FcL->wData[43][10]=31;
FcL->wData[43][11]=-99;
FcL->wData[43][12]=143;
FcL->wData[43][13]=-88;
FcL->wData[43][14]=-64;
FcL->wData[43][15]=-57;
FcL->wData[43][16]=122;
FcL->wData[43][17]=-25;
FcL->wData[43][18]=-21;
FcL->wData[43][19]=16;
FcL->wData[43][20]=58;
FcL->wData[43][21]=301;
FcL->wData[43][22]=-105;
FcL->wData[43][23]=-254;
FcL->wData[43][24]=-131;
FcL->wData[43][25]=-182;
FcL->wData[43][26]=189;
FcL->wData[43][27]=11;
FcL->wData[43][28]=-297;
FcL->wData[43][29]=158;
FcL->wData[43][30]=136;
FcL->wData[43][31]=-27;
FcL->wData[43][32]=-221;
FcL->wData[43][33]=495;
FcL->wData[43][34]=225;
FcL->wData[43][35]=-69;
FcL->wData[43][36]=154;
FcL->wData[43][37]=-43;
FcL->wData[43][38]=-228;
FcL->wData[43][39]=363;
FcL->wData[43][40]=315;
FcL->wData[43][41]=-62;
FcL->wData[43][42]=155;
FcL->wData[43][43]=-75;
FcL->wData[43][44]=-15;
FcL->wData[43][45]=-282;
FcL->wData[43][46]=73;
FcL->wData[43][47]=-12;
FcL->wData[43][48]=-159;
FcL->wData[43][49]=169;
FcL->wData[43][50]=134;
FcL->wData[43][51]=252;
FcL->wData[43][52]=4;
FcL->wData[43][53]=-89;
FcL->wData[43][54]=104;
FcL->wData[43][55]=356;
FcL->wData[43][56]=-262;
FcL->wData[43][57]=-29;
FcL->wData[43][58]=-191;
FcL->wData[43][59]=174;
FcL->wData[43][60]=306;
FcL->wData[43][61]=-406;
FcL->wData[43][62]=19;
FcL->wData[43][63]=509;
FcL->wData[43][64]=200;
FcL->wData[43][65]=-40;
FcL->wData[43][66]=46;
FcL->wData[43][67]=-74;
FcL->wData[43][68]=40;
FcL->wData[43][69]=226;
FcL->wData[43][70]=224;
FcL->wData[43][71]=-99;
FcL->wData[43][72]=84;
FcL->wData[43][73]=-224;
FcL->wData[43][74]=49;
FcL->wData[43][75]=-114;
FcL->wData[43][76]=-35;
FcL->wData[43][77]=-111;
FcL->wData[43][78]=-201;
FcL->wData[43][79]=80;
FcL->wData[43][80]=-127;
FcL->wData[44][0]=-142;
FcL->wData[44][1]=78;
FcL->wData[44][2]=-114;
FcL->wData[44][3]=48;
FcL->wData[44][4]=126;
FcL->wData[44][5]=7;
FcL->wData[44][6]=-191;
FcL->wData[44][7]=-70;
FcL->wData[44][8]=-34;
FcL->wData[44][9]=-200;
FcL->wData[44][10]=-108;
FcL->wData[44][11]=41;
FcL->wData[44][12]=-52;
FcL->wData[44][13]=-40;
FcL->wData[44][14]=76;
FcL->wData[44][15]=-173;
FcL->wData[44][16]=-216;
FcL->wData[44][17]=90;
FcL->wData[44][18]=-224;
FcL->wData[44][19]=-180;
FcL->wData[44][20]=-140;
FcL->wData[44][21]=-60;
FcL->wData[44][22]=-116;
FcL->wData[44][23]=-117;
FcL->wData[44][24]=60;
FcL->wData[44][25]=-80;
FcL->wData[44][26]=-34;
FcL->wData[44][27]=-168;
FcL->wData[44][28]=-149;
FcL->wData[44][29]=-137;
FcL->wData[44][30]=65;
FcL->wData[44][31]=-86;
FcL->wData[44][32]=12;
FcL->wData[44][33]=-73;
FcL->wData[44][34]=38;
FcL->wData[44][35]=-118;
FcL->wData[44][36]=-7;
FcL->wData[44][37]=-125;
FcL->wData[44][38]=96;
FcL->wData[44][39]=137;
FcL->wData[44][40]=196;
FcL->wData[44][41]=72;
FcL->wData[44][42]=-170;
FcL->wData[44][43]=-151;
FcL->wData[44][44]=-129;
FcL->wData[44][45]=126;
FcL->wData[44][46]=-65;
FcL->wData[44][47]=169;
FcL->wData[44][48]=51;
FcL->wData[44][49]=-84;
FcL->wData[44][50]=-95;
FcL->wData[44][51]=-62;
FcL->wData[44][52]=122;
FcL->wData[44][53]=-219;
FcL->wData[44][54]=58;
FcL->wData[44][55]=183;
FcL->wData[44][56]=48;
FcL->wData[44][57]=-216;
FcL->wData[44][58]=25;
FcL->wData[44][59]=-78;
FcL->wData[44][60]=-62;
FcL->wData[44][61]=108;
FcL->wData[44][62]=180;
FcL->wData[44][63]=-161;
FcL->wData[44][64]=-200;
FcL->wData[44][65]=202;
FcL->wData[44][66]=23;
FcL->wData[44][67]=137;
FcL->wData[44][68]=-94;
FcL->wData[44][69]=43;
FcL->wData[44][70]=94;
FcL->wData[44][71]=-188;
FcL->wData[44][72]=-34;
FcL->wData[44][73]=-30;
FcL->wData[44][74]=153;
FcL->wData[44][75]=-95;
FcL->wData[44][76]=201;
FcL->wData[44][77]=-14;
FcL->wData[44][78]=-189;
FcL->wData[44][79]=-144;
FcL->wData[44][80]=44;
FcL->basicData[0]=-97;
FcL->basicData[1]=175;
FcL->basicData[2]=8;
FcL->basicData[3]=-67;
FcL->basicData[4]=23;
FcL->basicData[5]=-86;
FcL->basicData[6]=5;
FcL->basicData[7]=18;
FcL->basicData[8]=-15;
FcL->basicData[9]=29;
FcL->basicData[10]=220;
FcL->basicData[11]=-17;
FcL->basicData[12]=-414;
FcL->basicData[13]=-105;
FcL->basicData[14]=44;
FcL->basicData[15]=36;
FcL->basicData[16]=107;
FcL->basicData[17]=38;
FcL->basicData[18]=-22;
FcL->basicData[19]=-25;
FcL->basicData[20]=232;
FcL->basicData[21]=-42;
FcL->basicData[22]=-30;
FcL->basicData[23]=-79;
FcL->basicData[24]=-118;
FcL->basicData[25]=111;
FcL->basicData[26]=105;
FcL->basicData[27]=21;
FcL->basicData[28]=-65;
FcL->basicData[29]=-21;
FcL->basicData[30]=122;
FcL->basicData[31]=-55;
FcL->basicData[32]=-50;
FcL->basicData[33]=51;
FcL->basicData[34]=99;
FcL->basicData[35]=89;
FcL->basicData[36]=120;
FcL->basicData[37]=-19;
FcL->basicData[38]=101;
FcL->basicData[39]=56;
FcL->basicData[40]=-11;
FcL->basicData[41]=-55;
FcL->basicData[42]=54;
FcL->basicData[43]=58;
FcL->basicData[44]=-14;


	for (i = 0; i < outputNum; ++i)
	{
		for (k = 0; k < inputNum; ++k)
		{
			FcL->y[i] = inputData[k] * FcL->wData[i][k] + FcL->y[i];
		}
		FcL->y[i] = activation_relu(FcL->y[i], FcL->basicData[i]);
		FcL->y[i] = FcL->y[i]/1000;
		//printf("%f\n ", FcL->y[i]);
	}
	//printf("\n\n");


	for (i = (outputNum - 1); i != (-1); i--)
	{
		free(FcL->wData[i]);
	}
	free(FcL->wData);
	free(FcL->basicData);

	return FcL->y;
}


void* output(int* inputData, char* filename, int inputNum, int outputNum, char* filename1)
{

	int i, j, k;
	OutLayer* outL = (OutLayer*)malloc(sizeof(OutLayer));
	outL->wData = (int**)malloc(outputNum * sizeof(int*));
	
	for (i = (outputNum - 1); i != (-1); i--)
	{
		outL->wData[i] = (int*)calloc(inputNum,sizeof(int));
	}
	outL->basicData = (int*)calloc(outputNum, sizeof(int));
	outL->outputdata = (int*)calloc(outputNum, sizeof(int));

	//read_file_fc(filename, outputNum, inputNum, outL);
outL->wData[0][0]=-179;
outL->wData[0][1]=-154;
outL->wData[0][2]=-192;
outL->wData[0][3]=34;
outL->wData[0][4]=131;
outL->wData[0][5]=-628;
outL->wData[0][6]=207;
outL->wData[0][7]=-28;
outL->wData[0][8]=-237;
outL->wData[0][9]=73;
outL->wData[0][10]=113;
outL->wData[0][11]=83;
outL->wData[0][12]=-133;
outL->wData[0][13]=-543;
outL->wData[0][14]=81;
outL->wData[0][15]=-12;
outL->wData[0][16]=99;
outL->wData[0][17]=116;
outL->wData[0][18]=-350;
outL->wData[0][19]=-86;
outL->wData[0][20]=-120;
outL->wData[0][21]=-458;
outL->wData[0][22]=96;
outL->wData[0][23]=-720;
outL->wData[0][24]=-104;
outL->wData[0][25]=-437;
outL->wData[0][26]=157;
outL->wData[0][27]=3;
outL->wData[0][28]=-180;
outL->wData[0][29]=-341;
outL->wData[0][30]=82;
outL->wData[0][31]=-567;
outL->wData[0][32]=259;
outL->wData[0][33]=-340;
outL->wData[0][34]=301;
outL->wData[0][35]=226;
outL->wData[0][36]=-108;
outL->wData[0][37]=-6;
outL->wData[0][38]=38;
outL->wData[0][39]=199;
outL->wData[0][40]=88;
outL->wData[0][41]=333;
outL->wData[0][42]=-395;
outL->wData[0][43]=193;
outL->wData[0][44]=258;
outL->wData[1][0]=-404;
outL->wData[1][1]=70;
outL->wData[1][2]=59;
outL->wData[1][3]=-96;
outL->wData[1][4]=128;
outL->wData[1][5]=-395;
outL->wData[1][6]=-292;
outL->wData[1][7]=27;
outL->wData[1][8]=-145;
outL->wData[1][9]=-280;
outL->wData[1][10]=317;
outL->wData[1][11]=-32;
outL->wData[1][12]=-814;
outL->wData[1][13]=2;
outL->wData[1][14]=-153;
outL->wData[1][15]=-399;
outL->wData[1][16]=243;
outL->wData[1][17]=175;
outL->wData[1][18]=262;
outL->wData[1][19]=287;
outL->wData[1][20]=73;
outL->wData[1][21]=-652;
outL->wData[1][22]=-259;
outL->wData[1][23]=-170;
outL->wData[1][24]=-352;
outL->wData[1][25]=375;
outL->wData[1][26]=130;
outL->wData[1][27]=-175;
outL->wData[1][28]=485;
outL->wData[1][29]=-135;
outL->wData[1][30]=119;
outL->wData[1][31]=-680;
outL->wData[1][32]=40;
outL->wData[1][33]=96;
outL->wData[1][34]=-113;
outL->wData[1][35]=102;
outL->wData[1][36]=-186;
outL->wData[1][37]=-112;
outL->wData[1][38]=-311;
outL->wData[1][39]=16;
outL->wData[1][40]=-87;
outL->wData[1][41]=224;
outL->wData[1][42]=51;
outL->wData[1][43]=-249;
outL->wData[1][44]=53;
outL->wData[2][0]=6;
outL->wData[2][1]=-88;
outL->wData[2][2]=220;
outL->wData[2][3]=-513;
outL->wData[2][4]=168;
outL->wData[2][5]=9;
outL->wData[2][6]=193;
outL->wData[2][7]=25;
outL->wData[2][8]=-238;
outL->wData[2][9]=-226;
outL->wData[2][10]=308;
outL->wData[2][11]=-303;
outL->wData[2][12]=-363;
outL->wData[2][13]=49;
outL->wData[2][14]=293;
outL->wData[2][15]=-110;
outL->wData[2][16]=-250;
outL->wData[2][17]=-78;
outL->wData[2][18]=42;
outL->wData[2][19]=227;
outL->wData[2][20]=299;
outL->wData[2][21]=-203;
outL->wData[2][22]=-202;
outL->wData[2][23]=-396;
outL->wData[2][24]=209;
outL->wData[2][25]=11;
outL->wData[2][26]=-714;
outL->wData[2][27]=98;
outL->wData[2][28]=-370;
outL->wData[2][29]=-221;
outL->wData[2][30]=150;
outL->wData[2][31]=-341;
outL->wData[2][32]=-10;
outL->wData[2][33]=104;
outL->wData[2][34]=-234;
outL->wData[2][35]=191;
outL->wData[2][36]=-768;
outL->wData[2][37]=-8;
outL->wData[2][38]=111;
outL->wData[2][39]=51;
outL->wData[2][40]=244;
outL->wData[2][41]=-137;
outL->wData[2][42]=-483;
outL->wData[2][43]=-740;
outL->wData[2][44]=274;
outL->wData[3][0]=-125;
outL->wData[3][1]=-517;
outL->wData[3][2]=-65;
outL->wData[3][3]=-722;
outL->wData[3][4]=-235;
outL->wData[3][5]=174;
outL->wData[3][6]=-128;
outL->wData[3][7]=-114;
outL->wData[3][8]=173;
outL->wData[3][9]=-840;
outL->wData[3][10]=190;
outL->wData[3][11]=179;
outL->wData[3][12]=134;
outL->wData[3][13]=-73;
outL->wData[3][14]=60;
outL->wData[3][15]=152;
outL->wData[3][16]=122;
outL->wData[3][17]=-298;
outL->wData[3][18]=225;
outL->wData[3][19]=-60;
outL->wData[3][20]=-195;
outL->wData[3][21]=76;
outL->wData[3][22]=156;
outL->wData[3][23]=68;
outL->wData[3][24]=-155;
outL->wData[3][25]=-223;
outL->wData[3][26]=38;
outL->wData[3][27]=108;
outL->wData[3][28]=-167;
outL->wData[3][29]=118;
outL->wData[3][30]=45;
outL->wData[3][31]=-514;
outL->wData[3][32]=148;
outL->wData[3][33]=226;
outL->wData[3][34]=-621;
outL->wData[3][35]=-129;
outL->wData[3][36]=-152;
outL->wData[3][37]=-82;
outL->wData[3][38]=86;
outL->wData[3][39]=175;
outL->wData[3][40]=-194;
outL->wData[3][41]=-90;
outL->wData[3][42]=-404;
outL->wData[3][43]=-61;
outL->wData[3][44]=296;
outL->wData[4][0]=-471;
outL->wData[4][1]=-246;
outL->wData[4][2]=-131;
outL->wData[4][3]=-213;
outL->wData[4][4]=-688;
outL->wData[4][5]=-339;
outL->wData[4][6]=-300;
outL->wData[4][7]=-463;
outL->wData[4][8]=-252;
outL->wData[4][9]=-107;
outL->wData[4][10]=176;
outL->wData[4][11]=178;
outL->wData[4][12]=-783;
outL->wData[4][13]=425;
outL->wData[4][14]=-231;
outL->wData[4][15]=-233;
outL->wData[4][16]=-39;
outL->wData[4][17]=-175;
outL->wData[4][18]=-293;
outL->wData[4][19]=52;
outL->wData[4][20]=81;
outL->wData[4][21]=-41;
outL->wData[4][22]=-181;
outL->wData[4][23]=361;
outL->wData[4][24]=216;
outL->wData[4][25]=-289;
outL->wData[4][26]=-10;
outL->wData[4][27]=-386;
outL->wData[4][28]=-38;
outL->wData[4][29]=-88;
outL->wData[4][30]=95;
outL->wData[4][31]=-151;
outL->wData[4][32]=-318;
outL->wData[4][33]=-303;
outL->wData[4][34]=-66;
outL->wData[4][35]=294;
outL->wData[4][36]=250;
outL->wData[4][37]=22;
outL->wData[4][38]=215;
outL->wData[4][39]=123;
outL->wData[4][40]=106;
outL->wData[4][41]=-736;
outL->wData[4][42]=357;
outL->wData[4][43]=-38;
outL->wData[4][44]=89;
outL->wData[5][0]=151;
outL->wData[5][1]=83;
outL->wData[5][2]=-301;
outL->wData[5][3]=-36;
outL->wData[5][4]=24;
outL->wData[5][5]=200;
outL->wData[5][6]=37;
outL->wData[5][7]=-150;
outL->wData[5][8]=-176;
outL->wData[5][9]=-506;
outL->wData[5][10]=-148;
outL->wData[5][11]=-32;
outL->wData[5][12]=-170;
outL->wData[5][13]=-37;
outL->wData[5][14]=-987;
outL->wData[5][15]=182;
outL->wData[5][16]=-108;
outL->wData[5][17]=38;
outL->wData[5][18]=-122;
outL->wData[5][19]=-324;
outL->wData[5][20]=186;
outL->wData[5][21]=-152;
outL->wData[5][22]=17;
outL->wData[5][23]=-172;
outL->wData[5][24]=-82;
outL->wData[5][25]=179;
outL->wData[5][26]=122;
outL->wData[5][27]=-102;
outL->wData[5][28]=74;
outL->wData[5][29]=123;
outL->wData[5][30]=289;
outL->wData[5][31]=8;
outL->wData[5][32]=-98;
outL->wData[5][33]=209;
outL->wData[5][34]=-632;
outL->wData[5][35]=33;
outL->wData[5][36]=-829;
outL->wData[5][37]=-256;
outL->wData[5][38]=251;
outL->wData[5][39]=-746;
outL->wData[5][40]=-10;
outL->wData[5][41]=-138;
outL->wData[5][42]=-831;
outL->wData[5][43]=238;
outL->wData[5][44]=-215;
outL->wData[6][0]=86;
outL->wData[6][1]=217;
outL->wData[6][2]=122;
outL->wData[6][3]=-189;
outL->wData[6][4]=-438;
outL->wData[6][5]=115;
outL->wData[6][6]=51;
outL->wData[6][7]=-239;
outL->wData[6][8]=168;
outL->wData[6][9]=92;
outL->wData[6][10]=64;
outL->wData[6][11]=265;
outL->wData[6][12]=-940;
outL->wData[6][13]=-92;
outL->wData[6][14]=-915;
outL->wData[6][15]=207;
outL->wData[6][16]=-6;
outL->wData[6][17]=-253;
outL->wData[6][18]=-190;
outL->wData[6][19]=233;
outL->wData[6][20]=263;
outL->wData[6][21]=-966;
outL->wData[6][22]=245;
outL->wData[6][23]=165;
outL->wData[6][24]=-242;
outL->wData[6][25]=102;
outL->wData[6][26]=-74;
outL->wData[6][27]=53;
outL->wData[6][28]=-195;
outL->wData[6][29]=-153;
outL->wData[6][30]=40;
outL->wData[6][31]=77;
outL->wData[6][32]=30;
outL->wData[6][33]=-799;
outL->wData[6][34]=128;
outL->wData[6][35]=-158;
outL->wData[6][36]=60;
outL->wData[6][37]=-239;
outL->wData[6][38]=175;
outL->wData[6][39]=-120;
outL->wData[6][40]=154;
outL->wData[6][41]=-100;
outL->wData[6][42]=-483;
outL->wData[6][43]=127;
outL->wData[6][44]=-235;
outL->wData[7][0]=-323;
outL->wData[7][1]=354;
outL->wData[7][2]=106;
outL->wData[7][3]=-670;
outL->wData[7][4]=165;
outL->wData[7][5]=372;
outL->wData[7][6]=150;
outL->wData[7][7]=-159;
outL->wData[7][8]=147;
outL->wData[7][9]=-938;
outL->wData[7][10]=-383;
outL->wData[7][11]=254;
outL->wData[7][12]=-581;
outL->wData[7][13]=-96;
outL->wData[7][14]=-14;
outL->wData[7][15]=126;
outL->wData[7][16]=92;
outL->wData[7][17]=142;
outL->wData[7][18]=-11;
outL->wData[7][19]=55;
outL->wData[7][20]=-385;
outL->wData[7][21]=175;
outL->wData[7][22]=127;
outL->wData[7][23]=-301;
outL->wData[7][24]=71;
outL->wData[7][25]=8;
outL->wData[7][26]=-179;
outL->wData[7][27]=-757;
outL->wData[7][28]=168;
outL->wData[7][29]=41;
outL->wData[7][30]=-10;
outL->wData[7][31]=112;
outL->wData[7][32]=-259;
outL->wData[7][33]=180;
outL->wData[7][34]=72;
outL->wData[7][35]=-109;
outL->wData[7][36]=91;
outL->wData[7][37]=-98;
outL->wData[7][38]=-396;
outL->wData[7][39]=-251;
outL->wData[7][40]=114;
outL->wData[7][41]=-364;
outL->wData[7][42]=45;
outL->wData[7][43]=-10;
outL->wData[7][44]=-16;
outL->wData[8][0]=12;
outL->wData[8][1]=80;
outL->wData[8][2]=-254;
outL->wData[8][3]=-26;
outL->wData[8][4]=-365;
outL->wData[8][5]=-105;
outL->wData[8][6]=-122;
outL->wData[8][7]=343;
outL->wData[8][8]=219;
outL->wData[8][9]=-449;
outL->wData[8][10]=139;
outL->wData[8][11]=-232;
outL->wData[8][12]=-488;
outL->wData[8][13]=-406;
outL->wData[8][14]=-161;
outL->wData[8][15]=80;
outL->wData[8][16]=312;
outL->wData[8][17]=-161;
outL->wData[8][18]=-26;
outL->wData[8][19]=58;
outL->wData[8][20]=353;
outL->wData[8][21]=139;
outL->wData[8][22]=242;
outL->wData[8][23]=-125;
outL->wData[8][24]=142;
outL->wData[8][25]=-663;
outL->wData[8][26]=117;
outL->wData[8][27]=-59;
outL->wData[8][28]=146;
outL->wData[8][29]=308;
outL->wData[8][30]=52;
outL->wData[8][31]=-343;
outL->wData[8][32]=-149;
outL->wData[8][33]=-169;
outL->wData[8][34]=183;
outL->wData[8][35]=-25;
outL->wData[8][36]=-941;
outL->wData[8][37]=161;
outL->wData[8][38]=-57;
outL->wData[8][39]=157;
outL->wData[8][40]=175;
outL->wData[8][41]=-103;
outL->wData[8][42]=-476;
outL->wData[8][43]=-609;
outL->wData[8][44]=230;
outL->wData[9][0]=-178;
outL->wData[9][1]=249;
outL->wData[9][2]=-759;
outL->wData[9][3]=-273;
outL->wData[9][4]=170;
outL->wData[9][5]=-798;
outL->wData[9][6]=-764;
outL->wData[9][7]=32;
outL->wData[9][8]=-15;
outL->wData[9][9]=-298;
outL->wData[9][10]=265;
outL->wData[9][11]=-131;
outL->wData[9][12]=-830;
outL->wData[9][13]=-665;
outL->wData[9][14]=170;
outL->wData[9][15]=-93;
outL->wData[9][16]=-43;
outL->wData[9][17]=84;
outL->wData[9][18]=-422;
outL->wData[9][19]=95;
outL->wData[9][20]=242;
outL->wData[9][21]=189;
outL->wData[9][22]=-56;
outL->wData[9][23]=162;
outL->wData[9][24]=-65;
outL->wData[9][25]=-519;
outL->wData[9][26]=40;
outL->wData[9][27]=125;
outL->wData[9][28]=-45;
outL->wData[9][29]=-72;
outL->wData[9][30]=-533;
outL->wData[9][31]=-498;
outL->wData[9][32]=55;
outL->wData[9][33]=5;
outL->wData[9][34]=-277;
outL->wData[9][35]=249;
outL->wData[9][36]=200;
outL->wData[9][37]=148;
outL->wData[9][38]=106;
outL->wData[9][39]=149;
outL->wData[9][40]=-320;
outL->wData[9][41]=-277;
outL->wData[9][42]=-368;
outL->wData[9][43]=122;
outL->wData[9][44]=-134;
outL->basicData[0]=122;
outL->basicData[1]=183;
outL->basicData[2]=192;
outL->basicData[3]=135;
outL->basicData[4]=39;
outL->basicData[5]=214;
outL->basicData[6]=140;
outL->basicData[7]=236;
outL->basicData[8]=179;
outL->basicData[9]=131;


	for (i = 0; i < outputNum; i++)
	{
		for (k = 0; k < inputNum; k++)
		{
			outL->outputdata[i] += inputData[k] * outL->wData[i][k];
		}
		//printf("%f\n ", cnn->fc160_1->y[i]);
		outL->outputdata[i] = activation_relu(outL->outputdata[i], outL->basicData[i]);
		//printf("%f\n ",outL->outputdata[i]);
		printf("output %d\n", outL->outputdata[i]);
	}

	for (i = (outputNum - 1); i != (-1); i--)
	{
		free(outL->wData[i]);
	}
	free(outL->wData);
	free(outL->basicData);
}


void conv23(int model,int *addr){
	//printf("conv23 addr is %d\n",addr);
	int size,result;
	if(model==0){
		size = 16;
	}
	else{
		size = 65552;
	}
	__asm__ __volatile__(
		"addi zero,zero,0\n"
		".insn r 0x77, 1, 0, %[con_o], %[con_i1], %[con_i2]"
		:[con_o] "=r"(result)
		:[con_i1]"r"(addr),[con_i2]"r"(size)
		);
}

void wb23(int *addr){
	int n=0;
	int result;
	__asm__ __volatile__(
		"addi zero,zero,0\n"
		".insn r 0x77, 1, 1, %[out], %[addr], %[null]"
		:[out] "=r"(result)
		:[addr]"r"(addr),[null]"r"(n)
		:"memory"
	);
}

void w_wb(int rank, int value){
	int null;
	__asm__ __volatile__(
		"addi zero,zero,0\n"
		".insn r 0x77, 4, 0, %[null], %[rank], %[value]"
		:[null] "=r"(null)
		:[rank]"r"(rank),[value]"r"(value)
		);
}

void max_pooling(){
	int null;
	int in1=0;
	int in2=0;
	__asm__ __volatile__(
		"addi zero,zero,0\n"
		".insn r 0x77, 2, 0, %[null], %[in1], %[in2]"
		:[null] "=r"(null)
		:[in1]"r"(in1),[in2]"r"(in2)
		);
}

void mp_wb(int *addr){
	int null;
	int in2=0;
	__asm__ __volatile__(
		"addi zero,zero,0\n"
		".insn r 0x77, 2, 1, %[null], %[addr], %[in2]"
		:[null] "=r"(null)
		:[addr]"r"(addr),[in2]"r"(in2)
		);
}
void mp_ri(int *addr){
	int null;
	int in2 = 0;
	__asm__ __volatile__(
		"addi zero,zero,0\n"
		".insn r 0x77, 2, 2, %[null], %[addr], %[in2]"
		:[null] "=r"(null)
		:[addr]"r"(addr),[in2]"r"(in2)
		);
}

void relu(int bias){
	int null;
	int in2 = 0;
	__asm__ __volatile__(
		"addi zero,zero,0\n"
		".insn r 0x77, 3, 0, %[null], %[in1], %[in2]"
		:[null] "=r"(null)
		:[in1]"r"(bias),[in2]"r"(in2)
		);
}


int main(int argc, char* argv[])
{
	int cycle_s;
	int cycle_e;
	__asm__ __volatile__(
	"rdcycle %[rdcycle]"
	:[rdcycle] "=r"(cycle_s)
	);

	char* filename;
	char* filename1;
	int** inputData;
	int*** y;
	int* y1;
	
	filename = "";
	inputData = read_image(filename);
	y=input(inputData,filename,28,28,3,1,6);//kernal_size=5

// y=pool(y,26,26, MaxPool, 2,6,6,2);//kernal_size=3

	y=conv(y,filename,13,13,3,6,9);//kernal_size=3
	
// y=pool(y,11,11, MaxPool,2,9,9,2);//kernal_size=3
	
	y=pool(y,6,6, MaxPool,2,9,9,2);//kernal_size=3

	y1 = flatten(y, 3, 3, 9, 81);//kernal_size=3
	y1 = fc(y1,filename,81,45);

	output(y1, filename, 45, 10,filename1);
	__asm__ __volatile__(
	"rdcycle %[rdcycle]"
	:[rdcycle] "=r"(cycle_e)
	);
	printf("cycle=%d\n",cycle_e-cycle_s);
	return 0;
}

// LeNet-5 use c achieve 卷积神经网络的C语言实现


// how to use python下 1.在python环境下训练模型，并保存模型（python->model_train.py） 
// 2.模型预测，获取模型预测的结果（python->model_predict.py） 
// 3.获取模型各层权重参数（python->get_model_weight） 
// 4.将图片转为.bin格式（python->image_to_array.py） 
// 5.获取模型各层结果（get_layers_results.py） 
// C下： 1.根据需要修改网络结构，以及数据存放位置。 2.直接运行就可以了
