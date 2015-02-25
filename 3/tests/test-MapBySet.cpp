#include "../MapBySet.h"
#include <assert.h>

using namespace std;

void test_empty_set ()
{
  MapBySet mymap = {
    {set<int> {}, 10}
  };

  assert(mymap[set<int>{}] == 10);
}

/**
 * A set must be accessible by any permutation
 * of its elements.
 */
void test_set_1 ()
{
  MapBySet mymap = {
    {set<int> {1, 2, 3}, 10}
  };

  assert(mymap[set<int>({1, 2, 3})] == 10);
  assert(mymap[set<int>({3, 2, 1})] == 10);
  assert(mymap[set<int>({3, 1, 2})] == 10);
  assert(mymap[set<int>({2, 1, 3})] == 10);
}

/**
 * Changing an entry from any permutation must
 * affect the others
 */
void test_set_2 ()
{
  MapBySet mymap = {
    {set<int> {1, 2, 3}, 10}
  };

  assert(mymap[set<int>({1, 2, 3})] == 10);
  assert(mymap[set<int>({2, 1, 3})] == 10);

  mymap[set<int>({1, 2, 3})] = 20;

  assert(mymap[set<int>({1, 2, 3})] == 20);
  assert(mymap[set<int>({3, 2, 1})] == 20);
}

int main(int argc, char const *argv[])
{
  test_set_1();
  test_set_2();
  test_empty_set();
  return 0;
}
