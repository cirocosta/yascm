/**
 * Parser for the CFG:
 * S -> + S S | - S S | a
 */

#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
	/**
	 * Opens a file and associates it with a
	 * stream that can be identified in future
	 * operations by the FILE pointer returned;
	 */
	FILE* fp = fopen("input.txt", "r");
	int c;

	if (!fp) { // if error, null is returned from fopen
		perror("File openning failed");

		return EXIT_FAILURE;
	}

	// getting char till an EOF is reached
	while ((c = fgetc(fp)) != EOF) {
		putchar(c); // writes to stdout
	}

	// verifying if the error indicator associated
	// with the stream is set.
	if (ferror(fp))
		puts("I/O error when reading");
	else if (feof(fp)) // checking EOF indicator
		puts('End of file reached successfully!');

	// disassociating the file
	fclose(fp);

	return 0;
}
