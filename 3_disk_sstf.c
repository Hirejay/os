#include<stdio.h>
#include<stdlib.h>
void sstf(int sequence[],int head,int n){
int seektime=0;
int visited[n];
printf("\nthe disk sequence is:");
for(int i=0;i<n;i++){
visited[i]=0;
}
while(1){
int pos;
int min=999;
for(int i=0;i<n;i++){

if(visited[i]==0 && min>abs(head-sequence[i]) ){
min=abs(head-sequence[i]);
pos=i;
}

}
if(min==999){
break;
}
visited[pos]=1;
seektime+=min;
head=sequence[pos];
printf(" > %d ",sequence[pos]);

}

printf("\nseektime of sstf= %d\n",seektime);
}


int main(){
int n,head;
printf("\nenter the inint disk :");
scanf("%d", &head);
printf("\nenter the number of disk sequence: ");
scanf("%d",&n);
int sequence[n];
printf("\nenter the disk sequence:");
for(int i=0; i<n; i++)
	{
		scanf("%d", &sequence[i]);
	}


sstf(sequence,head,n);

}
