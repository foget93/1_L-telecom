#include "server.h"
#include <QTime>
#include "analyzer.h"

Server::Server()
    : nextBlockSize{0}
{
    if (this->listen(QHostAddress::Any, 2323))
        qDebug() << "Start";
    else
        qDebug() << "Error";
    //this->nextBlockSize = 0;
}

//=================================================================

void Server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, &QTcpSocket::readyRead,
            this,   &Server::slotReadyRead);    //сигнал сокета реадиРид и наш слот сервера

    connect(socket, &QTcpSocket::disconnected,
            socket, &QTcpSocket::deleteLater);  //при откл клиента приложение удалит сокет

    sockets.push_back(socket);
    qDebug() << "client connected:" << socketDescriptor;
}

//=================================================================

void Server::slotReadyRead()
{
    socket = dynamic_cast<QTcpSocket*>(sender());
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);

        qDebug() << "read...";

        for (;;)
        {
            if (!nextBlockSize) {
                if (socket->bytesAvailable() < static_cast<qint64>(sizeof(quint32)) ) // что бы компилятор не ругался :)
                    break;

                in >> nextBlockSize;
            }
            if (socket->bytesAvailable() < nextBlockSize)
                break;

            QString str;
            in >> str;
            nextBlockSize = 0;

            qDebug() << str;
            /*обработать*/
            QString bufStr;

            Analyzer testAlg1 (new algorithm_A);
            bufStr += testAlg1.executeAlgorithm(str);

            Analyzer testAlg2 (new algorithm_B);
            bufStr += testAlg2.executeAlgorithm(str);

            sendToClient(bufStr);
            break;
        }

}

//=================================================================

void Server::sendToClient(const QString& str)
{
    this->data.clear();

    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);

    out << quint32(0) << str;
    out.device()->seek(0);
    out << quint32(data.size() - sizeof(quint32));

    //this->socket->write(data);
        for (int i {0}; i < sockets.size(); ++i)
              sockets[i]->write(data);
}

//=================================================================
