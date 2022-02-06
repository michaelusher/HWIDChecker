#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <intrin.h>

void main() { // retrives HWID information and prints it out.
	std::cout << "HWID information" << std::endl;
	TCHAR volumeName[MAX_PATH + 1] = { 0 };
	TCHAR fileSystemName[MAX_PATH + 1] = { 0 };
	DWORD serialNumber = 0;
	DWORD maxComponentLen = 0;
	DWORD fileSystemFlags = 0;
	if (GetVolumeInformation(
		_T("C:\\"),
		volumeName,
		ARRAYSIZE(volumeName),
		&serialNumber,
		&maxComponentLen,
		&fileSystemFlags,
		fileSystemName,
		ARRAYSIZE(fileSystemName))) {
		std::cout << "Volume Name: " << volumeName << std::endl;
		std::cout << "HDD Serial: " << serialNumber << std::endl;
		std::cout << "File System Type: " << fileSystemName << std::endl;
		std::cout << "Max Component Length: " << maxComponentLen << std::endl;
	}
	system("pause");
}
