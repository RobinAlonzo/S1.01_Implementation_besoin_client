/*
 Programme : jeuDesMultiples
 But :  Trouver le multiple d'un nombre
 Date de dernière modification : 21 septembre 2021
 Auteur : R. Alonzo et A. Pascal
 Remarques : Code conforme aux spécification internes données en cours
*/


#include <iostream>
using namespace std;

int main(void)
{
    //Variables
    int degreDifficulte; //Le degré de difficulté saisit par le joueur
    bool gagnerPartie; //Indique que la partie est gagner ou non
    unsigned short int nombrePrecedent = 2; //Le nombre dont il faut trouver le multiple
    unsigned short int nombreMultiple; //Le multiple du nombre precedent
    unsigned short int resteDivision; //Le reste de la division euclidienne de nombrePrecedent modulo nombreMultiple
    int scoreJoueur; //Le score obtenue par le joueur durant la partie

    //Initialisation de la partie
    //clavier >> saisirDifficulte >> degreDifficulte
    cout <<"Choisissez la difficulte du jeux (nombre de reponses correctes pour gagner) : ";
    cin >> degreDifficulte;

    while ((degreDifficulte < 0))
    {
        //clavier >> saisirDifficulte >> degreDifficulte
        cout <<"La valeur attendu doit etre superieur a 0. Recommencez "<< endl;
        cout <<"Choisissez la difficulte du jeux (nombre de reponses correctes pour gagner) : ";
        cin >> degreDifficulte;
    }

    //Jouer la partie
    while ((degreDifficulte != 0))
    {
        //clavier, nombrePrecedent >> saisirNombreMultiple >> nombreMultiple
        cout <<"Saisir un multiple de "<< nombrePrecedent <<" superieur a "<< nombrePrecedent <<" : ";
        cin >> nombreMultiple;

        //nombrePrecedent, nombreMultiple >> calculeReste >> resteDivision
        resteDivision = nombreMultiple % nombrePrecedent;

        if (resteDivision == 0 && nombreMultiple > nombrePrecedent)
        {
            nombrePrecedent = nombreMultiple; 
            degreDifficulte = degreDifficulte - 1; 
            scoreJoueur = scoreJoueur + 1; 
            gagnerPartie = true;
            cout <<"Bonne reponse"<< endl;
        }
        else
        {
            gagnerPartie = false;
            cout <<"Mauvaise réponse"<< endl;
            break;
        }
    }    
    //Finaliser la partie

    if (gagnerPartie == true)
    {
        // afficher >> ecran
        cout << "Bravo vous avez gagne";
    }
    else
    {
        //score >> afficherScore >> ecran
        cout << "Vous avez perdu avec un score de " << scoreJoueur <<endl;
    }

}


