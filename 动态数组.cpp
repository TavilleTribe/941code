#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 5;
    int *dynamicArray = (int *)malloc(size * sizeof(int)); // 动态数组内存分配

    if (dynamicArray == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &dynamicArray[i]);
    }

    printf("Dynamic Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    free(dynamicArray); // 动态数组内存释放

    return 0;
}
