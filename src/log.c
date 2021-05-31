// header
#include <grackle/log.h>

// standard library
#include <stdio.h>
#include <string.h>

// macros
#define FILEPATH_LEN  32


char curr_filepath[FILEPATH_LEN + 1];

#define COLOR_RED	"\033[31m"
#define COLOR_RESET	"\033[0m"
#define ERROR_PROMPT COLOR_RED "error:" COLOR_RESET

void log_prompt(const char *prompt, unsigned line, unsigned col)
{
	fprintf(stderr, "%s:%u:%u: %s ", curr_filepath, line, col, prompt);
}


void log_error_prompt(unsigned line, unsigned col)
{
	log_prompt(ERROR_PROMPT, line, col);
}


void log_set_filepath(const char *filepath)
{	
	size_t len = strlen(filepath);
	size_t oi = 0;
	size_t start = len - FILEPATH_LEN;
	if (start > len) start = 0;
	for (size_t i = start; i < len; ++i)
	{
		curr_filepath[oi++] = filepath[i];
	}
	
	curr_filepath[len - start] = 0;
}


const char *log_filepath()
{
	return curr_filepath;
}
