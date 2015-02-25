#include "../nfa.h"
#include "../dfa.h"
#include <iostream>
#include <assert.h>

using namespace std;

// tests closure with a single eps along
void test_closure_1 ()
{
  // initialization
  const int start = 1;
  nfa_tmap transitions =
  {
    {make_pair(1, 'x'), s_states {2}},
    {make_pair(2, NFA_EPS), s_states {1}},
  };
  const s_states final_states {2};

  Nfa nfa (start, transitions, final_states);

  // assertion

  s_states states {1};
  s_states result = nfa.closure(states);

  assert(result.count(1));
  assert(!result.count(2));
}

/**
 * tests closure that has to follow eps moves:
 *
 * 1---x--->2---y--->3--y-->4*
 * └─--e----|─---e---|
 */
void test_closure_2 ()
{
  const int start = 1;
  nfa_tmap transitions =
  {
    {make_pair(1,'x'), s_states {2}},
    {make_pair(1,'y'), s_states {}},
    {make_pair(1,NFA_EPS), s_states {2}},

    {make_pair(2,'x'), s_states {}},
    {make_pair(2,'y'), s_states {3}},
    {make_pair(2,NFA_EPS), s_states {3}},

    {make_pair(3,'x'), s_states {}},
    {make_pair(3,'y'), s_states {4}},
    {make_pair(3,NFA_EPS), s_states {}},

    {make_pair(4,'x'), s_states {}},
    {make_pair(4,'y'), s_states {}},
    {make_pair(4,NFA_EPS), s_states {}},
  };
  const s_states final_states {4};

  Nfa nfa (start, transitions, final_states);

  // assertion

  s_states result = nfa.closure(s_states {1});

  assert(result == s_states({1, 2, 3}));
}

/**
 * Should handle well cyclic eps-transitions
 *
 * |--e-->|
 * 1--x-->2*
 * |<-e---|
 */
void test_closure_3 ()
{
  const int start = 1;
  nfa_tmap transitions =
  {
    {make_pair(1, 'x'), s_states {2}},
    {make_pair(1, NFA_EPS), s_states {2}},

    {make_pair(2, 'x'), s_states {}},
    {make_pair(2, NFA_EPS), s_states {1}},
  };
  const s_states final_states {2};

  Nfa nfa (start, transitions, final_states);

  s_states states {1};
  s_states result = nfa.closure(states);

  assert(result.count(1));
  assert(result.count(2));
}

/**
 * 1---x--->2---y--->3--y-->4*
 * └─--e----|─---e---|
 */
void test_move_1 ()
{
  const int start = 1;
  nfa_tmap transitions =
  {
    {make_pair(1,'x'), s_states {2}},
    {make_pair(1,'y'), s_states {}},
    {make_pair(1,NFA_EPS), s_states {2}},

    {make_pair(2,'x'), s_states {}},
    {make_pair(2,'y'), s_states {3}},
    {make_pair(2,NFA_EPS), s_states {3}},

    {make_pair(3,'x'), s_states {}},
    {make_pair(3,'y'), s_states {4}},
    {make_pair(3,NFA_EPS), s_states {}},

    {make_pair(4,'x'), s_states {}},
    {make_pair(4,'y'), s_states {}},
    {make_pair(4,NFA_EPS), s_states {}},
  };
  const s_states final_states {2};
  Nfa nfa (start, transitions, final_states);

  assert(nfa.move(s_states {1}, 'x') == s_states {2});
  assert(nfa.move(s_states {1}, 'y') == s_states {});
  assert(nfa.move(s_states {2}, 'y') == s_states {3});
  assert(nfa.move(s_states {2, 3}, 'y') == s_states({3, 4}));

}

/**
 * Verifies if a converted NFA->DFA actually
 * does what the NFA or a DFA would do
 */
void test_convert_1 ()
{
  dfa_tmap transitions =
  {
    {make_pair(0, '0'), 1},
    {make_pair(0, '1'), 0},

    {make_pair(1, '0'), 1},
    {make_pair(1, '1'), 2},

    {make_pair(2, '0'), 1},
    {make_pair(2, '1'), 0},
  };

  Dfa dfa (0, transitions,s_states {2});

  assert(dfa.validate("01"));
  assert(dfa.validate("001"));
  assert(dfa.validate("01001"));
  assert(!dfa.validate("0"));
  assert(!dfa.validate("1"));
  assert(!dfa.validate("10"));
  assert(!dfa.validate("1110"));

  nfa_tmap nfa_trans =
  {
    {make_pair(0, '0'), s_states {1,0}},
    {make_pair(0, '1'), s_states {0}},

    // {make_pair(1, '0'), s_states {}},
    {make_pair(1, '1'), s_states {2}},

    // {make_pair(2, '0'), s_states {}},
    // {make_pair(2, '1'), s_states {}},
  };
  Nfa nfa (0, nfa_trans, s_states {2}, "01");

  assert(nfa.closure(s_states {0}) == s_states {0});
  assert(nfa.closure(s_states {1,0}) == s_states ({1,0}));
  assert(nfa.closure(nfa.move(s_states {1,0}, '0')) == s_states({1, 0}));
  assert(nfa.closure(nfa.move(s_states {1,0}, '1')) == s_states({2, 0}));

  Dfa converted_dfa = nfa.convert();

  assert(converted_dfa.validate("01"));
  assert(converted_dfa.validate("001"));
  assert(converted_dfa.validate("01001"));
  assert(!converted_dfa.validate("0"));
  assert(!converted_dfa.validate("1"));
  assert(!converted_dfa.validate("10"));
  assert(!converted_dfa.validate("1110"));
}

/**
 * Tests wheter NFA->DFA conversion works for
 * NFAs with epslon moves.
 *
 * The nfa: x+ -> accepts 'x' one time or more
 */
void test_convert_2 ()
{
  nfa_tmap nfa_trans =
  {
    {make_pair(1, 'x'), {2}},
    {make_pair(2, NFA_EPS), {1}}
  };
  Nfa nfa (1, nfa_trans, s_states {2}, "x");

  Dfa dfa = nfa.convert();

  assert(!dfa.validate(""));
  assert(dfa.validate("x"));
  assert(dfa.validate("xx"));
  assert(dfa.validate("xxxxxxxxxx"));
  assert(!dfa.validate("xy"));
  assert(!dfa.validate("yx"));
}

/**
 * When trying to validate, should throw an
 * error if no previously compiled DFA is found
 * for the NFA.
 */
void test_validate_1 ()
{
  nfa_tmap transitions = {
    {make_pair(1, 'a'), {2}},
    {make_pair(2, 'b'), {3}},
  };
  Nfa nfa (1, transitions, s_states {3}, "ab");

  assert(nfa.validate("ab"));
  assert(!nfa.validate("aa"));
}

/**
 * Validate a kleene-star over 'a' (i.e.: a*)
 */
void  test_validate_2 ()
{
  nfa_tmap nfa_trans =
  {
    {make_pair(0, NFA_EPS), s_states {1,3}},
    {make_pair(1, 'a'), s_states {2}},
    {make_pair(2, NFA_EPS), s_states {1,3}},
  };

  Nfa nfa (0, nfa_trans, s_states {3}, "a");

  assert(nfa.validate("a"));
  assert(nfa.validate("aa"));
  assert(nfa.validate("aaaa"));
  // assert(nfa.validate("")); // FIX
  assert(!nfa.validate("b"));
}

void test_validate_3 ()
{
  nfa_tmap transitions =
  {
    {make_pair(0, 'a'), s_states {2}},
    {make_pair(2, 'b'), s_states {3}},
  };

  Nfa nfa (0, transitions, s_states {3}, "ab");

  assert(nfa.validate("ab"));
  assert(!nfa.validate("a"));
  assert(!nfa.validate("b"));
  assert(!nfa.validate("aa"));
  assert(!nfa.validate("bb"));
}

int main(int argc, char const *argv[])
{

  test_closure_1();
  test_closure_2();
  test_closure_3();

  test_move_1();

  test_convert_1();
  test_convert_2();

  test_validate_1();
  test_validate_2();
  test_validate_3();

  return 0;
}
