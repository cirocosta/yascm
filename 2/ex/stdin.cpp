#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string input_line;

	ios_base::sync_with_stdio(false);

	while (cin) {
		getline(cin, input_line);
		cout << input_line << endl;
	}

	return 0;
}
