#include "Lexer.h"
#include "Tag.h"

using namespace std;
using namespace l_utils;

/**
 * Creates Token objects that have a particular
 * tag(param) attached to it
 */
Token::Token (Tag t) : tag{t} {}
/**
 * Creates a specialized Token for number, setting an
 * integer value to it.
 */
Num::Num (int v) : Token(Tag::Num), value(v) {}

/**
 * Empty constructor for Word
 */
Word::Word () : Token{Tag::Undefined} {}

/**
 * Creates a specialize Token for words, setting
 * an String value to it and also allowing more
 * than one type of tags.
 */
Word::Word (Tag t, string s) : Token{t}, lexeme{s} {}

/**
 * Lexer encapsulates reserved words and
 * provides a ::scan method for scanning input
 * for tokens.
 */
Lexer::Lexer (char *src)
  : line(1), source(src), index(0), peek(' ') {
  words["true"] = Word(Tag::True, "true");
  words["false"] = Word(Tag::False, "false");
}

char Lexer::get_digit ()
{
  return source[index++];
}

/**
 * Process Description:
 *
 * - skip whitespaces
 * - handle numbers
 * - handle reserved words and identifiers
 *
 * - generate the token
 * - reinitialize peek
 * - return token
 */

Token Lexer::scan ()
{
  ////////////////////
  // SCANNING PHASE //
  ////////////////////

  for (;;peek = get_digit()) {
    if (peek == ' ' || peek == '\t')
      continue;
    else if (peek == '\n')
      line++;
    else
      break;
  }

  // COMMENTS

  if (peek == '/') {
    peek = get_digit();

    if (peek == '/') {
      do {
        peek = get_digit();
      } while (peek != '\n');

      return Token(Tag::Comment);
    }

    if (peek == '*') {
      char nextPeek = get_digit();
      do {
        peek = nextPeek;
        nextPeek = get_digit();
      } while (peek != '*' && nextPeek != '/');

      peek = get_digit();
      return Token(Tag::Comment);
    }
  }

  //////////////////////////
  // ACTUAL TOCKENIZATION //
  //////////////////////////

  // NUMBERS

  if (is_digit(peek)) {
    int v = 0;

    do {
      v = 10*v + char_to_int(peek);
      peek = get_digit();
    } while (is_digit(peek));

    return Num(v);
  }

  //IDS OR RESERVED WORDS

  if (is_letter(peek)) {
    string b;

    do {
      b += peek;
      peek = get_digit();
    } while ((is_digit(peek) || is_letter(peek)));

    if (words.count(b))
      return words[b];

    Word w (Tag::Id, b);
    words[b] = w;

    return w;
  }

  cerr << "Lexer::scan - Unexpected End" << endl;
  return Token(Tag::Undefined);
}

