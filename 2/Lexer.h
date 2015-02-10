/**
 * class Token
 * int tag
 * ---- class Num
 * ---------- int value
 * ---- class Word
 * ---------- string lexeme
 *
 */

#ifndef LEXER_H
#define LEXER_H

#include "Tag.h"
#include <unordered_map>
#include <iostream>

namespace l_utils {

inline bool is_digit (char c)
{
  return c >= 48 && c <= 57;
}

inline bool is_letter (char c)
{
  return (c >= 97 && c <= 122) || (c >= 65 && c <= 90);
}

inline int char_to_int (char c)
{
  return (int)c - 48;
}

} // utils namespace

// TODO: implement virtual method for obtaining
// fields (allow base class pointer polyformism).

class Token {
public:
  Tag tag;
  Token(Tag t);
};

class Num : public Token {
public:
  int value;
  Num (int v);
};

/**
 * Used both for reserved words and
 * identifiers. It expects a lexeme and also a
 * corresponding integer that represents the
 * correct tag.
 */
class Word : public Token {
public:
  std::string lexeme;
  Word ();
  Word (Tag t, std::string s);
};

/**
 * Scans a given input generating tokens from
 * it through its scan method.
 */
class Lexer {
public:
  Lexer(char *src);

  int line;
  void reserve (Word w);
  Token scan();
  char get_digit();

private:
  char* source;
  int index;
  char peek;
  std::unordered_map<std::string, Word> words;
};

#endif
// end lexer_h
