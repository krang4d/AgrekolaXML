#include "koagrxml.h"

QDomDocument createTestKo(QString name) {

    QDomDocument document;
    QDomElement test = document.createElement(name);
    document.appendChild(test);

    QDomElement single = document.createElement("single");
    single.setAttribute("Value", "1");
    test.appendChild(single);

    QDomElement k1 = document.createElement("k1");
    k1.setAttribute("Value", "1");
    test.appendChild(k1);

    QDomElement k2 = document.createElement("k2");
    k2.setAttribute("Value", "1");
    test.appendChild(k2);

    QDomElement k3 = document.createElement("k3");
    k3.setAttribute("Value", "1");
    test.appendChild(k3);

    QDomElement k4 = document.createElement("k4");
    k4.setAttribute("Value", "1");
    test.appendChild(k4);

    return document;
}

QDomDocument createTestAgr(QString name) {
    QDomDocument document = createTestKo(name);
    QDomElement test = document.firstChildElement(name);
    return document;
}

int writeFile(QString name, QDomDocument doc)
{
    QFile file(name + QString(".xml"));
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Faild to open file for writting";
        return -1;
    } else {
        QTextStream stream(&file);
        stream << doc.toString();
        file.close();
    }
    file.close();
    return 0;
}

int readFile(QString name, QDomDocument doc)
{
    QFile file(name + QString(".xml"));
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Faild to open file for writting";
        return -1;
    } else {
        if(!doc.setContent(&file)) {
            qDebug() << "Failed to load document";
            return -2;
        }
        file.close();
    }
    return 0;
}

KoAgrXML::KoAgrXML(QObject *parent) : QObject(parent)
{

}

QDomDocument KoAgrXML::createTestKo1()
{
    QString name("testKo1");
    QDomDocument document = createTestKo(name);
    writeFile(name, document);
    return document;
}

QDomDocument KoAgrXML::createTestKo2()
{
    QString name("testKo2");
    QDomDocument document = createTestKo(name);
    writeFile(name, document);
    return document;
}

QDomDocument KoAgrXML::createTestKo3()
{
    QString name("testKo3");
    QDomDocument document = createTestKo(name);
    writeFile(name, document);
    return document;
}

QDomDocument KoAgrXML::createTestKo4()
{
    QString name("testKo4");
    QDomDocument document = createTestKo(name);
    writeFile(name, document);
    return document;
}

QDomDocument KoAgrXML::createTestKo5()
{
    QString name("testKo5");
    QDomDocument document = createTestKo(name);
    writeFile(name, document);
    return document;
}

QDomDocument KoAgrXML::createTestAgr1()
{
    QString name("testAgr1");
    QDomDocument document = createTestAgr(name);
    writeFile(name, document);
    return document;
}

QDomDocument KoAgrXML::createTestAgr2()
{
    QString name("testAgr2");
    QDomDocument document = createTestAgr(name);
    writeFile(name, document);
    return document;
}

QDomDocument KoAgrXML::createCalibrationKo2()
{
    QString name("calibrationKo2");
    QDomDocument document;
    QDomElement calibration = document.createElement(name);
    document.appendChild(calibration);
    calibration.appendChild(document.createElement("data"));
    calibration.appendChild(document.createElement("reagent_serial"));
    calibration.appendChild(document.createElement("reagent_data"));
    calibration.appendChild(document.createElement("k_plazma_serial"));
    calibration.appendChild(document.createElement("k_plazma_data"));
    calibration.appendChild(document.createElement("a4tv_k_plazma"));

    calibration.appendChild(document.createElement("write_time"));
    calibration.appendChild(document.createElement("incube_time"));

    writeFile(name, document);
    return document;
}

QDomDocument KoAgrXML::createCalibrationKo3()
{
    QString name("calibrationKo3");
    QDomDocument document;
    QDomElement calibration = document.createElement(name);
    document.appendChild(calibration);
    calibration.appendChild(document.createElement("data"));
    calibration.appendChild(document.createElement("reagent_serial"));
    calibration.appendChild(document.createElement("reagent_data"));
    calibration.appendChild(document.createElement("fibrinogen_k_plazma"));
    calibration.appendChild(document.createElement("time_k_plazma"));
    calibration.appendChild(document.createElement("fibrinogen_200_plazma"));
    calibration.appendChild(document.createElement("time_200_plazma"));
    calibration.appendChild(document.createElement("fibrinogen_50_plazma"));
    calibration.appendChild(document.createElement("time_50_plazma"));
    calibration.appendChild(document.createElement("fibrinogen_25_plazma"));
    calibration.appendChild(document.createElement("time_25_plazma"));

    calibration.appendChild(document.createElement("write_time"));
    calibration.appendChild(document.createElement("incube_time"));

    writeFile(name, document);
    return document;
}

QDomDocument KoAgrXML::createCalibrationKo4()
{
    QString name("calibrationKo4");
    QDomDocument document;
    QDomElement calibration = document.createElement(name);
    document.appendChild(calibration);
    calibration.appendChild(document.createElement("data"));
    calibration.appendChild(document.createElement("reagent_serial"));
    calibration.appendChild(document.createElement("reagent_data"));
    calibration.appendChild(document.createElement("k_plazma_serial"));
    calibration.appendChild(document.createElement("k_plazma_data"));
    calibration.appendChild(document.createElement("action"));
    calibration.appendChild(document.createElement("trombine_time"));
    calibration.appendChild(document.createElement("write_time"));
    calibration.appendChild(document.createElement("incube_time"));

    writeFile(name, document);
    return document;
}

QDomDocument KoAgrXML::createCalibrationKo5()
{
    QString name("calibrationKo5");
    QDomDocument document;
    QDomElement calibration = document.createElement(name);
    document.appendChild(calibration);
    calibration.appendChild(document.createElement("data"));
    calibration.appendChild(document.createElement("tromboplastin_serial"));
    calibration.appendChild(document.createElement("tromboplastin_data"));
    calibration.appendChild(document.createElement("k_plazma_serial"));
    calibration.appendChild(document.createElement("k_plazma_data"));
    calibration.appendChild(document.createElement("k_protrombine_index"));
    calibration.appendChild(document.createElement("k_protrombine_otn"));
    calibration.appendChild(document.createElement("protrombine_k_Kvik"));
    calibration.appendChild(document.createElement("time_k_Kvik"));

    calibration.appendChild(document.createElement("protrombine_50_Kvik"));
    calibration.appendChild(document.createElement("time_50_Kvik"));

    calibration.appendChild(document.createElement("protrombine_25_Kvik"));
    calibration.appendChild(document.createElement("time_25_Kvik"));

    calibration.appendChild(document.createElement("protrombine_12_Kvik"));
    calibration.appendChild(document.createElement("time_12_Kvik"));

    calibration.appendChild(document.createElement("protrombine_index"));
    calibration.appendChild(document.createElement("protrombine_otn"));

    calibration.appendChild(document.createElement("write_time"));
    calibration.appendChild(document.createElement("incube_time"));

    writeFile(name, document);
    return document;
}

QDomDocument KoAgrXML::createCalibrationAgr1()
{
    QString name("calibrationAgr1");
    QDomDocument document;
    QDomElement calibration = document.createElement(name);
    document.appendChild(calibration);
    //входные данные
    calibration.appendChild(document.createElement("data"));
    calibration.appendChild(document.createElement("reagent_serial"));
    calibration.appendChild(document.createElement("reagent_data"));
    calibration.appendChild(document.createElement("k_concentration"));
    //выходные данные
    calibration.appendChild(document.createElement("level_0"));
    calibration.appendChild(document.createElement("level_100"));

    calibration.appendChild(document.createElement("write_time"));
    calibration.appendChild(document.createElement("incube_time"));
    calibration.appendChild(document.createElement("incube_time_2"));

    writeFile(name, document);
    return document;
}

QDomDocument KoAgrXML::createCalibrationAgr2()
{
    QString name("calibrationAgr2");
    QDomDocument document;
    QDomElement calibration = document.createElement(name);
    document.appendChild(calibration);
    //входные данные
    calibration.appendChild(document.createElement("data"));
    calibration.appendChild(document.createElement("reagent_serial"));
    calibration.appendChild(document.createElement("reagent_data"));
    calibration.appendChild(document.createElement("k_plazma_serial"));
    calibration.appendChild(document.createElement("k_plazma_data"));
    calibration.appendChild(document.createElement("k_plazma"));
    //выходные данные
    calibration.appendChild(document.createElement("level_0"));
    calibration.appendChild(document.createElement("level_100"));

    calibration.appendChild(document.createElement("k_plazma_serial"));
    calibration.appendChild(document.createElement("k_plazma_data"));

    calibration.appendChild(document.createElement("c1"));
    calibration.appendChild(document.createElement("ck1"));

    calibration.appendChild(document.createElement("c2"));
    calibration.appendChild(document.createElement("ck2"));

    calibration.appendChild(document.createElement("c3"));
    calibration.appendChild(document.createElement("ck3"));

    calibration.appendChild(document.createElement("c4"));
    calibration.appendChild(document.createElement("ck4"));

    calibration.appendChild(document.createElement("write_time"));
    calibration.appendChild(document.createElement("incube_time"));
    calibration.appendChild(document.createElement("incube_time_2"));

    writeFile(name, document);
    return document;
}

QDomDocument KoAgrXML::openTestKo1()
{
    QDomDocument doc;
    QString name("testKo1");
    if( QFile::exists(name + QString(".xml")) ) {
        readFile(name, doc);
    }
    else doc = createTestKo1();
    return doc;
}

void KoAgrXML::closeTestKo1(QDomDocument doc)
{
    QString name("testKo1");
    writeFile((name + QString(".xml")), doc);
}

QDomDocument KoAgrXML::openTestKo2()
{
    QDomDocument doc;
    QString name("testKo2");
    if( QFile::exists(name + QString(".xml")) ) {
        readFile(name, doc);
    }
    else doc = createTestKo2();
    return doc;
}

QDomDocument KoAgrXML::openTestKo3()
{
    QDomDocument doc;
    QString name("testKo3");
    if( QFile::exists(name + QString(".xml")) ) {
        readFile(name, doc);
    }
    else doc = createTestKo3();
    return doc;
}

QDomDocument KoAgrXML::openTestKo4()
{
    QDomDocument doc;
    QString name("testKo3");
    if( QFile::exists(name + QString(".xml")) ) {
        readFile(name, doc);
    }
    else doc = createTestKo4();
    return doc;
}

QDomDocument KoAgrXML::openTestKo5()
{
    QDomDocument doc;
    QString name("testKo5");
    if( QFile::exists(name + QString(".xml")) ) {
        readFile(name, doc);
    }
    else doc = createTestKo5();
    return doc;
}

QDomDocument KoAgrXML::openTestAgr1()
{
    QDomDocument doc;
    QString name("testAgr1");
    if( QFile::exists(name + QString(".xml")) ) {
        readFile(name, doc);
    }
    else doc = createTestAgr1();
    return doc;
}

QDomDocument KoAgrXML::openTestAgr2()
{
    QDomDocument doc;
    QString name("testAgr2");
    if( QFile::exists(name + QString(".xml")) ) {
        readFile(name, doc);
    }
    else doc = createTestAgr2();
    return doc;
}

QDomDocument KoAgrXML::openCalibrationKo2()
{
    QDomDocument doc;
    QString name("calibrationKo2");
    if( QFile::exists(name + QString(".xml")) ) {
        readFile(name, doc);
    }
    else doc = createCalibrationKo2();
    return doc;
}

QDomDocument KoAgrXML::openCalibrationKo3()
{
    QDomDocument doc;
    QString name("calibrationKo3");
    if( QFile::exists(name + QString(".xml")) ) {
        readFile(name, doc);
    }
    else doc = createCalibrationKo3();
    return doc;
}

QDomDocument KoAgrXML::openCalibrationKo4()
{
    QDomDocument doc;
    QString name("calibrationKo4");
    if( QFile::exists(name + QString(".xml")) ) {
        readFile(name, doc);
    }
    else doc = createCalibrationKo4();
    return doc;
}

QDomDocument KoAgrXML::openCalibrationKo5()
{
    QDomDocument doc;
    QString name("calibrationKo5");
    if( QFile::exists(name + QString(".xml")) ) {
        readFile(name, doc);
    }
    else doc = createCalibrationKo5();
    return doc;
}

QDomDocument KoAgrXML::openCalibrationAgr1()
{
    QDomDocument doc;
    QString name("calibrationAgr1");
    if( QFile::exists(name + QString(".xml")) ) {
        readFile(name, doc);
    }
    else doc = createCalibrationAgr1();
    return doc;
}

QDomDocument KoAgrXML::openCalibrationAgr2()
{
    QDomDocument doc;
    QString name("calibrationAgr2");
    if( QFile::exists(name + QString(".xml")) ) {
        readFile(name, doc);
    }
    else doc = createCalibrationAgr2();
    return doc;
}

void KoAgrXML::ListElement(QDomElement root, QString tagname, QString attribute)
{
    QDomNodeList items = root.elementsByTagName(tagname);
    qDebug() << "Total items = " << items.count();
    for(int i =0; i < items.count(); i++) {
        QDomNode itemnode = items.at(i);

        //convert to element
        if(itemnode.isElement()) {
            QDomElement itemele = itemnode.toElement();
            qDebug() << itemele.attribute(attribute);
        }
    }

}

QString KoAgrXML::getElement(QDomDocument root, QString tagname)
{
    QDomNodeList items = root.elementsByTagName(tagname);
    QDomNode itemnode = items.at(0);
    if( itemnode.isElement()) {
        QDomElement itemelement = itemnode.toElement();
        return itemelement.attribute(QString("Value"));
    } else return QString("");
}

void KoAgrXML::setElement(QDomDocument root, QString tagname, QString value)
{
    QDomNodeList items = root.elementsByTagName(tagname);
    QDomNode itemnode = items.at(0);
    if( itemnode.isElement()) {
        QDomElement itemelement = itemnode.toElement();
        itemelement.setAttribute(QString("Value"), value);
    }
}

TestKo1::TestKo1()
{
    document = KoAgrXML::openTestKo1();
}

TestKo1::~TestKo1()
{
    KoAgrXML::closeTestKo1(document);
    qDebug() << "TestKo1::~TestKo1()";
}

void TestKo1::setK1(int k)
{
    KoAgrXML::setElement(document, QString("k1"), QString("%1").arg(k));
}

int TestKo1::getK1()
{
    QString value = KoAgrXML::getElement(document, QString("k1"));
    return value.toInt();
}

void TestKo1::setK2(int k)
{
    KoAgrXML::setElement(document, QString("k2"), QString("%1").arg(k));
}

int TestKo1::getK2()
{
    QString value = KoAgrXML::getElement(document, QString("k2"));
    return value.toInt();
}

void TestKo1::setK3(int k)
{
    KoAgrXML::setElement(document, QString("k3"), QString("%1").arg(k));
}

int TestKo1::getK3()
{
    QString value = KoAgrXML::getElement(document, QString("k3"));
    return value.toInt();
}

void TestKo1::setK4(int k)
{
    KoAgrXML::setElement(document, QString("k4"), QString("%1").arg(k));
}

int TestKo1::getK4()
{
    QString value = KoAgrXML::getElement(document, QString("k4"));
    return value.toInt();
}

void TestKo1::setSingle(int k)
{
    KoAgrXML::setElement(document, QString("single"), QString("%1").arg(k));
}

int TestKo1::getSingle()
{
    QString value = KoAgrXML::getElement(document, QString("single"));
    return value.toInt();
}

QString TestKo1::getText()
{
    return document.toString();
}
