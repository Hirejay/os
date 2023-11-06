#include <stdio.h>

int main() {
    int process, resource, i, j;
    

    printf("Enter the number of processes: ");
    scanf("%d", &process);
    printf("Enter the number of resources: ");
    scanf("%d", &resource);

    int available[resource], max[process][resource], allocated[process][resource], need[process][resource];

    for (i = 0; i < process; i++) {
        for (j = 0; j < resource; j++) {
            available[j] = 0;
            allocated[i][j] = 0;
            max[i][j] = 0;
            need[i][j] = 0;
        }
    }

    for (i = 0; i < resource; i++) {
        printf("Enter the available instances of Resource[%d]: ", i);
        scanf("%d", &available[i]);
    }

    printf("Enter the maximum demand matrix for processes:\n");
    for (i = 0; i < process; i++) {
        for (j = 0; j < resource; j++) {
            printf("For Process[%d], Resource[%d]: ", i, j);
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < process; i++) {
        for (j = 0; j < resource; j++) {
            printf("For Process[%d], Resource[%d]: ", i, j);
            scanf("%d", &allocated[i][j]);
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }

    int count = 0;
    int completed[process];
    for (i = 0; i < process; i++) {
        completed[i] = 0;
    }

    printf("Safe Sequence is: ");
    while (count != process) {
        int k = 0;
        for (i = 0; i < process; i++) {
            for (j = 0; j < resource; j++) {
                if (need[i][j] <= available[j]) {
                    k++;
                }
            }

            if (k == resource && completed[i] == 0) {
                printf(" > P[%d] ", i);
                completed[i] = 1;
                for (j = 0; j < resource; j++) {
                    available[j] += allocated[i][j];
                }
                count++;
            }
            k = 0;
        }
    }

    for (i = 0; i < process; i++) {
        if (completed[i] != 1) {
            printf("\n\n P[%d] cannot be allocated", i);
        }
    }
    printf("\n");

    return 0;
}

