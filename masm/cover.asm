            includelib  kernel32.lib
            ExitProcess proto
            .code
main        proc
            xor rcx, rcx
            mov rcx, 10
            call ExitProcess
main        endp
            end