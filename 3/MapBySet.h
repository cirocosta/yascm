#ifndef MAPBYSET_H
#define MAPBYSET_H

#include <unordered_map>
#include <set>

const int PRIME_A = 54059;
const int PRIME_B = 76963;

using namespace std;

unsigned get_set_hash (set<int> s)
{
  char * res = new char[s.size()];
  set<int>::iterator it = s.begin();
  int count = 0;
  unsigned h = 31;

  while (it != s.end())
    res[count++] = *it++;

  while (count--)
    h = (h * PRIME_A) ^ (res[0] * PRIME_B);

  delete[] res;

  return h;
}

struct KeyHash {
  std::size_t operator()(const set<int>& k) const
  {
    return get_set_hash(k);
  }
};

using MapBySet = unordered_map<set<int>, int, KeyHash>;

#endif
