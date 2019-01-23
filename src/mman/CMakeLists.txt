# /locale calls __munmap(). /time call __mmap().
set(mman_src munmap.c mmap.c)
add_library(mman ${mman_src})