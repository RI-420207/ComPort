#pragma once

ref class ModbusSlave
{
public:
	ModbusSlave();
	array< unsigned char >^ ReadCoilStatus(unsigned __int16, unsigned __int16);
	array< unsigned char >^ ReadDiscreteInputs(unsigned __int16, unsigned __int16);
	array< unsigned char >^ ReadHoldingRegisters(unsigned __int16, unsigned __int16);
	array< unsigned char >^ ReadInputRegisters(unsigned __int16, unsigned __int16);
	array< unsigned char >^ Diagnostic();
private:

	unsigned __int8* DiscreteInputs;
	unsigned __int8* Coils;
	unsigned __int16* InputRegisters;
	unsigned __int16* Holdingregisters;
};

