//Attributs du personnage

vitesseHorizontale = 0;		//Variable vitesse horizontale du personnage.
vitesseVerticale = 0;		//Variable vitesse verticale du personnage.
vitesseMarche = 1.2;		//Variable vitesse de marche du personnage.
global.pv_boss = 20;			//Variable globale des pv du boss utilisé pour le couteau, le boss et le joueur.
delaiAttaqueBase = room_speed * 2;	// Variable de base du délai entre chaque attaque du boss.
delaiAttaque = delaiAttaqueBase;	// Variable du délai entre chaque attaque qui pourra s'écouler dans le jeu.
delaiBoss = room_speed * 5;	//Variable de délai de fin du jeu à la mort du boss.
uneInstance = 0;			//Variable utilisé pour créer une seule instance du cadavre à la place d'une infinité.