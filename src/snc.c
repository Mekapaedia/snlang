#include "snc.h"
#include "lex.h"

int main(/*int argc, char **argv*/)
{
    lexeme *lexlist = NULL;
    const char *input = "int32 a = 1;";
    lex(input, &lexlist);
    return 0;
}
