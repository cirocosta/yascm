#include <iostream>

using std::cout;
using std::endl;

/**
 * Tells the number of arguments that the
 * function's template was instantiated with
 */
template<class... T>
size_t f ()
{
  // 'sizeof...' takes the packed arguments and
  // 'returns their count (both for template and
  // 'function args)
  return sizeof...(T);
}

/**
 * Base case for our iteration through recursion
 */
template<class T>
void print (const T& msg)
{
  cout << msg << " ";
}

template<class A, class... B>
void print (A head, B... tail)
{
  print(head);
  print(tail...);
}


/**
 * Tels the number of arguments that the
 * function just received. We call "class... T"
 * the a "template parameter pack", and "T...
 * args" the function parameter pack.
 */
template<class... T>
size_t g(T... args)
{
  return sizeof...(args);
}

int main(int argc, char const *argv[])
{
  cout << "sizeof f<int> " << f<int>() << endl;
  cout << "sizeof f<int, float>" << f<int, float>() << endl;

  cout << "#args: " << g() << endl
       << "#args: " << g(1) << endl
       << "#args: " << g(1,2, 'c', "hue") << endl;

  print("hue", "br", "hueee!", "\n");

  return 0;
}
