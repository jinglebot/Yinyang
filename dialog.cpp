#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    height = 500;
    width = 500;
    rad = 0;

    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    rad = (height/2)*4/5;
    QRect bigC(width/2 - rad, height/2 - rad, 2*rad, 2*rad);

    QPen  whitepen;
    whitepen.setColor(Qt::white);
    whitepen.setWidth(0);
    QPen  graypen;
    graypen.setColor(Qt::black);
    graypen.setWidth(0);

    QBrush graybrush(Qt::black, Qt::SolidPattern);
    QBrush whitebrush(Qt::white, Qt::SolidPattern);

    graypen.setWidth(10);
    painter.setPen(graypen);
    painter.setBrush(whitebrush);
    painter.drawChord(bigC, -90*16, 180*16);
    painter.setBrush(graybrush);
    painter.drawChord(bigC, 90*16, 180*16);

    QRect smallupC((width - rad)/2, height/2 - rad, rad, rad);
    painter.setPen(whitepen);
    painter.setBrush(whitebrush);
    painter.drawEllipse(smallupC);

    QRect smalldownC((width - rad)/2, height/2, rad, rad);
    graypen.setWidth(0);
    painter.setPen(graypen);
    painter.setBrush(graybrush);
    painter.drawEllipse(smalldownC);

    QRect upctrC(width/2 - rad/8, height/2 - 5*rad/8, 4*rad/16, 4*rad/16);
    painter.setBrush(graybrush);
    painter.drawEllipse(upctrC);

    QRect downctrC(width/2 - rad/8, height - 7*rad/8, 4*rad/16, 4*rad/16);
    painter.setBrush(whitebrush);
    painter.drawEllipse(downctrC);

   // painter.setOpacity(0.2);
   // painter.drawEllipse(bigC);





}
