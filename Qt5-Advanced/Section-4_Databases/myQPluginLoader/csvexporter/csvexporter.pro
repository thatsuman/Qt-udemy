QT       = core
CONFIG   += c++17 plugin
TEMPLATE  = lib

TARGET = csvexporter

SOURCES += csvexporter.cpp
HEADERS += csvexporter.h ../exporterinterface.h ../contact.h

DESTDIR = ../plugins