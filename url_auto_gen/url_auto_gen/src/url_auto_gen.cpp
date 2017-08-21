// url_auto_gen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "url_auto_gen.h"

#include <string>
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

void gen_url(const CStringA& url_pattern, const char* no)
{
    CStringA strUrl;

    const int cnt = std::stoi(no);
    for (int i = 0; i < cnt; ++i)
    {
        strUrl.Format(url_pattern, i);
        std::cout << strUrl << std::endl;
    }
}

int main(int argc, char *argv[])
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // initialize MFC and print and error on failure
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: change error code to suit your needs
            wprintf(L"Fatal Error: MFC initialization failed\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: code your application's behavior here.
            if (argc == 3)
            {
                gen_url(argv[1], argv[2]);
            }
            else
            {
                std::cout << "usage eg.:" << std::endl;
                const std::string url("http://t.c/%2d.7z");
                const int no(2);
                std::cout << argv[0] << " " << url << " " << no << endl;
                std::cout << endl << "output:" << std::endl;
                gen_url("http://t.c/%02d.zip", "2");
            }
        }
    }
    else
    {
        // TODO: change error code to suit your needs
        wprintf(L"Fatal Error: GetModuleHandle failed\n");
        nRetCode = 1;
    }

    return nRetCode;
}
