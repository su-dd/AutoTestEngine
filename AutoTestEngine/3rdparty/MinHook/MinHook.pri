
INCLUDEPATH += $$PWD/minhook/include


SOURCES += \
    $$PWD/minhook/src/buffer.c \
    $$PWD/minhook/src/hook.c \
    $$PWD/minhook/src/trampoline.c \
    $$PWD/minhook/src/hde/hde32.c \
    $$PWD/minhook/src/hde/hde64.c

HEADERS += \
    $$PWD/minhook/include/MinHook.h \
    $$PWD/minhook/src/buffer.h \
    $$PWD/minhook/src/trampoline.h \
    $$PWD/minhook/src/hde/hde32.h \
    $$PWD/minhook/src/hde/hde64.h \
    $$PWD/minhook/src/hde/pstdint.h \
    $$PWD/minhook/src/hde/table32.h \
    $$PWD/minhook/src/hde/table64.h
