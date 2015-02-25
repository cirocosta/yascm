/**
 * parses:
 *
 * expr  -> expr + term     {print('+')}
 *       |  expr - term     {print('-')}
 *       |  term
 *
 * term  -> term * factor   {print('*')}
 *       |  term / factor   {print('/')}
 *       |  factor
 *
 * factor-> '(' expr ')'
 *       |  num             {print(num.value)}
 *       |  id              {print(id.lexeme)}
 *
 * id    ->
 *
 * num   -> 0 | 1 | ... | 9 {print()}
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
 *       | 1   ...
 *         ..
 *       | 9 {print ('9')}
 *       | '('expr')'
 *       | '-' term {print('-')}
 */


#include <iostream>
#include "Parser.h"

using namespace std;

void Parser::match (int t) {
  if (lookahead == t)
    while (lookahead = source[++index], lookahead == ' ')
      continue;
  else
    cerr << "Parser::match: Syntax Error." << endl;
}

void Parser::expr() {
  term();
  rest();
}

void Parser::rest () {
  while (true) {
    if (lookahead == '+') {
      match('+');
      term();
      result+= '+';
      continue;
    } else if (lookahead == '-') {
      match('-');
      term();
      result+= '-';
      continue;
    }

    break;
  }
}

void Parser::term () {
  int la = lookahead;

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
      match(lookahead);
      result+= (char)la;
    break;

    case '-':
      match('-');
      term();
      result += '-';
    break;

    case '(':
      match('(');
      expr();
      match(')');
    break;

    default:
      cerr << "Parser::term: Syntax Error." << endl;
      cerr << "not expected: " << (char)lookahead << endl;
  }
}

string Parser::parse () {
  lookahead = source[index];
  expr();

  return result;
}
