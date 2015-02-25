#include <assert.h>
#include <iostream>
#include <utility>
#include <map>
#include <set>
#include <string>

#include "../dfa.h"

using namespace std;

/**
 * DFA that accepts any string with AB substring.
 */
void test1 ()
{
  int start = 0;
  dfa_tmap transition =
  {
    {make_pair(0, 'a'), 2},
    {make_pair(0, 'b'), 0},
    {make_pair(1, 'a'), 1},
    {make_pair(1, 'b'), 1},
    {make_pair(2, 'a'), 2},
    {make_pair(2, 'b'), 1},
  };
  set<int> final_states {1};

  Dfa dfa (start, transition, final_states);

  assert(dfa.validate("ab"));
  assert(dfa.validate("aab"));
  assert(dfa.validate("aaba"));

  assert(!dfa.validate("ba"));
  assert(!dfa.validate("a"));
  assert(!dfa.validate(" "));
}

int main(int argc, char const *argv[])
{
  test1();

  return 0;
}
