#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover cardfilename\n");
        return 1;
    }

    char *infile = argv[1];
    FILE *card = fopen(infile, "r");

    if (card == NULL)
    {
        printf("Could not open the %s\n", infile);
        return 1;
    }

    int filecount = 0;
    uint8_t dat[512];
    char namef[8];
    FILE *output;

    while (fread(&dat, sizeof(uint8_t), 512, card) == 512)
    {
        if (dat[0] == 0xff &&  dat[1] == 0xd8 && dat[2] == 0xff && (dat[3] & 0xf0) == 0xe0)
        {
            if (filecount == 0)
            {
                sprintf(namef, "%03i.jpg", filecount);
                output = fopen(namef, "w");
                (fwrite(&dat, sizeof(uint8_t), 512, output));
            }

            else if (filecount > 0)
            {
                fclose(output);
                sprintf(namef, "%03i.jpg", filecount);
                output = fopen(namef, "w");
                (fwrite(&dat, sizeof(uint8_t), 512, output));
            }

            filecount++;
        }

        else if (filecount > 0)
        {
            (fwrite(&dat, sizeof(uint8_t), 512, output));
        }
    }

    fclose(output);
    fclose(card);
}
