QT       += core gui
QT += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CompteView.cpp \
    EvolutionSolde.cpp \
    GraphPage.cpp \
    RowView.cpp \
    TransactionManager.cpp \
    TransactionModel.cpp \
    main.cpp

HEADERS += \
    CompteView.h \
    EvolutionSolde.h \
    GraphPage.h \
    RowView.h \
    TransactionManager.h \
    TransactionModel.h

FORMS +=

TRANSLATIONS += \
    Application_fr_FR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
