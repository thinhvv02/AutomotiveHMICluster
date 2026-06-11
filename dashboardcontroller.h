#ifndef DASHBOARDCONTROLLER_H
#define DASHBOARDCONTROLLER_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QJsonDocument>
#include <QJsonObject>

class DashboardController : public QObject
{
    Q_OBJECT

    //  Biến cho Slider (Giá trị thô)
    Q_PROPERTY(int speed READ speed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(int tacho READ tacho WRITE setTacho NOTIFY tachoChanged)

    //  Biến Góc quay để QML đọc (Kết quả sau khi C++ tính toán)
    Q_PROPERTY(double speedAngle READ speedAngle NOTIFY speedAngleChanged)
    Q_PROPERTY(double tachoAngle READ tachoAngle NOTIFY tachoAngleChanged)

    //  Biến cho Buttons
    Q_PROPERTY(bool turnLeft READ turnLeft WRITE setTurnLeft NOTIFY turnLeftChanged)
    Q_PROPERTY(bool turnRight READ turnRight WRITE setTurnRight NOTIFY turnRightChanged)
    Q_PROPERTY(bool hiBeam READ hiBeam WRITE setHiBeam NOTIFY hiBeamChanged)
    Q_PROPERTY(bool fogLight READ fogLight WRITE setFogLight NOTIFY fogLightChanged)
    Q_PROPERTY(bool dimLight READ dimLight WRITE setDimLight NOTIFY dimLightChanged)

public:
    explicit DashboardController(QObject *parent = nullptr);

    int speed() const;
    int tacho() const;
    double speedAngle() const;
    double tachoAngle() const;
    bool turnLeft() const;
    bool turnRight() const;
    bool hiBeam() const;
    bool fogLight() const;
    bool dimLight() const;

public slots:
    void setSpeed(int speed);
    void setTacho(int tacho);
    void setTurnLeft(bool turnLeft);
    void setTurnRight(bool turnRight);
    void setHiBeam(bool hiBeam);

    void setFogLight(bool fogLight);
    void setDimLight(bool dimLight);
    void sendCommandToESP(QString cmd);

private slots:
    void readSerialData();

signals:
    void speedChanged();
    void tachoChanged();
    void speedAngleChanged();
    void tachoAngleChanged();

    void turnLeftChanged();
    void turnRightChanged();
    void hiBeamChanged();
    void fogLightChanged();
    void dimLightChanged();

private:
    int m_speed;
    int m_tacho;
    double m_speedAngle;
    double m_tachoAngle;

    bool m_turnLeft;
    bool m_turnRight;
    bool m_hiBeam;

    bool m_fogLight;
    bool m_dimLight;

    QSerialPort *serial;   //  Đối tượng quản lý cáp USB
    void connectToESP();   // Hàm khởi tạo kết nối
};

#endif