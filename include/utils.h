#pragma once

#define TOTAL_KEYWORDS 36
#define TOTAL_OPERATORS 44
enum class KeyWord{
    KW_NONE = -1,
    KW_AUTO,
    KW_BREAK,
    KW_CASE,
    KW_CHAR,
    KW_CONST,
    KW_CONTINUE,
    KW_DEFAULT,
    KW_DO,
    KW_DOUBLE,
    KW_ELSE,
    KW_ENUM,
    KW_EXTERN,
    KW_FLOAT,
    KW_FOR,
    KW_GOTO,
    KW_IF,
    KW_INLINE,
    KW_INT,
    KW_LONG,
    KW_REGISTER,
    KW_RESTRICT,
    KW_RETURN,
    KW_SHORT,
    KW_SIGNED,
    KW_SIZEOF,
    KW_STATIC,
    KW_STRUCT,
    KW_SWITCH,
    KW_TYPEDEF,
    KW_TYPEOF,
    KW_TYPEOF_UNQUAL,
    KW_UNION,
    KW_UNSIGNED,
    KW_VOID,
    KW_VOLATILE,
    KW_WHILE
};

static char* keywordstr[] = {
    "auto",
    "break",
    "case",
    "char",
    "const",
    "continue",
    "default",
    "do",
    "double",
    "else",
    "enum",
    "extern",
    "float",
    "for",
    "goto",
    "if",
    "inline",
    "int",
    "long",
    "register",
    "restrict",
    "return,",
    "short",
    "signed",
    "sizeof",
    "static",
    "struct",
    "switch",
    "typedef",
    "typeof",
    "typeof_unqual",
    "union",
    "unsigned",
    "void",
    "volatile",
    "while"
};

enum class Operator{
    OP_NONE = -1,
    // Arithmetic Operators
    OP_PLUS,             // +
    OP_MINUS,            // -
    OP_MULTIPLY,         // *
    OP_DIVIDE,           // /
    OP_MODULO,           // %

    // Relational (Comparison) Operators
    OP_EQUAL_TO,         // ==
    OP_NOT_EQUAL,        // !=
    OP_LESS_THAN,        // <
    OP_GREATER_THAN,     // >
    OP_LESS_EQUAL,       // <=
    OP_GREATER_EQUAL,    // >=

    // Logical Operators
    OP_LOGICAL_AND,      // &&
    OP_LOGICAL_OR,       // ||
    OP_LOGICAL_NOT,      // !

    // Bitwise Operators
    OP_BITWISE_AND,      // &
    OP_BITWISE_OR,       // |
    OP_BITWISE_XOR,      // ^
    OP_BITWISE_NOT,      // ~
    OP_LEFT_SHIFT,       // <<
    OP_RIGHT_SHIFT,      // >>

    // Assignment Operators
    OP_ASSIGN,           // =
    OP_ADD_ASSIGN,       // +=
    OP_SUB_ASSIGN,       // -=
    OP_MUL_ASSIGN,       // *=
    OP_DIV_ASSIGN,       // /=
    OP_MOD_ASSIGN,       // %=
    OP_AND_ASSIGN,       // &=
    OP_OR_ASSIGN,        // |=
    OP_XOR_ASSIGN,       // ^=
    OP_LEFT_SHIFT_ASSIGN,// <<=
    OP_RIGHT_SHIFT_ASSIGN,// >>=

    // Unary Operators
    OP_INCREMENT,        // ++
    OP_DECREMENT,        // --
    OP_UNARY_PLUS,       // +
    OP_UNARY_MINUS,      // -
    OP_ADDRESS_OF,       // &
    OP_DEREFERENCE,      // *

    // Ternary Operator
    OP_CONDITIONAL,      // ? :

    // Pointer Operators
    OP_POINTER,          // *
    OP_ADDRESS,          // &

    // Sizeof Operator
    OP_SIZEOF,           // sizeof


    // Member Access Operators
    OP_DOT,              // .
    OP_ARROW,            // ->

    // Type Cast Operator
    OP_CAST              // (type)
};

static char* operatorstr[] = {
     // Arithmetic Operators
    "+",    // OP_PLUS
    "-",    // OP_MINUS
    "*",    // OP_MULTIPLY
    "/",    // OP_DIVIDE
    "%",    // OP_MODULO

    // Relational (Comparison) Operators
    "==",   // OP_EQUAL_TO
    "!=",   // OP_NOT_EQUAL
    "<",    // OP_LESS_THAN
    ">",    // OP_GREATER_THAN
    "<=",   // OP_LESS_EQUAL
    ">=",   // OP_GREATER_EQUAL

    // Logical Operators
    "&&",   // OP_LOGICAL_AND
    "||",   // OP_LOGICAL_OR
    "!",    // OP_LOGICAL_NOT

    // Bitwise Operators
    "&",    // OP_BITWISE_AND
    "|",    // OP_BITWISE_OR
    "^",    // OP_BITWISE_XOR
    "~",    // OP_BITWISE_NOT
    "<<",   // OP_LEFT_SHIFT
    ">>",   // OP_RIGHT_SHIFT

    // Assignment Operators
    "=",    // OP_ASSIGN
    "+=",   // OP_ADD_ASSIGN
    "-=",   // OP_SUB_ASSIGN
    "*=",   // OP_MUL_ASSIGN
    "/=",   // OP_DIV_ASSIGN
    "%=",   // OP_MOD_ASSIGN
    "&=",   // OP_AND_ASSIGN
    "|=",   // OP_OR_ASSIGN
    "^=",   // OP_XOR_ASSIGN
    "<<=",  // OP_LEFT_SHIFT_ASSIGN
    ">>=",  // OP_RIGHT_SHIFT_ASSIGN

    // Unary Operators
    "++",   // OP_INCREMENT
    "--",   // OP_DECREMENT
    "+",    // OP_UNARY_PLUS
    "-",    // OP_UNARY_MINUS
    "&",    // OP_ADDRESS_OF
    "*",    // OP_DEREFERENCE

    // Ternary Operator
    "?",    // OP_CONDITIONAL

    // Pointer Operators
    "*",    // OP_POINTER
    "&",    // OP_ADDRESS

    // Sizeof Operator
    "sizeof", // OP_SIZEOF


    // Member Access Operators
    ".",    // OP_DOT
    "->",   // OP_ARROW

    // Type Cast Operator
    "(type)" // OP_CAST
};