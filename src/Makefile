BIN := snc
LEX_SRC := lex.re
LEX_C := $(LEX_SRC:.re=.c)
LEX := re2c
SRC := snc.c $(LEX_C)
OBJ := $(SRC:.c=.o)
CFLAGS := $(CFLAGS) -std=c99 -pedantic -g -Og -Wall -Wextra -Werror
LEXFLAGS := -i -W -Werror

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $(BIN)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(LEX_C): $(LEX_SRC)
	$(LEX) $< -o $@ $(LEXFLAGS)

clean:
	rm $(BIN) $(OBJ) $(LEX_C)
