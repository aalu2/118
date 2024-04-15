#include <array>
#include <iostream>
#include <string>
#include <cctype>

class HugeInt {
    friend std::ostream& operator<<(std::ostream&, const HugeInt&);

public:
    static const int digits = 100; // Maximum digits in a HugeInt

    HugeInt(long = 0); // Conversion/default constructor
    HugeInt(const std::string&); // Conversion constructor

    HugeInt operator+(const HugeInt&) const; // Addition operator; HugeInt + HugeInt
    HugeInt operator+(int) const; // Addition operator; HugeInt + int
    HugeInt operator+(const std::string&) const; // Addition operator; HugeInt + string

    HugeInt operator*(const HugeInt&) const; // Multiplication operator; HugeInt * HugeInt
    HugeInt operator/(const HugeInt&) const; // Division operator; HugeInt / HugeInt

    bool operator==(const HugeInt&) const; // Equality operator
    bool operator!=(const HugeInt&) const; // Inequality operator
    bool operator<(const HugeInt&) const; // Less than operator
    bool operator>(const HugeInt&) const; // Greater than operator
    bool operator<=(const HugeInt&) const; // Less than or equal to operator
    bool operator>=(const HugeInt&) const; // Greater than or equal to operator

private:
    std::array<short, digits> integer;
}; // end class HugeInt

// HugeInt member-function and friend-function definitions.
HugeInt::HugeInt(long value) {
    // Initialize array to zero
    for (short& element : integer)
        element = 0;

    // Place digits of argument into array
    for (size_t j = digits - 1; value != 0 && j >= 0; j--) {
        integer[j] = value % 10;
        value /= 10;
    }
}

HugeInt::HugeInt(const std::string& number) {
    // Initialize array to zero
    for (short& element : integer)
        element = 0;

    // Place digits of argument into array
    size_t length = number.size();

    for (size_t j = digits - length, k = 0; j < digits; ++j, ++k) {
        if (isdigit(number[k])) // Ensure that character is a digit
            integer[j] = number[k] - '0';
    }
}

HugeInt HugeInt::operator+(const HugeInt& op2) const {
    HugeInt temp; // Temporary result
    int carry = 0;

    for (int i = digits - 1; i >= 0; i--) {
        temp.integer[i] = integer[i] + op2.integer[i] + carry;

        // Determine whether to carry a 1
        if (temp.integer[i] > 9) {
            temp.integer[i] %= 10; // Reduce to 0-9
            carry = 1;
        } else {
            carry = 0;
        }
    }

    return temp; // Return copy of temporary object
}

HugeInt HugeInt::operator*(const HugeInt& op2) const {
    // To be implemented
    return HugeInt(); // Placeholder return
}

HugeInt HugeInt::operator/(const HugeInt& op2) const {
    // To be implemented
    return HugeInt(); // Placeholder return
}

bool HugeInt::operator==(const HugeInt& op2) const {
    // To be implemented
    return false; // Placeholder return
}

bool HugeInt::operator!=(const HugeInt& op2) const {
    // To be implemented
    return false; // Placeholder return
}

bool HugeInt::operator<(const HugeInt& op2) const {
    // To be implemented
    return false; // Placeholder return
}

bool HugeInt::operator>(const HugeInt& op2) const {
    // To be implemented
    return false; // Placeholder return
}

bool HugeInt::operator<=(const HugeInt& op2) const {
    // To be implemented
    return false; // Placeholder return
}

bool HugeInt::operator>=(const HugeInt& op2) const {
    // To be implemented
    return false; // Placeholder return
}

std::ostream& operator<<(std::ostream& output, const HugeInt& num) {
    int i;

    for (i = 0; (i < HugeInt::digits) && (0 == num.integer[i]); ++i)
        ; // Skip leading zeros

    if (i == HugeInt::digits)
        output << 0;
    else
        for (; i < HugeInt::digits; ++i)
            output << num.integer[i];

    return output;
}

// Addition operator; HugeInt + int
HugeInt HugeInt::operator+(int op2) const
{
    // Convert op2 to a HugeInt, then invoke
    // operator+ for two HugeInt objects
    return *this + HugeInt(op2);
}

// Addition operator; HugeInt + string
HugeInt HugeInt::operator+(const std::string& op2) const{
    // Convert op2 to a HugeInt, then invoke
    // operator+ for two HugeInt objects
    return *this + HugeInt(op2);
}

int main() {
    HugeInt n1(7654321);
    HugeInt n2(7891234);
    HugeInt n3("99999999999999999999999999999");
    HugeInt n4("1");
    HugeInt n5;

    std::cout << "n1 is " << n1 << "\nn2 is " << n2
         << "\nn3 is " << n3 << "\nn4 is " << n4
         << "\nn5 is " << n5 << "\n\n";

    n5 = n1 + n2;
    std::cout << n1 << " + " << n2 << " = " << n5 << "\n\n";

    std::cout << n3 << " + " << n4 << "\n= " << (n3 + n4) << "\n\n";

    n5 = n1 + 9;
    std::cout << n1 << " + " << 9 << " = " << n5 << "\n\n";

    n5 = n2 + "10000";
    std::cout << n2 << " + " << "10000" << " = " << n5 << std::endl;
}
