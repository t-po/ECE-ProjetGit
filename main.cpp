#include "svgfile.h"
#include "interfaceSB.h"

/// ATTENTION : nous vous prions de bien vouloir ouvrir le fichier output.svg avec Chrome ou Firefox pour pouvoir profiter de toutes les fonctionalités disponibles.
/// PS : le barycentre n'est calulé ,et donc affiché, seulement par rapport aux astres statiques (qui ne tournes pas).

/*
    Ce programme vous est proposé par Mathis Brionne et Benoît Montazeaud (TD7 Promo 2022 à ECE Paris)
    Ils se sont beaucoup amusés à farfouiller, bidouiller, lire les TP et mails de M. Fercoq.

    Sources :
        - Pour les animation en svg :
            - www.w3.org ,
            - https://la-cascade.io/guide-des-animations-svg/
        - Pour la fonction erase() de vector :
            - http://www.cplusplus.com
        - Pour les infos sur astre du systeme solaire et les calculs de temps de révolution :
            - media4.obspm.fr
            - google image
        - Pour blinder la saisi avec cin :
            - cpp.developpez.com
*/

int main()
{
    SystemeAstral systemeSolaire;
    systemeSolaire.initSolaire();

    while(1)
    {
        systemeSolaire.dessiner();
        system("start output.svg");
        size_t champ = menu(systemeSolaire);

        if(champ == 1)
        {
            Astre a;
            systemeSolaire.ajouter(a);
        }
        else
        {
            if(menu(MENU_ASTRE) == 1)
            {
                systemeSolaire.modifier(champ);
            }
            else
            {
                systemeSolaire.supprimer(champ);
            }
        }
    }

    return 0;
}
