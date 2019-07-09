//Attributs du personnage.

vitesseHorizontale = 0;							//Variable vitesse horizontale du personnage.
vitesseVerticale = 0;							//Variable vitesse verticale du personnage.
vitesseMarcheInitiale = 4;
vitesseMarche = vitesseMarcheInitiale;			//Variable vitesse de marche du personnage.

// Variables utiles aux attaques et au comportement des ennemis.

room_speed = 60;				//Fps ou nombres ajoutés en une seconde.
seconde = 0.5;					//Variable du nombre de secondes pour le délai d'une attaque normale.
seconde2 = 5;					//Variable du nombre de secondes pour le délai d'une attaque normale.
delaiBase = room_speed * seconde;	//Variable de base du délai d'attaque.
delai = delaiBase;					//Variable du délai d'attaque.
delai2Base = room_speed * seconde2;	//Variable du délai de base de l'attaque importante.
delai2 = delai2Base;				//Variable du délai de l'attaque importante.
global.aggro = 0;					// Variable commencant la pourchasse des ennemis.
global.aggroBoss = 0;				// Variable commencant la pourchasse du boss.
