# Some dependency complexity...
# /stdio uses /locale, which uses __map_file(), which lives here in /time. 
# Also /temp uses __clock_gettime().
set(time_src __map_file.c clock_gettime.c)
add_library(time STATIC ${time_src})
