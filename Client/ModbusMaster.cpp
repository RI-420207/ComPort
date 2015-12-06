#include "ModbusMaster.h"


ModbusImplMaster::ModbusImplMaster()
{
}


array< unsigned char >^ ModbusImplMaster::ReadCoilStatus(unsigned __int16 first, unsigned __int16 count){
	array< unsigned char >^ bytes = gcnew array< unsigned char >(5);
	bytes[0] = 1;
	bytes[1] = (__int8)(first >> 8);
	bytes[2] = (__int8)first;
	bytes[3] = (__int8)(count >> 8);
	bytes[4] = (__int8)count;
	return bytes;
}

array< unsigned char >^ ModbusImplMaster::ReadDiscreteInputs(unsigned __int16 first, unsigned __int16 count){
	array< unsigned char >^ bytes = gcnew array< unsigned char >(5);
	bytes[0] = 2;
	bytes[1] = (__int8)(first >> 8);
	bytes[2] = (__int8)first;
	bytes[3] = (__int8)(count >> 8);
	bytes[4] = (__int8)count;
	return bytes;
}

array< unsigned char >^ ModbusImplMaster::ReadHoldingRegisters(unsigned __int16 first, unsigned __int16 count){
	array< unsigned char >^ bytes = gcnew array< unsigned char >(5);
	bytes[0] = 3;
	bytes[1] = (__int8)(first >> 8);
	bytes[2] = (__int8)first;
	bytes[3] = (__int8)(count >> 8);
	bytes[4] = (__int8)count;
	return bytes;
}

array< unsigned char >^ ModbusImplMaster::ReadInputRegisters(unsigned __int16 first, unsigned __int16 count){
	array< unsigned char >^ bytes = gcnew array< unsigned char >(5);
	bytes[0] = 4;
	bytes[1] = (__int8)(first >> 8);
	bytes[2] = (__int8)first;
	bytes[3] = (__int8)(count >> 8);
	bytes[4] = (__int8)count;
	return bytes;
}