#-------------------------------------------------
#
# Project created by QtCreator 2011-05-15T04:34:07
#
#-------------------------------------------------

QT       += core gui

TARGET = saod
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    forms.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    android/AndroidManifest.xml \
    android/res/drawable-hdpi/icon.png \
    android/res/drawable-ldpi/icon.png \
    android/res/drawable-mdpi/icon.png \
    android/res/values/libs.xml \
    android/res/values/strings.xml \
    android/src/eu/licentia/necessitas/industrius/QtActivity.java \
    android/src/eu/licentia/necessitas/industrius/QtApplication.java \
    android/src/eu/licentia/necessitas/industrius/QtLayout.java \
    android/src/eu/licentia/necessitas/industrius/QtSurface.java \
    android/src/eu/licentia/necessitas/ministro/IMinistro.aidl \
    android/src/eu/licentia/necessitas/ministro/IMinistroCallback.aidl \
    android/src/eu/licentia/necessitas/mobile/QtAndroidContacts.java \
    android/src/eu/licentia/necessitas/mobile/QtCamera.java \
    android/src/eu/licentia/necessitas/mobile/QtFeedback.java \
    android/src/eu/licentia/necessitas/mobile/QtLocation.java \
    android/src/eu/licentia/necessitas/mobile/QtMediaPlayer.java \
    android/src/eu/licentia/necessitas/mobile/QtSensors.java \
    android/src/eu/licentia/necessitas/mobile/QtSystemInfo.java
