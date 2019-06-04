#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const size_t MAX_SIZE = 256;
const size_t MAX_EXTENSION = 3;
const char* forbidden =  "*<>?|\"";

int main()
{
    char text[MAX_SIZE];
    cout << "Enter file name: ";
    fgets(text, MAX_SIZE, stdin);
    char* filename = text;
    filename[strlen(filename) - 1] = '\0';  //strlen возвращает в байтах длину строки
    while(true) {
        if( strcspn( filename, forbidden ) == strlen( filename ) ) ;//Длина начального участка строки, не содержащая символов указанных в аргументе
        else {
            cout << "Invalid format";
            break;
        }

        if( strchr( filename, ':' ) == nullptr ) ;  //strchr выполняет поиск первого вхождения символа : в filename
        else {
            char* colon = strchr(filename,':');
            if( colon - filename + 1 <= 1 ) {
                cout << "Invalid format";
                break;
            }
            while( colon != nullptr ) {
                if( isalpha( filename[colon - filename - 1] ) > 0 && //isalpha() возвращает ненулевое значение, если его аргумент является буквой алфавита (верхнего или нижнего регистра). В противном случае возвращается 0.
                    filename[colon - filename + 1] == '\\')
                    colon = strchr(colon + 1, ':');
                else {
                    cout << "Invalid format";
                    break;
                }
            }
        }

        if( strrchr( filename, '.' ) == nullptr ) //ищет последнее вхождение символа
            strcat( filename, ".txt" ); //strcat() присоединяет к строке str1 копию строки str2 и завершает строку str1 нулевым символом


        else {
            char* ext = strrchr( filename, '.' );
            for( int i = 1; ext[i] != '\0'; i ++ )
                *(ext + i) = char(tolower(*(ext + i)));
            if( strncmp( ext, ".txt", MAX_EXTENSION + 1 ) == 0 ) ; //strncmp – сравнение строк с ограничением количества сравниваемых символов.
//0 – если первые n символов сравниваемых строк идентичны.
//Положительное число – если в первых n символах сравниваемых строк есть отличия и код первого отличающегося символа в строке str1 больше кода символа на той же позиции в строке str2.
//Отрицательное число – в первых n символах сравниваемых строк есть отличия и код первого отличающегося символа в строке str1 меньше кода символа на той же позиции в строке str2.

            else {
                cout << "Invalid format";
                break;
            }
        }

        puts(filename);

        FILE* file = fopen( filename, "r" ); //Создает файл для записи (по умолчанию файл открывается как текстовый).

        if( file == nullptr ) {
            cout << "Invalid file name";
            break;
        }
        fseek( file, 0, SEEK_END );//fseek перемещает указатель позиции в потоке. Устанавливает внутренний указатель положения в файле, в новую позицию, которая определяются путем добавления смещения к исходному положению.

        long filesize = ftell( file );//ftell – опрос текущей позиции в потоке данных


        char* filedata = new char[filesize];
        rewind( file ); //станавливает внутренний указатель положения файла в начальное положение (начало файла).
        fread( filedata, 1, filesize, file ); //fread считывает массив размером — count элементов, каждый из которых имеет размер size байт, из потока, и сохраняет его в блоке памяти, на который указывает ptrvoid.
        char* fldt = filedata;
        fldt[filesize  ] = '\0';

        char STR[MAX_SIZE];
        cout << "Enter string: ";
        fgets(STR, MAX_SIZE, stdin);
        char* str = STR;
        *( str + strlen(str) - 1 ) = '\0';

        int occur = 0;
        while( strstr( fldt, str ) != nullptr ) { //strstr – поиск первого вхождения строки А в строку В
            occur ++;
            fldt = strstr( fldt, str ) + 1;
        }
        cout << "Occurance number: " << occur;
        delete[] filedata;
        fclose( file );
        break;
    }
    return 0;
}
