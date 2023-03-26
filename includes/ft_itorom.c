#include <stdio.h>

// Function to convert integer to Roman numeral
void intToRoman(int num)
{
    // Array to store Roman numerals
    char *thousands[] = {"", "M", "MM", "MMM"};
    char *hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char *tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char *ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    // Store thousands, hundreds, tens, and ones
    int thousands_digit, hundreds_digit, tens_digit, ones_digit;

    // Find the thousands, hundreds, tens, and ones digits
    thousands_digit = num / 1000;
    hundreds_digit = (num / 100) % 10;
    tens_digit = (num / 10) % 10;
    ones_digit = num % 10;

    // Print the thousands digit, if any
    if (thousands_digit > 0)
        printf("%s", thousands[thousands_digit]);

    // Print the hundreds digit, if any
    if (hundreds_digit > 0)
        printf("%s", hundreds[hundreds_digit]);

    // Print the tens digit, if any
    if (tens_digit > 0)
        printf("%s", tens[tens_digit]);

    // Print the ones digit, if any
    if (ones_digit > 0)
        printf("%s", ones[ones_digit]);
}

// Test function
int main(void)
{
    int num = 555;
    // Convert integer to Roman numeral
    intToRoman(num);

    return 0;
}