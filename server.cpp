#include "server.h"
#include <QTime>

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
    socket = static_cast<QTcpSocket*>(sender());
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_15);
    if (in.status() == QDataStream::Ok)
    {

        //продолжаем обработку // сделать обработку картинок (заранее знать какие данные пересылаются)
        qDebug() << "read...";

       /* QString str;
        in >> str;
        qDebug() << str;
        SendToClient(str);
        */
        for (;;)
        {
            if (nextBlockSize == 0)
            {
                qDebug() << "nextBlockSize = 0";
                if(socket->bytesAvailable() < 2)
                {
                    qDebug() << "Data < 2, break";
                    break;
                }
                in >> nextBlockSize;
                qDebug() << "nextBlockSize = " << nextBlockSize;
            }
            if (socket->bytesAvailable() < nextBlockSize)
            {
                qDebug() << "Data not full, break";
                break;
            }

            QString str;
            QTime time;
            in >> time >> str;
            nextBlockSize = 0;
            qDebug() << str;
            sendToClient(str);
            break;
        }
    }
    else
    {
        qDebug() << "DataStream error";
    }
}

//=================================================================

void Server::sendToClient(const QString& str)
{
    this->data.clear();

    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_15);

    out << quint32(0) << str;
    out.device()->seek(0);
    out << quint32(data.size() - sizeof(quint32));

    this->socket->write(data);
    //    for (int i {0}; i < Sockets.size(); ++i)
    //          Sockets[i]->write(Data);
}

//=================================================================

