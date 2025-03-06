#include<stdio.h>
#include<limits.h>
int main()
{
int i,j,k,n,source;
int w[50][50];
int visited[20];
int minwt,tc=0,ev=0,sv=0;
printf("Enter the number of vertices in graph.");
scanf("%d",&n);
printf("Enter the weight matrix\n");
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
scanf("%d",&w[i][j]);
}
}
printf("Enter the source vertex of start\n");
scanf("%d",&source);
for(i=1;i<=n;i++)
visited[i]=0;
visited[source]=1;
printf("Minimum weight edge selected foe spanning tree are:\n");
for(i=1;i<n;i++){
minwt=INT_MAX;
for(j=1;j<=n;j++){
if(visited[j]==1){
for(k=1;k<=n;k++){
if(visited[k]!=1 && w[j][k]<minwt){
sv=j;
ev=k;
minwt=w[j][k];
}
}
}
}
tc+=minwt;
visited[ev]=1;
printf("%d-->%d cost:%d\n",sv,ev,minwt);
}
printf("The Total Cost of mst id %d\n",tc);
return 0;
}



