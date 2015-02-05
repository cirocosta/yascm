#include "Lexer.h"

using namespace std;

Token::Token (int t) : tag{t} {}
Num::Num (int v) : Token{T_NUM}, value{v} {}
Word::Word (int t, string s) : Token{t}, lexeme{s} {}
