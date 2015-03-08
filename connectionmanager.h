#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <QObject>
#include <QBluetoothDeviceInfo>
#include <QStringList>
#include "iConnection.h"
class QBluetoothSocket;
class QBluetoothDeviceDiscoveryAgent;

class ConnectionManager : public iConnection
{
    Q_OBJECT
public:
    explicit ConnectionManager(QObject *parent = 0);
    ~ConnectionManager();
    bool isConnected();


public slots:
    void scanForDevices(QString filter_type);
    void stopScanning();
    void sendMessage(QByteArray message);
    void connectToDevice(QString device_name, QString addr, QString pin = "");

protected:
    void connectToDeviceDiscover();
    void connectToTargetSocket();
    void deviceDiscovered(QBluetoothDeviceInfo info);
    QStringList serviceEnumToStrList(QBluetoothDeviceInfo::ServiceClasses service);
private:

    QBluetoothDeviceInfo*                mTargetDevice;
    QBluetoothSocket*                    mTargetSocket;
    QBluetoothDeviceDiscoveryAgent*      mDeviceDiscover;

};

#endif // CONNECTIONMANAGER_H
