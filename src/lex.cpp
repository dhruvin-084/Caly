#include "lex.h"
#include <stdlib.h>

Lexer::Lexer(std::string& srcStr): srcStr{srcStr}, idx{0}, LastChar{' '} {}

Token Lexer::gettok(){
    while(isspace(LastChar))
        LastChar = nextChar();
    
    if(LastChar == '(') {
        LastChar = nextChar(); 
        return Token::TOK_LEFT_PAREN;
    }

    if(LastChar == ')') {
        LastChar = nextChar();
        return Token::TOK_RIGHT_PAREN;
    }
    if(LastChar == '{') {
        LastChar = nextChar();
        return Token::TOK_LEFT_BRACE;
    }
    if(LastChar == '}') {
        LastChar = nextChar();
        return Token::TOK_RIGHT_BRACE;
    }
    if(LastChar == ';') {
        LastChar = nextChar();
        return Token::TOK_SEMICOLON;
    }
    if(LastChar == ',') {
        LastChar = nextChar();
        return Token::TOK_COMMA;
    }

    
    if(isalpha(LastChar)){
        IdentifierStr = LastChar;

        while(isalnum(LastChar = nextChar()))
            IdentifierStr += LastChar;
        
        KeyWord kw = checkKeyWord();
        if(kw != KeyWord::KW_NONE) {
            keyword = kw;
            return Token::TOK_KEYWORD;
        }

        return Token::TOK_IDENTIFIER;
    }

    if(isdigit(LastChar)){
        std::string numStr;
        do{
            numStr += LastChar;
            LastChar = nextChar();
        }while(isdigit(LastChar));
        if(LastChar == '.'){
            do{
                numStr += LastChar;
                LastChar = nextChar();
            }while(isdigit(LastChar));
            floatVal = strtof(numStr.c_str(), NULL);

            return Token::TOK_FLOAT_LITERAL;
        }else{
            intVal = atoi(numStr.c_str());
            return Token::TOK_INT_LITERAL;
        }
    }

    Operator op = checkOperator();
    if(op != Operator::OP_NONE){
        optr = op;
        return Token::TOK_OPERATOR;
    }

    if(LastChar == EOF)
        return Token::TOK_EOF;

    return Token::TOK_NONE;
}

int Lexer::getIntVal(){
    return intVal;
}
double Lexer::getFloatVal(){
    return floatVal;
}
std::string Lexer::getIdentifierStr(){
    return IdentifierStr;
}
KeyWord Lexer::getKeyWord(){
    return keyword;
}
Operator Lexer::getOperator(){
    return optr;
}


char Lexer::nextChar(){
    if(idx < srcStr.length()){
        char c = srcStr[idx];
        idx++;
        return c;
    }
    return -1;
}

KeyWord Lexer::checkKeyWord(){
    for(int i = 0; i < TOTAL_KEYWORDS; i++){
        if(IdentifierStr == keywordstr[i]){
            return static_cast<KeyWord>(i);
        }
    }
    return KeyWord::KW_NONE;
}

static int isOpChar(char c){
    int res = 
        c == '+' ||
        c == '-' ||
        c == '*' ||
        c == '/' ||
        c == '%' ||
        c == '=' ||
        c == '!' ||
        c == '<' ||
        c == '>' ||
        c == '&' ||
        c == '|' ||
        c == '^' ||
        c == '~' ||
        c == '?' ||
        c == ':';
    return res;
}

Operator Lexer::checkOperator(){
    if(isOpChar(LastChar)){

        IdentifierStr = LastChar;

        while(isOpChar(LastChar = nextChar()))
            IdentifierStr += LastChar;
        
        for(int i = 0; i < TOTAL_OPERATORS; i++){
            if(IdentifierStr == operatorstr[i])
                return static_cast<Operator>(i);
        }
    }
    return Operator::OP_NONE;
}

