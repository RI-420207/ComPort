#pragma once
//using namespace System;

ref class ModbusImplMaster
{
public:
	ModbusImplMaster();
	array< unsigned char >^ ReadCoilStatus(unsigned __int16, unsigned __int16);
	array< unsigned char >^ ReadDiscreteInputs(unsigned __int16, unsigned __int16);
	array< unsigned char >^ ReadHoldingRegisters(unsigned __int16, unsigned __int16);
	array< unsigned char >^ ReadInputRegisters(unsigned __int16, unsigned __int16);
};

