//Actions à la collision du couteau avec le boss.

audio_play_sound(sonTouche, 10, false);		//Lancement du son de réception d'un couteau.
global.pv_boss -= 1;						//Enlever un pv du boss dans la variable.
instance_destroy();							//Destruction de l'instance du couteau.