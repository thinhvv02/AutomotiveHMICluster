#ifndef BLUETOOTHMODEL_H
#define BLUETOOTHMODEL_H

#include <QAbstractListModel>
#include <QVector>

struct BluetoothDevice {
    QString mac;
    QString name;
};

class BluetoothModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum DeviceRoles {
        MacRole = Qt::UserRole + 1,
        NameRole
    };

    BluetoothModel(QObject *parent = nullptr);

    Q_INVOKABLE void addDevice(const QString &mac, const QString &name);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QVector<BluetoothDevice> m_devices;
};

#endif