#include <iostream>
#include <windows.h>
#include "Encryption.hpp"

static char base64[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

BOOL ShiftBytes(DWORD* out, DWORD64 in)
{
	*(BYTE*)out = *(BYTE*)in >> 2;
	char enc_char_1 = 0x10 * *(BYTE*)in;
	*(BYTE*)(out + 1) = enc_char_1;
	*(BYTE*)(out + 1) = (enc_char_1 | (*(BYTE*)(in + 1) >> 4)) & 0x3F;
	char enc_char_2 = 4 * *(BYTE*)(in + 1);
	*(BYTE*)(out + 2) = enc_char_2;
	*(BYTE*)(out + 2) = (enc_char_2 | (*(BYTE*)(in + 2) >> 6)) & 0x3F;
	char result = *(BYTE*)(in + 2) & 0x3F;
	*(BYTE*)(out + 3) = result;
	return result;
}

VOID Encode(DWORD64 in, DWORD* out)
{
	DWORD shift_index;
	ShiftBytes(&shift_index, in);
	*(BYTE*)out = base64[shift_index];
	*(BYTE*)(out + 1) = base64[(shift_index + 1)];
	*(BYTE*)(out + 2) = base64[(shift_index + 2)];
	*(BYTE*)(out + 3) = base64[(shift_index + 3)];
	if (*(BYTE*)(in + 4) == 1)
	{
		*(BYTE*)(out + 2) = 0x3D;
	}
	if (*(BYTE*)(in + 4) == 2)
		*(BYTE*)(out + 3) = 0x3D;
}

VOID EncodeBytes32(DWORD64* out, DWORD64* in)
{
	DWORD v12 = *(DWORD*)in;
	*(BYTE*)out = *(DWORD*)in >> 24;
	*(BYTE*)(out + 1) = BYTE2(v12);
	*(BYTE*)(out + 2) = BYTE1(v12);
	*(BYTE*)(out + 3) = v12;
	DWORD v13 = *(DWORD*)(in + 4);
	*(BYTE*)(out + 4) = *(DWORD*)(in + 4) >> 24;
	*(BYTE*)(out + 5) = BYTE2(v13);
	*(BYTE*)(out + 6) = BYTE1(v13);
	*(BYTE*)(out + 7) = v13;
	DWORD v14 = *(DWORD*)(in + 8);
	*(BYTE*)(out + 8) = *(DWORD*)(in + 8) >> 24;
	*(BYTE*)(out + 9) = BYTE2(v14);
	*(BYTE*)(out + 10) = BYTE1(v14);
	*(BYTE*)(out + 11) = v14;
	DWORD v15 = *(DWORD*)(in + 12);
	*(BYTE*)(out + 12) = *(DWORD*)(in + 12) >> 24;
	*(BYTE*)(out + 13) = BYTE2(v15);
	*(BYTE*)(out + 14) = BYTE1(v15);
	*(BYTE*)(out + 15) = v15;
	DWORD v16 = *(DWORD*)(in + 16);
	*(BYTE*)(out + 16) = *(DWORD*)(in + 16) >> 24;
	*(BYTE*)(out + 17) = BYTE2(v16);
	*(BYTE*)(out + 18) = BYTE1(v16);
	*(BYTE*)(out + 19) = v16;
	DWORD v17 = *(DWORD*)(in + 20);
	*(BYTE*)(out + 20) = *(DWORD*)(in + 20) >> 24;
	*(BYTE*)(out + 21) = BYTE2(v17);
	*(BYTE*)(out + 22) = BYTE1(v17);
	*(BYTE*)(out + 23) = v17;
	DWORD v18 = *(DWORD*)(in + 24);
	*(BYTE*)(out + 24) = *(DWORD*)(in + 24) >> 24;
	*(BYTE*)(out + 25) = BYTE2(v18);
	*(BYTE*)(out + 26) = BYTE1(v18);
	*(BYTE*)(out + 27) = v18;
	DWORD v19 = *(DWORD*)(in + 28);
	*(BYTE*)(out + 28) = *(DWORD*)(in + 28) >> 24;
	*(BYTE*)(out + 29) = BYTE2(v19);
	*(BYTE*)(out + 30) = BYTE1(v19);
	*(BYTE*)(out + 31) = v19;
}

DWORD64* BuildByteArray()
{
	PVOID ret = malloc(32);
	/* Set default values */
	*(DWORD*)((uintptr_t)ret)	   = 0x6A09E667;
	*(DWORD*)((uintptr_t)ret + 4)  = 0xBB67AE85;
	*(DWORD*)((uintptr_t)ret + 8)  = 0x3C6EF372;
	*(DWORD*)((uintptr_t)ret + 12) = 0xA54FF53A;
	*(DWORD*)((uintptr_t)ret + 16) = 0x510E527F;
	*(DWORD*)((uintptr_t)ret + 20) = 0x9B05688C;
	*(DWORD*)((uintptr_t)ret + 24) = 0x1F83D9AB;
	*(DWORD*)((uintptr_t)ret + 28) = 0x5BE0CD19;
	return (DWORD64*)ret;
}

int main()
{
	auto test = BuildByteArray();
	PVOID test2 = malloc(32);
	EncodeBytes32((DWORD64*)test2, (DWORD64*)test);
	for (int i = 0; i < 32; i += 3)
	{
		DWORD out;
		Encode((DWORD64)((uintptr_t)test2 + i), &out);
		for (int k = 0; k < 4; k++)
		{
			printf("%c", (BYTE)(out + k));
		}
	}
}