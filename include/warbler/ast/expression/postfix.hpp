#ifndef WARBLER_AST_POSTFIX_EXPRESSION_HPP
#define WARBLER_AST_POSTFIX_EXPRESSION_HPP

// local headers
#include <warbler/ast/argument.hpp>
#include <warbler/ast/identifier.hpp>
#include <warbler/ast/expression/expression.hpp>

namespace warbler::ast
{
	enum PostfixType
	{
		POSTFIX_INDEX,
		POSTFIX_FUNCTION_CALL,
		POSTFIX_MEMBER
	};

	class Postfix
	{
	private:

		union
		{
			Expression *_index;
			Array<Argument> _arguments;
			Identifier _member;
		};

		PostfixType _type;

	public:

		Postfix(Expression *index);
		Postfix(Array<Argument>&& arguments);
		Postfix(Identifier&& member);
		Postfix(Postfix&& other);
		Postfix(const Postfix& other);
		~Postfix();

		static Result<Postfix> parse(TokenIterator& iter);
		static Result<Array<Postfix>> parse_list(TokenIterator& iter);

		void print_tree(u32 depth = 0) const;

		Postfix& operator=(Postfix&& other);
		Postfix& operator=(const Postfix& other);
	};
}

#endif
