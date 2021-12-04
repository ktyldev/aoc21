#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* INPUT_FILENAME = "input";
const int BUF_SIZE = 16;

int main()
{
    FILE* fp;
    char buf[BUF_SIZE];

    int epsilon = 0;
    int gamma = 0;

    // open input file
    fp = fopen(INPUT_FILENAME, "r");

    // figure out how many columns we're dealing with
    int cols = 0;
    // read in first line
    fscanf(fp, "%s", buf);
    cols = strlen(buf);

    char result[cols];

    // calculate gamma and epsilon rates
    for (int i=0; i<cols; i++)
    {
        // reset pointer to start of file
        fseek(fp, 0, SEEK_SET);

        int ones = 0;
        int zeroes = 0;

        while (1)
        {
            fscanf(fp, "%s", buf);

            if (feof(fp)) break;

            switch (buf[i])
            {
                case '0':
                    zeroes++;
                    break;
                case '1':
                    ones++;
                    break;

                default: break;
            }
        }
        
        // shift everything left
        gamma <<= 1;
        epsilon <<= 1;

        if (ones > zeroes)
        {
            gamma++;
        }
        else
        {
            epsilon++;
        }
    }

    printf("%d\n", gamma);
    printf("%d\n", epsilon);

    printf("power rate: %d * %d = %d\n", gamma, epsilon, gamma*epsilon);

    return 0;
}
