#include <windows.h>

void SetRegistry()
{
	HKEY hKey;
	LONG lResult;
	const WCHAR command[66] = TEXT("\"C:\\Program Files (x86)\\Bit Safer\\Bit Safer.exe\"");

	lResult = RegOpenKeyEx(
		HKEY_CLASSES_ROOT,
		(LPCWSTR)L"Directory\\Background\\shell\\Bit Safer",
		(REGSAM)0,
		KEY_WRITE,
		&hKey
	);

	if (lResult != ERROR_SUCCESS)
	{
		lResult = RegCreateKeyEx(
			HKEY_CLASSES_ROOT,
			(LPCWSTR)L"Directory\\Background\\shell\\Bit Safer",
			0,
			NULL,
			0,
			KEY_WRITE,
			NULL,
			&hKey,
			NULL
		);

		if (lResult != ERROR_SUCCESS)
		{
			RegCloseKey(hKey);
			return;
		}

		lResult = RegCreateKeyEx(
			HKEY_CLASSES_ROOT,
			(LPCWSTR)L"Directory\\Background\\shell\\Bit Safer\\command",
			0,
			NULL,
			0,
			KEY_WRITE,
			NULL,
			&hKey,
			NULL
		);

		if (lResult != ERROR_SUCCESS)
		{
			RegCloseKey(hKey);
			return;
		}

		lResult = RegOpenKeyEx(
			HKEY_CLASSES_ROOT,
			(LPCWSTR)L"Directory\\Background\\shell\\Bit Safer\\command",
			(REGSAM)0,
			KEY_WRITE,
			&hKey
		);

		if (lResult != ERROR_SUCCESS)
		{
			RegCloseKey(hKey);
			return;
		}

		lResult = RegSetValueEx(
			hKey,
			L"",
			0,
			REG_SZ,
			(LPBYTE)command,
			sizeof(WCHAR) * wcslen(command)
		);

		if (lResult != ERROR_SUCCESS)
		{
			RegCloseKey(hKey);
			return;
		}
	}
	RegCloseKey(hKey);
}

int main()
{
	SetRegistry();
}