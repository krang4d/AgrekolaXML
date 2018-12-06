#include <QCoreApplication>
#include <QDomDocument>
#include <QDebug>
#include <QFile>
#include <QString>
#include <koagrxml.h>

int Test();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    KoAgrXML docxml;
    //docxml.createTestKo1();
    TestKo1 t_ko1;
    qDebug() << "Text XML" << t_ko1.getText();
    t_ko1.setK1(6);
    qDebug() << "K1 = " << t_ko1.getK1();

    docxml.createTestKo2();
    docxml.createTestKo3();
    docxml.createTestKo4();
    docxml.createTestKo5();
    docxml.createTestAgr1();
    docxml.createTestAgr2();

    docxml.createCalibrationKo2();
    docxml.createCalibrationKo3();
    docxml.createCalibrationKo4();
    docxml.createCalibrationKo5();
    docxml.createCalibrationAgr1();
    docxml.createCalibrationAgr2();

    //Test();
    return a.exec();
}

int Test()
{
    QDomDocument document;
    QDomElement KoAgr = document.createElement("KoAgr");

    document.appendChild(KoAgr);

    QDomElement ko1 = document.createElement("Ko1");
    QDomText t1 = document.createTextNode(QString::number(1.1));
    QDomText t2 = document.createTextNode(QString::number(2.2));
    QDomText t3 = document.createTextNode(QString::number(3.3));
    ko1.appendChild(t1);
    ko1.appendChild(t2);
    ko1.appendChild(t3);
    QDomElement test = document.createElement("Test");

    QDomElement channels = document.createElement("channels");
    channels.appendChild(document.createElement("k1"));
    channels.appendChild(document.createElement("k2"));
    channels.appendChild(document.createElement("k3"));
    channels.appendChild(document.createElement("k4"));
    test.appendChild(channels);
    test.appendChild(document.createElement("single"));
    test.appendChild(document.createElement("write_time"));
    test.appendChild(document.createElement("incube_time"));
    ko1.appendChild(test);

    ko1.appendChild(document.createElement("Calibration"));
    KoAgr.appendChild(ko1);

    QDomElement ko2 = document.createElement("Ko2");
    ko2.appendChild(document.createElement("Test"));
    ko2.appendChild(document.createElement("Calibration"));
    KoAgr.appendChild(ko2);

    QDomElement ko3 = document.createElement("Ko3");
    ko3.appendChild(document.createElement("Test"));
    ko3.appendChild(document.createElement("Calibration"));
    KoAgr.appendChild(ko3);

    QDomElement ko4 = document.createElement("Ko4");
    ko4.appendChild(document.createElement("Test"));
    ko4.appendChild(document.createElement("Calibration"));
    KoAgr.appendChild(ko4);

    QDomElement ko5 = document.createElement("Ko5");
    ko5.appendChild(document.createElement("Test"));
    ko5.appendChild(document.createElement("Calibration"));
    KoAgr.appendChild(ko5);

    QDomElement agr1 = document.createElement("Agr1");
    agr1.appendChild(document.createElement("Test"));
    agr1.appendChild(document.createElement("Calibration"));
    KoAgr.appendChild(agr1);

    QDomElement agr2 = document.createElement("Agr2");
    agr2.appendChild(document.createElement("Test"));
    agr2.appendChild(document.createElement("Calibration"));
    KoAgr.appendChild(agr2);

//    kotest.setAttribute("Single", "1");
//    kotest.setNodeValue("NodeValue");
//    kotest.setAttribute("K1", "1");
//    kotest.setAttribute("K2", "1");
//    kotest.setAttribute("K3", "1");
//    kotest.setAttribute("K4", "1");
//    kotest.setAttribute("Write_time", "5");
//    kotest.setAttribute("Incube_time", "2");
//    ko5.appendChild(kotest);

    QDomElement agrtest = document.createElement("Test");
    agrtest.setAttribute("Single", "1");
    agrtest.setNodeValue("NodeValue");
    agrtest.setAttribute("K1", "1");
    agrtest.setAttribute("K2", "1");
    agrtest.setAttribute("K3", "1");
    agrtest.setAttribute("K4", "1");
    agrtest.setAttribute("Write_time", "5");
    agrtest.setAttribute("Incube_time", "2");
    agr1.appendChild(agrtest);
    agr2.appendChild(agrtest);

//    QDomElement calibrate =document.createElement("Calibrate");
//    ko1.appendChild(calibrate);

    QFile file("d:/KoAgr.xml");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Faild to open file for writting";
        return -1;
    } else {
        QTextStream stream(&file);
        stream << document.toString();
        file.close();
    }
    file.close();

//    QFile file("d:/KoAgr.xml");
//    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//        qDebug() << "Faild to open file for writting";
//        return -1;
//    } else {
//        if(!document.setContent(&file)){
//            qDebug() << "Failed to load document";
//        }
//        file.close();
 //   }
    return 0;
}
