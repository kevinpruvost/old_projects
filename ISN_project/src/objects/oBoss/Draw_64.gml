if (global.pv_boss > 0)												//Affichage de la vie du boss.
{
	draw_text(100, 950, "VIE DU BOSS :" + string(global.pv_boss));
}
else if (global.pv_boss <= 0)										//Affichage de la mort du boss.
{
	draw_text(100, 950, "LE BOSS EST MORT !");
}