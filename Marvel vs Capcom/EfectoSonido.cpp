/*
 * EfectoSonido.cpp
 *
 *  Created on: Jun 16, 2019
 *      Author: jorge
 */

#include "EfectoSonido.h"

EfectoSonido::EfectoSonido(int tecla) {
	// TODO Auto-generated constructor stub
	this->tecla_activacion=tecla;

}
bool EfectoSonido::init(){

	//Initialize SDL_mixer

	if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
	{
		printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );

		return false;
	}else

		return true;


}

bool EfectoSonido::loadMedia(char* path) {
	//Loading success flag
	bool success = true;


	//Load sound effects
	audio= Mix_LoadWAV(path);
	if(audio== NULL )
	{
		printf( "Sonido, LaadMedia: SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}

	return success;
}
const int EfectoSonido::get_tecla(){
	return this->tecla_activacion;

}
/*
 In the event loop, we play a sound effect when the 1, 2, 3, or 4 keys are pressed. The way to play a Mix_Chunk is by
calling Mix_PlayChannel. The first argument is the channel you want to use to play it. Since we don't care which channel
it comes out of, we set the channel to negative 1 which will use the nearest available channel. The second argument is the
sound effect and last argument is the number of times to repeat the effect. We only want it to play once per button press,
so we have it repeat 0 times.
ejemplo Mix_PlayChannel( -1, gScratch, 0 );
 */
void EfectoSonido::reproducir_sonido(){


	Mix_PlayChannel( -1,this->audio, 0 );


}
void EfectoSonido::parar_sonido(){

	Mix_HaltMusic();


}
EfectoSonido::~EfectoSonido() {
	// TODO Auto-generated destructor stub
}

