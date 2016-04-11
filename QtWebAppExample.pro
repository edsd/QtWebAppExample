TEMPLATE = subdirs

SUBDIRS += \
    QtWebApp \
    common

CONFIG += ordered

common.files = common/html-static/*
CONFIG(debug, debug|release) {
    common.path = $$OUT_PWD/../HttpServiceDebug/html-static
} else {
    common.path = $$OUT_PWD/../HttpService/html-static
}

INSTALLS += common
