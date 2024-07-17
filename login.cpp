#include<iostream>
#include<fstream>
using namespace std;

class temp
{
private:
    string userName,Email,Password;
    string searchName,searchPass,searchEmail;
    fstream file;
public:
    void login();
    void signUp();
    void forgot();
}obj;


int main(){
    char choice;
    cout<<"\n1- Login";
    cout<<"\n2- Sign-Up";
    cout<<"\n3- Forget Password";
    cout<<"\n4- Exit";
    cout<<"\n Enter Your Choice : ";
    cin>>choice;

    switch (choice)
    {
    case '1':
        cin.ignore();
        obj.login();
        break;
    case '2':
        cin.ignore();
        obj.signUp();
        break;
    case '3':
        cin.ignore();
        obj.forgot();
        break;
    case '4':
        return 0;
        break;
    
    default:
    cout<<"Invalid Statement....!";
        break;
    }

    return 0;
}

void temp ::signUp(){
    cout<<"\n Enter Your User Name : ";
    getline(cin, userName);
    cout<<"Enter Your Email Address : ";
    getline(cin,Email);
    cout<<"Enter Your Password : ";
    getline(cin,Password);

    file.open("loginData.txt", ios::out | ios::app);
    file<<userName<<"*"<<Email<<"*"<<Password<<endl;
    file.close();
}
void temp ::login(){
    cout<<"==============Login====================="<<endl;
    cout<<"Enter Your User Name : "<<endl;
    getline(cin,searchName);
    cout<<"Enter Your Password : "<<endl;
    getline(cin,searchPass);

    file.open("loginData.txt",ios::in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');
    while (!file.eof())
    {
        if (userName == searchName)
        {
            if (Password == searchPass)
            {
                cout<<"\n Account Login Succesfull....!";
                cout<<"\nUsername :: "<<userName<<endl;
                cout<<"\nEmail :: "<<Email<<endl;
            }
            else
            {
                cout<<"Password is Incorrect.....!";
            }
            
        }           
            getline(file,userName,'*');
            getline(file,Email,'*');
            getline(file,Password,'\n'); 
    }
    file.close();
}

void temp :: forgot(){
    cout<<"\n Enter Your UserName :: ";
    getline(cin,searchName);
    cout<<"\n Enter Your Email Address :: ";
    getline(cin,searchEmail);

    file.open("loginData.txt",ios::in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');
    while (!file.eof())
    {
        if (userName == searchName)
        {
            if (Email == searchEmail)
            {
                cout<<"\n Account Found...!"<<endl;
                cout<<"Your Password : "<<Password<<endl;
            }
            else
            {
                cout<<"Not found...!\n";
            }
        }
        else
        {
            cout<<"\nNot found....!\n";
        }
        getline(file,userName,'*');
        getline(file,Email,'*');
        getline(file,Password,'\n');
    }
    file.close();
}