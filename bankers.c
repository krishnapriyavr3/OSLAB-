#include<stdio.h>

void main() {
    int n, m, i, j, k, y, allo[20][20], max[20][20], ava[50], ind = 0;
    
    printf("Enter the no. of processes:\n");
    scanf("%d", &n);
    printf("Enter the number of resources:\n");
    scanf("%d", &m);
    
    printf("Enter the Allocation matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &allo[i][j]);
        }
    }

    printf("Enter the Max matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the Available matrix:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &ava[i]);
    }

    // Need matrix 
    int finish[n], safesequence[n], work[m], need[n][m];
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allo[i][j];
        }
    }

     printf("Need Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf(" %d ", need[i][j]);
        }
        printf("\n");
    }

        for(i = 0; i < m; i++) {
        work[i] = ava[i];
    }

    for(i = 0; i < n; i++) {
        finish[i] = 0;      }

       int flag = 0;
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {
                flag = 0;
                for(j = 0; j < m; j++) {
                    if(need[i][j] > work[j]) {
                        flag = 1;
                        break;
                    }
                }
                
                               if(flag == 0) {
                    safesequence[ind++] = i;
                    for(y = 0; y < m; y++) {
                        work[y] += allo[i][y];
                    }
                    finish[i] = 1;
                }
            }
        }
    }

      printf("Safe sequence:\n");
    for(i = 0; i < n; i++) {
        printf("P%d ", safesequence[i]);
    }
    printf("\n");
}

