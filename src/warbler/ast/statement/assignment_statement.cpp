#include <warbler/ast/statement/assignment_statement.hpp>

// local headers
#include <warbler/print.hpp>

// standard headers
#include <cstdlib>

namespace warbler
{
	AssignmentStatement::AssignmentStatement(PrimaryExpression&& lhs, Expression&& rhs, AssignmentType type) :
	_lhs(lhs),
	_rhs(rhs),
	_type(type)
	{}

	Result<AssignmentStatement> AssignmentStatement::parse(TokenIterator& iter)
	{
		auto lhs = PrimaryExpression::parse(iter);

		if (lhs.has_error())
			return lhs.error();

		AssignmentType type;
		switch (iter->type())
		{
			case TOKEN_ASSIGN:
				type = ASSIGN_BECOME;
				break;

			case TOKEN_MULTIPLY_ASSIGN:
				type = ASSIGN_MULTIPLY;
				break;

			case TOKEN_DIVIDE_ASSIGN:
				type = ASSIGN_DIVIDE;
				break;

			case TOKEN_MODULUS_ASSIGN:
				type = ASSIGN_MODULUS;
				break;

			case TOKEN_ADD_ASSIGN:
				type = ASSIGN_ADD;
				break;

			case TOKEN_SUBTRACT_ASSIGN:
				type = ASSIGN_SUBTRACT;
				break;

			case TOKEN_LSHIFT_ASSIGN:
				type = ASSIGN_LSHIFT;
				break;

			case TOKEN_RSHIFT_ASSIGN:
				type = ASSIGN_RSHIFT;
				break;

			case TOKEN_BITAND_ASSIGN:
				type = ASSIGN_BITWISE_AND;
				break;

			case TOKEN_BITOR_ASSIGN:
				type = ASSIGN_BITWISE_OR;
				break;

			case TOKEN_BITXOR_ASSIGN:
				type = ASSIGN_BITWISE_XOR;
				break;

			default:
				error_out(iter) << "expected assignment operator after primary expression but got '" << *iter << '\'' << token_error(iter) << std::endl;
				return ERROR_ARGUMENT;
		}

		++iter;

		auto rhs = ConditionalExpression::parse(iter);

		if (rhs.has_error())
			return rhs.error();

		return AssignmentStatement(lhs.unwrap(), rhs.unwrap(), type);
	}

	void AssignmentStatement::print_tree(u32 depth) const
	{
		_lhs.print_tree(depth);

		switch (_type)
		{
			case ASSIGN_BECOME:
				std::cout << tree_branch(depth) << "=\n";
				break;

			case ASSIGN_MULTIPLY:
				std::cout << tree_branch(depth) << "*=\n";
				break;

			case ASSIGN_DIVIDE:
				std::cout << tree_branch(depth) << "/=\n";
				break;

			case ASSIGN_MODULUS:
				std::cout << tree_branch(depth) << "%=\n";				
				break;

			case ASSIGN_ADD:
				std::cout << tree_branch(depth) << "*=\n";
				break;

			case ASSIGN_SUBTRACT:
				std::cout << tree_branch(depth) << "-=\n";
				break;

			case ASSIGN_LSHIFT:
				std::cout << tree_branch(depth) << "<<=\n";
				break;

			case ASSIGN_RSHIFT:
				std::cout << tree_branch(depth) << ">>=\n";
				break;

			case ASSIGN_BITWISE_AND:
				std::cout << tree_branch(depth) << "&=\n";
				break;

			case ASSIGN_BITWISE_OR:
				std::cout << tree_branch(depth) << "|=\n";
				break;

			case ASSIGN_BITWISE_XOR:
				std::cout << tree_branch(depth) << "^=\n";
				break;
		}

		_rhs.print_tree(depth + 1);
	}
}