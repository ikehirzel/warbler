#ifndef TOKEN_H
#define TOKEN_H

#include <grackle/data/string.h>

enum TokenType
{
	// Generic
	TOK_EOF,
	TOK_ERROR,
	TOK_IDENTIFIER,

	// Separators
	TOK_LPAREN,
	TOK_RPAREN,
	TOK_LBRACK,
	TOK_RBRACK,
	TOK_LBRACE,
	TOK_RBRACE,
	TOK_LANGBRACK,
	TOK_RANGBRACK,
	TOK_SEMICOLON,
	TOK_COLON,

	// Dot based
	TOK_DOT,		// 1 dot
	TOK_RANGE,		// 2 dots
	TOK_ELIPSIS,	// 3 dots

	// Bitwise
	TOK_AMPERSAND,
	TOK_PIPELINE,
	TOK_CARROT,

	// Boolean
	TOK_EXCLAMATION,
	TOK_AND_LOGICAL,
	TOK_OR_LOGICAL,
	TOK_EQ_LOGICAL,
	TOK_NEQ_LOGICAL,

	// Operators	===========================

	// Arrows
	TOK_SINGLE_ARROW,
	TOK_DOUBLE_ARROW,

	// Assignment
	TOK_ASSIGN,
	TOK_ADD_ASSIGN,
	TOK_MIN_ASSIGN,
	TOK_MUL_ASSIGN,
	TOK_DIV_ASSIGN,
	TOK_MOD_ASSIGN,

	// Arithmetic
	TOK_MODULUS,
	TOK_SLASH,
	TOK_ASTERISK,
	TOK_PLUS,
	TOK_MINUS,
	TOK_SQRT,
	TOK_INCREMENT,
	TOK_DECREMENT,

	// Literals
	TOK_INT_LITERAL,
	TOK_FLOAT_LITERAL,
	TOK_HEX_LITERAL,	// todo
	TOK_BIN_LITERAL,	// todo
	TOK_OCT_LITERAL,	// todo
	TOK_CHAR_LITERAL,
	TOK_STR_LITERAL,

	// Typenames
	TOK_VAR,
	TOK_FUNC,

	// Integer types
	TOK_TYPE_I8,
	TOK_TYPE_I16,
	TOK_TYPE_I32,
	TOK_TYPE_I64,
	TOK_TYPE_U8,
	TOK_TYPE_U16,
	TOK_TYPE_U32,
	TOK_TYPE_U64,
	TOK_TYPE_F32,
	TOK_TYPE_F64,
	TOK_TYPE_STR,

	// Keywords
	TOK_RETURN,
	TOK_FOR,

	// last
	TOK_COUNT
};

typedef struct token
{
	string_t str;
	short type;
	unsigned line;
	unsigned short col;
} token_t;

extern token_t token_create();

#endif