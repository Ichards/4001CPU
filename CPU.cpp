#include "CPU.h"
#include <iostream>

namespace CPU_4001 {

	CPU::CPU(Memory* p_Memory)
		:
		m_ReservedAddress(0),
		m_ProgramStart(1),
		m_AddressCeiling(253), //longest operation is 2 bytes.
		m_ProgramCounter(m_ProgramStart),
		m_Register0(0),
		m_Register1(0),
		m_OverflowError(false),
		m_UnderflowError(false),
		m_SignedMode(false),
		m_Halt(false),
		m_Memory(p_Memory)
		{
		}

	CPU::~CPU() {
		m_Memory = nullptr;
	}

	void CPU::Reset() {
		m_ProgramCounter = m_ProgramStart;
		m_OverflowError = false;
		m_UnderflowError = false;
		m_SignedMode = false;
		m_Halt = false;
	}

	const byte CPU::Fetch() {
		byte l_opCode = 0; //not sure why to initialize it at 0, but i will :/
		l_opCode = m_Memory->Read(m_ProgramCounter);
		m_ProgramCounter++;
		if (m_ProgramCounter > m_AddressCeiling) {
			m_Halt = true;
		}
		// has to stop after 253, since it would increment to 254, and then
		// COULD increment to 255 (load op), and then would fetch another
		// instruction, after which it would increment to 256. DASTARDLY.
		// personally, i would want to prevent it from fetching in the last
		// byte of memory, but that's neither here nor there.
		return l_opCode;
	}

	void CPU::Decode(const byte& p_OpCode) {
		switch(p_OpCode) {
			case 0:
				m_Halt = true;
				//halt
				break;
			case 1: //load next byte into register 0
				m_Register0 = m_Memory->Read(m_ProgramCounter);
				//m_ProgramCounter has already been incremented.
				//well, time to increment it again
				m_ProgramCounter++;
				break;
			case 2: //LOAD1
				m_Register1 = m_Memory->Read(m_ProgramCounter);
				m_ProgramCounter++;
				break;
			case 3: //Add
				m_Register0 = m_Register0 + m_Register1;
				break;
			case 4: //Beep
				std::cout << "BEEEEP" << std::endl; //generally beeps
				break;
			case 5: //Store
				m_Register1 = m_Memory->Read(m_ProgramCounter++);
				m_Memory->Write(m_Register1, m_Register0);
				break;
			case 6: //Print
				m_Register1 = m_Memory->Read(m_ProgramCounter++);
				m_Register0 = m_Memory->Read(m_Register1);
				std::cout << static_cast<unsigned>(m_Register0)
				<< std::endl;
		}
	}

	void CPU::Run() {
		while (!m_Halt) { //0 is gonna be HALT
			m_Memory->Write(m_ReservedAddress, Fetch());
			
			Decode(m_Memory->Read(m_ReservedAddress));
		}	
	}
}		
