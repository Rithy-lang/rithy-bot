#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define MAX_HISTORY 10
#define MAX_LEN 500
#define EXCHANGE_RATE 4100.0

char history[MAX_HISTORY][MAX_LEN];
int count = 0;

/* ---------- ENGLISH ---------- */
char *ones[] = {"", "One", "Two", "Three", "Four", "Five",
                "Six", "Seven", "Eight", "Nine", "Ten",
                "Eleven", "Twelve", "Thirteen", "Fourteen",
                "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

char *tens[] = {"", "", "Twenty", "Thirty", "Forty",
                "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

/* ---------- KHMER ---------- */
char *kh_ones[] = {"", "មួយ", "ពីរ", "បី", "បួន", "ប្រាំ",
                   "ប្រាំមួយ", "ប្រាំពីរ", "ប្រាំបី", "ប្រាំបួន"};

char *kh_tens[] = {"", "ដប់", "ម្ភៃ", "សាមសិប", "សែសិប",
                   "ហាសិប", "ហុកសិប", "ចិតសិប", "ប៉ែតសិប", "កៅសិប"};

/* ---------- COMMON ---------- */
void append(char *result, const char *text)
{
    if (strlen(result) + strlen(text) < MAX_LEN - 1)
    {
        strcat(result, text);
    }
}

/* ---------- ENGLISH ---------- */
void numberToWords(long long num, char *result)
{
    if (num == 0)
        return;

    if (num >= 1000000000)
    {
        numberToWords(num / 1000000000, result);
        append(result, "Billion ");
        numberToWords(num % 1000000000, result);
    }
    else if (num >= 1000000)
    {
        numberToWords(num / 1000000, result);
        append(result, "Million ");
        numberToWords(num % 1000000, result);
    }
    else if (num >= 1000)
    {
        numberToWords(num / 1000, result);
        append(result, "Thousand ");
        numberToWords(num % 1000, result);
    }
    else if (num >= 100)
    {
        append(result, ones[num / 100]);
        append(result, " Hundred ");
        numberToWords(num % 100, result);
    }
    else if (num >= 20)
    {
        append(result, tens[num / 10]);
        append(result, " ");
        numberToWords(num % 10, result);
    }
    else
    {
        append(result, ones[num]);
        append(result, " ");
    }
}

/* ---------- KHMER ---------- */
void numberToKhmer(long long num, char *result)
{
    if (num == 0)
        return;

    if (num >= 1000000)
    {
        numberToKhmer(num / 1000000, result);
        append(result, "លាន ");
        numberToKhmer(num % 1000000, result);
    }
    else if (num >= 1000)
    {
        numberToKhmer(num / 1000, result);
        append(result, "ពាន់ ");
        numberToKhmer(num % 1000, result);
    }
    else if (num >= 100)
    {
        numberToKhmer(num / 100, result);
        append(result, "រយ ");
        numberToKhmer(num % 100, result);
    }
    else if (num >= 20)
    {
        append(result, kh_tens[num / 10]);
        if (num % 10 != 0)
        {
            append(result, " ");
            append(result, kh_ones[num % 10]);
        }
        append(result, " ");
    }
    else if (num >= 10)
    {
        append(result, "ដប់");
        if (num % 10 != 0)
        {
            append(result, kh_ones[num % 10]);
        }
        append(result, " ");
    }
    else
    {
        append(result, kh_ones[num]);
        append(result, " ");
    }
}

/* ---------- UTIL ---------- */
void clearScreen()
{
    system("cls");
}

void addHistory(char *text)
{
    if (count < MAX_HISTORY)
    {
        snprintf(history[count], MAX_LEN, "%s", text);
        count++;
    }
    else
    {
        for (int i = 1; i < MAX_HISTORY; i++)
        {
            strcpy(history[i - 1], history[i]);
        }
        snprintf(history[MAX_HISTORY - 1], MAX_LEN, "%s", text);
    }
}

void showHistory()
{
    if (count == 0)
    {
        printf("No history yet\n");
        return;
    }

    printf("\n===== HISTORY =====\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d. %s\n", i + 1, history[i]);
    }
}

/* ---------- ABOUT US ---------- */
void aboutUs()
{
    clearScreen();

    printf("\n========== ABOUT US ==========\n\n");

    printf("Developed by : SIN SOTIN\n");
    printf("Phone number : 078289172\n");
    printf("Gmail        : Sinsotin978@gmail.com\n");
    printf("Class        : E7\n");
    printf("Major        : Computer Science\n");
    printf("Group        : 8\n\n");

    printf("Group members:\n");
    printf("- SUM CHANREAKSA\n");
    printf("- SIN SOTIN\n");
    printf("- ﻿﻿﻿SIV KHEMRA\n");
    printf("- ﻿﻿﻿SROEUN PANHA\n");
    printf("- SENG LYSAK\n");

    printf("University   : Royal University Of Phnom Penh\n");

    printf("\n===============================\n");
    printf("Press any key to go back...");
    getch();
}

/* ---------- MAIN ---------- */
int main()
{

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int choice;
    long long num;

    do
    {
        printf("\n===== NUMBER TO WORD =====\n");
        printf("1. Convert Number to Words\n");
        printf("2. Clear Screen\n");
        printf("3. View History\n");
        printf("4. About Us\n");
        printf("5. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
        {
            printf("Enter number: ");
            scanf("%lld", &num);

            if (num < 0)
            {
                printf("Invalid number!\n");
                break;
            }

            char eng[MAX_LEN] = "";
            char kh[MAX_LEN] = "";

            if (num == 0)
            {
                strcpy(eng, "Zero");
                strcpy(kh, "សូន្យ");
            }
            else
            {
                numberToWords(num, eng);
                numberToKhmer(num, kh);
            }

            int len;

            len = strlen(eng);
            if (len > 0 && eng[len - 1] == ' ')
                eng[len - 1] = '\0';

            len = strlen(kh);
            if (len > 0 && kh[len - 1] == ' ')
                kh[len - 1] = '\0';

            double usd = num / EXCHANGE_RATE;

            printf("\n===== RESULT =====\n");
            printf("រៀល: %lld ៛\n", num);
            printf("English: %s Riel\n", eng);
            printf("Khmer: %s រៀល\n", kh);
            printf("USD: $%.2f\n", usd);

            char full[MAX_LEN];
            snprintf(full, MAX_LEN,
                     "%lld = %s | %s ($%.2f)",
                     num, eng, kh, usd);

            addHistory(full);
            break;
        }

        case 2:
            clearScreen();
            break;

        case 3:
            showHistory();
            break;

        case 4:
            aboutUs();
            break;

        case 5:
            printf("Goodbye!\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
