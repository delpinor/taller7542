/*
 * Sonido.cpp
 *
 *  Created on: Jun 15, 2019
 *      Author: jorge
 */

#include "Sonido.h"



Sonido::Sonido(int tecla) {
	// TODO Auto-generated constructor stub
	this->tecla_activacion=tecla;
}
/*
To initialize SDL_mixer we need to call Mix_OpenAudio. The first argument sets the sound frequency,
and 44100 is a standard frequency that works on most systems. The second argument determines the
sample format, which again here we're using the default. The third argument is the number of hardware channels,
and here we're using 2 channels for stereo. The last argument is the sample size, which determines the size of
the chunks we use when playing sound. 2048 bytes (AKA 2 kilobyes) worked fine for me, but you may have to experiment
with this value to minimize lag when playing sounds.
 */
bool Sonido::init(){

	//Initialize SDL_mixer
	if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
	{
		printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );

		return false;
	}else
		return true;


}

bool Sonido::loadMedia(char* path) {
	//Loading success flag
	bool success = true;


	//Load sound effects
	audio= Mix_LoadMUS( path);
	if(audio== NULL )
	{
		printf( "Sonido, LaadMedia: SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}

	return success;
}
const int Sonido::get_tecla(){
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
void Sonido::reproducir_sonido(){

	Mix_PlayMusic( this->audio, -1 );


}
void Sonido::parar_sonido(){

	Mix_HaltMusic();

}
Sonido::~Sonido() {

	Mix_FreeMusic(audio);
	audio= NULL;
	Mix_Quit();
}

