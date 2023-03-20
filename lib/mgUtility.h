#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <conio.h>
using namespace std;

const string WHITESPACE = " \n\r\t\f\v";

string mgTrimLeft(const string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE); //     "   pepep"
    return (start == string::npos) ? "" : s.substr(start);
}

string mgTrimRight(const string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE); //      "pepe 		"
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}

string mgTrim(const string &s)
{
    return mgTrimRight(mgTrimLeft(s));		// " loro 	"  -> "loro"
}

string mgToLowerStr(string str)
{
    for (int x=0; x < str.length(); x++)
        str[x] = tolower(str[x]);
    return str;
}

string mgToUpperStr(string str)
{
    for (int x=0; x < str.length(); x++)
        str[x] = toupper(str[x]);
    return str;
}

string ppToCapitalStr(string str)
{
    for (int x=0; x < str.length(); x++)
        str[x] = (x==0) ? toupper(str[x]) : tolower(str[x]);
    return str;
}

void mgSplitStr( const string  str, const char delim,  vector<string> &outlst )
{
    string strDiv;
    stringstream s(str);
    while ( getline(s, strDiv, delim) )
        outlst.push_back(strDiv);
}

void mgGetString(string etiqueta, string &respuesta)
{
 	cout << etiqueta;
    cin>>respuesta;
    cin.get();
	cin.clear();
    fflush(stdin);
}

void mgGetNumber(string etiqueta, int &respuesta)
{
	cout<< etiqueta;
	cin >> respuesta ;
	cin.clear();
    fflush(stdin);
}

void mgGetNumber(string etiqueta, float &respuesta)
{
	cout<< etiqueta;
	cin >> respuesta;
	cin.clear();
    fflush(stdin);
}

void mgGetNumberPosi(string etiqueta, int &respuesta)
{
    string str;
    do {
        cout<<etiqueta;
        getline (cin,str);
        
        cin.clear();
        fflush(stdin);
        try
        {
            respuesta = stoi(str);
        }
        catch(const exception& e)
        {
            respuesta =-1;
        }
    } while (respuesta<0);
}

int mgGetNumberBetween(string etiqueta, int min, int max)
{
    int num;
    string str;
    bool numValido = false;
    do {
        cout<<etiqueta;
        getline (cin,str);

        numValido = false;
        cin.clear();
        fflush(stdin);
        try
        {
            num = stoi(str);
            if ((num >= min) && (num <= max))
                numValido = true;
        }
        catch(const exception& e)
        {
            num =min-1;
        }
    } while (!numValido);
    return num;
}

void mgGetCharArray(string etiqueta, char* dato )
{
    string str;
    cout << etiqueta;
    getline(cin, str);    

    str = mgTrim(str);
    strcpy(dato ,str.c_str());

    cin.clear();
    fflush(stdin);
}

string mgGetPassword(string etiqueta)
{
    int i=0;
    char s[10] = { 0 };
    cout<<etiqueta;
	while ((s[i] = _getch()) && int(s[i++])!= 13)
		_putch('*');
	s[--i] ='\0';
	cin.clear();
    fflush(stdin);
	cout<<"\n";
	return s;
}

string mgGetStringTrim(string etiqueta)
{
    string str;
    do {
        cout<<etiqueta;
        getline (cin,str);
        cin.clear();
        fflush(stdin);
        try
        {
            str = mgTrim(str);
            if (str == "")
                throw 100;
        }
        catch(const exception& e)
        {
            cout << " :( Valor no valido... " << endl;
        }
    } while (str.length()<=0);
    return str;
}

void mgClearTerminal()
{
    cout << "\033[H\033[2J\033[3J" ;
    cin.clear();
    fflush(stdin);
}