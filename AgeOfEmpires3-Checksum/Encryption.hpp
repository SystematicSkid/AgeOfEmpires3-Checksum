#pragma once
#include <windows.h>
#include <cstdint>
#include "./defs.hpp"

namespace Encryption
{
	static uint8_t hash_table[] =
	{
		0xC6, 0x9D, 0xC1, 0x0F, 0xCC, 0xA1, 0x0C, 0x24,
		0x6F, 0x2C, 0xE9, 0x2D, 0xAA, 0x84, 0x74, 0x4A,  0xDC, 0xA9, 0xB0, 0x5C ,0xDA ,0x88 ,0xF9 ,0x76,
		0x52, 0x51, 0x3E, 0x98, 0x6D, 0xC6, 0x31, 0xA8,  0xC8, 0x27, 0x03, 0xB0 ,0xC7 ,0x7F ,0x59 ,0xBF,
		0xF3, 0x0B, 0xE0, 0xC6, 0x47, 0x91, 0xA7, 0xD5,  0x51, 0x63, 0xCA, 0x06 ,0x67 ,0x29 ,0x29 ,0x14,
		0x85, 0x0A, 0xB7, 0x27, 0x38, 0x21, 0x1B, 0x2E,  0xFC, 0x6D, 0x2C, 0x4D ,0x13 ,0x0D ,0x38 ,0x53,
		0x54, 0x73, 0x0A, 0x65, 0xBB, 0x0A, 0x6A, 0x76,  0x2E, 0xC9, 0xC2, 0x81 ,0x85 ,0x2C ,0x72 ,0x92,
		0xA1, 0xE8, 0xBF, 0xA2, 0x4B, 0x66, 0x1A, 0xA8,  0x70, 0x8B, 0x4B, 0xC2 ,0xA3 ,0x51 ,0x6C ,0xC7,
		0x19, 0xE8, 0x92, 0xD1, 0x24, 0x06, 0x99, 0xD6,  0x85, 0x35, 0x0E, 0xF4 ,0x70 ,0xA0 ,0x6A ,0x10,
		0x16, 0xC1, 0xA4, 0x19, 0x08, 0x6C, 0x37, 0x1E,  0x4C, 0x77, 0x48, 0x27 ,0xB5 ,0xBC ,0xB0 ,0x34,
		0xB3, 0x0C, 0x1C, 0x39, 0x4A, 0xAA, 0xD8, 0x4E,  0x4F, 0xCA, 0x9C, 0x5B ,0xF3 ,0x6F ,0x2E ,0x68,
		0xEE, 0x82, 0x8F, 0x74, 0x6F, 0x63, 0xA5, 0x78,  0x14, 0x78, 0xC8, 0x84 ,0x08 ,0x02 ,0xC7 ,0x8C,
		0xFA, 0xFF, 0xBE, 0x90, 0xEB, 0x6C, 0x50, 0xA4,  0xF7, 0xA3, 0xF9, 0xBE ,0xF2 ,0x78 ,0x71 ,0xC6,
	};

	VOID ByteRoll32Encrypt(DWORD64* byte_array, unsigned int* data, signed __int64 unknown1)
	{
		/*
			Note: You are out of your mind if you think I am
					going to rewrite this function myself. ^_^
		*/

		int v3; // er10
		signed __int64 v4; // rax
		int v5; // er9
		int v6; // ebx
		int v7; // esi
		int v8; // er12
		int v9; // er14
		int v10; // er15
		int v11; // er11
		unsigned int v12; // er8
		unsigned int* v13; // ST10_8
		int v14; // edx
		int v15; // er11
		int v16; // edi
		unsigned int v17; // er8
		int v18; // edx
		int v19; // er10
		int v20; // er13
		unsigned int v21; // er8
		int v22; // edx
		int v23; // ebx
		int v24; // eax
		int v25; // er15
		unsigned int v26; // er8
		int v27; // edx
		int v28; // er9
		int v29; // er12
		unsigned int v30; // er8
		int v31; // edx
		int v32; // edi
		int v33; // er14
		unsigned int v34; // er8
		int v35; // edx
		int v36; // er13
		int v37; // eax
		int v38; // esi
		unsigned int v39; // er8
		int v40; // edx
		int v41; // ecx
		int v42; // er15
		int v43; // er10
		unsigned int v44; // er8
		int v45; // edx
		int v46; // er12
		int v47; // er11
		unsigned int v48; // er8
		int v49; // edx
		int v50; // er14
		int v51; // eax
		int v52; // ebx
		unsigned int v53; // er8
		int v54; // edx
		int v55; // ecx
		int v56; // esi
		int v57; // edi
		unsigned int v58; // er8
		int v59; // er8
		int v60; // er10
		int v61; // eax
		int v62; // er8
		int v63; // er11
		int v64; // ecx
		int v65; // er12
		int v66; // ecx
		int v67; // er8
		int v68; // ebx
		int v69; // ST00_4
		int v70; // er13
		int v71; // er8
		int v72; // ecx
		int v73; // ebx
		int v74; // ecx
		int v75; // er8
		int v76; // eax
		int v77; // ecx
		int v78; // esi
		int v79; // er10
		int v80; // er8
		int v81; // ecx
		int v82; // er12
		int v83; // ecx
		char v84; // r8
		int v85; // er11
		unsigned int* v86; // rdi
		int* v87; // r14
		int* v88; // r15
		int v89; // er8
		int v90; // er10
		int v91; // er11
		int v92; // er13
		int v93; // ST00_4
		int* v94; // rbx
		int* v95; // rsi
		int v96; // er8
		int v97; // ST04_4
		int* v98; // r10
		unsigned int v99; // er8
		int v100; // ST0C_4
		int v101; // eax
		int* v102; // r11
		unsigned int v103; // edx
		unsigned int v104; // er8
		int v105; // ST08_4
		int v106; // er12
		int* v107; // r10
		unsigned int v108; // edx
		unsigned int v109; // er8
		__int64 v110; // rcx
		unsigned int v111; // edx
		int v112; // er8
		int v113; // er14
		int* v114; // r10
		unsigned int v115; // er8
		unsigned int v116; // edx
		int v117; // er8
		unsigned int v118; // er8
		unsigned int v119; // edx
		int v120; // er8
		bool v121; // zf
		int v122; // edx
		int v123; // er15
		int v124; // er10
		int v125; // er11
		int v126; // er8
		int v127; // edi
		int v128; // ST20_4
		int v129; // edx
		int v130; // [rsp+0h] [rbp-69h]
		int v131; // [rsp+4h] [rbp-65h]
		int v132; // [rsp+8h] [rbp-61h]
		int v133; // [rsp+Ch] [rbp-5Dh]
		unsigned int* v134; // [rsp+10h] [rbp-59h]
		signed __int64 v135; // [rsp+18h] [rbp-51h]
		int v136; // [rsp+20h] [rbp-49h]
		_DWORD* v137; // [rsp+28h] [rbp-41h]
		signed __int64 v138; // [rsp+30h] [rbp-39h]
		__int64 v139; // [rsp+38h] [rbp-31h]
		signed __int64 v140; // [rsp+40h] [rbp-29h]
		unsigned int v141; // [rsp+50h] [rbp-19h]
		unsigned int v142; // [rsp+54h] [rbp-15h]
		unsigned int v143; // [rsp+58h] [rbp-11h]
		unsigned int v144; // [rsp+5Ch] [rbp-Dh]
		unsigned int v145; // [rsp+60h] [rbp-9h]
		unsigned int v146; // [rsp+64h] [rbp-5h]
		unsigned int v147; // [rsp+68h] [rbp-1h]
		unsigned int v148; // [rsp+6Ch] [rbp+3h]
		unsigned int v149; // [rsp+70h] [rbp+7h]
		unsigned int v150; // [rsp+74h] [rbp+Bh]
		unsigned int v151; // [rsp+78h] [rbp+Fh]
		unsigned int v152; // [rsp+7Ch] [rbp+13h]
		unsigned int v153; // [rsp+80h] [rbp+17h]
		unsigned int v154; // [rsp+84h] [rbp+1Bh]
		unsigned int v155; // [rsp+88h] [rbp+1Fh]
		unsigned int v156; // [rsp+8Ch] [rbp+23h]

		if (unknown1)
		{
			v3 = *(_DWORD*)(byte_array + 8);
			v4 = unknown1;
			v5 = *(_DWORD*)(byte_array + 12);
			v6 = *(_DWORD*)(byte_array + 24);
			v7 = *(_DWORD*)byte_array;
			v8 = *(_DWORD*)(byte_array + 20);
			v9 = *(_DWORD*)(byte_array + 16);
			v10 = *(_DWORD*)(byte_array + 4);
			v11 = *(_DWORD*)(byte_array + 28);
			v139 = (long long)byte_array;
			do
			{
				v140 = v4 - 1;
				v12 = _byteswap_ulong(*data);
				v13 = data + 1;
				v141 = v12;
				v14 = v12 + (__ROR__(v9, 6) ^ __ROL__(v9, 7) ^ __ROR__(v9, 11)) + (v8 & v9 ^ v6 & ~v9) + v11 + 0x428A2F98;
				v15 = v5 + v14;
				v16 = v14 + (__ROL__(v7, 10) ^ __ROR__(v7, 13) ^ __ROR__(v7, 2)) + (v10 & v7 ^ (v10 ^ v7) & v3);
				v17 = _byteswap_ulong(*v13);
				++v13;
				v142 = v17;
				v18 = v6 + (v15 & v9 ^ v8 & ~v15) + v17 + 1899447441 + (__ROR__(v15, 6) ^ __ROL__(v15, 7) ^ __ROR__(v15, 11));
				v19 = v18 + v3;
				v20 = v18 + (__ROL__(v16, 10) ^ __ROR__(v16, 13) ^ __ROR__(v16, 2)) + (v10 & v7 ^ v16 & (v10 ^ v7));
				v21 = _byteswap_ulong(*v13);
				v143 = v21;
				v22 = v8 + (v19 & v15 ^ v9 & ~v19) + v21 - 1245643825 + (__ROR__(v19, 6) ^ __ROL__(v19, 7) ^ __ROR__(v19, 11));
				v23 = v10 + v22;
				v24 = v22 + (__ROR__(v20, 2) ^ __ROL__(v20, 10) ^ __ROR__(v20, 13));
				v25 = v24 + (v20 & v7 ^ v16 & (v20 ^ v7));
				v26 = _byteswap_ulong(v13[1]);
				v13 += 2;
				v144 = v26;
				v27 = v9 + (v23 & v19 ^ v15 & ~v23) + v26 - 373957723 + (__ROR__(v23, 6) ^ __ROL__(v23, 7) ^ __ROR__(v23, 11));
				v28 = v7 + v27;
				v29 = v27
					+ (__ROR__(v24 + (v20 & v7 ^ v16 & (v20 ^ v7)), 2) ^ __ROL__(v24 + (v20 & v7 ^ v16 & (v20 ^ v7)), 10) ^ __ROR__(v24 + (v20 & v7 ^ v16 & (v20 ^ v7)), 13))
					+ (v25 & v20 ^ v16 & (v25 ^ v20));
				v30 = _byteswap_ulong(*v13);
				++v13;
				v145 = v30;
				v31 = v30
					+ (__ROR__(v7 + v27, 6) ^ __ROL__(v7 + v27, 7) ^ __ROR__(v7 + v27, 11))
					+ (v28 & v23 ^ v19 & ~v28)
					+ v15
					+ 961987163;
				v32 = v31 + v16;
				v33 = v31 + (__ROR__(v29, 2) ^ __ROL__(v29, 10) ^ __ROR__(v29, 13)) + (v29 & v25 ^ v20 & (v29 ^ v25));
				v34 = _byteswap_ulong(*v13);
				v146 = v34;
				v35 = v19
					+ (v28 & v32 ^ v23 & ~v32)
					+ 1508970993
					+ v34
					+ (__ROR__(v32, 6) ^ __ROL__(v32, 7) ^ __ROR__(v32, 11));
				v36 = v35 + v20;
				v37 = v35 + (__ROR__(v33, 2) ^ __ROL__(v33, 10) ^ __ROR__(v33, 13));
				v38 = v37 + (v33 & v29 ^ v25 & (v33 ^ v29));
				v39 = _byteswap_ulong(v13[1]);
				v147 = v39;
				v40 = v23
					+ (v36 & v32 ^ v28 & ~v36)
					- 1841331548
					+ v39
					+ (__ROR__(v36, 6) ^ __ROL__(v36, 7) ^ __ROR__(v36, 11));
				v41 = __ROL__(v37 + (v33 & v29 ^ v25 & (v33 ^ v29)), 10) ^ __ROR__(v38, 13);
				v42 = v40 + v25;
				v43 = v40 + (__ROR__(v38, 2) ^ v41) + (v38 & v33 ^ v29 & (v38 ^ v33));
				v44 = _byteswap_ulong(v13[2]);
				v13 += 3;
				v148 = v44;
				v45 = v28
					+ (v42 & v36 ^ v32 & ~v42)
					- 1424204075
					+ v44
					+ (__ROR__(v42, 6) ^ __ROL__(v42, 7) ^ __ROR__(v42, 11));
				v46 = v45 + v29;
				v47 = v45 + (__ROR__(v43, 2) ^ __ROL__(v43, 10) ^ __ROR__(v43, 13)) + (v43 & v38 ^ v33 & (v43 ^ v38));
				v48 = _byteswap_ulong(*v13);
				++v13;
				v149 = v48;
				v49 = v32 + (v46 & v42 ^ v36 & ~v46) - 670586216 + v48 + (__ROR__(v46, 6) ^ __ROL__(v46, 7) ^ __ROR__(v46, 11));
				v50 = v49 + v33;
				v51 = v49 + (__ROL__(v47, 10) ^ __ROR__(v47, 13) ^ __ROR__(v47, 2));
				v52 = v51 + (v47 & v43 ^ v38 & (v47 ^ v43));
				v53 = _byteswap_ulong(*v13);
				++v13;
				v150 = v53;
				v54 = v36 + (v50 & v46 ^ v42 & ~v50) + 310598401 + v53 + (__ROR__(v50, 6) ^ __ROL__(v50, 7) ^ __ROR__(v50, 11));
				v55 = __ROL__(v51 + (v47 & v43 ^ v38 & (v47 ^ v43)), 10) ^ __ROR__(v52, 13);
				v56 = v54 + v38;
				v57 = v54 + (v55 ^ __ROR__(v52, 2)) + (v47 & v43 ^ v52 & (v47 ^ v43));
				v58 = _byteswap_ulong(*v13);
				++v13;
				v151 = v58;
				v59 = v42 + (v56 & v50 ^ v46 & ~v56) + 607225278 + (__ROR__(v56, 6) ^ __ROL__(v56, 7) ^ __ROR__(v56, 11)) + v58;
				v60 = v59 + v43;
				v61 = v59 + (__ROR__(v57, 2) ^ __ROL__(v57, 10) ^ __ROR__(v57, 13)) + (v47 & v57 ^ v52 & (v47 ^ v57));
				v152 = _byteswap_ulong(*v13);
				v62 = v152
					+ (__ROR__(v60, 6) ^ __ROL__(v60, 7) ^ __ROR__(v60, 11))
					+ (v60 & v56 ^ v50 & ~v60)
					+ v46
					+ 1426881987;
				v63 = v62 + v47;
				v64 = v62 + (__ROR__(v61, 2) ^ __ROL__(v61, 10) ^ __ROR__(v61, 13));
				v65 = v64 + (v61 & v57 ^ v52 & (v61 ^ v57));
				v153 = _byteswap_ulong(v13[1]);
				v66 = __ROL__(v64 + (v61 & v57 ^ v52 & (v61 ^ v57)), 10);
				v67 = v50
					+ (v63 & v60 ^ v56 & ~v63)
					+ 1925078388
					+ v153
					+ (__ROR__(v63, 6) ^ __ROL__(v63, 7) ^ __ROR__(v63, 11));
				v68 = v67 + v52;
				v69 = v68;
				v70 = v67 + (__ROR__(v65, 2) ^ v66 ^ __ROR__(v65, 13)) + (v65 & v61 ^ v57 & (v65 ^ v61));
				v154 = _byteswap_ulong(v13[2]);
				v71 = v56
					+ (v63 & v68 ^ v60 & ~v68)
					- 2132889090
					+ v154
					+ (__ROR__(v68, 6) ^ __ROL__(v68, 7) ^ __ROR__(v68, 11));
				v131 = v71 + v57;
				v72 = v71 + (__ROR__(v70, 2) ^ __ROL__(v70, 10) ^ __ROR__(v70, 13));
				v73 = v72 + (v70 & v65 ^ v61 & (v70 ^ v65));
				v136 = v72 + (v70 & v65 ^ v61 & (v70 ^ v65));
				v155 = _byteswap_ulong(v13[3]);
				v74 = __ROL__(v72 + (v70 & v65 ^ v61 & (v70 ^ v65)), 10);
				v75 = v60
					+ (v131 & v69 ^ v63 & ~v131)
					- 1680079193
					+ v155
					+ (__ROR__(v131, 6) ^ __ROL__(v131, 7) ^ __ROR__(v131, 11));
				v76 = v75 + v61;
				v77 = v75 + (__ROR__(v73, 2) ^ v74 ^ __ROR__(v73, 13));
				v78 = v77 + (v73 & v70 ^ v65 & (v73 ^ v70));
				v133 = v78;
				v156 = _byteswap_ulong(v13[4]);
				v134 = v13 + 5;
				v79 = v69;
				v138 = 6i64;
				v80 = v156
					+ (__ROR__(v76, 6) ^ __ROL__(v76, 7) ^ __ROR__(v76, 11))
					+ (v76 & v131 ^ v69 & ~v76)
					+ v63
					- 1046744716;
				v81 = __ROL__(v77 + (v73 & v70 ^ v65 & (v73 ^ v70)), 10);
				v82 = v80 + v65;
				v83 = v80 + (__ROR__(v78, 2) ^ v81 ^ __ROR__(v78, 13));
				v84 = 25;
				v85 = v83 + (v78 & v73 ^ v70 & (v78 ^ v73));
				v135 = 25i64;
				v132 = v83 + (v78 & v73 ^ v70 & (v78 ^ v73));
				v137 = (uint32_t*)&hash_table;
				while (1)
				{
					v86 = &v141 + ((v84 - 8) & 0xF);
					v87 = (int*)(&v141 + ((v84 + 5) & 0xF));
					v88 = (int*)(&v141 + ((v84 + 7) & 0xF));
					*v88 += *(&v141 + (v135 & 0xF))
						+ ((*v86 >> 3) ^ __ROR__(*v86, 7) ^ __ROL__(*v86, 14))
						+ (((unsigned int)*v87 >> 10) ^ __ROL__(*v87, 13) ^ __ROL__(*v87, 15));
					v89 = v79
						+ *v88
						+ *(v137 - 2) // what teh fuck??
						+ (v82 & v76 ^ v131 & ~v82)
						+ (__ROR__(v82, 6) ^ __ROL__(v82, 7) ^ __ROR__(v82, 11));
					v90 = v85 ^ v78;
					v91 = v132 & v78;
					v92 = v89 + v70;
					v93 = v89 + (__ROL__(v132, 10) ^ __ROR__(v132, 13) ^ __ROR__(v132, 2)) + (v132 & v78 ^ v73 & v90);
					v94 = (int*)(&v141 + (((_BYTE)v135 - 7) & 0xF));
					v95 = (int*)(&v141 + (((_BYTE)v135 + 6) & 0xF));
					*v86 += *(&v141 + (((_BYTE)v135 + 1) & 0xF))
						+ (((unsigned int)*v94 >> 3) ^ __ROR__(*v94, 7) ^ __ROL__(*v94, 14))
						+ (((unsigned int)*v95 >> 10) ^ __ROL__(*v95, 13) ^ __ROL__(*v95, 15));
					v96 = v131
						+ *v86
						+ *(v137 - 1) // maybe this will crash.... T_T
						+ (v92 & v82 ^ v76 & ~v92)
						+ (__ROR__(v92, 6) ^ __ROL__(v92, 7) ^ __ROR__(v92, 11));
					LODWORD(v86) = v96 + v136;
					v97 = v96 + (__ROL__(v93, 10) ^ __ROR__(v93, 13) ^ __ROR__(v93, 2)) + (v91 ^ v93 & v90);
					v98 = (int*)(&v141 + (((_BYTE)v135 - 6) & 0xF));
					*v94 += *(&v141 + (((_BYTE)v135 + 2) & 0xF))
						+ (((unsigned int)*v98 >> 3) ^ __ROR__(*v98, 7) ^ __ROL__(*v98, 14))
						+ (((unsigned int)*v88 >> 10) ^ __ROL__(*v88, 13) ^ __ROL__(*v88, 15));
					v99 = v76
						+ *v94
						+ *v137
						+ ((unsigned int)v86 & v92 ^ v82 & ~(_DWORD)v86)
						+ (__ROR__((_DWORD)v86, 6) ^ __ROL__((_DWORD)v86, 7) ^ __ROR__((_DWORD)v86, 11));
					v100 = v99 + v133;
					v101 = v99 + (__ROR__(v97, 2) ^ __ROL__(v97, 10) ^ __ROR__(v97, 13)) + (v132 & v97 ^ v93 & (v132 ^ v97));
					v102 = (int*)(&v141 + (((_BYTE)v135 - 5) & 0xF));
					v103 = *(&v141 + (((_BYTE)v135 + 8) & 0xF));
					*v98 += *(&v141 + (((_BYTE)v135 + 3) & 0xF))
						+ (((unsigned int)*v102 >> 3) ^ __ROR__(*v102, 7) ^ __ROL__(*v102, 14))
						+ ((v103 >> 10) ^ __ROL__(*(&v141 + (((_BYTE)v135 + 8) & 0xF)), 13) ^ __ROL__(v103, 15));
					v104 = v82
						+ *v98
						+ v137[1]
						+ (v100 & (unsigned int)v86 ^ v92 & ~v100)
						+ (__ROR__(v100, 6) ^ __ROL__(v100, 7) ^ __ROR__(v100, 11));
					v105 = v104 + v132;
					v106 = v104 + (__ROR__(v101, 2) ^ __ROL__(v101, 10) ^ __ROR__(v101, 13)) + (v101 & v97 ^ v93 & (v101 ^ v97));
					v107 = (int*)(&v141 + (((_BYTE)v135 - 4) & 0xF));
					v108 = *(&v141 + (((_BYTE)v135 - 7) & 0xF));
					*v102 += *(&v141 + (((_BYTE)v135 + 4) & 0xF))
						+ (((unsigned int)*v107 >> 3) ^ __ROR__(*v107, 7) ^ __ROL__(*v107, 14))
						+ ((v108 >> 10) ^ __ROL__(*(&v141 + (((_BYTE)v135 - 7) & 0xF)), 13) ^ __ROL__(v108, 15));
					v109 = v92
						+ *v102
						+ v137[2]
						+ (v105 & v100 ^ (unsigned int)v86 & ~v105)
						+ (__ROR__(v105, 6) ^ __ROL__(v105, 7) ^ __ROR__(v105, 11));
					v130 = v109 + v93;
					v70 = v109 + (__ROR__(v106, 2) ^ __ROL__(v106, 10) ^ __ROR__(v106, 13)) + (v106 & v101 ^ v97 & (v106 ^ v101));
					v110 = ((_BYTE)v135 - 3) & 0xF;
					v111 = *(&v141 + (((_BYTE)v135 - 6) & 0xF));
					*v107 += *v87
						+ ((*(&v141 + v110) >> 3) ^ __ROR__(*(&v141 + v110), 7) ^ __ROL__(*(&v141 + v110), 14))
						+ ((v111 >> 10) ^ __ROL__(*(&v141 + (((_BYTE)v135 - 6) & 0xF)), 13) ^ __ROL__(v111, 15));
					v112 = (_DWORD)v86
						+ *v107
						+ v137[3]
						+ (v105 & v130 ^ v100 & ~v130)
						+ (__ROR__(v130, 6) ^ __ROL__(v130, 7) ^ __ROR__(v130, 11));
					v131 = v112 + v97;
					v113 = v112 + (__ROR__(v70, 2) ^ __ROL__(v70, 10) ^ __ROR__(v70, 13)) + (v70 & v106 ^ v101 & (v70 ^ v106));
					v136 = v112 + (__ROR__(v70, 2) ^ __ROL__(v70, 10) ^ __ROR__(v70, 13)) + (v70 & v106 ^ v101 & (v70 ^ v106));
					v114 = (int*)(&v141 + (((_BYTE)v135 - 2) & 0xF));
					v115 = *(&v141 + (((_BYTE)v135 - 2) & 0xF));
					v116 = *(&v141 + (((_BYTE)v135 - 5) & 0xF));
					*(&v141 + v110) += *v95
						+ ((v115 >> 3) ^ __ROR__(*(&v141 + (((_BYTE)v135 - 2) & 0xF)), 7) ^ __ROL__(v115, 14))
						+ ((v116 >> 10) ^ __ROL__(*(&v141 + (((_BYTE)v135 - 5) & 0xF)), 13) ^ __ROL__(v116, 15));
					v117 = v100
						+ *(&v141 + v110)
						+ v137[4]
						+ (v131 & v130 ^ v105 & ~v131)
						+ (__ROR__(v131, 6) ^ __ROL__(v131, 7) ^ __ROR__(v131, 11));
					v76 = v117 + v101;
					v78 = v117 + (__ROR__(v113, 2) ^ __ROL__(v113, 10) ^ __ROR__(v113, 13)) + (v113 & v70 ^ v106 & (v113 ^ v70));
					v133 = v117 + (__ROR__(v113, 2) ^ __ROL__(v113, 10) ^ __ROR__(v113, 13)) + (v113 & v70 ^ v106 & (v113 ^ v70));
					v118 = *(&v141 + (((_BYTE)v135 - 1) & 0xF));
					v119 = *(&v141 + (((_BYTE)v135 - 4) & 0xF));
					*v114 += *v88
						+ ((v118 >> 3) ^ __ROR__(*(&v141 + (((_BYTE)v135 - 1) & 0xF)), 7) ^ __ROL__(v118, 14))
						+ ((v119 >> 10) ^ __ROL__(*(&v141 + (((_BYTE)v135 - 4) & 0xF)), 13) ^ __ROL__(v119, 15));
					v135 += 8i64;
					v120 = v105
						+ *v114
						+ v137[5]
						+ (v76 & v131 ^ v130 & ~v76)
						+ (__ROR__(v76, 6) ^ __ROL__(v76, 7) ^ __ROR__(v76, 11));
					v82 = v120 + v106;
					v137 += 8;
					LODWORD(v110) = v120 + (__ROR__(v78, 2) ^ __ROL__(v78, 10) ^ __ROR__(v78, 13));
					v84 = v135;
					v85 = v110 + (v78 & v113 ^ v70 & (v78 ^ v113));
					v121 = v138-- == 1;
					v132 = v110 + (v78 & v113 ^ v70 & (v78 ^ v113));
					if (v121)
						break;
					v79 = v130;
					v73 = v113;
				}
				v122 = *(_DWORD*)(v139 + 4);
				v123 = *(_DWORD*)v139 + v132;
				v124 = *(_DWORD*)(v139 + 16);
				v125 = *(_DWORD*)(v139 + 20);
				v126 = *(_DWORD*)(v139 + 8);
				v5 = v70 + *(_DWORD*)(v139 + 12);
				v127 = *(_DWORD*)(v139 + 28);
				v6 = v131 + *(_DWORD*)(v139 + 24);
				v128 = v123;
				*(_DWORD*)v139 = v123;
				v10 = v122 + v78;
				v7 = v128;
				v129 = v126 + v113;
				v9 = v124 + v82;
				*(_DWORD*)(v139 + 8) = v129;
				v8 = v125 + v76;
				*(_DWORD*)(v139 + 4) = v10;
				v3 = v129;
				v4 = v140;
				v11 = v127 + v130;
				data = v134;
				*(_DWORD*)(v139 + 12) = v5;
				*(_DWORD*)(v139 + 16) = v9;
				*(_DWORD*)(v139 + 20) = v8;
				*(_DWORD*)(v139 + 24) = v6;
				*(_DWORD*)(v139 + 28) = v127 + v130;
			} while (v140);
		}
	}
}