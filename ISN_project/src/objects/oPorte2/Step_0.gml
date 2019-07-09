delai -= 1 ;	// Enlever 1 à délai à chaque frame donc delai sera égal à 0 au bout d'une seconde.

// Action des touches du clavier

appuyerPorte = keyboard_check(ord("F"));			//Variable appuyerPorte changeant de 1 à 0 avec la touche F

// Animation du déplacement

if ( distance_to_object(oJoueur) <= 50 )
	{
	if (appuyerPorte == 1 and image_angle == 270 and delai <= 0)
		{
		image_angle = 180;								//Position de la porte
		x = 803;
		y = 640;
		instance_activate_object(inst_p20);		//Activation			Position de la physique de la porte
		instance_deactivate_object(inst_p21);		//Desactivation
		audio_play_sound(sonOuverturePorte, 10, false);
		
		delai = room_speed * seconde;					//Variable delai remis au départ
		}
	else if (appuyerPorte == 1 and image_angle == 180 and delai <= 0)
		{
		image_angle = 270;								//Position de la porte
		x = 855;
		y = 629;
		instance_deactivate_object(inst_p20);		//Activation			Position de la physique de la porte
		instance_activate_object(inst_p21);		//Desactivation
		audio_play_sound(sonOuverturePorte, 10, false);
		
		delai = room_speed * seconde;					//Variable delai remis au départ
		}
	}