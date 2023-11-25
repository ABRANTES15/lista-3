#include <stdio.h>
#include <string.h>

int roman_to_decimal(char roman) 
{
    switch (roman) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

void decimal_to_binary(int decimal,char* romano) 
    {
    char binary[13];
    int index = 0;

    while (decimal > 0) {
        binary[index++] = (decimal % 2) + '0';
        decimal /= 2;
    }

    if (index == 0) {
        binary[index++] = '0';
    }

    
    int start = 0;
    int end = index - 1;
    while (start < end) {
        char temp = binary[start];
        binary[start] = binary[end];
        binary[end] = temp;
        start++;
        end--;
    }

    printf("%s na base 2: %s\n", romano, binary);
}

void decimal_to_hexadecimal(int decimal,char* romano) 
{
    printf("%s na base 16: %X\n", romano, decimal);
}

int main() {
    char entrada[13];
    scanf("%s", entrada);

    int decimal = 0;
    int length = strlen(entrada);

    
    for (int i = 0; i < length; i++) 
    {
        if (i < length - 1 && roman_to_decimal(entrada[i]) < roman_to_decimal(entrada[i + 1]))
         {
            decimal -= roman_to_decimal(entrada[i]);
        } else {
            decimal += roman_to_decimal(entrada[i]);
        }
    }

    
    decimal_to_binary(decimal, entrada);
    printf("%s na base 10: %d\n", entrada, decimal);
    decimal_to_hexadecimal(decimal, entrada);

    return 0;
}