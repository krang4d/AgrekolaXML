#include "koagrxml.h"

QDomDocument CreateKoAgr::createTest(QString name) {

    QDomDocument document;
    QDomElement test = document.createElement(name);
    document.appendChild(test);

    QDomElement k1 = document.createElement("k1");
    k1.setAttribute("Value", "1");
    k1.setAttribute("Num", "num1");
    test.appendChild(k1);

    QDomElement k2 = document.createElement("k2");
    k2.setAttribute("Value", "1");
    k2.setAttribute("Num", "num2");
    test.appendChild(k2);

    QDomElement k3 = document.createElement("k3");
    k3.setAttribute("Value", "1");
    k3.setAttribute("Num", "num3");
    test.appendChild(k3);

    QDomElement k4 = document.createElement("k4");
    k4.setAttribute("Value", "1");
    k4.setAttribute("Num", "num4");
    test.appendChild(k4);

    QDomElement single = document.createElement("single");
    single.setAttribute("Value", "1");
    test.appendChild(single);

    return document;
}

//QDomDocument CreateKoAgr::createTestAgr(QString name) {
//    QDomDocument document = createTestKo(name);
//    QDomElement test = document.firstChildElement(name);
//    return document;
//}

QDomDocument CreateKoAgr::createCalibration(QString name)
{
    QDomDocument document;
    QDomElement calibration = document.createElement(name);
    calibration.appendChild(document.createElement("k1"));
    calibration.appendChild(document.createElement("k2"));
    calibration.appendChild(document.createElement("k3"));
    calibration.appendChild(document.createElement("k4"));
    document.appendChild(calibration);

    return document;
}

int CreateKoAgr::writeFile(QString name, QDomDocument doc)
{
//    QDir cur_dir = QDir::current();
//    qDebug() << "cur_dir at start" << cur_dir.path();
//    QDir xml_dir = getXMLDir();
//    QDir::setCurrent(xml_dir.path());
//    qDebug() << "KoAgrXML::openTestKo1() cur_dir" << QDir::currentPath() << "xml_dir.dirName()" << xml_dir.path();
    QFile file(name + QString(".xml"));
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Faild to open file for write";
        //QDir::setCurrent(cur_dir.path());
        return -1;
    } else {
        QTextStream stream(&file);
        stream << doc.toString();
        file.close();
    }
    //QDir::setCurrent(cur_dir.path());
    file.close();
    return 0;
}

int CreateKoAgr::readFile(QString name, QDomDocument &doc)
{
    //QDir cur_dir = QDir::current();
    //qDebug() << "cur_dir at start" << cur_dir.path();
    //QDir xml_dir = getXMLDir();
    //QDir::setCurrent(xml_dir.path());
    //qDebug() << "KoAgrXML::openTestKo1() cur_dir" << QDir::currentPath() << "xml_dir.dirName()" << xml_dir.path();
    //dir.dirName();
    QFile file(name + QString(".xml"));
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Faild to open file for read";
        //QDir::setCurrent(cur_dir.path());
        return -1;
    } else {
        if(!doc.setContent(&file)) {
            qDebug() << "Failed to load document";
            //QDir::setCurrent(cur_dir.path());
            return -2;
        }
        file.close();
    }
    file.close();
    //QDir::setCurrent(cur_dir.path());
    //qDebug() << "cur_dir at stop" << cur_dir.path();
    return 0;
}

QDir CreateKoAgr::getXMLDir()
{
    QDir dir;
    QString path = QDir::homePath();
    dir.cd(path); //переходим в папку home
    if(!dir.cd("Agrekola4k"))
    {
        if(dir.mkdir("Agrekola4k")) dir.cd("Agrekola4k");
        //QDir::setCurrent(dir.path());
        qDebug() << "mkdir(Agrekola4k)";
    }
    if(!dir.cd("XML"))
    {
        if(dir.mkdir("XML")) dir.cd("XML");
        qDebug() << "mkdir(XML)";
    }
    return dir;
}

//QDomDocument KoAgrXML::createTestKo1()
//{
//    QString name("testKo1");
//    QDomDocument document = createTest(name);
//    writeFile(name, document);
//    return document;
//}

//QDomDocument KoAgrXML::createTestKo2()
//{
//    QString name("testKo2");
//    QDomDocument document = createTest(name);
//    writeFile(name, document);
//    return document;
//}

//QDomDocument KoAgrXML::createTestKo3()
//{
//    QString name("testKo3");
//    QDomDocument document = createTest(name);
//    writeFile(name, document);
//    return document;
//}

//QDomDocument KoAgrXML::createTestKo4()
//{
//    QString name("testKo4");
//    QDomDocument document = createTest(name);
//    writeFile(name, document);
//    return document;
//}

//QDomDocument KoAgrXML::createTestKo5()
//{
//    QString name("testKo5");
//    QDomDocument document = createTest(name);
//    writeFile(name, document);
//    return document;
//}

//QDomDocument KoAgrXML::createTestAgr1()
//{
//    QString name("testAgr1");
//    QDomDocument document = createTest(name);
//    writeFile(name, document);
//    return document;
//}

//QDomDocument KoAgrXML::createTestAgr2()
//{
//    QString name("testAgr2");
//    QDomDocument document = createTest(name);
//    writeFile(name, document);
//    return document;
//}

//QDomDocument KoAgrXML::createCalibrationKo1()
//{
//    QString name("calibrationKo1");
//    QDomDocument document = createCalibration(name);
//    QDomElement calibration = document.firstChildElement();
//    calibration.appendChild(document.createElement("date"));
//    calibration.appendChild(document.createElement("reagent_serial"));
//    calibration.appendChild(document.createElement("reagent_date"));

//    QDomElement write_time = document.createElement("write_time");
//    write_time.setAttribute("Value", "10");
//    calibration.appendChild(write_time);

//    QDomElement incube_time = document.createElement("incube_time");
//    incube_time.setAttribute("Value", "3");
//    calibration.appendChild(incube_time);

//    writeFile(name, document);
//    return document;
//}

//QDomDocument KoAgrXML::createCalibrationKo2()
//{
//    QString name("calibrationKo2");
//    QDomDocument document = createCalibration(name);
//    QDomElement calibration = document.firstChildElement();
//    calibration.appendChild(document.createElement("date"));
//    calibration.appendChild(document.createElement("reagent_serial"));
//    calibration.appendChild(document.createElement("reagent_date"));
//    calibration.appendChild(document.createElement("k_plazma_serial"));
//    calibration.appendChild(document.createElement("k_plazma_date"));

//    QDomElement a4tv = document.createElement("a4tv_kp1");
//    a4tv.setAttribute("Value", "0");
//    calibration.appendChild(a4tv);

//    a4tv = document.createElement("a4tv_kp2");
//    a4tv.setAttribute("Value", "0");
//    calibration.appendChild(a4tv);

//    a4tv = document.createElement("a4tv_kp3");
//    a4tv.setAttribute("Value", "0");
//    calibration.appendChild(a4tv);

//    a4tv = document.createElement("a4tv_kp4");
//    a4tv.setAttribute("Value", "0");
//    calibration.appendChild(a4tv);

//    calibration.appendChild(document.createElement("write_time"));
//    calibration.appendChild(document.createElement("incube_time"));

//    writeFile(name, document);
//    return document;
//}

//QDomDocument KoAgrXML::createCalibrationKo3()
//{
//    QString name("calibrationKo3");
//    QDomDocument document = createCalibration(name);
//    QDomElement calibration = document.firstChildElement();
//    calibration.appendChild(document.createElement("date"));
//    calibration.appendChild(document.createElement("reagent_serial"));
//    calibration.appendChild(document.createElement("reagent_date"));
//    calibration.appendChild(document.createElement("k_plazma_serial"));
//    calibration.appendChild(document.createElement("k_plazma_date"));
//    calibration.appendChild(document.createElement("fibrinogen_k_plazma"));
//    calibration.appendChild(document.createElement("time_k_plazma"));
//    calibration.appendChild(document.createElement("fibrinogen_200_plazma"));
//    calibration.appendChild(document.createElement("time_200_plazma"));
//    calibration.appendChild(document.createElement("fibrinogen_50_plazma"));
//    calibration.appendChild(document.createElement("time_50_plazma"));
//    calibration.appendChild(document.createElement("fibrinogen_25_plazma"));
//    calibration.appendChild(document.createElement("time_25_plazma"));

//    calibration.appendChild(document.createElement("write_time"));
//    calibration.appendChild(document.createElement("incube_time"));

//    writeFile(name, document);
//    return document;
//}

//QDomDocument KoAgrXML::createCalibrationKo4()
//{
//    QString name("calibrationKo4");
//    QDomDocument document = createCalibration(name);
//    QDomElement calibration = document.firstChildElement();
//    calibration.appendChild(document.createElement("date"));
//    calibration.appendChild(document.createElement("reagent_serial"));
//    calibration.appendChild(document.createElement("reagent_date"));
//    calibration.appendChild(document.createElement("k_plazma_serial"));
//    calibration.appendChild(document.createElement("k_plazma_date"));
//    calibration.appendChild(document.createElement("action"));
//    calibration.appendChild(document.createElement("tv1_concentration"));
//    calibration.appendChild(document.createElement("tv1_time"));
//    calibration.appendChild(document.createElement("tv2_concentration"));
//    calibration.appendChild(document.createElement("tv2_time"));
//    calibration.appendChild(document.createElement("tv3_concentration"));
//    calibration.appendChild(document.createElement("tv3_time"));
//    calibration.appendChild(document.createElement("write_time"));
//    calibration.appendChild(document.createElement("incube_time"));

//    writeFile(name, document);
//    return document;
//}

//QDomDocument KoAgrXML::createCalibrationKo5()
//{
//    QString name("calibrationKo5");
//    QDomDocument document = createCalibration(name);
//    QDomElement calibration = document.firstChildElement();
//    calibration.appendChild(document.createElement("date"));
//    calibration.appendChild(document.createElement("reagent_date"));
//    calibration.appendChild(document.createElement("reagent_serial"));
//    calibration.appendChild(document.createElement("tromboplastin_serial"));
//    calibration.appendChild(document.createElement("tromboplastin_date"));
//    calibration.appendChild(document.createElement("k_plazma_serial"));
//    calibration.appendChild(document.createElement("k_plazma_date"));
//    calibration.appendChild(document.createElement("k_protrombine_index"));
//    calibration.appendChild(document.createElement("k_protrombine_otn"));
//    calibration.appendChild(document.createElement("protrombine_k_Kvik"));
//    calibration.appendChild(document.createElement("time_k_Kvik"));

//    calibration.appendChild(document.createElement("protrombine_50_Kvik"));
//    calibration.appendChild(document.createElement("time_50_Kvik"));

//    calibration.appendChild(document.createElement("protrombine_25_Kvik"));
//    calibration.appendChild(document.createElement("time_25_Kvik"));

//    calibration.appendChild(document.createElement("protrombine_12_Kvik"));
//    calibration.appendChild(document.createElement("time_12_Kvik"));

//    calibration.appendChild(document.createElement("protrombine_index"));
//    calibration.appendChild(document.createElement("protrombine_otn"));

//    calibration.appendChild(document.createElement("write_time"));
//    calibration.appendChild(document.createElement("incube_time"));

//    writeFile(name, document);
//    return document;
//}

//QDomDocument KoAgrXML::createCalibrationAgr1()
//{
//    qDebug() << "QDomDocument KoAgrXML::createCalibrationAgr1()";
//    QString name("calibrationAgr1");
//    QDomDocument document = createCalibration(name);
//    QDomElement calibration = document.firstChildElement();
//    //входные данные
//    calibration.appendChild(document.createElement("date"));
//    calibration.appendChild(document.createElement("reagent_serial"));
//    calibration.appendChild(document.createElement("reagent_date"));
//    calibration.appendChild(document.createElement("k_concentration"));

//    calibration.appendChild(document.createElement("write_time"));
//    calibration.appendChild(document.createElement("incube_time"));
//    calibration.appendChild(document.createElement("incube_time_2"));
//    //выходные данные
//    calibration.appendChild(document.createElement("level_0"));
//    calibration.appendChild(document.createElement("level_100"));

//    writeFile(name, document);
//    return document;
//}

//QDomDocument KoAgrXML::createCalibrationAgr2()
//{
//    QString name("calibrationAgr2");
//    QDomDocument document = createCalibration(name);
//    QDomElement calibration = document.firstChildElement();
//    //входные данные
//    calibration.appendChild(document.createElement("date"));

//    calibration.appendChild(document.createElement("write_time"));
//    calibration.appendChild(document.createElement("incube_time"));
//    calibration.appendChild(document.createElement("incube_time_2"));

//    calibration.appendChild(document.createElement("reagent_serial"));
//    calibration.appendChild(document.createElement("reagent_date"));
//    calibration.appendChild(document.createElement("k_plazma_serial"));
//    calibration.appendChild(document.createElement("k_plazma_date"));
//    calibration.appendChild(document.createElement("k_plazma"));
//    //выходные данные
//    calibration.appendChild(document.createElement("level_0"));
//    calibration.appendChild(document.createElement("level_100"));

//    calibration.appendChild(document.createElement("c1"));
//    calibration.appendChild(document.createElement("ck1"));

//    calibration.appendChild(document.createElement("c2"));
//    calibration.appendChild(document.createElement("ck2"));

//    calibration.appendChild(document.createElement("c3"));
//    calibration.appendChild(document.createElement("ck3"));

//    calibration.appendChild(document.createElement("c4"));
//    calibration.appendChild(document.createElement("ck4"));

//    writeFile(name, document);
//    return document;
//}

//QDomDocument openXML(QString name, std::function<QDomDocument(void)> fun)
//{
//    QDomDocument doc;
//    QDir::setCurrent(CreateKoAgr::getXMLDir().path());
//    if( QFile::exists(name) ) {
//        CreateKoAgr::readFile(name, doc);
//    }
//    else doc = fun();
//    return doc;
//}

//QDomDocument KoAgrXML::openTestKo1()
//{
//    QDomDocument doc;
//    QString name("testKo1");
//    //QDir::setCurrent(getXMLDir().path());
//    if( QFile::exists(name  + QString(".xml")) ) {
//        readFile(name, doc);
//    }
//    else doc = createTestKo1();
//    return doc;
//}

//QDomDocument KoAgrXML::openTestKo2()
//{
//    QDomDocument doc;
//    QString name("testKo2");
//    if( QFile::exists(name + QString(".xml")) ) {
//        readFile(name, doc);
//    }
//    else doc = createTestKo2();
//    return doc;
//}

//QDomDocument KoAgrXML::openTestKo3()
//{
//    QDomDocument doc;
//    QString name("testKo3");
//    if( QFile::exists(name + QString(".xml")) ) {
//        readFile(name, doc);
//    }
//    else doc = createTestKo3();
//    return doc;
//}

//QDomDocument KoAgrXML::openTestKo4()
//{
//    QDomDocument doc;
//    QString name("testKo3");
//    if( QFile::exists(name + QString(".xml")) ) {
//        readFile(name, doc);
//    }
//    else doc = createTestKo4();
//    return doc;
//}

//QDomDocument KoAgrXML::openTestKo5()
//{
//    QDomDocument doc;
//    QString name("testKo5");
//    if( QFile::exists(name + QString(".xml")) ) {
//        readFile(name, doc);
//    }
//    else doc = createTestKo5();
//    return doc;
//}

//QDomDocument KoAgrXML::openTestAgr1()
//{
//    QDomDocument doc;
//    QString name("testAgr1");
//    if( QFile::exists(name + QString(".xml")) ) {
//        readFile(name, doc);
//    }
//    else doc = createTestAgr1();
//    return doc;
//}

//QDomDocument KoAgrXML::openTestAgr2()
//{
//    QDomDocument doc;
//    QString name("testAgr2");
//    if( QFile::exists(name + QString(".xml")) ) {
//        readFile(name, doc);
//    }
//    else doc = createTestAgr2();
//    return doc;
//}

//QDomDocument KoAgrXML::openCalibrationKo1()
//{
//    QDomDocument doc;
//    QString name("calibrationKo1");
//    if( QFile::exists(name + QString(".xml")) ) {
//        readFile(name, doc);
//    }
//    else doc = createCalibrationKo1();
//    return doc;
//}

//QDomDocument KoAgrXML::openCalibrationKo2()
//{
//    QDomDocument doc;
//    QString name("calibrationKo2");
//    if( QFile::exists(name + QString(".xml")) ) {
//        readFile(name, doc);
//    }
//    else doc = createCalibrationKo2();
//    return doc;
//}

//QDomDocument KoAgrXML::openCalibrationKo3()
//{
//    QDomDocument doc;
//    QString name("calibrationKo3");
//    if( QFile::exists(name + QString(".xml")) ) {
//        readFile(name, doc);
//    }
//    else doc = createCalibrationKo3();
//    return doc;
//}

//QDomDocument KoAgrXML::openCalibrationKo4()
//{
//    QDomDocument doc;
//    QString name("calibrationKo4");
//    if( QFile::exists(name + QString(".xml")) ) {
//        readFile(name, doc);
//    }
//    else doc = createCalibrationKo4();
//    return doc;
//}

//QDomDocument KoAgrXML::openCalibrationKo5()
//{
//    QDomDocument doc;
//    QString name("calibrationKo5");
//    if( QFile::exists(name + QString(".xml")) ) {
//        readFile(name, doc);
//    }
//    else doc = createCalibrationKo5();
//    return doc;
//}

//QDomDocument KoAgrXML::openCalibrationAgr1()
//{
//    qDebug() << "QDomDocument KoAgrXML::openCalibrationAgr1() dir: " << QDir::currentPath();
//    QDomDocument doc;
//    QString name("calibrationAgr1");
//    if( QFile::exists(name + QString(".xml")) ) {
//        readFile(name, doc);
//    }
//    else doc = createCalibrationAgr1();
//    return doc;
//}

//QDomDocument KoAgrXML::openCalibrationAgr2()
//{
//    QDomDocument doc;
//    QString name("calibrationAgr2");
//    if( QFile::exists(name + QString(".xml")) ) {
//        readFile(name, doc);
//    }
//    else doc = createCalibrationAgr2();
//    return doc;
//}

Test::Test(QString n, QObject *parent) : QObject(parent)
{
    name = n;

    dir = KoAgrXML::getXMLDir();
    QDir::setCurrent(dir.path());
    qDebug() << "name" << name << "dir" << dir.currentPath();
    load();
    //document = KoAgrXML::openTest();
}

void Test::load()
{
    QDir::setCurrent(dir.path());
    if( QFile::exists(name  + QString(".xml")) ) {
        CreateKoAgr::readFile(name, document);
    }
    else {
        document = CreateKoAgr::createTest(name);
        KoAgrXML::writeFile(name, document);
    }

    QString value;
    value = getElement(document, QString("k1"));
    k1 = value.toInt();

    value = getElement(document, QString("k2"));
    k2 = value.toInt();

    value = getElement(document, QString("k3"));
    k3 = value.toInt();

    value = getElement(document, QString("k4"));
    k4 = value.toInt();

    value = getElement(document, QString("single"));
    single = value.toInt();

    num1 = getElement(document, QString("k1"), "Num");
    num2 = getElement(document, QString("k2"), "Num");
    num3 = getElement(document, QString("k3"), "Num");
    num4 = getElement(document, QString("k4"), "Num");
}

Test::~Test()
{
    qDebug() << name << " ~Test()";
    save();
}

void Test::save()
{
    QDir::setCurrent(dir.path());
    setElement(document, QString("k1"), QString("%1").arg(k1));
    setElement(document, QString("k2"), QString("%1").arg(k2));
    setElement(document, QString("k3"), QString("%1").arg(k3));
    setElement(document, QString("k4"), QString("%1").arg(k4));
    setElement(document, QString("single"), QString("%1").arg(single));

    setElement(document, QString("k1"), num1, "Num");
    setElement(document, QString("k2"), num2, "Num");
    setElement(document, QString("k3"), num3, "Num");
    setElement(document, QString("k4"), num4, "Num");

    CreateKoAgr::writeFile(name, document);
}

void Test::ListElement(QDomElement root, QString tagname, QString attribute)
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

QString Test::getElement(QDomDocument root, QString tagname, QString attribute)
{
    QDomNodeList items = root.elementsByTagName(tagname);
    QDomNode itemnode = items.at(0);
    if( itemnode.isElement()) {
        QDomElement itemelement = itemnode.toElement();
        return itemelement.attribute(attribute);
    } else return QString("");
}

void Test::setElement(QDomDocument &root, QString tagname, QString value, QString attribute)
{
    QDomNodeList items = root.elementsByTagName(tagname);
    QDomNode itemnode = items.at(0);
    if( itemnode.isElement()) {
        QDomElement itemelement = itemnode.toElement();
        itemelement.setAttribute(attribute, value);
    }
}

void Test::setK1(const int value)
{
    k1 = value;
}

int Test::getK1() const
{
    return k1;
}

void Test::setK2(const int value)
{
    k2 = value;
}

int Test::getK2() const
{
    return k2;
}

void Test::setK3(const int value)
{
    k3 = value;
}

int Test::getK3() const
{
    return k3;
}

void Test::setK4(const int value)
{
    k4 = value;
}

int Test::getK4() const
{
    return k4;
}

void Test::setSingle(const int value)
{
    single = value;
}

int Test::getSingle() const
{
    return single;
}

QString Test::getText() const
{
    return document.toString();
}

QDomDocument Test::getDoc() const
{
    return document;
}

QString Test::getName() const
{
    return name;
}

QString Test::getNum4() const
{
    return num4;
}

void Test::setNum4(const QString &value)
{
    num4 = value;
}

QString Test::getNum3() const
{
    return num3;
}

void Test::setNum3(const QString &value)
{
    num3 = value;
}

QString Test::getNum2() const
{
    return num2;
}

void Test::setNum2(const QString &value)
{
    num2 = value;
}

QString Test::getNum1() const
{
    return num1;
}

void Test::setNum1(const QString &value)
{
    num1 = value;
}

TestKo1::TestKo1(QObject *parent)
    : Test("testKo1", parent)
{

}

TestKo1::~TestKo1()
{
    qDebug() << name << " ~TestKo1()";
}

TestKo2::TestKo2(QObject *parent)
    : Test("testKo2", parent)
{}

TestKo2::~TestKo2()
{
    qDebug() << name << " ~TestKo2()";
}

TestKo3::TestKo3(QObject *parent)
    : Test("testKo3", parent)
{

}

TestKo3::~TestKo3()
{
    qDebug() << name << " ~TestKo3()";
}

TestKo4::TestKo4(QObject *parent)
    : Test("testKo4", parent)
{}

TestKo4::~TestKo4()
{
    qDebug() << name << " ~TestKo4()";
}

TestKo5::TestKo5(QObject *parent)
    : Test("testKo5", parent)
{}

TestKo5::~TestKo5()
{
    qDebug() << name << " ~TestKo5()";
}

TestAgr1::TestAgr1(QObject *parent)
    : Test("testAgr1", parent)
{}

TestAgr1::~TestAgr1()
{
    qDebug() << name << " ~TestAgr1()";
}

TestAgr2::TestAgr2(QObject *parent)
    : Test("testAgr2", parent)
{}

TestAgr2::~TestAgr2()
{
    qDebug() << name << " ~TestAgr2()";
}

Calibration::Calibration(QString n, QObject *parent) : QObject(parent)
{
    name = n;
    dir = KoAgrXML::getXMLDir();
    QDir::setCurrent(dir.path());
    qDebug() << "name" << name << "dir" << dir.currentPath();
}

void Calibration::load()
{
    QDir::setCurrent(dir.path());
    QString value;
    value = getElement(document, QString("date"));
    date = QDate::fromString(value, QString("yyyyMMdd"));

    value = getElement(document, QString("write_time"));
    write_time = value.toDouble();

    value = getElement(document, QString("incube_time"));
    incube_time = value.toDouble();

    value = getElement(document, QString("k1"));
    k1  = value.toInt();

    value = getElement(document, QString("k2"));
    k2 = value.toInt();

    value = getElement(document, QString("k3"));
    k3 = value.toInt();

    value = getElement(document, QString("k4"));
    k4 = value.toInt();
}

Calibration::~Calibration()
{
    qDebug() << name << " ~Calibration()";
    save();
}

void Calibration::save()
{
    QDir::setCurrent(dir.path());
    setElement(document, QString("date"), QString("%1").arg(date.toString("yyyyMMdd")));
    setElement(document, QString("write_time"), QString("%1").arg(write_time));
    setElement(document, QString("incube_time"), QString("%1").arg(incube_time));

    setElement(document, QString("k1"), QString("%1").arg(k1));
    setElement(document, QString("k2"), QString("%1").arg(k2));
    setElement(document, QString("k3"), QString("%1").arg(k3));
    setElement(document, QString("k4"), QString("%1").arg(k4));
    CreateKoAgr::writeFile(name, document);
    //qDebug() << "Calibration::save()";
}

void Calibration::ListElement(QDomElement root, QString tagname, QString attribute)
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

QString Calibration::getElement(QDomDocument root, QString tagname, QString attribute)
{
    QDomNodeList items = root.elementsByTagName(tagname);
    QDomNode itemnode = items.at(0);
    if( itemnode.isElement()) {
        QDomElement itemelement = itemnode.toElement();
        return itemelement.attribute(attribute);
    } else return QString("");
}

void Calibration::setElement(QDomDocument &root, QString tagname, QString value, QString attribute)
{
    QDomNodeList items = root.elementsByTagName(tagname);
    QDomNode itemnode = items.at(0);
    if( itemnode.isElement()) {
        QDomElement itemelement = itemnode.toElement();
        itemelement.setAttribute(attribute, value);
    }
}

void Calibration::setIncube_time(double value)
{
    incube_time = value;
}

QDomDocument Calibration::getDoc() const
{
    return document;
}

QString Calibration::getName() const
{
    return name;
}

bool Calibration::getK4() const
{
    return k4;
}

void Calibration::setK4(bool value)
{
    k4 = value;
}

bool Calibration::getK3() const
{
    return k3;
}

void Calibration::setK3(bool value)
{
    k3 = value;
}

bool Calibration::getK2() const
{
    return k2;
}

void Calibration::setK2(bool value)
{
    k2 = value;
}

bool Calibration::getK1() const
{
    return k1;
}

void Calibration::setK1(bool value)
{
    k1 = value;
}

QDate Calibration::getDate() const
{
    return date;
}

void Calibration::setDate(const QDate &value)
{
    date = value;
}

double Calibration::getWrite_time() const
{
    return write_time;
}

void Calibration::setWrite_time(const double value)
{
    write_time = value;
}

double Calibration::getIncube_time() const
{
    return incube_time;
}

CalibrationKo1::CalibrationKo1(QObject *parent) : Calibration("calibrationKo1", parent)
{
    if( QFile::exists(name  + QString(".xml")) ) {
        CreateKoAgr::readFile(name, document);
    }
    else {
        document = CreateKoAgr::createCalibration(name);
        QDomElement calibration = document.firstChildElement();
        calibration.appendChild(document.createElement("date"));
        calibration.appendChild(document.createElement("reagent_serial"));
        calibration.appendChild(document.createElement("reagent_date"));

        QDomElement write_time = document.createElement("write_time");
        write_time.setAttribute("Value", "10");
        calibration.appendChild(write_time);

        QDomElement incube_time = document.createElement("incube_time");
        incube_time.setAttribute("Value", "3");
        calibration.appendChild(incube_time);

        CreateKoAgr::writeFile(name, document);
    }
    load();
}

CalibrationKo1::~CalibrationKo1()
{
    qDebug() << name << "~CalibrationKo1()";
    save();
}

CalibrationKo2::CalibrationKo2(QObject *parent)
    : Calibration("calibrationKo2")
{
    if( QFile::exists(name  + QString(".xml")) ) {
        CreateKoAgr::readFile(name, document);
    }
    else {
        document = CreateKoAgr::createCalibration(name);
        QDomElement calibration = document.firstChildElement();
        calibration.appendChild(document.createElement("date"));
        calibration.appendChild(document.createElement("reagent_serial"));
        calibration.appendChild(document.createElement("reagent_date"));
        calibration.appendChild(document.createElement("k_plazma_serial"));
        calibration.appendChild(document.createElement("k_plazma_date"));
        calibration.appendChild(document.createElement("k_plazma_a4tv"));

        QDomElement a4tv = document.createElement("a4tv_kp1");
        a4tv.setAttribute("Value", "0");
        calibration.appendChild(a4tv);

        a4tv = document.createElement("a4tv_kp2");
        a4tv.setAttribute("Value", "0");
        calibration.appendChild(a4tv);

        a4tv = document.createElement("a4tv_kp3");
        a4tv.setAttribute("Value", "0");
        calibration.appendChild(a4tv);

        a4tv = document.createElement("a4tv_kp4");
        a4tv.setAttribute("Value", "0");
        calibration.appendChild(a4tv);

        calibration.appendChild(document.createElement("write_time"));
        calibration.appendChild(document.createElement("incube_time"));

        CreateKoAgr::writeFile(name, document);
    }
    load();

    //Calibration::setDoc(KoAgrXML::createCalibrationKo2());
    //Calibration::setName("calibrationKo2");
}

void CalibrationKo2::load()
{
    Calibration::load();
    QString value;
    value = getElement(document, QString("reagent_date"));
    reagent_date = QDate::fromString(value, QString("yyyyMMdd"));

    value = getElement(document, QString("reagent_serial"));
    reagent_serial = value.toInt();

    value = getElement(document, QString("k_plazma_date"));
    k_plazma_date = QDate::fromString(value, QString("yyyyMMdd"));

    value = getElement(document, QString("k_plazma_serial"));
    k_plazma_serial = value.toInt();

    value = getElement(document, QString("k_plazma_a4tv"));
    k_plazma_a4tv = value.toDouble();

    value = getElement(document, QString("a4tv_kp1"));
    a4tv_kp1 = value.toDouble();
    value = getElement(document, QString("a4tv_kp2"));
    a4tv_kp2 = value.toDouble();
    value = getElement(document, QString("a4tv_kp3"));
    a4tv_kp3 = value.toDouble();
    value = getElement(document, QString("a4tv_kp4"));
    a4tv_kp4 = value.toDouble();
}

CalibrationKo2::~CalibrationKo2()
{
    qDebug() << name << "~CalibrationKo2()";
    save();
}

void CalibrationKo2::save()
{
    Calibration::save();
    setElement(document, QString("reagent_date"), reagent_date.toString("yyyyMMdd"));
    setElement(document, QString("reagent_serial"), reagent_serial);
    setElement(document, QString("k_plazma_date"), k_plazma_date.toString("yyyyMMdd"));
    setElement(document, QString("k_plazma_serial"), k_plazma_serial);
    setElement(document, QString("k_plazma_a4tv"), QString("%1").arg(k_plazma_a4tv));
    setElement(document, QString("a4tv_kp1"), QString("%1").arg(a4tv_kp1));
    setElement(document, QString("a4tv_kp2"), QString("%1").arg(a4tv_kp2));
    setElement(document, QString("a4tv_kp3"), QString("%1").arg(a4tv_kp3));
    setElement(document, QString("a4tv_kp4"), QString("%1").arg(a4tv_kp4));
    CreateKoAgr::writeFile(name, document);
    //qDebug() << "CalibrationKo2::save()";
}

QDate CalibrationKo2::getReagent_date() const
{
    //QString value = KoAgrXML::getElement(Calibration::getDoc(), QString("reagent_date"));
    return reagent_date;
}

void CalibrationKo2::setReagent_date(const QDate &value)
{
    reagent_date = value;
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

double CalibrationKo2::getA4tv_kp4() const
{
    return a4tv_kp4;
}

void CalibrationKo2::setA4tv_kp4(double value)
{
    a4tv_kp4 = value;
}

double CalibrationKo2::getK_plazma_a4tv() const
{
    return k_plazma_a4tv;
}

void CalibrationKo2::setK_plazma_a4tv(double value)
{
    k_plazma_a4tv = value;
}

double CalibrationKo2::getA4tv_kp3() const
{
    return a4tv_kp3;
}

void CalibrationKo2::setA4tv_kp3(double value)
{
    a4tv_kp3 = value;
}

double CalibrationKo2::getA4tv_kp2() const
{
    return a4tv_kp2;
}

void CalibrationKo2::setA4tv_kp2(double value)
{
    a4tv_kp2 = value;
}

double CalibrationKo2::getA4tv_kp1() const
{
    return a4tv_kp1;
}

void CalibrationKo2::setA4tv_kp1(double value)
{
    a4tv_kp1 = value;
}

CalibrationKo3::CalibrationKo3(QObject *parent)
    : Calibration("calibrationKo3", parent)
{
    if( QFile::exists(name  + QString(".xml")) ) {
        CreateKoAgr::readFile(name, document);
    }
    else {
        document = CreateKoAgr::createCalibration(name);
        QDomElement calibration = document.firstChildElement();
        calibration.appendChild(document.createElement("date"));
        calibration.appendChild(document.createElement("reagent_serial"));
        calibration.appendChild(document.createElement("reagent_date"));
        calibration.appendChild(document.createElement("k_plazma_serial"));
        calibration.appendChild(document.createElement("k_plazma_date"));
        calibration.appendChild(document.createElement("fibrinogen_k_plazma"));
        calibration.appendChild(document.createElement("time_k_plazma"));
        calibration.appendChild(document.createElement("fibrinogen_200_plazma"));
        calibration.appendChild(document.createElement("time_200_plazma"));
        calibration.appendChild(document.createElement("fibrinogen_50_plazma"));
        calibration.appendChild(document.createElement("time_50_plazma"));
        calibration.appendChild(document.createElement("fibrinogen_25_plazma"));
        calibration.appendChild(document.createElement("time_25_plazma"));

        QDomElement write_time = document.createElement("write_time");
        write_time.setAttribute("Value", "10");
        calibration.appendChild(write_time);

        QDomElement incube_time = document.createElement("incube_time");
        incube_time.setAttribute("Value", "3");
        calibration.appendChild(incube_time);

        CreateKoAgr::writeFile(name, document);
    }
    load();
}

void CalibrationKo3::load()
{
    Calibration::load();
    QString value;
    value = getElement(document, QString("reagent_date"));
    reagent_date = QDate::fromString(value, QString("yyyyMMdd"));

    value = getElement(document, QString("reagent_serial"));
    reagent_serial = value;

    value = getElement(document, QString("fibrinogen_k_plazma"));
    fibrinogen_k_plazma = value.toDouble();

    value = getElement(document, QString("time_k_plazma"));
    time_k_plazma = value.toDouble();

    value = getElement(document, QString("fibrinogen_200_plazma"));
    fibrinogen_200_plazma = value.toDouble();

    value = getElement(document, QString("time_200_plazma"));
    time_200_plazma = value.toDouble();

    value = getElement(document, QString("fibrinogen_50_plazma"));
    fibrinogen_50_plazma = value.toDouble();

    value = getElement(document, QString("time_50_plazma"));
    time_50_plazma = value.toDouble();

    value = getElement(document, QString("fibrinogen_25_plazma"));
    fibrinogen_25_plazma = value.toDouble();

    value = getElement(document, QString("time_25_plazma"));
    time_25_plazma = value.toDouble();
}

CalibrationKo3::~CalibrationKo3()
{
    qDebug() << name << "~CalibrationKo3()";
    save();
}

void CalibrationKo3::save()
{
    Calibration::save();
    setElement(document, QString("reagent_date"), reagent_date.toString("yyyyMMdd"));
    setElement(document, QString("reagent_serial"), reagent_serial);

    setElement(document, QString("k_plazma_date"), k_plazma_date.toString("yyyyMMdd"));
    setElement(document, QString("k_plazma_serial"), k_plazma_serial);

    setElement(document, QString("fibrinogen_k_plazma"), QString("%1").arg(fibrinogen_k_plazma));
    setElement(document, QString("time_k_plazma"), QString("%1").arg(time_k_plazma));

    setElement(document, QString("fibrinogen_200_plazma"), QString("%1").arg(fibrinogen_200_plazma));
    setElement(document, QString("time_200_plazma"), QString("%1").arg(time_200_plazma));

    setElement(document, QString("fibrinogen_50_plazma"), QString("%1").arg(fibrinogen_50_plazma));
    setElement(document, QString("time_50_plazma"), QString("%1").arg(time_50_plazma));

    setElement(document, QString("fibrinogen_25_plazma"), QString("%1").arg(fibrinogen_25_plazma));
    setElement(document, QString("time_25_plazma"), QString("%1").arg(time_25_plazma));

    CreateKoAgr::writeFile(name, document);
    //qDebug() << "CalibrationKo3::save()";
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

QString CalibrationKo3::getK_plazma_serial() const
{
    return k_plazma_serial;
}

void CalibrationKo3::setK_plazma_serial(const QString &value)
{
    k_plazma_serial = value;
}

QDate CalibrationKo3::getK_plazma_date() const
{
    return k_plazma_date;
}

void CalibrationKo3::setK_plazma_date(const QDate &value)
{
    k_plazma_date = value;
}

CalibrationKo4::CalibrationKo4(QObject *parent)
    : Calibration("calibrationKo4", parent)
{
    if( QFile::exists(name  + QString(".xml")) ) {
        CreateKoAgr::readFile(name, document);
    }
    else {
        document = CreateKoAgr::createCalibration(name);
        QDomElement calibration = document.firstChildElement();
        calibration.appendChild(document.createElement("date"));
        calibration.appendChild(document.createElement("reagent_serial"));
        calibration.appendChild(document.createElement("reagent_date"));
        calibration.appendChild(document.createElement("k_plazma_serial"));
        calibration.appendChild(document.createElement("k_plazma_date"));
        calibration.appendChild(document.createElement("action"));
        calibration.appendChild(document.createElement("tv1_concentration"));
        calibration.appendChild(document.createElement("tv1_time"));
        calibration.appendChild(document.createElement("tv2_concentration"));
        calibration.appendChild(document.createElement("tv2_time"));
        calibration.appendChild(document.createElement("tv3_concentration"));
        calibration.appendChild(document.createElement("tv3_time"));
        QDomElement write_time = document.createElement("write_time");
        write_time.setAttribute("Value", "10");
        calibration.appendChild(write_time);

        QDomElement incube_time = document.createElement("incube_time");
        incube_time.setAttribute("Value", "3");
        calibration.appendChild(incube_time);

        CreateKoAgr::writeFile(name, document);
    }
    load();
}

void CalibrationKo4::load()
{
    Calibration::load();
    QString value;
    value = getElement(document, QString("reagent_date"));
    reagent_date = QDate::fromString(value, QString("yyyyMMdd"));

    value = getElement(document, QString("reagent_serial"));
    reagent_serial = value;

    value = getElement(document, QString("k_plazma_date"));
    k_plazma_date = QDate::fromString(value, QString("yyyyMMdd"));

    value = getElement(document, QString("k_plazma_serial"));
    k_plazma_serial = value;

    value = getElement(document, QString("tv1_concentration"));
    tv1_concentration = value.toDouble();
    value = getElement(document, QString("tv1_time"));
    tv1_time = value.toDouble();

    value = getElement(document, QString("tv2_concentration"));
    tv2_concentration = value.toDouble();
    value = getElement(document, QString("tv2_time"));
    tv2_time = value.toDouble();

    value = getElement(document, QString("tv3_concentration"));
    tv3_concentration = value.toDouble();
    value = getElement(document, QString("tv3_time"));
    tv3_time = value.toDouble();
}

CalibrationKo4::~CalibrationKo4()
{
    qDebug() << name << "~CalibrationKo4()";
    save();
}

void CalibrationKo4::save()
{
    Calibration::save();
    setElement(document, QString("reagent_date"), reagent_date.toString("yyyyMMdd"));
    setElement(document, QString("k_plazma_date"), k_plazma_date.toString("yyyyMMdd"));

    setElement(document, QString("reagent_serial"), reagent_serial);
    setElement(document, QString("k_plazma_serial"), k_plazma_serial);

    setElement(document, QString("tv1_concentration"), QString("%1").arg(tv1_concentration));
    setElement(document, QString("tv1_time"), QString("%1").arg(tv1_time));

    setElement(document, QString("tv2_concentration"), QString("%1").arg(tv2_concentration));
    setElement(document, QString("tv2_time"), QString("%1").arg(tv2_time));

    setElement(document, QString("tv3_concentration"), QString("%1").arg(tv3_concentration));
    setElement(document, QString("tv3_time"), QString("%1").arg(tv3_time));

    CreateKoAgr::writeFile(name, document);
    //qDebug() << "CalibrationKo4::save()";
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

double CalibrationKo4::getTv3_concentration() const
{
    return tv3_concentration;
}

void CalibrationKo4::setTv3_concentration(double value)
{
    tv3_concentration = value;
}

double CalibrationKo4::getTv2_concentration() const
{
    return tv2_concentration;
}

void CalibrationKo4::setTv2_concentration(double value)
{
    tv2_concentration = value;
}

double CalibrationKo4::getTv1_concentration() const
{
    return tv1_concentration;
}

void CalibrationKo4::setTv1_concentration(double value)
{
    tv1_concentration = value;
}

double CalibrationKo4::getTv3_time() const
{
    return tv3_time;
}

void CalibrationKo4::setTv3_time(double value)
{
    tv3_time = value;
}

double CalibrationKo4::getTv2_time() const
{
    return tv2_time;
}

void CalibrationKo4::setTv2_time(double value)
{
    tv2_time = value;
}

double CalibrationKo4::getTv1_time() const
{
    return tv1_time;
}

void CalibrationKo4::setTv1_time(double value)
{
    tv1_time = value;
}


CalibrationKo5::CalibrationKo5(QObject *parent) : Calibration("calibrationKo5", parent)
{
    if( QFile::exists(name  + QString(".xml")) ) {
        CreateKoAgr::readFile(name, document);
    }
    else {
        document = CreateKoAgr::createCalibration(name);
        QDomElement calibration = document.firstChildElement();
        calibration.appendChild(document.createElement("date"));
        calibration.appendChild(document.createElement("reagent_serial"));
        calibration.appendChild(document.createElement("reagent_date"));

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

        QDomElement write_time = document.createElement("write_time");
        write_time.setAttribute("Value", "10");
        calibration.appendChild(write_time);

        QDomElement incube_time = document.createElement("incube_time");
        incube_time.setAttribute("Value", "3");
        calibration.appendChild(incube_time);

        CreateKoAgr::writeFile(name, document);
    }
    load();
}

void CalibrationKo5::load()
{
    Calibration::load();
    QString value;

    value = getElement(document, QString("reagent_date"));
    reagent_date = QDate::fromString(value, QString("yyyyMMdd"));

    value = getElement(document, QString("reagent_serial"));
    reagent_serial = value;

    value = getElement(document, QString("tromboplastin_date"));
    tromboplastin_date = QDate::fromString(value, QString("yyyyMMdd"));

    value = getElement(document, QString("tromboplastin_serial"));
    tromboplastin_serial = value;

    value = getElement(document, QString("k_plazma_date"));
    k_plazma_date = QDate::fromString(value, QString("yyyyMMdd"));

    value = getElement(document, QString("k_plazma_serial"));
    k_plazma_serial = value;

    value = getElement(document, QString("k_protrombine_index"));
    k_protrombine_index = value.toDouble();
    value = getElement(document, QString("k_protrombine_otn"));
    k_protrombine_otn = value.toDouble();

    value = getElement(document, QString("protrombine_k_Kvik"));
    protrombine_k_Kvik = value.toDouble();
    value = getElement(document, QString("time_k_Kvik"));
    time_k_Kvik = value.toDouble();

    value = getElement(document, QString("protrombine_50_Kvik"));
    protrombine_50_Kvik = value.toDouble();
    value = getElement(document, QString("time_50_Kvik"));
    time_50_Kvik = value.toDouble();
    value = getElement(document, QString("protrombine_25_Kvik"));
    protrombine_25_Kvik = value.toDouble();
    value = getElement(document, QString("time_25_Kvik"));
    time_25_Kvik = value.toDouble();
    value = getElement(document, QString("protrombine_12_Kvik"));
    protrombine_12_Kvik = value.toDouble();
    value = getElement(document, QString("time_12_Kvik"));
    time_12_Kvik = value.toDouble();
    value = getElement(document, QString("protrombine_index"));
    protrombine_index = value.toDouble();
    value = getElement(document, QString("protrombine_otn"));
    protrombine_otn = value.toDouble();
}

CalibrationKo5::~CalibrationKo5()
{
    qDebug() << name << "~CalibrationKo5()";
    save();
}

void CalibrationKo5::save()
{
    Calibration::save();
    setElement(document, QString("reagent_date"), reagent_date.toString("yyyyMMdd"));
    setElement(document, QString("reagent_serial"), reagent_serial);

    setElement(document, QString("tromboplastin_date"), tromboplastin_date.toString("yyyyMMdd"));
    setElement(document, QString("tromboplastin_serial"), tromboplastin_serial);

    setElement(document, QString("k_plazma_date"), k_plazma_date.toString("yyyyMMdd"));
    setElement(document, QString("k_plazma_serial"), k_plazma_serial);

    setElement(document, QString("k_protrombine_index"), QString("%1").arg(k_protrombine_index));
    setElement(document, QString("k_protrombine_otn"), QString("%1").arg(k_protrombine_otn));
    setElement(document, QString("protrombine_k_Kvik"), QString("%1").arg(protrombine_k_Kvik));
    setElement(document, QString("time_k_Kvik"), QString("%1").arg(time_k_Kvik));
    setElement(document, QString("protrombine_50_Kvik"), QString("%1").arg(protrombine_50_Kvik));
    setElement(document, QString("time_50_Kvik"), QString("%1").arg(time_50_Kvik));
    setElement(document, QString("protrombine_25_Kvik"), QString("%1").arg(protrombine_25_Kvik));
    setElement(document, QString("time_25_Kvik"), QString("%1").arg(time_25_Kvik));
    setElement(document, QString("protrombine_12_Kvik"), QString("%1").arg(protrombine_12_Kvik));
    setElement(document, QString("time_12_Kvik"), QString("%1").arg(time_12_Kvik));
    setElement(document, QString("protrombine_index"), QString("%1").arg(protrombine_index));
    setElement(document, QString("protrombine_otn"), QString("%1").arg(protrombine_otn));

    CreateKoAgr::writeFile(name, document);
    //qDebug() << "CalibrationKo5::save()";
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

QString CalibrationKo5::getReagent_serial() const
{
    return reagent_serial;
}

void CalibrationKo5::setReagent_serial(const QString &value)
{
    reagent_serial = value;
}

QDate CalibrationKo5::getReagent_date() const
{
    return reagent_date;
}

void CalibrationKo5::setReagent_date(const QDate &value)
{
    reagent_date = value;
}

CalibrationAgr1::CalibrationAgr1(QObject *parent) : Calibration("calibrationAgr1", parent)
{
    if( QFile::exists(name  + QString(".xml")) ) {
        CreateKoAgr::readFile(name, document);
    }
    else {
        document = CreateKoAgr::createCalibration(name);
        QDomElement calibration = document.firstChildElement();
        calibration.appendChild(document.createElement("date"));
        calibration.appendChild(document.createElement("reagent_serial"));
        calibration.appendChild(document.createElement("reagent_date"));

        calibration.appendChild(document.createElement("k_concentration"));

        QDomElement write_time = document.createElement("write_time");
        write_time.setAttribute("Value", "10");
        calibration.appendChild(write_time);

        QDomElement incube_time = document.createElement("incube_time");
        incube_time.setAttribute("Value", "1");
        calibration.appendChild(incube_time);

        QDomElement incube_time_2 = document.createElement("incube_time_2");
        incube_time_2.setAttribute("Value", "3");
        calibration.appendChild(incube_time);

        //выходные данные
        calibration.appendChild(document.createElement("level_0"));
        calibration.appendChild(document.createElement("level_100"));

        CreateKoAgr::writeFile(name, document);
    }
    load();
}

void CalibrationAgr1::load()
{
    Calibration::load();
    QString value;
    value = getElement(document, QString("reagent_date"));
    reagent_date = QDate::fromString(value, QString("yyyyMMdd"));

    value = getElement(document, QString("incube_time_2"));
    incube_time_2 = value.toDouble();

    value = getElement(document, QString("reagent_serial"));
    reagent_serial = value;

    value = getElement(document, QString("k_concentration"));
    k_concentration = value.toDouble();

    value = getElement(document, QString("level_0"));
    level_0 = value.toDouble();

    value = getElement(document, QString("level_100"));
    level_100 = value.toDouble();
}

CalibrationAgr1::~CalibrationAgr1()
{
    qDebug() << name << "~CalibrationAgr1()";
    save();
}

void CalibrationAgr1::save()
{
    setElement(document, QString("reagent_date"), reagent_date.toString("yyyyMMdd"));
    setElement(document, QString("reagent_serial"), reagent_serial);
    setElement(document, QString("k_concentration"), QString("%1").arg(k_concentration));
    setElement(document, QString("level_0"), QString("%1").arg(level_0));
    setElement(document, QString("level_100"), QString("%1").arg(level_100));

    CreateKoAgr::writeFile(name, document);
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

double CalibrationAgr1::getIncube_time_2() const
{
    return incube_time_2;
}

void CalibrationAgr1::setIncube_time_2(double value)
{
    incube_time_2 = value;
}

CalibrationAgr2::CalibrationAgr2(QObject *parent) : Calibration("calibrationAgr2", parent)
{
    if( QFile::exists(name  + QString(".xml")) ) {
        CreateKoAgr::readFile(name, document);
    }
    else {
        document = CreateKoAgr::createCalibration(name);
        QDomElement calibration = document.firstChildElement();
        calibration.appendChild(document.createElement("date"));
        calibration.appendChild(document.createElement("reagent_serial"));
        calibration.appendChild(document.createElement("reagent_date"));

        QDomElement write_time = document.createElement("write_time");
        write_time.setAttribute("Value", "10");
        calibration.appendChild(write_time);

        QDomElement incube_time = document.createElement("incube_time");
        incube_time.setAttribute("Value", "1");
        calibration.appendChild(incube_time);

        QDomElement incube_time_2 = document.createElement("incube_time_2");
        incube_time_2.setAttribute("Value", "3");
        calibration.appendChild(incube_time);

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
        CreateKoAgr::writeFile(name, document);
    }
    load();
}

void CalibrationAgr2::load()
{
    Calibration::load();
    QString value;
    value = getElement(document, QString("reagent_date"));
    reagent_date = QDate::fromString(value, QString("yyyyMMdd"));

    value = getElement(document, QString("k_plazma_date"));
    k_plazma_date = QDate::fromString(value, QString("yyyyMMdd"));

    value = getElement(document, QString("reagent_serial"));
    reagent_serial = value;

    value = getElement(document, QString("k_plazma_serial"));
    k_plazma_serial = value;

    value = getElement(document, QString("incube_time_1"));
    incube_time_1 = value.toDouble();

    value = getElement(document, QString("incube_time_2"));
    incube_time_2 = value.toDouble();

    value = getElement(document, QString("k_plazma"));
    k_plazma = value.toDouble();
    value = getElement(document, QString("level_0"));
    level_0 = value.toDouble();
    value = getElement(document, QString("level_100"));
    level_100 = value.toDouble();

    value = getElement(document, QString("c1"));
    c1 = value.toDouble();
    value = getElement(document, QString("ck1"));
    ck1 = value.toDouble();
    value = getElement(document, QString("c2"));
    c2 = value.toDouble();
    value = getElement(document, QString("ck2"));
    ck2 = value.toDouble();
    value = getElement(document, QString("c3"));
    c3 = value.toDouble();
    value = getElement(document, QString("ck3"));
    ck3 = value.toDouble();
    value = getElement(document, QString("c4"));
    c4 = value.toDouble();
    value = getElement(document, QString("ck4"));
    ck4 = value.toDouble();
}

CalibrationAgr2::~CalibrationAgr2()
{
    qDebug() << name << "~CalibrationAgr2()";
    save();
}

void CalibrationAgr2::save()
{
    Calibration::save();
    setElement(document, QString("reagent_date"), reagent_date.toString("yyyyMMdd"));
    setElement(document, QString("k_plazma_date"), k_plazma_date.toString("yyyyMMdd"));

    setElement(document, QString("reagent_serial"), reagent_serial);
    setElement(document, QString("k_plazma_serial"), k_plazma_serial);

    setElement(document, QString("incube_time_1"), QString("%1").arg(incube_time_1));
    setElement(document, QString("incube_time_2"), QString("%1").arg(incube_time_2));

    setElement(document, QString("k_plazma"), QString("%1").arg(k_plazma));
    setElement(document, QString("level_0"), QString("%1").arg(level_0));
    setElement(document, QString("level_100"), QString("%1").arg(level_100));

    setElement(document, QString("c1"), QString("%1").arg(c1));
    setElement(document, QString("ck1"), QString("%1").arg(ck1));
    setElement(document, QString("c2"), QString("%1").arg(c2));
    setElement(document, QString("ck2"), QString("%1").arg(ck2));
    setElement(document, QString("c3"), QString("%1").arg(c3));
    setElement(document, QString("ck3"), QString("%1").arg(ck3));
    setElement(document, QString("c4"), QString("%1").arg(c4));
    setElement(document, QString("ck4"), QString("%1").arg(ck4));

    CreateKoAgr::writeFile(name, document);
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
