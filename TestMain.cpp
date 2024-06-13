
#include <iostream>
#include "DString.h"

using namespace std;

int main(void)
{
	DString x1;
	DString x2("ala ma kotka ");
	DString x3(x1);
	DString x4("Romek lubi raki");
	DString x5;


	x3 = x2 + x4;

	x4 += x2;

	x2 = x2;

	x5 = x3 + " pies ma pchly";

	cout << x1;
	cout << x2;
	cout << x3;
	cout << x4;
	cout << x5;

	cout << "podaj nowy teskt";
	cin >> x2;
	cout << endl << "podany tekst to " << x2;
	cout << "Wyciety tekst to: " << x2.GetString(3, 5);
		
	char znak = x2[3];
	cout << endl << "odczytany znak to " << znak;
	x2[3] = 'x';
	cout << endl << "A teraz po zmianie x2 =" << x2;

	cout << "Test rzutowania " << (const char*)x2<<endl;

	cout << "Nowy obsiety z lewej strony obiket to: " << x2.TrimLeft(3);
	cout << endl << "A teraz po zmianie x2 =" << x2;
	cout << "Nowy obsiety z lewej strony obiket to: " << x2.TrimRight(3);
	cout << endl << "A teraz po zmianie x2 =" << x2;

	cout << "Wyciety obiket z wzorca to: "<<  x2.IsString("mama");

	cout << "podaj nowy teskt do konwersj calkowitej";
	cin >> x3;
	cout << endl << "podany tekst to " << x3;
    return 0;

}