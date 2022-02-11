#ifndef WARBLER_TOKEN_HPP
#define WARBLER_TOKEN_HPP

// local includes
#include <warbler/util/array.hpp>
#include <warbler/util/string.hpp>
#include <warbler/util/primitive.hpp>
#include <iostream>

namespace warbler
{
	enum TokenType
	{
		TOKEN_END_OF_FILE,
		TOKEN_IDENTIFIER,
		TOKEN_LPAREN,
		TOKEN_RPAREN,
		TOKEN_LBRACK,
		TOKEN_RBRACK,
		TOKEN_LBRACE,
		TOKEN_RBRACE,
		TOKEN_SEMICOLON,
		TOKEN_COLON,
		TOKEN_COMMA,
		TOKEN_DOT,
		TOKEN_ELIPSIS,
		TOKEN_AMPERSAND,
		TOKEN_PIPELINE,
		TOKEN_CARROT,
		TOKEN_LSHIFT,
		TOKEN_RSHIFT,
		TOKEN_INCREMENT,
		TOKEN_DECREMENT,
		TOKEN_BOOLEAN_NOT,
		TOKEN_BOOLEAN_AND,
		TOKEN_BOOLEAN_OR,
		TOKEN_BITWISE_NOT,
		TOKEN_BITWISE_XOR,
		TOKEN_EQUALS,
		TOKEN_NOT_EQUALS,		
		TOKEN_LESS_OR_EQUAL,
		TOKEN_GREATER_OR_EQUAL,
		TOKEN_LESS_THAN,
		TOKEN_GREATER_THAN,
		TOKEN_SINGLE_ARROW,
		TOKEN_DOUBLE_ARROW,
		TOKEN_OPTION,
		TOKEN_QUESTION,
		TOKEN_ASSIGN,
		TOKEN_BECOME_ASSIGN,
		TOKEN_ADD_ASSIGN,
		TOKEN_SUBTRACT_ASSIGN,
		TOKEN_MULTIPLY_ASSIGN,
		TOKEN_DIVIDE_ASSIGN,
		TOKEN_MODULUS_ASSIGN,
		TOKEN_LSHIFT_ASSIGN,
		TOKEN_RSHIFT_ASSIGN,
		TOKEN_BITAND_ASSIGN,
		TOKEN_BITOR_ASSIGN,
		TOKEN_BITXOR_ASSIGN,
		TOKEN_MODULUS,
		TOKEN_SLASH,
		TOKEN_ASTERISK,
		TOKEN_PLUS,
		TOKEN_MINUS,
		TOKEN_POW,
		TOKEN_INTEGER_LITERAL,
		TOKEN_FLOAT_LITERAL,
		TOKEN_HEXADECIMAL_LITERAL,
		TOKEN_BINARY_LITERAL,
		TOKEN_OCTAL_LITERAL,
		TOKEN_CHAR_LITERAL,
		TOKEN_STRING_LITERAL,
		TOKEN_TRUE,
		TOKEN_FALSE,
		TOKEN_MUT,
		TOKEN_VAR,
		TOKEN_FUNC,
		TOKEN_RETURN,
		TOKEN_FOR,
		TOKEN_WHILE,
		TOKEN_LOOP,
		TOKEN_CONTINUE,
		TOKEN_BREAK,
		TOKEN_IF,
		TOKEN_THEN,
		TOKEN_ELSE,
		TOKEN_MATCH,
		TOKEN_CASE,
		TOKEN_TYPE,
		TOKEN_STRUCT,
		TOKEN_ENUM,
		TOKEN_UNION,
		TOKEN_IMPORT,
		TOKEN_EXPORT,
		TOKEN_SCOPE,
		TOKEN_PRIVATE,
		TOKEN_PUBLIC
	};

	class Location
	{
	private:

		const char *_filename;
		const char *_src;
		usize _line;
		usize _col;
		usize _pos;
		usize _length;

	public:

		Location();
		Location(const char *filename, const char *src, usize line, usize col, usize pos, usize length);
		Location(const char *filename, const char *src);

		Location with_length(usize length) const;
		void offset(usize offset);

		const char *src() const { return _src; }
		const char *pos_ptr() const { return _src + _pos; }
		const char *start_of_line() const { return (_src + _pos) - _col; }
		const char *filename() const { return _filename; }
		usize line() const { return _line; }
		usize col() const { return _col; }
		usize pos() const { return _pos; }
		usize length() const { return _length; }

		const char *begin() const { return _src + _pos; }
		const char *end() const { return _src + _pos + _length; }

		char operator[](usize i) const { return _src[_pos + i]; }

		friend std::ostream& operator<<(std::ostream& out, const Location& location);
	};

	struct Token
	{
	private:

		Location _location;
		TokenType _type;
	
	public:

		Token();
		Token(const Location& location, TokenType type, usize length);

		usize length() const { return _location.length(); }
		const Location& location() const { return _location; }
		const char *filename() const { return _location.filename(); }
		usize line() const { return _location.line(); }
		usize col() const { return _location.col(); }
		TokenType type() const { return _type; }

		const char *begin() const { return _location.begin(); }
		const char *end() const { return _location.end(); }
		char operator[](usize i) const { return _location[i]; }

		friend std::ostream& operator<<(std::ostream& out, const Token& token);
	};

	typedef Array<Token>::const_iterator TokenIterator;
}

#endif
