#include <stdio.h>
#include <stdlib.h>

const char* inputFilename = "input";

int main()
{
    FILE* fp;
    char buf[255];

    int lastReading = -1;
    int currentReading = -1;
    int increases = 0;
    int reading[3];

    // open input file for reading
    fp = fopen(inputFilename, "r");

    // load up first three positions
    fscanf(fp, "%s", buf);
    reading[0] = atoi(buf);
    fscanf(fp, "%s", buf);
    reading[1] = atoi(buf);
    fscanf(fp, "%s", buf);

    // off we loop
    while (fscanf(fp, "%s", buf) == 1)
    {
        // move elements over and drop the first one
        reading[0] = reading[1];
        reading[1] = reading[2];

        // read in new element
        reading[2] = atoi(buf);

        lastReading = currentReading;
        currentReading = 0;
        for (int i=0; i<3; i++)
        {
            currentReading += reading[i];
        }

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
