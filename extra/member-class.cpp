#include <iostream>

/**
 * a member class if a class that is defined in
 * the closure of a class. It can only refer to
 * types and static members of its enclosing
 * class (it can refer to members if a reference
 * of the object is passed to it).
 */

template<typename T>
class Tree {
  using value_type = T;
  enum Policy {rb, splay, treeps};
  class Node {
    Node* right;
    Node* left;
    value_type value;
  public:
    void f(Tree*);
  };
  Node* top;
public:
  void g(Tree::Node*p);
};

template<typename T>
void Tree::Node::f(Tree* p)
{
  p->top = right;
  value_type v = left->value;
}

void Tree::g(Tree::Node* p)
{
  p->f(this);
}

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}
