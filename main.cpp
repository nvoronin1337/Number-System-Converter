#include "QtConverterV2.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QtConverterV2 w;
	w.setWindowTitle("Number Systems Converter");

	w.show();
	return a.exec();
}
