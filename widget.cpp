#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QImage>
#include <QPixmap>
#include <QGraphicsScene>

Widget::Widget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  ui->setupUi(this);
  ui ->label ->resize(640, 380 );
}

Widget::~Widget()
{
  delete ui;
}
QString a;
 QRgb p;

void Widget::on_pushButton_clicked()
{

  a=QFileDialog::getOpenFileName();
   QImage image(a);
  ui->label->setPixmap ( QPixmap::fromImage(image).scaled( 640, 380 ) );

}

void Widget::on_pushButton_2_clicked()
{
  QImage image (a);
   ui->label->setPixmap( QPixmap::fromImage(image).scaled( 640, 380 ) );

}

void Widget::on_pushButton_3_clicked()
{

  QImage image(a);
  QImage imagegray(a);
   ui->label->setPixmap( QPixmap::fromImage(image).scaled( 640, 380 ) );
  for ( int x=0; x<image.width (); x++ )
  {
   for ( int y=0; y<image.height(); y++ )
  {
   p=image.pixel( x, y);
  imagegray.setPixel ( x, y, qRgb ( qRed(p)/3 + qGreen(p)/3 + qBlue(p)/3, qRed(p)/3 + qGreen(p)/3 + qBlue(p)/3, qRed(p)/3 + qGreen(p)/3 + qBlue(p)/3 ) );
  }

}
  ui->label->setPixmap ( QPixmap::fromImage(imagegray).scaled( 640, 380  ) );

}

