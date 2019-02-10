cmake_minimum_required(VERSION 3.1)
project(PNG_MAPPER)

set(DEPS
        png-lite/pnglite.h
        png-lite/pnglite.c
        zlib/adler32.c
        zlib/compress.c
        zlib/crc32.c
        zlib/crc32.h
        zlib/deflate.c
        zlib/deflate.h
        zlib/gzio.c
        zlib/infback.c
        zlib/inffast.c
        zlib/inffast.h
        zlib/inffixed.h
        zlib/inflate.c
        zlib/inflate.h
        zlib/inftrees.c
        zlib/inftrees.h
        zlib/trees.c
        zlib/trees.h
        zlib/uncompr.c
        zlib/zconf.h
        zlib/zlib.h
        zlib/zutil.c
        zlib/zutil.h
        )

set(SOURCES
        src/main.cpp
        src/Io.h
        src/Io.cpp
        src/Png.h
        src/Png.cpp
        src/Vector2.h
        src/Vector2.cpp
        src/Mapper.cpp src/Mapper.h)


add_executable(png-mapper ${SOURCES} ${DEPS})

target_include_directories(png-mapper PRIVATE png-lite zlib)

target_compile_features(png-mapper PUBLIC cxx_std_17)

target_link_libraries(png-mapper stdc++fs)
