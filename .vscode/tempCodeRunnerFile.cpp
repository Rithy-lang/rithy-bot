#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include <limits>
#include <fstream>
#include <sstream>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

using namespace std;

// Canteen Vendor & Product Sales Management System
// (Royal University of Phnom Penh)

// File that stores registered accounts, one "username password" pair per line.
const string USERS_FILE = "users.dat";

// ---- Table column widths (used by the boxed table display) ----
const int W_ID = 11;
const int W_TYPE = 11;
const int W_NAME = 21;
const int W_GENDER = 9;
const int W_AGE = 7;
const int W_PRODUCT = 23;
const int W_CONTACT = 15;

// Name of the file used to persist vendor/customer records between runs
const string DB_FILE = "vendors_data.txt";

class Vendor
{
private:
    string id;               // Stall Number (e.g., A01)
    int age;                 // Age
    string name;             // Vendor/Customer Name
    string product, contact; // Product Sold/Bought, Contact
    char gender;             // Gender
    string type;             // "Vendor" or "Customer"

public:
    // Methods
    void addVendor();
    void displayVendor();
    void searchVendor();
    void menu();
    void header();

    // Get methods
    string getId();
    string getName();
    string getProduct();
    string getType();
    string getContact();
    char getGender();
    int getAge();

    // Set methods (useful for editing)
    void editVendor();

    // Used when loading saved records back from the database file
    void setData(const string &id_, const string &type_, const string &name_,
                 char gender_, int age_, const string &product_, const string &contact_);
};

// Returns the current date & time as a formatted string, e.g. "2026-07-11 14:32:05"
string currentTimestamp()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buf[32];
    snprintf(buf, sizeof(buf), "%04d-%02d-%02d %02d:%02d:%02d",
             1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday,
             ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
    return string(buf);
}

// Prompts for a name and keeps asking until the input contains only
// letters and spaces (no numbers or symbols).
string askValidName(const string &prompt)
{
    string input;
    while (true)
    {
        cout << prompt;
        getline(cin, input);

        bool valid = !input.empty();
        for (char c : input)
        {
            if (!isalpha(static_cast<unsigned char>(c)) && c != ' ')
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            return input;
        }
        else
        {
            cout << "Invalid name. Please use letters and spaces only (no numbers or symbols).\n";
        }
    }
}

// Prompts the user to specify whether this entry is a Vendor or a Customer.
// Keeps asking until valid input ('V' or 'C', case-insensitive) is given.
string askType()
{
    char input;
    while (true)
    {
        cout << "Is this a Vendor or Customer? (V/C): ";
        cin >> input;
        input = toupper(input);
        if (input == 'V')
        {
            return "Vendor";
        }
        else if (input == 'C')
        {
            return "Customer";
        }
        else
        {
            cout << "Invalid input. Please enter 'V' for Vendor or 'C' for Customer.\n";
        }
    }
}

// ---- Database persistence (save/load to a text file) ----
// Records are stored one-per-line, fields separated by '|'.
void saveDatabase(Vendor vendor[], int n)
{
    ofstream out(DB_FILE);
    if (!out)
    {
        cout << "[Warning] Could not save database to " << DB_FILE << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        out << vendor[i].getId() << "|"
            << vendor[i].getType() << "|"
            << vendor[i].getName() << "|"
            << vendor[i].getGender() << "|"
            << vendor[i].getAge() << "|"
            << vendor[i].getProduct() << "|"
            << vendor[i].getContact() << "\n";
    }
}

int loadDatabase(Vendor vendor[])
{
    ifstream in(DB_FILE);
    if (!in)
    {
        return 0; // no existing database file yet, start fresh
    }

    string line;
    int n = 0;
    while (getline(in, line) && n < 100)
    {
        if (line.empty())
            continue;

        vector<string> fields;
        stringstream ss(line);
        string field;
        while (getline(ss, field, '|'))
        {
            fields.push_back(field);
        }

        if (fields.size() < 7)
            continue; // skip malformed lines

        char genderChar = fields[3].empty() ? ' ' : fields[3][0];
        int ageVal = 0;
        try
        {
            ageVal = stoi(fields[4]);
        }
        catch (...)
        {
            ageVal = 0;
        }

        vendor[n].setData(fields[0], fields[1], fields[2], genderChar, ageVal, fields[5], fields[6]);
        n++;
    }
    return n;
}

// ---- Boxed table helpers ----
void printSeparator()
{
    cout << "+" << string(W_ID, '-')
         << "+" << string(W_TYPE, '-')
         << "+" << string(W_NAME, '-')
         << "+" << string(W_GENDER, '-')
         << "+" << string(W_AGE, '-')
         << "+" << string(W_PRODUCT, '-')
         << "+" << string(W_CONTACT, '-')
         << "+" << endl;
}

// Truncates text that is too long for its column, adding "..." so the
// table stays perfectly aligned no matter how long the input was.
string fitCell(const string &text, int width)
{
    if ((int)text.size() > width)
    {
        if (width <= 3)
            return text.substr(0, width);
        return text.substr(0, width - 3) + "...";
    }
    return text;
}

// ==================== Account Login / Registration ====================

// Reads a password from the keyboard character-by-character, printing '*'
// for each character typed instead of the real character, and supporting
// backspace. Works on both Windows (conio.h) and Linux/macOS (termios).
string readMaskedPassword()
{
    string password;

#ifdef _WIN32
    char ch;
    while ((ch = _getch()) != '\r' && ch != '\n')
    {
        if (ch == '\b' || ch == 127)
        { // backspace
            if (!password.empty())
            {
                password.pop_back();
                cout << "\b \b" << flush;
            }
        }
        else
        {
            password += ch;
            cout << '*' << flush;
        }
    }
    cout << endl;
#else
    termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // turn off canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (ch == 127 || ch == '\b')
        { // backspace (127 on most terminals)
            if (!password.empty())
            {
                password.pop_back();
                cout << "\b \b" << flush;
            }
        }
        else
        {
            password += static_cast<char>(ch);
            cout << '*' << flush;
        }
    }
    cout << endl;

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore terminal settings
#endif

    return password;
}

// Checks whether a username is already taken.
bool usernameExists(const string &username)
{
    ifstream file(USERS_FILE);
    string u, p;
    while (file >> u >> p)
    {
        if (u == username)
        {
            return true;
        }
    }
    return false;
}

// ---- Register a new account ----
void registerUser()
{
    string username, password;

    cout << "\n===== REGISTER NEW ACCOUNT =====\n";
    cout << "Choose a Username: ";
    cin >> username;

    if (usernameExists(username))
    {
        cout << "==> That username is already taken. Please choose another, or log in instead.\n";
        return;
    }

    cout << "Choose a Password: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    password = readMaskedPassword();

    if (password.empty())
    {
        cout << "==> Password cannot be empty. Registration cancelled.\n";
        return;
    }

    ofstream file(USERS_FILE, ios::app);
    if (!file)
    {
        cout << "==> Could not write to " << USERS_FILE << ". Registration failed.\n";
        return;
    }
    file << username << " " << password << endl;
    file.close();

    cout << "==> Account created successfully! You can now log in.\n";
}

// ---- Log in to an existing account ----
bool attemptLogin()
{
    string username, password, u, p;

    cout << "\n===== LOGIN =====\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    password = readMaskedPassword();

    ifstream file(USERS_FILE);
    if (!file)
    {
        cout << "==> No accounts have been registered yet. Please register first.\n";
        return false;
    }

    while (file >> u >> p)
    {
        if (u == username && p == password)
        {
            cout << "\n==> Login successful! Welcome, " << username << ".\n";
            return true;
        }
    }

    cout << "\n==> Invalid username or password.\n";
    return false;
}

// Runs the account-access gate (register/login) before the main system
// is allowed to start. Returns true once the user is authenticated,
// false if they should be exited out of the program (too many attempts).
bool accountAccessGate()
{
    const int MAX_ATTEMPTS = 3;
    int choice;

    cout << "=====================================" << endl;
    cout << ">>> Canteen Vendor - Account Access <<<" << endl;
    cout << "=====================================" << endl;
    cout << "[1] ចុះឈ្មោះ (អ្នកប្រើប្រាស់ថ្មី)[Register (new user)]" << endl;
    cout << "[2] ចូល (Login)" << endl;
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1)
    {
        registerUser();
        cout << "\nPlease log in with your new account below.\n";
    }

    int attempts = 0;
    while (attempts < MAX_ATTEMPTS)
    {
        if (attemptLogin())
        {
            return true;
        }
        attempts++;
        if (attempts < MAX_ATTEMPTS)
        {
            cout << "Attempts remaining: " << (MAX_ATTEMPTS - attempts) << "\n";
        }
    }

    cout << "\nToo many failed attempts. Exiting.\n";
    return false;
}

// ==================== Program Entry Point ====================

int main()
{
    // Require a successful login/registration before the vendor system starts.
    if (!accountAccessGate())
    {
        return 0;
    }
    cout << "\nLaunching Vendor Management System...\n"
         << endl;

    Vendor vendor[100];
    int n = loadDatabase(vendor); // Load any previously saved records
    if (n > 0)
    {
        cout << n << " saved record(s) loaded from " << DB_FILE << ".\n"
             << endl;
    }

    string vId;
    string vName;
    int choice;
    vector<string> history; // Stores a log of every action performed this session

    while (true)
    {
        vendor[0].menu();
        cout << "===================================" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Add Vendor/Customer
            if (n < 100)
            {
                cout << "=====+Add Vendor/Customer+=====" << endl;
                vendor[n].addVendor();
                history.push_back("[" + currentTimestamp() + "] ADDED " + vendor[n].getType() + " - Stall No: " +
                                  vendor[n].getId() + ", Vendor/Customer Name: " + vendor[n].getName() +
                                  ", Product Sold/Bought: " + vendor[n].getProduct());
                n++;
                saveDatabase(vendor, n);
                cout << endl
                     << " +Vendor added successfully !!!" << endl;
            }
            else
            {
                cout << "Database full!" << endl;
            }
            break;

        case 2: // List all Vendors/Customers
            if (n == 0)
            {
                cout << "No vendors registered yet." << endl;
            }
            else
            {
                vendor[0].header();
                for (int i = 0; i < n; i++)
                {
                    vendor[i].displayVendor();
                }
                printSeparator();
            }
            break;

        case 3:
        { // Search Vendor/Customer
            cout << "===== Search Vendor/Customer =====" << endl;
            vendor[0].searchVendor();
            cout << "Your choice: ";
            cin >> choice;

            bool found = false;
            if (choice == 1)
            { // Search by Stall Number
                cout << "Input the Stall Number to search: ";
                cin >> vId;
                for (int i = 0; i < n; i++)
                {
                    if (vId == vendor[i].getId())
                    {
                        vendor[i].header();
                        vendor[i].displayVendor();
                        printSeparator();
                        found = true;
                        break; // Stop looking once found
                    }
                }
                if (!found)
                {
                    cout << ">> Stall Number " << vId << " not found....!!!" << endl;
                }
            }
            else if (choice == 2)
            { // Search by Name
                cout << "Input the Vendor/Customer Name to search: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, vName);
                bool headerPrinted = false;
                for (int i = 0; i < n; i++)
                {
                    if (vName == vendor[i].getName())
                    {
                        if (!headerPrinted)
                        {
                            vendor[i].header();
                            headerPrinted = true;
                        }
                        vendor[i].displayVendor();
                        found = true;
                    }
                }
                if (found)
                {
                    printSeparator();
                }
                else
                {
                    cout << ">> Vendor/Customer Name \"" << vName << "\" not found....!!!" << endl;
                }
            }
            break;
        }

        case 4:
        { // Edit Vendor/Customer
            cout << "Input the Stall Number to Edit (Vendor/Customer): ";
            cin >> vId;
            bool found = false;
            for (int i = 0; i < n; i++)
            {
                if (vId == vendor[i].getId())
                {
                    cout << "--- Current Data ---" << endl;
                    vendor[i].header();
                    vendor[i].displayVendor();
                    printSeparator();
                    cout << "--- Enter New Data ---" << endl;
                    vendor[i].editVendor();
                    history.push_back("[" + currentTimestamp() + "] EDITED " + vendor[i].getType() + " - Stall No: " +
                                      vendor[i].getId() + ", New Vendor/Customer Name: " + vendor[i].getName() +
                                      ", New Product Sold/Bought: " + vendor[i].getProduct());
                    saveDatabase(vendor, n);
                    cout << "Updated successfully!" << endl;
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Stall Number not found!" << endl;
            break;
        }

        case 5: // View History
            if (history.empty())
            {
                cout << "No history yet. Nothing has been entered this session." << endl;
            }
            else
            {
                cout << "===================================" << endl;
                cout << ">>> Input History (this session) <<<" << endl;
                cout << "===================================" << endl;
                for (size_t i = 0; i < history.size(); i++)
                {
                    cout << i + 1 << ". " << history[i] << endl;
                }
            }
            break;

        case 6:
        { // Delete Vendor/Customer
            cout << "Input the Stall Number to Delete (Vendor/Customer): ";
            cin >> vId;
            bool found = false;
            for (int i = 0; i < n; i++)
            {
                if (vId == vendor[i].getId())
                {
                    history.push_back("[" + currentTimestamp() + "] DELETED " + vendor[i].getType() + " - Stall No: " +
                                      vendor[i].getId() + ", Vendor/Customer Name: " + vendor[i].getName());
                    // Shift remaining elements left to overwrite deleted one
                    for (int j = i; j < n - 1; j++)
                    {
                        vendor[j] = vendor[j + 1];
                    }
                    n--; // Reduce count
                    saveDatabase(vendor, n);
                    cout << "Deleted vendor successfully!" << endl;
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Stall Number not found!" << endl;
            break;
        }

        case 7: // Exit Program
            saveDatabase(vendor, n);
            cout << "All data saved to " << DB_FILE << ". Exiting program. Goodbye!" << endl;
            return 0;

        default:
            cout << "Invalid option! Please try again." << endl;
        }
        cout << "\n";
    }
    return 0;
}

// ---- Class Method Implementations ----

void Vendor::menu()
{
    cout << "=====================================" << endl;
    cout << ">>>Canteen Vendor Management System<<<" << endl;
    cout << "=====================================" << endl;
    cout << "[1].បន្ថែមអ្នកផ្គត់ផ្គង់/អតិថិជន(Add Vendor/Customer)" << endl;
    cout << "[2].រាយបញ្ជីអ្នកផ្គត់ផ្គង់/អតិថិជនទាំងអស់(List all vendors/customers)" << endl;
    cout << "[3].ស្វែងរកអ្នកផ្គត់ផ្គង់/អតិថិជន(Search vendor/customer)" << endl;
    cout << "[4].កែសម្រួលអ្នកផ្គត់ផ្គង់/អតិថិជន(Edit vendor/customer)" << endl;
    cout << "[5].មើលប្រវត្តិ(View History)" << endl;
    cout << "[6].លុបអ្នកផ្គត់ផ្គង់/អតិថិជន(Delete vendor/customer)" << endl;
    cout << "[7].ចេញពីកម្មវិធី(Exit Program)" << endl;
}

void Vendor::addVendor()
{
    cout << "Stall Number: ";
    cin >> id;
    type = askType();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    name = askValidName("Vendor/Customer Name: ");
    cout << "Gender (M/F): ";
    cin >> gender;
    cout << "Age: ";
    cin >> age;
    cout << "Product Sold/Bought: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, product);
    cout << "Contact: ";
    getline(cin, contact);
}

void Vendor::editVendor()
{
    // Keeps Stall Number the same, edits other details
    type = askType();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    name = askValidName("New Vendor/Customer Name: ");
    cout << "New Gender (M/F): ";
    cin >> gender;
    cout << "New Age: ";
    cin >> age;
    cout << "New Product Sold/Bought: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, product);
    cout << "New Contact: ";
    getline(cin, contact);
}

// Boxed table header, e.g.
// +-----------+-----------+---------------------+---------+-------+-----------------------+---------------+
// | Stall No  | Type      | Vendor/Customer     | Gender  | Age   | Product               | Contact       |
// +-----------+-----------+---------------------+---------+-------+-----------------------+---------------+
void Vendor::header()
{
    printSeparator();
    cout << "|" << setw(W_ID) << left << " Stall No"
         << "|" << setw(W_TYPE) << left << " Type"
         << "|" << setw(W_NAME) << left << " Vendor/Customer"
         << "|" << setw(W_GENDER) << left << " Gender"
         << "|" << setw(W_AGE) << left << " Age"
         << "|" << setw(W_PRODUCT) << left << " Product"
         << "|" << setw(W_CONTACT) << left << " Contact"
         << "|" << endl;
    printSeparator();
}

void Vendor::displayVendor()
{
    cout << "|" << setw(W_ID) << left << (" " + fitCell(id, W_ID - 1))
         << "|" << setw(W_TYPE) << left << (" " + fitCell(type, W_TYPE - 1))
         << "|" << setw(W_NAME) << left << (" " + fitCell(name, W_NAME - 1))
         << "|" << setw(W_GENDER) << left << (" " + string(1, gender))
         << "|" << setw(W_AGE) << left << (" " + to_string(age))
         << "|" << setw(W_PRODUCT) << left << (" " + fitCell(product, W_PRODUCT - 1))
         << "|" << setw(W_CONTACT) << left << (" " + fitCell(contact, W_CONTACT - 1))
         << "|" << endl;
}

void Vendor::searchVendor()
{
    cout << "[1].Search by Stall Number" << endl;
    cout << "[2].Search by Vendor/Customer Name" << endl;
}

string Vendor::getId()
{
    return id;
}

string Vendor::getName()
{
    return name;
}

string Vendor::getProduct()
{
    return product;
}

string Vendor::getType()
{
    return type;
}

string Vendor::getContact()
{
    return contact;
}

char Vendor::getGender()
{
    return gender;
}

int Vendor::getAge()
{
    return age;
}

void Vendor::setData(const string &id_, const string &type_, const string &name_,
                     char gender_, int age_, const string &product_, const string &contact_)
{
    id = id_;
    type = type_;
    name = name_;
    gender = gender_;
    age = age_;
    product = product_;
    contact = contact_;
}
