///////////////////////////////////////////////////////////////////////////////
// Main File:	decode.c
// This File:	decode.c
// Other Files:	ciphertext.txt
// Semester:	CS 354 Spring 2019
//
// Author:	Shu Hu
// Email:	shu94@wisc.edu
// CS Login:	shuh
//
// //////////////////// OTHER SOURCES OF HELP /////////////////////////////////
// 
// Persons:	none
// Online sources: none
//
// /////////////////// 80 columns wide ////////////////////////////////////////


/*
 * This program decodes ciphertexts using the Caesar cipher technique.
 * Left shifts are used to encode the message and right shifts are used to
 * decode the ciphertext. 
 * The ciphertext is read from a file named "ciphertext.txt" that should be
 * present in the current working directory.
 * The number of right shifts required to decode the message is calculated
 * using a (not so) secret key, the CS login of the intended recipient.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * read_cipher_file();
char * get_login_key();
char * decode(char *ciphertext, char *key);
int    calculate_shifts(char *key);

int main(int argc, char *argv[]) {      

    // Read cipher-text from cipher file
    // ciphertext is used to store the undecoded text
    char *ciphertext = read_cipher_file();
    printf("Ciphertext:\n%s\n", ciphertext);

    // Prompt user for CS login
    // This is used to determine the shifts needed for decoding
    char * key = get_login_key();

    // Decode the ciphertext using the Caesar cipher technique
    char * plaintext = decode(ciphertext, key);

    // Print out the plain-text
    printf("Plaintext:\n%s\n", plaintext);

    return 0;
}

/*
 * Reads the first line of the file named "ciphertext.txt" and returns
 * it as a string
 * 
 * no parameter
 * return a char pointer variable
 */
char * read_cipher_file() {      

    // Open the ciphertext file for reading
    FILE *fp;
    fp = fopen("ciphertext.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open file for reading.\n");
        exit(1);
    }
    // char type pointer variable
    char *str = malloc(1000);
    // Read the first and only line in the file as ciphertext
    if (fgets(str, 1000, fp) == NULL) {
        fprintf(stderr, "Error reading ciphertext file.\n");
        exit(1);
    }
    // int variable
    int len = strlen(str);
    // Replace the trailing newline with a null character
    if (str[len - 1] == '\n') str[len - 1] = '\0';

    return str;
}

/* Prompt the user for their CS loging and return it as a string
 * no parameter
 * return a char pointer variable
 */
char * get_login_key() {      

    // Prompt the user for their CS login
    char *str = malloc(50);
    printf("Enter your CS login: ");
    if (fgets (str, 50, stdin) == NULL) {
        fprintf(stderr, "Error reading user input.\n");
        exit(1);
    }
    // int variable used to store length of string
    int len = strlen(str);
    // Replace the trailing newline with a null character
    if (str[len - 1] == '\n') str[len - 1] = '\0';

    return str;
}

/* Decodes the ciphertext to plaintext.
 * ciphertext, a char pointer variable that used to access the text to be decode
 * key, a char pointer variable that used to account how many shifts are needed
 * return a char pointer variable 
 */
char * decode(char *ciphertext, char *key) {      

    // int variable used to calculate the number of shifts needed to decode the message from the key
    int shifts = calculate_shifts(key);

    // p is a char type pointer variable used to store text from ciphertext
    // Decode by right shifting every alphabet in the ciphertext
    char *p = ciphertext;
    for ( ; *p != '\0'; ++p) {
        //Skip decoding anything other than lowercase alphabets(a-z)
        if (*p < 'a' || *p > 'z') continue;

        // Ascii number for 'a' => 97
        int curr_index = *p - 'a';
        // The lower case alphabet(a-z) is indexed from 0-25
        // We do a circular right shift by the required number of shifts
        int new_index = (curr_index + shifts) % 26;
        // Convert the index back to the ascii code for the decoded letter
        *p = new_index + 'a';
    }

    return ciphertext;
}

/* Calculates and returns the number of shifts(1-25) needed in the Caesar cipher
 * by taking the bitwise XOR of every character in the CS login key string
 * key, a char pointer variable, used to know how many shifts are needed
 * return an int value
 */
int calculate_shifts(char * key) {      
    // char type pointer variable tells how many shifts are needed
    char *p = key;
    // int variable used to store number of shifts needed
    int shifts = 0;
    // using p to calculate number of shifts needed and store in shifts
    for ( ; *p != '\0'; ++p) shifts = shifts ^ *p; 
    shifts = abs(shifts % 26);
    if (shifts == 0) shifts = 1;
    return shifts;
}
