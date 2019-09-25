#include "QtConverterV2.h"

QtConverterV2::QtConverterV2(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(Calculate()));
}

// Function to convert decimal number to BINARY
std::bitset<INT_SIZE> QtConverterV2::DecToBin(const int num) {
	return std::bitset<INT_SIZE>(num);
}

// Function to convert BINARY number to decimal
int QtConverterV2::BinToDec(std::bitset<INT_SIZE> bin) {
	return bin.to_ulong();
}

// Function to convert decimal number to HEX
std::string QtConverterV2::DecToHex(int num) {
	std::stringstream ss;
	ss << std::hex << num;
	return ss.str();
}

// Function to convert HEX number to decimal
int QtConverterV2::HexToDec(std::string hex) {
	int num;
	std::stringstream ss;
	ss << hex;
	ss >> std::hex >> num;
	return num;
}

// Function to convert decimal number to octal
int QtConverterV2::DecToOctal(int decimalNumber)
{
	int rem, i = 1, octalNumber = 0;
	while (decimalNumber != 0)
	{
		rem = decimalNumber % 8;
		decimalNumber /= 8;
		octalNumber += rem * i;
		i *= 10;
	}
	return octalNumber;
}

// Function to convert OCTAL number to decimal
int QtConverterV2::OctalToDec(int octalNumber)
{
	int decimalNumber = 0, i = 0, rem;
	while (octalNumber != 0)
	{
		rem = octalNumber % 10;
		octalNumber /= 10;
		decimalNumber += rem * pow(8, i);
		++i;
	}
	return decimalNumber;
}

void QtConverterV2::Calculate() {
	std::string zeroes = "000000000000000000000000";
	int difference = 0;
	if (ui.spinBox->value() > INT_SIZE) {
		difference = ui.spinBox->value() - INT_SIZE;
	}

	if (ui.rb_dec->isChecked() && (ui.decimal->text() != QString(""))) {
		int num = std::stoi(ui.decimal->text().toStdString());
		std::bitset<INT_SIZE> binary = DecToBin(num);
		std::string hex = DecToHex(num);
		int octal = DecToOctal(num);

		QString binaryQS = QString::fromStdString(binary.to_string().append(zeroes,0,difference));
		QString hexQS = QString::fromStdString(hex);
		QString octalQS = QString::fromStdString(std::to_string(octal));

		ui.binary->setText(binaryQS);
		ui.hex->setText(hexQS);
		ui.octal->setText(octalQS);

	}
	else if(ui.rb_bin->isChecked()){
		std::bitset<INT_SIZE> bin(ui.binary->text().toStdString());
		int dec = BinToDec(bin);
		std::string hex = DecToHex(dec);
		int octal = DecToOctal(dec);

		QString DecQS = QString::fromStdString(std::to_string(dec));
		QString hexQS = QString::fromStdString(hex);
		QString octalQS = QString::fromStdString(std::to_string(octal));

		ui.decimal->setText(DecQS);
		ui.hex->setText(hexQS);
		ui.octal->setText(octalQS);
	}
	else if(ui.rb_hex->isChecked()) {
		std::string hex = ui.hex->text().toStdString();
		int dec = HexToDec(hex);
		std::bitset<INT_SIZE> bin = DecToBin(dec);
		int octal = DecToOctal(dec);
		

		QString DecQS = QString::fromStdString(std::to_string(dec));
		QString binQS = QString::fromStdString(bin.to_string().append(zeroes, 0, difference));
		QString octalQS = QString::fromStdString(std::to_string(octal));

		ui.decimal->setText(DecQS);
		ui.binary->setText(binQS);
		ui.octal->setText(octalQS);
	}
	else if (ui.rb_octal->isChecked()) {
		int octal = std::stoi(ui.octal->text().toStdString());
		int dec = OctalToDec(octal);
		std::bitset<INT_SIZE> bin = DecToBin(dec);
		std::string hex = DecToHex(dec);

		QString DecQS = QString::fromStdString(std::to_string(dec));
		QString binQS = QString::fromStdString(bin.to_string().append(zeroes, 0, difference));
		QString hexQS = QString::fromStdString(hex);

		ui.decimal->setText(DecQS);
		ui.binary->setText(binQS);
		ui.hex->setText(hexQS);

	}
}
