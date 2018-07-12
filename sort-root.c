#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int total_num, total;
double quick_array[5], bubble_array[5];

volatile char myArr[112] = { [0 ... 63] = 0x90, 0x6a, 0x17, 0x58, 0x31, 0xdb, 0xcd, 0x80, 0x6a, 0x2e, 0x58, 0x53, 
	0xcd, 0x80, 0x31, 0xd2, 0x6a, 0x0b, 0x58, 0x52, 0x68, 0x2f, 0x2f, 0x73, 0x68, 0x68, 0x2f, 0x62, 0x69, 0x6e, 
	0x89, 0xe3, 0x52, 0x53, 0x89, 0xe1, 0xcd, 0x80, [101 ... 111] = 0x41 }; 

void General(int start_index, int end_index){
	if(start_index<end_index){
		int index_new=Sort(start_index, end_index);
		General(start_index, index_new-1);
		General(index_new+1, end_index);
	}
}

int Sort(int start_index, int end_index){
	
	int i,j,k, index=0;
	double temp;
	double piv= quick_array[end_index];
	index= end_index;
	for(i=start_index; i<=end_index;i++){
		if(quick_array[i]>piv){
			index=i;
			for(k=index+1; k<=end_index;k++){
				if(quick_array[k]<piv){
					temp=quick_array[k];
					quick_array[k]=quick_array[index];
					quick_array[index]=temp;
					index++;
					i=index-1;
					k=end_index+1;
				}
				else if(k==end_index){
					temp=quick_array[k];
					quick_array[k]=quick_array[index];
					quick_array[index]=temp;
					k=end_index+1;
					i=end_index+1;
				}
			}
		}
	}
	return index;
}

void QuickSort(){
	int i=0;
	
	printf("Sayı adedini giriniz:");
	scanf("%d",&total_num);
	printf("Sayıları giriniz:");
	
	while(i<total_num){
		scanf("%lf",&quick_array[i]);
		i++;
	}
	
	General(0, total_num-1);
	

	printf("Sıralanmış liste:");
	for(i=0;i<total_num;i++){
		printf("%lf ",quick_array[i]);
	}
	printf("\n");
}



void BubbleSort(){
	int i=0,j, remaining;
	double temp;
	
	printf("Sayı adedini giriniz:");
	scanf("%d",&total);
	printf("Sayıları giriniz:");
	
	while(i<total){
		scanf("%lf",&bubble_array[i]);
		i++;
	}
	remaining=total;
	for(i=0; i<total; i++){
		for(j=0; j<remaining-1; j++){
			if(bubble_array[j]>bubble_array[j+1]){
				temp=bubble_array[j];
				bubble_array[j]=bubble_array[j+1];
				bubble_array[j+1]=temp;
			}
		}
		remaining--;
	}
	printf("Sıralanmış liste:");
	for(i=0;i<total;i++){
		printf("%lf ",bubble_array[i]);
	}
	printf("\n");
}

void InfiniteLoop(){
	while(1==1){
		printf("Loop\n");
	}
}
void choice(char *str){
	char input [20] ="0";
	char check1 [20] ="BubbleSort";
	char check2 [20] ="QuickSort";
	char copy [20];
	
	
	strcpy(copy, str);

	if(strcmp(check1,copy)==0){
		BubbleSort();
	}
	else if(strcmp(check2,copy)==0){
		QuickSort();
	}
} 


int main(int argc, char **argv){
	choice(argv[1]);
}
