## Compile hello world

Using "x64 Native Tools Command Prompt for VS 2022"

```
ml64 programShell.asm /link /subsystem:console /entry:main
```

## Compile hybrid

Using "x64 Native Tools Command Prompt for VS 2022"

```
ml64 /c listing1-3.asm

cl listing1-2.cc listing1-3.obj
```
