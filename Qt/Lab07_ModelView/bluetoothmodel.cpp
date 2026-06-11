#include "bluetoothmodel.h"

BluetoothModel::BluetoothModel(QObject *parent) : QAbstractListModel(parent) {}

void BluetoothModel::addDevice(const QString &mac, const QString &name) {
    if(mac.isEmpty() || name.isEmpty()) return;

    int rowIndex = static_cast<int>(m_devices.size());

    beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    m_devices.append({mac, name});
    endInsertRows();
}

int BluetoothModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return static_cast<int>(m_devices.size());
}

QVariant BluetoothModel::data(const QModelIndex &index, int role) const {
    if (index.row() < 0 || index.row() >= m_devices.size()) return QVariant();
    const BluetoothDevice &device = m_devices[index.row()];
    if (role == MacRole) return device.mac;
    else if (role == NameRole) return device.name;
    return QVariant();
}

QHash<int, QByteArray> BluetoothModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[MacRole] = "macAddress";
    roles[NameRole] = "deviceName";
    return roles;
}