# dependency from syscall -> __cancel() -> __libc_sigaction()
set(signal_src 
    sigaction.c
    block.c
    x86_64/restore.s
)
add_library(signal ${signal_src})
