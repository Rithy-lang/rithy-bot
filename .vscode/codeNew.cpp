#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

// ==========================================
// 1. មុខងារ LOGIN
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

        // ប្រសិនបើគ្មានទិន្នន័យក្នុង File ទេ កម្មវិធីនឹងបង្កើត Sample Data ឲ្យស្វ័យប្រវត្តិ
        if (sellers.empty())
        {
            seedSampleData();
        }
    }

    // មុខងារបង្កើត Sample Data ដំបូង
    void seedSampleData()
    {
        Seller s1(101, "សុខ ឆៃ", "ហាងបាយឆា 88");
        s1.products.push_back({"បាយឆាសាច់ជ្រូក", 2.50, 45});
        s1.products.push_back({"បាយឆាសាច់គោ", 3.00, 30});

        Seller s2(102, "ម៉ារីយ៉ា", "តូបកាហ្វេដី");
        s2.products.push_back({"កាហ្វេទឹកដោះគោទឹកកក", 1.50, 80});
        s2.products.push_back({"តែបៃតង", 1.25, 50});

        sellers.push_back(s1);
        sellers.push_back(s2);

        saveToFile(); // រក្សាទុកទិន្នន័យគំរូចូល File
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
                cout << "=> ID នេះមានរួចហើយនៅក្នុងប្រព័ន្ធ!\n";
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
            cout << left << setw(25) << "ឈ្មោះទំនិញ"
                 << setw(12) << "តម្លៃ ($)"
                 << setw(12) << "ចំនួនលក់"
                 << setw(12) << "ចំណូល ($)" << endl;

            double totalRevenue = 0;
            for (const auto &p : s.products)
            {
                double totalProd = p.price * p.quantitySold;
                totalRevenue += totalProd;
                cout << left << setw(25) << p.productName
                     << setw(12) << fixed << setprecision(2) << p.price
                     << setw(12) << p.quantitySold
                     << setw(12) << totalProd << endl;
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
            outFile << s.sellerID << "|" << s.sellerName << "|" << s.shopName << "|" << s.products.size() << "\n";
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
            return;

        sellers.clear();
        string line;

        while (getline(inFile, line))
        {
            if (line.empty())
                continue;

            stringstream ss(line);
            string idStr, name, shop, countStr;

            getline(ss, idStr, '|');
            getline(ss, name, '|');
            getline(ss, shop, '|');
            getline(ss, countStr, '|');

            int id = stoi(idStr);
            int numProducts = stoi(countStr);

            Seller s(id, name, shop);

            for (int i = 0; i < numProducts; ++i)
            {
                string pLine;
                if (getline(inFile, pLine))
                {
                    stringstream pss(pLine);
                    string pName, priceStr, qtyStr;

                    getline(pss, pName, '|');
                    getline(pss, priceStr, '|');
                    getline(pss, qtyStr, '|');

                    Product p;
                    p.productName = pName;
                    p.price = stod(priceStr);
                    p.quantitySold = stoi(qtyStr);

                    s.products.push_back(p);
                }
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

    CanteenManager manager; // ប្រកាស Manager Object
    int choice;             // ប្រកាស Variable choice

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
            cout << "\nរក្សាទុកទិន្នន័យ និងចាកចេញ... អរគុណ!🙏\n";
            break;
        default:
            cout << "=> ជម្រើសមិនត្រឹមត្រូវ! សូមជ្រើសរើសម្ដងទៀត។\n";
        }
    } while (choice != 6);

    cout << "\nសូមអរគុណ🙏ដែលប្រើប្រាស់ប្រព័ន្ធគ្រប់គ្រងអាហារដ្ឋាន!\n";
    cout << "សូមចូលប្រើប្រាស់ម្តងទៀតនៅពេលក្រោយ។\n";
    cout << "==========ហើយមួយទៀតបងស្រឡាញ់អូនBaby😘🥰";
    return 0;
}