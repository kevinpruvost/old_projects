//Variables aggro.

if distance_to_object(oProvocation) <= 2	//Si le joueur rentre dans la zone de provocation des ennemis, la variable provocation s'active.
{
	global.aggro = 1;
}

if distance_to_object(oProvocationBoss) <= 2	//Si le joueur rentre dans la zone de provocation du boss, la variable provocation s'active.
{
	global.aggroBoss = 1;
}

// Actions des touches du clavier

appuyerAttaque= mouse_check_button(mb_left);	//Variable appuyerAttaque changeant de 1 à 0 avec la touche Clic gauche.
appuyerAttaque2= mouse_check_button(mb_right);	//Variable appuyerAttaque2 changeant de 1 à 0 avec la touche Clic droit.
appuyerHaut = keyboard_check(ord("Z"));			//Variable appuyerHaut changeant de 1 à 0 avec la touche Z.
appuyerGauche = keyboard_check(ord("Q"));		//Variable appuyerGauche changeant de 1 à 0 avec la touche Q.
appuyerBas = keyboard_check(ord("S"));			//Variable appuyerBas changeant de 1 à 0 avec la touche S.
appuyerDroite = keyboard_check(ord("D"));		//Variable appuyerDroite changeant de 1 à 0 avec la touche D.
appuyerSprint = keyboard_check(vk_lshift);	//Variable appuyerSprint changeant de 1 à 0 avec la touche Maj.

// Mouvements du personnage

var deplacementHor = appuyerDroite - appuyerGauche;
vitesseHorizontale = deplacementHor * vitesseMarche;
var deplacementVer = appuyerBas - appuyerHaut;
vitesseVerticale = deplacementVer * vitesseMarche;

if ( appuyerSprint == 1 )
{
	vitesseMarche = vitesseMarcheInitiale * 1.5;	
}
else if ( appuyerSprint == 0 )
{
	vitesseMarche = vitesseMarcheInitiale;
}


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

//Animations.
	//Règlage de l'angle et du sprite du joueur.
if (vitesseHorizontale == 0 and vitesseVerticale == 0 and image_angle == 90)
{
	sprite_index = fixe;	//Sprite.
	image_angle = 90;	//Angle.
}
	else if (deplacementHor > 0)
	{
		sprite_index = mouvement;	//Sprite.
		image_angle = 90;	//Angle.
	}
		
if (vitesseHorizontale == 0 and vitesseVerticale == 0 and image_angle == 270)
{
	sprite_index = fixe;	//Sprite.
	image_angle = 270;	//Angle.
}
	else if (deplacementHor < 0)
	{
		sprite_index = mouvement;	//Sprite.
		image_angle = 270;	//Angle.
	}
	
if (vitesseHorizontale == 0 and vitesseVerticale == 0 and image_angle == 180)
{
	sprite_index = fixe;	//Sprite.
	image_angle = 180;	//Angle.
}
	else if (deplacementVer < 0)
	{
		sprite_index = mouvement;	//Sprite.
		image_angle = 180;	//Angle.
	}

if (vitesseHorizontale == 0 and vitesseVerticale == 0 and image_angle == 0)
{
	sprite_index = fixe;	//Sprite.
	image_angle = 0;	//Angle.
}
	else if (deplacementVer > 0)
	{
		sprite_index = mouvement;	//Sprite.
		image_angle = 0;	//Angle.
	}
	
//Attaque du joueur

delai -= 1;		//Faire en sorte que le délai s'écoule à chaque frame.
delai2 -= 1;

if (appuyerAttaque == true and delai <= 0)				//Création de l'attaque normale.
{
	instance_create_depth(x, y, oJoueur, oCouteau);		//Création de l'instance du couteau.
	audio_play_sound(sonTirNormal, 10, false);			//Lancement du son du lancer.
	delai = delaiBase;
}

if (appuyerAttaque2 == true and delai2 <= 0)			//Création de l'attaque importante.
{
	instance_create_depth(x, y + 30, oJoueur, oCouteau);	//Création de l'instance du couteau.
	instance_create_depth(x, y + 15, oJoueur, oCouteau);	//Création de l'instance du couteau.
	instance_create_depth(x, y, oJoueur, oCouteau);			//Création de l'instance du couteau.
	instance_create_depth(x, y - 15, oJoueur, oCouteau);	//Création de l'instance du couteau.
	instance_create_depth(x, y - 30, oJoueur, oCouteau);	//Création de l'instance du couteau.
	audio_play_sound(sonTirPuissant, 10, false);			//Lancement du son du lancer.
	delai2 = delai2Base;
}

