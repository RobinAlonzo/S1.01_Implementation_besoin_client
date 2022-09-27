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
    //Creation d'un types énumérés
    enum UneCouleur {Vert, Jaune, Rouge, Bleu}; //Les couleurs disponibles
    UneCouleur derniereCouleurJoueur;           //La dernière couleur saisie par le Joueur    
    UneCouleur derniereCouleurSimon;            //La dernière couleur générée par le Simon      

    //Creation du tableau de couleur
    const unsigned short int NB_CASES = 100;    //La taille du tableau des couleurs
    UneCouleur tabCouleurSimon[NB_CASES];             //Le tableau des couleurs du Simon    

    //Variables
    unsigned short int nombreCouleurSimon = 0;  //Le nombre de couleur généré par le Simon
    unsigned short int nombreCouleurJoueur = 0; //Le nombre de couleur entré par le joueur
    unsigned short int scoreJoueur = 0;         //Le score du joueur
    unsigned short int nombreAleatoire;         //Un nombre aléatoire entre 1 et 4
    bool partiePerdu = false;                   //Indique si le joueur à perdu la partie
    unsigned short int couleurErreur;           //Le numero de la mauvaise couleur rentrée par le joueur  
    char saisieJoueur;                          //La couleur entrée par le joueur            

    //Joueur la partie
    while (partiePerdu == false)
    {
        cout << "** Jeu du Simon **" << endl;

        //Choix aleatoire des couleurs, et ajout de la couleur dans le tableau du Simon
        nombreAleatoire = static_cast<unsigned short int>(random(1, 4));
        switch (nombreAleatoire)
        {
        case 1:
            derniereCouleurSimon = Vert;
            break;

        case 2:
            derniereCouleurSimon = Rouge;
            break;

        case 3:
            derniereCouleurSimon = Bleu;
            break;

        case 4:
            derniereCouleurSimon = Jaune;
            break;
        default:
            break;
        };

        tabCouleurSimon[nombreCouleurSimon] = derniereCouleurSimon;

        //Affichage des couleurs du Simon
        cout << "Simon : ";
        for (unsigned short int i = 0; i <= nombreCouleurSimon; i++)
        {
            switch (tabCouleurSimon[i])
            {
            case Vert:
                afficherTexteEnCouleur("v ", vert, false);
                break;
            case Rouge:
                afficherTexteEnCouleur("r ", rouge, false);
                break;
            case Bleu:
                afficherTexteEnCouleur("b ", bleu, false);
                break;
            case Jaune:
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
                
                cin >> saisieJoueur;

                if ((saisieJoueur == 'v') || (saisieJoueur == 'b') || (saisieJoueur == 'r') || (saisieJoueur == 'j'))
                {
                    break;
                }

                cout << "Numero de couleur incorrect. Recommencez : ";
            }  

            //On sauvegarde la couleur rentré par le joueur
            switch (saisieJoueur)
            {
            case 'v':
                derniereCouleurJoueur = Vert;
                break;
            case 'r':
                derniereCouleurJoueur = Rouge;
                break;  
            case 'j':
                derniereCouleurJoueur = Jaune;
                break;                              
            case 'b':
                derniereCouleurJoueur = Bleu;
                break;            
            default:
                break;
            }

            //On compare la couleur entré par le joueur avec la couleur du Simon
            if (derniereCouleurJoueur != tabCouleurSimon[i])
            {
                partiePerdu = true;

                couleurErreur = static_cast<unsigned short int>(i);

                scoreJoueur = static_cast<unsigned short int >(scoreJoueur - 1);
                break;
            }
            else
            {
                //Affichage en couleurs des caractère saisis par le joueur
                effacer();
                cout << "** Jeu du Simon **" << endl;
                cout << "[v -> vert, b -> bleu, j -> jaune, r -> rouge]" << endl << endl;
                cout << "Joueur : ";

                for (unsigned short int i = 0; i <= nombreCouleurJoueur; i++)
                {
                    switch (tabCouleurSimon[i])
                    {
                    case Vert:
                        afficherTexteEnCouleur("v ", vert, false);
                        break;
                    case Rouge:
                        afficherTexteEnCouleur("r ", rouge, false);
                        break;
                    case Bleu:
                        afficherTexteEnCouleur("b ", bleu, false);
                        break;
                    case Jaune:
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
        //Mise à jour des compteurs
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
        for (unsigned short int i = 0; i < nombreCouleurSimon; i++)
        {
            switch (tabCouleurSimon[i])
            {
            case Vert:
                afficherTexteEnCouleur("v ", vert, false);
                break;
            case Rouge:
                afficherTexteEnCouleur("r ", rouge, false);
                break;
            case Bleu:
                afficherTexteEnCouleur("b ", bleu, false);
                break;
            case Jaune:
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
            case Vert:
                afficherTexteEnCouleur("v ", vert, false);
                break;
            case Rouge:
                afficherTexteEnCouleur("r ", rouge, false);
                break;
            case Bleu:
                afficherTexteEnCouleur("b ", bleu, false);
                break;
            case Jaune:
                afficherTexteEnCouleur("j ", jaune, false);
                break;
            default:
                break;
            }
        }

        //On affiche la couleur où il c'est trompé
        switch (derniereCouleurJoueur)
        {
        case Vert:
            afficherTexteEnCouleur("v ", vert, false);
            break;
        case Rouge:
            afficherTexteEnCouleur("r ", rouge, false);
            break;
        case Bleu:
            afficherTexteEnCouleur("b ", bleu, false);
            break;
        case Jaune:
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
