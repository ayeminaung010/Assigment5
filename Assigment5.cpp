#include "iostream"
using namespace std;
#include "fstream"
#define SIZE 100

class Assigment5{
    public:
        char name[SIZE];
        int password = 0;
        int age = 0;
        int id = 0;
        char address[SIZE];
        int amount = 0;
};
void findData();
void insertData();
void updateData();

int programs  = 0;
    FILE *fptr;

int main(){
    do
    {
        cout<<"Press 1 to Insert Data.. :"<<endl;
        cout<<"Press 2 to Find your Data.. :"<<endl;
        cout<<"Press 3 to Update Data.. :"<<endl;

        cin>>programs;

        switch (programs){
        case 1:
            insertData();
            break;
        case 2:
            findData();
            break;
        case 3:
            updateData();
            break;
        default:
            printf("Wrong input Try Again!");
        }
        
    } while (programs != 0);
}

void insertData(){
    int number = 0;
    ofstream MyFile;
    MyFile.open("assigment5.txt");
    if(!MyFile){
        cout<<"You cannot open file"<<endl;
    }else{
        cout<<"How many people do u want ..:"<<endl;
        cin>>number;
        for (int i = 0; i < number; i++){

            Assigment5 userData[i];
            cout<<"Enter your id :"<<endl;
            cin>>userData[i].id;

            cout<<"Enter your name :"<<endl;
            cin>>userData[i].name;

            cout<<"Enter your password :"<<endl;
            cin>>userData[i].password;

            cout<<"Enter your age :"<<endl;
            cin>>userData[i].age;

            cout<<"Enter your address :"<<endl;
            cin>>userData[i].address;

            cout<<"Enter your amount :"<<endl;
            cin>>userData[i].amount;

            MyFile<<userData[i].id<<" "<<userData[i].name<<" "<<userData[i].password<<" "<<userData[i].age<<" "<<userData[i].address<<" "<<userData[i].amount<<endl;
        }

    }
    
    MyFile.close();
}

void findData(){
    int number = 0;
    string findName;

    ifstream MyFile;
    MyFile.open("assigment5.txt");

        cout<<" Enter how many peoeple do you want to see  :"<<endl;
        cin>>number;
        Assigment5 userData1;
       

        for (int j = 0; j < number; j++)
        {     
            MyFile>>userData1.id>>userData1.name>>userData1.password>>userData1.age>>userData1.address>>userData1.amount;
            cout<<userData1.id<<" "<<userData1.name<<" "<<userData1.password<<" "<<userData1.age<<" "<<userData1.address<<" "<<userData1.amount<<"\n";
        }

        cout<<"Enter name to find your data"<<endl;
        cin>>findName;
        MyFile>>userData1.id>>userData1.name>>userData1.password>>userData1.age>>userData1.address>>userData1.amount;
        if(findName == userData1.name){
            cout<<userData1.id<<" "<<userData1.name<<" "<<userData1.password<<" "<<userData1.age<<" "<<userData1.address<<" "<<userData1.amount<<"\n";
        }else{
            cout<<"Your name doesn't have ..."<<endl;
        }

    MyFile.close();
}

void updateData(){
    string findName;
    
    ifstream MyFile;
    MyFile.open("assigment5.txt");
    Assigment5 userData1;

    cout<<"Enter name to find your data"<<endl;
    cin>>findName;
    MyFile>>userData1.id>>userData1.name>>userData1.password>>userData1.age>>userData1.address>>userData1.amount;
    if(findName == userData1.name){
        cout<<userData1.id<<" "<<userData1.name<<" "<<userData1.password<<" "<<userData1.age<<" "<<userData1.address<<" "<<userData1.amount<<"\n";

        cout<<"Enter new name to edit.. :"<<endl;
        cin>>userData1.name;

        cout<<"After changing your name :"<<endl;
        
        ofstream MyFile;
        MyFile.open("assigment5.txt");
         
        MyFile<< userData1.id<<" "<<userData1.name<<" "<<userData1.password<<" "<<userData1.age<<" "<<userData1.address<<" "<<userData1.amount<<endl;

        cout<<userData1.id<<" "<<userData1.name<<" "<<userData1.password<<" "<<userData1.age<<" "<<userData1.address<<" "<<userData1.amount<<"\n";

        MyFile.close();


    }else{
        cout<<"Your name doesn't have ..."<<endl;
    }
    MyFile.close();
    

}
