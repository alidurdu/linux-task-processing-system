#include <string.h>
#include <stdio.h>
#include <stdbool.h>

/*
    Function prototypes
*/

bool isPrime(int n);

bool isFibonacci(int n);

bool isSquareNumber(int n);

bool isCubeNumber(int n);

bool isPerfectNumber(int n);

bool isAbundantNumber(int n);

bool isDeficientNumber(int n);

bool isOdd(int n);


/*
    Metadata structure
*/
#pragma pack(push,1)


typedef struct {

    int number;

    int fibonacci;

    int prime;

    int square;

    int cube;

    int perfect;

    int abundant;

    int deficient;

    int odd;

    int even;

} TASK2_METADATA;

#pragma pack(pop)

int main() {


    FILE *inputFile;

    FILE *outputFile;

    int number;

    TASK2_METADATA data;
	
	printf("Struct size: %lu\n", sizeof(TASK2_METADATA));


    /*
        Open input file
    */

    inputFile = fopen("txt_file.txt", "r");

    if(inputFile == NULL) {

        printf("Could not open input file\n");

        return 1;
    }


    /*
        Create binary output file
    */

    outputFile = fopen("pgexam26_output.bin", "wb");

    if(outputFile == NULL) {

        printf("Could not create output file\n");

        fclose(inputFile);

        return 1;
    }


    printf("Reading numbers...\n\n");


    /*
        Read all numbers from file
    */

    while(fscanf(inputFile, "%d", &number) == 1) {

		memset(&data, 0, sizeof(TASK2_METADATA));
        data.number = number;


        /*
            Call helper functions
        */

		data.fibonacci = isFibonacci(number) ? 1 : 0;

		data.prime = isPrime(number) ? 1 : 0;

		data.square = isSquareNumber(number) ? 1 : 0;

		data.cube = isCubeNumber(number) ? 1 : 0;

		data.perfect = isPerfectNumber(number) ? 1 : 0;

		data.abundant = isAbundantNumber(number) ? 1 : 0;

		data.deficient = isDeficientNumber(number) ? 1 : 0;

		data.odd = isOdd(number) ? 1 : 0;

		data.even = isOdd(number) ? 0 : 1;


        /*
            Write struct to binary file
        */

        fwrite(&data, sizeof(TASK2_METADATA), 1, outputFile);


        /*
            Print result
        */

        printf("Number: %d\n", data.number);

        printf("Prime: %d\n", data.prime);

        printf("Fibonacci: %d\n", data.fibonacci);

        printf("Square: %d\n", data.square);

        printf("Cube: %d\n", data.cube);

        printf("Perfect: %d\n", data.perfect);

        printf("Abundant: %d\n", data.abundant);

        printf("Deficient: %d\n", data.deficient);

        printf("Odd: %d\n", data.odd);

        printf("--------------------------\n");
    }


    /*
        Close files
    */

    fclose(inputFile);

    fclose(outputFile);


    printf("Binary output file created successfully\n");

    return 0;
}