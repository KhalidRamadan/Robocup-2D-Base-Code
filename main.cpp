#include <QCoreApplication>
#include "test.hpp"
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	
	test firsttest;

	firsttest.connectToServer(QHostAddress::LocalHost, 6000);
	

	return a.exec();
}