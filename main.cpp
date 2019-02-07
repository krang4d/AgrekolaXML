#include <QApplication>
#include <QDomDocument>
#include <QDebug>
#include <QFile>
#include <QString>
#include <koagrxml.h>
#include <QMessageBox>

int Test();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QDomDocument dom = KoAgrXML::createCalibrationKo1();
    CalibrationKo1 c_ko1;
    CalibrationKo2 c_ko2;
    CalibrationKo3 c_ko3;
    CalibrationKo4 c_ko4;
    CalibrationKo5 c_ko5;

    CalibrationAgr1 c_agr1;
    CalibrationAgr2 c_Agr2;

    TestKo1 t_ko1;
    TestKo2 t_ko2;
    TestKo3 t_ko3;
    TestKo4 t_ko4;
    TestKo5 t_ko5;

    setlocale(LC_ALL, "Russian");

    qDebug() << "проверка";
    c_agr1.setIncube_time(3.14);
    c_agr1.setTrombotsit_serial("Серия");
    c_agr1.save();
    qDebug() << c_agr1.getIncube_time() << "Серия" << c_agr1.getTrombotsit_serial();
//    qDebug() << QString("%1").arg(c_ko1.getIncube_time());
//    qDebug() << QString("%1").arg(c_ko1.getWrite_time());

//    c_ko1.setIncube_time(12.5);
//    c_ko1.setWrite_time(23.5);

//    qDebug() << QString("%1").arg(c_ko1.getIncube_time());
//    qDebug() << QString("%1").arg(c_ko1.getWrite_time());

//    c_ko1.save();

//    qDebug() << QString("%1").arg(c_ko1.getIncube_time());
//    qDebug() << QString("%1").arg(c_ko1.getWrite_time());

//    qDebug() << QString("%1").arg(c_ko2.getIncube_time());
//    qDebug() << QString("%1").arg(c_ko2.getWrite_time());

    QMessageBox::StandardButton button;
    QMessageBox test_dialog;
    test_dialog.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    test_dialog.setIcon(QMessageBox::Information);
    //Проверка Перемешивания в канале 1
    test_dialog.setWindowTitle("Канал 1 - проверка");
    test_dialog.setText("Проконтролируте включение перемешивания в канале 1");
    test_dialog.exec();
    return a.exec();
}
