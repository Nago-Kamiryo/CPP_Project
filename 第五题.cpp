#include <iostream>
//李俊尚原创代码，用于实现复数的加减
class Complex {
private:
    double real;   // 实部
    double imag;   // 虚部
public:
    // 构造函数，实部和虚部默认赋值为0
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    // 重载加号运算符
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    // 重载减号运算符
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }
    // 成员函数重载：复数 + 实数（double）
    Complex operator+(double num) const {
        return Complex(real + num, imag);  // 实数虚部为0
    }
    // 成员函数重载：复数 - 实数（double）
    Complex operator-(double num) const {
        return Complex(real - num, imag);
    }

    // 友元函数：重载流插入运算符 <<（输出复数）
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real;
        if (c.imag >= 0) os << "+";  // 虚部为正显式输出'+'
        os << c.imag << "i";
        return os;
    }
    // 友元函数：重载流提取运算符 >>（输入复数）
    friend std::istream& operator>>(std::istream& is, Complex& c) {
        // 输入格式：实部 虚部（例如：3 4 表示3+4i，5 -6表示5-6i）
        is >> c.real >> c.imag;
        return is;
    }
    // 提供获取实部和虚部的接口（用于全局函数中实数与复数的运算）
    double getReal() const { return real; }
    double getImag() const { return imag; }
};

// 全局函数
Complex operator+(double num, const Complex& c)
{
    return Complex(num + c.getReal(), c.getImag());
}
Complex operator-(double num, const Complex& c)
{
    return Complex(num - c.getReal(), -c.getImag());
}

int main() {
    Complex c1, c2, c3;
    std::cout << "请输入第一个复数（实部 虚部）：";
    std::cin >> c1;
    std::cout << "请输入第二个复数（实部 虚部）：";
    std::cin >> c2;
    // 复数与复数运算
    c3 = c1 + c2;
    std::cout << "c1 + c2 = " << c3 << std::endl;
    c3 = c1 - c2;
    std::cout << "c1 - c2 = " << c3 << std::endl;
    // 复数与实数运算
    double num = 3.5;
    c3 = c1 + num;
    std::cout << "c1 + " << num << " = " << c3 << std::endl;
    c3 = num + c1;  // 测试实数 + 复数
    std::cout << num << " + c1 = " << c3 << std::endl;
    c3 = c2 - num;
    std::cout << "c2 - " << num << " = " << c3 << std::endl;
    c3 = num - c2;  // 测试实数 - 复数
    std::cout << num << " - c2 = " << c3 << std::endl;

    return 0;
}