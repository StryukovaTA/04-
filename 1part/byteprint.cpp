#include "byteprint.h"

using namespace std;

char nibble_to_hex(uint8_t i)
{
    assert( 0x0 <= i && i <= 0xf );
    char digits[] = "0123456789abcdef";
    return digits[i];
}

char bit_digit(uint8_t byte, uint8_t bit)
{
    if( byte & ( 0x1 << bit ) )
        return '1';
    return '0';
}

void print_in_hex(uint8_t byte)
{
    cout << nibble_to_hex(byte >> 4)
         << nibble_to_hex(byte & 0xf);
}

void print_in_hex(const void* data, size_t datasize)
{
    const uint8_t* bytes = reinterpret_cast<const uint8_t*>(data);
    for( size_t i = 0; i < datasize; i++ )
    {
        print_in_hex( bytes[i] );
        if ( (i + 1) % 16 == 0)
            cout << '\n';
        else
            cout << ' ';
    }
}

void print_in_binary(uint8_t byte)
{
    for( int bit = 7; bit >= 0; bit-- )
        cout << bit_digit(byte, bit);
}

void print_in_binary(const void* data, size_t datasize)
{
    const uint8_t* bytes = reinterpret_cast<const uint8_t*>(data);
    for (size_t i = 0; i < datasize; i++)
    {
        print_in_binary(bytes[i]);
        if ( (i + 1) % 4 == 0 )
            cout << '\n';
        else
            cout << ' ';
    }
}

void byte_calc( uint16_t first, uint16_t second, char oper )
{
    uint16_t byteand = first & second;
    uint16_t byteor = first | second;
    uint16_t bytexor = first ^ second;
    switch( oper )
    {
        case '&':
            print_in_hex( &first, sizeof(first) );
            cout << "& ";
            print_in_hex( &second, sizeof(second) );
            cout << "= ";
            print_in_hex( &byteand, sizeof(byteand) );
            cout << "\n";
            print_in_binary( &first, sizeof(first) );
            cout << "& ";
            print_in_binary( &second, sizeof(second));
            cout << "= ";
            print_in_binary( &byteand, sizeof(byteand) );
            break;
        case '|':
            print_in_hex( &first, sizeof(first));
            cout << "| ";
            print_in_hex( &second, sizeof(second) );
            cout << "= ";
            print_in_hex( &byteand, sizeof(byteand) );
            cout << "\n";
            print_in_binary( &first, sizeof(first) );
            cout << "| ";
            print_in_binary( &second, sizeof(second) );
            cout << "= ";
            print_in_binary( &byteor, sizeof(byteor) );
            break;
        case '^':
            print_in_hex( &first, sizeof(first));
            cout << "^ ";
            print_in_hex( &second, sizeof(second) );
            cout << "= ";
            print_in_hex( &byteand, sizeof(byteand) );
            cout << "\n";
            print_in_binary( &first, sizeof(first) );
            cout << "^ ";
            print_in_binary( &second, sizeof(second) );
            cout << "= ";
            print_in_binary( &bytexor, sizeof(bytexor) );
            break;
    }
}
