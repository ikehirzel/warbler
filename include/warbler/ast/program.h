#ifndef WARBLER_PROGRAM_H
#define WARBLER_PROGRAM_H

// local headers
#include <warbler/ast/function.h>

typedef struct Program
{
	Function *functions;
	size_t function_count;
} Program;

void program_init(Program *program);
void program_free(Program *program);
Error program_parse(Program *program, TokenIterator *iter);

#endif