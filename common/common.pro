QT += core network
QT -= gui

TARGET = common
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp \
    webconfigurator.cpp \
    webconfiguratorpage.cpp

HEADERS += \
    webconfigurator.h \
    webconfiguratorpage.h \
    httpsettings.hpp

RESOURCES += \
    resources.qrc

CONFIG(debug, debug|release) {
    DESTDIR = $$OUT_PWD/../../HttpServiceDebug
} else {
    DESTDIR = $$OUT_PWD/../../HttpService
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QtWebApp/release/ -lQtWebApp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QtWebApp/debug/ -lQtWebApp
else:unix: LIBS += -L$$OUT_PWD/../QtWebApp/ -lQtWebApp

INCLUDEPATH += $$PWD/../QtWebApp/httpserver
DEPENDPATH += $$PWD/../QtWebApp/httpserver
INCLUDEPATH += $$PWD/../QtWebApp/templateengine
DEPENDPATH += $$PWD/../QtWebApp/templateengine
INCLUDEPATH += $$PWD/../QtWebApp/qtservice
DEPENDPATH += $$PWD/../QtWebApp/qtservice

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../QtWebApp/release/libQtWebApp.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../QtWebApp/debug/libQtWebApp.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../QtWebApp/release/QtWebApp.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../QtWebApp/debug/QtWebApp.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../QtWebApp/libQtWebApp.a

DISTFILES += \
    html-static/style.css \
    html-static/favicon-32x32.png \
    html-static/favicon.png
