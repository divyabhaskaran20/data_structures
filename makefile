cc := gcc

INC_DIR := single_list
EXAMPLE_DIR := example

all:
	cc ${EXAMPLE_DIR}/ex_basic_list.c  \
		${INC_DIR}/basic_list.c \
		${INC_DIR}/coding_problems.c

clean:
	rm a.out

run:
	./a.out

