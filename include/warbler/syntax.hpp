#ifndef WARBLER_SYNTAX_HPP
#define WARBLER_SYNTAX_HPP

#include <warbler/token.hpp>
#include <warbler/type.hpp>
#include <warbler/util/optional.hpp>
#include <warbler/util/box.hpp>

namespace warbler
{
	class ConditionalExpressionSyntax;
	class BooleanOrExpressionSyntax;
	class BooleanAndExpressionSyntax;
	class BitwiseOrExpressionSyntax;
	class BitwiseXorExpressionSyntax;
	class BitwiseAndExpressionSyntax;
	class EqualityExpressionSyntax;
	class RelationalExpressionSyntax;
	class BitShiftExpressionSyntax;
	class AdditiveExpressionSyntax;
	class MultiplicativeExpressionSyntax;
	class PrefixExpressionSyntax;
	class PostfixExpressionSyntax;
	class PrimaryExpressionSyntax;
	class ConstantSyntax;
	class SymbolSyntax;
	class AssignmentSyntax;
	class ExpressionStatementSyntax;
	class BlockStatementSyntax;
	class DeclarationSyntax;
	class IfStatementSyntax;

	class SymbolSyntax
	{
		Token _token;

	public:

		SymbolSyntax(const Token& token) :
		_token(token)
		{}
	};

	class LabelSyntax
	{
		Token _token;

	public:

		LabelSyntax(const Token& token) :
		_token(token)
		{}
	};

	class IdentifierSyntax
	{
		Token _token;

	public:

		IdentifierSyntax(const Token& token) :
		_token(token)
		{}

		const auto& token() const { return _token; }
	};

	class ExpressionSyntax
	{
		union
		{
			ConditionalExpressionSyntax *_conditional;
			BooleanOrExpressionSyntax *_boolean_or;
			BooleanAndExpressionSyntax *_boolean_and;
			BitwiseOrExpressionSyntax *_bitwise_or;
			BitwiseXorExpressionSyntax *_bitwise_xor;
			BitwiseAndExpressionSyntax *_bitwise_and;
			EqualityExpressionSyntax *_equality;
			RelationalExpressionSyntax *_relational;
			BitShiftExpressionSyntax *_shift;
			AdditiveExpressionSyntax *_additive;
			MultiplicativeExpressionSyntax *_multiplicative;
			PrefixExpressionSyntax *_prefix;
			PostfixExpressionSyntax *_postfix;
			PrimaryExpressionSyntax *_primary;
			ConstantSyntax *_constant;
			SymbolSyntax *_symbol;
		};

		ExpressionType _type;
	
	public:

		ExpressionSyntax(ConditionalExpressionSyntax&&);
		ExpressionSyntax(BooleanOrExpressionSyntax&&);
		ExpressionSyntax(BooleanAndExpressionSyntax&&);
		ExpressionSyntax(BitwiseOrExpressionSyntax&&);
		ExpressionSyntax(BitwiseXorExpressionSyntax&&);
		ExpressionSyntax(BitwiseAndExpressionSyntax&&);
		ExpressionSyntax(EqualityExpressionSyntax&&);
		ExpressionSyntax(RelationalExpressionSyntax&&);
		ExpressionSyntax(BitShiftExpressionSyntax&&);
		ExpressionSyntax(AdditiveExpressionSyntax&&);
		ExpressionSyntax(MultiplicativeExpressionSyntax&&);
		ExpressionSyntax(PrefixExpressionSyntax&&);
		ExpressionSyntax(PostfixExpressionSyntax&&);
		ExpressionSyntax(PrimaryExpressionSyntax&&);
		ExpressionSyntax(ConstantSyntax&&);
		ExpressionSyntax(SymbolSyntax&&);
		ExpressionSyntax(ExpressionSyntax&&);
		ExpressionSyntax& operator=(ExpressionSyntax&&) = default;
		ExpressionSyntax(const ExpressionSyntax&) = delete;
		ExpressionSyntax& operator=(const ExpressionSyntax&) = delete;
		~ExpressionSyntax();

		ExpressionType type() const { return _type; }
		const ConditionalExpressionSyntax& conditional() const { assert(_type == ExpressionType::conditional); return *_conditional; }
		const BooleanOrExpressionSyntax& boolean_or() const { assert(_type == ExpressionType::BooleanOr); return *_boolean_or; }
		const BooleanAndExpressionSyntax& boolean_and() const { assert(_type == ExpressionType::BooleanAnd); return *_boolean_and; }
		const BitwiseOrExpressionSyntax& bitwise_or() const { assert(_type == ExpressionType::BitwiseOr); return *_bitwise_or; }
		const BitwiseXorExpressionSyntax& bitwise_xor() const { assert(_type == ExpressionType::BitwiseXor); return *_bitwise_xor; }
		const BitwiseAndExpressionSyntax& bitwise_and() const { assert(_type == ExpressionType::BitwiseAnd); return *_bitwise_and; }
		const EqualityExpressionSyntax& equality() const { assert(_type == ExpressionType::Equality); return *_equality; }
		const RelationalExpressionSyntax& relational() const { assert(_type == ExpressionType::Relational); return *_relational; }
		const BitShiftExpressionSyntax& bit_shift() const { assert(_type == ExpressionType::Shift); return *_shift; }
		const AdditiveExpressionSyntax& additive() const { assert(_type == ExpressionType::Additive); return *_additive; }
		const MultiplicativeExpressionSyntax& multiplicative() const { assert(_type == ExpressionType::Multiplicative); return *_multiplicative; }
		const PrefixExpressionSyntax& prefix() const { assert(_type == ExpressionType::Prefix); return *_prefix; }
		const PostfixExpressionSyntax& postfix() const { assert(_type == ExpressionType::Postfix); return *_postfix; }
		const PrimaryExpressionSyntax& primary() const { assert(_type == ExpressionType::Primary); return *_primary; }
		const ConstantSyntax& constant() const { assert(_type == ExpressionType::Constant); return *_constant; }
		const SymbolSyntax& symbol() const { assert(_type == ExpressionType::Symbol); return *_symbol; }
	};

	class ConstantSyntax
	{
	private:

		Token _token;

		union
		{
			char _character;
			String _string;
			u64 _integer;
			double _floating;
			bool _boolean;
		};

		ConstantType _type;

	public:

		ConstantSyntax(const Token& token, String&& string);
		ConstantSyntax(const Token& token, char character);
		ConstantSyntax(const Token& token, u64 integer);
		ConstantSyntax(const Token& token, double floating);
		ConstantSyntax(const Token& token, bool boolean);
		ConstantSyntax(ConstantSyntax&&);
		ConstantSyntax(const ConstantSyntax&) = delete;
		~ConstantSyntax();

		const Token& token() const { return _token; }

		ConstantSyntax& operator=(ConstantSyntax&& other);
		ConstantSyntax& operator=(const ConstantSyntax& other) = delete;
	};

	class PrimaryExpressionSyntax
	{
		// union
		// {
		// ConstantSyntax _constant;
		// ExpressionSyntax _expression;
		// SymbolSyntax _symbol;
		// }
	};

	class PostfixExpressionSyntax
	{
	private:

		ExpressionSyntax _expression;

		union
		{
			ExpressionSyntax _index;
			Array<ExpressionSyntax> _arguments;
			IdentifierSyntax _member;
		};

		PostfixType _type;

	public:

		PostfixExpressionSyntax(ExpressionSyntax&& expression, ExpressionSyntax&& index);
		PostfixExpressionSyntax(ExpressionSyntax&& expression, Array<ExpressionSyntax>&& arguments);
		PostfixExpressionSyntax(ExpressionSyntax&& expression, IdentifierSyntax&& member);
		PostfixExpressionSyntax(PostfixExpressionSyntax&& other);
		PostfixExpressionSyntax(const PostfixExpressionSyntax& other) = delete;
		~PostfixExpressionSyntax();
	};

	class PrefixExpressionSyntax
	{
	private:

		Token _token;
		ExpressionSyntax _expression;
		PrefixType _type;

	public:

		PrefixExpressionSyntax(const Token& token, ExpressionSyntax&& expression, PrefixType type) :
		_token(token),
		_expression(std::move(expression)),
		_type(type)
		{}
	};

	struct MultiplicativeRhsSyntax
	{
		ExpressionSyntax expr;
		MultiplicativeType type;
	};

	class MultiplicativeExpressionSyntax
	{
	private:

		ExpressionSyntax _lhs;
		Array<MultiplicativeRhsSyntax> _RhsSyntax;
	
	public:

		MultiplicativeExpressionSyntax(ExpressionSyntax&& lhs, Array<MultiplicativeRhsSyntax>&& RhsSyntax) :
		_lhs(std::move(lhs)),
		_RhsSyntax(std::move(RhsSyntax))
		{}
	};

	struct AdditiveRhsSyntax
	{
		ExpressionSyntax expr;
		AdditiveType type;
	};

	class AdditiveExpressionSyntax
	{
	private:

		ExpressionSyntax _lhs;
		Array<AdditiveRhsSyntax> _RhsSyntax;
	
	public:

		AdditiveExpressionSyntax(ExpressionSyntax&& lhs, Array<AdditiveRhsSyntax>&& RhsSyntax) :
		_lhs(std::move(lhs)),
		_RhsSyntax(std::move(RhsSyntax))
		{}
	};

	struct BitShiftRhsSyntax
	{
		ExpressionSyntax expr;
		BitShiftType type;
	};

	class BitShiftExpressionSyntax
	{
		ExpressionSyntax _lhs;
		Array<BitShiftRhsSyntax> _RhsSyntax;

	public:

		BitShiftExpressionSyntax(ExpressionSyntax&& lhs, Array<BitShiftRhsSyntax>&& RhsSyntax) :
		_lhs(std::move(lhs)),
		_RhsSyntax(std::move(RhsSyntax))
		{}
	};

	struct RelationalRhsSyntax
	{
		ExpressionSyntax expr;
		RelationalType type;
	};

	class RelationalExpressionSyntax
	{
	private:

		ExpressionSyntax _lhs;
		Array<RelationalRhsSyntax> _RhsSyntax;

	public:

		RelationalExpressionSyntax(ExpressionSyntax&& lhs, Array<RelationalRhsSyntax>&& RhsSyntax) :
		_lhs(std::move(lhs)),
		_RhsSyntax(std::move(RhsSyntax))
		{}
	};

	struct EqualityRhsSyntax
	{
		ExpressionSyntax expr;
		EqualityType type;
	};

	class EqualityExpressionSyntax
	{
	private:

		ExpressionSyntax _lhs;
		Array<EqualityRhsSyntax> _RhsSyntax;

	public:

		EqualityExpressionSyntax(ExpressionSyntax&& lhs, Array<EqualityRhsSyntax>&& RhsSyntax) :
		_lhs(std::move(lhs)),
		_RhsSyntax(std::move(RhsSyntax))
		{}
	};

	class BitwiseAndExpressionSyntax
	{
	private:

		ExpressionSyntax _lhs;
		Array<ExpressionSyntax> _RhsSyntax;

	public:

		BitwiseAndExpressionSyntax(ExpressionSyntax&& lhs, Array<ExpressionSyntax>&& RhsSyntax) :
		_lhs(std::move(lhs)),
		_RhsSyntax(std::move(RhsSyntax))
		{}
	};

	class BitwiseXorExpressionSyntax
	{
	private:

		ExpressionSyntax _lhs;
		Array<ExpressionSyntax> _RhsSyntax;

	public:

		BitwiseXorExpressionSyntax(ExpressionSyntax&& lhs, Array<ExpressionSyntax>&& RhsSyntax) :
		_lhs(std::move(lhs)),
		_RhsSyntax(std::move(RhsSyntax))
		{}
	};

	class BitwiseOrExpressionSyntax
	{
	private:

		ExpressionSyntax _lhs;
		Array<ExpressionSyntax> _RhsSyntax;	

	public:

		BitwiseOrExpressionSyntax(ExpressionSyntax&& lhs, Array<ExpressionSyntax>&& RhsSyntax) :
		_lhs(std::move(lhs)),
		_RhsSyntax(std::move(RhsSyntax))
		{}
	};

	class BooleanAndExpressionSyntax
	{
	private:

		ExpressionSyntax _lhs;
		Array<ExpressionSyntax> _RhsSyntax;

	public:

		BooleanAndExpressionSyntax(ExpressionSyntax&& lhs, Array<ExpressionSyntax>&& RhsSyntax) :
		_lhs(std::move(lhs)),
		_RhsSyntax(std::move(RhsSyntax))
		{}
	};

	class BooleanOrExpressionSyntax
	{
	private:

		ExpressionSyntax _lhs;
		Array<ExpressionSyntax> _RhsSyntax;

	public:

		BooleanOrExpressionSyntax(ExpressionSyntax&& lhs, Array<ExpressionSyntax>&& RhsSyntax) :
		_lhs(std::move(lhs)),
		_RhsSyntax(std::move(RhsSyntax))
		{}
	};

	struct ConditionalRhsSyntax
	{
		ExpressionSyntax _true_case;
		ExpressionSyntax _false_case;

		ConditionalRhsSyntax(ExpressionSyntax&& true_case, ExpressionSyntax&& false_case) :
		_true_case(std::move(true_case)),
		_false_case(std::move(false_case))
		{}
	};

	class ConditionalExpressionSyntax
	{
	private: // members

		ExpressionSyntax _lhs;
		Optional<ConditionalRhsSyntax> _RhsSyntax;

	public: // methods

		ConditionalExpressionSyntax(ExpressionSyntax&& lhs) :
		_lhs(std::move(lhs)),
		_RhsSyntax()
		{}

		ConditionalExpressionSyntax(ExpressionSyntax&& lhs, ExpressionSyntax&& true_case, ExpressionSyntax&& false_case) :
		_lhs(std::move(lhs)),
		_RhsSyntax(Optional<ConditionalRhsSyntax>(ConditionalRhsSyntax { std::move(true_case), std::move(false_case) }))
		{}
	};

	struct PtrSyntax
	{
		Token token;
		bool is_mutable;
	};

	class TypeSyntax
	{

		Token _base_type;
		Array<PtrSyntax> _ptrs;

	public:

		TypeSyntax(const Token& base_type, Array<PtrSyntax>&& ptrs) :
		_base_type(base_type),
		_ptrs(std::move(ptrs))
		{}
	};

	class MemberSyntax
	{
		IdentifierSyntax _name;
		TypeSyntax _type;
		bool _is_public;

	public:

		MemberSyntax(IdentifierSyntax&& name, TypeSyntax&& type, bool is_public) :
		_name(std::move(name)),
		_type(std::move(type)),
		_is_public(is_public)
		{}
	};

	class EnumSyntax
	{
		Array<MemberSyntax> _values;

	public:

		EnumSyntax(Array<MemberSyntax>&& values) :
		_values(std::move(values))
		{}
	};

	class StructSyntax
	{
		Array<MemberSyntax> _members;

	public:

		StructSyntax(Array<MemberSyntax>& members) :
		_members(std::move(members))
		{}

		const auto& members() const { return _members; }
	};

	class TypeDefinitionSyntax
	{
		IdentifierSyntax _name;
		
		union
		{
			StructSyntax _struct;
		};
		
		TypeDefinitionType _type;

	public:

		TypeDefinitionSyntax(IdentifierSyntax&& name, StructSyntax&& struct_def);
		TypeDefinitionSyntax(TypeDefinitionSyntax&& other);
		TypeDefinitionSyntax(const TypeDefinitionSyntax& other) = delete;
		~TypeDefinitionSyntax();


		const auto& name() const { return _name; }
		const auto& type() const { return _type; }
		const auto& struct_syntax() const { return _struct; }
	};

	class VariableSyntax
	{
	private:

		IdentifierSyntax _name;
		Optional<TypeSyntax> _type;
		bool _is_mutable;

	public:

		VariableSyntax(IdentifierSyntax&& name, Optional<TypeSyntax>&& type, bool is_mutable) :
		_name(std::move(name)),
		_type(std::move(type)),
		_is_mutable(is_mutable)
		{}

		bool is_mutable() const { return _is_mutable; }
		bool is_auto_type() const { return _type.has_value(); }

		const IdentifierSyntax& name() const { return _name; }
		TypeSyntax& type() { return *_type; }
	};

	class StatementSyntax
	{
		union
		{
			AssignmentSyntax *_assignment;
			ExpressionStatementSyntax *_expression;
			BlockStatementSyntax *_block;
			DeclarationSyntax *_declaration;
			IfStatementSyntax *_iff;
		};

		StatementType _type;

	public:

		StatementSyntax(AssignmentSyntax&&);
		StatementSyntax(ExpressionStatementSyntax&&);
		StatementSyntax(BlockStatementSyntax&&);
		StatementSyntax(DeclarationSyntax&&);
		StatementSyntax(IfStatementSyntax&&);
		StatementSyntax(StatementSyntax&&);
		StatementSyntax(const StatementSyntax&) = delete;
		~StatementSyntax();
		
	};

	class BlockStatementSyntax
	{
		Array<Box<StatementSyntax>> _statements;

	public:

		BlockStatementSyntax(Array<Box<StatementSyntax>>&& statements) :
		_statements(std::move(statements))
		{}
	};

	class JumpStatementSyntax
	{
		ExpressionSyntax *_value;
		JumpType _type;

	public:

		JumpStatementSyntax(ExpressionSyntax *value, JumpType type);
	};

	class IfStatementSyntax
	{
	private:

		ExpressionSyntax _condition;
		BlockStatementSyntax _then_body;

		union
		{
			BlockStatementSyntax _else_body;
			IfStatementSyntax *_else_if;
		};

		IfType _type;

	public:

		IfStatementSyntax(ExpressionSyntax&& condition, BlockStatementSyntax&& then_body);
		IfStatementSyntax(ExpressionSyntax&& condition, BlockStatementSyntax&& then_body, BlockStatementSyntax&& else_body);
		IfStatementSyntax(ExpressionSyntax&& condition, BlockStatementSyntax&& then_body, IfStatementSyntax *else_if);
		IfStatementSyntax(IfStatementSyntax&& other);
		IfStatementSyntax(const IfStatementSyntax& other) = delete;
		~IfStatementSyntax();
	};

	class ExpressionStatementSyntax
	{
	private:

		ExpressionSyntax _expression;

	public:

		ExpressionStatementSyntax(ExpressionSyntax&& expression) :
		_expression(std::move(expression))
		{}
	};

	class DeclarationSyntax
	{
		VariableSyntax _declaration;
		ExpressionSyntax _value;

	public:

		DeclarationSyntax(VariableSyntax&& declaration, ExpressionSyntax&& value) :
		_declaration(std::move(declaration)),
		_value(std::move(value))
		{}
	};

	class AssignmentSyntax
	{
	private:

		ExpressionSyntax _lhs;
		ExpressionSyntax _RhsSyntax;
		AssignmentType _type;

	public:

		AssignmentSyntax(ExpressionSyntax&& lhs, ExpressionSyntax &&RhsSyntax, AssignmentType type) :
		_lhs(std::move(lhs)),
		_RhsSyntax(std::move(RhsSyntax)),
		_type(type)
		{}
	};

	class LoopStatementSyntax
	{
		Array<StatementSyntax> _body;
		//LoopCondition _condition;
		LoopType _type;

	public:

		LoopStatementSyntax(Array<StatementSyntax>&& body, LoopType type);
	};

	class ParameterSyntax
	{
	private:

		IdentifierSyntax _identifier;
		TypeSyntax _type;
		bool _is_mutable;

	public:

		ParameterSyntax(IdentifierSyntax&& identifier, TypeSyntax&& type, bool is_mutable) :
		_identifier(std::move(identifier)),
		_type(std::move(type)),
		_is_mutable(is_mutable)
		{}
	};

	class FunctionSignatureSyntax
	{
		Array<ParameterSyntax> _parameters;
		TypeSyntax _return_type;
	
	public:

		FunctionSignatureSyntax(Array<ParameterSyntax>&& parameters, TypeSyntax&& return_type) :
		_parameters(std::move(parameters)),
		_return_type(std::move(return_type))
		{}
	};

	class FunctionSyntax
	{
		IdentifierSyntax _name;		
		FunctionSignatureSyntax _signature;
		BlockStatementSyntax _body;

	public:

		FunctionSyntax(IdentifierSyntax&& name, FunctionSignatureSyntax&& signature, BlockStatementSyntax&& body) :
		_name(std::move(name)),
		_signature(std::move(signature)),
		_body(std::move(body))
		{}

		const auto& name() const { return _name; }
		const auto& signature() const { return _signature; }
		const auto& body() const { return _body; }
	};

	class ModuleSyntax
	{
		Array<FunctionSyntax> _functions;
		Array<TypeDefinitionSyntax> _types;

	public:

		ModuleSyntax(Array<FunctionSyntax>& functions, Array<TypeDefinitionSyntax>& types) :
		_functions(std::move(functions)),
		_types(std::move(types))
		{}

		const auto& functions() const { return _functions; }
		const auto& types() const { return _types; }
	};

	class AstSyntax
	{
		ModuleSyntax _module;

	public:

		AstSyntax(ModuleSyntax&& module) :
		_module(std::move(module))
		{}

		const auto& module() const { return _module; }
	};
}

#endif