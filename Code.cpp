#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <map>
#include <iomanip>
#include <set>
#include <algorithm>
using namespace std;

/*
BAI = Bank Account Information

Variables:
AN = Account Number
AHN = Account Holder Name
Bal = Balance
Pass = Password
Email = User Email ID
MN = Mobile Number
*/

struct BAI
{ 
    unsigned int AN;
    string AHN;
    double Bal;
    string Pass;
    string EmailID;
    string MN;
    int passtry;
};

/*
Account = Bank Account

Private Member Variable:
an = account number!
ahn = account holder name!
ib = initial balance!
am = amount!
pass = password!
email = email id!
mn = mobile number!

Member Functions:
deposit = +$
withdraw = -$
display = <$>
retan = Account Number
retpass = Password
retacc = Account Holder Name
retbal = Balance
retem = Email ID
retmob = Mobile Number
*/

class Account
{
private:
    BAI bai;

public:
    Account(unsigned int an, string ahn, double ib, string pass, string email, string mn, int atpass = 3)
    {
        bai.AN = an;
        bai.AHN = ahn;
        bai.Bal = ib;
        bai.Pass = pass;
        bai.EmailID = email;
        bai.MN = mn;
        bai.passtry = atpass;
    }

    void deposit(double am)
    {
        if (am > 0)
        {
            bai.Bal += am;
            cout << "\nDeposited Amount = $" << am << "\\-" << endl;
        }
        else
        {
            cout << "\nInvalid Deposit." << endl;
        }
    }

    void withdraw(double am)
    {
        if (am > 0 && am <= bai.Bal)
        {
            bai.Bal -= am;
            cout << "\nWithdrawn Amount = $" << am << "\\-" << endl;
            cout << "Total Balance = $" << bai.Bal <<"\\-" << endl;
        }
        else
        {
            cout << "\nInvalid withdrawal Amount or Insufficient Bal." << endl;
        }
    }

    void display()
    {
        cout << "\nAccount Number : " << bai.AN << endl;
        cout << "Account Holder : " << bai.AHN << endl;
        cout << "Account Balance = $" << bai.Bal << endl;
        cout << "Email ID : " << bai.EmailID << endl;
        cout << "Mobile Number : " << bai.MN << endl;
    }

    void admindisplay()
    {
        cout << bai.AN << "\t:::::\t" << bai.AHN << "\t:::::\t" << bai.Bal;
        cout << "\t:::::\t" << bai.EmailID << "\t:::::\t" << bai.MN << endl;
    }

    void tminus()
    {
        bai.passtry--;
    }

    void reset()
    {
        bai.passtry = 3;
    }

    unsigned int retan() const
    {
        return bai.AN;
    }
    string retpass() const
    {
        return bai.Pass;
    }
    string retacc() const
    {
        return bai.AHN;
    }
    double retbal() const
    {
        return bai.Bal;
    }
    string retem() const
    {
        return bai.EmailID;
    }
    string retmob() const
    {
        return bai.MN;
    }
    int rettry() const
    {
        return bai.passtry;
    }

    void modify(char c, string n)
    {
        switch (c)
        {
            case 'N':
                bai.AHN = n;
                break;
            case 'P':
                bai.Pass = n;
                break;
            case 'M':
                bai.MN = n;
                break;
            case 'E':
                bai.EmailID = n;
                break;
            default:
                cout << "INVALID CHOICE!!!" << endl;
        }
    }
};


/*
as = Bank Accounts
choice = Action on Account
Action List = List of choices

an = account number!!
ahn = account holder name!!
ib = initial balance!!
am = amount!!
pass = password!!
email = email id!!
mn = mobile number!!

adam = add amount
subam = subract amount
*/

int main()
{
    cout << fixed << setprecision(0);
    vector<Account> as;
    const char path[74] = "C:\\C-Structured and Object Oriented Programming\\Project\\Bank_Database.txt";
    ifstream infil(path);

    map<string, string> addata;
    addata["Jayanth"] = "jayrocks";
    addata["Kishor"] = "kish";
    addata["Karthick"] = "prof.c++";

    set<unsigned int> excheck;

     if (infil.is_open()) {
        while (!infil.eof()) {
            unsigned int an;
            string ahn;
            double ib;
            string pass, pass_;
            string email;
            string mn;
            int atpass;
            
            infil >> an >> ahn >> ib >> pass >> email >> mn >> atpass;
            
            Account account(an, ahn, ib, pass, email, mn, atpass);
            as.push_back(account);
            
            excheck.insert(an);
        }
        infil.close();
    }


    cout << "\nBank Account Manager\n";
    cout << "Press 0 for 'Action List'" << endl;
    cout << "Press 1 to 'Create an Account'" << endl;
    cout << "Press 2 to 'Deposit Amount'" << endl;
    cout << "Press 3 to 'Withdraw Amount'" << endl;
    cout << "Press 4 to 'View Account Details'" << endl;
    cout << "Press 5 to 'Exit'" << endl;

    while (true)
    {
        int choice;
        cout << "\nOption : ";
        cin >> choice;

        switch (choice)
        {
            case 0:
                cout << "\nPress 1 to 'Create an Account'" << endl;
                cout << "Press 2 to 'Deposit Amount'" << endl;
                cout << "Press 3 to 'Withdraw Amount'" << endl;
                cout << "Press 4 to 'View Account Details'" << endl;
                cout << "Press 5 to 'Exit'" << endl;
                break;

            case 1:
            {
                string ahn;
                unsigned int an;
                double ib;
                string pass, pass_;
                string email;
                string mn;

                srand(time(0));
                an = rand() * 7137;

                cout << "\nAccount Holder (All Caps) : ";
                cin.ignore();
                getline(cin, ahn);

                cout << "Password : ";
                cin >> pass;
                cout << "Re-enter Password : ";
                cin >> pass_;
                if(pass != pass_)
                {
                    cout << "PASSWORDS DO NOT MATCH.\nRETRY ACCOUNT REGISTRATION.";
                    break;
                }

                cout << "Email ID : ";
                cin >> email;

                cout << "Mobile Number: ";
                cin >> mn;

                cout << "Initial Balance Deposit = $";
                cin >> ib;

                Account account(an, ahn, ib, pass, email, mn);
                as.push_back(account);
                cout << "\nACCOUNT CREATED." << endl;
                cout << "\nYour Account:-" << endl;
                account.display();
                break;
            }

            case 2:
            {
                unsigned int an;
                double adam;
                bool note = false;

                cout << "\nAccount Number : ";
                cin >> an;
                cout << "Deposit Amount = $";
                cin >> adam;

                for (Account& account : as)
                {
                    if (account.retan() == an)
                    {
                        account.deposit(adam);
                        note = true;
                        break;
                    }
                }

                if(!note){
                    cout << "\nACCOUNT NUMBER INVALID." << endl;
                }
                break;
            }

            case 3:
            {
                unsigned int an;
                double subam;
                string pass;
                bool note = false;

                cout << "\nAccount Number : ";
                cin >> an;
                cout << "Password : ";
                cin >> pass;

                for (Account& account : as)
                {
                    if(account.rettry() == 0)
                    {
                        cout << "\nMAXIMUM PASSWORD TRIES REACHED.\nACCOUNT LOCKED" << endl;
                        return 0;
                    }

                    if((account.retan() == an) && (account.retpass() == pass))
                    {
                        cout << "Withdrawal Amount = $";
                        cin >> subam;
                        account.withdraw(subam);
                        note = true;
                        break;
                    }
                    else if((account.retan() == an) && (account.retpass() != pass))
                    {
                        account.tminus();
                        cout << "\nINVALID PASSWORD" << endl;
                        note = true;
                        break;
                    }
                }

                if(!note){
                    cout << "\nACCOUNT NUMBER INVALID." << endl;
                }
                break;
            }

            case 4:
            {
                unsigned int an;
                string pass;
                bool note = false;

                cout << "\nAccount Number : ";
                cin >> an;
                cout << "Password : ";
                cin >> pass;

                for (Account& account : as)
                {
                    if(account.rettry() == 0)
                    {
                        cout << "\nMAXIMUM PASSWORD TRIES REACHED.\nACCOUNT LOCKED" << endl;
                        return 0;
                    }

                    if ((account.retan() == an) && (account.retpass() == pass))
                    {
                        account.display();
                        note = true;
                        break;
                    }
                    else if((account.retan() == an) && (account.retpass() != pass))
                    {
                        account.tminus();
                        cout << "\nINVALID PASSWORD" << endl;
                        note = true;
                        break;
                    }
                }

                if(!note){
                    cout << "\nACCOUNT NUMBER INVALID." << endl;
                }
                break;
            }
            
            case -1:
            {
                string adid, adpass;
                bool note = false;

                cout << "\nAdmin User ID: ";
                cin >> adid;
                cout << "Admin Password: ";
                cin >> adpass;

                map<string, string>::reverse_iterator it = addata.rbegin();
                while (it != addata.rend()) {
                    if (it->first == adid) {
                        note = true;
                        if (it->second != adpass) {
                            return 0;
                        }
                        else {
                            cout << "\nAccount List:\n";
                            for (Account& account : as) {
                                account.admindisplay();
                            }
                            break;
                        }
                    }
                    ++it;
                }

                if (!note) {
                    cout << "\nADMIN USERNAME INVALID" << endl;
                    break;
                }
                break;
            }

            case -2:
            {
                string adid, adpass;
                bool note = false;
                unsigned int an;

                cout << "\nAdmin User ID: ";
                cin >> adid;
                cout << "Admin Password: ";
                cin >> adpass;

                map<string, string>::reverse_iterator it = addata.rbegin();
                while (it != addata.rend()) {
                    if (it->first == adid) {
                        note = true;
                        if (it->second != adpass) {
                            return 0;
                        }
                        else {
                            cout << "\nEnter the Account Number to Unlock: ";
                            cin >> an;
                            for (Account& account : as) {
                                if (account.retan() == an) {
                                    account.reset();
                                    cout << "Account Unlocked." << endl;
                                    break;
                                }
                            }
                            note = true;
                            break;
                        }
                    }
                    ++it;
                }

                if (!note) {
                    cout << "\nADMIN USERNAME INVALID" << endl;
                    break;
                }
                break;
            }


            case -3:
            {
                string adid, adpass, newval;
                char mod;
                bool note = false;
                unsigned int an;

                cout << "\nAdmin User ID: ";
                cin >> adid;
                cout << "Admin Password: ";
                cin >> adpass;

                map<string, string>::reverse_iterator it = addata.rbegin();
                while (it != addata.rend()) {
                    if (it->first == adid) {
                        note = true;
                        if (it->second != adpass) {
                            return 0;
                        }
                        else {
                            cout << "\nEnter the Account Number to Modify: ";
                            cin >> an;
                            break;
                        }
                    }
                    ++it;
                }

                if (!note) {
                    cout << "\nADMIN USERNAME INVALID" << endl;
                    break;
                }

                cout << "\nModify:\n";
                cout << "N. Name\nP. Password\nE. Email ID\nM. Mobile Number\n\nChoice: ";
                cin >> mod;
                cout << "\nNew Value: ";
                cin >> newval;

                for (Account& account : as) {
                    if (account.retan() == an) {
                        account.modify(mod, newval);
                        cout << "Account with number " << an << " has been modified." << endl;
                        break;
                    }
                }
                break;
            }


            case 5:
                cout << "\n(-: THANK YOU :-)\n" << endl;
                return 0;

            default:
                cout << "\nINVALID ACTION\n" << endl;
                break;
        }

        ofstream exfil(path, ios::app);
        if (exfil.is_open()) {
        for (const Account& account : as) {
            unsigned int acno = account.retan();

            if (find(excheck.begin(), excheck.end(), acno) == excheck.end()) {
                exfil << account.retan() << "\t" << account.retpass() << "\t";
                exfil << account.retbal() << "\t" << account.retem() << "\t";
                exfil << account.retmob() << "\t" << account.rettry() << endl;
            }
        }
        exfil.close();
        }
    }

    return 0;
}