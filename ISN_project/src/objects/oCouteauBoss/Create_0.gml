//Quand le couteau du boss est crée. ( quand il attaque le joueur )
mx = oJoueur.x;		//Variable x de la position du joueur.
my = oJoueur.y;		//Variable y de la posiiton du joueur.
move_towards_point(mx,my,5);		//Mouvement vers le point instantané du joueur.
image_angle = point_direction(x, y, mx, my) - 90;		//Rotation du sprite du couteau du boss vers le joueur.