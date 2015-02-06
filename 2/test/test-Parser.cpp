#include <iostream>
#include "../Parser.h"

using namespace std;

/**
 * Asserts that a given input produces the
 * correct parsing one.
 * @param  source   input (infix)
 * @param  expected expect postfix
 * @param  ann      annotation
 */
inline void assert(char* source, string expected, string const ann)
{
  Parser parser (source);

  if (expected.compare(parser.parse()))
    cerr << ann << endl;
}


int main(int argc, char const *argv[])
{
  assert((char *)"1", "1", "positive number");
  // assert((char *)"-1", "-1", "negative number");
  assert((char *)"1+1", "11+", "simple addition");
  assert((char *)"2+3+4", "23+4+", "simple addition");
  // assert((char *)"1 + 1", "11+", "simple addition with whitechars");
  // assert((char *)"(1+1)", "11+", "simple addition with brackets");
  // assert((char *)"(1 + 1)", "11+", "simple addition with brackets and white chars");

  // assert((char *)"52+(1+2)*4-3", "52 1 2 + 4 * 3 -", "hard");
  // assert((char *)"52+((1+2)*4)-3", "52 1 2 + 4 * 3 -", "hard");
  // assert((char *)"(52+1+2)*4-3", "52 1 + 2 + 4 * 3 -", "hard");

	return 0;
}
