/**
 * @file scanner.h
 * @author M.H. Gholamrezei (gholamrezaei.mh@gmail.com)
 * @brief Script Engine Scanner
 * @details
 * @version 0.1
 * @date 2020-10-22
 *
 * @copyright This project is released under the GNU Public License v3.
 *
 */
#ifndef SCANNER_H
#define SCANNER_H
#include <stdio.h>

/**
* @brief maximum length of string in the token
*/
#define TOKEN_VALUE_MAX_LEN 100

/**
* @brief init size of token list
*/
#define TOKEN_LIST_INIT_SIZE 16

/**
* @brief enumerates possible types for token 
*/
typedef enum TOKEN_TYPE
{
	ID,
	DECIMAL,
	HEX,
	OCTAL,
	BINARY,
	SPECIAL_TOKEN,
	KEYWORD,
	WHITE_SPACE,
	COMMENT,
	REGISTER,
	PSEUDO_REGISTER,
	NON_TERMINAL,
	SEMANTIC_RULE,
	END_OF_STACK,
	EPSILON,
	TEMP,
	UNKNOWN
} TOKEN_TYPE;

/**
* @brief read tokens from input stored in this structure
*/
struct _TOKEN
{
	TOKEN_TYPE Type;
	char* Value;
};


/**
* @brief Pointer to _TOKEN structure 
*/
typedef struct _TOKEN* TOKEN;

/**
* @brief this structure is a dynamic containter of TOKENS
*/
typedef struct _TOKEN_LIST
{
	TOKEN* Head;
	unsigned int Pointer;
	unsigned int Size;
} *TOKEN_LIST;

/**
* @brief number of read characters from input
*/
unsigned int InputIdx;

/**
* @ brief When this variable is '1', we wait for a ID TOKEN. otherwise, we 
*	will wait for keyword. It is because ID can be lvalue only.
*/
unsigned char WaitForID;

////////////////////////////////////////////////////
// TOKEN related functions						  // 
////////////////////////////////////////////////////
TOKEN NewToken(void); 

void RemoveToken(TOKEN Token);

void PrintToken(TOKEN Token);

void Append(TOKEN Token, char c);


////////////////////////////////////////////////////
// TOKEN_LIST related functions					  // 
////////////////////////////////////////////////////
TOKEN_LIST NewTokenList(void);

void RemoveTokenList(TOKEN_LIST TokenList);

void PrintTokenList(TOKEN_LIST TokenList);

TOKEN_LIST Push(TOKEN_LIST TokenList, TOKEN Token);

TOKEN Pop(TOKEN_LIST TokenList);

TOKEN Top(TOKEN_LIST TokenList);


////////////////////////////////////////////////////
// Util Functions								  // 
////////////////////////////////////////////////////
char IsHex(char c);

char IsDecimal(char c);

char IsLetter(char c);

char IsBinary(char c);

char IsOctal(char c);


////////////////////////////////////////////////////
// Interfacing functions						  // 
////////////////////////////////////////////////////
TOKEN GetToken(char* c, char* str);

TOKEN Scan(char* str, char* c);

char sgetc(char* str);


#endif