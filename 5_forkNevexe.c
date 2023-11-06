#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
void bubble_sort_asc(int a[], int n){
for (int i = n - 1; i > 0; i--) {
for (int j = 0; j < i; j++) {
if (a[j] > a[j + 1]) {
int temp = a[j];
a[j] = a[j + 1];
a[j + 1] = temp;
}
}
}
}
void bubble_sort_dsc(int a[], int n){
for (int i = n - 1; i > 0; i--) {
for (int j = 0; j < i; j++) {
if (a[j] < a[j + 1]) {
int temp = a[j];
a[j] = a[j + 1];
a[j + 1] = temp;
}
}
}
}
int main(int argc, char *argv[]){

int n = argc - 2;
printf("enter the number of element in array:");
scanf("%d",&n);
int a[n];
for (int i = 0; i < n; i++) {
scanf("%d",&a[i]);
}
pid_t pid = fork();
if (pid == 0) {
// Child Process
bubble_sort_dsc(a, n);
printf("\nI am Child Process, my pid is %d\n", getpid());
printf("I am Parent Process, my pid is %d\n", getppid());
printf("\nSorted Array in Child Process:\n");
for (int i = 0; i < n; i++) {
printf("%d\n", a[i]);
}
execve(argv[1], argv + 1, NULL);
}
else
{
int k;
wait(&k);
bubble_sort_asc(a, n);
printf("\nI am Parent Process, my pid is %d\n", getpid());
printf("I am Parent's Parent Process, my pid is %d\n\n", getppid());
printf("Sorted Array in Parent Process:\n");
for (int i = 0; i < n; i++)
{
printf("%d\n", a[i]);
}
}
return 0;
}

