#include "lex.h"

int lex(const char *input, lexeme **lexlist)
{
    const char *YYCURSOR = input;
    //const char *YYMARKER;
    const char *YYTOKEN;
    int ret = 0;
    lexeme *lexout = NULL;

    if(lexlist != NULL)
    {
        lexout = malloc(8);
        *lexlist = lexout;
    }
    else
    {
        return 1;
    }

    for(;;)
    {
        YYTOKEN = YYCURSOR;
        /*!re2c
            re2c:yyfill:enable = 0;
            re2c:define:YYCTYPE = char;

            end = "\x00";

            end { return ret; }

            ws = [ \t\v\n\r]+;

            ws { continue; }

            number = [1-9][0-9]*;
            type = "int"[0-9]+;
            name = [A-z][A-z0-9_-]*;
            assign = "=";
            semi = ";";

            number { puts("number"); continue; }
            type   { puts("type"); continue; }
            name   { puts("name"); continue; }
            assign { puts("assign"); continue; }
            semi   { puts("semi"); continue; }
            *      { ret = 1; lex_error(YYTOKEN); break; }

        */

        if(ret != 0)
            break;
    }

    return ret;
}

void lex_error(const char *cur)
{
    printf("Unknown token: %s\n", cur);
}

/* vim: set ft=c: */
