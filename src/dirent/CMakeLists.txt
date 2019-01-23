set(dirent_src
    alphasort.c
    closedir.c
    dirfd.c
    fdopendir.c
    opendir.c
    readdir_r.c
    readdir.c
    rewinddir.c
    scandir.c
    seekdir.c
    telldir.c
    versionsort.c
)
add_library(dirent STATIC ${dirent_src})
