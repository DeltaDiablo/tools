# TDL message builder/interpretor

This is a negotiator still under development for processing X Message Types with TCP/IP protocols only
this project requires raylib to run for the front end, 
download raylib from link (TBD) and install locally on your machine in the default locations so the makefile can register correctly

## Using jreaplib.a from a C application

The project now exposes a C ABI wrapper in `milstd3011/jreaplib_c.h` so non-C++ applications can call the decoder safely.

### Build the library

From the tools root:

```powershell
C:/raylib/w64devkit/bin/mingw32-make.exe -B RAYLIB_PATH=C:/raylib/raylib PROJECT_NAME=JReapCHeads OBJS=*.cpp BUILD_MODE=DEBUG
```

This produces `jreaplib.a`.

### C usage example

```c
#include <stdio.h>
#include "milstd3011/jreaplib_c.h"

int main(void)
{
	const char* csv = "...";
	const char* out = jreap_decode_application_message_csv(csv, 0);
	if (out == NULL) return 1;

	puts(out);
	jreap_free_string(out);
	return 0;
}
```

### Link notes

- Compile your caller as C (for example: `gcc -std=c11`).
- Link with `jreaplib.a` and the C++ runtime (`-lstdc++`).
- The returned string from `jreap_decode_application_message_csv` is heap allocated by the library and must be released with `jreap_free_string`.

### Troubleshooting

- `undefined reference` to C++ symbols (for example `std::__cxx11::basic_string`): add `-lstdc++` at link time.
- `undefined reference to jreap_decode_application_message_csv`: ensure `jreaplib.a` is on the linker command and appears after your object files.
- Crash or heap corruption after decoding: free only with `jreap_free_string`; do not call `free()` directly from the caller.
- `jreap_decode_application_message_csv` returns `NULL`: treat as allocation failure and handle as an error path.

## X1.0.0 quick test

Use this byte line to exercise the X1.0.0 decoder path (AH.0 + Message Type 1 + 17-byte payload):

```text
49,1,0,17,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
```

Expected output includes:

- `X1.0.0 decode`
- `JRE Source Track Number: ...`
- `J-Series Message Sequence Number: ...`
- `Relay Flag: ...`
- `Acknowledgement Request Flag: ...`
- `Data Age: ...`
- `Number of J-Words: ...`
- `JREAP J-Series Message Word 1..5: ...`
