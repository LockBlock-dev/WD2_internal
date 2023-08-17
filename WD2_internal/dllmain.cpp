#include <windows.h>
#include <iostream>
#include "FeatureManager.h"

#define DEBUG true


void MainThread(HMODULE instance)
{
    if (DEBUG)
    {
        AllocConsole();

        FILE* fDummy;

        freopen_s(&fDummy, "CONOUT$", "w", stderr);
        freopen_s(&fDummy, "CONOUT$", "w", stdout);
    }

    FeatureManager& featureManager = FeatureManager::getInstance();

    FeaturesMap features = featureManager.getFeatures();

    while (TRUE)
    {
        if (GetAsyncKeyState(VK_INSERT) & 0x01)
        {
            // Toggle GUI
        }

        if (GetAsyncKeyState(VK_END) & 0x01)
        {
            // Hide GUI
            break;
        }

        for (auto const& [name, feature] : features)
        {
            feature->update();
        }

        Sleep(10);
    }

    if (DEBUG)
    {
        fclose(stderr);
        fclose(stdout);
        FreeConsole();
    }
    FreeLibraryAndExitThread(instance, EXIT_SUCCESS);
}

BOOL APIENTRY DllMain(
    HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hModule);

        CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(&MainThread), hModule, 0, 0);
    }

    return TRUE;
}
