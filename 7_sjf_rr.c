#include<stdio.h>
#include<stdlib.h>




void sjf()
{
    
	int n; 
	int i;
	printf("Enter the total no of processes: ");
		scanf("%d",&n);
	
    int bt[n]; 		
    int art[n]; 	
	int rmn[n];
	for(i=0;i<n;i++)
	{
		
		printf("Enter the arrival time and burst time for process p[%d]: ",i);
		scanf("%d  %d",&art[i],&bt[i]);
		rmn[i] =bt[i];
	}


	int time = 0;		
	int flag = 0;	
	int j;
	int minm = 1000;	
	int current = 0; 	
	int done = 0;		
	int wait[100];	
	int tat[100];
	int totalwait = 0;
	int totaltat = 0;
	double averagewait = 0.0;
	double averagetat = 0.0; 
		
	while(done < n)	
	{
			
	 for (j = 0; j < n; j++) { 						
            if ((art[j] <= time) && 
            (rmn[j] < minm) && rmn[j] > 0) { 
                minm =rmn[j]; 
                current = j; 							
                flag = 1; 								
            } 
        } 
	
	if (flag!=0)			
	{
		rmn[current]--;	
		
		if(rmn[current] > 0)	
			minm =rmn[current];
		else							
		{
			minm = 1000;
			done++;
			flag = 0;
			wait[current] = time - bt[current] - art[current] + 1;
			tat[current]=time - art[current] + 1;
		}				
	}	
		
	time++;								
	
}
	printf("time passed: %d ",time);
	for(j = 0; j < n; j++){
		totalwait+=wait[j]; 
		totaltat+=tat[j];
	
	}
	averagewait = (double) totalwait / n;
	averagetat = (double) totaltat / n;
		
	printf("\nProcessName\tArrivalTime\tBurstTime\tWaitingTime\tturn time");	
		for(i=0;i<n;i++)
		{
		printf("\np[%d]\t\t%d\t\t%d\t\t%d\t\t%d",i,art[i],bt[i],wait[i],tat[i]);
		}
	
	printf("\nTotal waiting time: %d \nAverage waiting time: %f",totalwait,averagewait);
	printf("\nTotal turn time: %d \nAverage turn time: %f",totaltat,averagetat);
		
	
}

void rr(){
int tat=0,wt=0,n,qt;
printf("\nenter the number of process:");
scanf("%d",&n);
int at[n],bt[n],rt[n];
for(int i=0;i<n;i++){
printf("\nenter the arrival time and burst time for process[%d]",i);
scanf("%d  %d",&at[i],&bt[i]);
rt[i]=bt[i];
}
printf("\nenter the quantum time:");
scanf("%d",&qt);
printf("\nprocess\ttat\twt\n");
int remain=n, cnt=0,flag=0,t=0;
while(remain!=0){
if(rt[cnt]<=qt && rt[cnt]>0){
t+=rt[cnt];
rt[cnt]=0;
flag=1;
}
else if(rt[cnt]>0){
rt[cnt]-=qt;
t+=qt;
}
if(rt[cnt]==0 && flag==1){
remain--;
printf("p[%d]\t[%d]\t[%d]\n",cnt,t-at[cnt],t-at[cnt]-bt[cnt]);
wt+=t-at[cnt]-bt[cnt];
tat+=t-at[cnt];
flag=0;
}
cnt=(cnt+1)%n;
if(cnt==0 || at[cnt]<=t){

}else{
cnt=0;
}

}




printf("\naverage turn around time :%f",(float)tat/n);
printf("\naverage waiting time :%f",(float)wt/n);
}
int main(){
int ch;
do{

printf("\n------menu-----\n1.rr\n2.sjf\n3.exit\nenter your choice:");
scanf("%d",&ch);
switch(ch){
case 1: 
       rr();
       break;
         

case 2:
       sjf();
       break;
      
        
case 3: 
       exit(0);




}

}while(1);

return 0;
}






