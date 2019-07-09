// Désactivation des portes ouvertes

if (debut == 0)
{
	instance_deactivate_object(inst_p0);
	instance_deactivate_object(inst_p20);
	instance_deactivate_object(inst_p30);
	debut = 1;
}

delai -= 1 ; // Enlever 1 à délai à chaque frame donc delai sera égal à 0 au bout d'une seconde.

// Action des touches du clavier

appuyerPorte = keyboard_check(ord("F"));			//Variable appuyerPorte changeant de 1 à 0 avec la touche F

// Animation du déplacement

if ( distance_to_object(oJoueur) <= 50 )
	{
	if (appuyerPorte == 1 and image_angle == 0 and delai <= 0)
		{
	image_angle = 90;								//Position de la porte
	x = 1846;
	y = 682;
	instance_activate_object(inst_p0);		//Activation		Position de la physique de la porte
	instance_deactivate_object(inst_p1);	//Desactivation
	audio_play_sound(sonOuverturePorte, 10, false);
	
	delai = room_speed * seconde;					//Variable delai remis au départ
		}
	else if (appuyerPorte == 1 and image_angle == 90 and delai <= 0)
		{
	image_angle = 0;								//Position de la porte
	x = 1824;
	y = 672;
	instance_deactivate_object(inst_p0);		//Activation			Position de la physique de la porte
	instance_activate_object(inst_p1);			//Desactivation
	audio_play_sound(sonOuverturePorte, 10, false);
	
	delai = room_speed * seconde;					//Variable delai remis au départ
		}
	}

