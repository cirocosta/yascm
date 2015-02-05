/**
 * parses:
 *
 * S -> + S S
 *    | - S S
 *    | a
 *    
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

void S () {
	switch (lookahead) {
		case '+':
		match('+');
		S();
		S();
		break;

		case '-':
		match('-');
		S();
		S();
		break;

		case 'a':
		match('a');
		break;

		default:
		fprintf(stderr, "S: Syntax Error.\n");
	}
}

int main(int argc, char const *argv[])
{
	cout << "Enter expressions following the grammar:" << endl;
	cout << "S -> '+' S S | '-' S S | 'a'" << endl;

	while(1) {
		printf("> ");
		fflush(stdout);
		updateLookahead();
		S();
	}

	return 0;
}
