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
<<<<<<< HEAD

//Functions to edit an expense
void editExpense(vector<Expense>&expenses){
    int searchID;
    int found = 0;
    cout<<"Enter the ID of the expense to edit: ";
    cin>> searchID;

    for(int i = 0;i<=expenses.size(); i++){
        if(expenses[i].id == searchID){
            cout<<"Enter new description: ";
            cin.ignore();
            getline(cin,expenses[i].description);
            cout<<"Enter new amount: ";
            cin>>expenses[i].amount;

            cin.ignore();
            cout<<"Enter new category: ";
            getline(cin, expenses[i].category);
            cout<<"Enter new date: ";
            getline(cin,expenses[i].date);

            cout<<"Expense updated successfully!"<<endl;

            found = 1;
            break;
        }
    }
    if(found == 0) {
        cout<<"Expense ID not found!"<<endl;
    }
}

//Function to delete an expense

void deleteExpense(vector<Expense>&expenses){
    int searchID;
    int found = 0;

    cout<<"Enter the ID of the expense to delete: ";
    cin>>searchID;

    for(int i = 0; i< expenses.size();i++){
        if(expenses[i].id == searchID){
            for(int j = i;j<expenses.size() - 1; j++){
                expenses[j] = expenses[j + 1];

            }

            expenses.pop_back();
            cout<<"Expense deleted successfully!" <<endl;

            found = 1;
            break;
        }
    }
   if (found == 0){
    cout<<"Expense ID not found!"<<endl;
   } 
}
=======
>>>>>>> 13ffe8e4200522f290504bf1d5159fe62f140c5b
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
<<<<<<< HEAD
        cout<<"4. Edit Expense"<<endl;
        cout<<"5. Delete Expense"<<endl;
        cout<<"6. Exit<<endl";
=======
        cout<<"4. Exit<<endl";
>>>>>>> 13ffe8e4200522f290504bf1d5159fe62f140c5b
        cout<<"Enter Your Choice: "<<endl;
        cin>>choice;

        switch(choice){
            case 1: addExpense(expenses);
            break;
            case 2: viewExpenses(expenses);
<<<<<<< HEAD
            break;   
            case 3: calculateTotal(expenses);
            break;
            case 4: editExpense(expenses);
            break;
            case 5: deleteExpense(expenses);
            break;
            case 6: cout<<"Exiting Expense Tracker..."<<endl;
=======
            break;
            case 3: calculateTotal(expenses);
            break;
            case 4: cout<<"Exiting Expense Tracker..."<<endl;
>>>>>>> 13ffe8e4200522f290504bf1d5159fe62f140c5b
            break;
            default:cout<<"Invalid choice!"<<endl; 
            

        }
<<<<<<< HEAD
     }while(choice !=6);
=======
     }while(choice !=4);
>>>>>>> 13ffe8e4200522f290504bf1d5159fe62f140c5b
    
    return 0;
}
