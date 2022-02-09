#ifndef WARBLER_AST_EXPRESSION_ASSIGNMENT_HPP
#define WARBLER_AST_EXPRESSION_ASSIGNMENT_HPP

// local headers
#include <warbler/ast/expression/expression.hpp>
#include <warbler/ast/expression/conditional_expression.hpp>
#include <warbler/ast/expression/primary_expression.hpp>

namespace warbler::ast
{
	enum AssignmentType
	{
		ASSIGN_BECOME,
		ASSIGN_MULTIPLY,
		ASSIGN_DIVIDE,
		ASSIGN_MODULUS,
		ASSIGN_ADD,
		ASSIGN_SUBTRACT,
		ASSIGN_LSHIFT,
		ASSIGN_RSHIFT,
		ASSIGN_BITWISE_AND,
		ASSIGN_BITWISE_OR,
		ASSIGN_BITWISE_XOR
	};

	class AssignmentStatement
	{
	private:

		PrimaryExpression _lhs;
		Ptr<Expression> _rhs;
		AssignmentType _type;

	public:

		AssignmentStatement(PrimaryExpression&& lhs, Ptr<Expression> &&rhs, AssignmentType type);

		static Result<AssignmentStatement> parse(TokenIterator& iter);

		void print_tree(u32 depth = 0) const;
	};
}
#endif
