#include "serialmanager.h"
#include <QDebug>

SerialManager::SerialManager(QObject *parent) : QObject(parent)
{
    serial = new QSerialPort(this);
    connectToDevice();

    // Hễ có dữ liệu tới cổng USB là gọi hàm readData
    connect(serial, &QSerialPort::readyRead, this, &SerialManager::readData);
}

void SerialManager::connectToDevice()
{
    bool deviceFound = false;
    QString portName;

    // Quét tìm thiết bị đang cắm
    for (const QSerialPortInfo &info : QSerialPortInfo::availablePorts()) {
        portName = info.portName();
        deviceFound = true;
        break;
    }

    if (deviceFound) {
        serial->setPortName(portName);
        serial->setBaudRate(QSerialPort::Baud115200);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);

        if (serial->open(QIODevice::ReadWrite)) {
            qDebug() << "[SerialManager] Đã kết nối thành công tại cổng:" << portName;
        } else {
            qDebug() << "[SerialManager] LỖI: Không thể mở cổng" << portName;
        }
    } else {
        qDebug() << "[SerialManager] LỖI: Không tìm thấy mạch ESP32!";
    }
}

void SerialManager::readData()
{
    while (serial->canReadLine()) {
        QByteArray rawData = serial->readLine().trimmed();

        // Không xử lý JSON ở đây, chỉ việc "bắn" dữ liệu thô ra ngoài cho class khác lo
        emit dataReceived(rawData);
    }
}

void SerialManager::sendData(const QByteArray &data)
{
    if (serial->isOpen() && serial->isWritable()) {
        serial->write(data);
        serial->write("\n"); // Thêm ký tự ngắt dòng để ESP32 dễ đọc
        serial->flush();
    }
}