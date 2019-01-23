# __lock() is used all over so we need that
# vmlock() is used by /mman
set(thread_src 
    __lock.c 
    vmlock.c 
    __wait.c
    __syscall_cp.c
    pthread_cancel.c
    x86_64/syscall_cp.s
)
add_library(thread STATIC ${thread_src})
