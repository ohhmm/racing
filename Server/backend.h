#pragma once

#include <QObject>
#include "serverStuff.h"

class Backend : public QObject
{
    Q_OBJECT
public:
    using QObject::QObject;
    explicit Backend(QObject *parent);

signals:
    void smbConnected();
    void smbDisconnected();
    void newMessage(QString msg);

public slots:
    QString stopClicked();
    QString startClicked();
    QString testClicked();
    void smbConnectedToServer();
    void smbDisconnectedFromServer();
    void gotNewMesssage(QString msg);

private:
    ServerStuff *server;
};

