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
signals:

public slots:

private:
    //QDomDocument document;
};

#endif // KOAGRXML_H
