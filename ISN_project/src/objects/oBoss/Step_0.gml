if (global.pv_boss > 0 and global.aggroBoss == 1)		//Si l'ennemi a tous ses PV et qu'il est provoqué, lancement de l'IA du boss.
{
	delaiAttaque -=1;													//Faire en sorte que le délai s'écoule à chaque frame.
	
	if (delaiAttaque <= 0)												//Création des attaques.
	{
		instance_create_depth(x + 50, y - 65, oBoss, oCouteauBoss);		//Création de l'instance du couteau.
		instance_create_depth(x, y, oBoss, oCouteauBoss);				//Création de l'instance du couteau.
		instance_create_depth(x - 50, y + 65, oBoss, oCouteauBoss);		//Création de l'instance du couteau.
		audio_play_sound(sonTirNormal, 10, false);						//Lancement du son du lancer.
		delaiAttaque = delaiAttaqueBase;
	}
	
	// Variables du joueur à suivre

	joueurX = oJoueur.x - x;		//Acquisition dans 2 variables de la distance entre
	joueurY = oJoueur.y - y;		// le joueur et le boss.
									//Variable qui fait commencer les ennemis à suivre le joueur.

	// Mouvements du boss

	var deplacementHor = 0;
	var deplacementVer = 0;

	distanceMin = 2;	// Variable de distance x et y minimum que le boss peut se rapprocher
						// du joueur, 16 soit la moitié d'un sprite + 6 pour laisser un espace apparent.

	if ( global.aggro == 1)
	{
	if (distance_to_object(oJoueur) >= distanceMin)
	{
		if ( joueurX > distanceMin )			// Si le boss doit aller à droite.
		{
			deplacementHor = 1;
		}
		else if ( joueurX <= distanceMin and joueurX >= -distanceMin )	// Si le boss ne doit pas faire de mouvements horizontaux.
		{
			deplacementHor = 0;
		}
		else if ( joueurX < -distanceMin )	// Si le boss doit aller à gauche.
		{
			deplacementHor = -1;
		}

		if ( joueurY > distanceMin )		// Si le boss doit aller vers le haut.
		{
			deplacementVer = 1;
		}
		else if ( joueurY <= distanceMin and joueurY >= -distanceMin )	// Si le boss ne doit pas faire de mouvements verticaux.
		{
			deplacementVer = 0;
		}
		else if ( joueurY < -distanceMin )		// Si le boss doit aller vers le bas.
		{
			deplacementVer = -1;
		}
	}
	}

	vitesseHorizontale = deplacementHor * vitesseMarche;
	vitesseVerticale = deplacementVer * vitesseMarche;

	// Définitions des collisions aux murs

	if (place_meeting(x + vitesseHorizontale, y, oMur))					//Collision sur l'axe x.
	{
		while (!place_meeting(x + sign(vitesseHorizontale), y, oMur))
		{
			x = x + sign(vitesseHorizontale);
		}
	}
	else
	{
		x = x + vitesseHorizontale;
	}

	if (place_meeting(x, y + vitesseVerticale, oMur))					//Collision sur l'axe y.
	{
		while (!place_meeting(x, y + sign(vitesseVerticale), oMur))
		{
			y = y + sign(vitesseVerticale);
		}	
	}
	else
	{
		y = y + vitesseVerticale;
	}

	// Animations.

	image_angle = point_direction(x, y, oJoueur.x, oJoueur.y) + 180;
	
}

//Actions à la Mort du boss.

if (global.pv_boss<=0)
	{	
		mortX = x;													//Position x et y du boss
		mortY = y;													//au moment où il meurt.
		if (uneInstance == 0)
		{
			instance_create_depth(mortX, mortY, oBoss, oBossMort);		//Création de l'instance du cadavre.
			uneInstance += 1;
		}
		delaiBoss -= 1;												//Début du delai de fin de jeu.
	
		if (delaiBoss < 0)
		{
			game_end();												//Fin du jeu à la fin du délai.
		}
	}
	