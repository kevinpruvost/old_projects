if (delai2 > 0)								//Barre de charge de l'attaque importante déchargée.
{
	draw_sprite(tirPuissant,0,10,900);
}
if (delai2 <= 0)							//Barre de charge de l'attaque importante chargée.
{
	draw_sprite(tirPuissant,1,10,900);
}
