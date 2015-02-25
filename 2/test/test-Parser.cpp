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
  string actual = parser.parse();

  if (expected.compare(actual))
    cerr << "------------" << endl
         << "FAILED: " << ann << "." << endl
         << "Expected: " << expected << endl
         << "Actual: " << actual << endl
         << "------------" << endl;
}


int main(int argc, char const *argv[])
{
  assert((char *)"1", "1", "positive number");
  assert((char *)"1+1", "11+", "simple addition");
  assert((char *)"2+3+4", "23+4+", "simple addition");
  assert((char *)"(1+1)", "11+", "simple addition with brackets");
  assert((char *)"((1+1))", "11+", "simple addition with brackets");
  assert((char *)"((1+1)+1)", "11+1+", "simple addition with brackets");
  assert((char *)"1 + 1", "11+", "simple addition with whitechars");
  assert((char *)"(1 + 1)", "11+", "simple addition with brackets and white chars");
  assert((char *)"-1", "1-", "unary minus");
  assert((char *)"-1-1", "1-1-", "unary minus with binary minus");

	return 0;
}
