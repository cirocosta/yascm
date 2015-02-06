#include <iostream>
#include <unordered_map>

using namespace std;

class Item
{
public:
  Item (){}
  Item (string item_name) : name(item_name) {}
  ~Item() {}

  string toString () {
    return name;
  }
private:
  string name;
};

int main(int argc, char const *argv[])
{
  unordered_map<string, Item> items;
  items["ciro"] = Item("ciro");

  Item c;

  if (items.count("ciro")) {
    c = items["ciro"];
  } else {
    c = Item("ciro");
    items["ciro"] = c;
  }

  cout << c.toString() << endl;

  return 0;
}
