/**
 * parses:
 *
 * expr -> expr + term {print('+')}
 *       | expr - term {print('-')}
 *       | eps
 * term -> 0 {print ('0')}
 *       | 1   ...
 *         ..
 *       | 9 {print ('9')}
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
 */


#include <iostream>
#include "Parser.h"

using namespace std;

Parser::Parser (char* src, int src_length) {
  source = src;
  index = 0;
}

void Parser::match (int t) {
  if (lookahead == t)
    lookahead = source[++index];
  else
    fprintf(stderr, "Parser::match: Syntax Error.\n");
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
      result+= (char)la;
      match(lookahead);
    break;

    default:
      fprintf(stderr, "%s\n", "Parser::term: Syntax Error.");
  }
}

string Parser::parse () {
  lookahead = source[index];
  expr();

  return result;
}
