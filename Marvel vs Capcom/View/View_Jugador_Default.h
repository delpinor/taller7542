/*
 * ViewJugadorDefault.h
 *
 *  Created on: 13 abr. 2019
 *      Author: maciel
 */

#ifndef VIEW_VIEW_JUGADOR_DEFAULT_H_
#define VIEW_VIEW_JUGADOR_DEFAULT_H_

#include "View_Jugador.h"

class View_Jugador_Default: public View_Jugador {
	public:
		View_Jugador_Default();
		void initialize(Jugador *model,
			LTexture * texturaJugador);

	private:
		void getSprites();
};

#endif /* VIEW_VIEW_JUGADOR_DEFAULT_H_ */
