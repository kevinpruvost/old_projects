//Actions à la collision du joueur avec la zone de passage de niveau.

room_goto(niveau2);						//Passage au niveau 2.
instance_deactivate_object(inst_j1);	//Désactivation de l'instance joueur du niveau 1.
instance_activate_object(inst_j2);		//Activation de l'instance joueur du niveau 2.