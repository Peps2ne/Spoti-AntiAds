#include <windows.h>
#include <psapi.h>
#include <iostream>
#include <string>

void SimulatePlayPause() {
    keybd_event(VK_MEDIA_PLAY_PAUSE, 0, 0, 0);
    keybd_event(VK_MEDIA_PLAY_PAUSE, 0, KEYEVENTF_KEYUP, 0);
}

int main() {
    
    MessageBoxW(NULL, L"Looking For Ads", L"Started!", MB_OK);
    std::wcout << L"App Started!\n";

    while (true) {
        
        HWND hwnd = FindWindowW(NULL, L"Advertisement");

        if (hwnd != NULL) {
            std::wcout << L"Ads Founded!, Exiting...\n";

            
            PostMessage(hwnd, WM_CLOSE, 0, 0);

           
            ShellExecuteW(NULL, L"open", L"C:\\Users\\e\\AppData\\Roaming\\Spotify\\Spotify.exe", NULL, NULL, SW_SHOWNORMAL);

            Sleep(2000);
            
            SimulatePlayPause();

            std::wcout << L"Restarting App...\n";

            return main();

        }

        
        MEMORYSTATUSEX memInfo;
        memInfo.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&memInfo);

        DWORDLONG totalPhysMem = memInfo.ullTotalPhys;
        DWORDLONG physMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;

        int ramYuzde = (int)((physMemUsed * 100) / totalPhysMem);

        if (ramYuzde >= 90) {
            std::cout << "Waiting RAM %90\n";
            Sleep(1500);
            continue;
        }

        Sleep(1000);
    }

    return 0;
}


