#include <iostream>
#include <string>
// 李俊尚原创代码，学习抽象基类和纯虚函数，以图书销量为例
class Base {
protected:
    std::string title;// 书或杂志名
public:
    void setTitle(const std::string& t) { title = t; }
    void showTitle() const { std::cout << "标题：" << title << std::endl; }
    // 纯虚函数（让该类成为抽象类）
    virtual bool isGood() const = 0;
};
// 图书类 Book
class Book : public Base {
private:
    int monthlySales; // 每月销售量
public:
    Book(const std::string& t, int sales) {
        title = t;
        monthlySales = sales;
    }
    bool isGood() const override
    {
        return monthlySales > 500;
    }
};
// 杂志类 Journal
class Journal : public Base {
private:
    int monthlySales;
public:
    Journal(const std::string& t, int sales) {
        title = t;
        monthlySales = sales;
    }

    bool isGood() const override
    {
        return monthlySales > 2500;
    }
};
int main() {
    Book b1("C++ 程序设计", 800);
    Journal j1("科学杂志", 2000);

    b1.showTitle();
    std::cout << "是否畅销: " << (b1.isGood() ? "是" : "否") << std::endl;

    j1.showTitle();
    std::cout << "是否畅销: " << (j1.isGood() ? "是" : "否") << std::endl;

    return 0;
}
