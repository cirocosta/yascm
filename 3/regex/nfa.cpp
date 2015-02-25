#include "nfa.h"
#include "../MapBySet.h"

void Nfa::show_nfa ()
{
  cout << endl;
  cout << "---------" << endl;
  cout << "initial: " << initial_state << endl
       << "alphabet: " << alphabet << endl
       << "final: ";
  show_s_states(final_states);

  cout << "compiled: " << compiled << endl
       << "transitions: " << endl;

  for (nfa_tmap::iterator it = transitions.begin();
       it != transitions.end();
       it++) {
    cout << it->first.first << ":'" << it->first.second << "' | ";
    show_s_states(it->second);
  }

  cout << endl
       << "----------" << endl
       << endl;
}

s_states Nfa::adj_closure (s_states& states, s_states& visited)
{
  s_states::iterator it;
  s_states output;

  for (it = states.begin(); it != states.end(); it++) {
    pair<int, char> t_pair = make_pair(*it, NFA_EPS);

    if (visited.count(*it))
      continue;

    if (transitions.count(t_pair))
      assign(output, transitions[t_pair]);
  }

  assign(visited, states);

  return output;
}

s_states Nfa::closure (s_states& states, s_states visited)
{
  s_states adjs = adj_closure(states, visited);

  if (adjs.empty())
    return states;

  assign(states, closure(adjs, visited));
  return states;
}

s_states Nfa::closure (s_states states)
{
  return closure(states, s_states {});
}

s_states Nfa::move (s_states states, char input_char)
{
  s_states::iterator it = states.begin();
  s_states reach;

  while(it != states.end())
    assign(reach, transitions[make_pair(*it++, input_char)]);

  return reach;
}

bool Nfa::has_final_state (s_states& states)
{
  s_states::iterator it = states.begin();

  while (it != states.end())
    if (final_states.count(*it++))
      return true;

  return false;
}

bool Nfa::validate (string input)
{
  if (!compiled)
    convert();

  return compiled_dfa.validate(input);
}

Dfa Nfa::convert ()
{
  // counter of the dfa states
  int counter = 0;
  // set of final_states
  s_states final_states;
  // keeps track of new states
  vector<s_states> new_states;
  // maps: set_of_states --> dfa_state_number. If
  // a dfa_state_number is zero, then nothing is
  // there (min-value = 1).
  MapBySet states_map = {
    {closure(s_states {initial_state}), ++counter}
  };
  // holds the dfa transitions being generated
  dfa_tmap dfa_transitions;

  new_states.push_back(closure(s_states {initial_state}));

  while (!new_states.empty()) {
    s_states state = new_states.back();
    new_states.pop_back();
    // if we already mapped, take the map value,
    // otherwise, use the counter
    int current_state = states_map[state];

    if (!current_state)
      current_state = ++counter;

    // simulate nfa travel
    for (char& c : alphabet) {
      s_states new_state = closure(move(state, c));
      // search for the state in the map
      int mapped_new_state = states_map[new_state];

      // current state has never been mapped
      // before
      if (!mapped_new_state) {
        states_map[new_state] = ++counter;
        new_states.push_back(new_state);
        mapped_new_state = counter;
      }

      dfa_transitions[make_pair(current_state, c)] = mapped_new_state;

      if (has_final_state(new_state))
        final_states.insert(mapped_new_state);
    }
  }

  compiled_dfa = Dfa (1, dfa_transitions, final_states);

  return compiled_dfa;
}
