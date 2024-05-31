#include <iostream>

using namespace std;

class BankAccount
{
protected:
    double balance;
    double amount;
public:
    BankAccount()
    {
        balance = 0;
        amount = 0.0;
    }
    void deposit()
    {
        amount = 0.0;
        cout<<"Please Enter Amount you want to deposit"<<endl;
        cin>>amount;
        balance += amount;
    }

    void withdraw()
    {
        amount = 0.0;

        cout<<"Please Enter Amount you want to withdraw"<<endl;
        cin>>amount;

        if (balance >= amount)
        {
          balance -= amount;
        }

        else
        {
            cout << "Insufficient funds!" << endl;
        }
    }

    void getBalance()
    {
        cout<<"Your Current Balance is "<<balance<<endl;
    }

};

class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;
public:
    CheckingAccount()
    {
        overdraftLimit = 50000;
    }

    withdraw()
    {
     {
        if (balance + overdraftLimit >= amount)
        {
            balance -= amount;
            cout << "Withdrawn " << amount << " from Checking Account. New balance: " << balance << endl;
        }

        else
        {
            cout << "Overdraft limit exceeded!" << endl;
        }
     }

    }
};

class SavingsAccount:public BankAccount
{
private:
    double interestRate;
public:

    SavingsAccount()
    {
        interestRate = 24;
    }

    void addInterest()
    {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest added. New balance: " << balance << endl;
    }
};

int main()
{
    string account;
    cout<<"Please Enter type of Account. Savings or Checking"<<endl;
    cin>>account;

    if(account == "Savings" || account == "savings")
    {
        SavingsAccount s1;

        s1.getBalance();

        int enter;

        cout<<"Please Enter whether you want to Deposit(1) or Withdraw Amount(2)"<<endl;
        cin>>enter;

        if(enter == 1)
        {
         s1.deposit();
        }

        else if(enter == 2 )
        {
            s1.withdraw();
        }

        else
        {
            cout<<"Please Enter Again"<<endl;
            cin>>enter;
        }

      int choice;

      cout<<"Please Press 1 if you want to check balance and 2 for exiting"<<endl;
      cin>>choice;

      if(choice == 1)
      {
          s1.addInterest();
      }

      else
      {
          cout<<"________________THANKS FOR VISITING___________"<<endl;
      }
    }

    else
    {
        CheckingAccount c1;

        c1.getBalance();

        int enter;

        cout<<"Please Enter whether you want to Deposit(1) or Withdraw Amount(2)"<<endl;
        cin>>enter;

        if(enter == 1)
        {
         c1.deposit();
        }

        else if(enter == 2 )
        {
            c1.withdraw();
        }

        else
        {
            cout<<"Please Enter Again"<<endl;
            cin>>enter;
        }
        cout<<"Please Press 1 if you want to check balance or 2 for exiting"<<endl;
        cin>>enter;

        if(enter == 1)
        {
            c1.getBalance();
        }

        else
        {
            cout<<"_______________________THANKS FOR VISITING______________"<<endl;
        }

    }
    return 0;
}
