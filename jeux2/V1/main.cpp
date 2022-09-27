/*
Programme: jeuDuSimon
But: Faire le plus grand nombre de partie sans se tromper
Date de dernière modification : 12/10/2021
Auteur: R. ALonzo, A. Pascal
*/

#include <iostream>
#include "game-tools.h"
using namespace std;

int main(void)
{
    //Initialisation de la partie
    //Creation du tableau de couleur
    const unsigned short int NB_CASES = 100;    //La taille du tableau des couleurs
    char tabCouleurSimon[NB_CASES];             //Le tableau des couleurs du Simon

    //Variables
    bool partiePerdu = false;                   //Indique si le joueur à perdu la partie
    unsigned short int couleurErreur;           //Le numero de la mauvaise couleur rentrée par le joueur
    unsigned short int nombreCouleurSimon = 0;  //Le nombre de couleur généré par le Simon
    unsigned short int nombreCouleurJoueur = 0; //Le nombre de couleur entré par le joueur
    char derniereCouleurSimon;                  //La dernière couleur générée par le Simon
    char couleurJoueur;                         //La couleur entrée par le joueur
    unsigned short int scoreJoueur = 0;         //Le score du joueur
    unsigned short int nombreAleatoire;         //Un nombre aléatoire entre 1 et 4

    //Joueur la partie
    while (partiePerdu == false)
    {
        cout << "** Jeu du Simon **" << endl;

        //Choix aleatoire des couleurs
        nombreAleatoire = static_cast<unsigned short int>(random(1, 4));
        switch (nombreAleatoire)
        {
        case 1:
            derniereCouleurSimon = 'v';
            break;

        case 2:
            derniereCouleurSimon = 'r';
            break;

        case 3:
            derniereCouleurSimon = 'b';
            break;

        case 4:
            derniereCouleurSimon = 'j';
            break;
        default:
            break;
        };

        //Inserer la derniere couleur généré dans le tableau
        tabCouleurSimon[nombreCouleurSimon] = derniereCouleurSimon;

        //Affichage des couleurs du Simon
        cout << "Simon : ";
        for (unsigned short int i = 0; i <= nombreCouleurSimon; i++)
        {
            switch (tabCouleurSimon[i])
            {
            case 'v':
                afficherTexteEnCouleur("v ", vert, false);
                break;
            case 'r':
                afficherTexteEnCouleur("r ", rouge, false);
                break;
            case 'b':
                afficherTexteEnCouleur("b ", bleu, false);
                break;
            case 'j':
                afficherTexteEnCouleur("j ", jaune, false);
                break;
            default:
                break;
            }
            pause(1);
        }
        
        //Phase de décompte avant que le joueur rentre les couleurs
        cout << endl;
        cout << "3...";
        pause(1);
        cout << "2...";
        pause(1);
        cout << "1..." << endl;
        pause(1);
        effacer();

        //Affichage et vérification des couleurs saisies par le joueur
        cout << "** Jeu du Simon **" << endl;
        cout << "[v -> vert, b -> bleu, j -> jaune, r -> rouge]" << endl<< endl;
        cout << "Joueur : ";
        for (unsigned short int i = 0; i <= nombreCouleurSimon; i++)
        {
            //On verifie si le caractère rentré par le joueur est b, v, r ou j.
            while (true)
            {
                
                cin >> couleurJoueur;

                if ((couleurJoueur == 'v') || (couleurJoueur == 'b') || (couleurJoueur == 'r') || (couleurJoueur == 'j'))
                {
                    break;
                }

                cout << "Numero de couleur incorrect. Recommencez : ";
            }  

            //On compare la couleur entré par le joueur avec la couleur du Simon
            if (couleurJoueur != tabCouleurSimon[i])
            {
                partiePerdu = true;

                //On sauvegarde la couleur d'erreur
                couleurErreur = static_cast<unsigned short int>(i);

                //On enleve un au score joueur pour pas compter le dernier tour qui est faux
                scoreJoueur = static_cast<unsigned short int >(scoreJoueur - 1);
                break;
            }
            else
            {
                effacer();
                cout << "** Jeu du Simon **" << endl;
                cout << "[v -> vert, b -> bleu, j -> jaune, r -> rouge]" << endl << endl;
                cout << "Joueur : ";

                //Affichage en couleurs des caractère saisis par le joueur
                for (unsigned short int i = 0; i <= nombreCouleurJoueur; i++)
                {
                    switch (tabCouleurSimon[i])
                    {
                    case 'v':
                        afficherTexteEnCouleur("v ", vert, false);
                        break;
                    case 'r':
                        afficherTexteEnCouleur("r ", rouge, false);
                        break;
                    case 'b':
                        afficherTexteEnCouleur("b ", bleu, false);
                        break;
                    case 'j':
                        afficherTexteEnCouleur("j ", jaune, false);
                        break;
                    default:
                        break;
                    }
                }
                pause(1);
                nombreCouleurJoueur = static_cast<unsigned short int>(nombreCouleurJoueur + 1);
            }
        }
        scoreJoueur = static_cast<unsigned short int>(scoreJoueur + 1);
        nombreCouleurSimon = static_cast<unsigned short int>(nombreCouleurSimon + 1);
        nombreCouleurJoueur = 0;
        effacer();
    }

    //Fin de la partie
    if (partiePerdu == true)
    {
        cout << "** Jeu du Simon **" << endl;
        cout << "Erreur de saisie a la couleur numero " << couleurErreur + 1 << endl << endl;

        //On affiche les couleurs du Simon
        cout << "Simon : ";
        for (unsigned short int i = 0; i <= nombreCouleurSimon; i++)
        {
            switch (tabCouleurSimon[i])
            {
            case 'v':
                afficherTexteEnCouleur("v ", vert, false);
                break;
            case 'r':
                afficherTexteEnCouleur("r ", rouge, false);
                break;
            case 'b':
                afficherTexteEnCouleur("b ", bleu, false);
                break;
            case 'j':
                afficherTexteEnCouleur("j ", jaune, false);
                break;
            default:
                break;
            }
        }

        //On affiche les couleurs du joueur jusqu'a celle où il c'est trompé
        cout << endl << "Joueur : ";
        for (unsigned short int i = 0; i <= couleurErreur - 1; i++)
        {
            switch (tabCouleurSimon[i])
            {
            case 'v':
                afficherTexteEnCouleur("v ", vert, false);
                break;
            case 'r':
                afficherTexteEnCouleur("r ", rouge, false);
                break;
            case 'b':
                afficherTexteEnCouleur("b ", bleu, false);
                break;
            case 'j':
                afficherTexteEnCouleur("j ", jaune, false);
                break;
            default:
                break;
            }
        }

        //On affiche la couleur où il c'est trompé
        switch (couleurJoueur)
        {
        case 'v':
            afficherTexteEnCouleur("v ", vert, false);
            break;
        case 'r':
            afficherTexteEnCouleur("r ", rouge, false);
            break;
        case 'b':
            afficherTexteEnCouleur("b ", bleu, false);
            break;
        case 'j':
            afficherTexteEnCouleur("j ", jaune, false);
            break;
        default:
            break;
        }

        //On affiche le score du joueur
        cout << endl << "Score : " << scoreJoueur;
    }
    return 0;
}
