#include <iostream>
#include <graphics.h>
using namespace std;

#define ORANGE COLOR(255, 165, 0)  // Définition manuelle de la couleur ORANGE
#define BROWN COLOR(128, 0, 0)  // Définition manuelle de la couleur BROWN
#define RED COLOR(255, 0, 0)  // Définition manuelle de la couleur RED
#define GOLD COLOR(255,215,0)   // Définition manuelle de la couleur GOLD
#define SILVER COLOR(192, 192, 192)  // Définition manuelle de la couleur SILVER

// Définition des couleurs
const int couleurs[] = {BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, MAGENTA, LIGHTGRAY, WHITE, GOLD, SILVER};

// Valeurs associées aux couleurs
const int valeurs[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
// Multiplicateurs associés aux couleurs
const float multiplicateurs[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 0.1, 0.01};
// Tolérances associées aux couleurs
const float tolerances[12] = {0, 1, 2, 0, 0, 0.5, 0.25, 0.1, 0.05, 0, 5, 10};

void dessinerResistance(int couleursAnneaux[]) {
    // Redessiner la résistance et les anneaux
    //dessin resistance
    setfillstyle(1, COLOR(240, 178, 122));
    bar(100, 100, 400, 200); // Corps de la résistance
    setfillstyle(1,COLOR(128, 128, 128));//barre résistance gauche
    bar(10,145,100,155);
    setfillstyle(1,COLOR(128, 128, 128));//barre résistance droite
    bar(400,145,490,155);
    // Dessin des anneaux
    setfillstyle(1, couleursAnneaux[0]); // Remplissage plein
    bar(125, 100, 150, 200); // 1er anneau
    setfillstyle(1, couleursAnneaux[1]); // Remplissage plein
    bar(175, 100, 200, 200); // 2ème anneau
    setfillstyle(1, couleursAnneaux[2]); // Remplissage plein
    bar(225, 100, 250, 200); // 3ème anneau
    setfillstyle(1, couleursAnneaux[3]); // Remplissage plein
    bar(275, 100, 300, 200); // 4ème anneau
    }


void afficherResistance(int valeursAnneaux[]) {
   int valeurSignificative = valeursAnneaux[0] * 10 + valeursAnneaux[1];
    float resistance = valeurSignificative * multiplicateurs[valeursAnneaux[2]];
    char temp[100];

    if (resistance >= 1000000000) {
        sprintf(temp, "%4.2f G Ohms %4.2f %%", resistance / 1000000000, tolerances[valeursAnneaux[3]]);
    } else if (resistance >= 1000000) {
        sprintf(temp, "%4.2f M Ohms %4.2f %% ", resistance / 1000000, tolerances[valeursAnneaux[3]]);
    } else if (resistance >= 1000) {
        sprintf(temp, "%4.2f K Ohms %4.2f %%", resistance / 1000, tolerances[valeursAnneaux[3]]);
    } else {
        sprintf(temp, "%4.2f Ohms %4.2f %%", resistance, tolerances[valeursAnneaux[3]]);
    }

    outtextxy(20, 600, temp);}

void dessinerBarreCouleurs() {
    // Dessin de la barre de couleurs sans boucle
    setfillstyle(1, couleurs[0]); // Noir
    bar(50, 300, 100, 350);

    setfillstyle(1, couleurs[1]); // Marron
    bar(110, 300, 160, 350);

    setfillstyle(1, couleurs[2]); // Rouge
    bar(170, 300, 220, 350);

    setfillstyle(1, couleurs[3]); // Orange
    bar(230, 300, 280, 350);

    setfillstyle(1, couleurs[4]); // Jaune
    bar(290, 300, 340, 350);

    setfillstyle(1, couleurs[5]); // Vert
    bar(350, 300, 400, 350);

    setfillstyle(1, couleurs[6]); // Bleu
    bar(410, 300, 460, 350);

    setfillstyle(1, couleurs[7]); // Violet
    bar(470, 300, 520, 350);

    setfillstyle(1, couleurs[8]); // Gris
    bar(530, 300, 580, 350);

    setfillstyle(1, couleurs[9]); // Blanc
    bar(590, 300, 640, 350);

    setfillstyle(1, couleurs[10]); // Or
    bar(650, 300, 700, 350);

    setfillstyle(1, couleurs[11]); // Argent
    bar(710, 300, 760, 350);
}

void afficherNomsCouleurs() {
    // Affichage des noms de couleurs sans boucle
    outtextxy(50, 275, "noir");
    outtextxy(110, 275, "marron");
    outtextxy(170, 275, "rouge");
    outtextxy(230, 275, "orange");
    outtextxy(290, 275, "jaune");
    outtextxy(350, 275, "vert");
    outtextxy(410, 275, "bleu");
    outtextxy(470, 275, "violet");
    outtextxy(530, 275, "gris");
    outtextxy(590, 275, "blanc");
    outtextxy(650, 275, "or");
    outtextxy(710, 275, "argent");
}

int main() {
    initwindow(800, 800, "Calcul de Résistance");

    int couleursAnneaux[4] = {WHITE, WHITE, WHITE, WHITE}; // Couleurs initiales des anneaux
    int x, y;
    int anneauSelectionne = -1; // Pour suivre quel anneau est sélectionné
    int valeursAnneaux[4] = {0, 0, 0, 0};

    setfillstyle(1, COLOR(187, 210, 225));
    bar(0, 0, 800, 800);

    char BVN[99];
    char phrase[7][99] = {
        "Vous avez sélectionné le premier anneau !",
        "Vous avez sélectionné le deuxième anneau ! ",
        "Vous avez sélectionné le troisième anneau ! ",
        "Vous avez sélectionné le quatrième anneau !",
        "Copyright : ZANA && ETIENNE ",

    };

    sprintf(BVN, "Bienvenue dans notre application"); // texte de bienvenue
    outtextxy(10, 30, BVN);
    outtextxy(500, 700, phrase[4]);

    outtextxy(20, 550, "La valeur de votre résistance est :"); // message de la valeur de la résistance

    // Dessin initial de la résistance
    dessinerResistance(couleursAnneaux);
    dessinerBarreCouleurs(); // Dessin de la barre de couleurs
    afficherNomsCouleurs(); // Affichage des noms des couleurs

    // Boucle principale
while (1) {
    while (ismouseclick(WM_LBUTTONDOWN) == 0);
    getmouseclick(WM_LBUTTONDOWN, x, y);

    // Effacement du message précédent
    setfillstyle(1, COLOR(187, 210, 225)); // Couleur de fond
    bar(20, 250, 400, 270); // Effacer la zone de texte pour le message de sélection

    // Vérification des clics sur les anneaux
    if (y >= 100 && y <= 200) {
        if (x >= 125 && x <= 150) {
            anneauSelectionne = 0; // 1er anneau szlectionne
            outtextxy(20, 220, phrase[0]); // Affichage du message
        } else if (x >= 175 && x <= 200) {
            anneauSelectionne = 1; // 2eme anneau selectionné
            outtextxy(20, 220, phrase[1]); // Affichage du message
        } else if (x >= 225 && x <= 250) {
            anneauSelectionne = 2; // 3eme anneau selectionné
            outtextxy(20, 220, phrase[2]); // Affichage du message
        } else if (x >= 275 && x <= 300) {
            anneauSelectionne = 3; // 4eme anneau sélectionné
            outtextxy(20, 220, phrase[3]); // Affichage du message
        } else {
            anneauSelectionne = -1; // Aucun anneau sélectionné
        }
    }

    // Vérification des clics sur la barre de couleurs
    if (anneauSelectionne != -1) {
        if (y >= 300 && y <= 350) {
            if (x >= 50 && x <= 100) {
                couleursAnneaux[anneauSelectionne] = couleurs[0];
                valeursAnneaux[anneauSelectionne] = valeurs[0];
            } else if (x >= 110 && x <= 160) {
                couleursAnneaux[anneauSelectionne] = couleurs[1];
                valeursAnneaux[anneauSelectionne] = valeurs[1];
            } else if (x >= 170 && x <= 220) {
                couleursAnneaux[anneauSelectionne] = couleurs[2];
                valeursAnneaux[anneauSelectionne] = valeurs[2];
            } else if (x >= 230 && x <= 280) {
                couleursAnneaux[anneauSelectionne] = couleurs[3];
                valeursAnneaux[anneauSelectionne] = valeurs[3];
            } else if (x >= 290 && x <= 340) {
                couleursAnneaux[anneauSelectionne] = couleurs[4];
                valeursAnneaux[anneauSelectionne] = valeurs[4];
            } else if (x >= 350 && x <= 400) {
                couleursAnneaux[anneauSelectionne] = couleurs[5];
                valeursAnneaux[anneauSelectionne] = valeurs[5];
            } else if (x >= 410 && x <= 460) {
                couleursAnneaux[anneauSelectionne] = couleurs[6];
                valeursAnneaux[anneauSelectionne] = valeurs[6];
            } else if (x >= 470 && x <= 520) {
                couleursAnneaux[anneauSelectionne] = couleurs[7];
                valeursAnneaux[anneauSelectionne] = valeurs[7];
            } else if (x >= 530 && x <= 580) {
                couleursAnneaux[anneauSelectionne] = couleurs[8];
                valeursAnneaux[anneauSelectionne] = valeurs[8];
            } else if (x >= 590 && x <= 640) {
                couleursAnneaux[anneauSelectionne] = couleurs[9];
                valeursAnneaux[anneauSelectionne] = valeurs[9];
            } else if (x >= 650 && x <= 700) {
                couleursAnneaux[anneauSelectionne] = couleurs[10];
                valeursAnneaux[anneauSelectionne] = valeurs[10];
            } else if (x >= 710 && x <= 760) {
                couleursAnneaux[anneauSelectionne] = couleurs[11];
                valeursAnneaux[anneauSelectionne] = valeurs[11];
            }
        }
    }

    // Redessin de la résistance avec les nouvelles couleurs
    dessinerResistance(couleursAnneaux);

    // Affichage de la résistance calculée
    afficherResistance(valeursAnneaux);
}
}



