#include <iostream>
#include "Memory.h"
#include "CPU.h"

using namespace std;
using namespace CPU_4001;

int main() {


	cout << "Initializing memory" << endl;

	Memory* memory = new Memory();

	cout << "Memory INITIALIZED" << endl;

	cout << "Creating program" << endl;

	//load value 3 into register 0
	memory->Write(1, 1);
	memory->Write(2, 3);
	//load value 6 into register 1
	memory->Write(3, 2); //load reg 1
	memory->Write(4, 6); //value 6
	//add
	memory->Write(5, 3); //Add
	//store sum
	memory->Write(6, 5); //store
	memory->Write(7, 11); //idk where to put the sum
	//print
	memory->Write(8, 6);
	memory->Write(9, 11); //i think i'm just gonna put the sum here lmao
	memory->Write(10, 4); //BEEP

	CPU* cpu = new CPU(memory);

	cout << "Initialized CPU" << endl;

	cout << "Running CPU" << endl;

	cpu->Run();

	
	delete cpu;
	delete memory;

	return 0;
}
