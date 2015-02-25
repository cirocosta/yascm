#include "Buff.h"

char * Buff::consume ()
{
  switch (type) {
    case BuffType::File:

    break;

    case BuffType::Text:
    cout << "not specified." << endl;
    break;
  }
}
