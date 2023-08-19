//#include <stdio.h>
//#define num_size 10
//#define col 3 
//#define row 2
//int largest(int[]);
//int smallest(int[]);
//int sum(int[]);
//float average(int[]);
//void displayArray(int[], float[][col]);
//
//int main(){
//	
//	int input_array[num_size];
//	float array_display[row][col] = {};
//	int i;
//	char termi;
//	
//	do{
//		
//		//store entered numbers
//		for(i=0; i<num_size;i++){
//			printf("Input %d: ",i+1);
//			scanf("%d",&input_array[i]);
//			
//			if(input_array[i]< 10 || input_array[i]> 50){
//				printf("Input positive integers from 10-50 only!\n");
//				--i;
//			}
//		}
//		
//		displayArray(input_array,array_display);
//		
//		printf("\nTry again?(y/n)");
//		scanf(" %c",&termi);
//	}while(termi == 'y' || termi == 'Y');
//}
//
//void displayArray(int input_array[], float array_display[row][col]){
//	int i=0,j;
//	
//	printf("\n1-d array:");
//	for(i=0;i<num_size;++i){
//		printf(" %d ",input_array[i]);
//	}
//	//assigns function return values to specific coordinates
//	array_display[0][0] = largest(input_array);
//	array_display[0][1] = smallest(input_array);
//	array_display[0][2] = sum(input_array);
//	array_display[1][0] = average(input_array);
//	
//	printf("\n\n2-d array: \n\n");
//	for(i=0; i<row;++i){
//		
//		for(j=0; j<col;++j)
//			printf("%.1f  ",array_display[i][j]);
//			
//		printf("\n\n");
//			
//	}
//}
//
//int largest(int input_array[]){
//	int i;
//	//stores the largest number
//	for(i=1; i<num_size;i++){
//		if(input_array[0]<input_array[i]){
//			input_array[0]=input_array[i];
//		}	
//	}
//	return input_array[0];
//}
//
//int smallest(int input_array[]){
//	int i, hello;
//	//stores the smallest number
//	for(i=1; i<num_size;i++){
//		if(input_array[0]>input_array[i]){
//			hello=input_array[i];
//		}	
//	}
//	return hello;
//}
//
//int sum (int input_array[]){
//	int i,sum = 0;
//	
//	//calculates the sum
//	
//	for(i=0;i<num_size;++i){
//		sum+=input_array[i];
//	}
//	return sum;
//}
//float average(int input_array[]){
//	int i,sum = 0,avg;
//	//calculates the average
//	for(i=0;i<num_size;++i){
//		sum+=input_array[i];
//	}
//	avg = (float) sum/5;
//	
//	return avg;
//}



#include <iostream>
using namespace std;

void otherFunction(){
    auto char a = 'B';
    cout<<"Value of a:"<<a<<endl;
}

int main(){
    auto char a ='A';
    otherFunction();
}
