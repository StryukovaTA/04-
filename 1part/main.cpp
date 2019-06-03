#include <conio.h>
#include <cstring>
#include "byteprint.h"

using namespace std;

struct Student
{
    char name[17];
    uint16_t entr_year;
    float aver_mark;
    uint8_t gender : 1;
    uint16_t fin_courses;
    Student* headman;
};

int main()
{
    /*
    uint16_t first, second;
    char oper;
    cin >> first >> oper >> second;
    byte_calc( first, second, oper );
    */

    Student students[3];

    strcpy( students[0].name, "Nastya" );
    students[0].entr_year = 2018;
    students[0].aver_mark = 4.6f;
    students[0].gender = 0;
    students[0].fin_courses = 1;
    students[0].headman = nullptr;

    strcpy( students[0].name, "Valya" );
    students[1].entr_year = 2018;
    students[1].aver_mark = 3.4f;
    students[1].gender = 1;
    students[1].fin_courses = 1;
    students[1].headman = &students[0];

    strcpy( students[0].name, "Kolya" );
    students[1].entr_year = 2018;
    students[1].aver_mark = 4.3f;
    students[1].gender = 1;
    students[1].fin_courses = 1;
    students[1].headman = &students[0];

    cout << "Adres massiva: " << &students
         << "\nRazmer massiva: " << sizeof(students);
    cout << "\n\nAdres elementa massiva: " << &students[0]
         << "\nRazmer elementa massiva: " << sizeof(students[0])
         << "\nHexadecimal: ";
    print_in_hex( &students[0], sizeof( students[0] ) );
    cout << "\n\nAdres elementa massiva: " << &students[1]
         << "\nRazmer elementa massiva: " << sizeof(students[1])
         << "\nHexadecimal: ";
    print_in_hex( &students[1], sizeof( students[1] ) );
    cout << "\n\nAdres elementa massiva: " << &students[2]
         << "\nRazmer elementa massiva: " << sizeof(students[2])
         << "\nHexadecimal: ";
    print_in_hex( &students[2], sizeof( students[2] ) );

    cout << "\n\nDlya vtorogo elementa massiva:" << endl;

    cout << "\nName:"
         << "\nAdres: " << &students[1].name
         << "\nSmeshcheniye ot nachala: " << offsetof( Student, name )
         << "\nRazmer: " << sizeof( students[1].name )
         << "\nBinary: ";
    print_in_binary( &students[1].name, sizeof( students[1].name ) );
    cout << "\nHexadecimal: ";
    print_in_hex( &students[1].name, sizeof( students[1].name ) );

    cout << "\n\nEntrance year:"
         << "\nAdres: " << &students[1].entr_year
         << "\nSmeshcheniye ot nachala: " << offsetof( Student, entr_year )
         << "\nRazmer: " << sizeof( students[1].entr_year )
         << "\nBinary: ";
    print_in_binary( &students[1].entr_year, sizeof( students[1].entr_year ) );
    cout << "\nHexadecimal: ";
    print_in_hex( &students[1].entr_year, sizeof( students[1].entr_year ) );

    cout << "\n\nAverage mark:"
         << "\nAdres: " << &students[1].aver_mark
         << "\nSmeshcheniye ot nachala: " << offsetof( Student, aver_mark )
         << "\nRazmer: " << sizeof( students[1].aver_mark )
         << "\nBinary: ";
    print_in_binary( &students[1].aver_mark, sizeof( students[1].aver_mark ) );
    cout << "\nHexadecimal: ";
    print_in_hex( &students[1].aver_mark, sizeof( students[1].aver_mark ) );

    cout << "\n\nFinished courses:"
         << "\nAdres: " << &students[1].fin_courses
         << "\nSmeshcheniye ot nachala: " << offsetof( Student, fin_courses )
         << "\nRazmer: " << sizeof( students[1].fin_courses )
         << "\nBinary: ";
    print_in_binary( &students[1].fin_courses, sizeof( students[1].fin_courses ) );
    cout << "\nHexadecimal: ";
    print_in_hex( &students[1].fin_courses, sizeof( students[1].fin_courses ) );

    cout << "\n\nStarosta:"
         << "\nAdres: " << &students[1].headman
         << "\nSmeshcheniye ot nachala: " << offsetof( Student, headman )
         << "\nRazmer: " << sizeof( students[1].headman )
         << "\nBinary: ";
    print_in_binary( &students[1].headman, sizeof( students[1].headman ) );
    cout << "\nHexadecimal: ";
    print_in_hex( &students[1].headman, sizeof( students[1].headman ) );

    getch();
    return 0;
}
