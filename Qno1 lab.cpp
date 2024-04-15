#include <iostream>

class Complex {
public:
    explicit Complex(double real = 0.0, double imaginary = 0.0)
        : real(real), imaginary(imaginary) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    Complex operator*(const Complex& other) const {
        double newReal = real * other.real - imaginary * other.imaginary;
        double newImaginary = real * other.imaginary + imaginary * other.real;
        return Complex(newReal, newImaginary);
    }

    bool operator==(const Complex& other) const {
        return real == other.real && imaginary == other.imaginary;
    }

    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& complex) {
        os << '(' << complex.real << ", " << complex.imaginary << 'i' << ')';
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Complex& complex) {
        is >> complex.real >> complex.imaginary;
        return is;
    }

private:
    double real;
    double imaginary;
};

int main() {
    Complex x;
    Complex y(4.3, 8.2);
    Complex z(3.3, 1.1);

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "z: " << z << std::endl;

    x = y + z;
    std::cout << "\nx = y + z: " << y <<" + " << z << " = " << x << std::endl;

    x = y - z;
    std::cout << "\nx = y - z: " << y <<" + " << z << " = " << x << std::endl;

    x = y * z;
    std::cout << "\nx = y * z: " << y <<" + " << z << " = " << x << std::endl;

    return 0;
}
