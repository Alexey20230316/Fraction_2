#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	
	Fraction(int numerator, int denominator)  // создает обьект с сокращенной дробью
	{
		numerator_ = numerator;      // числитель
		denominator_ = denominator; // знаменатель
		int bye = 1;
		while (bye)
		{
			if (!(numerator_ % 2) && !(denominator_ % 2))
			{
				numerator_ = numerator_ / 2;
				denominator_ = denominator_ / 2;
			}
			else if (!(numerator_ % 3) && !(denominator_ % 3))
			{
				numerator_ = numerator_ / 3;
				denominator_ = denominator_ / 3;
			}
			else if (!(numerator_ % numerator_) && !(denominator_ % numerator_) && (numerator_ > 1))
			{
				denominator_ = denominator_ / numerator_;
				numerator_ = numerator_ / numerator_;
			}
			else if (!(numerator_ % denominator_) && !(denominator_ % denominator_) && (denominator_ > 1))
			{
				numerator_ = numerator_ / denominator_;
				denominator_ = denominator_ / denominator_;
			}
			else { bye = 0; }
		}
	}

	void set_numerartot(int a)
	{
		numerator_ = a;
	}
	void set_denominator(int b)
	{
		denominator_ = b;
	}

	int get_numerator_()
	{
		return numerator_;
	}
	int get_denominator_()
	{
		return denominator_;
	}


	Fraction operator + (const Fraction& other) const
	{
		int i = 1;

		int a = this->numerator_;
		int b = this->denominator_;

		int c = other.numerator_;
		int d = other.denominator_;
		int byi = 1;

		while (byi)
		{
			if ((b * i) % d)
			{
				i++;
			}
			else
			{
				byi = 0;
			}
		}

		a = a * i;
		b = b * i;
		c = c * (b / d);
		d = b;
		
		return Fraction(a + c, d);
		
	}

	Fraction operator - (const Fraction& other) const
	{
		int i = 1;

		int a = this->numerator_;
		int b = this->denominator_;

		int c = other.numerator_;
		int d = other.denominator_;
		int byi = 1;

		while (byi)
		{
			if ((b * i) % d)
			{
				i++;
			}
			else
			{
				byi = 0;
			}
		}

		a = a * i;
		b = b * i;
		c = c * (b / d);
		d = b;

		return Fraction(a - c, d);

	}

	Fraction operator * (const Fraction& other) const
	{
		return Fraction(this->numerator_ * other.numerator_,
			            this->denominator_ * other.denominator_);
	}

	Fraction operator / (const Fraction& other) const
	{
		int a = this->numerator_;
		int b = this->denominator_;

		int c = other.numerator_;
		int d = other.denominator_;

		return Fraction(a*d, b*c);
	}

	Fraction operator=(const Fraction& other)
	{
		numerator_ = other.numerator_;
		denominator_ = other.denominator_;
		return *this;
	}

	Fraction& operator ++()
	{
		this->numerator_ = this->numerator_ + this->denominator_;
		return *this;
	}

	Fraction& operator ++(int h)
	{
		Fraction temp = *this;
		this->numerator_ = this->numerator_ + this->denominator_;
		return temp;
	}

	Fraction& operator --()
	{
		this->numerator_ = this->numerator_ - this->denominator_;
		return *this;
	}

	Fraction& operator --(int h)
	{
		Fraction temp = *this;
		this->numerator_ = this->numerator_ - this->denominator_;
		return temp;
	}

};


void foo_plus(Fraction f1, Fraction f2, Fraction f3);
void foo_minys(Fraction f1, Fraction f2, Fraction f3);
void foo_umn(Fraction f1, Fraction f2, Fraction f3);
void foo_del(Fraction f1, Fraction f2, Fraction f3);
void foo_umn_min_pref(Fraction f1, Fraction f2, Fraction f3);
void foo_umn_plus_pref(Fraction f1, Fraction f2, Fraction f3);
void foo_umn_min_post(Fraction f1, Fraction f2, Fraction f3);
void foo_umn_plus_post(Fraction f1, Fraction f2, Fraction f3);

int a, b, c, d = 0;

int main()
{

	setlocale(LC_ALL, "Russian");

	
	std::cout << "¬ведите числитель дроби 1: ";
	std::cin >> a;
	std::cout << "¬ведите знаменатель дроби 1: ";
	std::cin >> b;
	std::cout << "¬ведите числитель дроби 2: ";
	std::cin >> c;
	std::cout << "¬ведите знаменатель дроби 2: ";
	std::cin >> d;


	Fraction f1(a,b);
	Fraction f2(c,d);
	
	
	Fraction f3 = f1 + f2;
	foo_plus(f1, f2, f3);
	f3 = f1 - f2;
	foo_minys(f1, f2, f3);
	f3 = f1 * f2;
	foo_umn(f1, f2, f3);
	f3 = f1 / f2;
	foo_del(f1, f2, f3);

	f3 = --f1 * f2;
	foo_umn_min_pref(f1, f2, f3);
	f1.set_numerartot(a);
	f1.set_denominator(b);
	f3 = ++f1 * f2;
	foo_umn_plus_pref(f1, f2, f3);
	f1.set_numerartot(a);
	f1.set_denominator(b);
	f3 = f1-- * f2;
	foo_umn_min_post(f1, f2, f3);
	f1.set_numerartot(a);
	f1.set_denominator(b);
	f3 = f1++ * f2;
	foo_umn_plus_post(f1, f2, f3);
	
	
	

	return 0;
}


void foo_plus(Fraction f1, Fraction f2, Fraction f3)
{
	std::cout << f1.get_numerator_() << "/" << f1.get_denominator_() << " + "
		<< f2.get_numerator_() << "/" << f2.get_denominator_()
		<< " = " << f3.get_numerator_() << "/" << f3.get_denominator_() << std::endl;
}
void foo_minys(Fraction f1, Fraction f2, Fraction f3)
{
	std::cout << f1.get_numerator_() << "/" << f1.get_denominator_() << " - "
		<< f2.get_numerator_() << "/" << f2.get_denominator_() << " = "
		<< f3.get_numerator_() << "/" << f3.get_denominator_() << std::endl;
}
void foo_umn(Fraction f1, Fraction f2, Fraction f3)
{
	std::cout << f1.get_numerator_() << "/" << f1.get_denominator_() << " * "
		<< f2.get_numerator_() << "/" << f2.get_denominator_()
		<< " = " << f3.get_numerator_() << "/" << f3.get_denominator_() << std::endl;
}
void foo_del(Fraction f1, Fraction f2, Fraction f3)
{
	std::cout << f1.get_numerator_() << "/" << f1.get_denominator_() 
		<< " / " << f2.get_numerator_() << "/" << f2.get_denominator_() <<
		" = " << f3.get_numerator_() << "/" << f3.get_denominator_() << std::endl;
}
void foo_umn_min_pref(Fraction f1, Fraction f2, Fraction f3)
{
	std::cout << "--" << a << "/" << b << " * "
		<< f2.get_numerator_() << "/" << f2.get_denominator_()
		<< " = " << f3.get_numerator_() << "/" << f3.get_denominator_() << std::endl;
	std::cout << "ƒробь номер один после префиксного декримента равна: "
		<< f1.get_numerator_() << "/" << f1.get_denominator_() << std::endl;
}
void foo_umn_plus_pref(Fraction f1, Fraction f2, Fraction f3)
{
	std::cout << "++" << a << "/" << b << " * "
		<< f2.get_numerator_() << "/" << f2.get_denominator_()
		<< " = " << f3.get_numerator_() << "/" << f3.get_denominator_() << std::endl;
	std::cout << "ƒробь номер один после префиксного инкремента равна: " 
		<< f1.get_numerator_() << "/" << f1.get_denominator_() << std::endl;
}
void foo_umn_min_post(Fraction f1, Fraction f2, Fraction f3)
{
	std::cout << a << "/" << b << "--" << " * "
		<< f2.get_numerator_() << "/" << f2.get_denominator_()
		<< " = " << f3.get_numerator_() << "/" << f3.get_denominator_() << std::endl;
	std::cout << "ƒробь номер один после постфиксного декремента равна: "
		<< f1.get_numerator_() << "/" << f1.get_denominator_() << std::endl;
}
void foo_umn_plus_post(Fraction f1, Fraction f2, Fraction f3)
{
	std::cout << a << "/" << b << "++" << " * "
		<< f2.get_numerator_() << "/" << f2.get_denominator_()
		<< " = " << f3.get_numerator_() << "/" << f3.get_denominator_() << std::endl;
	std::cout << "ƒробь номер один после постфиксного инкремента равна: "
		<< f1.get_numerator_() << "/" << f1.get_denominator_() << std::endl;
}