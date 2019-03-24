#ifndef COMMAND_H
#define COMMAND_H
#define DECVELX 0x00
#define DECVELY 0x01
#define INCVELX 0x02
#define INCVELY 0x03
#define AGACHAR 0x04
#define SALTAR  0x05
#define CANTCOMMANDS 6
class Command {
public:
	Command();
	virtual ~Command();
	virtual void execute() = 0;
protected:
private:
};
#endif // COMMAND_H
