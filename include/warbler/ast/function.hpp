#ifndef WARBLER_AST_FUNCTION_HPP
#define WARBLER_AST_FUNCTION_HPP

// local headers
#include <warbler/ast/name.hpp>
#include <warbler/ast/expression/expression.hpp>
#include <warbler/ast/expression/conditional_expression.hpp>
#include <warbler/ast/statement/block_statement.hpp>
#include <warbler/ast/statement/statement.hpp>
#include <warbler/ast/declaration.hpp>
#include <warbler/util/table.hpp>
#include <warbler/semantics/context.hpp>

namespace warbler::ast
{
	class Symbol;

	class Function
	{
	private:

		semantics::FunctionContext _context;
		Name _name;
		Array<Declaration> _parameters;
		Typename _return_type;
		BlockStatement _body;
	
	public:

		Function(Name&& name, Array<Declaration>&& parameters, Typename&& return_type, BlockStatement&& compound_body);
		Function(Function&& other) = default;
		Function(const Function& other) = delete;		

		static Result<Function> parse(TokenIterator& iter);

		void print_tree(u32 depth = 0) const;
		bool validate(semantics::ModuleContext& context);

		const Name& name() const { return _name; }

		Function& operator=(Function&& other) = default;
		Function& operator=(const Function& other) = delete;
	};
}

#endif
