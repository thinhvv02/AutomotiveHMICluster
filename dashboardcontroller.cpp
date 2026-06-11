#include "dashboardcontroller.h"

DashboardController::DashboardController(QObject *parent)
    : QObject(parent),
    m_speed(0), m_tacho(0), m_speedAngle(-120.0), m_tachoAngle(-120.0),
    m_turnLeft(false), m_turnRight(false), m_hiBeam(false),
    m_fogLight(false), m_dimLight(false) // Đã đồng bộ tên biến mới
{
    // Khởi tạo kết nối USB ngay khi chạy app
    serial = new QSerialPort(this);
    connectToESP();
    connect(serial, &QSerialPort::readyRead, this, &DashboardController::readSerialData);
}

// Hàm tự động quét và mở cổng kết nối với ESP32
void DashboardController::connectToESP() {
    for (const QSerialPortInfo &info : QSerialPortInfo::availablePorts()) {
        serial->setPortName(info.portName());
        serial->setBaudRate(QSerialPort::Baud115200);

        if (serial->open(QIODevice::ReadWrite)) {
            qDebug() << "Đã kết nối ESP32 tại cổng:" << info.portName();

            serial->write("pause\n");
            serial->flush();
            return;
        }
    }
    qDebug() << "LỖI: Không tìm thấy mạch ESP32. Hãy kiểm tra cáp USB!";
}

// Xử lý dữ liệu JSON truyền từ ESP32 lên màn hình QT
void DashboardController::readSerialData() {
    while (serial->canReadLine()) {
        QByteArray data = serial->readLine().trimmed();

        QJsonParseError error;
        QJsonDocument doc = QJsonDocument::fromJson(data, &error);

        if (error.error == QJsonParseError::NoError && doc.isObject()) {
            QJsonObject obj = doc.object();

            if (obj.contains("speed")) {
                setSpeed(obj["speed"].toInt());
            }
            if (obj.contains("tacho")) {
                setTacho(obj["tacho"].toInt());
            }
            if (obj.contains("turnLeft")) {
                setTurnLeft(obj["turnLeft"].toBool());
            }
            if (obj.contains("turnRight")) {
                setTurnRight(obj["turnRight"].toBool());
            }
            if (obj.contains("hiBeam")) {
                setHiBeam(obj["hiBeam"].toBool());
            }
            if (obj.contains("fogLight")) {
                setFogLight(obj["fogLight"].toBool());
            }
            if (obj.contains("dimLight")) {
                setDimLight(obj["dimLight"].toBool());
            }
        }
    }
}

// Hàm đẩy lệnh điều khiển nhạc từ QML xuống ESP32
void DashboardController::sendCommandToESP(QString cmd) {
    if (serial && serial->isOpen()) {
        QString commandToSend = cmd + "\n";
        serial->write(commandToSend.toUtf8());
        serial->flush();
        qDebug() << "Đã gửi lệnh xuống ESP32:" << cmd;
    } else {
        qDebug() << "LỖI: Cổng USB chưa mở, không thể gửi lệnh!";
    }
}

// SLIDERS VÀ LOGIC TÍNH GÓC KIM ĐỒNG HỒ
int DashboardController::speed() const { return m_speed; }
double DashboardController::speedAngle() const { return m_speedAngle; }

void DashboardController::setSpeed(int speed) {
    if (m_speed == speed) return;
    m_speed = speed;

    // Tốc độ max là 200. Góc quay từ -120 đến 120
    m_speedAngle = -120.0 + (static_cast<double>(m_speed) / 200.0) * 240.0;

    emit speedChanged();
    emit speedAngleChanged();
}

int DashboardController::tacho() const { return m_tacho; }
double DashboardController::tachoAngle() const { return m_tachoAngle; }

void DashboardController::setTacho(int tacho) {
    if (m_tacho == tacho) return;
    m_tacho = tacho;

    // Vòng tua max là 8. Góc quay từ -120 đến 120
    m_tachoAngle = -120.0 + (static_cast<double>(m_tacho) / 8.0) * 240.0;

    emit tachoChanged();
    emit tachoAngleChanged();
}

// BUTTONS VÀ LOGIC KHÓA LẪN (MUTUAL EXCLUSIVITY) ĐÃ ĐỒNG BỘ
bool DashboardController::turnLeft() const { return m_turnLeft; }
void DashboardController::setTurnLeft(bool turnLeft) {
    if (m_turnLeft == turnLeft) return;
    m_turnLeft = turnLeft;
    emit turnLeftChanged();

    // Khóa lẫn Xi-nhan: Bật trái thì ép phải tắt
    if (m_turnLeft) {
        setTurnRight(false);
    }
}

bool DashboardController::turnRight() const { return m_turnRight; }
void DashboardController::setTurnRight(bool turnRight) {
    if (m_turnRight == turnRight) return;
    m_turnRight = turnRight;
    emit turnRightChanged();

    // Khóa lẫn Xi-nhan: Bật phải thì ép trái tắt
    if (m_turnRight) {
        setTurnLeft(false);
    }
}

bool DashboardController::hiBeam() const { return m_hiBeam; }
void DashboardController::setHiBeam(bool hiBeam) {
    if (m_hiBeam == hiBeam) return;
    m_hiBeam = hiBeam;
    emit hiBeamChanged();

    // Khóa lẫn Cụm Đèn: Bật đèn Xa (Pha) thì tắt đèn Gần (Cốt) và Phá sương
    if (m_hiBeam) {
        setFogLight(false);
        setDimLight(false);
    }
}

bool DashboardController::fogLight() const { return m_fogLight; }
void DashboardController::setFogLight(bool fogLight) {
    if (m_fogLight == fogLight) return;
    m_fogLight = fogLight;
    emit fogLightChanged();

    if (m_fogLight) {
        setHiBeam(false);
        setDimLight(false);
    }
}

bool DashboardController::dimLight() const { return m_dimLight; }
void DashboardController::setDimLight(bool dimLight) {
    if (m_dimLight == dimLight) return;
    m_dimLight = dimLight;
    emit dimLightChanged();

    // Khóa lẫn Cụm Đèn: Bật đèn Gần (Cốt) thì tắt đèn Xa (Pha) và Phá sương
    if (m_dimLight) {
        setHiBeam(false);
        setFogLight(false);
    }
}