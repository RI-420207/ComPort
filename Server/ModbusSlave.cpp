#include "ModbusSlave.h"
#include <random>
#include <ctime>

ModbusSlave::ModbusSlave()
{
	srand(time(0));
	this->DiscreteInputs = new unsigned __int8[8192];
	this->Coils = new unsigned __int8[8192];
	this->InputRegisters = new unsigned __int16[65536];
	this->Holdingregisters = new unsigned __int16[65536];

	for (int i = 0; i < 8192; i++){
		this->DiscreteInputs[i] = (__int8)rand();
		this->Coils[i] = (__int8)rand();
	}
	for (int i = 0; i < 65536; i++){
		this->InputRegisters[i] = (__int16)rand();
		this->Holdingregisters[i] = (__int16)rand();
	}
}

array< unsigned char >^ ModbusSlave::ReadCoilStatus(unsigned __int16 first, unsigned __int16 count){
	__int8 resultLength = (__int8)System::Convert::ToInt16(System::Math::Ceiling((double)count / 8));
	array< unsigned char >^ bytes = gcnew array< unsigned char >(resultLength + 1);
	bytes[0] = resultLength;
	for (int i = 0; i < resultLength; i++){
		bytes[i + 1] = '\0';
	}
	for (__int16 i = first ; i< (first + count); i++){
		bytes[(i - first) / 8 + 1] |= ((this->Coils[i / 8] & (1 << (7 - i % 8))) >> (7- i % 8)) << (7 - ((i - first) % 8));
	}
	return bytes;
}

array< unsigned char >^ ModbusSlave::ReadDiscreteInputs(unsigned __int16 first, unsigned __int16 count){
	__int8 resultLength = (__int8)System::Convert::ToInt16(System::Math::Ceiling((double)count / 8));
	array< unsigned char >^ bytes = gcnew array< unsigned char >(resultLength + 1);
	bytes[0] = resultLength;
	for (int i = 0; i < resultLength; i++){
		bytes[i + 1] = '\0';
	}
	for (__int16 i = first; i< (first + count); i++){
		bytes[(i - first) / 8 + 1] |= ((this->DiscreteInputs[i / 8] & (1 << (7 - i % 8))) >> (7 - i % 8)) << (7 - ((i - first) % 8));
	}
	return bytes;
}
array< unsigned char >^ ModbusSlave::ReadHoldingRegisters(unsigned __int16 first, unsigned __int16 count){
	__int8 resultLength = (__int8)(count * 2);
	array< unsigned char >^ bytes = gcnew array< unsigned char >(resultLength + 1);
	bytes[0] = resultLength;
	for (int i = 0; i < resultLength; i++){
		bytes[i + 1] = '\0';
	}
	for (__int16 i = first; i< (first + count); i++){
		bytes[(i - first) * 2 + 1] = (__int8)(this->Holdingregisters[i] >> 8);
		bytes[(i - first) * 2 + 2] = (__int8)(this->Holdingregisters[i]);
	}
	return bytes;
}
array< unsigned char >^ ModbusSlave::ReadInputRegisters(unsigned __int16 first, unsigned __int16 count){
	__int8 resultLength = (__int8)(count * 2);
	array< unsigned char >^ bytes = gcnew array< unsigned char >(resultLength + 1);
	bytes[0] = resultLength;
	for (int i = 0; i < resultLength; i++){
		bytes[i + 1] = '\0';
	}
	for (__int16 i = first; i< (first + count); i++){
		bytes[(i - first) * 2 + 1] = (__int8)(this->InputRegisters[i] >> 8);
		bytes[(i - first) * 2 + 2] = (__int8)(this->InputRegisters[i]);
	}
	return bytes;
}

array< unsigned char >^ ModbusSlave::Diagnostic(){
	const char *str = "All OK";
	array <unsigned char>^ result = gcnew array<unsigned char>(strlen(str)+1);
	result[0] = 8;
	for (int i = 0; i < result->Length - 1; i++){
		result[i+1] = str[i];
	}
	return result;
}