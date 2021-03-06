#ifndef WARBLER_VALIDATOR_HPP
#define WARBLER_VALIDATOR_HPP

#include <warbler/syntax.hpp>
#include <warbler/context.hpp>
#include <warbler/symbol_table.hpp>

namespace warbler
{
	Result<StatementContext> validate_statement(const StatementSyntax& statement, FunctionSymbolTable& symbols);
	Result<ParameterContext> validate_parameter(const ParameterSyntax& syntax, FunctionSymbolTable& symbols);
	SymbolData& validate_variable(const VariableSyntax& syntax, FunctionSymbolTable& symbols);
	bool validate_struct(const StructSyntax& syntax, GlobalSymbolTable& symbols, Array<String>& containing_types);
	Result<PackageContext> validate_module(const ModuleSyntax& syntax);
	Result<ProgramContext> validate(const ProgramSyntax& syntax);
}

#endif
