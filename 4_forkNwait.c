#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

void sort(int arr[], int n) {  
  int i, j; 
  
  for (i = 0; i < n - 1; i++) {  
    for (j = 0; j < n - i - 1; j++) {  
 
      if (arr[j]>arr[j+1]) {  
        int temp = arr[j];  
        arr[j] = arr[j + 1];  
        arr[j + 1] = temp;  
      }  
    }  
  }  
}  
int main(){
int pid,size;
printf("\nenter the size of array :");
scanf("%d",&size);
int arr[size];
printf("\nenter the elements :");
for(int i=0;i<size;i++){
scanf("%d",&arr[i]);

}
pid=fork();
if(pid==0){
printf("\nchild's pid %d",getpid());
printf("\nparent's pid %d",getppid());
printf("\nsorted array is: ");
sort(arr,size);
for(int i=0;i<size;i++){
printf("%d\t",arr[i]);

}
printf("\n");
}
else if(pid>0){
int status;
wait(&status);
printf("\n\n\n\n\nchild is terminated %d",pid);
printf("\nparent's pid %d",getpid());
printf("\nparent's parent pid %d",getppid());
printf("\nsorted array is: ");
sort(arr,size);
for(int i=0;i<size;i++){
printf("%d\t",arr[i]);

}
printf("\n");

}else{

printf("\nerror in fork");
}

return 0;
}



