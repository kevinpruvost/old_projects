mortX = x;													//Position x et y de l'ennemi
mortY = y;													// au moment où il meurt.
instance_create_depth(mortX, mortY, oEnnemi, oEnnemiMort);	// Création de l'instance du cadavre.
instance_destroy()
