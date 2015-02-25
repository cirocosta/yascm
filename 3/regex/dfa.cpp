#include <string>
#include <utility>
#include "dfa.h"
#include <iostream>

using namespace std;


void Dfa::show_dfa ()
{
  cout << endl;
  cout << "-----DFA-----" << endl;
  cout << endl;
  cout << "initial_state: " << initial_state << endl;

  s_states::iterator it = final_states.begin();

  cout << "final_states#" << final_states.size() << ": ";
  while (it != final_states.end())
    cout << "(" << *it++ << ") ";
  cout << endl;

  cout << "transition_function:" << endl;

  for (dfa_tmap::iterator iter = transitions.begin();
       iter != transitions.end();
       iter++) {
    cout << iter->first.first << ":'" << iter->first.second << "' | ";
    cout << iter->second << endl;
  }

  cout << endl;
  cout << "-----------" << endl;
  cout << endl;
}

void Dfa::add_final_state (int i)
{
  final_states.insert(i);
}

void Dfa::add_transition (int start_state, int next_state, char c)
{
  transitions[make_pair(start_state, c)] = next_state;
}

bool Dfa::validate(string input)
{
  int state = initial_state;

  for (char& c : input)
    state = transitions[make_pair(state, c)];

  return final_states.count(state) != 0;
}
