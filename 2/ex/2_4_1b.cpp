/**
 * parses:
 *
 * S -> S ( S ) S | eps
 * which becomes (removing left recursion):
 *
 * S -> R
 * R -> '('S')'SR | eps
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

void R ();
void S () {
	R();
}

void R () {
	if (lookahead != '(')
		return;

	switch (lookahead) {
		case '(':
		match('(');
		S();
		break;

		case ')':
		match(')');
		S();
		R();
		break;

		default:
		fprintf(stderr, "R: Syntax Error.\n");
	}
}

int main(int argc, char const *argv[])
{
	cout << "Enter expressions following the specified grammar:" << endl;

	while(1) {
		printf("> ");
		fflush(stdout);
		updateLookahead();
		S();
	}

	return 0;
}
