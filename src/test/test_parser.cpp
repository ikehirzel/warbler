#include <warbler/tokenizer.hpp>

// local headers
#include <warbler/ast/ast.hpp>
#include <warbler/print.hpp>

// standard headers
#include <stdio.h>
#include <assert.h>

//const char *src = "foo(3, 4) * 1 / 5 + 2 / hello % 3\n + 3 == 4 >= &hello";
//const char *src = "var b: int = a || b && c << 1.7 * 3;";
// const char *src =
// "func do_thing(num: i32, text: String)\n"
// "{\n"
// "	var value: f64 = 12.58 * log(234);\n"
// "}\n"
// ;
const char *src = R"=====(
func do_thing(arg: i32)
{
	var value: i32 = arg * 3;
	if value == 3
	{
		var name : String = "hello";
	}
	else if value == 6
	{
		var num : f64 = 12.5;
	}
	else
	{
		print("uh oh");
	}
}
)=====";

using namespace warbler;

int main()
{
	tokenizer_init();

	auto token_res = tokenize("<in-memory-file>", src);

	if (token_res.has_error())
		return token_res.error();

	auto tokens = token_res.unwrap();

	for (const auto& token : tokens)
		std::cout << token.line() << ':' << token.col() << " " << token << '\n';
	std::cout << std::endl;

	TokenIterator iter = tokens.begin();
	auto res = Function::parse(iter);

	if (res.has_error())
		return res.error();

	if (iter->type() != TOKEN_END_OF_FILE)
	{
		error_out(iter) << "current token is not EOF" << token_error(iter) << std::endl;
	}


	auto node = res.unwrap();

	node.print_tree(1);

	return 0;
}