#include <iostream> 
#include <vector>
#include <string>
#include <ctime>


using namespace std; 


int main(){

  // Variables to store individual income, total income, individual expenses, and total expenses
  double income = 0;
  double totalIncome = 0;
  double expense = 0;
  double totalExpenses = 0;

  // Get today's date
  time_t now = time(0);
  tm *ltm = localtime(&now);

  // Array of month name
  const string months[] = { "January", "February", "March", "April", "May", "June", 
  "July", "August", "September", "October", "November", "December" };
  

  // Vector to store the source and amount of each income
  vector<pair<string, double>> diffIncomes;
  string incomeName;
  char choiceIncome;
  

  // Vector to store the name and amount of each expense
  vector<pair<string, double>> expenses;
  string expenseName; // Stores the name of each expense
  char choiceExpense; // For checking if the user wants to add more expenses

  // Display today's date in the Month dd, yyyy format
  cout 
  << months[ltm->tm_mon] << " " // Month name
  << ltm->tm_mday << ", " // Day
  << 1900 + ltm->tm_year << endl; // Year

  cout << "Luke's Daily Budget Calculator\n\n";

  cout << "Enter income sources and amounts now..." << endl;

  // To add multiple source and amounts of income
  do{
    cout << "Enter the name of the source: ";
    cin.ignore(); // Ignore any leftover newline character in input
    getline(cin, incomeName); // Read the full line

    // Ask amount of income
    cout << "Enter the income amount: $";
    cin >> income;

    // Add the income to the vector and update total income
    diffIncomes.push_back(make_pair(incomeName, income));
    totalIncome += income;

    // Ask if user wants to add another expense
    cout << "Do you want to add another income? (y/n); ";
    cin >> choiceIncome;

  } while (choiceIncome == 'y' || choiceIncome == 'Y'); // Repeat the loop if the user enters y or Y


  cout << "Enter your expenses now..." << endl;

  // To add multiple expenses
  do{
    cout << "Enter the name of the expense: ";
    cin.ignore(); // Ignore any leftover newline character in input
    getline(cin, expenseName); // Read the full line 

    // Ask amount of the expense
    cout << "Enter the amount of the expense: $";
    cin >> expense;

    // Add the expense to the vector and update total expenses
    expenses.push_back(make_pair(expenseName, expense));
    totalExpenses += expense;

    // Ask if user wants to add another expense
    cout << "Do you want to add another expense? (y/n); ";
    cin >> choiceExpense;

  } while (choiceExpense == 'y' || choiceExpense == 'Y'); // Repeat the loop if the user enters y or Y

  // Calculate the remaining balance after deducting total expenses from income
  double remainingBalance = totalIncome - totalExpenses;

  // Display summary of daily budget
  cout << "\n--- Budget Summary for ";

  // Display today's date in the Month dd, yyyy format
  cout 
  << months[ltm->tm_mon] << " " // Month name
  << ltm->tm_mday << ", " // Day
  << 1900 + ltm->tm_year << " ---\n" << endl ; // Year

  cout << "Today's Income: $" << totalIncome << endl;
  cout << "Total Expenses: $" << totalExpenses << endl;
  cout << "Remaining Balance: $" << remainingBalance << endl;

  // Display detialed list of income 
  cout << "\nDetailed Income:\n";
  for(const auto &income : diffIncomes){
    cout << income.first << ": $" << income.second << endl;
  }

  // Diplay detailed list of expenses
  cout << "\nDetailed Expenses:\n";
  for(const auto &expense : expenses){
    cout << expense.first << ": $" << expense.second << endl;
  }

  return 0; 

}
