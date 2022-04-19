/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "compiler.h"
#include "parser.h"

int i = 0;                                                          //creates i as a global variable for all functions

void setEqual(Instruction instruction){                             //MOV function
    printf("MOV R%d, #%s\n" , i, instruction.tokens[2]);            //prints MOV and sets given register to number
    i++;                                                            //i++
}

int j = 0;                                                          //creates j and k
int k = 0;

void setAdd(Instruction instruction){                               //ADD function
    j = i- 1;                                                       //j and k made to hold prev registers
    k = i - 2;
    
    if(atoi(instruction.tokens[4]) != 0){                           //if not equal 0 its a number
        printf("MOV R%d, #%s\n", i, instruction.tokens[4]);         //prints the number to a register 
        i++;                                                        //i++
        int m = i;                                                  //m and n represent prev registors
        m--;
        int n = i;
        n = n - 2;
        printf("ADD R%d, R%d, R%d\n", i, m, n);                     //add register plus the register with number
        i++;                                                        //i++
    }
    else{                                                           //if eq has not add with number
        printf("ADD R%d, R%d, R%d\n", i, j, k);                     //prints add with registers and adding them
        int l = i;                                                  //l hold prev i for register
        i++;
        printf("MOV R%d, R%d\n", i, l);                             //sets the addition register
    }
    i++;                                                            //i++
}

void setSub(Instruction instruction){                               //SUB function
    j = i- 1;                                                       //j and k to hold prev registers
    k = i - 3;
    
    if(atoi(instruction.tokens[4]) != 0){                           //if 4th token is a number goes through loop
        printf("MOV R%d, #%s\n", i, instruction.tokens[4]);         //prints MOV to set a register to number
        i++;                                                        //i++
        int o = i;                                                  //create o and p to hold prev registers
        o--;
        int p = i;
        p = p - 2;
        printf("SUB R%d, R%d, R%d\n", i, o, p);                     //prints SUB from register with number and standered register
        i++;                                                        //i++
    }
    else{                                                           //runs if SUB doesnt have a number
        printf("SUB R%d, R%d, R%d\n", i, j, k);                     //prints SUB with registers
        int l = i;                                                  //l holds prev registers
        i++;                                                        //i++
        printf("MOV R%d, R%d\n", i, l);                             //prints the MOV to the subtracted registers
    }
    i++;                                                            //i++
}