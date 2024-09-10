#ifndef __LEX_H__
#define __LEX_H__

#include <string>
#include "utils.h"


enum class Token{
    TOK_NONE = -1,

    TOK_KEYWORD,
    TOK_OPERATOR,
    
    TOK_IDENTIFIER,
    TOK_INT_LITERAL,
    TOK_FLOAT_LITERAL,
    TOK_CHAR_LITERAL,
    TOK_STRING_LITERAL,

      // Punctuation
    TOK_LEFT_PAREN,   // (
    TOK_RIGHT_PAREN,  // )
    TOK_LEFT_BRACE,   // {
    TOK_RIGHT_BRACE,  // }
    TOK_SEMICOLON,    // ;
    TOK_COMMA,        // ,

    TOK_EOF
};
class Lexer{
public:
    Lexer(std::string& srcStr);
    Token gettok();
    int getIntVal();
    double getFloatVal();
    std::string getIdentifierStr();
    KeyWord getKeyWord();
    Operator getOperator();

private:
    char nextChar();
    KeyWord checkKeyWord();
    Operator checkOperator();


private:
    std::string IdentifierStr;

    KeyWord keyword;
    Operator optr;
    int intVal;
    float floatVal;

    std::string& srcStr;
    int idx;
    char LastChar;

};



#endif // __LEX_H__