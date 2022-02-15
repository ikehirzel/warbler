#include <warbler/ast/function.hpp>

// local headers
#include <warbler/print.hpp>
#include <warbler/semantics/symbol.hpp>

namespace warbler::ast
{
	Function::Function(Name&& name, std::vector<Declaration>&& parameters, Typename&& return_type, BlockStatement&& body) :
	_name(std::move(name)),
	_parameters(std::move(parameters)),
	_return_type(std::move(return_type)),
	_body(std::move(body))
	{}

	static Result<Array<Declaration>> parse_parameters(TokenIterator& iter)
	{
		if (iter->type() != TOKEN_LPAREN)
		{
			parse_error(iter, "'(' after function name");
			return {};
		}

		iter += 1;

		Array<Declaration> parameters;

		if (iter->type() != TOKEN_RPAREN)
		{
			while (true)
			{
				auto res = Declaration::parse_parameter(iter);

				if (!res)
					return {};

				parameters.emplace_back(res.unwrap());

				if (iter->type() != TOKEN_COMMA)
					break;

				iter += 1;
			}

			if (iter->type() != TOKEN_RPAREN)
			{
				parse_error(iter, "')' after function parameters");
				return {};
			}
		}

		iter += 1;

		return parameters;
	}

	Result<Function> Function::parse(TokenIterator& iter)
	{
		if (iter->type() != TOKEN_FUNC)
		{
			parse_error(iter, "'function'");
			return {};
		}

		iter += 1;

		auto name = Name::parse(iter);

		if (!name)
			return {};

		auto parameters = parse_parameters(iter);

		if (!parameters)
			return {};
		
		auto type = Typename();

		if (iter->type() == TOKEN_COLON)
		{
			iter += 1;

			auto res = Typename::parse(iter);
			
			if (!res)
				return {};

			type = res.unwrap();
		}

		if (iter->type() != TOKEN_LBRACE)
		{
			parse_error(iter, "function body starting with '{'");
			return {};
		}
		
		auto body = BlockStatement::parse(iter);

		if (!body)
			return {};

		return Function(name.unwrap(), parameters.unwrap(), std::move(type), body.unwrap());
	}

	void Function::print_tree(u32 depth) const 
	{
		std::cout << tree_branch(depth) << "function " << _name.text() << '\n';
		std::cout << tree_branch(depth + 1) << "(\n";

		for (const auto& parameter : _parameters)
			parameter.print_tree(depth + 2);

		std::cout << tree_branch(depth + 1) << ")\n";
		std::cout << tree_branch(depth + 1) << ": " << _return_type.name() << '\n';
		
		_body.print_tree(depth + 1);
	}

	bool Function::validate(semantics::ModuleContext& mod_ctx)
	{
		for (auto& parameter : _parameters)
		{
			if (!parameter.validate_parameter(mod_ctx, _context))
				return false;
		}

		return _body.validate(mod_ctx, _context);
	}
}