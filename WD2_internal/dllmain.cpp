#include <windows.h>
#include <iostream>
#include "FeatureManager.h"
#include "HookManager.h"
#include "Dependencies/minhook/include/MinHook.h"

#define DEBUG false


void exitProgram(HMODULE instance)
{
    if (DEBUG)
    {
        fclose(stderr);
        fclose(stdout);
        FreeConsole();
    }

    HookManager& hookManager = HookManager::getInstance();

    hookManager.disableAll();

    MH_DisableHook(MH_ALL_HOOKS);
    MH_Uninitialize();

    FreeLibraryAndExitThread(instance, EXIT_SUCCESS);
}

void MainThread(HMODULE instance)
{
    if (DEBUG)
    {
        AllocConsole();

        FILE* fDummy;

        freopen_s(&fDummy, "CONOUT$", "w", stderr);
        freopen_s(&fDummy, "CONOUT$", "w", stdout);
    }

    if (MH_Initialize() != MH_OK)
    {
        exitProgram(instance);
    }

    FeatureManager& featureManager = FeatureManager::getInstance();

    FeaturesMap features = featureManager.getFeatures();

    HookManager& hookManager = HookManager::getInstance();

    hookManager.enableAll();

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

    exitProgram(instance);
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
