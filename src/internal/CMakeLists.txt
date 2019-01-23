set(internal_src
    floatscan.c
    intscan.c
    libc.c
    procfdname.c
    shgetc.c
    syscall.c
    syscall_ret.c
    vdso.c
    version.c
    x86_64/syscall.s
)
add_library(internal STATIC ${internal_src})
