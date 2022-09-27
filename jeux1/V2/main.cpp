/*
 Programme : jeuDesMultiples
 But :  Trouver le multiple d'un nombre
 Date de dernière modification : 28 septembre 2021
 Auteur : R. Alonzo et A. Pascal,
*/


#include <iostream>
using namespace std;

int main(void)
{
    //Variables
    int degreDifficulte; //Le degré de difficulté saisit par le joueur
    bool gagnerPartie = false; //Indique que la partie est gagner ou non
    unsigned short int nombrePrecedent = 2; //Le nombre dont il faut trouver le multiple
    unsigned short int nombreMultiple; //Le multiple du nombre precedent
    unsigned short int resteDivision; //Le reste de la division euclidienne de nombrePrecedent modulo nombreMultiple
    int scoreJoueur = 0; //Le score obtenue par le joueur durant la partie

    //Initialisation de la partie
    cout <<"Choisissez la difficulte du jeux (nombre de reponses correctes pour gagner) : ";

    while (true)
    {
        //clavier >> saisiDegreDifficulte >> degreDifficulte
        cin >> degreDifficulte;

        if (degreDifficulte > 0)
        {
            break;
        }

        cout <<"La valeur attendu doit etre superieur a 0. Recommencez : ";
    }

    //Jouer la partie
    while ((degreDifficulte != 0))
    {
        //clavier, nombrePrecedent >> saisiNombreMultiple >> nombreMultiple
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
            //degreDifficulte >> afficherNombrePartieRestante >> ecran
            cout <<"Bonne reponse, il vous reste "<< degreDifficulte << " partie a jouer" << endl << endl;
        }
        else
        {
            cout <<"Mauvaise reponse"<< endl << endl;
            gagnerPartie = false;
            break;
        }
    }    
    //Finaliser la partie
    //gagnerPartie >> verifieSiPartieGagner
    if (gagnerPartie == true)
    {
        cout << "Bravo vous avez gagne";
    }
    else
    {
        //score >> afficherScore >> ecran
        cout << "Vous avez perdu avec un score de " << scoreJoueur << " bonne reponses !!"  <<endl;
    }

}


