#include <stdio.h>

const char* inputFilename = "input";

int main()
{
    FILE* fp;
    char buf[255];
    int lastReading = -1;
    int currentReading = -1;
    int increases = 0;

    // read input
    fp = fopen(inputFilename, "r");
    fscanf(fp, "%s", buf);
    currentReading = atoi(buf);
    printf("%d\n", currentReading);

    while (fscanf(fp, "%s", buf) == 1)
    {
        lastReading = currentReading;
        currentReading = atoi(buf);

        printf("%d", currentReading);

        if (currentReading > lastReading)
        {
            increases++;
            printf(" (increased)");
        }
        printf("\n");
    }

    printf("%d depth increases.\n", increases);
    
    fclose(fp);
    return 0;
}
