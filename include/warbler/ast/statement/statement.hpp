#ifndef WARBLER_AST_STATEMENT_HPP
#define WARBLER_AST_STATEMENT_HPP

#include <warbler/semantics/context.hpp>
#include <warbler/util/result.hpp>
#include <warbler/token.hpp>
#include <warbler/util/ptr.hpp>

namespace warbler::ast
{
	struct Statement
	{
		virtual ~Statement() = default;
		virtual bool validate(semantics::ModuleContext& context) = 0;
		virtual void print_tree(u32 depth = 0) const = 0;

		static Result<Ptr<Statement>> parse(TokenIterator& iter);
	};
}

#endif
