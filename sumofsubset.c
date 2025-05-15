#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int X[MAX];
int S[MAX];
int d,flag=0;
void sumofsub(int m,int k,int r);
void inputArray(int arr[],int n);
int main(){
int n,sum=0;
printf("enter number of elements:");
scanf("%d",&n);
printf("enter the elements:\n");
inputArray(S,n);
printf("enter the value of d:");
scanf("%d",&d);
int i;
for(i=1;i<=n;i++){
sum+=S[i];
}
if(sum<d||S[i]>d){
printf("the given problem instance does not have solution\n");
return 0;
}else{
printf("subsets are\n");
sumofsub(0,1,sum);
}
if(flag==0){
printf("no subset possible\n");
}
return 0;
}
void sumofsub(int m,int k,int r){
int i;
X[k]=1;
if(m+S[k]==d){
flag=1;
printf("{");
for(i=1;i<=k;i++){
if(X[i]==1){
printf("%d",S[i]);
}
}
printf("}\n");
}
else if((m+S[k]+S[k+1])<=d){
sumofsub(m+S[k],k+1,r-S[k]);
}
if((m+r-S[k]>=d)&&(m+S[k+1]<=d)){
X[k]=0;
sumofsub(m,k+1,r-S[k]);
}
}
void inputArray(int arr[],int n){
int i;
for(i=1;i<=n;i++){
scanf("%d",&arr[i]);
}
}
