/*
 Author: Nikola Tunguz
 Purpose: Create carnival ticketing system that tracks each patron's tickets 
 and calculates whether customers need to purchase more tickets or not
 Max park capacity is 300 on any given day, Max number of rides for a person is 100
*/

#include "patron.h"
#include "costCalculator.h"
#include <fstream>


//function forward declarations 
void displayMenuOption();
void displayModOptions();
void displayRideMenu();
void displayPatrons(Patron[], int);

int readExistingPatrons(Patron[], string);
void printFileNotFound();
void overwriteFile(Patron[], string, int);

Patron createNewPatron();
void addPatron(Patron[], Patron, int*);
void removePatron(Patron[], int, int*);
void modifyPatron(Patron*);
void editName(Patron*);

void addTickets(Patron*);
void addRide(Patron*);

template <typename Type>
Type getOption(Type userChoice);
template<class T>
ostream &operator << ( ostream& output, CostCalculator<T>& calculator);


//Main function, runs all the code
int main(int argc, char* argv[]){

    //default variables and arrays
    int userChoice = 1;
    int patronOpt = 0;
    Patron* patrons = new Patron[100]; 
    int numPatron = 0;
    Patron patron;

    //makes sure correct number of arguments was supplied 
    if (argc > 1)
    {
        numPatron = readExistingPatrons(patrons, argv[1]);
    }
    else{
        printFileNotFound();
        return 1;
    }
    
    //repeatedly prompts user for menu option selection
    do{
        displayMenuOption();
        userChoice = getOption(userChoice); 

        switch(userChoice){
            case 1:
                //create a new patron, add them, and update the file
                patron = createNewPatron();
                addPatron(patrons, patron, &numPatron);
                overwriteFile(patrons, argv[1], numPatron);
                break;
            case 2:
                //get the user to select a patron, remove that patron from the array, and then updates the file
                displayPatrons(patrons, numPatron);
                patronOpt = getOption(patronOpt);

                removePatron(patrons, patronOpt-1, &numPatron);
                overwriteFile(patrons, argv[1], numPatron);
                break;
            case 3:
                //get the user to select a patron, modify that patron
                cout << "Enter the number of the patron you'd like to modify." << endl;
                displayPatrons(patrons, numPatron);
                patronOpt = getOption(patronOpt);
                modifyPatron(&patrons[patronOpt-1]);
                overwriteFile(patrons, argv[1], numPatron);
                break;
            case 4: 
                //get the user to select a patron, output that patron's data
                cout << "Enter the number of the patron you'd like to view." << endl;
                displayPatrons(patrons, numPatron);
                patronOpt = getOption(patronOpt);

                if(patronOpt <= numPatron){
                    cout << "First  Last ID Tickets" << endl;
                    patrons[patronOpt - 1].displayPatronData();
                }
                else{
                    cout << "Invalid Input" << endl;
                }

                break;
            case 0:
                //exit program
                break;
            default:
                cout << "Invalid Input." << endl;
        }
    }while(userChoice != 0);

    //destructs array
    delete [] patrons;
    return 0;
}


//Displays for patron modification (add tickets, purchase ride admit, edit name, exit to main menu) 
void displayModOptions(){
    cout << "1. Add tickets" << endl;
    cout << "2. Purchase admittance to ride" << endl;
    cout << "3. Edit name" << endl;
    cout << "0. Exit to main menu" << endl;
}

//Displays the first menus options (add patron, remove patron, etc.)
void displayMenuOption(){
    cout << "1. Add Patron" << endl;
    cout << "2. Remove Patron" << endl;
    cout << "3. Modify Patron" << endl;
    cout << "4. View Patron" << endl;
    cout << "0. Exit" << endl;
}

//Displays ride options (teacups, magic carpet, world tour) 
void displayRideMenu(){
    cout << "Ride (TicketCost)" << endl;
    cout << "1. Teacups (3 tickets)" << endl; 
    cout << "2. Magic Carpet (2 tickets)" << endl;
    cout << "3. World Tour (1 tickets)" << endl;
}

//Displays patron information
void displayPatrons(Patron patrons[], int numPatrons){
    for(int i = 0; i < numPatrons; i++){
        cout << i + 1 << ". ";
        patrons[i].displayName();
    }
}

//Reads preeixsting patron data
int readExistingPatrons(Patron patrons[], string fname){
    ifstream inputFile;
    string fName, lName;
    int patronNum, ticketNum;
    int totalPatron = 0;
    inputFile.open(fname);

    if(inputFile.is_open()){
        while(inputFile.good()){
            inputFile >> fName >> lName >> patronNum >> ticketNum;
            patrons[totalPatron].setFirstName(fName);
            patrons[totalPatron].setLastName(lName);
            patrons[totalPatron].setPatronNumber(patronNum);
            patrons[totalPatron].setNumTickets(ticketNum);
            totalPatron++;
        }
    }
    else{
        printFileNotFound();
        return -1;
    }
    return totalPatron;
}

//Prints file error
void printFileNotFound(){
    cout << "Patron File not found. Run the program again with the file name on the command line." << endl;
    cout << "Example: ./carnivalComplete patronList.txt" << endl;
}

//updates the supplied patron file
void overwriteFile(Patron patrons[], string fname, int numPatron){
    ofstream outputFile;
    string fName, lName;
    int patronNum, ticketNum;
    int totalPatron = 0;
    outputFile.open(fname);
    if(outputFile.is_open()){
       for(int i = 0; i < numPatron; i++){
            outputFile <<  patrons[i].getFirstName() << " " << patrons[i].getLastName() << " " << patrons[i].getPatronNumber() << " "<< patrons[i].getNumTickets();
            if(i != numPatron-1){
                outputFile << "\n";
            }
        }
    }
    else{
        printFileNotFound();
    }
}

//Creates a new patron object
Patron createNewPatron(){
    string first, last;
    char response;
    int numT, numP;
    int numRides = 0;

    cout << "Let's add a patron to the system!" << endl;
    cout << "Patron first and last name (Sara Davis): " << endl;
    cin >> first >> last;
    cout << "Patron idNumber (last 4 digits of phone number): " << endl;
    cin >> numP;
    
    Patron newPatron = Patron();
    newPatron.setFirstName(first);
    newPatron.setLastName(last);
    newPatron.setPatronNumber(numP);
    addTickets(&newPatron);

    cout << "Would they like to purchase ride admittance now? (Y or N)" << endl; 
    cin >> response;
    if(response != 'N' && response != 'n'){
        do{
            addRide(&newPatron);
            cout << "Would they like to purchase ride admittance now? (Y or N)" << endl; 
            cin >> response;
        }while(response != 'N' && response != 'n');

    }
    return newPatron;
}

//Adds a patron to the Patron array and increments the passed in numPatrons
void addPatron(Patron patrons[], Patron newPatron, int* numPatrons){
    patrons[*numPatrons] = newPatron;
    (*numPatrons)++;
}

//Removes a patron from the patron array
void removePatron(Patron patrons[], int optPatron, int* numPatrons){
    //iterates through array, and writes over the patron with following one
    for(int i = 0; i <= *numPatrons; i++){
        if (i < optPatron){
            patrons[i] = patrons[i];
        }
        else if (i > optPatron){
            patrons[i-1] = patrons[i];
        }
    }
    (*numPatrons)--;
    
}

//Changes a patron
void modifyPatron(Patron* patron){
    int modOpt = 1;
    do{
        displayModOptions();
        modOpt = getOption(modOpt);
        switch(modOpt){
            case 1:
                addTickets(patron);
                break;
            case 2:
                addRide(patron);
                break;
            case 3:
                editName(patron);
                break;
            case 0:
                break;
            default:
                cout << "Invalid Input" << endl;
                break;
        }
    }while(modOpt != 0);

}

//Edits a patron's name
void editName(Patron* patron){
    int userChoice;
    string firstName, lastName;

    cout << "Would you like to edit the:\n1. first \n2. last  \n3. whole name" << endl;
    cin >> userChoice;
    switch(userChoice){
        case 1:
            cout << "Enter edited first name." << endl;
            cin >> firstName;
            patron->setFirstName(firstName);
            break;
        case 2:
            cout << "Enter edited last name." << endl;
            cin >> lastName;
            patron->setLastName(lastName);
            break;
        case 3:
            cout << "Enter edited first and last name." << endl;
            cin >> firstName >> lastName;
            patron->setFirstName(firstName);
            patron->setLastName(lastName);
        default:
            cout << "Invalid Entry" << endl;
    }
}

//Add a number of tickets to a patron
void addTickets(Patron* patron){
    int numTickToAdd;
    int currencyOpt;
    double moneyAmount;
    double cost;

    Money currency = Money();
    CostCalculator<Money> calculator = CostCalculator<Money>();

    cout << "How many tickets would you like to add?" << endl;
    cin >> numTickToAdd;
    calculator.setAmount(numTickToAdd);
    cout << "Select the type of currency" << "\n1. American Currency (USD)" << "\n2. Madagascan Currency (Ariarys)" << endl;
    cin >> currencyOpt;
    switch(currencyOpt){
        case 1:
            currency.setUsCurrency(true);
            currency.setConversionRate(.75);
            break;
        case 2:
            currency.setUsCurrency(false);
            currency.setConversionRate(313);
            break;
        default:
            cout << "Invalid Input" << endl;
            break;
    }

    calculator.setCurrency(currency);
    calculator.calcCost();

    cost = calculator.getCost();
    cout << "Total Cost: " << cost << endl;

    cout << "Enter the amount of money provided by the patron: " << endl;
    cin >> moneyAmount;
    currency.setDollars( (int)(moneyAmount) );
    currency.setCents( (int)(moneyAmount * 100) % 100);

    if(moneyAmount >= cost ){
        patron -> setNumTickets( patron -> getNumTickets() + numTickToAdd );
        calculator.calcChange(moneyAmount);

        cout << calculator;  // usage of << overloader
    }
    else{
        cout << "Not enough money" << endl;
    }
}

//Add a ride to a patron
void addRide(Patron* patron){
    int userOpt, numTickets;
    Ride* newRide;

    cout << "Select the ride you'd like to add." << endl;
    displayRideMenu();
    cin >> userOpt;
    switch(userOpt){
        case 1:
            newRide = new Teacups();
            break;
        case 2:
            newRide = new MagicCarpet();
            break;
        case 3:
            newRide = new WorldTour();
            break;
        default:
            cout << "Invalid Input." << endl;
    }
    
    numTickets = newRide -> getNumTicketsNecessary();

    if(patron->getNumTickets() >= numTickets){
        patron->setNumTickets(patron->getNumTickets() - numTickets);
        patron -> addPatronRide(newRide);
    }
    else{
        cout << "Patron does not have enough tickets. Do they want to purchase more tickets?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> userOpt;
        if(userOpt == 1){
            addTickets(patron);
        }
    }
}

//template function to recieve user options
template <typename Type>
Type getOption( Type userChoice){
    cin >> userChoice;
    return userChoice;
}

//template friend function of costCalculator
template<class T>
ostream &operator << ( ostream& output,  CostCalculator<T>& calculator){
    output << "Your change is: " << calculator.getChange() << endl;
    return output;
}
