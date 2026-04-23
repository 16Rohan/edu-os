# EDU-OS: Educational OS Simulator

EDU-OS is a user-space educational simulator that mimics the feel of an operating system starting up and providing a stateful interactive shell. Written entirely in modular C, it provides a simulated boot sequence, kernel initialization phase, an interactive command loop, and interactive mocked subsystems like a Process Manager and an In-Memory File System.

## Project Structure

* `src/` - Contains all C implementation files.
  * `main.c`: The entry point orchestrating boot, kernel, and shell sequences.
  * `sysinfo.c`, `process.c`, `filesystem.c`: Subsystem logic modules.
* `include/` - Contains all C header files defining the project's interfaces and struct architectures (like `SystemState`).
* `Makefile` - The automation tool to compile the executable safely natively on Windows environments.

## Prior Requirements

To compile and run EDU-OS natively, you will need a C compiler environment natively setup:

* **GCC Compiler**: Ensure `gcc` is installed. For Windows, Mingw-w64 or MSYS2 are firmly recommended. 
* **Make**: The `make` build-automation utility is required (often bundled as `mingw32-make` or available via MSYS2).
* **Terminal**: PowerShell, Command Prompt, or any modern terminal emulator.

*Verify your installations in your terminal:*
```sh
gcc --version
make --version
```

## How to Build

Simply run the `make` utility at the root of the project directory.

```powershell
# Clears old build files and compiles locally
make clean
make
```

If successful, an executable uniquely named `edu-os.exe` will be effortlessly generated in your project root!

## How to Run

After optimal compilation, launch the executable right from your shell:

```powershell
.\edu-os.exe
```

### Supported Commands
Once inside the `edu-os>` shell, you will have access to 15 different built-in commands natively routed to their subsystems:
- **General**: `help`, `echo`, `clear`, `exit`, `quit`
- **Processes**: `ps`, `run <name>`, `kill <pid>` 
- **Filesystem**: `ls`, `touch <name>`, `cat <name>`, `write <name> <content>`
- **System**: `uptime`, `uname`, `whoami`, `version`, `history`

Type `help` directly in the simulator for more context mapping!
