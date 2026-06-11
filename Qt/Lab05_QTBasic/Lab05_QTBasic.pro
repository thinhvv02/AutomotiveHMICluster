# Khai báo các module hỗ trợ QML
QT += core gui qml quick

TEMPLATE = app
TARGET = Lab05_QTBasic

CONFIG += c++17

# File mã nguồn
SOURCES += \
    main.cpp

# File tài nguyên
RESOURCES += \
    images.qrc

# Hiển thị file QML lên cây thư mục của Qt Creator (không bắt buộc để build, nhưng dễ nhìn)
DISTFILES += \
    Main.qml