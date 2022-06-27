#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server();
    QTcpSocket* socket;

public slots:
    void slotReadyRead();
protected slots:
    void incomingConnection(qintptr socketDescriptor) override;

private:
    QVector<QTcpSocket*> sockets;
    QByteArray data;
    quint32 nextBlockSize;

private:
    void sendToClient(const QString& str);
    QString useAlgorithms(const QString& str);
};

#endif // SERVER_H

