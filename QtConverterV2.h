#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtConverterV2.h"

#include <bitset>
#include <sstream>

#define INT_SIZE 8

class QtConverterV2 : public QMainWindow
{
	Q_OBJECT

public:
	QtConverterV2(QWidget *parent = Q_NULLPTR);

private:

	std::bitset<INT_SIZE> DecToBin(const int num);
	int BinToDec(std::bitset<INT_SIZE> bin);
	std::string DecToHex(int num);
	int HexToDec(std::string hex);
	int DecToOctal(int decimalNumber);
	int OctalToDec(int octalNumber);

	Ui::QtConverterV2Class ui;
	

private slots:
	void Calculate();
};
