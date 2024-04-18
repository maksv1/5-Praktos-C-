#include <iostream>
#include <iomanip> 
using namespace std;
class BankAccount {

private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accNum, double initialBalance) {
        this->accountNumber = accNum;
        this->balance = initialBalance;
        this->interestRate = 0.0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            this->balance += amount;
            cout << "Пополнение прошло отлично, вот ваш баланс: " << this->balance << endl;
        }
        else {
            cout << "Ошибка: Недопустимая сумма для депозита." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= this->balance) {
            this->balance -= amount;
            cout << "Вывод завершён, текущий баланс: " << this->balance << endl;
        }
        else {
            cout << "Ошибка: Недостаточно средст, либо у вас слишком сильно отличаются цифры." << endl;
        }
    }

    double getBalance() {
        return this->balance;
    }

    double getInterest() {
        return this->balance * this->interestRate * (1.0 / 12.0);
    }

    void setInterestRate(double rate) {
        this->interestRate = rate;
    }

    int getAccountNumber() {
        return this->accountNumber;
    }

    friend bool transfer(BankAccount& from, BankAccount& to, double amount);
};

bool transfer(BankAccount& from, BankAccount& to, double amount) {
    if (amount > 0 && amount <= from.balance) {
        from.balance -= amount;
        to.balance += amount;
        cout << "Перевод успешный: " << endl;
        return true;
    }
    else {
        cout << "Ошибка: недостаточно средст чтобы перевести средства." << endl;
        return false;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int choice;
    BankAccount account1(123456, 1000.0);
    BankAccount account2(654321, 2000.0);

    do {
        cout << "\nБанк аккаунт меню:\n";
        cout << "1. Депозит\n";
        cout << "2. Вывод\n";
        cout << "3. Получит' Баланс\n";
        cout << "4. Рфсчёт и вывод расчёта и вывода % баланса \n";
        cout << "5. Установленная просентная ставка\n";
        cout << "6. Получит' номер счёта \n";
        cout << "7. Перевод\n";
        cout << "8. Выход\n";
        cout << "Сделайте ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            double depositAmount;
            cout << "Введите сумму: ";
            cin >> depositAmount;
            account1.deposit(depositAmount);
            break;
        }
        case 2: {
            double withdrawAmount;
            cout << "Введите сумму вывода: ";
            cin >> withdrawAmount;
            account1.withdraw(withdrawAmount);
            break;
        }
        case 3:
            cout << "Баланс счёта : " << fixed << setprecision(2) << account1.getBalance() << endl;
            break;
        case 4:
            cout << "Заработанные проценты: " << fixed << setprecision(2) << account1.getInterest() << endl;
            break;
        case 5: {
            double interestRate;
            cout << "Введите новую % ставку : ";
            cin >> interestRate;
            account1.setInterestRate(interestRate);
            break;
        }
        case 6:
            cout << "Номер аккаунта " << account1.getAccountNumber() << endl;
            break;
        case 7: {
            double transferAmount;
            cout << "Нажмите Enter, если подтвержаете трансфер: ";
            cin >> transferAmount;
            if (transfer(account1, account2, transferAmount))
                cout << "Трансфер выполнен." << endl;
            else
                cout << "Перевод не успешен." << endl;
            break;
        }
        case 8:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Выбор неверный, попробуйте ещё раз." << endl;
            break;
        }
    } while (choice != 8);

    return 0;
}
