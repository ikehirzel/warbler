#include <warbler/syntax/ast.hpp>

#include <warbler/syntax/function.hpp>

namespace warbler::syntax
{
	Ast::Ast(Module&& module) :
	_module(std::move(module))
	{}

	Result<Ast> Ast::parse(lexicon::Token& token)
	{
		auto res = Module::parse(token.next());

		if (!res)
			return {};

		return Ast(res.unwrap());
	}

	void Ast::print_tree(u32 depth) const
	{
		_module.print_tree(depth);
	}

	bool Ast::validate()
	{
		#pragma message "actually implement passing scope to module"
		return _module.validate({ "TEST_MODULE" });
	}
}