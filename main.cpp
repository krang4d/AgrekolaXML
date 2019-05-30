#include <QApplication>
#include <QDomDocument>
#include <QDebug>
#include <QFile>
#include <QString>
#include <koagrxml.h>
#include <QMessageBox>

void test();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    setlocale(LC_ALL, "Russian");

    //QDomDocument dom = KoAgrXML::createCalibrationKo1();

//    TestKo3 t_ko3;
    //test();
//    TestKo1 *t_ko1(new TestKo1);

//    TestKo2 *t_ko2_1(new TestKo2());
//    TestKo3 *t_ko3(new TestKo3);
//    TestKo4 *t_ko4_1(new TestKo4);

//    TestKo5 *t_ko5(new TestKo5);
//    TestAgr1 *t_agr1(new TestAgr1);
//    TestAgr2 *t_agr2(new TestAgr2);
//    CalibrationAgr1 *c_agr1(new CalibrationAgr1);
//    QMessageBox::information(0, "Info c_ko2", t_ko2_1->print());
    test();
    return a.exec();
}

void test() {
    CalibrationKo1 *c_ko1(new CalibrationKo1);
    CalibrationKo2 *c_ko2(new CalibrationKo2);
    CalibrationKo3 *c_ko3(new CalibrationKo3);
    CalibrationKo4 *c_ko4(new CalibrationKo4);
    CalibrationKo4_1 *c_ko4_1(new CalibrationKo4_1);
    CalibrationKo4_2 *c_ko4_2(new CalibrationKo4_2);
    CalibrationKo4_3 *c_ko4_3(new CalibrationKo4_3);
    CalibrationKo5 *c_ko5(new CalibrationKo5);

    CalibrationAgr1 *c_agr1(new CalibrationAgr1);
    CalibrationAgr2 *c_agr2(new CalibrationAgr2);

    TestKo1 *t_ko1(new TestKo1);
    TestKo2 *t_ko2_1(new TestKo2);
    TestKo2 *t_ko2_2(new TestKo2(WithoutCalibration()));
    TestKo3 *t_ko3(new TestKo3);
    TestKo4 *t_ko4_1(new TestKo4);
    TestKo4 *t_ko4_2(new TestKo4(WithoutCalibration()));
    TestKo5 *t_ko5(new TestKo5);
    TestAgr1 *t_agr1(new TestAgr1);
    TestAgr2 *t_agr2(new TestAgr2);

//    QMessageBox::information(0, "Info c_ko1", c_ko1.print());
//    QMessageBox::information(0, "Info c_ko2", c_ko2.print());
//    QMessageBox::information(0, "Info c_ko3", c_ko3.print());
//    QMessageBox::information(0, "Info c_ko4", c_ko4.print());
//    QMessageBox::information(0, "Info c_ko5", c_ko5.print());
//    QMessageBox::information(0, "Info c_agr1", c_agr1.print());
//    QMessageBox::information(0, "Info c_agr2", c_agr2.print());
}
