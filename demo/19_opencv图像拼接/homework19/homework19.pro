TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

INCLUDEPATH += D:/QtEngineer/opencv_3.4.2_Qt/include
LIBS += D:/QtEngineer/opencv_3.4.2_Qt/x86/bin/libopencv_*.dll   \
        D:/QtEngineer/opencv_3.4.2_Qt/x86/bin/opencv_ffmpeg342.dll
