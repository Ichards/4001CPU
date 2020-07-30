#ifndef CPU_MEMORY
#define CPU_MEMORY

namespace CPU_4001 {
	typedef unsigned char byte;
	class Memory {
		public:
			const byte MaxAddress;
		private:
			byte* MemorySpace;
		public:
			Memory();
			~Memory();

			void Clear();
			
			const byte& Read(const byte& p_Address);
			void Write(const byte& p_Address, const byte& p_Value);
	};
}

#endif
