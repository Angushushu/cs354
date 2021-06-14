/////////////////////////////////////////////////////////////////////////////////
// Main File:        check_queens.c
// This File:        check_queens.c
// Other Files:      
// Semester:         CS 354 SPRING 2019
//           
// Author:           Shu Hu
// Email:            shu94@wisc.edu
// CS Login:         shuh
//           
/////////////////////////// OTHER SOURCES OF HELP //////////////////////////////
//                   fully acknowledge and credit all sources of help,
//                   other than Instructors and TAs.
//           
// Persons:          Shu Hu, shu94@wisc.edu
//           
// Online sources:   avoid web searches to solve your problems, but if you do
//                   search, be sure to include Web URLs and description of 
//                   of any information you find.
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h> 
#include <stdlib.h>  
#include <string.h>   
 
//declare a constant COMMA for breaking elts in strings
char *COMMA = ",";
  
/* COMPLETED:
 * Retrieves from the first line of the input file,
 * the number of rows and columns for the board.
 * 
 * fp: file pointer for input file
 * rows: pointer to number of rows
 * cols: pointer to number of columns
 */
void get_dimensions(FILE *fp, int *rows, int *cols) {  
        //declare a pointer line store each line of the board
	char *line = NULL;  
        //declare a var that store length of each line
	size_t len = 0;  
        if (getline(&line, &len, fp) == -1) {  
                printf("Error in reading the file\n");  
                exit(1);  
        }  
        //declare a pointer store token   
        char *token = NULL; 
        token = strtok(line, COMMA);
        *rows = atoi(token); 
           
        token = strtok(NULL, COMMA); 
        *cols = atoi(token);
}      


/* TODO:
 * Returns 1 if and only if there exists at least one pair
 * of queens that can attack each other.
 * Otherwise returns 0.
 * 
 * board: heap allocated 2D board
 * rows: number of rows
 * cols: number of columns
 */
int check_queens(int **board, int rows, int cols) {  
	//find a queen first
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			if(*(*(board+i)+j)==1){
				//check col
				for(int i2=i+1; i2<rows; i2++){
					if(*(*(board+i2)+j)==1) return 1;
				}
				//check row
				for(int j2=j+1; j2<cols; j2++){				
					if(*(*(board+i)+j2)==1) return 1;
				}
				//check diagnals
				int j2 = j+1;
				int j3 = j-1;
				for(int i2=i+1; i2<rows; i2++){
					if(j2<cols){
						if(*(*(board+i2)+j2)==1) return 1;
					}
					if(j3>=0){
						if(*(*(board+i2)+j3)==1) return 1;
					}
					j2++;
					j3--;
				}
			}
		}
	}
        return 0;
}


/* PARTIALLY COMPLETED:
 * This program prints true if the input file has any pair
 * of queens that can attack each other, and false otherwise
 * 
 * argc: CLA count
 * argv: 2D array that stores CLA value 
 */
int main(int argc, char *argv[]) {        

        //TODO: Check if number of command-line arguments is correct.
        if(argc!=2){
		fprintf(stderr, "Usage: ./check_queens <input_filename>\n");
		exit(1);
	}
        //Open the file and check if it opened successfully.
        FILE *fp = fopen(*(argv + 1), "r");
        if (fp == NULL) {
                printf("Cannot open file for reading\n");
                exit(1);
        }


        //Declare local variables: int var that count # of rows and cols
        int rows, cols;


        //TODO: Call get_dimensions to retrieve the board dimensions.
	get_dimensions(fp, &rows, &cols);

        //TODO: Dynamically allocate a 2D array of dimensions retrieved above.
        //declare and locate a 2D array in heap
	int **board = malloc(sizeof(int*)*rows);
	if(board==NULL){
		printf("Memory allocation error\n");
		exit(1);
	}
	for(int i=0; i<rows; i++){
		*(board+i) = malloc(sizeof(int)*cols);
		if(*(board+i)==NULL){
			printf("Memory allocation error\n");
			exit(1);
		}
	}

        //Read the file line by line.
        //Tokenize each line wrt comma to store the values in your 2D array.
        //declare a pointer that store each line of token
	char *line = NULL;
	//declare a var that store length of each line
        size_t len = 0;
	//declare a pointer of char store the strings of each line
        char *token = NULL;
        for (int i = 0; i < rows; i++) {

                if (getline(&line, &len, fp) == -1) {
                        printf("Error while reading the file\n");
                        exit(1);        
                }

                token = strtok(line, COMMA);
                for (int j = 0; j < cols; j++) {
                        //TODO: Complete the line of code below
                        //to initialize your 2D array.
                        /* ADD ARRAY ACCESS CODE HERE */
			*(*(board+i)+j) = atoi(token);
                        token = strtok(NULL, COMMA);    
                }
        }

        //TODO: Call the function check_queens and print the appropriate
        //output depending on the function's return value.
        if(check_queens(board, rows, cols)) printf("true\n");
	else printf("false\n");
        
        //TODO: Free all dynamically allocated memory.
	for(int i=0; i<rows; i++) free(*(board+i));
	free(board);

        //Close the file.
        if (fclose(fp) != 0) {
                printf("Error while closing the file\n");
                exit(1);        
        }

	return 0;
}
