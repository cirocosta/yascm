#include <iostream>
#include "../Parser.h"

using namespace std;

bool char_arr_eq (char* a, char* b, int length) {
  for (int i = 0; i < length; i++)
    if (a[i] != b[i])
      return false;

  return true;
}

int test_binary () {
  char src[] = "2+3";
  string expected ("23+");
  Parser parser (src, 3);

  return expected.compare(parser.parse());
}

int main(int argc, char const *argv[])
{
  if (test_binary()) {
    cout << "test-Parser failed";

    return EXIT_FAILURE;
  }

	return 0;
}
