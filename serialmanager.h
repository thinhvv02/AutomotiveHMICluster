#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

class SerialManager : public QObject
{
    Q_OBJECT
public:
    explicit SerialManager(QObject *parent = nullptr);

    // Hàm public để nơi khác có thể gọi khi cần gửi lệnh (ví dụ: phát nhạc)
    void sendData(const QByteArray &data);

signals:
    // Tín hiệu này sẽ phát ra ngay khi nhận được dòng dữ liệu từ ESP32
    void dataReceived(const QByteArray &data);

private slots:
    // Hàm nội bộ tự động chạy khi có tín hiệu điện qua cáp
    void readData();

private:
    QSerialPort *serial;
    void connectToDevice(); // Hàm tự động dò tìm ESP32
};

#endif