#ifndef NFA_H
#define NFA_H

#include <string>
#include <vector>
#include <iostream>
#include "common.h"
#include "dfa.h"

const int NFA_EPS = -9999;

/**
 * Differently from the DFA, NFAs have the
 * ability to be in several states at once (even
 * if no input provided - through epslon
 * transitions). This difference comes from the
 * transition function: transitions from a state
 * on an input can be to any set of states.
 *
 * For any NFA there is a DFA that accepts the
 * same language (by subset construction)
 */

/**
 * Given two sets, returns the union of them.
 */

class Nfa {
public:
  int initial_state;
  nfa_tmap transitions;
  s_states final_states;
  string alphabet;
  Dfa compiled_dfa;
  bool compiled;


  // without alphabet
  Nfa (int s, nfa_tmap t, s_states f) :
    initial_state(s), transitions(t), final_states(f),
    alphabet(" "), compiled(false)
  {}

  // with alphabet
  Nfa (int s, nfa_tmap t,
       s_states f, string aAlphabet) :
    initial_state(s), transitions(t), final_states(f),
    alphabet(aAlphabet), compiled(false)
  {}

  void add_transition (int from, char input, s_states to);
  inline void set_final_states (s_states fs) {
    final_states = fs;
  }
  inline void set_transition (pair<int, char> key, s_states value) {
    transitions[key] = value;
  }

  inline void set_alphabet (string aAlphabet) {
    alphabet = aAlphabet;
  }

  bool validate (string input);

  /**
   * 1. Create the start state of the DFA by
   * taking the eps-closure of the start state
   * of the NFA.
   *
   * 2. for the new DFA state: for each possible
   * input symbol:
   *
   * 2.1. apply 'move' to the newly-created
   * state and the input symbol (returns a set
   * of states)
   *
   * 2.2. apply the eps-closure to this set of
   * states, possibly returning in a new set.
   *
   * 3. Redo 2 until it stops yielding NEW
   * states
   *
   * 4. The finish states of the DFA are those
   * which contain any of the finish states of
   * the NFA
   */
  Dfa convert ();

  void show_nfa ();

  /**
   * Given a list of states the closure set is
   * all the sets that can be reached without
   * any input, including the input states
   * themselves
   */
  s_states closure (s_states states);

  /**
   * Given a set of states and an input symbol,
   * finds all the states reachable by
   * traversing those edges that require the
   * given input symbol
   */
  s_states move (s_states states, char input_char);
private:
  /**
   * Verifies if, in the set (states), there's a
   * final state
   */
  bool has_final_state (s_states& states);

  /**
   * Given a state, assigns to the output a set
   * of all of the results of trans(state,
   * NFA_EPS) - adjacent eps moves.
   */
  s_states adj_closure (s_states& states, s_states& visited);
  /**
   * Same as the other, but with a visited list
   * (used internally).
   */
  s_states closure (s_states& states, s_states visited);
};


#endif
