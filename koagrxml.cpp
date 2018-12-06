#include "koagrxml.h"

CreateKoAgr::CreateKoAgr(QObject *parent) : QObject(parent)
{

}

QDomDocument CreateKoAgr::createTestKo(QString name) {

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

QDomDocument CreateKoAgr::createTestAgr(QString name) {
    QDomDocument document = createTestKo(name);
    QDomElement test = document.firstChildElement(name);
    return document;
}

int CreateKoAgr::writeFile(QString name, QDomDocument doc)
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

int CreateKoAgr::readFile(QString name, QDomDocument &doc)
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

KoAgrXML::KoAgrXML(QObject *parent) : CreateKoAgr(parent)
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

QDomDocument KoAgrXML::createCalibrationKo1()
{
    QString name("calibrationKo1");
    QDomDocument document;
    QDomElement calibration = document.createElement(name);
    document.appendChild(calibration);
    calibration.appendChild(document.createElement("date"));
    calibration.appendChild(document.createElement("reagent_serial"));
    calibration.appendChild(document.createElement("reagent_date"));

    calibration.appendChild(document.createElement("write_time"));
    calibration.appendChild(document.createElement("incube_time"));

    writeFile(name, document);
    return document;
}

QDomDocument KoAgrXML::createCalibrationKo2()
{
    QString name("calibrationKo2");
    QDomDocument document;
    QDomElement calibration = document.createElement(name);
    document.appendChild(calibration);
    calibration.appendChild(document.createElement("date"));
    calibration.appendChild(document.createElement("reagent_serial"));
    calibration.appendChild(document.createElement("reagent_date"));
    calibration.appendChild(document.createElement("k_plazma_serial"));
    calibration.appendChild(document.createElement("k_plazma_date"));
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
    calibration.appendChild(document.createElement("date"));
    calibration.appendChild(document.createElement("reagent_serial"));
    calibration.appendChild(document.createElement("reagent_date"));
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
    calibration.appendChild(document.createElement("date"));
    calibration.appendChild(document.createElement("reagent_serial"));
    calibration.appendChild(document.createElement("reagent_date"));
    calibration.appendChild(document.createElement("k_plazma_serial"));
    calibration.appendChild(document.createElement("k_plazma_date"));
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
    calibration.appendChild(document.createElement("date"));
    calibration.appendChild(document.createElement("tromboplastin_serial"));
    calibration.appendChild(document.createElement("tromboplastin_date"));
    calibration.appendChild(document.createElement("k_plazma_serial"));
    calibration.appendChild(document.createElement("k_plazma_date"));
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
    calibration.appendChild(document.createElement("date"));
    calibration.appendChild(document.createElement("reagent_serial"));
    calibration.appendChild(document.createElement("reagent_date"));
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
    calibration.appendChild(document.createElement("date"));

    calibration.appendChild(document.createElement("write_time"));
    calibration.appendChild(document.createElement("incube_time"));
    calibration.appendChild(document.createElement("incube_time_2"));

    calibration.appendChild(document.createElement("reagent_serial"));
    calibration.appendChild(document.createElement("reagent_date"));
    calibration.appendChild(document.createElement("k_plazma_serial"));
    calibration.appendChild(document.createElement("k_plazma_date"));
    calibration.appendChild(document.createElement("k_plazma"));
    //выходные данные
    calibration.appendChild(document.createElement("level_0"));
    calibration.appendChild(document.createElement("level_100"));

    calibration.appendChild(document.createElement("c1"));
    calibration.appendChild(document.createElement("ck1"));

    calibration.appendChild(document.createElement("c2"));
    calibration.appendChild(document.createElement("ck2"));

    calibration.appendChild(document.createElement("c3"));
    calibration.appendChild(document.createElement("ck3"));

    calibration.appendChild(document.createElement("c4"));
    calibration.appendChild(document.createElement("ck4"));

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

QDomDocument KoAgrXML::openCalibrationKo1()
{
    QDomDocument doc;
    QString name("calibrationKo1");
    if( QFile::exists(name + QString(".xml")) ) {
        readFile(name, doc);
    }
    else doc = createCalibrationKo1();
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

void KoAgrXML::setElement(QDomDocument &root, QString tagname, QString value)
{
    QDomNodeList items = root.elementsByTagName(tagname);
    QDomNode itemnode = items.at(0);
    if( itemnode.isElement()) {
        QDomElement itemelement = itemnode.toElement();
        itemelement.setAttribute(QString("Value"), value);
    }
}

Test::Test(QObject *parent)
    : QObject(parent), name("none")
{
    //document = KoAgrXML::openTest();
}

Test::~Test()
{
    qDebug() << "TestKo1::~TestKo1()";
}

void Test::setK1(const int k)
{
    KoAgrXML::setElement(document, QString("k1"), QString("%1").arg(k));
    CreateKoAgr::writeFile(name, document);
}

int Test::getK1() const
{
    QString value = KoAgrXML::getElement(document, QString("k1"));
    return value.toInt();
}

void Test::setK2(const int k)
{
    KoAgrXML::setElement(document, QString("k2"), QString("%1").arg(k));
    CreateKoAgr::writeFile(name, document);
}

int Test::getK2() const
{
    QString value = KoAgrXML::getElement(document, QString("k2"));
    return value.toInt();
}

void Test::setK3(const int k)
{
    KoAgrXML::setElement(document, QString("k3"), QString("%1").arg(k));
    CreateKoAgr::writeFile(name, document);
}

int Test::getK3() const
{
    QString value = KoAgrXML::getElement(document, QString("k3"));
    return value.toInt();
}

void Test::setK4(const int k)
{
    KoAgrXML::setElement(document, QString("k4"), QString("%1").arg(k));
    CreateKoAgr::writeFile(name, document);
}

int Test::getK4() const
{
    QString value = KoAgrXML::getElement(document, QString("k4"));
    return value.toInt();
}

void Test::setSingle(const int k)
{
    KoAgrXML::setElement(document, QString("single"), QString("%1").arg(k));
    CreateKoAgr::writeFile(name, document);
}

int Test::getSingle() const
{
    QString value = KoAgrXML::getElement(document, QString("single"));
    return value.toInt();
}

QString Test::getText() const
{
    return document.toString();
}

void Test::setDoc(const QDomDocument doc)
{
    document = doc;
}

void Test::setName(const QString n)
{
    name = n;
}


TestKo1::TestKo1(QObject *parent) : Test(parent)
{
    Test::setDoc(KoAgrXML::createTestKo1());
    Test::setName("testKo1");
}

TestKo1::~TestKo1()
{

}

TestKo2::TestKo2(QObject *parent) : Test(parent)
{
    Test::setDoc(KoAgrXML::createTestKo2());
    Test::setName("testKo2");
}

TestKo2::~TestKo2()
{

}

TestKo3::TestKo3(QObject *parent) : Test(parent)
{
    Test::setDoc(KoAgrXML::createTestKo3());
    Test::setName("testKo3");
}

TestKo3::~TestKo3()
{

}

TestKo4::TestKo4(QObject *parent) : Test(parent)
{
    Test::setDoc(KoAgrXML::createTestKo4());
    Test::setName("testKo4");
}

TestKo4::~TestKo4()
{

}

TestKo5::TestKo5(QObject *parent) : Test(parent)
{
    Test::setDoc(KoAgrXML::createTestKo5());
    Test::setName("testKo5");
}

TestKo5::~TestKo5()
{

}

TestAgr1::TestAgr1(QObject *parent) : Test(parent)
{
    Test::setDoc(KoAgrXML::createTestAgr1());
    Test::setName("testAgr1");
}

TestAgr1::~TestAgr1()
{

}

TestAgr2::TestAgr2(QObject *parent) : Test(parent)
{
    Test::setDoc(KoAgrXML::createTestAgr2());
    Test::setName("testAgr2");
}

TestAgr2::~TestAgr2()
{

}

Calibration::Calibration(QObject *parent) : QObject(parent)
{

}

Calibration::~Calibration()
{

}

QDate Calibration::getDate() const
{
    return date;
}

void Calibration::setDate(const QDate &value)
{
    date = value;
}

int Calibration::getWrite_time() const
{
    return write_time;
}

void Calibration::setWrite_time(const int value)
{
//    KoAgrXML::setElement(document, QString("incube_time"), QString("%1").arg(value));
//    CreateKoAgr::writeFile(name, document);
}

int Calibration::getIncube_time() const
{

    return incube_time;
}

void Calibration::setIncube_time(int value)
{
    incube_time = value;
}

void Calibration::setDoc(const QDomDocument doc)
{
    document = doc;
}

void Calibration::setName(const QString n)
{
    name = n;
}

CalibrationKo1::CalibrationKo1()
{
    Calibration::setDoc(KoAgrXML::createCalibrationKo1());
    Calibration::setName("calibrationKo1");
}

CalibrationKo1::~CalibrationKo1()
{

}

CalibrationKo2::CalibrationKo2()
{
    Calibration::setDoc(KoAgrXML::createCalibrationKo2());
    Calibration::setName("calibrationKo2");
}

CalibrationKo2::~CalibrationKo2()
{

}

QDate CalibrationKo2::getReaget_date() const
{
    return reaget_date;
}

void CalibrationKo2::setReaget_date(const QDate &value)
{
    reaget_date = value;
}

QDate CalibrationKo2::getK_plazma_date() const
{
    return k_plazma_date;
}

void CalibrationKo2::setK_plazma_date(const QDate &value)
{
    k_plazma_date = value;
}

QString CalibrationKo2::getReagent_serial() const
{
    return reagent_serial;
}

void CalibrationKo2::setReagent_serial(const QString &value)
{
    reagent_serial = value;
}

QString CalibrationKo2::getK_plazma_serial() const
{
    return k_plazma_serial;
}

void CalibrationKo2::setK_plazma_serial(const QString &value)
{
    k_plazma_serial = value;
}

double CalibrationKo2::getA4tv_k_plazma() const
{
    return a4tv_k_plazma;
}

void CalibrationKo2::setA4tv_k_plazma(double value)
{
    a4tv_k_plazma = value;
}

CalibrationKo3::CalibrationKo3()
{

}

CalibrationKo3::~CalibrationKo3()
{

}

QDate CalibrationKo3::getReagent_date() const
{
    return reagent_date;
}

void CalibrationKo3::setReagent_date(const QDate &value)
{
    reagent_date = value;
}

QString CalibrationKo3::getReagent_serial() const
{
    return reagent_serial;
}

void CalibrationKo3::setReagent_serial(const QString &value)
{
    reagent_serial = value;
}

double CalibrationKo3::getFibrinogen_k_plazma() const
{
    return fibrinogen_k_plazma;
}

void CalibrationKo3::setFibrinogen_k_plazma(double value)
{
    fibrinogen_k_plazma = value;
}

double CalibrationKo3::getTime_k_plazma() const
{
    return time_k_plazma;
}

void CalibrationKo3::setTime_k_plazma(double value)
{
    time_k_plazma = value;
}

double CalibrationKo3::getFibrinogen_200_plazma() const
{
    return fibrinogen_200_plazma;
}

void CalibrationKo3::setFibrinogen_200_plazma(double value)
{
    fibrinogen_200_plazma = value;
}

double CalibrationKo3::getTime_200_plazma() const
{
    return time_200_plazma;
}

void CalibrationKo3::setTime_200_plazma(double value)
{
    time_200_plazma = value;
}

double CalibrationKo3::getFibrinogen_50_plazma() const
{
    return fibrinogen_50_plazma;
}

void CalibrationKo3::setFibrinogen_50_plazma(double value)
{
    fibrinogen_50_plazma = value;
}

double CalibrationKo3::getTime_50_plazma() const
{
    return time_50_plazma;
}

void CalibrationKo3::setTime_50_plazma(double value)
{
    time_50_plazma = value;
}

double CalibrationKo3::getFibrinogen_25_plazma() const
{
    return fibrinogen_25_plazma;
}

void CalibrationKo3::setFibrinogen_25_plazma(double value)
{
    fibrinogen_25_plazma = value;
}

double CalibrationKo3::getTime_25_plazma() const
{
    return time_25_plazma;
}

void CalibrationKo3::setTime_25_plazma(double value)
{
    time_25_plazma = value;
}

CalibrationKo4::CalibrationKo4()
{

}

CalibrationKo4::~CalibrationKo4()
{

}

QDate CalibrationKo4::getReagent_date() const
{
    return reagent_date;
}

void CalibrationKo4::setReagent_date(const QDate &value)
{
    reagent_date = value;
}

QDate CalibrationKo4::getK_plazma_date() const
{
    return k_plazma_date;
}

void CalibrationKo4::setK_plazma_date(const QDate &value)
{
    k_plazma_date = value;
}

QString CalibrationKo4::getReagent_serial() const
{
    return reagent_serial;
}

void CalibrationKo4::setReagent_serial(const QString &value)
{
    reagent_serial = value;
}

QString CalibrationKo4::getK_plazma_serial() const
{
    return k_plazma_serial;
}

void CalibrationKo4::setK_plazma_serial(const QString &value)
{
    k_plazma_serial = value;
}

QString CalibrationKo4::getAction() const
{
    return action;
}

void CalibrationKo4::setAction(const QString &value)
{
    action = value;
}

double CalibrationKo4::getTrombine_time() const
{
    return trombine_time;
}

void CalibrationKo4::setTrombine_time(double value)
{
    trombine_time = value;
}

CalibrationKo5::CalibrationKo5()
{

}

CalibrationKo5::~CalibrationKo5()
{

}

QDate CalibrationKo5::getTromboplastin_date() const
{
    return tromboplastin_date;
}

void CalibrationKo5::setTromboplastin_date(const QDate &value)
{
    tromboplastin_date = value;
}

QDate CalibrationKo5::getK_plazma_date() const
{
    return k_plazma_date;
}

void CalibrationKo5::setK_plazma_date(const QDate &value)
{
    k_plazma_date = value;
}

QString CalibrationKo5::getTromboplastin_serial() const
{
    return tromboplastin_serial;
}

void CalibrationKo5::setTromboplastin_serial(const QString &value)
{
    tromboplastin_serial = value;
}

QString CalibrationKo5::getK_plazma_serial() const
{
    return k_plazma_serial;
}

void CalibrationKo5::setK_plazma_serial(const QString &value)
{
    k_plazma_serial = value;
}

double CalibrationKo5::getK_protrombine_index() const
{
    return k_protrombine_index;
}

void CalibrationKo5::setK_protrombine_index(double value)
{
    k_protrombine_index = value;
}

double CalibrationKo5::getK_protrombine_otn() const
{
    return k_protrombine_otn;
}

void CalibrationKo5::setK_protrombine_otn(double value)
{
    k_protrombine_otn = value;
}

double CalibrationKo5::getProtrombine_k_Kvik() const
{
    return protrombine_k_Kvik;
}

void CalibrationKo5::setProtrombine_k_Kvik(double value)
{
    protrombine_k_Kvik = value;
}

double CalibrationKo5::getTime_k_Kvik() const
{
    return time_k_Kvik;
}

void CalibrationKo5::setTime_k_Kvik(double value)
{
    time_k_Kvik = value;
}

double CalibrationKo5::getProtrombine_50_Kvik() const
{
    return protrombine_50_Kvik;
}

void CalibrationKo5::setProtrombine_50_Kvik(double value)
{
    protrombine_50_Kvik = value;
}

double CalibrationKo5::getTime_50_Kvik() const
{
    return time_50_Kvik;
}

void CalibrationKo5::setTime_50_Kvik(double value)
{
    time_50_Kvik = value;
}

double CalibrationKo5::getProtrombine_25_Kvik() const
{
    return protrombine_25_Kvik;
}

void CalibrationKo5::setProtrombine_25_Kvik(double value)
{
    protrombine_25_Kvik = value;
}

double CalibrationKo5::getTime_25_Kvik() const
{
    return time_25_Kvik;
}

void CalibrationKo5::setTime_25_Kvik(double value)
{
    time_25_Kvik = value;
}

double CalibrationKo5::getProtrombine_12_Kvik() const
{
    return protrombine_12_Kvik;
}

void CalibrationKo5::setProtrombine_12_Kvik(double value)
{
    protrombine_12_Kvik = value;
}

double CalibrationKo5::getTime_12_Kvik() const
{
    return time_12_Kvik;
}

void CalibrationKo5::setTime_12_Kvik(double value)
{
    time_12_Kvik = value;
}

double CalibrationKo5::getProtrombine_index() const
{
    return protrombine_index;
}

void CalibrationKo5::setProtrombine_index(double value)
{
    protrombine_index = value;
}

double CalibrationKo5::getProtrombine_otn() const
{
    return protrombine_otn;
}

void CalibrationKo5::setProtrombine_otn(double value)
{
    protrombine_otn = value;
}

CalibrationAgr1::CalibrationAgr1()
{

}

CalibrationAgr1::~CalibrationAgr1()
{

}

QDate CalibrationAgr1::getReagent_date() const
{
    return reagent_date;
}

void CalibrationAgr1::setReagent_date(const QDate &value)
{
    reagent_date = value;
}

QString CalibrationAgr1::getReagent_serial() const
{
    return reagent_serial;
}

void CalibrationAgr1::setReagent_serial(const QString &value)
{
    reagent_serial = value;
}

double CalibrationAgr1::getK_concentration() const
{
    return k_concentration;
}

void CalibrationAgr1::setK_concentration(double value)
{
    k_concentration = value;
}

double CalibrationAgr1::getLevel_0() const
{
    return level_0;
}

void CalibrationAgr1::setLevel_0(double value)
{
    level_0 = value;
}

double CalibrationAgr1::getLevel_100() const
{
    return level_100;
}

void CalibrationAgr1::setLevel_100(double value)
{
    level_100 = value;
}

CalibrationAgr2::CalibrationAgr2()
{

}

CalibrationAgr2::~CalibrationAgr2()
{

}

QDate CalibrationAgr2::getReagent_date() const
{
    return reagent_date;
}

void CalibrationAgr2::setReagent_date(const QDate &value)
{
    reagent_date = value;
}

QDate CalibrationAgr2::getK_plazma_date() const
{
    return k_plazma_date;
}

void CalibrationAgr2::setK_plazma_date(const QDate &value)
{
    k_plazma_date = value;
}

int CalibrationAgr2::getIncube_time_1() const
{
    return incube_time_1;
}

void CalibrationAgr2::setIncube_time_1(int value)
{
    incube_time_1 = value;
}

int CalibrationAgr2::getIncube_time_2() const
{
    return incube_time_2;
}

void CalibrationAgr2::setIncube_time_2(int value)
{
    incube_time_2 = value;
}

QString CalibrationAgr2::getReagent_serial() const
{
    return reagent_serial;
}

void CalibrationAgr2::setReagent_serial(const QString &value)
{
    reagent_serial = value;
}

QString CalibrationAgr2::getK_plazma_serial() const
{
    return k_plazma_serial;
}

void CalibrationAgr2::setK_plazma_serial(const QString &value)
{
    k_plazma_serial = value;
}

double CalibrationAgr2::getK_plazma() const
{
    return k_plazma;
}

void CalibrationAgr2::setK_plazma(double value)
{
    k_plazma = value;
}

double CalibrationAgr2::getLevel_0() const
{
    return level_0;
}

void CalibrationAgr2::setLevel_0(double value)
{
    level_0 = value;
}

double CalibrationAgr2::getLevel_100() const
{
    return level_100;
}

void CalibrationAgr2::setLevel_100(double value)
{
    level_100 = value;
}

double CalibrationAgr2::getC1() const
{
    return c1;
}

void CalibrationAgr2::setC1(double value)
{
    c1 = value;
}

double CalibrationAgr2::getCk1() const
{
    return ck1;
}

void CalibrationAgr2::setCk1(double value)
{
    ck1 = value;
}

double CalibrationAgr2::getC2() const
{
    return c2;
}

void CalibrationAgr2::setC2(double value)
{
    c2 = value;
}

double CalibrationAgr2::getCk2() const
{
    return ck2;
}

void CalibrationAgr2::setCk2(double value)
{
    ck2 = value;
}

double CalibrationAgr2::getC3() const
{
    return c3;
}

void CalibrationAgr2::setC3(double value)
{
    c3 = value;
}

double CalibrationAgr2::getCk3() const
{
    return ck3;
}

void CalibrationAgr2::setCk3(double value)
{
    ck3 = value;
}

double CalibrationAgr2::getC4() const
{
    return c4;
}

void CalibrationAgr2::setC4(double value)
{
    c4 = value;
}

double CalibrationAgr2::getCk4() const
{
    return ck4;
}

void CalibrationAgr2::setCk4(double value)
{
    ck4 = value;
}
