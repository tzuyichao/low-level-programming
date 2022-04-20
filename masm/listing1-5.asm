; listing1-5.asm
            option casemap:none
            .data
fmtStr      byte        'Hello, World!', 10, 0

            .code
            externdef printf:proc

            public asmFunc
asmFunc     proc
            sub         rsp, 56
            lea         rcx, fmtStr
            call        printf
            add         rsp, 56
            ret
asmFunc     endp
            end