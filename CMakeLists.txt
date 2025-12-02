cmake_minimum_required(VERSION 3.10)
project(mpg123 C ASM)

enable_language(ASM)

set(MPG123_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/libmpg123)

# Archivos fuente principales - solo 16-bit output para Android
set(LIBMPG123_SOURCES
    ${MPG123_SRC_DIR}/parse.c
    ${MPG123_SRC_DIR}/frame.c
    ${MPG123_SRC_DIR}/format.c
    ${MPG123_SRC_DIR}/dct64.c
    ${MPG123_SRC_DIR}/equalizer.c
    ${MPG123_SRC_DIR}/id3.c
    ${MPG123_SRC_DIR}/optimize.c
    ${MPG123_SRC_DIR}/readers.c
    ${MPG123_SRC_DIR}/tabinit.c
    ${MPG123_SRC_DIR}/libmpg123.c
    ${MPG123_SRC_DIR}/index.c
    ${MPG123_SRC_DIR}/layer1.c
    ${MPG123_SRC_DIR}/layer2.c
    ${MPG123_SRC_DIR}/layer3.c
    ${MPG123_SRC_DIR}/dither.c
    ${MPG123_SRC_DIR}/feature.c
    ${MPG123_SRC_DIR}/synth.c
    ${MPG123_SRC_DIR}/stringbuf.c
    ${MPG123_SRC_DIR}/lfs_wrap.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/compat/compat.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/compat/compat_str.c
)

# Para ARM64 Android - añadir NEON64 ASM y getcpuflags
if(ANDROID AND CMAKE_ANDROID_ARCH_ABI STREQUAL "arm64-v8a")
    list(APPEND LIBMPG123_SOURCES
        ${MPG123_SRC_DIR}/getcpuflags_arm.c
        # NEON64 ASM files
        ${MPG123_SRC_DIR}/check_neon.S
        ${MPG123_SRC_DIR}/dct36_neon64.S
        ${MPG123_SRC_DIR}/dct64_neon64.S
        ${MPG123_SRC_DIR}/dct64_neon64_float.S
        ${MPG123_SRC_DIR}/synth_neon64.S
        ${MPG123_SRC_DIR}/synth_neon64_accurate.S
        ${MPG123_SRC_DIR}/synth_neon64_float.S
        ${MPG123_SRC_DIR}/synth_neon64_s32.S
        ${MPG123_SRC_DIR}/synth_stereo_neon64.S
        ${MPG123_SRC_DIR}/synth_stereo_neon64_accurate.S
        ${MPG123_SRC_DIR}/synth_stereo_neon64_float.S
        ${MPG123_SRC_DIR}/synth_stereo_neon64_s32.S
    )
endif()

add_library(libmpg123 SHARED ${LIBMPG123_SOURCES})

# Renombrar el output a mpg123 (sin el prefijo lib duplicado)
set_target_properties(libmpg123 PROPERTIES OUTPUT_NAME "mpg123")

target_include_directories(libmpg123 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/libmpg123
)

# Configuración para Android
if(ANDROID)
    target_compile_definitions(libmpg123 PRIVATE
        OPT_MULTI
        OPT_GENERIC
        OPT_GENERIC_DITHER
        OPT_NEON64
        REAL_IS_FLOAT
        ACCURATE_ROUNDING
        HAVE_STDLIB_H
        HAVE_STRERROR
        HAVE_SYS_TYPES_H
        HAVE_SYS_STAT_H
        HAVE_DIRENT_H
        HAVE_FCNTL_H
        HAVE_ERRNO_H
        HAVE_INTTYPES_H
        HAVE_STDINT_H
        HAVE_UNISTD_H
        HAVE_STRING_H
        SIZEOF_OFF_T=8
        _FILE_OFFSET_BITS=64
        LFS_LARGEFILE_64
        # Disable features not needed
        NO_8BIT
        NO_32BIT
        NO_REAL
        NO_NTOM
        NO_ICY
    )
else()
    target_compile_definitions(libmpg123 PRIVATE
        OPT_GENERIC
        REAL_IS_FLOAT
    )
endif()

target_compile_options(libmpg123 PRIVATE -w)
