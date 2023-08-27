CC = gcc
FLAGS = -Wall -Werror -Wextra -std=c11
SRC_TESTS = $(wildcard tests/*.c)
SRC_FILES= *.c

GCOVFLAGS = -L. --coverage
TEST_FLAGS = -lcheck

ifeq ($(shell uname), Linux)
	TEST_FLAGS += -lpthread -lrt -lsubunit -lm
endif

all: clean style s21_matrix.a test gcov_report

s21_matrix.a:
	$(CC) $(FLAGS) $(SRC_FILES) -c
	ar r s21_matrix.a *.o
	rm *.o

test: s21_matrix.a
	$(CC) $(FLAGS) -g $(SRC_TESTS) s21_matrix.a $(TEST_FLAGS) -o test

style:
	clang-format -n -style=Google *.h tests/*.h $(SRC_TESTS) $(SRC_FILES)
	
set-style:
	clang-format -i -style=Google *.h tests/*.h $(SRC_TESTS) $(SRC_FILES)

gcov_report: s21_matrix.a test
	$(CC) $(FLAGS) -w $(SRC_TESTS) $(SRC_FILES) s21_matrix.a $(TEST_FLAGS) $(GCOVFLAGS) -o test
	./test
	lcov -t test -o test.info -c -d .
	genhtml -o test_html test.info
	open ./test_html/index.html

clean:
	rm -rf *.o *.a *.gch *.gcno *.gcna *.gcda *.info *.out test test_html test.dSYM report_make tests/*.o

build:
	$(CC) $(FLAGS) $(SRC_FILES) -o s21_matrix.o
