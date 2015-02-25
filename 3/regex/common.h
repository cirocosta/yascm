#ifndef R_COMMON_H
#define R_COMMON_H

#include <set>
#include <map>
#include <utility>
#include <iostream>
#include <exception>

typedef std::set<int> s_states;
typedef std::map<std::pair<int, char>, s_states> nfa_tmap;
typedef std::map<std::pair<int, char>, int> dfa_tmap;

inline void show_s_states (s_states states)
{
  s_states::iterator it = states.begin();

  std::cout << "{";
  while (it != states.end())
    std::cout << " " << *it++ << " ";
  std::cout << "}" << std::endl;
}

template<class T>
void assign(T& a, T& b)
{
  a.insert(b.begin(), b.end());
}

template<class A, class... B>
void assign (A& head, B... tail)
{
  assign(head, tail...);
}


#endif
