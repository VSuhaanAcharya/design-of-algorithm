#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int partition(int arr[],int low,int high){
int pivot=arr[low];
int i=low+1;
int j=high;
int temp;
while(1){
while(i<=high && arr[i]<=pivot)
i++;
while(arr[j]>pivot)
j--;
if(i<j){
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}else{
temp=arr[low];
arr[low]=arr[j];
arr[j]=temp;
return j;
}
}
}
void quicksort(int arr[],int low,int high){
if(low<high){
int pi=partition(arr,low,high);
quicksort(arr,low,pi-1);
quicksort(arr,pi+1,high);
}
}
int main()
{
int n;
printf("Enter the number of elements:");
scanf("%d",&n);
int arr[n];
srand(time(NULL));
for(int i=0;i<n;i++)
{
arr[i]=rand()%25000;
//printf("%d\t",arr[i]);
}
clock_t start=clock();
quicksort(arr,0,n-1);
//for(int i=0;i<n;i++){
//printf("%d\t",arr[i]);}
//printf("\n");
clock_t end=clock();
double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
printf("sorted array is\n");
for(int i=0;i<10;i++){
printf("%d\t",arr[i]);}
printf("Time taken for sorting:%f seconds\n",time_taken);
return 0;
}
