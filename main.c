#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "compiler.h"

#define MAX_LIMIT 30

//Function Prototypes
void clean(Instruction instruction);
void printInstruction(Instruction instruction);


int main() {
    int i = 0;
    
    char filename[64];
    printf("Enter Source File Name: ");
    scanf("%s", filename );
    
    FILE* f = fopen(filename, "r");
    if (f == NULL){
        printf("ERROR opening file: %s!\n", filename);
        return EXIT_FAILURE;
    }
    
    int lineNumber = 1;
    char* str = readLine(f);
    while( str != NULL ){
        
        // Instruction string converted to Instruction Structure
        Instruction instruction = parseInstructionString(str);
        
        // Check if instruction is a valid MUCKS instruction
        bool isValid = isValidInstruction(instruction);    
        if (isValid == false){
            fprintf(stderr, "COMPILE ERROR: Line #%d, %s \n", lineNumber, str);
            return EXIT_FAILURE;
        }
        
		 // For each Instruction Structure, print each instruction tokens 
		 // to the screen.  You'll want to remove this, but it's included 
		 // in the template to demonstrate the functionality of the provided
		 // code template.
         //printf("Instruction #%d:\n", lineNumber);
		 //printInstruction(instruction);
                 
        if(instruction.numTokens >= 4){                                      //error checking to see if instruction has more than 4 tokens
            if(strcmp(instruction.tokens[3],"+") == 0){                      //if 3rd token is + run ADD function
                setAdd(instruction);         
            }
            else if(strcmp(instruction.tokens[3],"-") == 0){                //else if 3rd token is - run SUB function
                setSub(instruction);
            }
        }    
        else if(strcmp(instruction.tokens[1],"=") == 0){                    //else run MOV function
            setEqual(instruction);
        }
        
        lineNumber++;
        str = readLine(f); // Get Next Line from file
        clean(instruction); // Free Heap Memory used for instruction
        //setEqual(instruction);
    }
    
    fclose(f);
    
    return (EXIT_SUCCESS);
}

/* Print Instruction Tokens */ 
void printInstruction(Instruction instruction){
	for(int i=0;i<instruction.numTokens;i++){
		printf("  token[%d]: %s\n", i, instruction.tokens[i]);
	}
}


/* Frees memory allocated on the heap */
void clean(Instruction instruction){
    //Clean Up Heap Memory
    for(int i=0;i<instruction.numTokens;i++){
        free(instruction.tokens[i]);
    }
    free( instruction.tokens );
}
