#include <iostream>
#include<iomanip>
#include <windows.h>
#include <conio.h>

using namespace std;

void gotoxy(int,int);
string eingabeText(int);
int ganzzahl(int);
string eingabedatum(void);

int main(void)
{
	string vorname,nachname,ort,geburtsdatum;
	int postleitzahl;
 	gotoxy(7,1);
 	cout << "SuchPersonen\n";
 	gotoxy(1,3);
 	cout << "vorname: ";
 	gotoxy(25,3);
 	cout << "nachname: ";
 	gotoxy(1,5);
 	cout << "ort: ";
 	gotoxy(25,5);
 	cout << "geburtsdatum: ";
 	gotoxy(1,7);
 	cout << "postleitzahl: ";
 	
 	
 	
 	
 	gotoxy(9,3);
 	vorname=eingabeText(10);
 
 	gotoxy(34,3);
 	nachname=eingabeText(10);
 	
 	gotoxy(5,5);
 	ort=eingabeText(15);
 	
 	{
 		gotoxy(38,5);
		geburtsdatum=eingabedatum();	
	}
// 	gotoxy(38,5);
// 	geburtsdatum=eingabeText(8);
 	
 	gotoxy(14,7);
 	postleitzahl=ganzzahl(5);
 	
 	
 	
	return 0;
}
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
string eingabeText(int zeichen)
{
	char temp;
	int stellen=0;
	string text;
	do
	{
		temp=getch();
		if(temp==8 && stellen>0)
		{
			stellen--;
			cout << temp;
			cout << '_';
			cout << temp;
			text.erase(stellen);
		}
		
		
		if(stellen<zeichen-1 && temp!=13 && temp!=8)
		{
			cout <<temp;
			text+=temp;
			stellen++;
		}
		
	}while(temp != 13);
	return  text;

}
int ganzzahl(int max)
{
	string zeichenkette;
	char temp;
	int stellen=0,zahl=0,faktor=1;
	do
	{
		temp=getch();
		if(temp==8 && stellen>0)
		{
			stellen--;
			cout << temp;
			cout << '_';
			cout << temp;
			zeichenkette.erase(stellen);			
		}
		
		
		if(stellen<max && temp>=48 && temp<=57)
		{
			cout << temp;
			zeichenkette+=temp;
			stellen++;
		}
		
	}while(temp != 13);
	for(stellen-=1;stellen>=0;stellen--)
	{
		zahl+=(zeichenkette[stellen]-48)*faktor;
		faktor*=10;
	}
	return zahl;
}
string eingabedatum()
{
	string datum,rueckgabe;
	int pos=10;
	cout << "__.__.____";
	for(pos;pos>0;pos--)cout << (char)8;
	char temp;
	
	do
	{
		temp=getch();
		if(temp==8 && pos>0)
		{
			pos--;
			if(pos==2|| pos==5)
			{
				
				cout << (char)8 ;//8 ist backspace -> korsur geht zurück
				pos--;
				datum.erase(pos);
			}

			cout << temp;
			cout << '_';
			cout << temp;

			datum.erase(pos);//löscht letzte stelle			
		}
		
		
		if(pos<10 && (temp>=48 && temp<=57))
		{
			cout << temp;
			datum+=temp;
			pos++;
			if(pos==2 || pos==5)
			{
				cout << ".";
				datum+="-";
				pos++;
			}
		}
		
	}while(temp != 13 || pos!=10);//13 ist return
	for(int i=6;i<10;i++)rueckgabe+=datum[i];
	rueckgabe+="-";
	for(int i=3;i<5;i++)rueckgabe+=datum[i];
	rueckgabe+="-";
	for(int i=0;i<2;i++)rueckgabe+=datum[i];	
	return rueckgabe;
}