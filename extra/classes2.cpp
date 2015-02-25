#include <iostream>
using std::cin;
using std::cout;
using std::endl;

namespace Chrono {
  enum class Month {jan = 1, fab, mar, apr, may, jun, jul, aug, sep, nov, dec};

  class Date {
  public:
    class Bad_date {};  // for exceptions
    // using default parameters is not optimal but
    // it lets us be very clear of what we're
    // covering.
    explicit Date(int dd = {}, Month mm = {}, int yy = {});

    inline int day() const {return d;}
    inline Month month() const {return m;}
    inline int year() const {return y;}

    string string_rep() const;
    void char_rep(char s[], int max) const;

    Date& add_year(int n);
    Date& add_month(int n);
    Date& add_day(int n);

  private:
    bool is_valid();
    int d, m, y;
  };

  bool is_date(int d, Month m, int y);
  bool is_leapyear(int y);

  bool operator==(const Date& a, const Date& b);
  bool operator!=(const Date&a, const Date& b);

  // a default date getter
  const Date& default_date();

  // write from D into OS
  ostream& operator<<(ostream& os, const Date& d);
  // read from IS into D
  istream& operator>>(istream& is, const Date& d);
}

// the constructor will establish the invariant
// for the class so that future copies are done
// without further checking
Date::Date (int dd, Month mm, int yy)
  : d(dd), m(mm), y(yy)
{
  if (!y) y = default_date().year();
  // making it clear that we catch the fact that
  // the user has not entered a valid enumered
  // month (de default for this enum would be
  // zero, which does not makes sense)
  if (m == Month{}) m = default_date().month();
  if (!d) d = default_date().day();

  if (!is_valid())
    throw Bad_date();
}

/**
 * Checks whether the current values represents
 * a valid date. In this case, not checking if
 * it is a possible date ({1,1,0000} could be a
 * date but not a valid one).
 */
bool Date::is_valid ()
{
  return is_date(d, m, y);
}

int main(int argc, char const *argv[])
{
  Date date1 {10, Month::mar, 2000};

  cout << "current day: " << d << endl;
  cout << "day after: " << d+1 << endl;

  Date dd;
  cin >> dd;

  cout << dd;
  return 0;
}
