#include "classSB.h"
#include "interfaceSB.h"

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Methodes et constructeurs de Astre

Astre::Astre()
{
    system("cls");
    double _x,_y;
    std::cout<<"Saisir le nom de l'astre : ";
    std::cin>>nom;
    blindage(_x, 0, 2000, "Saisir x : ");
    coordSphere.set_x(_x);
    blindage(_y, 0, 2000, "Saisir y : ");
    coordSphere.set_y(_y);
    blindage(masse, 0, 1000000000, "Saisir la masse : ");
    blindage(rayon, 0, 500, "Saisir le rayon : ");
    switch(menu(MENU_COULEUR))
    {
    case 1 :
        couleur = "blueball";
        break;
    case 2 :
        couleur = "redball";
        break;
    case 3 :
        couleur = "yellowball";
        break;
    case 4 :
        couleur = "greenball";
        break;
    case 5 :
        couleur = "greyball";
        break;
    }
    switch(menu(MENU_ROTATION))
    {
    case 1 :
        tourne = false;
        break;
    case 2 :
        tourne = true;
        break;
    }

}

Astre::Astre(std::string _nom, double _x, double _y, double _masse, double _rayon, std::string _couleur)
{
    nom = _nom;
    coordSphere.set_x(_x);
    coordSphere.set_y(_y);
    masse = _masse;
    rayon = _rayon;
    couleur = _couleur;
    tourne = false;
}

void Astre::displayAstre()
{
    std::cout << "  - "
              << nom
              << " : {"
              << coordSphere.get_x() << ","
              << coordSphere.get_y() << ","
              << masse << ","
              << rayon << ","
              << couleur
              << "}"
              <<std::endl;
}

void Astre::dessiner(Svgfile &f)
{
    //f.annimation(coordSphere.get_x(), coordSphere.get_y(), rayon, couleur, nom);
    f.addAnimatedDisk(coordSphere.get_x(), coordSphere.get_y(), rayon, couleur, nom, tourne);
}

double Astre::get_x()
{
    return coordSphere.get_x();
}

double Astre::get_y()
{
    return coordSphere.get_y();
}

double Astre::get_m()
{
    return masse;
}

bool Astre::get_t()
{
    return tourne;
}

void Astre::modifier(int champs)
{
    system("cls");
    switch(champs)
    {
    case 1:
        std::cout<<"Saisir le nouveau nom de l'astre"<<std::endl ;
        std::cin>>nom;
        break;
    case 2:
        double _x;
        blindage(_x, 0, 2000, "Saisir la nouvelle abscisse de l'astre : ");
        coordSphere.set_x(_x);
        break;
    case 3:
        double _y;
        blindage(_y, 0, 2000, "Saisir la nouvelle ordonnée de l'astre : ");
        coordSphere.set_y(_y);
        break;
    case 4:
        blindage(masse, 0, 1000000000, "Saisir la nouvelle masse de l'astre : ");
        break;
    case 5:
        blindage(rayon, 0, 500, "Saisir le nouveau rayon de l'astre : ");
        break;
    case 6:
    switch(menu(MENU_COULEUR))
        {
        case 1 :
            couleur = "blueball";
            break;
        case 2 :
            couleur = "redball";
            break;
        case 3 :
            couleur = "yellowball";
            break;
        case 4 :
            couleur = "greenball";
            break;
        case 5 :
            couleur = "greyball";
            break;
        }
        break;
        case 7:
            switch(menu(MENU_ROTATION))
            {
            case 1 :
                tourne = false;
                break;
            case 2 :
                tourne = true;
                break;
            }
    }
}

/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Methodes et constructeurs de SystemeAstral

void SystemeAstral::dessinerBarycentre(Svgfile &f)
{
    double croix_x = 0, croix_y = 0;
    size_t i = 0, masseTotal = 0;

    for(i = 0 ; i < systeme.size() ; i++)
    {
        if(systeme[i].get_t() == true)
        {
            croix_x += (systeme[i].get_x()*systeme[i].get_m());
            croix_y += (systeme[i].get_y()*systeme[i].get_m());
            masseTotal += systeme[i].get_m();
        }
    }
    croix_x /= masseTotal;
    croix_y /= masseTotal;

    f.addCross(croix_x, croix_y, 10);
}

void SystemeAstral::modifier(size_t bitocu)
{
    bitocu -= 2;
    systeme[bitocu].modifier(menu(MENU_MODIF));
}

void SystemeAstral::supprimer(size_t i)
{
    systeme.erase(systeme.begin() + i-1-1);
}

void SystemeAstral::ajouter(Astre a)
{
    systeme.push_back(a);
}

void SystemeAstral::initSolaire()
{
    Astre soleil("Soleil",1000,1000,MASSE_SOLEIL,30,"yellowball");
    Astre mercure("Mercure",1000 + 60*(2/3.0),1000,MASSE_SOLEIL*0.166/1000000,DIAMETRE_MARS*0.7,"greyball");
    Astre venus("Venus",1000 + 110*(2/3.0),1000,MASSE_SOLEIL*2.45/1000000,DIAMETRE_MARS*1.7,"greyball");
    Astre terre("Terre",1000 + 150*(2/3.0),1000,MASSE_SOLEIL*3.00/1000000,DIAMETRE_MARS*1.8,"blueball");
    Astre mars("Mars",1000 + 230*(2/3.0),1000,MASSE_SOLEIL*0.322/1000000,DIAMETRE_MARS,"redball");
    Astre jupiter("Jupiter",1000 + 780*(2/3.0),1000,MASSE_SOLEIL*954.6/1000000,DIAMETRE_MARS*20,"yellowball");
    Astre saturne("Saturne",1000 + 1420*(2/3.0),1000,MASSE_SOLEIL*285.8/1000000,DIAMETRE_MARS*17.1,"yellowball");
    ajouter(soleil);
    ajouter(mercure);
    ajouter(venus);
    ajouter(terre);
    ajouter(mars);
    ajouter(jupiter);
    ajouter(saturne);
}

void SystemeAstral::dessiner()
{
    size_t i = 0;
    Svgfile svgout;
    svgout.addGrid();
    for(i = 0 ; i < systeme.size(); i++)
    {
        systeme[i].dessiner(svgout); //On dessine chaques astres
    }
    dessinerBarycentre(svgout);
}

void SystemeAstral::display()
{
    size_t i = 0;
    for(i = 0 ; i < systeme.size() ; i++)
    {
        systeme[i].displayAstre();
    }
}

size_t SystemeAstral::size()
{
    return systeme.size();
}

/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Methodes et constructeurs de Coord

Coord::Coord(double _x, double _y)
{
    x = _x;
    y = _y;
}

double Coord::get_x()
{
    return x;
}

double Coord::get_y()
{
    return y;
}

void Coord::set_x(double _x)
{
    x =_x;
}

void Coord::set_y(double _y)
{
    y =_y;
}
