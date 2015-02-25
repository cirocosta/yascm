CPPFLAGS = -Wall -std=c++11 -g
CPPC = g++
D_REGEX = ./regex
D_REGEX_TESTS = $(D_REGEX)/tests

# --
# OBJS
# --

$(D_REGEX)/dfa.o: $(D_REGEX)/dfa.cpp
	@echo "Preparing dfa.o"
	@$(CPPC) $(CPPFLAGS) $^ -c -o $@

$(D_REGEX)/nfa.o: $(D_REGEX)/nfa.cpp
	@echo "Preparing nfa.o"
	@$(CPPC) $(CPPFLAGS) $^ -c -o $@

$(D_REGEX)/regex.o: $(D_REGEX)/regex.cpp
	@echo "Preparing regex.o"
	@$(CPPC) $(CPPFLAGS) $^ -c -o $@


# --
# TEST EXECUTABLES
# --


$(D_REGEX_TESTS)/test-dfa.out: $(D_REGEX_TESTS)/test-dfa.cpp $(D_REGEX)/dfa.o
	@echo "Preparing test-dfa.out"
	@$(CPPC) $(CPPFLAGS) -o $@ $^

$(D_REGEX_TESTS)/test-nfa.out: $(D_REGEX_TESTS)/test-nfa.cpp $(D_REGEX)/nfa.o $(D_REGEX)/dfa.o
	@echo "Preparing test-nfa.out"
	@$(CPPC) $(CPPFLAGS) -o $@ $^

$(D_REGEX_TESTS)/test-regex.out: $(D_REGEX_TESTS)/test-regex.cpp $(D_REGEX)/regex.o $(D_REGEX)/nfa.o $(D_REGEX)/dfa.o
	@echo "Preparing test-regex.out"
	@$(CPPC) $(CPPFLAGS) -o $@ $^

$(D_REGEX_TESTS)/test-common.out: $(D_REGEX_TESTS)/test-common.cpp
	@echo "Preparing test-common.out"
	@$(CPPC) $(CPPFLAGS) -o $@ $^


.PHONY: clean test

test: $(D_REGEX_TESTS)/test-dfa.out $(D_REGEX_TESTS)/test-nfa.out $(D_REGEX_TESTS)/test-regex.out $(D_REGEX_TESTS)/test-common.out
	@echo "Testing: test-common, test-dfa, test-nfa, test-regex"
	@$(D_REGEX_TESTS)/test-common.out
	@$(D_REGEX_TESTS)/test-dfa.out
	@$(D_REGEX_TESTS)/test-nfa.out
	@$(D_REGEX_TESTS)/test-regex.out


clean:
	find . -name "*.out" -delete
	find . -name "*.o" -delete
	find . -name "*.s" -delete
