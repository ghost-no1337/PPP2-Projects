#include "../../std_lib_facilities.h"

namespace Chrono {
	enum class Month {
		jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};

	Month& operator++(Month &m);

	class Date {
	public:
		class Invalid { };
		Date(int y, Month m, int d);
		Date();

		int day() const { return d; }
		Month month() const { return m; }
		int year() const { return y; }

		void add_day(int n);
		void add_month(int n);
		void add_year(int n);
	private:
		int y;
		Month m;
		int d;
	};
	bool is_date(int y, Month m, int d);
	bool leapyear(int y);

	int days_in_month(Month m, bool is_leapyear);

	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);

	ostream& operator<<(ostream& os, const Date& d);
	istream& operator>>(istream& is, Date& dd);
}