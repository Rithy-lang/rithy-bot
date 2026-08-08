#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// ==========================================
// 1. មុខងារ LOGIN (គំរូ Username: admin, Password: 123)
// ==========================================
bool login()
{
    string username, password;
    int attempts = 0;

    while (attempts < 3)
    {
        cout << "\n=========================================\n";
        cout << "         ប្រព័ន្ធចូលប្រើប្រាស់ (LOGIN)         \n";
        cout << "=========================================\n";
        cout << "ឈ្មោះអ្នកប្រើប្រាស់ (Username): ";
        cin >> username;
        cout << "លេខកូដសម្ងាត់ (Password): ";
        cin >> password;

        if (username == "Toji" && password == "168")
        {
            cout << "\n=> ចូលប្រើប្រាស់ប្រព័ន្ធបានជោគជ័យ!\n";
            return true;
        }
        else
        {
            attempts++;
            cout << "=> ឈ្មោះ ឬលេខកូដខុស! (សល់ឱកាស " << 3 - attempts << " ដង)\n";
        }
    }
    return false;
}

// Struct សម្រាប់រក្សាទុកព័ត៌មានទំនិញរបស់អ្នកលក់ម្នាក់ៗ
struct Product
{
    string productName;
    double price;
    int quantitySold;
};

// Class សម្រាប់គ្រប់គ្រងព័ត៌មានអ្នកលក់
class Seller
{
public:
    int sellerID;
    string sellerName;
    string shopName;
    vector<Product> products;

    Seller(int id, string name, string shop)
    {
        sellerID = id;
        sellerName = name;
        shopName = shop;
    }
};

// ==========================================
// 2. ថ្នាក់គ្រប់គ្រងប្រព័ន្ធអាហារដ្ឋាន (Canteen Management)
// ==========================================
class CanteenManager
{
private:
    vector<Seller> sellers;
    string fileName = "sellers_data.txt";

public:
    CanteenManager()
    {
        loadFromFile(); // ផ្ទុកទិន្នន័យពី Text File ពេលបើកកម្មវិធី
    }

    // [CREATE] - បន្ថែមអ្នកលក់ថ្មី
    void createSeller()
    {
        int id;
        string name, shop;
        cout << "\n--- [CREATE] បន្ថែមព័ត៌មានអ្នកលក់ថ្មី ---\n";
        cout << "បញ្ចូល ID: ";
        cin >> id;

        // ពិនិត្យ ID ជាន់គ្នា
        for (const auto &s : sellers)
        {
            if (s.sellerID == id)
            {
                cout << "=> ជម្រាបសួរ! ID នេះមានរួចហើយនៅក្នុងប្រព័ន្ធ។\n";
                return;
            }
        }

        cin.ignore();
        cout << "បញ្ចូលឈ្មោះអ្នកលក់: ";
        getline(cin, name);
        cout << "បញ្ចូលឈ្មោះតូប/ហាង: ";
        getline(cin, shop);

        sellers.push_back(Seller(id, name, shop));
        saveToFile();
        cout << "=> បានរក្សាទុកទិន្នន័យអ្នកលក់ថ្មី!\n";
    }

    // [CREATE PRODUCT] - បន្ថែមទំនិញលក់ទៅឲ្យអ្នកលក់
    void addProductToSeller()
    {
        int id;
        cout << "\nបញ្ចូល ID អ្នកលក់ ដើម្បីបន្ថែមផលិតផល: ";
        cin >> id;
        for (auto &s : sellers)
        {
            if (s.sellerID == id)
            {
                Product p;
                cin.ignore();
                cout << "បញ្ចូលឈ្មោះផលិតផល: ";
                getline(cin, p.productName);
                cout << "បញ្ចូលតម្លៃ ($): ";
                cin >> p.price;
                cout << "បញ្ចូលចំនួនលក់ដាច់: ";
                cin >> p.quantitySold;

                s.products.push_back(p);
                saveToFile();
                cout << "=> បានបន្ថែមផលិតផលជោគជ័យ!\n";
                return;
            }
        }
        cout << "=> រកមិនឃើញអ្នកលក់ដែលមាន ID នេះទេ!\n";
    }

    // [READ] - បង្ហាញព័ត៌មានអ្នកលក់ និងទំនិញទាំងអស់
    void readAllSellers() const
    {
        cout << "\n======================================================\n";
        cout << "       [READ] របាយការណ៍អាហារដ្ឋាន សាលាភូមិន្ទភ្នំពេញ       \n";

        if (sellers.empty())
        {
            cout << "               មិនទាន់មានទិន្នន័យនៅឡើយទេ                \n";
            cout << "======================================================\n";
            return;
        }

        for (const auto &s : sellers)
        {
            cout << "\n------------------------------------------------------\n";
            cout << " ID អ្នកលក់: " << s.sellerID << " | ឈ្មោះ: " << s.sellerName
                 << " | ហាង: " << s.shopName << endl;
            cout << "------------------------------------------------------\n";
            cout << left << setw(20) << "ឈ្មោះទំនិញ"
                 << setw(12) << "តម្លៃ ($)"
                 << setw(15) << "ចំនួនលក់"
                 << setw(15) << "ចំណូល ($)" << endl;

            double totalRevenue = 0;
            for (const auto &p : s.products)
            {
                double totalProd = p.price * p.quantitySold;
                totalRevenue += totalProd;
                cout << left << setw(20) << p.productName
                     << setw(12) << fixed << setprecision(2) << p.price
                     << setw(15) << p.quantitySold
                     << setw(15) << totalProd << endl;
            }
            cout << ">>> ចំណូលសរុបរបស់ហាង: $" << totalRevenue << endl;
        }
        cout << "======================================================\n";
    }

    // [UPDATE] - កែប្រែព័ត៌មានអ្នកលក់
    void updateSeller()
    {
        int id;
        cout << "\n--- [UPDATE] កែប្រែព័ត៌មានអ្នកលក់ ---\n";
        cout << "បញ្ចូល ID អ្នកលក់ដែលចង់កែប្រែ: ";
        cin >> id;

        for (auto &s : sellers)
        {
            if (s.sellerID == id)
            {
                cin.ignore();
                cout << "ឈ្មោះចាស់: " << s.sellerName << " -> ប្ដូរទៅជា: ";
                getline(cin, s.sellerName);
                cout << "ហាងចាស់: " << s.shopName << " -> ប្ដូរទៅជា: ";
                getline(cin, s.shopName);
                saveToFile();
                cout << "=> បានកែប្រែព័ត៌មានដោយជោគជ័យ!\n";
                return;
            }
        }
        cout << "=> រកមិនឃើញអ្នកលក់ដែលមាន ID នេះទេ!\n";
    }

    // [DELETE] - លុបព័ត៌មានអ្នកលក់
    void deleteSeller()
    {
        int id;
        cout << "\n--- [DELETE] លុបព័ត៌មានអ្នកលក់ ---\n";
        cout << "បញ្ចូល ID អ្នកលក់ដែលចង់លុប: ";
        cin >> id;

        for (auto it = sellers.begin(); it != sellers.end(); ++it)
        {
            if (it->sellerID == id)
            {
                sellers.erase(it);
                saveToFile();
                cout << "=> បានលុបទិន្នន័យអ្នកលក់ចេញពីប្រព័ន្ធរួចរាល់!\n";
                return;
            }
        }
        cout << "=> រកមិនឃើញអ្នកលក់ដែលមាន ID នេះទេ!\n";
    }

    // ==========================================
    // 3. មុខងារ FILE HANDLING (Save & Load Text File)
    // ==========================================
    void saveToFile() const
    {
        ofstream outFile(fileName);
        if (!outFile)
            return;

        for (const auto &s : sellers)
        {
            // រក្សាទុកព័ត៌មានអ្នកលក់ (បំបែកដោយសញ្ញា | )
            outFile << s.sellerID << "|" << s.sellerName << "|" << s.shopName << "|" << s.products.size() << "\n";
            // រក្សាទុកផលិតផលរបស់គាត់
            for (const auto &p : s.products)
            {
                outFile << p.productName << "|" << p.price << "|" << p.quantitySold << "\n";
            }
        }
        outFile.close();
    }

    void loadFromFile()
    {
        ifstream inFile(fileName);
        if (!inFile)
            return; // បើមិនទាន់មាន File ទេ មិនបាច់ផ្ទុកទេ

        sellers.clear();
        int id, numProducts;
        string name, shop, line;

        while (inFile >> id)
        {
            inFile.ignore(); // រំលងសញ្ញា |
            getline(inFile, name, '|');
            getline(inFile, shop, '|');
            inFile >> numProducts;
            inFile.ignore(); // រំលង newline

            Seller s(id, name, shop);
            for (int i = 0; i < numProducts; ++i)
            {
                Product p;
                getline(inFile, p.productName, '|');
                inFile >> p.price;
                inFile.ignore();
                inFile >> p.quantitySold;
                inFile.ignore();
                s.products.push_back(p);
            }
            sellers.push_back(s);
        }
        inFile.close();
    }
};

// ==========================================
// MAIN FUNCTION
// ==========================================
int main()
{
    // ហៅមុខងារ Login ជាមុនសិន
    if (!login())
    {
        cout << "\nចូលប្រើប្រាស់បរាជ័យ! កម្មវិធីត្រូវបានបិទ។\n";
        return 0;
    }
    CanteenManager manager; // បន្ថែម Object manager នៅទីនេះ
    int choice;

    do
    {
        cout << "\n===== ប្រព័ន្ធគ្រប់គ្រងអាហារដ្ឋាន (CRUD & File System) =====\n";
        cout << "1. [CREATE] បន្ថែមព័ត៌មានអ្នកលក់ថ្មី\n";
        cout << "2. [CREATE] បន្ថែមផលិតផលទៅឲ្យអ្នកលក់\n";
        cout << "3. [READ]   បង្ហាញរបាយការណ៍អ្នកលក់ទាំងអស់\n";
        cout << "4. [UPDATE] កែប្រែព័ត៌មានអ្នកលក់\n";
        cout << "5. [DELETE] លុបព័ត៌មានអ្នកលក់\n";
        cout << "6. ចាកចេញពីកម្មវិធី (Exit)\n";
        cout << "សូមជ្រើសរើសជម្រើស (1-6): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            manager.createSeller();
            break;
        case 2:
            manager.addProductToSeller();
            break;
        case 3:
            manager.readAllSellers();
            break;
        case 4:
            manager.updateSeller();
            break;
        case 5:
            manager.deleteSeller();
            break;
        case 6:
            manager.saveToFile();
            cout << "\nរក្សាទុកទិន្នន័យ និងចាកចេញ... អរគុណ!🙏\n";
            break;
        default:
            cout << "=> ជម្រើសមិនត្រឹមត្រូវ! សូមជ្រើសរើសម្ដងទៀត។\n";
        }
    } while (choice != 6);
    cout << "\nសូមអរគុណ🙏ដែលប្រើប្រាស់ប្រព័ន្ធគ្រប់គ្រងអាហារដ្ឋាន!\n";
    cout << "សូមចូលប្រើប្រាស់ម្តងទៀតនៅពេលក្រោយ។\n";
    cout << "==========ហើយមួយទៀតបងស្រឡាញ់អូនBaby🥰==========\n";

    return 0;
}
