//Actions à la collision du couteau avec l'ennemi.

audio_play_sound(sonTouche, 10, false);		//Lancement du son de réception d'un couteau.
instance_destroy();							//Destruction de l'instance du couteau.