#ifndef KOAGRXML_H
#define KOAGRXML_H

#include <QtXml>
#include <QDebug>
#include <QFile>

#include <QObject>

class KoAgrXML : public QObject
{
    Q_OBJECT
public:
    explicit KoAgrXML(QObject *parent = 0);
    QDomDocument createTestKo1();
    QDomDocument createTestKo2();
    QDomDocument createTestKo3();
    QDomDocument createTestKo4();
    QDomDocument createTestKo5();
    QDomDocument createTestAgr1();
    QDomDocument createTestAgr2();

    QDomDocument createCalibrationKo2();
    QDomDocument createCalibrationKo3();
    QDomDocument createCalibrationKo4();
    QDomDocument createCalibrationKo5();
    QDomDocument createCalibrationAgr1();
    QDomDocument createCalibrationAgr2();

    QDomDocument openTestKo1();
    void closeTestKo1(QDomDocument doc);
    QDomDocument openTestKo2();
    QDomDocument openTestKo3();
    QDomDocument openTestKo4();
    QDomDocument openTestKo5();
    QDomDocument openTestAgr1();
    QDomDocument openTestAgr2();

    QDomDocument openCalibrationKo2();
    QDomDocument openCalibrationKo3();
    QDomDocument openCalibrationKo4();
    QDomDocument openCalibrationKo5();
    QDomDocument openCalibrationAgr1();
    QDomDocument openCalibrationAgr2();

    static void ListElement(QDomElement root, QString tagname, QString attribute);
    static QString getElement(QDomDocument root, QString tagname);
    static void setElement(QDomDocument root, QString tagname, QString value);
signals:

public slots:

private:
    //QDomDocument document;
};

class TestKo1 : public KoAgrXML
{
    Q_OBJECT
public:
    TestKo1();
    ~TestKo1();
    void setK1(int k);
    int getK1();
    void setK2(int k);
    int getK2();
    void setK3(int k);
    int getK3();
    void setK4(int k);
    int getK4();
    void setSingle(int k);
    int getSingle();

    QString getText();
private:
    QDomDocument document;
    int k1, k2, k3, k4, single;
};

#endif // KOAGRXML_H
