//Avoid problems with the compiler
#define HAVE_STDINT_H

#include "SDK/plugin.h"

#define NULL						0
typedef void(*logprintf_t)(const char* format, ...);

logprintf_t
logprintf
;

void
**ppPluginData
;

extern void
*pAMXFunctions
;

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData)
{
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];
	logprintf("** quicksort was successfully loaded! ** ");
	return 1;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
}


PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *amx)
{
	return AMX_ERR_NONE;
}

//  quickSort
//
//  This public-domain C implementation by Darel Rex Finley.
//
//  * This function assumes it is called with valid parameters.
//
//  * Example calls:
//    quickSort(&myArray[0],5); // sorts elements 0, 1, 2, 3, and 4
//    quickSort(&myArray[3],5); // sorts elements 3, 4, 5, 6, and 7
//	Available at: http://alienryderflex.com/quicksort/

bool quickSort_asc(int *arr, int elements)
{
#define  MAX_LEVELS  1000
	int  piv, beg[MAX_LEVELS], end[MAX_LEVELS], i = 0, L, R;
	beg[0] = 0; end[0] = elements;
	while (i >= 0)
	{
		L = beg[i]; R = end[i] - 1;
		if (L < R)
		{
			piv = arr[L];
			if (i == MAX_LEVELS - 1) return 0;
			while (L < R)
			{
				while (arr[R] >= piv && L<R) R--; if (L<R) arr[L++] = arr[R];
				while (arr[L] <= piv && L<R) L++; if (L<R) arr[R--] = arr[L];
			}
			arr[L] = piv; beg[i + 1] = L + 1; end[i + 1] = end[i]; end[i++] = L;
		}
		else
		{
			i--;
		}
	}
	return 1;
}
bool quickSort_desc(int *arr, int elements)
{
#define  MAX_LEVELS  1000
	int  piv, beg[MAX_LEVELS], end[MAX_LEVELS], i = 0, L, R;
	beg[0] = 0; end[0] = elements;
	while (i >= 0)
	{
		L = beg[i]; R = end[i] - 1;
		if (L < R)
		{
			piv = arr[L];
			if (i == MAX_LEVELS - 1) return 0;
			while (L < R)
			{
				while (arr[R] <= piv && L<R) R--; if (L<R) arr[L++] = arr[R]; //just swap > for < for descending order
				while (arr[L] >= piv && L<R) L++; if (L<R) arr[R--] = arr[L]; //just swap < for > for descending order
			}
			arr[L] = piv; beg[i + 1] = L + 1; end[i + 1] = end[i]; end[i++] = L;
		}
		else
		{
			i--;
		}
	}
	return 1;
}

//native quicksort_asc(array[], elements = sizeof(array));
static cell AMX_NATIVE_CALL n_quicksort_asc(AMX *amx, cell *params)
{
	cell* addr = NULL;
	amx_GetAddr(amx, params[1], &addr);
	return quickSort_asc(static_cast<int*>(addr), static_cast<int>(params[2]));
}
//native quicksort_desc(array[], elements = sizeof(array));
static cell AMX_NATIVE_CALL n_quicksort_desc(AMX *amx, cell *params)
{
	cell* addr = NULL;
	amx_GetAddr(amx, params[1], &addr);
	return quickSort_desc(static_cast<int*>(addr), static_cast<int>(params[2]));
}

AMX_NATIVE_INFO projectNatives[] =
{
	{ "quicksort_asc", n_quicksort_asc },
	{ "quicksort_desc", n_quicksort_desc },
	{ NULL, NULL }
};
PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX *amx)
{
	return amx_Register(amx, projectNatives, -1);
}