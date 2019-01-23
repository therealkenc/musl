# __strchrnul() is used by /locale
set(string_src 
    strchrnul.c
)
add_library(string ${string_src})
