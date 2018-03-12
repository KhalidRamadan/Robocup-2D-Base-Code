#include "test.hpp"
#include <QUdpSocket>
#include <QString>
#include <QNetworkDatagram>
#include <QDebug>

test::test(QObject *parent) : QObject(parent),
	m_port(0)
{
	m_server = new QUdpSocket(this);
	connect(m_server, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void test::connectToServer(const QHostAddress & address, const quint16 port) 
{
	m_address = address;
	m_port = port;
	
	sendToServer("(init khalid (version 15.4))");
}

void test::sendToServer(const QString & msg)
{
	m_server->writeDatagram(msg.toUtf8(), m_address, m_port);
}


void test::readyRead()
{
	while (m_server->hasPendingDatagrams())
	{
		QNetworkDatagram datagram = m_server->receiveDatagram();
		qDebug() << "data:" << datagram.data();


	}
}


