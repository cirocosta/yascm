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
  #include <iostream>

  class Token {
  public:
    int tag;
    Token(int t);
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
    Word (int t, std::string s);
  };
#endif
