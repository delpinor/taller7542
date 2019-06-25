#ifndef COMMAND_H
#define COMMAND_H
#define DECVELX 0x00
#define DECVELY 0x01
#define INCVELX 0x02
#define INCVELY 0x03
#define AGACHAR 0x04
#define SALTAR  0x05
#define CAMBIAR_PERSONAJE  0x06
#define PARAR  0x07
#define PINIA  0x08
#define PINION  0x09
#define PATADA  0x0A
#define PATADON  0x0B
#define DEFENSA 0x0C
#define PATADA_AGACHADO  0x0D
#define PINION_AGACHADO  0x0E
#define PATADON_AGACHADO  0x0F
#define PINIA_AGACHADO  0x10
#define ARROJAR  0x11
#define PODER  0x12
#define CANTCOMMANDS 20


class Command {
public:
	Command();
	virtual ~Command();
	virtual void execute(int i) = 0;
protected:
private:
};
#endif // COMMAND_H
