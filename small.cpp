#include <windows.h>

extern "C" 
unsigned int strlen(const char* f)
{
    INT i = 0;
    while (*f++) i++;
    return i;
}
void printf(char* fmtstr, ...)
{
    DWORD dwRet;
    CHAR buffer[256];
    va_list v1;
    va_start(v1, fmtstr);
    wvsprintf(buffer, fmtstr, v1);
    WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), buffer, strlen(buffer), &dwRet, 0);
    va_end(v1);
}

bool HKLMKeyExists(LPCWSTR regSubKey, LPCWSTR regValue)
{
    LPCTSTR valueBuf[255];
    DWORD cbData = 255;

    LONG rc = RegGetValueW(
        HKEY_LOCAL_MACHINE,
        regSubKey,
        regValue,
        RRF_RT_REG_SZ,
        nullptr,
        valueBuf,
        &cbData
    );

    return rc == ERROR_SUCCESS;
}

VOID main()
{
    LPCWSTR regSubKey = L"SOFTWARE\\WOW6432Node\\Company Name\\Application Name\\";
    bool rc = HKLMKeyExists(regSubKey, L"SomeValue");
    printf("%d", rc);
}
