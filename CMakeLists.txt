cmake_minimum_required(VERSION 3.12)
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
        png-mapper.cpp)

add_executable(png-mapper ${SOURCES} ${DEPS})

target_compile_features(png-mapper PUBLIC cxx_std_17)
