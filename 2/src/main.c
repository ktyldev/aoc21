#include <stdio.h>

const char* inputFilename = "input";

int main()
{
    FILE* fp;
    char buf[16];

    int depth = 0;
    int hpos = 0;

    // open input file for reading
    fp = fopen(inputFilename, "r");

    while (1)
    {
        fscanf(fp, "%s", buf);
        char dir = buf[0];

        fscanf(fp, "%s", buf);
        int amount = atoi(buf);

        if (feof(fp)) break;

        switch (dir)
        {
            case 'f':
                hpos += amount;
                break;
            case 'd':
                depth += amount;
                break;
            case 'u':
                depth -= amount;
                break;

            default: break;
        }

        printf("%c: %d -> d: %d h: %d\n", dir, amount, depth, hpos);
    }

    printf("hpos: %d\n", hpos);
    printf("depth: %d\n", depth);
    printf("\nsolution: %d * %d = %d\n", hpos, depth, hpos*depth);

    return 0;
}
