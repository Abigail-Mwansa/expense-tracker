#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Structure for storing expense information
struct Expense{
    
    int id;
    string description;
    double amount ;
    string category;
    string date;
};

//Function to add an expense
void addExpense(vector<Expense>&expenses){
    Expense e;
    cout<<"Enter expense ID:";
    cin>>e.id;
    cin.ignore();
    cout<<"Enter Description:";
    getline(cin, e.description);
    cout<<"Enter amount: ";
    cin>>e.amount;

    cin.ignore();
    cout<<"Enter category: ";
    getline(cin, e.category);

    cout<<"Expense added successfully!"<<endl;
}

//Function to display expenses

void viewExpenses(vector<Expense>&expenses){
    if(expenses.size() == 0){
        cout<<"No expenses recorded."<<endl;
    }
    else{
        for(int i = 0; i < expenses.size(); i++){
            cout<<"\nExpenses ID: "<<expenses[i].id<<endl;
            cout<<"Description: "<<expenses[i].description<<endl;
            cout<<"Amount: K"<<expenses[i].amount<<endl;
            cout<<"Category: "<<expenses[i].category<<endl;
            cout<<"Date: "<<expenses[i].date<<endl;
        }
    }
}

//Function to calculate total expenses
void calculateTotal(vector<Expense>&expenses){
    double total = 0;
    for (int i = 0; i <expenses.size();i++){
        total = total + expenses[i].amount;
    }
    cout<<"Total expenses: K"<<total<<endl;
}
int main(){
   // vector<Expense> expenses;
    cout<<"=====EXPENSE TRACKER===== "<<endl;
    vector<Expense> expenses;
    int choice;
     do{
        cout<<"\n====EXPENSE TRACKER===="<<endl;
        cout<<"1. Add Expense"<<endl;
        cout<<"2. View Expense"<<endl;
        cout<<"3.Calculate Total"<<endl;
        cout<<"4. Exit<<endl";
        cout<<"Enter Your Choice: "<<endl;
        cin>>choice;

        switch(choice){
            case 1: addExpense(expenses);
            break;
            case 2: viewExpenses(expenses);
            break;
            case 3: calculateTotal(expenses);
            break;
            case 4: cout<<"Exiting Expense Tracker..."<<endl;
            break;
            default:cout<<"Invalid choice!"<<endl; 
            

        }
     }while(choice !=4);
    
    return 0;
}
