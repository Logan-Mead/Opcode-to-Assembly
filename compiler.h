/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   compiler.h
 * Author: loganmead
 *
 * Created on March 20, 2021, 5:39 PM
 */

#ifndef COMPILER_H
#define COMPILER_H

#include "parser.h"

#ifdef __cplusplus
extern "C" {
#endif
void setEqual(Instruction instruction);                     //header for MOV
void setAdd(Instruction instruction);                       //header for ADD
void setSub(Instruction instruction);                       //header for SUB


#ifdef __cplusplus
}
#endif

#endif /* COMPILER_H */

