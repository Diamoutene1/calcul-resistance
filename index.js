const canvas = document.getElementById('resistanceCanvas');
const ctx = canvas.getContext('2d');

let selectedBand = 1;
let colors = ['black', 'black', 'black', 'gold'];  // Par défaut, le 4e anneau est "gold" pour la tolérance

// Fonction pour dessiner la résistance
function dessinerResistance() {
    // Dessiner le corps de la résistance
    ctx.fillStyle = '#F0B27A';  // Corps de la résistance
    ctx.fillRect(100, 100, 300, 100);  // Rectangle représentant le corps
    ctx.fillStyle = '#808080';  // Les barres métalliques
    ctx.fillRect(10, 145, 90, 10);  // Barre gauche
    ctx.fillRect(400, 145, 90, 10);  // Barre droite
}

// Fonction pour dessiner les anneaux de la résistance
function dessinerAnneaux(couleurs) {
    couleurs.forEach((couleur, index) => {
        ctx.fillStyle = couleur;
        ctx.fillRect(125 + index * 50, 100, 25, 100);  // Dessiner chaque anneau en fonction de la couleur choisie
    });
}

// Fonction pour détecter le clic sur un anneau
canvas.addEventListener('click', function(event) {
    const x = event.offsetX;
    const y = event.offsetY;

    // Vérifier si le clic est sur un des anneaux
    if (y >= 100 && y <= 200) {
        if (x >= 125 && x <= 150) {
            selectBand(1);  // Premier anneau
        } else if (x >= 175 && x <= 200) {
            selectBand(2);  // Deuxième anneau
        } else if (x >= 225 && x <= 250) {
            selectBand(3);  // Troisième anneau
        } else if (x >= 275 && x <= 300) {
            selectBand(4);  // Quatrième anneau (tolérance)
        }
    }
});

// Fonction appelée quand on sélectionne un anneau
function selectBand(bandNumber) {
    selectedBand = bandNumber;
    alert('Vous avez cliqué sur l\'anneau ' + bandNumber);
}

// Fonction appelée quand une couleur est sélectionnée
function selectionner_couleur(color) {
    // Vérifier si la couleur "or" est utilisée dans les premiers anneaux
    if ((selectedBand === 1 || selectedBand === 2) && color === 'gold') {
        document.getElementById('error').innerText = 'Erreur : La couleur Or ne peut pas être utilisée dans les anneaux 1 ou 2.';
        return;  // Ne pas changer la couleur si l'erreur est détectée
    } else {
        document.getElementById('error').innerText = '';  // Effacer les messages d'erreur
    }

    colors[selectedBand - 1] = color;
    dessinerResistance();
    dessinerAnneaux(colors);  // Redessiner les anneaux avec la nouvelle couleur
    calculateResistance();
}

// Fonction pour calculer la résistance basée sur les couleurs sélectionnées
function calculateResistance() {
    const valeur_couleur = {
        black: 0, brown: 1, red: 2, orange: 3, yellow: 4, green: 5,
        blue: 6, violet: 7, gray: 8, white: 9, gold: -1, silver: -2
    };

    const valeur_tolerance = {
        brown: '±1%', red: '±2%', green: '±0.5%', blue: '±0.25%',
        violet: '±0.1%', gray: '±0.05%', gold: '±5%', silver: '±10%'
    };

    // Calculer la résistance
    const premiere_couleur = valeur_couleur[colors[0]];
    const deuxieme_couleur = valeur_couleur[colors[1]];
    const multiplier = Math.pow(10, valeur_couleur[colors[2]]); // Couleur du multiplicateur

    let resistance = ((premiere_couleur * 10) + deuxieme_couleur) * multiplier;
    let tolerance = valeur_tolerance[colors[3]];  // Tolérance couleur

    // Vérifier si la couleur de tolérance est valide
    if (colors[3] === 'yellow' || colors[3] === 'orange' || colors[3] === 'white') {
        document.getElementById('error').innerText = 'Erreur : Les couleurs jaune, orange et blanc ne peuvent pas être utilisées pour la tolérance.';
        tolerance = '';  // Ne pas afficher de tolérance
    } else {
        document.getElementById('error').innerText = '';  // Effacer les messages d'erreur
        tolerance = tolerance || '±20%';  // Par défaut, ±20% si la couleur n'est pas valide
    }

    // Formater la résistance selon sa valeur
    let temp;
    if (resistance >= 1000000000) {
        temp = `${(resistance / 1000000000).toFixed(2)} G Ohms ${tolerance}`;
    } else if (resistance >= 1000000) {
        temp = `${(resistance / 1000000).toFixed(2)} M Ohms ${tolerance}`;
    } else if (resistance >= 1000) {
        temp = `${(resistance / 1000).toFixed(2)} K Ohms ${tolerance}`;
    } else {
        temp = `${resistance.toFixed(2)} Ohms ${tolerance}`;
    }

    document.getElementById('result').innerText = 'Résistance : ' + temp;
}

// Dessiner la résistance et les anneaux de base lors du chargement de la page
window.onload = function() {
    dessinerResistance();
    dessinerAnneaux(colors);
}