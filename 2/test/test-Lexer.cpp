#include <iostream>
#include <assert.h>
#include "../Lexer.h"
#include "../Tag.h"

using namespace std;

// single id
void test_1 ()
{
  Lexer lex ((char *)"heuhe");
  Token t = lex.scan();

  assert(t.tag == Tag::Id);
}

// multiple ids
void test_2 ()
{
  Lexer lex ((char *)"aaa bbb ccc");
  Token t[] = {
    lex.scan(), lex.scan(), lex.scan()
  };

  for (int i = 0; i < 3; i++)
    assert(t[i].tag == Tag::Id);
}

// simple digit
void test_3 ()
{
  Lexer lex ((char *)"222");
  Token t = lex.scan();

  assert(t.tag == Tag::Num);
  // assert(t.value == 222);
}

void test_4 ()
{
  Lexer lex ((char *)"true");
  Token t = lex.scan();

  assert(t.tag == Tag::True);
}

// multiple tokens
void test_5 ()
{
  Lexer lex ((char *)"aAa false 212 atrue2");
  Token t[] = {
    lex.scan(), lex.scan(), lex.scan(), lex.scan()
  };

  assert(t[0].tag == Tag::Id);
  assert(t[1].tag == Tag::False);
  // would be great to handle the following:
  // assert(t[2].tag == Tag::Num && t[2].value == 212);
  assert(t[2].tag == Tag::Num);
  assert(t[3].tag == Tag::Id);
}

// simple inline comment
void test_6 ()
{
  Lexer lex ((char *)"//this is a coommentary\n");
  Token t = lex.scan();

  assert(t.tag == Tag::Comment);
}

/**
 * inline comments followed by a line with tokens
 */
void test_7 ()
{
  Lexer lex ((char *)"//comments\ntoken true");
  Token t[] = {
    lex.scan(), lex.scan(), lex.scan()
  };

  assert(t[0].tag == Tag::Comment);
  assert(t[1].tag == Tag::Id);
  assert(t[2].tag == Tag::True);
}

/**
 * Multiline comments
 */
void test_8 ()
{
  Lexer lex ((char *)"/*comments\ntoken true*/");
  Token t = lex.scan();

  assert(t.tag == Tag::Comment);
}

/**
 * Multiline comments followed by line with tokens
 */
void test_9 ()
{
  Lexer lex ((char *)"/*comments\ntoken true*/\tfalse");
  Token t[] = {
    lex.scan(), lex.scan()
  };

  assert(t[0].tag == Tag::Comment);
  assert(t[1].tag == Tag::False);
}

int main(int argc, char const *argv[])
{

  test_1();
  test_2();
  test_3();
  test_4();
  test_5();
  test_6();
  test_7();
  test_8();
  test_9();

  return 0;
}
