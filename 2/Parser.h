#ifndef PARSER_H
  #define PARSER_H

  /**
   * A grammar derives strings by beginning with
   * the start symbol and repeatedly replacing a
   * nonterminal by the body of a production for
   * that nonterminal.
   */

  class Parser {
  public:
    Parser (char* src) : source(src), index(0) {}
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
