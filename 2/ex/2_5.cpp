/**
 * parses:
 *
 * expr -> expr + term {print('+')}
 * 	     | expr - term {print('-')}
 * 	     | eps
 * term -> 0 {print ('0')}
 * 			 | 1   ...
 * 			   ..
 * 			 | 9 {print ('9')}
 *
 * Using:
 *
 * A -> Aa | Ab | c
 *   =>
 * A -> cR
 * R -> aR | bR | eps
 * 
 * converts to:
 * 
 * expr -> term rest
 * rest -> + term {print('+')} rest
 *       | - term {print('-')} rest
 *       | eps
 * term -> 0 {print ('0')}
 * 			 | 1   ...
 * 			   ..
 * 			 | 9 {print ('9')}
 */     

#include <iostream>
#include <cstdio>

using namespace std;

int lookahead;

void updateLookahead () {
	lookahead = getchar();
}

void match (int t) {
	if (lookahead == t)
		updateLookahead();
	else
		fprintf(stderr, "match: Syntax Error.\n");
}

void term();
void rest();

void expr() {
	term();
	rest();
}

void rest () {
	// if (lookahead == '+') {
	// 	match('+');
	// 	term();
	// 	cout << '+';
	// 	rest();
	// } else if (lookahead == '-') {
	// 	match('-');
	// 	term();
	// 	cout << '-';
	// 	rest();
	// } else { /* eps */ }
		
	// substituting tail recursion by iteration:

	while (true) {
		if (lookahead == '+') {
			match('+');
			term();
			cout << '+';
			continue;
		} else if (lookahead == '-') {
			match('-');
			term();
			cout << '-';
			continue;
		}

		break;
	}

	// notice: as there's a call to 'rest' only from
	// 'expr', this implementatin could go into
	// 'expr' declaration without a side effect.
}

void term () {
	switch (lookahead) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			cout << (char)lookahead;
			match(lookahead);
		break;

		default:
			fprintf(stderr, "%s\n", "Syntax Error.");
	}
}

int test () {

	return 0;
}

int main(int argc, char const *argv[])
{
	if (argc > 1)
		return test();

	cout << "Enter expressions following the specified grammar:" << endl;

	while(1) {
		printf("> ");
		fflush(stdout);
		updateLookahead();
		expr();
	}

	return 0;
}
