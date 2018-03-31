#include "mytcp.h"

MyTCP::MyTCP (QObject *parent) : QObject(parent)
{
    QByteArray data;
    data = "Test";
    tcpaddress.setAddress(QHostAddress::LocalHost);

    tcpsocket = new QTcpSocket(this);
    connect(tcpsocket, SIGNAL(readyRead()), SLOT(readyRead()));

    tcpsocket->connectToHost(QHostAddress::LocalHost, 15000);
    if (tcpsocket->waitForConnected()) {
        tcpsocket->write(data);
    }
}

void MyTCP::readyRead() {
    QByteArray response;
    response.resize(10);
    response = tcpsocket->readAll();
}

//void MyTCP::sendCommand() {
//    QByteArray cmd;
//    cmd = "Test";
//    tcpsocket->writeData(cmd, cmd.size());
//}
