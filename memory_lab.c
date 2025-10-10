#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void myFunction() {
            int largeArray[9 * 1024 * 1024]; // Allocate a large array on the stack
            largeArray[0] = 1; // Use the array to prevent optimization
        }

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "memory_leak") == 0) {
        char *leak = malloc(1024); // Allocate 1KB
        if (leak == NULL) {
            perror("Failed to allocate memory");
            return 1;
        }
        // Intentionally not freeing the allocated memory to simulate a memory leak
        printf("Memory leak simulated: 1KB allocated and not freed.\n");
        return 0;
    }

    else if (strcmp(argv[1], "stack_leak") == 0) {
        myFunction();
        printf("Allocated ~9MB on stack (may crash before printing).\n");
        return 0;
    }

    else if (strcmp(argv[1], "out_of_memory") == 0) {
        for (int i = 0; i < 1024; i++) { // Try to allocate 1GB in total
            char *block = malloc(1024 * 1024); // Allocate 1MB blocks
            if (block == NULL) {
                perror("Out of memory");
                return 1;
            }
            printf("Allocated %d MB\n", i + 1);
        }
        printf("Successfully allocated 1GB (unexpected).\n");
        return 0;
    }

    else {
        printf("Unknown option: %s\n", argv[1]);
        return 1;
    }

}