#ifndef TEST_H
#define TEST_H



#include<QObject>
#include <QHostAddress>

class QUdpSocket;


class test : public QObject
{
	Q_OBJECT

private:
	QUdpSocket *m_server;
	QHostAddress m_address;
	quint16 m_port;


public :
	explicit test(QObject *parent = NULL);
	void connectToServer(const QHostAddress &address, const quint16 port);
	void sendToServer(const QString &msg);
public slots :
	void readyRead();



};



#endif