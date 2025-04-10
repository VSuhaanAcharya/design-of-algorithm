#include<stdio.h>
#define MAX 10
double cmv(double w,double wt[],double val[],double ratio[],int nt);
int gni(double wt[],double val[],double ratio[],int nt);
int main()
{
int nt;
double w;
double wt[MAX];
double val[MAX];
double ratio[MAX];
printf("Enter the number of items:");
scanf("%d",&nt);
printf("Enter the weight of the items:\n");
for(int i=0;i<nt;i++){
scanf("%lf",&wt[i]);
}
printf("Enter the value  of the items:\n");
for(int i=0;i<nt;i++){
scanf("%lf",&val[i]);
}
for(int i=0;i<nt;i++){
ratio[i]=val[i]/wt[i];
}
printf("Enter the capacity of knapsack:");
scanf("%lf",&w);
printf("\n The maximum value in knapsack of capacity %2f is:%.2f\n",w,cmv(w,wt,val,ratio,nt));
return 0;
}
double cmv(double w,double wt[],double val[],double ratio[],int nt)
{
double cw=0;
double cv=0;
printf("\n Items considered are:");
while(cw<w){
int item=gni(wt,val,ratio,nt);
if(item==-1){
break;
}
printf("%d",item+1);
if(cw+wt[item]<=w){
cw+=wt[item];
cv+=val[item];
ratio[item]=0;
}
else{
cv+=(ratio[item]*(w-cw));
cw+=(w-cw);
break;
}
}
return cv;
}
int gni(double wt[],double val[],double ratio[],int nt){
double highest=0;
int index=-1;
for(int i=0;i<nt;i++){
if(ratio[i]>highest){
highest=ratio[i];
index=i;
}
}
return index;
}



