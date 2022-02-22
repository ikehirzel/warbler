#include <warbler/ast/typename.hpp>

// standard headers
#include <warbler/print.hpp>

namespace warbler::ast
{
	Typename::Typename() :
	_location(),
	_name(""),
	_ptr_mutability(),
	_type(nullptr)
	{}

	Typename::Typename(const Location& location, Array<bool>&& ptr_mutability) :
	_location(location),
	_name(location.text()),
	_ptr_mutability(std::move(ptr_mutability)),
	_type(nullptr)
	{}

	Result<Typename> Typename::parse(TokenIterator& iter)
	{
		Array<bool> ptr_mutability;

		while (iter->type() == TOKEN_ASTERISK)
		{
			iter += 1;

			if (iter->type() == TOKEN_MUT)
			{
				ptr_mutability.push_back(true);
				iter += 1;
			}
			else
			{
				ptr_mutability.push_back(false);
			}
		}

		if (iter->type() != TOKEN_IDENTIFIER)
		{
			parse_error(iter, "typename");
			return {};
		}
		
		const auto& location = iter->location();

		iter += 1;

		return Typename { location, std::move(ptr_mutability) };
	}

	bool Typename::validate(semantics::ModuleContext& context)
	{
		if (context.types.find(_name) == context.types.end() && context.primitives.find(_name) == context.primitives.end())
		{
			print_error(_location, "'" + _name + "' is not an imported or locally defined type");
			return false;
		}

		return true;
	}

	void Typename::print_tree(u32 depth) const
	{
		
		std::cout << tree_branch(depth) << ": " <<  _name << '\n';
	}
}