//Quand la touche d'attaque est enfoncée.
mx = mouse_x;	//Variable x de la position du joueur.
my = mouse_y;	//Variable y de la position du joueur.
move_towards_point(mx,my,9);		//Mouvement vers le point instantané du joueur.
image_angle = point_direction(x, y, mx, my) - 90;		//Rotation du sprite du couteau du boss vers le joueur.