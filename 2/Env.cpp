#include <unordered_map>
#include "Env.h"

using namespace std;

Env::Env (Env p) : prev(p) {}

Symbol Env::get (string s)
{
  for (Env e = this; e != NULL; e = e.prev) {
    Symbol found = e.table[s];

    if (found)
      return found;
  }

  return NULL;
}

void Env::put (string s, Symbol sym)
{
  table[s] = sym;
}
