#include <iostream>
#include <string>
//李俊尚原创代码，用于创建银行账户并实现存取款
class Account {
private:
    std::string id;     // 账号
    double balance;     // 余额
public:
    // 构造函数
    Account(const std::string& accountId, double initialBalance)
        : id(accountId), balance(initialBalance) {}
    // 获取账号
    std::string getId() const
    {
        return id;
    }
    // 获取余额
    double getBalance() const
    {
        return balance;
    }
    // 存款
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            std::cout << "存款成功: " << amount << " 元\n";
        } else
        {
            std::cout << "存款金额必须大于 0\n";
        }
    }
    // 取款
    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            std::cout << "取款金额必须大于 0\n";
        } else if (amount > balance)
        {
            std::cout << "余额不足，无法取款\n";
        } else
        {
            balance -= amount;
            std::cout << "取款成功: " << amount << " 元\n";
        }
    }
};
int main() {
    // 定义多个账户对象
    Account acc1("1001", 500.0);
    Account acc2("1002", 1000.0);
    Account acc3("1003", 200.0);
    // 对账户进行操作
    std::cout << "账户 " << acc1.getId() << " 初始余额: " << acc1.getBalance() << " 元\n";
    acc1.deposit(200.0);
    acc1.withdraw(100.0);
    std::cout << "账户 " << acc1.getId() << " 当前余额: " << acc1.getBalance() << " 元\n\n";

    std::cout << "账户 " << acc2.getId() << " 初始余额: " << acc2.getBalance() << " 元\n";
    acc2.withdraw(1200.0); // 尝试超额取款
    acc2.deposit(500.0);
    std::cout << "账户 " << acc2.getId() << " 当前余额: " << acc2.getBalance() << " 元\n\n";

    std::cout << "账户 " << acc3.getId() << " 初始余额: " << acc3.getBalance() << " 元\n";
    acc3.deposit(300.0);
    acc3.withdraw(150.0);
    std::cout << "账户 " << acc3.getId() << " 当前余额: " << acc3.getBalance() << " 元\n";
    return 0;
}
