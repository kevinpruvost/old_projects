// Variables du joueur à suivre

joueurX = oJoueur.x - x;		//Acquisition dans 2 variables de la distance entre
joueurY = oJoueur.y - y;		// le joueur et l'ennemi.
				//Variable qui fait commencer les ennemis à suivre le joueur.

// Mouvements du personnage

var deplacementHor = 0;
var deplacementVer = 0;

distanceMin = 2;	// Variable de distance x et y minimum que l'ennemi peut se rapprocher
					// du joueur, 16 soit la moitié d'un sprite + 6 pour laisser un espace apparent.

if ( global.aggro == 1)
{
if (distance_to_object(oJoueur) >= distanceMin)
{
	if ( joueurX > distanceMin )			// Si l'ennemi doit aller à droite.
	{
		deplacementHor = 1;
	}
	else if ( joueurX <= distanceMin and joueurX >= -distanceMin )	// Si l'ennemi ne doit pas faire de mouvements horizontaux.
	{
		deplacementHor = 0;
	}
	else if ( joueurX < -distanceMin )	// Si l'ennemi doit aller à gauche.
	{
		deplacementHor = -1;
	}

	if ( joueurY > distanceMin )		// Si l'ennemi doit aller vers le haut.
	{
		deplacementVer = 1;
	}
	else if ( joueurY <= distanceMin and joueurY >= -distanceMin )	// Si l'ennemi ne doit pas faire de mouvements verticaux.
	{
		deplacementVer = 0;
	}
	else if ( joueurY < -distanceMin )		// Si l'ennemi doit aller vers le bas.
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

// Animations

if (vitesseHorizontale == 0 and vitesseVerticale == 0 and image_angle == 90)
{
	sprite_index = fEnnemi;
	image_angle = 90;
}
	else if (deplacementHor > 0)
	{
		sprite_index = mEnnemi;
		image_angle = 90;
	}
		
if (vitesseHorizontale == 0 and vitesseVerticale == 0 and image_angle == 270)
{
	sprite_index = fEnnemi;
	image_angle = 270;
}
	else if (deplacementHor < 0)
	{
		sprite_index = mEnnemi;
		image_angle = 270;
	}
	
if (vitesseHorizontale == 0 and vitesseVerticale == 0 and image_angle == 180)
{
	sprite_index = fEnnemi;
	image_angle = 180;
}
	else if (deplacementVer < 0)
	{
		sprite_index = mEnnemi;
		image_angle = 180;
	}

if (vitesseHorizontale == 0 and vitesseVerticale == 0 and image_angle == 0)
{
	sprite_index = fEnnemi;
	image_angle = 0;
}
	else if (deplacementVer > 0)
	{
		sprite_index = mEnnemi;
		image_angle = 0;
	}