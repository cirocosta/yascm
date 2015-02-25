#include "../common.h"
#include <assert.h>

void test_assign_1 ()
{
  s_states s1 {1};
  s_states s2 {2};

  assign(s1, s2);
  assert(s1 == s_states({1, 2}));
}

void test_assign_2 ()
{
  s_states s1 {1};
  s_states s2 {};

  assign(s1, s2);
  assert(s1 == s_states({1}));
}

void test_assign_3 ()
{
  s_states s1 {};
  s_states s2 {1};

  assign(s1, s2);
  assert(s1 == s_states({1}));
}

void test_assign_4 ()
{
  s_states s1 {1,2,3};
  s_states s2 {1,2,3,4};

  assign(s1, s2);
  assert(s1 == s_states({1,2,3,4}));
}

void test_assign_5 ()
{
  s_states s1 {1,2};
  s_states s2 {1,2,3};
  s_states s3 {1,2,3,4};
  s_states s4 {1};

  assign(s1, s2, s3, s4);
  assert(s1 == s_states({1,2,3,4}));
  assert(s2 == s_states({1,2,3}));
  assert(s3 == s_states({1,2,3,4}));
  assert(s4 == s_states({1}));
}

int main(int argc, char const *argv[])
{

  test_assign_1();
  test_assign_2();
  test_assign_3();
  test_assign_4();

  return 0;
}
