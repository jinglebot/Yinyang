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

    // Set the size of the symbol
    QRect bigC(width/2 - rad, height/2 - rad, 2*rad, 2*rad);

    // Set pen properties
    QPen  whitepen;
    whitepen.setColor(Qt::white);
    whitepen.setWidth(0);
    QPen  blackpen;
    blackpen.setColor(Qt::black);
    blackpen.setWidth(0);

    // Set brush properties
    QBrush blackbrush(Qt::black, Qt::SolidPattern);
    QBrush whitebrush(Qt::white, Qt::SolidPattern);

    // Shade each half of the circle
    blackpen.setWidth(10);
    painter.setPen(blackpen);
    painter.setBrush(whitebrush);
    painter.drawChord(bigC, -90*16, 180*16);
    painter.setBrush(blackbrush);
    painter.drawChord(bigC, 90*16, 180*16);

    // Draw a small white circle
    QRect smallupC((width - rad)/2, height/2 - rad, rad, rad);
    painter.setPen(whitepen);
    painter.setBrush(whitebrush);
    painter.drawEllipse(smallupC);

    // Draw a small black circle
    QRect smalldownC((width - rad)/2, height/2, rad, rad);
    blackpen.setWidth(0);
    painter.setPen(blackpen);
    painter.setBrush(blackbrush);
    painter.drawEllipse(smalldownC);

    // Draw a small black dot
    QRect upctrC(width/2 - rad/8, height/2 - 5*rad/8, 4*rad/16, 4*rad/16);
    painter.setBrush(blackbrush);
    painter.drawEllipse(upctrC);

    // Draw a small white dot
    QRect downctrC(width/2 - rad/8, height - 7*rad/8, 4*rad/16, 4*rad/16);
    painter.setBrush(whitebrush);
    painter.drawEllipse(downctrC);






}
