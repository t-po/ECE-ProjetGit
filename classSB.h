#ifndef classSB
#define classSB

#include <math.h>
#include <cfloat>
#include "svgfile.h"

class Coord
{
public:
    Coord(double _x = 100, double _y = 100);
    //~Coord();
    double get_x();
    double get_y();
    void set_x(double _x);
    void set_y(double _y);
    friend Coord operator+(const Coord& c1, const Coord& c2);
private:
    double x,y;
};

class Astre
{
public:
    void displayAstre();
    void dessiner(Svgfile &f);
    Astre(std::string _nom, double _x, double _y, double _masse, double _rayon, std::string _couleur);
    Astre();
    double get_x();
    double get_y();
    double get_m();
    bool get_t();
    void modifier(int champ);
    //~Sphere();
private:
    double masse,rayon;
    Coord coordSphere;
    std::string couleur, nom;
    bool tourne;
};

class SystemeAstral
{
public:
    void dessinerBarycentre(Svgfile &f);
    void modifier(size_t champ);
    void supprimer(size_t i);
    void ajouter(Astre a);
    void initSolaire();
    void dessiner();
    void display();
    size_t size();
private:
    std::vector<Astre> systeme;
};

#endif // classSB
