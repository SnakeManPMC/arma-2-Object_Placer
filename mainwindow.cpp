#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QDebug>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QImage mappic;
	mappic.load("d:/coding/test_files/satellite_mask_512.png");

	view = new QGraphicsView;
	setCentralWidget(view);

	// LMB drag
	view->setDragMode(QGraphicsView::ScrollHandDrag);

	scene = new QGraphicsScene;
	QPixmap myPix;
	myPix.convertFromImage(mappic);
	scene->addPixmap(myPix);

	view->setScene(scene);

	resize(530,560);

	// return the RGB value with integer(s) ;)
	QRgb b;
	b = mappic.pixel(100,100);
	QColor c;
	c.setRgb(b);

	//qDebug() << "Pixel: " << c.red() << ", " << c.green() << ", " << c.blue();
	//qDebug() << "QRgb: " << b;

	// initialize random seed:
	QTime timmy(0, 0, 0);
	qsrand(timmy.secsTo(QTime::currentTime()));

	for (int i=0; i < 500; i++)
	{
	    float x = (511 * qrand() / (RAND_MAX + 1.0));
	    float y = (511 * qrand() / (RAND_MAX + 1.0));
	    b = mappic.pixel(x,y);
	    // RGB 100,100,100 as integer HEHE ;)
	    if (b == 4294902015) scene->addEllipse( x, y, 5, 5, Qt::SolidLine, Qt::NoBrush);
	}
}

MainWindow::~MainWindow()
{
	delete ui;
}
