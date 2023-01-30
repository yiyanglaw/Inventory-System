#include <iostream>
//#include<string>
//#include<sstream>
#include<fstream>//file handling
#include<iomanip>//setw
#include<unistd.h>//sleep
#include <conio.h>//getch
//#include <stdlib.h>
//#include <stdio.h>
#include <windows.h> //sleep
//#include<mmsystem.h>//play sound
//#include<dos.h>
//#include <time.h> //print time in receipt

//company
//report
//customer list(information)
//supplier
//Profit report (if expired/broken/damaged product cleared then loss increase, if checkout then profit increase)

//error checking
//id overloading

    using namespace std;
    string uname,pword;
    int tryCount=0;
    int tryLimit=3;
    bool outOfTry=false;


const int n=10;

string pname[n]={};
string id[n]={};
string qty[n]={};
string expDate[n]={};
string pcost[n]={};
string pprice[n]={};

string name_;
char pass[32];
string userName="a";
string password="1";
string newPassword;
char change;

int option;
int ptype;
int flag;
string searchProdName;
int qtyCheckout;
int profit1;
int profit;
int loss1;
int loss;

void report()
{
  system("cls");
  cout<<"Profit: "<<"RM"<<profit<<endl;
  cout<<"Loss  : "<<"RM"<<loss<<endl;

}
void saveReport() //write to file
{
          ofstream writeR;
          cout<<"Saving";
          writeR.open("report.txt");
          writeR<<profit<<endl;
          writeR<<loss<<endl;
          writeR.close();
          cout<<"Saved";

}




bool login() //enter name&&password
{
    string username,password,uname,pword;
    cout<<"Enter your username:";
    cin>>name_;
    cout<<"Enter your password:";
    int i = 0;
    char temp;//a Temp char
    for(i=0;;)//infinite loop
    {
        temp = _getch();// stores char typed in a
        if((temp>='a'&&temp<='z')||(temp>='A'&&temp<='Z')||(temp>='0'&&temp<='9'))

        {
            pass[i]=temp;//stores in pass
            ++i;
            cout<<"*";
        }
        if(temp=='\b'&&i>=1)//if user typed backspace
            //i should be greater than 1.
        {
            cout<<"\b \b";//rub the character behind the cursor.
            --i;
        }
        if(temp=='\r')//if enter is pressed
        {
            pass[i]='\0';//null means end of string.
            break;//break the loop
        }
    }

    ifstream read;
    read.open("login.txt");
    getline(read,uname);
    getline(read,pword);
    if(name_==uname&&pass==pword)
    {
      return true;
    }
    else
    {
     return false;
    }

}

bool chg() //change password
{
    string changeUn,changePass,cUname,cPass;

    cout<<"Enter your previous Username:";
    cin>>changeUn;
    cout<<"Enter your previous password:";
    cin>>changePass;
    ifstream read1;
    read1.open("login.txt");
    getline(read1,cUname);
    getline(read1,cPass);
    if(changeUn==cUname&&changePass==cPass)
    {
        return true;

    }
    else
    {
        return false;
    }

}


void us()
{
    system("cls");
    string about_us = "\t\t\t | About Us |\n\t\t\t--------------\n\t\t\tTeam Member:\n\t\t\tWong Xin Yao\n\t\t\tChong Jiu Yuan"
                      "\n\t\t\tTee Cheng Qi\n\t\t\tAw Chia Zheng\n\t\t\tLaw Yi Yang\n\n\t\t\t FIST MMU";

    int x=0;
    while ( about_us[x] != '\0')
  {
	cout <<about_us[x];
	Sleep(50);
	x++;
  };
}


void saving()
{
 for(int i=1;i<=20;i++)
    {
        system("cls");
        cout<<"\n\n\tLoading "<<5*i<<"%\n\n  ";
        for(int j=1;j<=i;j++)
            cout<<"\xB2";

     Sleep(40 - i*2);

    }
}


void OpenFile()
{
    string line_long;

    ifstream myfile("product.txt");
    if(myfile.is_open())
    {

        for(int x=0;x<n;x++)
        {

            getline(myfile,id[x],',');
            getline(myfile,pname[x],',');
            getline(myfile,qty[x],',');
            getline(myfile,pcost[x],',');
            getline(myfile,pprice[x],',');
            getline(myfile,expDate[x],'\n');
        }
    }
    else
    {
      cout<<"Can't open the file!"<<endl;

    }
}

void Insert()
{
    char name[50];
    char no[5];
    char quantity[5];
    char date[11];
    char price[6];
    char cost[6];
    string op;

    cin.ignore();
    cout<<"Product ID(max 999): ";
    cin.getline(no,4);

    for(int x=0;x<n;x++)
    {


            while(no==id[x])
            {

            system("cls");
            cout<<"Id Already exist! Please enter different ID..."<<endl;
            cout<<"Product ID(max 999): ";
            cin.getline(no,4);
            }


               cout<<"Product Name: ";
               cin.getline(name,50);
               cout<<"Product Expiry Date: ";
               cin.getline(date,11);
               cout<<"Product Cost: ";
               cin.getline(cost,6);
               cout<<"Product Price: ";
               cin.getline(price,6);
               cout<<"Product Quantity: ";
               cin.getline(quantity,6);
               break;

    }





    for(int x=0;x<n;x++)
    {
        if(id[x]=="\0")
        {
            id[x]=no;
            pname[x]=name;
            expDate[x]=date;
            qty[x]=quantity;
            pcost[x]=cost;
            pprice[x]=price;
            break;
        }
    }
    op:
    cout<<"Do you want to continue(Yes/No): ";
    cin>>op;
    if(op=="yes"||op=="Yes")
    {
    Insert();
    return;
    }
    else if(op=="no"||op=="No")
    {
    return;
    }
    else
    cout<<"Invalid option! ";
    goto op;



}


void Display()
{

    D:
    system("cls");
    cout<<"\t\tCurrent Products"<<endl;
    cout<<"==========================================================================="<<endl;

    int flag=0;
    cout<<"| No |   ID    |       NAME       |  Quantity | Cost | Price | Expiry Date |"<<endl<<"-------------------------------------------------------------------------\n";
    for(int x=0;x<n;x++)
    {
        if(id[x]!="\0")
        {
            flag++;
            cout<<"  "<<setw(7)<<left<<flag<<setw(10)<<id[x]<<setw(18)<<pname[x]<<setw(11)<<qty[x]<<setw(7)<<pcost[x]<<setw(8)<<pprice[x]<<setw(11)<<expDate[x]<<endl;
            cout<<"==========================================================================="<<endl;
        }

    }

    if(flag==0)
    {
        cout<<"          No record found!"<<endl;
    }


}

void Search(string search)
{
    system("cls");
    cout<<"\t\tCurrent Record(s)"<<endl;
    cout<<"===================================================="<<endl;
    int flag=0;
    for(int x=0;x<n;x++)
    {
        if(id[x]==search)
        {
            flag++;
            cout<<"  "<<flag<<"    "<<id[x]<<"          "<<pname[x]<<"        "<<expDate[x]<<"       "<<qty[x]<<"       "<<pcost[x]<<"       "<<pprice[x]<<endl;
            break;

        }
    }

    if(flag==0)
    {
        cout<<"   No record found!"<<endl;
    }

    cout<<"==============================================="<<endl;
}

void Clear(string search)
{

    system("cls");
    cout<<"\t\tExpired Product(s)"<<endl;
    cout<<"==============================================="<<endl;
    int flag=0;

    string pri[6];
    string cos[6];
    string exp_qty[5];

    for(int x=0;x<n;x++)
    {
        if(expDate[x]==search)
        {
            flag++;
            cos[x]=pcost[x];
            pri[x]=pprice[x];
            exp_qty[x]=qty[x];
            int pri=stoi(pprice[x]);
            int cos=stoi(pcost[x]);
            int exp_qty=stoi(qty[x]);
            loss1=cos*exp_qty;
            loss=loss+loss1;

            cout<<"  "<<flag<<"    "<<id[x]<<"          "<<pname[x]<<"        "<<expDate[x]<<"       "<<qty[x]<<"       "<<pcost[x]<<"       "<<pprice[x]<<endl;
            pname[x]=" ";
            id[x]=" ";
            qty[x]=" ";
            expDate[x]=" ";
            pcost[x]=" ";
            pprice[x]=" ";
            cout<<"============================================="<<endl;
            cout<<"\nSuccessfully cleared!"<<endl;
            break;
        }
    }
     ofstream writeR;
            writeR.open("report.txt");
            writeR<<loss<<endl;



    if(flag==0)
    {
        cout<<"    No record found!"<<endl;
    }
    cout<<"============================================="<<endl;


}




void Checkout(string search)
{

    int num=0;
    int flag=0;
    int qtyCheckout;
    string pri[9];
    string cos[9];
    for(int x=0;x<n;x++)
    {
        if(id[x]==search)
        {
            flag++;
            cout<<"How many product you want to checkout:";
            cin>>qtyCheckout;

            if(qtyCheckout>stoi(qty[x]))
            {
               system("cls");
               printf("Invalid quantity!\n");
               break;
            }
            else
                qty[x]=to_string(stoi(qty[x])-qtyCheckout);


            for(int x=0;x<n;x++)
    {
        {

            cos[x]=pcost[x];
            pri[x]=pprice[x];
            break;
        }
    }

            int pri=stoi(pprice[x]);
            int cos=stoi(pcost[x]);
            for(int y=0;y<qtyCheckout;y++)
    {
        {
            profit1=(pri-cos)*qtyCheckout;
            profit=profit+profit1;

            break;
        }
    }

            ofstream writeR;
            writeR.open("report.txt");
            writeR<<profit<<endl;
            system("cls");
            cout<<"\t\tChecking out...."<<endl;
            Sleep(1);
            system("cls");
            cout<<"=======================";
            cout<<"\nProduct id : "<<id[x]<<"\nProduct Name:"<<pname[x]<<"\nProduct Price: RM"<<pprice[x]<<"\nExpiry Date:  "
            <<expDate[x]<<"\nCheck Out Quantity:  "<<qtyCheckout<<"\nTotal Price: RM"<<profit1<<endl;
            time_t today;
            time(&today);
            cout<<"=======================";
            cout<<"\nChecked out successfully... ^U^"<<endl;
            break;

        }

    }

    if(flag==0)
    {
        cout<<"No record found!"<<endl;
    }

}

void Update(string search)
{
    char name[50];
    char q[5];
    char d[11];
    char c[5];
    char p[5];

    int flag=0;

      for(int x=0;x<n;x++)
    {
        if(id[x]==search)
        {
            flag++;
            cout<<"Product Name.  ";
            cin.getline(name,50);

            cout<<"Product Expiry Date.  ";
            cin.getline(d,11);

            cout<<"Product Quantity.  ";
            cin.getline(q,5);

            cout<<"Product Cost.  ";
            cin.getline(c,5);

            cout<<"Product Price.  ";
            cin.getline(p,5);

            pname[x]=name;
            qty[x]=q;
            expDate[x]=d;
            pcost[x]=c;
            pprice[x]=p;

            cout<<"Update Successfully!"<<endl;


            break;

        }
    }

    if(flag==0)
    {
        cout<<"ID Number does not exist!";
    }

}

void Delete(string search)
{
    int flag=0;

    for(int x=0;x<n;x++)
    {
        if(id[x]==search)
        {
            flag++;
            pname[x]="";
            id[x]="";
            qty[x]="";
            expDate[x]="";
            pcost[x]="";
            pprice[x]="";

            cout<<"Successfully deleted!"<<endl;
            break;

        }
    }

    if(flag==0)
    {
        cout<<"ID Number does not exist!";
    }
}

void SaveToFile()
{
    ofstream myfile;
    myfile.open("product.txt");

    for(int x=0;x<n;x++)
    {
        if(id[x]=="\0")
        {

            break;
        }
        else
        {
           myfile<<id[x] + "," + pname[x] + "," + qty[x] + "," + pcost[x] + "," + pprice[x]+ "," +expDate[x] +"\n";
        }
    }
}

int main()
{

    string sid;
    string id;
    string i;
    string searchDate;
   ifstream readR;
  readR.open("report.txt");
  readR>>profit;
  readR>>loss;

while(password != pass && !outOfTry)
{
     if(tryCount<tryLimit)
     {
      do{

    cout<<"\n\t\t\tWelcome to Inventory System. ^U^ "<<endl;
    START:

      bool status=login();
     if(!status)
      {
          system("cls");
          cout<<"\nSorry!Wrong password entered...\n";
          system("PAUSE");
          tryCount++;
      }
      else
        {
        cout<<"Successfully login"<<endl;
        cout<<"Welcome ^U^";
        goto labelA;
        }

     if (name_==uname&&pass==pword)
    {

    labelA:
    system("cls");
    OpenFile();
    labelM:
    char ch;
    system("cls");
    cout<<"\t\t\t1-Enter system\n\t\t\t2-Account&Security\n\t\t\t3-About us\n\t\t\t4-Exit\n\n\n";
    cout<<"Enter your choice(1-4): ";
    cin>>ch;
    system("cls");
    if(ch=='4')
    {
    system("cls");
    goto labelZ;

    }
    else if(ch=='3')
    {
     char back;
     us();
     labelB:
     cout<<"\n\nBack to menu(B) or play again(P):";
     cin>>back;

     if(back=='B'||back=='b')
      goto labelA;
     else if(back=='P'||back=='p')
      while(back=='P'||back=='p')
      {
        us();
        goto labelB;

      }

     else
     {
      cout<<"Invalid choice..";
      goto labelA;
     }

    }
    else if(ch=='2')
    {
        labelC:
        system("cls");
        cout<<"\n\n\t\t=======Change Your Password=======\n\n";
        bool status=chg();
      if(!status)
      {
          cout<<"\nYou enterd password is not right...\n";
          system("PAUSE");
          goto labelC;
      }
      else
      {
          cout<<"Verified successfully!\n";
          string name,name1;
          cout<<"\nEnter your new username:";
          cin>>name;
          cout<<"Enter your new password:";
          cin>>name1;
          ofstream write;
          write.open("login.txt");
          write<<name<<endl;
          write<<name1<<endl;
          write.close();

      }


    }

    else if(ch=='1')
    {
      labelY:
    do{
       system("cls");
       cout<<"\t\t1-Product management"<<endl;
       cout<<"\t\t2-Back"<<endl;
       cout<<"==================================================="<<endl;
       cout<<"Select option >>";
       cin>> option;

       switch(option)
    {
        case 1:goto labelN;
               break;

        case 2:goto labelM;
               break;
    }


       }while(option!='3');


        labelN:
        system("cls");
    do{

       cout<<"==========================================================================="<<endl;
       cout<<"1-Insert Products"<<endl;
       cout<<"2-Display Products"<<endl;
       cout<<"3-Search Products"<<endl;
       cout<<"4-Clear Expiry Products"<<endl;
       cout<<"5-Checkout Products"<<endl;
       cout<<"6-Update Products"<<endl;
       cout<<"7-Delete Products"<<endl;
       cout<<"8-Profit and Loss Report"<<endl;
       cout<<"9-Exit and Save to Textfile"<<endl;
       cout<<"=========================================================================="<<endl;

    cout<<"Select option >>";
    cin>> option;

    switch(option)
    {
        case 1:Insert();
               system("cls");
               break;
        case 2:Display();
               break;

        case 3:cin.ignore();//mei you jiu mo ren ni shu ru null
               cout<<"Search by ID>>";
               getline(cin,id);
               Search(id);
               cin.ignore();
               system("cls");
               break;
        case 4:cin.ignore();
               cout<<"Clear by date(dd/mm/yyyy)>>";
               getline(cin,searchDate);
               Clear(searchDate);
               cin.ignore();
               system("cls");
               break;

        case 5:system("cls");
               cin.ignore();
               cout<<"Checkout by ID>>";
               getline(cin,id);
               Checkout(id);
               break;

        case 6:cin.ignore();
               cout<<"Update by ID>>";
               getline(cin,id);
               Update(id);
               system("cls");
               break;
        case 7:cin.ignore();
               cout<<"Delete by ID>>";
               getline(cin,id);
               Delete(id);
               cin.ignore();
               system("cls");
               break;
        case 8:
               cin.ignore();
               report();
               break;

        default:system("cls");
                cout<<"\nError option! Please select again..\n";

    }

    }while(option!=9);
    }
    else
    cout<<"Invalid choice...";
     labelZ:
     cout<<"Saving To file......"<<endl;

     saving();
     SaveToFile();
     saveReport();
     system("cls");
     cout<<"\n\n\n\n\n\n\t\tSaved successfully ^U^. Press Any Key To Exit Screen ^U^\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
     return 0;
    }
    }while(tryCount<tryLimit);
     }

            else
            {
                outOfTry=true;
                cout<<"Sorry, maximum login limit reached.";
                cout<<"\n\n\n\n\n\n\t\tProgram Blocked. Press Any Key To Exit Screen ^U^\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
            }

}

    return 0;

     }



