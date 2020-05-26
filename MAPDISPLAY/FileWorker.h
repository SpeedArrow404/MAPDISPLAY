#pragma once
#ifndef _FILEWORKER_H_
#define _FILEWORKER_H_

#include "Governer.h"
#include "headers.h"


char* StringManager(char* _oldArray,int _oldLength, int _newLenght);
char* TxtReader(char* _path);

#endif