#include <warbler/ast/expression/equality_expression.hpp>

// local headers
#include <warbler/print.hpp>

// standard headers
#include <cstdlib>
#include <cassert>

namespace warbler::ast
{
	EqualityExpression::EqualityExpression(RelationalExpression&& lhs, Array<EqualityRhs>&& rhs) :
	_lhs(std::move(lhs)),
	_rhs(std::move(rhs))
	{}

	Result<EqualityExpression> EqualityExpression::parse(TokenIterator& iter)
	{
		auto lhs = RelationalExpression::parse(iter);

		if (!lhs)
			return {};

		Array<EqualityRhs> rhs;

		while (true)
		{
			bool should_break = false;

			EqualityType type;
			switch (iter->type())
			{
				case TOKEN_EQUALS:
					type = EQUALITY_EQUALS;
					break;

				case TOKEN_NOT_EQUALS:
					type = EQUALITY_NOT_EQUALS;
					break;

				default:
					should_break = true;
					break;
			}

			if (should_break)
				break;

			iter += 1;

			auto res = RelationalExpression::parse(iter);

			if (!res)
				return {};

			rhs.emplace_back(EqualityRhs { res.unwrap(), type });
		}

		return EqualityExpression(lhs.unwrap(), std::move(rhs));
	}

	bool EqualityExpression::validate(semantics::ModuleContext& mod_ctx, semantics::FunctionContext& func_ctx)
	{
		if (!_lhs.validate(mod_ctx, func_ctx))
			return false;

		for (auto& rhs : _rhs)
		{
			if (!rhs.expr.validate(mod_ctx, func_ctx))
				return false;
		}

		return true;
	}

	void EqualityExpression::print_tree(u32 depth) const
	{
		if (_rhs.size() > 0)
			depth += 1;

		_lhs.print_tree(depth);

		for (const auto& rhs : _rhs)
		{
			const char *symbol = rhs.type == EQUALITY_EQUALS
				? "==\n"
				: "!=\n";

			std::cout << tree_branch(depth - 1) << symbol;
			rhs.expr.print_tree(depth);
		}
	}

	Typename *EqualityExpression::get_type(semantics::ModuleContext& mod_ctx) const
	{
		throw std::runtime_error("EqualityExpression::" + String(__func__) + " is not implemented yet");
	}

	const Location& EqualityExpression::location() const
	{
		throw std::runtime_error("EqualityExpression::" + String(__func__) + " is not implemented yet");
	}
}
