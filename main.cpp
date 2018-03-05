#include "stdio.h"
#include "conio.h"
#include <iostream>
#include <string>
using namespace std;
const int lim = 40;
void getline(char *str, int lim)
{
    int c, i;
    c = 1;
    for (i = 0; (i<lim - 1) && (c != (int)'\n'); i++)
    {
        c = getchar();
        str[i] = c;
    }
    str[i] = '\0';
}

struct book
{
    int UDKnumber;
    char autor[lim];
    char bookname[lim];
    long int year;
    int kolvo;
    book* next;
};
book* firstbook = new book;
book* lastbook = firstbook;
bool isFirst = true;


int main()
{

}
