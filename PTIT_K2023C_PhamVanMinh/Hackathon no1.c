#include<stdio.h>
#include<stdlib.h>
int main()
{
	int row,col,temp;
	int count=0;
	printf("Nhap so cot:");
	scanf("%d",&row);
	printf("Nhap so hang:");
	scanf("%d",&col);
	int mulArray[row][col];
	int choice;
	int max1,max2,min1,min2;
	int max=0;
	int min=0;
	int perfect = 0;
	int sum = 0;
	do{
		printf("\n************************MENU**************************\n");
		printf("1. Nhap gia tri cac phan tu cua mang\n");
		printf("2. In gia tri cac phan tu theo ma tran\n");
		printf("3. Tinh so luong cac phan tu le chia het cho 5 trong mang\n");
		printf("4. In ra cac phan tu co gia tri lon nhat, nho nhat nam tren duong bien, duong cheo chinh, duong cheo phu\n");
		printf("5. Su dung thuat toan sap xep cac phan tu giam dan theo dong cua mang\n");
		printf("6. Tinh tong cac phan tu la so nguyen to trong mang\n");
		printf("7. Su dung thuat toan chen sap xep cac phan tu tren duong cheo phu cua mang tang dan\n");
		printf("8. Nhap gia tri mot mang 1 chieu gom n phan tu và chi so cot muon chen vao mang, thuc hien chen vao mang 2 chieu\n");
		printf("9. Thoat\n");
		printf("Lua chon cua ban:");
		scanf("%d",&choice);
		switch(choice){
			case 1 :
				for(int i=0;i<row;i++){
					for(int j =0;j<col;j++){
						printf("mulArray[%d][%d]=",i,j);
						scanf("%d",&mulArray[i][j]);
					}
				}
				break;
			case 2 :
				printf("Cac phan tu theo ma tran:\n");
				for(int i=0;i<row;i++){
					for(int j =0;j<col;j++){
						printf("%d ",mulArray[i][j]);
					}
					printf("\n");
				}
				break;
			case 3 :
				for(int i=0;i<row;i++){
					for(int j = 0;j<col;j++){
						if(mulArray[i][j] % 2 == 1 && mulArray[i][j]%5==0){
							count++;
						}
					}
				}
				printf("So phan tu le chia het cho 5 la: %d\n",count);
				break;
			case 4 :
				max1 = mulArray[0][0];
				max2 = mulArray[0][0];
				min1 = mulArray[0][0];
				min2 = mulArray[0][0];
				for(int i=0;i<row;i++){
					for(int j=0;j<col;j++){
						if(i == 0 || i == row-1){
							if(max1<mulArray[i][j]){
								max1=mulArray[i][j];
							}
						}else{
							if(mulArray[i][0]<mulArray[i][col-1]){
								max2=mulArray[i][col-1];
							}else{
								max2=mulArray[i][0];
							}
						}
					}
					if(max1<max2){
						max=max2;
					}else{
						max=max1;
					}
				}
				printf("Max cua duong bien la:%d\n",max);
				for(int i=0;i<row;i++){
					for(int j =0;j<col;j++){
						if(i == 0 ||i==row -1){
							if(min1>mulArray[i][j]){
								min1=mulArray[i][j];
							}
						}else{
							if(mulArray[i][0]>mulArray[i][col-1]){
								min2=mulArray[i][col-1];
							}else{
								min2=mulArray[i][0];
							}
						}
					}
					if(min1>min2){
						min=min2;
					}else{
						min=min1;
					}
				}
				printf("Min cua duong bien la:%d\n",min);
				max=mulArray[0][0];
				min=0;
				for(int i=0;i<row;i++){
						if(mulArray[i-1][i-1]<mulArray[i][i]){
							max=mulArray[i][i];
						}
						if(mulArray[i-1][i-1]>mulArray[i][i]){
							min=mulArray[i][i];
						}
					}
				printf("Max,min cua duong cheo chinh la:%d, %d",max,min);
				break;
			case 5 :
				for(int i=0;i<row;i++){
					for(int j=0;j<col;j++){
						for(int k=j+1;k<col;k++){
							if(mulArray[i][j]<mulArray[i][k]){
								temp=mulArray[i][j];
								mulArray[i][j]=mulArray[i][k];
								mulArray[i][k]=temp;
							}
						}
					}
				}
				for(int i=0;i<row;i++){
					printf("\nMang sap xep tu lon den be hang %d la:\t",i);
					for(int j=0;j<col;j++){
						printf("%10d",mulArray[i][j]);
					}
				}
				break;
			case 6 :
				for(int i = 0;i<row;i++){
					for(int j=0;j<col;j++){
						perfect = 0;
						for(int k=mulArray[i][j];k>0;k--){
							if(mulArray[i][j] % k == 0){
								perfect++;
							}
						}
					if(perfect == 2){
					sum +=mulArray[i][j];
						}
					}
				}
				printf("Tong cac so nguyen to:%d\n",sum);
				break;
			case 7 :
				break;
			case 8 :
				break;
			case 9 :
				exit(0);
				break;
			default:
				printf("Moi nhap lai lua chon >:((\n");
		}
	}while(1< choice || choice <9);
}