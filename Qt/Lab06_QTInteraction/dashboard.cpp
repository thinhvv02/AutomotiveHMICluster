#include "dashboard.h"

Dashboard::Dashboard(QObject *parent) : QObject(parent)
{
    m_tachoAngle = -120.0f;
    m_speedAngle = -118.0f;
}

float Dashboard::tachoAngle() const { return m_tachoAngle; }
float Dashboard::speedAngle() const { return m_speedAngle; }
bool Dashboard::turnLeftOn() const { return m_turnLeftOn; }
bool Dashboard::turnRightOn() const { return m_turnRightOn; }
bool Dashboard::hiBeamOn() const { return m_hiBeamOn; }
bool Dashboard::engineOilOn() const { return m_engineOilOn; }
bool Dashboard::batteryOn() const { return m_batteryOn; }

void Dashboard::setTachoAngle(float angle) {
    if (m_tachoAngle == angle) return;
    m_tachoAngle = angle;
    emit tachoAngleChanged();
}

void Dashboard::setSpeedAngle(float angle) {
    if (m_speedAngle == angle) return;
    m_speedAngle = angle;
    emit speedAngleChanged();
}

void Dashboard::updateTachoFromSlider(float percent) {
    float angle = -120.0f + (percent * 240.0f);
    setTachoAngle(angle);
}

void Dashboard::updateSpeedFromSlider(float percent) {
    float angle = -118.0f + (percent * 236.0f);
    setSpeedAngle(angle);
}

void Dashboard::updateButtonState(QString btnName, bool isOn) {
    if (btnName == "Turn-Left") {
        m_turnLeftOn = isOn;
        emit turnLeftOnChanged();
    } else if (btnName == "Turn-Right") {
        m_turnRightOn = isOn;
        emit turnRightOnChanged();
    } else if (btnName == "Hi-Beam") {
        m_hiBeamOn = isOn;
        emit hiBeamOnChanged();
    } else if (btnName == "Engine Oil") {
        m_engineOilOn = isOn;
        emit engineOilOnChanged();
    } else if (btnName == "Battery") {
        m_batteryOn = isOn;
        emit batteryOnChanged();
    }
}