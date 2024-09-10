#include <iostream>

#include <fstream>
#include <string>

#include "lex.h"
#include "utils.h"

void ProcessToken(Lexer& lex, Token tok);

int main(int argc, char* argv[]){
    std::ifstream srcFile;

    if(argc > 1){
        srcFile.open(argv[1]);
    }else{
        std::cerr << "Source file path not provided" << std::endl;
        return 1;
    }

    std::string srcStr;
    if(srcFile.is_open()){
        while(srcFile){
            srcStr += srcFile.get();
        }
    }else{
        std::cerr << "Enable to open source file" << std::endl;
        return 1;
    }

    Lexer lex(srcStr);
    Token currtok = lex.gettok();
    ProcessToken(lex, currtok);
    while(currtok != Token::TOK_EOF){
        currtok = lex.gettok();
        ProcessToken(lex, currtok);
    }
    return 0;
}

void ProcessToken(Lexer& lex, Token tok){
    switch (tok)
    {
    case Token::TOK_IDENTIFIER:
        std::cout << "TOK_IDENTIFIER : " << lex.getIdentifierStr() << std::endl;
        break;
    case Token::TOK_KEYWORD:
        std::cout << "TOK_KEYWORD : " << keywordstr[(int)lex.getKeyWord()] << std::endl;
        break;
    case Token::TOK_INT_LITERAL:
        std::cout << "TOK_INT_LITERAL : " << lex.getIntVal() << std::endl;
        break;
    case Token::TOK_FLOAT_LITERAL:
        std::cout << "TOK_FLOAT_LITERAL : " << lex.getFloatVal() << std::endl;
        break;
    case Token::TOK_OPERATOR:
        std::cout << "TOK_OPERATOR : " << operatorstr[(int)lex.getOperator()] << std::endl;
        break;
    case Token::TOK_LEFT_BRACE:
        std::cout << "TOK_LEFT_BRACE" << std::endl;
        break;
    case Token::TOK_RIGHT_BRACE:
        std::cout << "TOK_RIGHT_BRACE" << std::endl;
        break;
    case Token::TOK_LEFT_PAREN:
        std::cout << "TOK_LEFT_PAREN" << std::endl;
        break;
    case Token::TOK_RIGHT_PAREN:
        std::cout << "TOK_RIGHT_PAREN" << std::endl;
        break;
    case Token::TOK_SEMICOLON:
        std::cout << "TOK_SEMICOLON" << std::endl;
        break;
    case Token::TOK_COMMA:
        std::cout << "TOK_COMMA" << std::endl;
        break;
    case Token::TOK_NONE:
        std::cout << "TOK_NONE : " << lex.getIdentifierStr() << std::endl;
        break;
    case Token::TOK_EOF:
        std::cout << "TOK_EOF" << std::endl; 
        break; 
    default:
        break;
    }

}
