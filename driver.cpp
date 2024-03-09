/*!
 * Author: Nikola Tunguz
 * Date: 12/15/2022
 * Purpose: Create carnival ticketing system that tracks each patron's tickets 
 * and calculates whether customers need to purchase more tickets or not
 * Max park capacity is 300 on any given day, so set the patrons array using that
 * Max number of rides for a person is 100
 * NOTE: only include NECESSARY .h files and built in libraries in cpp files (you only need fstream in driver for example)
*/

#include "patron.h"
#include "costCalculator.h"
#include <fstream>
/*!
 * Displays the first menus options (add patron, remove patron, etc.)
 */
void displayMenuOption();


/*!
 * Displays menu options
 * Prompts user for menu option entry
 \return userChoice; the users integer value entry
*/
//int getMenuOption();


/*! adds a patron to the Patron array and increments the passed in numPatrons
 \param patronArray; an array of patron objects
 \param newPatron; a patron object to add to the patron array
 \param numPatrons; a pointer to the total number of patrons in the array (must be dereferenced to increase)
*/
void addPatron(Patron[], Patron, int*);
/*! Reads all existing patron data from file name that was provided on the command line in driver; adds patron data to the patron array
 \param patronArray; an array of patron objects
 \param fileName; a string pulled from argv in main and passed in
 */
int readExistingPatrons(Patron[], string);
/*! Display file not found message
*/
void printFileNotFound();
/*! Displays all patron first and last name by looping through each patron in the array and calling the display name method in patron
 \param patronArray; an array of patron objects;
 \param numPatrons; an int value of the number of patrons in the array
*/
void displayPatrons(Patron[], int);


/*! Displays all patron first and last name options
 * Prompts user for menu option entry
 \param patronArray; an array of patron objects;
 \param numPatrons; an int value of the number of patrons in the array
 \return userChoice; the users integer value entry.
*/
//int getPatronOption(Patron[], int numPatrons);


/*! Removes a patron from the patron array
 * Loops through each patron and moves every entry after the selected entry up one address space in the array
 * This means that the last element in the array is in there twice, but that's okay! We're keeping track of the number of patrons
 \param patronArrray; an array  of patron objects
 \param patronToRemove; an integer value entered by the user to remove. Corresponds to array index + 1
 \param numPatrons; a pointer to the number of useful patrons in the array (must be dereferenced to decrease)
*/
void removePatron(Patron[], int, int*);
/*! Creates a new patron object
 * prompts the user for input and collects it
 * sets the new patron's information using the user's input
 \return newPatron; a patron object
*/
Patron createNewPatron();
/*! Modifies a selected patron's information
 \param patron; a pointer to the patron object to be edited
*/
void modifyPatron(Patron*);
/*! Displays all of the options for patron modification (add tickets, purchase ride admit, edit name, exit to main menu) */
void displayModOptions();
/*! Displays all of the options for ride addition (teacups, magic carpet, world tour) */
void displayRideMenu();

/*! Displays ride menu options
 * Prompts user for menu option entry
 \return userChoice; the users integer value entry
*/
//int getModOption();

/*! Add a number of tickets to a patron
 * Prompt the user for the number of tickets they'd like to add
 * set the patron's number of tickets to be equal to the sum of the existing patron tickets and the tickets to add
 \param patron; a pointer to the patron object to modify. 
*/
void addTickets(Patron*);
/*! Add a ride to a patron ride array
 * Prompt the user for the ride they'd like to add
 * Take the user choice to determine which ride object to create (teacup, worldtour, or magic carpet)
 * add the ride object to the end of the patron's ride array if the patron has enough tickets to purchase admission
 * Otherwise prompt and ask if they'd like to purchase more tickets.
 \param patron; a pointer to the patron object to modify. 
*/
void addRide(Patron*);
/*! Edits a user name (first, last, or both)
 * Prompt the user for the portion of the name they'd like to edit (first, last, both)
 * Prompt user to enter new information
 * set the  selected name variables using user input
 \param patron; a pointer to the patron object to modify. 
*/
void editName(Patron*);
/*! overwrite the supplied patron file (from the command line arguments) so that the list of patrons is updated. Make sure it follows the same format as the provided patronList.txt file
 * create output stream object using file name.
 * loop through patron array and output first name, last name, patron number, and number of remaining tickets to the filestream
 \param patronArray; array of patron objects
 \param fileName; string name of the file from the command line
 \param numPatron; number of patrons in array
*/
void overwriteFile(Patron[], string, int);

/*! This is your main function. It should make sure the correct number of arguments was supplied (2)
 * if not, use the printFileNotFound method
 * creates the main menu by repeatedly prompting user for their menu option selection and then selecting the appropriate methods from the driver to call
 * If 1, create a new patron,, add them, and overwrite the file
 * If 2, get the user to select a patron, remove that patron from the array, and then overwrite the file
 * If 3, get the user to select a patron, modify that patron
 * If 4, get the user to select a patron, output that patron's data (using Patron displayPatronData method)
 * If 0, exit program
 \param argc; integer number of arguments on the command line
 \param argv; 2d character array of all arguments from command line (remember, the 0th argument is always your run prompt ./amusementPark)
*/

template<class T>
ostream &operator << ( ostream& output, CostCalculator<T>& calculator);

template <typename Type>
Type getOption(Type userChoice);


int main(int argc, char* argv[]){
    int userChoice = 1;
    int patronOpt = 0;

    Patron* patrons = new Patron[100]; 
    int numPatron = 0;

    Patron patron ;
    if (argc > 1)
    {
        numPatron = readExistingPatrons(patrons, argv[1]);
    }
    else{
        printFileNotFound();
        return 1;
    }
    
    
    do{
        displayMenuOption();
        userChoice = getOption(userChoice); 

        switch(userChoice){
            case 1:
                patron = createNewPatron();
                addPatron(patrons, patron, &numPatron);
                overwriteFile(patrons, argv[1], numPatron);
                break;
            case 2:
                displayPatrons(patrons, numPatron);
                patronOpt = getOption(patronOpt);

                removePatron(patrons, patronOpt-1, &numPatron);
                overwriteFile(patrons, argv[1], numPatron);
                break;
            case 3:
                cout << "Enter the number of the patron you'd like to modify." << endl;
                displayPatrons(patrons, numPatron);
                patronOpt = getOption(patronOpt);
                modifyPatron(&patrons[patronOpt-1]);
                overwriteFile(patrons, argv[1], numPatron);
                break;
            case 4: 
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
                break;
            default:
                cout << "Invalid Input." << endl;
        }
    }while(userChoice != 0);

    delete [] patrons;
    return 0;
}

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

void displayModOptions(){
    cout << "1. Add tickets" << endl;
    cout << "2. Purchase admittance to ride" << endl;
    cout << "3. Edit name" << endl;
    cout << "0. Exit to main menu" << endl;
}

void displayMenuOption(){
    cout << "1. Add Patron" << endl;
    cout << "2. Remove Patron" << endl;
    cout << "3. Modify Patron" << endl;
    cout << "4. View Patron" << endl;
    cout << "0. Exit" << endl;
}

void displayRideMenu(){
    cout << "Ride (TicketCost)" << endl;
    cout << "1. Teacups (3 tickets)" << endl; 
    cout << "2. Magic Carpet (2 tickets)" << endl;
    cout << "3. World Tour (1 tickets)" << endl;
}

template <typename Type>
Type getOption( Type userChoice){
    cin >> userChoice;
    return userChoice;
}

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

        cout << calculator;                                                        // usage of << overloader
    }
    else{
        cout << "Not enough money" << endl;
    }
}

void addRide(Patron* patron){
    int userOpt, numTickets;
    cout << "Select the ride you'd like to add." << endl;
    displayRideMenu();
    cin >> userOpt;

    Ride* newRide;
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

void displayPatrons(Patron patrons[], int numPatrons){
    for(int i = 0; i < numPatrons; i++){
        cout << i + 1 << ". ";
        patrons[i].displayName();
    }
}

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
    //cout << "How many tickets would they like to purchase? " << endl;
    //cin >> numT;
    //Ride* rides[100];
    Patron newPatron = Patron(); //(first, last, numP, numRides, numT, *rides);
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

void addPatron(Patron patrons[], Patron newPatron, int* numPatrons){
    patrons[*numPatrons] = newPatron;
    (*numPatrons)++;
}

void removePatron(Patron patrons[], int optPatron, int* numPatrons){
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

void printFileNotFound(){
    cout << "Patron File not found. Run the program again with the file name on the command line." <<endl;
}

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

template<class T>
ostream &operator << ( ostream& output,  CostCalculator<T>& calculator){
    output << "Your change is: " << calculator.getChange() << endl;
}
