#ifndef WARBLER_SYNTAX_EXPRESSION_BITWISE_SHIFT_HPP
#define WARBLER_SYNTAX_EXPRESSION_BITWISE_SHIFT_HPP

// local headers
#include <warbler/syntax/expression/additive_expression.hpp>

namespace warbler::syntax
{
	enum class ShiftType
	{
		Left,
		Right
	};

	struct ShiftRhs
	{
		Ptr<Expression> expr;
		ShiftType type;
	};

	class ShiftExpression : public Expression
	{
	private:

		Ptr<Expression> _lhs;
		Array<ShiftRhs> _rhs;

	public:

		ShiftExpression(Ptr<Expression>&& lhs, Array<ShiftRhs>&& rhs);

		static Result<Ptr<Expression>> parse(lexicon::Token& token);

		bool validate(semantics::Context& context);
		void print_tree(u32 depth = 0) const;
		Type *get_type();
		const lexicon::Token& token() const;
	};
}

#endif
