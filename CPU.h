#ifndef CPU_PROCESSOR
#define CPU_PROCESSOR

#include "Memory.h"

namespace CPU_4001 {

	class CPU {
		public:
			const byte m_ReservedAddress;
			const byte m_ProgramStart;
			const byte m_AddressCeiling;

		private:
			byte m_ProgramCounter;
			byte m_Register0;
			byte m_Register1;
			bool m_OverflowError;
			bool m_UnderflowError;
			bool m_SignedMode;
			bool m_Halt;

			const byte Fetch();
			void Decode(const byte&);

			Memory* m_Memory;
		public:
			CPU(Memory* p_Memory);
			~CPU();

			void Reset();

			void Run();
	};
}

#endif
