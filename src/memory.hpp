#pragma once
#include <Windows.h>

class memory
{
private:
	HANDLE process_handle;
public:

	template <typename T>
	T read( const std::uintptr_t &dw_address)
	{
		T value = { };
		ReadProcessMemory(this->process_handle, dw_address, value, sizeof(T), 0);
		return value;
	}
	template <typename T>
	bool write(const std::uintptr_t& dw_address, T value)
	{
		return WriteProcessMemory(this->process_handle, dw_address, value, sizeof(value), 0);
	}
};