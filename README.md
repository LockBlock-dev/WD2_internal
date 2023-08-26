# WD2_internal

An open-source internal (DLL) cheat for [Watch_Dogs 2](https://www.ubisoft.com/en-us/game/watch-dogs/watch-dogs-2).

# ⚠️ Disclaimer ⚠️

The cheat is not in a usable state as of now and has no GUI or menu.

This cheat was made for and tested on the cracked version of Watch_Dogs 2 `1.17` by CPY.  
It might work on a legitimate game version if you disable EAC by passing `-eac_launcher` as a launch option (also disables multiplayer).

## Features

- God mode
- Infinite botnets
- Lock your balance at 1B$
- No reload
- (Broken) Lock your Research Points to 100

## How to use

- Download the cheat from the [`Releases`](../../releases) or [build it](#compiling-from-source) yourself.
- Start the game.
- Open your favorite DLL injector.
- Inject `WD2_internal.dll` into the `WatchDogs2.exe` process.

- Release the DLL by pressing the <kbd>END</kbd> key.

## Compiling from source

- Download the project or clone it with `--recurse-submodules` option.
- Open [`WD2_internal.sln`](./WD2_internal.sln) in Microsoft Visual Studio.
- Make sure that your build configuration is `Release | x64` and build the solution.
- You can find `WD2_internal.dll` inside `./x64/Release`.

## Credits

[MinHook](https://github.com/TsudaKageyu/minhook) library  

## Copyright

See the [license](/LICENSE).
