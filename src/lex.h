#include <stdio.h>
#include <stdlib.h>

typedef enum _lextype
{
    type,
    num,
    ch,
    op,
    paran,
    semi
} lextype;

typedef struct _lexeme
{
    lextype type;
    void* val;
} lexeme;

int lex(const char *input, lexeme **lexlist);
void lex_error(const char *cur);
void lexprint(lexeme l);
