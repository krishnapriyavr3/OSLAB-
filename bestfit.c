#include <stdio.h>

void bestFit(int blockSize[], int m, int processSize[], int n) 
{
    int allocation[n],INT_MAX;

    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

     for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        int minDiff = INT_MAX;

        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                int diff = blockSize[j] - processSize[i];
                if (diff < minDiff) {
                    minDiff = diff;
                    bestIdx = j;
                }
            }
        }

        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

      printf("\nProcess No.\tProcess Size\tBlock No.\tBlock Size\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, processSize[i], allocation[i] + 1, blockSize[allocation[i]]);
        } else {
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, processSize[i]);
        }
    }
}

int main() {
    int m, n;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    int blockSize[m];
    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processSize[n];
    printf("Enter the size of each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }
    bestFit(blockSize, m, processSize, n);
    return 0;
}

