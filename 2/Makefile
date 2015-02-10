CPPFLAGS = -Wall -std=c++11 -g
CPPC = g++
D_TESTS = ./test

# --
# OBJS
# --

Parser.o: ./Parser.cpp
	$(CPPC) $(CPPFLAGS) $^ -c -o $@

Lexer.o: ./Lexer.cpp
	$(CPPC) $(CPPFLAGS) $^ -c -o $@

Env.o: ./Env.cpp
	$(CPPC) $(CPPFLAGS) $^ -c -o $@

# --
# TEST EXECUTABLES
# --

$(D_TESTS)/test-Parser.out: $(D_TESTS)/test-Parser.cpp Parser.o
	$(CPPC) $(CPPFLAGS) -o $@ $^

$(D_TESTS)/test-Lexer.out: $(D_TESTS)/test-Lexer.cpp Lexer.o
	$(CPPC) $(CPPFLAGS) -o $@ $^

$(D_TESTS)/test-Env.out: $(D_TESTS)/test-Env.cpp Env.o
	$(CPPC) $(CPPFLAGS) -o $@ $^


.PHONY: clean test

test: $(D_TESTS)/test-Parser.out $(D_TESTS)/test-Lexer.out
	@$(D_TESTS)/test-Parser.out
	@$(D_TESTS)/test-Lexer.out
	@$(D_TESTS)/test-Env.out

clean:
	find . -name "*.out" -delete
	find . -name "*.o" -delete
	find . -name "*.s" -delete
