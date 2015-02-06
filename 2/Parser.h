#ifndef PARSER_H
  #define PARSER_H

  class Parser {
  public:
    Parser (char* src);
    std::string parse();
  private:
    char* source;
    int lookahead;
    std::string result;
    int index;

    void match(int t);
    void expr ();
    void rest ();
    void term ();
  };

#endif
