#include "Memory.h"

namespace CPU_4001 {
	
	Memory::Memory()
		:
		MaxAddress(255), //I would want to change 255 to an actual value from
				 //the c++ value limits header, but I'll do it later
		MemorySpace(new byte[MaxAddress+1])
	{
		Clear();
	}

	Memory::~Memory() {
		if (MemorySpace != nullptr) {
			delete[] MemorySpace;
			MemorySpace = nullptr;
		}
	}

	void Memory::Clear() {
		for (int i=0; i<MaxAddress; i++) {
			MemorySpace[i] = 0;
		}
	}

	const byte& Memory::Read(const byte& p_Address) {
		return MemorySpace[p_Address];
	}

	void Memory::Write(const byte& p_Address, const byte& p_Value) {
		MemorySpace[p_Address] = p_Value;
	}


}

