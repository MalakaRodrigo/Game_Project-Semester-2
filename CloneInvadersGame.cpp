// header files
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "windows.h"
#include "time.h"
#include <string>
#include <stdio.h>
#include <limits>

//libraries

using namespace std;



//creating a 2-D array of characters as the game workarea for easy access

char Map[11][51] = {

	"########################################",
	"#                                    X #",
	"# @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @  #",
	"#  @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#                  W                   #",
	"########################################",

};


//declaring variables

bool endgame = false;
int gamespeed = 180;
int randomNumberOne, randomNumberTwo, randomNumberThree, randomNumberFour, randomNumberFive;
int randomNumberSix, randomNumberSeven, randomNumberEight, randomNumberNine,randomNumberTen;
int MaxHealth = 3;
int YourHealth = MaxHealth;
int GamePoints=0;
string UserAge;
int TotalWins=0;
int TotalLoses=0;
string PlayerName;
string Quote = "         Invalid Input!  Now Loading..........";
char Design[82] = {'*','*','*','*', '*','*','C','L','O','N','E',' ','I','N','V','A','D','E','R','S','*','*','*','*', '*','*','C','L','O','N','E',' ','I','N','V','A','D','E','R','S','*','*','*','*', '*','*','C','L','O','N','E',' ','I','N','V','A','D','E','R','S','*','*','*','*', '*','*','C','L','O','N','E',' ','I','N','V','A','D','E','R','S' };
char UserPermission, UserPermission2, UserPermission3;
int LevelCount=1;
float levelchange=0.5;
int LvelChange=100;

HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE); //setting up handler for font size in console
void fontsize(int, int);
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //setting up handler for font color in console


//Initiates the fullscreen function

void Fullscreen()
{
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}


//start page 

void StartPage() 
{
		//system("color 8e"); // for background background colour
		fontsize(40, 40);
		//Fullscreen();
		//welcome screen preview
		SetConsoleTextAttribute(color, 6); //gold
		cout << " ******************************************************************************\n";
		SetConsoleTextAttribute(color, 11); //cyan
		cout << " ****************************    Clone Invaders    ****************************\n";
		SetConsoleTextAttribute(color, 6); //gold
		cout << " ******************************************************************************\n\n\n";

		//animation 
		int i = 0;
		SetConsoleTextAttribute(color, 11);
		while (i < 83)
		{

			cout << Design[i];
			i++;
			Sleep(25);
		}

		cout << endl << endl;
		SetConsoleTextAttribute(color, 9); //light blue

		cout << "			##################################\n";
		cout << "			#                                #\n";
		cout << "			#     @  @  @  @  @  @  @  @     #\n";
		cout << "			#           `             ^      #\n";
		cout << "			#        ^                       #\n";
		cout << "			#               `   ^            #\n";
		cout << "			#           ^          ^         #\n";
		cout << "			#               W                #\n";
		cout << "			##################################\n";

		SetConsoleTextAttribute(color, 11);
		//getting user inputs
		cout << endl;

		cout << "	  Please Press Y(Start) - N(Exit) - C(Change fullscreen)  : (Y/N/C)\b\b\b\b";
		SetConsoleTextAttribute(color, 12);
		cin >> UserPermission;
		cin.clear();
		cin.ignore();
		cout << "\a";
}


//start page in case of error

void StartPageError() 
{
	// system("color 8e"); // for background background colour
	fontsize(40, 40);
	//welcome screen preview
	SetConsoleTextAttribute(color, 6); //gold
	cout << " ******************************************************************************\n";
	SetConsoleTextAttribute(color, 11); //cyan
	cout << " ****************************    Clone Invaders    ****************************\n";
	SetConsoleTextAttribute(color, 6); //gold
	cout << " ******************************************************************************\n\n\n";

	//animation 
	int i = 0;
	SetConsoleTextAttribute(color, 11);
	while (i < 83)
	{

		cout << Design[i];
		i++;
	}

	cout << endl << endl;
	SetConsoleTextAttribute(color, 9); //light blue

	cout << "			##################################\n";
	cout << "			#                                #\n";
	cout << "			#     @  @  @  @  @  @  @  @     #\n";
	cout << "			#           `             ^      #\n";
	cout << "			#        ^                       #\n";
	cout << "			#               `   ^            #\n";
	cout << "			#           ^          ^         #\n";
	cout << "			#               W                #\n";
	cout << "			##################################\n";
	SetConsoleTextAttribute(color, 3);
	//getting user inputs
	cout << endl;
	cout << "	  Please Press Y(Start) - N(Exit) - C(Change fullscreen)  : (Y/N/C)\b\b\b\b";
	SetConsoleTextAttribute(color, 12);
	cin >> UserPermission;
	cin.clear();
	cin.ignore();
	cout << "\a";
}



//in game transition page

void TransistionPage()
{
	fontsize(40, 40);
	//welcome screen
	SetConsoleTextAttribute(color, 6); //gold
	cout << " ******************************************************************************\n";
	SetConsoleTextAttribute(color, 11); //cyan
	cout << " ****************************    Clone Invaders    ****************************\n";
	SetConsoleTextAttribute(color, 6); //gold
	cout << " ******************************************************************************\n\n\n";

	int i = 0;
	while (i < 83)
	{
		SetConsoleTextAttribute(color, 11);
		cout << Design[i];
		i++;
	}
	cout << endl;
	SetConsoleTextAttribute(color, 9);
	cout << "                        ##################################\n";
	cout << "			#                                #\n";
	cout << "			#     @  @  @  @  @  @  @  @     #\n";
	cout << "			#           `             ^      #\n";
	cout << "			#        ^                       #\n";
	cout << "			#               `   ^            #\n";
	cout << "			#           ^          ^         #\n";
	cout << "			#               W                #\n";
	cout << "			##################################\n";
	
	SetConsoleTextAttribute(color, 11);
		cout << "\n                      ....Now Loading. Good luck, Enjoy!....\n\n";
		SetConsoleTextAttribute(color, 10);
		cout << "\n                                       LEVEL "<<LevelCount;
				SetConsoleTextAttribute(color, 11);
		Sleep(1500);
}



//win screen

void WinScreen()
{
	system("CLS");
	fontsize(40, 40);
	//welcome screen
	SetConsoleTextAttribute(color, 6); //gold
	cout << " ******************************************************************************\n";
	SetConsoleTextAttribute(color, 11); //cyan
	cout << " ****************************    Clone Invaders    ****************************\n";
	SetConsoleTextAttribute(color, 6); //gold
	cout << " ******************************************************************************\n\n\n";

	int i = 0;
	while (i < 83)
	{
		SetConsoleTextAttribute(color, 11);
		cout << Design[i];
		i++;
		Sleep(10);
	}
	SetConsoleTextAttribute(color, 9);
	SetConsoleTextAttribute(color, 9);
	cout << "\n			##################################\n";
	cout << "			#                                #\n";
	cout << "			#     @  @  @  @  @  @  @  @     #\n";
	cout << "			#           `             ^      #\n";
	cout << "			#        ^                       #\n";
	cout << "			#               `   ^            #\n";
	cout << "			#           ^          ^         #\n";
	cout << "			#               W                #\n";
	cout << "			##################################\n";
	SetConsoleTextAttribute(color, 6);
	cout << "	 \n\n				*_*  YOU WON  *_*    \n\n";
	SetConsoleTextAttribute(color, 11);
	cout << "		   Total Wins   :    " << (TotalWins) << "	  Total Losses   :   " << (TotalLoses);
	Sleep(2500);
}



//lost screen

void LostScreen()
{
	system("CLS");
	fontsize(40, 40);
	//welcome screen
	SetConsoleTextAttribute(color, 6); //gold
	cout << " ******************************************************************************\n";
	SetConsoleTextAttribute(color, 11); //cyan
	cout << " ****************************    Clone Invaders    ****************************\n";
	SetConsoleTextAttribute(color, 6); //gold
	cout << " ******************************************************************************\n\n";


	int i = 0;
	while (i < 83)
	{
		SetConsoleTextAttribute(color, 11);
		cout << Design[i];
		i++;
		Sleep(10);
	}
	SetConsoleTextAttribute(color, 9);
	cout << "\n			##################################\n";
	cout << "			#                                #\n";
	cout << "			#     @  @  @  @  @  @  @  @     #\n";
	cout << "			#           `             ^      #\n";
	cout << "			#        ^                       #\n";
	cout << "			#               `   ^            #\n";
	cout << "			#           ^          ^         #\n";
	cout << "			#               W                #\n";
	cout << "			##################################\n";

	SetConsoleTextAttribute(color,3);
	cout << "	 \n\n				*_*  YOU LOST  *_*    \n\n";
	SetConsoleTextAttribute(color, 11);
	cout << "		   Total Wins   :    " << (TotalWins) << "	  Total Losses   :   " << (TotalLoses);
	Sleep(2500);
}



//second game

void SecondGame()
{
	fontsize(40, 40);
	system("CLS");

	SetConsoleTextAttribute(color, 6); //gold
	cout << " ******************************************************************************\n";
	SetConsoleTextAttribute(color, 11); //cyan
	cout << " ****************************    Clone Invaders    ****************************\n";
	SetConsoleTextAttribute(color, 6); //gold
	cout << " ******************************************************************************\n\n\n";

	int i = 0;
	while (i < 83)
	{
		SetConsoleTextAttribute(color, 11);
		cout << Design[i];
		i++;
		Sleep(2);
	}
		
	//getting user inputs
	SetConsoleTextAttribute(color, 11);
	cout << "					\n\n Do you want to start a new game?\nPlease Clear buffer before enter.\n\n";
	cout << "	  Please Press Y(Start) - N(Exit ) - C(Change fullscreen)  :   ...\b\b";
	cin >> UserPermission2;
	cin.clear();cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


//instruction page
void instructions()
{
	fontsize(40, 40);
	system("CLS");

	//welcome screen
	SetConsoleTextAttribute(color, 6); //gold
	cout << " ******************************************************************************\n";
	SetConsoleTextAttribute(color, 11); //cyan
	cout << " ****************************    Clone Invaders    ****************************\n";
	SetConsoleTextAttribute(color, 6); //gold
	cout << " ******************************************************************************\n\n\n";

	int i = 0;
	while (i < 83)
	{
		SetConsoleTextAttribute(color, 11);
		cout << Design[i];
		i++;
		Sleep(10);
	}
	SetConsoleTextAttribute(color, 4);
	cout << "  \n\n  Movements  \n\n";
	SetConsoleTextAttribute(color, 14);
	cout << "		Right Arrow Key		-	Move Right\n";
	cout << "		Left Arrow Key		-	Move Right\n";
	cout << "		Space bar		-	Fire\n\n";
	SetConsoleTextAttribute(color, 4);
	cout << "  \n  Console  \n\n";
	SetConsoleTextAttribute(color, 14);
	cout << "		Escape Key		-	Change Full Screen\n\n\n";
	cout << "	  For better Experience use full screen. Press Enter to Continue.";
//	Sleep(1500);
	cin.get();
}

//player information

void UserData()
{
	fontsize(40, 40);
	system("CLS");
	
	//welcome screen
	SetConsoleTextAttribute(color, 6); //gold
	cout << " ******************************************************************************\n";
	SetConsoleTextAttribute(color, 11); //cyan
	cout << " ****************************    Clone Invaders    ****************************\n";
	SetConsoleTextAttribute(color, 6); //gold
	cout << " ******************************************************************************\n\n\n";

	int i = 0;
	while (i < 83)
	{
		SetConsoleTextAttribute(color, 11);
		cout << Design[i];
		i++;
		Sleep(2);
	}

//getting user data
	SetConsoleTextAttribute(color, 12);
	cout << "    \n\n           	Before we begin, we need some information.\n\n";
	SetConsoleTextAttribute(color, 14);
	cout << "    \n\n\n      Please enter your User Name(maximum 8 characters)	:........\b\b\b\b\b\b\b\b";
	SetConsoleTextAttribute(color, 14);
	cin >> PlayerName;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	SetConsoleTextAttribute(color, 14);
	cout <<"\n\n   Thank You for attending to save our planet";SetConsoleTextAttribute(color, 6);cout <<" UTONIA.";SetConsoleTextAttribute(color, 14);cout<<" \n   WELCOME TO PLANET UTONIA.";
	//cout << "    \n      Please enter your Age		:..\b\b";
	//SetConsoleTextAttribute(color, 14);
	//cin >> UserAge; cin.ignore(); UserAge.clear();
	SetConsoleTextAttribute(color, 12);
	cout << "\n               Your UTONIA planet name : UtoWarrier_"<<PlayerName<<  "\n\n";
	PlayerName.clear();
	Sleep(1800);
	cout << "\a";
	Sleep(100);
}


//check for numbers
bool isNumber(string s)
{
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;

	return true;
}



//initializing font size

void fontsize(int a, int b) {
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
	lpConsoleCurrentFontEx->dwFontSize.X = a;
	lpConsoleCurrentFontEx->dwFontSize.Y = b;
	SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
}

VOID WINAPI SetConsoleColors(WORD attribs) {
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFOEX cbi;
	cbi.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
	GetConsoleScreenBufferInfoEx(hOutput, &cbi);
	cbi.wAttributes = attribs;
	SetConsoleScreenBufferInfoEx(hOutput, &cbi);
}




int main()
{

	Fullscreen();

	//PlaySound(TEXT("Dancing.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);


	// calling welcome page
		StartPage();

	// user permission to start game
		switch (UserPermission)
		{
		case 'y':
		case 'Y':

			goto Continue2;

		case 'C':
		case 'c':

			Fullscreen();
			system("CLS");
			goto Continue8;

			break;

		case 'n':
		case 'N':
			SetConsoleTextAttribute(color, 78);
			cout << "                              !Warriers never quit!                             ";
			Sleep(2000);
			SetConsoleTextAttribute(color, 1);
			system("CLS");
			exit(0);
			break;

		default:
			SetConsoleTextAttribute(color, 6);
			cout << Quote;
			Sleep(2000);
			system("CLS");

	//continuing set 2 (set2 at line 44) in case of invalid input
		Set2: 

		Continue8:

	//invalid input- start page recalling
			StartPageError();
			switch (UserPermission)
			{
			case 'y':
			case 'Y':

				goto Continue2;

			case 'C':
			case 'c':

				Fullscreen();
				Sleep(2000);
				system("CLS");
				cin.clear();
				goto Set2;

			case 'n':
			case 'N':
				SetConsoleTextAttribute(color, 78);
				cout << "                              !Warriers never quit!                             ";
				Sleep(2000);
				SetConsoleTextAttribute(color, 1);
				system("CLS");
				exit(0);
				break;

			default:
				system("CLS");
				cin.clear();
				goto Set2;
			}

		}
	//continuing continue 2 (continue 2 at line 508)
		Continue2:

	//second page-userdata
		UserData();

		if (PlayerName.size() <=8 && (isNumber(UserAge)))
		{
			goto Continue3;
		}

		else
		{
			cout << "         !INVALID USERNAME OR AGE DATA!         ";
			Sleep(1500);
			system("CLS");

		Fix1:

			UserData();
			if (PlayerName.size() <= 8 && (isNumber(UserAge)))
			{
				goto Continue3;
			}

			else
			{
				cout << "         !INVALID USERNAME OR AGE DATA!         ";
				Sleep(1200);
				system("CLS");
				PlayerName.clear();
				goto Fix1;
			}
		}

		//continuing continue 3 (goto continue 3 at line)
	Continue3:

		instructions();
		
		//continuing continue 5 (goto continue 5 at line)
		Continue5:
		system("CLS");
		char Map[11][51] = {

	"########################################",
	"#                                    X #",
	"# @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @  #",
	"#  @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#                                      #",
	"#                  W                   #",
	"########################################",

		};

		//ingame variables
		int y = 0;
		int x = 0;
		GamePoints = 0;
		YourHealth = 3;

		//third page- transistion between userdata and game
		TransistionPage();

		system("CLS");
		Sleep(200);

		//run time code
		SetConsoleTextAttribute(color, 6); //gold
		cout << " ******************************************************************************\n";
		SetConsoleTextAttribute(color, 11); //cyan
		cout << " ****************************    Clone Invaders    ****************************\n";
		SetConsoleTextAttribute(color, 6); //gold
		cout << " ******************************************************************************\n\n";


		int i = 0;
		while (i < 83)
		{
			cout << Design[i] << "\a";
			i++;
			Sleep(10);
		}

		//start of game
		
			while (endgame == false && GamePoints <= 350) {
			
				srand(time(0));
				system("cls");

				//header of the page
				SetConsoleTextAttribute(color, 6); //gold
				cout << " ******************************************************************************\n";
				SetConsoleTextAttribute(color, 11); //cyan
				cout << " ****************************    Clone Invaders    ****************************\n";
				SetConsoleTextAttribute(color, 6); //gold
				cout << " ******************************************************************************\n\n";


				for (y = 0; y < 11; y++) {
					cout <<"                    " <<Map[y] << endl;
				}


				SetConsoleTextAttribute(color, 11);
				cout << "\n			    Total Points  "; SetConsoleTextAttribute(color, 2);cout << GamePoints; SetConsoleTextAttribute(color, 11); cout << " / 360" << endl;

				SetConsoleTextAttribute(color, 11);
				cout << "			    Health        "; SetConsoleTextAttribute(color, 4);cout << YourHealth; SetConsoleTextAttribute(color, 11); cout << " / " << MaxHealth;

				for (y = 0; y < 11; y++) {
					for (x = 0; x < 41; x++) {

						switch (Map[y][x]) {
						case 'X':

							if (GetAsyncKeyState(VK_ESCAPE) != 0) {
								Fullscreen();
							}
							break;
						case 'W':

							if (GetAsyncKeyState(VK_LEFT) != 0) {
								Sleep(50);
								int newX = x - 1;

								switch (Map[y][newX]) {

								case ' ':
									Map[y][x] = ' ';
									x--;
									Map[y][newX] = 'W';

									break;

								}

							}

							if (GetAsyncKeyState(VK_RIGHT) != 0) {
								Sleep(50);
								int newX = x + 1;

								switch (Map[y][newX]) {

								case ' ':
									Map[y][x] = ' ';
									x++;
									Map[y][newX] = 'W';

									break;

								}

							}

							if (GetAsyncKeyState(VK_SPACE) != 0) {
								Sleep(20);
								y--;
								Map[y][x] = '`';

							}

							break;

							

						case '`':

							Map[y][x] = ' ';
							y--;

							if (Map[y][x] != '#' && Map[y][x] != '@' && (Map[y][x] != 'X')) {

								Map[y][x] = '`';

							}
							else if (Map[y][x] == '@') {

								Map[y][x] = ' ';
								cout << "\a";

								GamePoints = GamePoints + 10;
							}

							break;

						case '@':

							randomNumberOne = rand() % LvelChange + 1;
							randomNumberTwo = rand() % 50 + 1;
							randomNumberThree = rand() % LvelChange + 1;
							randomNumberFour = rand() % 30 + 1;
							randomNumberFive = rand() % LvelChange + 1;



							randomNumberSix = rand() % 100 + 1;


							if (randomNumberOne == 1 || randomNumberTwo == 1 || randomNumberThree == 1 || randomNumberFour == 1 || randomNumberFive == 1) {
								y++;
								Map[y][x] = '^';

							}

							break;

						case '^':

							Map[y][x] = ' ';
						if(randomNumberSix>66)
						{
							x++;
							y++;
							goto Ingame;
						}
						else if(randomNumberSix>33)
						{
							y++;
							goto Ingame;
						}
						else if(randomNumberSix>0)
						{
							x--;
							y++;
							goto Ingame;	
						}
						Ingame:
							if (Map[y][x] != '#' && Map[y][x] != 'W') {
								Map[y][x] = '^';
							}
							else if (Map[y][x] == 'W') {

								YourHealth -= 1;
							}
							break;
						
						}
					}
				}
				time_t t = time(NULL);
				tm* tPtr = localtime(&t);
				SetConsoleTextAttribute(color, 7);
				cout << "\n\n  Current Date	: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 ;
				cout << "                       Current Time	: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << ":" << (tPtr->tm_sec) << endl;

				if (YourHealth <= 0) {
					endgame = true;

				}
				Sleep(gamespeed);



			}
			system("cls");

			if (!(endgame == true))
			{
				GamePoints = 0;
				YourHealth = 3;
				endgame = false;
				TotalWins += 1;
				LvelChange=-10;
				LevelCount++;

				WinScreen();
				if(LevelCount>5)
				{
					fontsize(50,50);
					system("CLS");
					cout<<"\n\n\n\n\n              You have saved the planet UTONIA for now!\n                           !CONGRATULATIONS!\n";
					cout<<"           Visit again for save planet UTONIA in future!\n";
					cin.get();
					system("CLS");
					Fullscreen();
					return main();
				}
				else
				{
					goto Pending;
				}
				Pending:
			Set3:
				SecondGame();
				switch (UserPermission2)
				{
				case 'y':
				case 'Y':
					system("CLS");
					goto Continue6;

					break;

				case 'C':
				case 'c':

					Fullscreen();
					system("CLS");
					cin.clear();
					goto Set4;
					break;

				case 'n':
				case 'N':
					SetConsoleTextAttribute(color, 14);
					cout << "\n\n\n				.... Warriers never quit!....";
					Sleep(1000);
					system("CLS");
					exit(0);
					break;

				default:

					system("CLS");
					cin.clear();
					goto Set3;
				}
			}
			else {
				endgame = false;
				TotalLoses += 1;
				LostScreen();
				GamePoints = 0;
				YourHealth = 3;

			Continue6:
			Set4:
				SecondGame();
				switch (UserPermission2)
				{
				case 'y':
				case 'Y':
					system("CLS");

					goto Continue5;

					break;

				case 'C':
				case 'c':

					Fullscreen();
					system("CLS");
					cin.clear();
					goto Set4;
					
					break;
				case 'n':
				case 'N':
					SetConsoleTextAttribute(color, 14);
					cout << "\n\n\n				.... Warriers never quit!....";
					Sleep(1000);
					system("CLS");
					exit(0);
					break;

				default:
					system("CLS");
					cin.clear();
					goto Set4;
				}
			}


			system("PAUSE");	
		
		return 0;
	}



