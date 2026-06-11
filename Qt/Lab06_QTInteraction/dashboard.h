#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QObject>
#include <QDebug>

class Dashboard : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float tachoAngle READ tachoAngle WRITE setTachoAngle NOTIFY tachoAngleChanged)
    Q_PROPERTY(float speedAngle READ speedAngle WRITE setSpeedAngle NOTIFY speedAngleChanged)

    Q_PROPERTY(bool turnLeftOn READ turnLeftOn NOTIFY turnLeftOnChanged)
    Q_PROPERTY(bool turnRightOn READ turnRightOn NOTIFY turnRightOnChanged)
    Q_PROPERTY(bool hiBeamOn READ hiBeamOn NOTIFY hiBeamOnChanged)
    Q_PROPERTY(bool engineOilOn READ engineOilOn NOTIFY engineOilOnChanged)
    Q_PROPERTY(bool batteryOn READ batteryOn NOTIFY batteryOnChanged)

public:
    explicit Dashboard(QObject *parent = nullptr);

    float tachoAngle() const;
    float speedAngle() const;

    bool turnLeftOn() const;
    bool turnRightOn() const;
    bool hiBeamOn() const;
    bool engineOilOn() const;
    bool batteryOn() const;

    // Các hàm nhận dữ liệu từ QML
    Q_INVOKABLE void updateTachoFromSlider(float percent);
    Q_INVOKABLE void updateSpeedFromSlider(float percent);
    Q_INVOKABLE void updateButtonState(QString btnName, bool isOn);

public slots:
    void setTachoAngle(float angle);
    void setSpeedAngle(float angle);

signals:
    void tachoAngleChanged();
    void speedAngleChanged();

    void turnLeftOnChanged();
    void turnRightOnChanged();
    void hiBeamOnChanged();
    void engineOilOnChanged();
    void batteryOnChanged();

private:
    float m_tachoAngle;
    float m_speedAngle;

    bool m_turnLeftOn = false;
    bool m_turnRightOn = false;
    bool m_hiBeamOn = false;
    bool m_engineOilOn = false;
    bool m_batteryOn = false;
};

#endif