#ifndef interfaceSB
#define interfaceSB

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>
#include <limits>
#include "classSB.h"

#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75

#define MENU_PRINCIPAL 1
#define MENU_ASTRE 2
#define MENU_COULEUR 3
#define MENU_MODIF 4
#define MENU_ROTATION 5

#define MASSE_SOLEIL 666000000 // masse du Soleil (mise à l'échelle)
#define GM 4422000000 // Constante gravitationnelle G x masse du Soleil M (mise à l'échelle)
#define DIAMETRE_MARS 10

int menu(SystemeAstral systeme);
int menu(int type);

void displayMenu(SystemeAstral systeme);
void displayMenu(int type);

int navigationMenu(SystemeAstral systeme);
int navigationMenu(int type);

void curseurMenu(int x, int y);
void clsCurseurMenu(int x, int y);

void blindage(int* event);
bool blindage(double &n, int min, int max, std::string s);

void gotoxy(int x, int y);

#endif // interfaceSB
