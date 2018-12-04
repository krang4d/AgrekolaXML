#ifndef KOAGRXML_H
#define KOAGRXML_H

#include <QtXml>
#include <QDebug>
#include <QFile>

#include <QObject>

class CreateKoAgr : public QObject
{
    Q_OBJECT
public:
    explicit CreateKoAgr(QObject *parent = 0);
    static QDomDocument createTestKo(QString name);
    static QDomDocument createTestAgr(QString name);
    static int writeFile(QString name, QDomDocument doc);
    static int readFile(QString name, QDomDocument &doc);
};

class KoAgrXML : public CreateKoAgr
{
    Q_OBJECT
public:
    explicit KoAgrXML(QObject *parent = 0);
    static QDomDocument createTestKo1();
    static QDomDocument createTestKo2();
    static QDomDocument createTestKo3();
    static QDomDocument createTestKo4();
    static QDomDocument createTestKo5();
    static QDomDocument createTestAgr1();
    static QDomDocument createTestAgr2();

    static QDomDocument createCalibrationKo2();
    static QDomDocument createCalibrationKo3();
    static QDomDocument createCalibrationKo4();
    static QDomDocument createCalibrationKo5();
    static QDomDocument createCalibrationAgr1();
    static QDomDocument createCalibrationAgr2();

    static QDomDocument openTestKo1();
    static QDomDocument openTestKo2();
    static QDomDocument openTestKo3();
    static QDomDocument openTestKo4();
    static QDomDocument openTestKo5();
    static QDomDocument openTestAgr1();
    static QDomDocument openTestAgr2();

    static QDomDocument openCalibrationKo2();
    static QDomDocument openCalibrationKo3();
    static QDomDocument openCalibrationKo4();
    static QDomDocument openCalibrationKo5();
    static QDomDocument openCalibrationAgr1();
    static QDomDocument openCalibrationAgr2();

    static void ListElement(QDomElement root, QString tagname, QString attribute);
    static QString getElement(QDomDocument root, QString tagname);
    static void setElement(QDomDocument &root, QString tagname, QString value);
};

class TestKo : public QObject
{
    Q_OBJECT
public:
    explicit TestKo(QObject *parent = 0);
    ~TestKo();
    virtual void setK1(int k);
    virtual int getK1();
    virtual void setK2(int k);
    virtual int getK2();
    virtual void setK3(int k);
    virtual int getK3();
    virtual void setK4(int k);
    virtual int getK4();
    virtual void setSingle(int k);
    virtual int getSingle();

    virtual QString getText();

protected:
    void setDoc(QDomDocument doc);
    void setName(QString n);

private:
    QDomDocument document;
    QString name;

    int k1, k2, k3, k4, single;
};

class TestKo1 : public TestKo
{
    Q_OBJECT
public:
    explicit TestKo1(QObject *parent = 0);
    ~TestKo1();
};

#endif // KOAGRXML_H
