TEMPLATE = subdirs

SUBDIRS += \
    myapp \
    mylib

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/mylib/release/ -lmylib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/mylib/debug/ -lmylib
else:unix: LIBS += -L$$OUT_PWD/mylib/ -lmylib

INCLUDEPATH += $$PWD/mylib
DEPENDPATH += $$PWD/mylib
