#include<stdio.h>
#define MAX 20
void warshall(int n,int r[MAX][MAX]);
int main()
{
int r[MAX][MAX];
int i,j,n;
printf("Enter the number of nodes/vertices:");
scanf("%d",&n);
printf("enter the weight/cost matrix:\n");
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
scanf("%d",&r[i][j]);
}
}
warshall(n,r);
return 0;
}
void warshall(int n,int r[MAX][MAX]){
int i,j,k;
for(k=1;k<=n;k++){
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
r[i][j]=r[i][j]||(r[i][k]&&r[k][j]);
}
}
}
printf("\n\t----------------------------------------------------\n");
for(i=1;i<=n;i++){
printf("%d|\t",i);
for(j=1;j<=n;j++){
printf("%d\t",r[i][j]);
}
printf("\n");
}
}


