#include <iostream>
#include <string>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#endif

// Convert standard numbers to Khmer Numerals
std::string toKhmerNumerals(int number)
{
    std::string numStr = std::to_string(number);
    std::string khmerNum = "";
    std::string khmerDigits[] = {"០", "១", "២", "៣", "៤", "៥", "៦", "៧", "៨", "៩"};

    for (char c : numStr)
    {
        if (c >= '0' && c <= '9')
        {
            khmerNum += khmerDigits[c - '0'];
        }
        else
        {
            khmerNum += c;
        }
    }
    return khmerNum;
}

// Check for Gregorian leap year
bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main()
{

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    // Khmer solar months
    std::vector<std::string> khmerSolarMonths = {
        "មករា", "កុម្ភៈ", "មិនា", "មេសា", "ឧសភា", "មិថុនា",
        "កក្ដា", "សីហា", "កញ្ញា", "តុលា", "វិច្ឆិកា", "ធ្នូ"};

    // Days of the week in Khmer
    std::vector<std::string> khmerDaysOfWeek = {
        "អាទិត្យ", "ច័ន្ទ", "អង្គារ", "ពុធ", "ព្រហស្បតិ៍", "សុក្រ", "សៅរ៍"};

    // Khmer Lunar Months
    std::vector<std::string> khmerLunarMonths = {
        "មិគសិរ", "បុស្ស", "មាឃ", "ផល្គុន", "ចេត្រ", "ពិសាខ",
        "ជេស្ឋ", "អាសាឍ", "ស្រាពណ៍", "ភទ្របទ", "អស្សុជ", "កត្តិក"};

    // Zodiac Animals
    std::vector<std::string> zodiacAnimals = {
        "ជូត", "ឆ្លូវ", "ខាល", "ថោះ", "រោង", "ម្សាញ់",
        "មមី", "មមែ", "វក", "រកា", "ច", "កុរ"};

    int day, month, year;

    std::cout << "========== Khmer Calendar Converter (C++) ==========\n";
    std::cout << "Enter Day (1-31): ";
    std::cin >> day;
    std::cout << "Enter Month (1-12): ";
    std::cin >> month;
    std::cout << "Enter Year (e.g., 2026): ";
    std::cin >> year;

    // Basic Validation
    if (month < 1 || month > 12 || day < 1 || day > 31)
    {
        std::cout << "Invalid Date Input.\n";
        return 1;
    }

    // --- 1. CALCULATE SOLAR CALENDAR (ប្រតិទិនសកល) ---
    std::string solarDayStr = toKhmerNumerals(day);
    std::string solarYearStr = toKhmerNumerals(year);
    std::string solarMonthKh = khmerSolarMonths[month - 1];

    // Calculate Day of Week using Sakamoto's Algorithm
    int y = year - (month < 3);
    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    int dayOfWeekIndex = (y + y / 4 - y / 100 + y / 400 + t[month - 1] + day) % 7;
    std::string dayOfWeekKh = khmerDaysOfWeek[dayOfWeekIndex];

    // --- 2. CALCULATE LUNAR CALENDAR COMPONENTS (ប្រតិទិនចន្ទគតិ) ---
    // Calculate Buddhist Era (ព.ស.): Khmer New Year falls in April (Month 4)
    int buddhistYear = year + 543;
    if (month < 4 || (month == 4 && day < 14))
    {
        buddhistYear -= 1; // Shifts if before traditional Khmer New Year
    }
    std::string beYearStr = toKhmerNumerals(buddhistYear);

    // Get Zodiac Year (Simplified estimation based on Khmer lunar cycle rotation)
    std::string zodiac = zodiacAnimals[(year - 4) % 12];

    // Approximate Lunar Day and Phase (Simplified formula for presentation purposes)
    // Real-world calculations require finding cumulative Julian Days against the Metonic cycle
    int approxLunarDay = (day + (month * 2)) % 15;
    if (approxLunarDay == 0)
        approxLunarDay = 15;
    std::string moonPhase = (month % 2 == 0) ? "កើត" : "រោច"; // Alternate phase indicator
    std::string lunarDayStr = toKhmerNumerals(approxLunarDay);
    std::string lunarMonthKh = khmerLunarMonths[(month + 8) % 12]; // General lunar offset alignment

    // --- OUTPUT RESULT ---
    std::cout << "\n=========================================\n";
    std::cout << "  លទ្ធផលប្រតិទិនខ្មែរ (Khmer Calendar Result) \n";
    std::cout << "=========================================\n";

    // Solar Output
    std::cout << "-> ប្រតិទិនសកល (Solar Calendar):\n";
    std::cout << "   ថ្ងៃ" << dayOfWeekKh << " ទី" << solarDayStr << " ខែ" << solarMonthKh << " ឆ្នាំ" << solarYearStr << "\n\n";

    // Lunar Output
    std::cout << "-> ប្រតិទិនចន្ទគតិ (Lunar Calendar):\n";
    std::cout << "   ថ្ងៃ" << dayOfWeekKh << " " << lunarDayStr << moonPhase << " ខែ" << lunarMonthKh << " ឆ្នាំ" << zodiac << " ព.ស. " << beYearStr << "\n";
    std::cout << "=========================================\n";
    system("pause");
    return 0;
}