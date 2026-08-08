#include <stdio.h>
#include <windows.h>

int main()

{
    int a, b, c;
    std::setlocale(LC_ALL, ".UTF-8");
    char latter;
    printf("inout latter: ");
    scanf(" %c", &latter);

    for (a = 0; a <= 10; ++a)
    {
        for (b = 0; b <= 10; ++b)
        {
            for (c = 0; c <= 10; ++c)
            {
                switch (latter)
                {
                case 'a':
                    printf("ខ្ញុំស្រឡាញ់អ្នក❤️😘");
                    break;
                case 'b':
                    printf("បងស្រឡាញ់អូន❤️😘");
                    break;
                case 'c':
                    printf("បើមានកូនស្រីសូមឲ្យស្អាតដូចអូន❤️😘");
                    break;
                default:
                    printf("ព្រមស្រឡាញ់បងទៅMy baby ❤️😘");
                    break;
                }
            }
        }
    }
    return 0;
}