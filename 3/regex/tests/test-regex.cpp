#include <assert.h>
#include "../regex.h"

void test_r_single ()
{
  Regex regex;

  Nfa nfa = regex.r_single(1, 2, 'a');

  assert(nfa.validate("a"));
  assert(!nfa.validate("b"));
  assert(!nfa.validate(""));
}

void test_alternate ()
{
  Regex regex;

  Nfa n1 = regex.r_single(2, 3, 'a');
  Nfa n2 = regex.r_single(4, 5, 'b');

  Nfa n3 = regex.r_alternate(1, n1, n2, 6);

  assert(n3.validate("a"));
  assert(n3.validate("b"));
  assert(!n3.validate(""));
  assert(!n3.validate("c"));
}

void test_concatenate ()
{
  Regex regex;

  Nfa n1 = regex.r_single(2, 3, 'a');
  Nfa n2 = regex.r_single(4, 5, 'b');

  Nfa n3 = regex.r_concatenate(n1, n2);

  assert(n3.validate("ab"));
  assert(!n3.validate("a"));
  assert(!n3.validate("b"));
  assert(!n3.validate(""));
  assert(!n3.validate("c"));

  Nfa n4 = regex.r_single(6, 7, 'a');
  Nfa n5 = regex.r_concatenate(n3, n4);

  assert(n5.validate("aba"));
  assert(!n5.validate("ab"));
}

void test_closure ()
{
  Regex regex;

  Nfa n1 = regex.r_single(2, 3, 'a');
  Nfa n3 = regex.r_closure(1, n1, 4);

  // assert(n3.validate(" "));
  assert(n3.validate("a"));
  assert(!n3.validate("b"));
  assert(n3.validate("aa"));
  assert(n3.validate("aaaaa"));
}

/**
 * a(a|b)a
 */
void test_compose_1 ()
{
  Regex regex;

  Nfa n1 = regex.r_single(1, 2, 'a');
  Nfa n2 = regex.r_single(3, 4, 'b');
  Nfa n3 = regex.r_alternate(5, n1, n2, 6);
  Nfa n4 = regex.r_single(7, 8, 'a');
  Nfa n5 = regex.r_single(9, 10, 'a');

  Nfa n6 = regex.r_concatenate(n4, n3);
  Nfa n7 = regex.r_concatenate(n6, n5);

  assert(n6.validate("ab"));
  assert(n6.validate("aa"));

  assert(n7.validate("aaa"));
  assert(n7.validate("aba"));
}

int main(int argc, char const *argv[])
{

  test_r_single();
  test_alternate();
  test_concatenate();
  test_closure();

  test_compose_1();

  return 0;
}
