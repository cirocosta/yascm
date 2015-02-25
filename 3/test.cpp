#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;

/**
 * Abstract how we deal with input. We might
 * receive a file (e.g, the location of it) or
 * pure text (through pipe). Abstracting this
 * leads to a great end: testing will be easier
 * (as we don't have to carry about dealing with
 * files - just test that abstraction layer
 * once).
 */

int main(int argc, char const *argv[])
{
  ifstream is ("./tests/sample.txt", ifstream::binary);
  assert(is);

  is.seekg(0, is.end);
  int length = is.tellg();
  is.seekg(0, is.beg);

  char * buffer = new char [5];

  cout << "Reading " << length << " chars" << endl;

  while (is) {
    cout << buffer << endl;
    is.read(buffer, 5);
  }

  cout << "\nfinished" << endl;

  is.close();

  delete[] buffer;

  return 0;
}
