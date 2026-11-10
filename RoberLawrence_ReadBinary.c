//
// Yony Rober - Working on the read file
// Ethan Lawrence - Working on the write file
// Cmpsc 472 - Fall 2026
// Reads binary records created by the Ethan's
// program and displays all stored information.
//

#include <stdio.h>
#include <stdlib.h>

#include "LawrenceRober_BinaryIO.h"

int main(void)
{
    FILE *file;
    struct someFileData record;
    int count = 0;

    /* Replace with the filename defined for your project */
    const char *filename = "RoberLawrence_Data.bin";

    /* Open file in binary read mode */
    file = fopen(filename, "rb");

    if (file == NULL)
    {
        printf("ERROR: Could not open binary file.\n");
        printf("File: %s\n", filename);
        return 1;
    }

    printf("========================================\n");
    printf("         BINARY FILE READER\n");
    printf("========================================\n");
    printf("Reading file: %s\n\n", filename);

    /* Read one complete record at a time */
    while (fread(&record, sizeof(record), 1, file) == 1)
    {
        count++;

        printf("------------- Record %d -------------\n",
               count);

        printf("Integer : %d\n", record.myInt);
        printf("Float   : %.2f\n", record.myFloat);
        printf("Double  : %.4f\n", record.myDouble);
        printf("Boolean : %s\n",
               record.myBool ? "True" : "False");
        printf("Text    : %.50s\n", record.myChar);

        printf("----------------------------------------\n\n");
    }

    /* Check for file-reading errors */
    if (ferror(file))
    {
        printf("ERROR: Problem reading binary file.\n");
        fclose(file);
        return 1;
    }

    /* Close the file */
    fclose(file);

    printf("========================================\n");
    printf("Total Records Read: %d\n", count);
    printf("File closed successfully.\n");
    printf("========================================\n");

    if (count != 5)
    {
        printf("WARNING: Expected 5 records, found %d.\n",
               count);
    }

    return 0;
}
