/* File: Yinyang
 * ---------------
 *
 * Name: jinglebot
 * Date started: March 11, 2015
 * Date finished: March 11, 2015
 *
 * This program draws a yinyang symbol in
 * the center of a blank console.
 *
 * Question:
 * - How do I make the smaller white circle have
 * a smoother blending with the border?
 *
 *
 */

#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    return a.exec();
}
