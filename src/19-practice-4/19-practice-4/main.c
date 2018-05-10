/*
Solución Práctica #4 - Lección 19 del curso de C y Reversing de Ricardo Narvaja.
by @rextco
*/
#include <stdio.h>
#include <Windows.h>

int main(int argc, const char* argv[]) {	
	// printf("argc = %d\n", *(argv+1));


	LPVOID lpBuffer = NULL;					// 0040135E mov [ebp+_lpBuffer], 0
	DWORD lpBaseAddress = 0;				// 00401365 mov[ebp + _lpBaseAddress], offset dword_402BC5
	DWORD dwProcessId = 0x2370;				// 0040136C mov[ebp + _dwProcessId],

	HANDLE hProccess;
	

	if ( *(argv + 1) == NULL ) {			// Maybe a little tricky same behavior with argv[1] == 0
											// 00401373 mov eax, [ebp+argv]
											// 00401376 add eax, 4 <= (argv + 1) from linked list lesson
											// 00401379 cmp dword ptr[eax], 0
											// 0040137C jz short _bad_args

		printf("Program to read the contents of a memory position of a process\n");	// 004013BE _bad_args : ; "Programa para leer el contenido de una "...
																					// 004013BE mov[esp + 38h + Src], offset aProgramaParaLe
																					// 004013C5 call _printf
																					
		printf("Usage: untitled.exe address(hex) p_id(hex) \n");					// 004013CA mov[esp + 38h + Src], offset aUsoUntitled_ex; "Uso = Untitled.exe Addresss(hexa) Pid(h"...
																					// 004013D1 call _printf
																					// 004013D6 mov[esp + 38h + Src], offset aEjUntitled2_ex; "Ej = Untitled2.exe 402bc5 2370 \n"
		
		printf("i.e: untitled.exe 402bc5 2370\n");									// 004013DD call  _printf
		getchar();																	// 004013E2 call _getchar
																					// 004013E7 mov[esp + 38h + Src], 1; Code
		exit(1);																	// 004013EE cal _exit		
	}else {
		sscanf( *(argv + 1), "%x", &lpBaseAddress);					// 0040137E lea eax, [ebp+_lpBaseAddress]
																	// 00401381 mov[esp + 38h + _trash_added_by_compiler], eax
																	// 00401385 mov[esp + 38h + _format_for_printf], offset Format; "%x"
																	// 0040138D mov eax, [ebp + argv]
																	// 00401390 add eax, 4
																	// 00401393 mov eax, [eax]
																	// 00401395 mov[esp + 38h + Src], eax; Src
																	// 00401398 call _sscanf

		sscanf(*(argv + 2), "%x", &dwProcessId);					// 0040139D lea eax, [ebp + _dwProcessId]
																	// 004013A0 mov[esp + 38h + _trash_added_by_compiler], eax
																	// 004013A4 mov[esp + 38h + _format_for_printf], offset Format; "%x"
																	// 004013AC mov eax, [ebp + argv]
																	// 004013AF add eax, 8
																	// 004013B2 mov eax, [eax]
																	// 004013B4 mov[esp + 38h + Src], eax; Src
																	// 004013B7 call _sscanf
		

		printf("lpBaseAddress => 0x%x\n", (unsigned int)lpBaseAddress);
		printf("dwProcessId => 0x%x\n", (unsigned int)dwProcessId);
		/*
		https://msdn.microsoft.com/en-us/library/windows/desktop/ms684320(v=vs.85).aspx
		HANDLE WINAPI OpenProcess(
			_In_ DWORD dwDesiredAccess,
			_In_ BOOL  bInheritHandle,
			_In_ DWORD dwProcessId
		);
		

		*/
		// EnableDebugPriv(); <= No need for Visual Studio maybe for Dev C
		// hProccess = OpenProcess((DWORD)0x1F0FF, FALSE, dwProcessId);			// 0040141E mov eax, [ebp+_dwProcessId] <= Harcoded
		hProccess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessId);		// 0040141E mov eax, [ebp+_dwProcessId] 
																				// 00401421 mov[esp + 38h + _trash_added_by_compiler], eax; dwProcessId
																				// 00401425 mov[esp + 38h + _format_for_printf], 0; bInheritHandle
																				// 0040142D mov[esp + 38h + Src], 1F0FFFh; dwDesiredAccess
																				// 00401434 call _OpenProcess@12; OpenProcess(x,x,x)

		/*
		https://msdn.microsoft.com/en-us/library/windows/desktop/ms680553(v=vs.85).aspx
		BOOL WINAPI ReadProcessMemory(
			_In_  HANDLE  hProcess,
			_In_  LPCVOID lpBaseAddress,
			_Out_ LPVOID  lpBuffer,
			_In_  SIZE_T  nSize,
			_Out_ SIZE_T  *lpNumberOfBytesRead
		);
		*/		
		ReadProcessMemory(hProccess, (LPCVOID)lpBaseAddress, &lpBuffer, 4, NULL);// 0040143C mov [ebp+hProcess], eax ; Type = HANDLE
																				// 0040143F mov[esp + 38h + lpNumberOfBytesRead], 0; lpNumberOfBytesRead
																				// 00401447 mov[esp + 38h + nSize], 4; nSize
																				// 0040144F lea eax, [ebp + _lpBuffer]
																				// 00401452 mov[esp + 38h + _trash_added_by_compiler], eax; lpBuffer
																				// 00401456 mov eax, [ebp + _lpBaseAddress]
																				// 00401459 mov[esp + 38h + _format_for_printf], eax; lpBaseAddress
																				// 0040145D mov eax, [ebp + hProcess]
																				// 00401460 mov[esp + 38h + Src], eax; hProcess
																				// 00401463 call _ReadProcessMemory@20; ReadProcessMemory(x, x, x, x, x)			

		if (lpBuffer != NULL) {
			printf("memory content => 0x%x\n", (unsigned int)lpBuffer);
		}
		else {
			printf("fail to read memory\n");
		}
	}

	getchar();
	return 0;
}