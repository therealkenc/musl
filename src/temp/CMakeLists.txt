set(temp_src
    mkdtemp.c
    mkostemp.c
    mkostemps.c
    mkstemp.c
    mkstemps.c
    mktemp.c
    __randname.c
)
add_library(temp STATIC ${temp_src})
