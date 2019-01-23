set(thread_src 
    __errno_location.c
    strerror.c
)
add_library(errno STATIC ${thread_src})
