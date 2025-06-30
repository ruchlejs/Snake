CC = gcc
CFLAGS = -Wall #-MMD -Iinclude

SRC = src
OBJ = obj

SRC_FILES = $(wildcard $(SRC)/*.c)
OBJ_FILES = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRC_FILES))
DEP = $(OBJ_FILES:.o=.d)

#-include $(DEP)

all: snake

snake: $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@ -lSDL2

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ):
	mkdir -p $@

clean:
	rm -rf snake $(OBJ)/