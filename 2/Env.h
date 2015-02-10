#ifndef ENV_V
#define ENV_H

/**
 * Env declares the notion of an environment,
 * which describes a collection of symbol tables
 * that are relevant at a point in the program.
 *
 * This one complies with the 'most-closely
 * nested' rule for blocks: an identifier X is
 * in the scope of the most-closely nested
 * declaration of X (examining blocks
 * inside-out, starting with the block in which
 * X appears). This is achieved by chaining
 * symbol tables.
 */

#include <unordered_map>

using namespace std;

/**
 * A symbol. It, actually, should contain a
 * bunch of fields, but here we limit to only
 * the 'type' field for brevity.
 */
class Symbol {
public:
  Symbol (string aType) : type(aType) {}
protected:
  string type;
};

class Env {
public:
  Env(Env p);

  /**
   * Gets a symbol from the table
   * @param  s [description]
   * @return   [description]
   */
  Symbol get (string s);
  /**
   * Inserts a symbol into the table
   * @param s symbol name
   * @param symnol symbol object
   */
  void put (string s, Symbol sym);

private:
  /**
   * Represents the actual symbol table
   */
  unordered_map<string, Symbol> table;
protected:
  /**
   * Reference to the previous symbol table
   */
  Env prev;
};

#endif
