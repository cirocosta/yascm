#ifndef REGEX_H
#define REGEX_H

#include <string>
#include <forward_list>
#include "common.h"
#include "nfa.h"

using namespace std;

/**
 * Regular expressions are capable of defining
 * all and only the regular languages.It
 * provides us a declarative way of expressing
 * the strings that we want to accept.
 *
 * Our simple lexical-analyser generator accepts
 * descriptions of the forms of tokens, which
 * are regular expressions that produces a DFA
 * that recognizes which token appears next on
 * the input.
 *
 * Every regular expression has an equivalent
 * NFA and vice-versa. To construct a NFA from a
 * Regular Expression we use Thompson's
 * construction, which uses the idea that we are
 * able to decompose regular expressions into
 * smaller regular expressions.
 */

class Regex {
  string source;
  char lookahead;
  int index = 0;

  bool compiled = false;

  forward_list<Nfa> nfa_stack;
  int counter = 0;
public:
  Nfa final_nfa;

  Regex () {}
  Regex (string i) : source(i) {}

  /**
   * => i->--a--->f*
   */
  Nfa r_single (int init, int final, char input);
  /**
   *
   *       |--e--N(a)--e--|
   * => i->|              |-->f*
   *       |--e--N(b)--e--|
   *
   */
  Nfa r_alternate (int init, Nfa a, Nfa b, int final);
  /**
   * The state state of N(r) becomes the start
   * state of N(a). The final state of N(a)
   * becomes the start state of N(b). The final
   * state of N(r) becomes the final state of
   * N(b).
   *
   * => i-> N(a) -> N(b) -> f*
   */
  Nfa r_concatenate (Nfa a, Nfa b);

  /**
   * Kleene-star over a given Nfa.
   */
  Nfa r_closure (int i, Nfa a, int f);

  void _match (char t);
  void _start();
  void _re ();
  void _re1 ();
  void _c ();
  void _c1 ();
  void _b ();
  void _b1 ();
  void _sim ();

  /**
   * Compiles a given regex string
   */
  void compile();

  /**
   * [match  description]
   * @param  input [description]
   * @return       [description]
   */
  bool match (string input);
};

#endif
