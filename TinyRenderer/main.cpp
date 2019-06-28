#include "TinyRenderer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	TinyRenderer w;
	w.show();
	return a.exec();
}
