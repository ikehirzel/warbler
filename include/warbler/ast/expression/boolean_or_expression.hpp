#ifndef WARBLER_AST_EXPRESSION_BOOLEAN_OR_HPP
#define WARBLER_AST_EXPRESSION_BOOLEAN_OR_HPP

// local headers
#include <warbler/ast/expression/boolean_and_expression.hpp>

namespace warbler
{
	class BooleanOrExpression
	{
	private:

		BooleanAndExpression _lhs;
		Array<BooleanAndExpression> _rhs;

	public:

		BooleanOrExpression(BooleanAndExpression&& lhs, Array<BooleanAndExpression>&& rhs);

		static Result<BooleanOrExpression> parse(TokenIterator& iter);

		void print_tree(u32 depth = 0) const;
	};
}
#endif