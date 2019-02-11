#include "interfaceSB.h"

int menu(SystemeAstral systeme)
{
    displayMenu(systeme);
    return navigationMenu(systeme);
}

int menu(int type)
{
    displayMenu(type);
    return navigationMenu(type);
}

void displayMenu(SystemeAstral systeme)
{
    std::cout << "=======MENU=======" << std::endl;
    std::cout << "  - Ajouter un astre" << std::endl;
    systeme.display();
}

void displayMenu(int type)
{

    switch(type)
    {
   case MENU_ASTRE:
        std::cout << "=======MENU_ASTRE=======" << std::endl;
        std::cout << "  - Modifier" << std::endl;
        std::cout << "  - Supprimer" << std::endl;
        break;
    case MENU_COULEUR:
        std::cout << "=======CHOIX_COULEUR=======" << std::endl;
        std::cout << "  - bleu" << std::endl;
        std::cout << "  - rouge" << std::endl;
        std::cout << "  - jaune" << std::endl;
        std::cout << "  - vert" << std::endl;
        std::cout << "  - gris" << std::endl;
        break;
        case MENU_MODIF:
        std::cout << "=======CHOIX_MODIFICATION=======" << std::endl;
        std::cout << "  - Nom" << std::endl;
        std::cout << "  - x" << std::endl;
        std::cout << "  - y" << std::endl;
        std::cout << "  - Masse" << std::endl;
        std::cout << "  - rayon" << std::endl;
        std::cout << "  - Couleur "<< std::endl;
        std::cout << "  - Rotation "<<std::endl;
        break;
     case MENU_ROTATION:
        std::cout << "=======CHOIX_ROTATION=======" << std::endl;
        std::cout << "  - l'Astre tourne a partir de ses coordonnées d'origines" << std::endl;
        std::cout << "  - l'Astre ne tourne pas" << std::endl;
        break;
    }
}

int navigationMenu(SystemeAstral systeme)
{
    int event;
    size_t x = 2, y = 1, x0, y0;

    system("cls");
    gotoxy(0, 0);
    displayMenu(systeme);

    while(event != ' ' && event != 13) //Si l'utilisateur valide avec espace ou entrer
    {
        x0 = x;
        y0 = y;
        curseurMenu(x, y);
        event = getch();
        fflush(stdin);
        blindage(&event);
        switch(event)
        {
        case 'Z':
            if(y > 1)
                y--;
            break;
        case 'S':
            if(y < systeme.size()+1)
            y++;
        }
        clsCurseurMenu(x0, y0);
    }
    return y;
}

int navigationMenu(int type)
{
    int event;
    size_t x = 2, y = 1, x0, y0;

    system("cls");
    gotoxy(0, 0);
    displayMenu(type);

    while(event != ' ' && event != 13) //Si l'utilisateur valide avec espace ou entrer
    {
        x0 = x;
        y0 = y;
        curseurMenu(x, y);
        event = getch();
        fflush(stdin);
        blindage(&event);
        switch(event)
        {
        case 'Z':
            if(y > 1)
                y--;
            break;
        case 'S':
            switch(type)
            {
            case MENU_ASTRE:
                if(y < 2)
                    y++;
                    break;
            case MENU_COULEUR:
                if(y < 5)
                    y++;
                    break;
            case MENU_MODIF:
                if(y < 7)
                    y++;
                    break;
            case MENU_ROTATION:
                if(y < 2)
                    y++;
                    break;
            }
        }
        clsCurseurMenu(x0, y0);
    }
    return y;
}

void curseurMenu(int x, int y)
{
    gotoxy(x, y);
    std::cout << ">";
}

void clsCurseurMenu(int x, int y)
{
    gotoxy(x, y);
    std::cout << "-";
}

void blindage(int* event)
{
    switch(*event)
    {
    case '&':
        *event = '1';
        return;
    case 130:
        *event = '2';
        return;
    case '"':
        *event = '3';
        return;
    case '\'':
        *event = '4';
        return;
    case UP:
        *event = 'Z';
        return;
    case LEFT:
        *event = 'Q';
        return;
    case RIGHT:
        *event = 'D';
        return;
    case DOWN:
        *event = 'S';
        return;
    }
    if(*event >= 'a' && *event <= 'z')
    {
        *event -= 32;
        return;
    }
}

bool blindage(double &n, int min, int max, std::string s)
{
    std::cout << s ;
    while (!(std::cin >> n) || n<min || n>max)
    {
        if (std::cin.eof())
        {
            return false;
        }
        else if (std::cin.fail())
        {
            std::cout << "Saisie incorrecte, veuillez recommencer : ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            std::cout << "Le nombre doit appartenir a l'intervalle ["
                    << min
                    << ";"
                    << max
                    << "], recommencez : ";
        }
    }
    return true; // succès
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

