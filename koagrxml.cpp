#include "koagrxml.h"
//#include "typeinfo"

QDomDocument Creator::createTest(QString name) {

    QDomDocument document;
    QDomElement test = document.createElement(name);
    document.appendChild(test);

    QDomElement k1 = document.createElement("k1");
    k1.setAttribute("Value", "0");
    k1.setAttribute("Num", "0");
    k1.setAttribute("t1", "0");
    test.appendChild(k1);

    QDomElement k2 = document.createElement("k2");
    k2.setAttribute("Value", "0");
    k2.setAttribute("Num", "0");
    k2.setAttribute("t2", "0");
    test.appendChild(k2);

    QDomElement k3 = document.createElement("k3");
    k3.setAttribute("Value", "0");
    k3.setAttribute("Num", "0");
    k3.setAttribute("t3", "0");
    test.appendChild(k3);

    QDomElement k4 = document.createElement("k4");
    k4.setAttribute("Value", "0");
    k4.setAttribute("Num", "0");
    k4.setAttribute("t4", "0");
    test.appendChild(k4);

    QDomElement single = document.createElement("single");
    single.setAttribute("Value", "1");
    test.appendChild(single);

    test.appendChild(document.createElement("date"));
    test.appendChild(document.createElement("time"));

    return document;
}

QDomDocument Creator::createCalibration(QString name)
{
    QDomDocument document;
    QDomElement calibration = document.createElement(name);
    calibration.appendChild(document.createElement("k1"));
    calibration.appendChild(document.createElement("k2"));
    calibration.appendChild(document.createElement("k3"));
    calibration.appendChild(document.createElement("k4"));
    calibration.appendChild(document.createElement("date"));
    calibration.appendChild(document.createElement("time"));
    document.appendChild(calibration);

    return document;
}

int Creator::writeFile(QString name, QDomDocument doc)
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
        stream.setCodec("UTF-8");
        stream << doc.toString();
        stream.flush();
        file.close();
    }
    //QDir::setCurrent(cur_dir.path());
    file.close();
    return 0;
}

int Creator::readFile(QString name, QDomDocument &doc)
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

QDir Creator::getXMLDir()
{
    QDir dir;
    QString path = QDir::homePath();
    dir.cd(path); //переходим в папку home
    if(!dir.cd("Agrekola4k"))
    {
        if(dir.mkdir("Agrekola4k")) dir.cd("Agrekola4k");
        //QDir::setCurrent(dir.path());
        //qDebug() << "mkdir(Agrekola4k)";
    }
    if(!dir.cd("XML"))
    {
        if(dir.mkdir("XML")) dir.cd("XML");
        //qDebug() << "mkdir(XML)";
    }
    return dir;
}

Test::Test(QString n, Calibration *c, QObject *parent) : QObject(parent)
{
    name = n;
    c_ko = c;
    dir = Creator::getXMLDir();
    QDir::setCurrent(dir.path());
    //qDebug() << "name" << name << "dir" << dir.currentPath();
    //load();
    //document = KoAgrXML::openTest();
}

void Test::load()
{
    QDir::setCurrent(dir.path());
    if( QFile::exists(name  + QString(".xml")) ) {
        Creator::readFile(name, document);
    }
    else {
        document = Creator::createTest(name);
        Creator::writeFile(name, document);
    }

    k1 = getElement(document, "k1").toInt();
    num1 = getElement(document, "k1", "Num");
    t1 = getElement(document, "k1", "t1").toDouble();

    k2 = getElement(document, "k2").toInt();
    num2 = getElement(document, "k2", "Num");
    t2 = getElement(document, "k2", "t2").toDouble();

    k3 = getElement(document, "k3").toInt();
    num3 = getElement(document, "k3", "Num");
    t3 = getElement(document, "k3", "t3").toDouble();

    k4 = getElement(document, "k4").toInt();
    num4 = getElement(document, "k4", "Num");
    t4 = getElement(document, "k4", "t4").toDouble();

    single = getElement(document, "single").toInt();
    date = QDate::fromString(getElement(document, "date"), "yyyyMMdd");
    time = QTime::fromString(getElement(document, "time"), "hhmm");
}

Test::~Test()
{
    //qDebug() << name << " ~Test()";
    save();
}

void Test::save()
{
    QDir::setCurrent(dir.path());
    setElement(document, "k1", QString("%1").arg(k1));
    setElement(document, "k1", num1, "Num");
    setElement(document, "k1", QString::number(t1), "t1");

    setElement(document, "k2", QString("%1").arg(k2));
    setElement(document, "k2", num2, "Num");
    setElement(document, "k2", QString::number(t2), "t2");

    setElement(document, "k3", QString("%1").arg(k3));
    setElement(document, "k3", num3, "Num");
    setElement(document, "k3", QString::number(t3), "t3");

    setElement(document, "k4", QString("%1").arg(k4));
    setElement(document, "k4", num4, "Num");
    setElement(document, "k4", QString::number(t4), "t4");

    setElement(document, "single", QString("%1").arg(single));
    setElement(document, "date", date.toString("yyyyMMdd"));
    setElement(document, "time", time.toString("hhmm"));

    Creator::writeFile(name, document);
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

QTime Test::getTime() const
{
    return time;
}

void Test::setTime(const QTime &value)
{
    time = value;
}

double Test::getT4() const
{
    return t4;
}

void Test::setT4(double value)
{
    t4 = value;
}

double Test::getT3() const
{
    return t3;
}

void Test::setT3(double value)
{
    t3 = value;
}

double Test::getT2() const
{
    return t2;
}

void Test::setT2(double value)
{
    t2 = value;
}

double Test::getT1() const
{
    return t1;
}

void Test::setT1(double value)
{
    t1 = value;
}

QDate Test::getDate() const
{
    return date;
}

void Test::setDate(const QDate &value)
{
    date = value;
}

QString Test::getNum4() const
{
    return num4;
}

void Test::setNum4(const QString &value)
{
    num4 = value;
}

double Test::getIncubeTime()
{
    c_ko->load();
    return c_ko->getIncube_time();
}

double Test::getWriteTime()
{ 
    c_ko->load();
    return c_ko->getWrite_time();
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
    : Test("testKo1", new CalibrationKo1)
{
    load();
}

TestKo1::~TestKo1()
{
    //qDebug() << name << " ~TestKo1()";
}

TestKo2::TestKo2(QObject *parent)
    : Test("testKo2_1", new CalibrationKo2)
{
    load();
}

TestKo2::TestKo2(WithoutCalibration, QObject *parent) : Test("testKo2_2", NULL)
{
    if( QFile::exists(name  + QString(".xml")) ) {
        Creator::readFile(name, document);
    }
    else {
        document = Creator::createTest(name);
        QDomElement calibration = document.firstChildElement();
        calibration.appendChild(document.createElement("date"));
        calibration.appendChild(document.createElement("reagent_serial"));
        calibration.appendChild(document.createElement("reagent_date"));
        calibration.appendChild(document.createElement("a4tv_kp"));

        QDomElement write_time = document.createElement("write_time");
        write_time.setAttribute("Value", "10");
        calibration.appendChild(write_time);

        QDomElement incube_time = document.createElement("incube_time");
        incube_time.setAttribute("Value", "3");
        calibration.appendChild(incube_time);

        Creator::writeFile(name, document);
    }
    load();
}

TestKo2::~TestKo2()
{
    //qDebug() << name << " ~TestKo2()";
    save();
}

double TestKo2::getIncubeTime()
{
    return this->incube_time;
}

double TestKo2::getWriteTime()
{
    return this->write_time;
}

void TestKo2::save()
{
    if(c_ko != NULL) {
        Test::save();
    }
    else {
        Test::save();
        setElement(document, "date", date.toString("yyyyMMdd"));
        setElement(document, "reagent_date", reagent_date.toString("yyyyMMdd"));
        setElement(document, "reagent_serial", reagent_serial);
        setElement(document, "write_time", QString::number(write_time));
        setElement(document, "incube_time", QString::number(incube_time));
        setElement(document, "a4tv_kp", QString::number(a4tv_kp));
        Creator::writeFile(name, document);
    }
}

void TestKo2::load()
{
    if(c_ko != NULL) {
        Test::load();
    }
    else {
        Test::load();
        date = QDate::fromString(getElement(document, "date"), "yyyyMMdd");
        reagent_date = QDate::fromString(getElement(document, "reagent_date"), "yyyyMMdd");
        reagent_serial = getElement(document, "reagent_serial");
        write_time = getElement(document, "write_time").toDouble();
        incube_time = getElement(document, "incube_time").toDouble();
        a4tv_kp = getElement(document, "a4tv_kp").toDouble();
    }
}

QDate TestKo2::getDate() const
{
    return date;
}

void TestKo2::setDate(const QDate &value)
{
    date = value;
}

QDate TestKo2::getReagent_date() const
{
    return reagent_date;
}

void TestKo2::setReagent_date(const QDate &value)
{
    reagent_date = value;
}

QString TestKo2::getReagent_serial() const
{
    return reagent_serial;
}

void TestKo2::setReagent_serial(const QString &value)
{
    reagent_serial = value;
}

double TestKo2::getWrite_time() const
{
    return write_time;
}

void TestKo2::setWrite_time(double value)
{
    write_time = value;
}

double TestKo2::getIncube_time() const
{
    return incube_time;
}

void TestKo2::setIncube_time(double value)
{
    incube_time = value;
}

double TestKo2::getA4tv_kp() const
{
    return a4tv_kp;
}

void TestKo2::setA4tv_kp(double value)
{
    a4tv_kp = value;
}

TestKo3::TestKo3(QObject *parent)
    : Test("testKo3", new CalibrationKo3)
{
    load();
}

TestKo3::~TestKo3()
{
    //qDebug() << name << " ~TestKo3()";
}

TestKo4::TestKo4(QObject *parent)
    : Test("testKo4_1", new CalibrationKo4)
{
    load();
}

TestKo4::TestKo4(WithoutCalibration, QObject *parent) : Test("testKo4_2", NULL)
{
    if( QFile::exists(name  + QString(".xml")) ) {
        Creator::readFile(name, document);
    }
    else {
        document = Creator::createTest(name);
        QDomElement calibration = document.firstChildElement();
        calibration.appendChild(document.createElement("date"));
        calibration.appendChild(document.createElement("reagent_serial"));
        calibration.appendChild(document.createElement("reagent_date"));
        calibration.appendChild(document.createElement("activity"));
        calibration.appendChild(document.createElement("trombine_time"));

        QDomElement write_time = document.createElement("write_time");
        write_time.setAttribute("Value", "10");
        calibration.appendChild(write_time);

        QDomElement incube_time = document.createElement("incube_time");
        incube_time.setAttribute("Value", "3");
        calibration.appendChild(incube_time);

        Creator::writeFile(name, document);
    }
    load();
}

TestKo4::~TestKo4()
{
    //qDebug() << name << " ~TestKo4()";
    save();
}

double TestKo4::getIncubeTime()
{
    return this->incube_time;
}

double TestKo4::getWriteTime()
{
    return this->write_time;
}

void TestKo4::save()
{
    if(c_ko != NULL) {
        Test::save();
    }
    else {
        Test::save();
        setElement(document, "date", date.toString("yyyyMMdd"));
        setElement(document, "reagent_date", reagent_date.toString("yyyyMMdd"));
        setElement(document, "reagent_serial", reagent_serial);
        setElement(document, "write_time", QString::number(write_time));
        setElement(document, "incube_time", QString::number(incube_time));
        setElement(document, "activity", QString::number(activity));
        setElement(document, "trombine_time", QString::number(trombine_time));
        Creator::writeFile(name, document);
    }
}

void TestKo4::load()
{
    if(c_ko != NULL) {
        Test::load();
    }
    else {
        Test::load();
        date = QDate::fromString(getElement(document, "date"), "yyyyMMdd");
        reagent_date = QDate::fromString(getElement(document, "reagent_date"), "yyyyMMdd");
        reagent_serial = getElement(document, "reagent_serial");
        write_time = getElement(document, "write_time").toDouble();
        incube_time = getElement(document, "incube_time").toDouble();
        activity = getElement(document, "activity").toInt();
        trombine_time = getElement(document, "trombine_time").toDouble();
    }
}

QDate TestKo4::getDate() const
{
    return date;
}

void TestKo4::setDate(const QDate &value)
{
    date = value;
}

QDate TestKo4::getReagent_date() const
{
    return reagent_date;
}

void TestKo4::setReagent_date(const QDate &value)
{
    reagent_date = value;
}

QString TestKo4::getReagent_serial() const
{
    return reagent_serial;
}

void TestKo4::setReagent_serial(const QString &value)
{
    reagent_serial = value;
}

double TestKo4::getWrite_time() const
{
    return write_time;
}

void TestKo4::setWrite_time(double value)
{
    write_time = value;
}

double TestKo4::getIncube_time() const
{
    return incube_time;
}

void TestKo4::setIncube_time(double value)
{
    incube_time = value;
}

int TestKo4::getActivity() const
{
    return activity;
}

void TestKo4::setActivity(int value)
{
    activity = value;
}

double TestKo4::getTrombine_time() const
{
    return trombine_time;
}

void TestKo4::setTrombine_time(double value)
{
    trombine_time = value;
}

TestKo5::TestKo5(QObject *parent)
    : Test("testKo5", new CalibrationKo5)
{
    load();
}

TestKo5::~TestKo5()
{
    //qDebug() << name << " ~TestKo5()";
}

TestAgr1::TestAgr1(QObject *parent)
    : Test("testAgr1", new CalibrationAgr1)
{
    if( QFile::exists(name  + QString(".xml")) ) {
        Creator::readFile(name, document);
    }
    else {
        document = Creator::createCalibration(name);
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
        calibration.appendChild(incube_time_2);

        calibration.appendChild(document.createElement("k_plazma_serial"));
        calibration.appendChild(document.createElement("k_plazma_date"));
        calibration.appendChild(document.createElement("k_plazma"));
        //выходные данные
        calibration.appendChild(document.createElement("BTP1"));
        calibration.appendChild(document.createElement("BTP2"));
        calibration.appendChild(document.createElement("BTP3"));
        calibration.appendChild(document.createElement("BTP4"));

        calibration.appendChild(document.createElement("OTP1"));
        calibration.appendChild(document.createElement("OTP2"));
        calibration.appendChild(document.createElement("OTP3"));
        calibration.appendChild(document.createElement("OTP4"));

        calibration.appendChild(document.createElement("c1"));
        calibration.appendChild(document.createElement("ck1"));

        calibration.appendChild(document.createElement("c2"));
        calibration.appendChild(document.createElement("ck2"));

        calibration.appendChild(document.createElement("c3"));
        calibration.appendChild(document.createElement("ck3"));

        calibration.appendChild(document.createElement("c4"));
        calibration.appendChild(document.createElement("ck4"));
        Creator::writeFile(name, document);
    }
    load();
}

TestAgr1::~TestAgr1()
{
    //qDebug() << name << " ~TestAgr1()";
}

double TestAgr1::getIncubeTime2()
{
    CalibrationAgr1* obj = qobject_cast<CalibrationAgr1*>(c_ko);
    if(!obj) {
        qDebug() << "errore at TestAgr1::getIncubeTime2() - qobject_cast is null";
        return;
    }
    obj->load();
    return obj->getIncube_time_2();
//    CalibrationAgr1 *obj;
//    if(typeid(c_ko) == typeid(CalibrationAgr1))
//        obj = dynamic_cast<CalibrationAgr1*>(c_ko);
//    obj->load();
//    return obj->getIncubeTime2();
}

TestAgr2::TestAgr2(QObject *parent)
    : Test("testAgr2", new CalibrationAgr2)
{
    load();
}

TestAgr2::~TestAgr2()
{
    //qDebug() << name << " ~TestAgr2()";
}

double TestAgr2::getIncubeTime2()
{
    CalibrationAgr2* obj = dynamic_cast<CalibrationAgr2*>(c_ko);
    obj->load();
    return obj->getIncube_time_2();
}

Calibration::Calibration(QString n, QObject *parent) : QObject(parent)
{
    name = n;
    dir = Creator::getXMLDir();
    QDir::setCurrent(dir.path());
    //qDebug() << "name" << name << "dir" << dir.currentPath();
}

void Calibration::load()
{
    QDir::setCurrent(dir.path());
    if( QFile::exists(name  + QString(".xml")) ) {
        Creator::readFile(name, document);
    }
    else {
        document = Creator::createCalibration(name);
        Creator::writeFile(name, document);
    }

    date = QDate::fromString(getElement(document, "date"), "yyyyMMdd");
    time = QTime::fromString(getElement(document, "time"), "hhmm");

    write_time = getElement(document, "write_time").toDouble();
    incube_time = getElement(document, "incube_time").toDouble();
    k1 = getElement(document, "k1").toInt();
    k2 = getElement(document, "k2").toInt();
    k3 = getElement(document, "k3").toInt();
    k4 = getElement(document, "k4").toInt();
}

Calibration::~Calibration()
{
    save();
}

void Calibration::save()
{
    QDir::setCurrent(dir.path());
    setElement(document, "date", date.toString("yyyyMMdd"));
    setElement(document, "time", time.toString("hhmm"));
    setElement(document, "write_time", QString::number(write_time));
    setElement(document, "incube_time", QString::number(incube_time));
    setElement(document, "k1", QString::number(k1));
    setElement(document, "k2", QString::number(k2));
    setElement(document, "k3", QString::number(k3));
    setElement(document, "k4", QString::number(k4));
    Creator::writeFile(name, document);
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

void Calibration::setIncube_time(const double value)
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

QTime Calibration::getTime() const
{
    return time;
}

void Calibration::setTime(const QTime &value)
{
    time = value;
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
        Creator::readFile(name, document);
    }
    else {
        document = Creator::createCalibration(name);
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

        Creator::writeFile(name, document);
    }
    load();
}

CalibrationKo1::~CalibrationKo1()
{
    //qDebug() << name << "~CalibrationKo1()";
    save();
}

CalibrationKo2::CalibrationKo2(QObject *parent)
    : Calibration("calibrationKo2")
{
    if( QFile::exists(name  + QString(".xml")) ) {
        Creator::readFile(name, document);
    }
    else {
        document = Creator::createCalibration(name);
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

        Creator::writeFile(name, document);
    }
    load();
}

void CalibrationKo2::load()
{
    Calibration::load();
    reagent_date = QDate::fromString(getElement(document, "reagent_date"), "yyyyMMdd");
    reagent_serial = getElement(document, "reagent_serial");
    k_plazma_date = QDate::fromString(getElement(document, "k_plazma_date"), "yyyyMMdd");
    k_plazma_serial = getElement(document, "k_plazma_serial");
    k_plazma_a4tv = getElement(document, "k_plazma_a4tv").toDouble();
    a4tv_kp1 = getElement(document, "a4tv_kp1").toDouble();
    a4tv_kp2 = getElement(document, "a4tv_kp2").toDouble();
    a4tv_kp3 = getElement(document, "a4tv_kp3").toDouble();
    a4tv_kp4 = getElement(document, "a4tv_kp4").toDouble();
}

CalibrationKo2::~CalibrationKo2()
{
    //qDebug() << name << "~CalibrationKo2()";
    save();
}

void CalibrationKo2::save()
{
    Calibration::save();
    setElement(document, "reagent_date", reagent_date.toString("yyyyMMdd"));
    setElement(document, "reagent_serial", reagent_serial);
    setElement(document, "k_plazma_date", k_plazma_date.toString("yyyyMMdd"));
    setElement(document, "k_plazma_serial", k_plazma_serial);
    setElement(document, "k_plazma_a4tv", QString::number(k_plazma_a4tv));
    setElement(document, "a4tv_kp1", QString::number(a4tv_kp1));
    setElement(document, "a4tv_kp2", QString::number(a4tv_kp2));
    setElement(document, "a4tv_kp3", QString::number(a4tv_kp3));
    setElement(document, "a4tv_kp4", QString::number(a4tv_kp4));
    Creator::writeFile(name, document);
}

QDate CalibrationKo2::getReagent_date() const
{
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
        Creator::readFile(name, document);
    }
    else {
        document = Creator::createCalibration(name);
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

        Creator::writeFile(name, document);
    }
    load();
}

void CalibrationKo3::load()
{
    Calibration::load();
    reagent_date = QDate::fromString(getElement(document, "reagent_date"), "yyyyMMdd");
    reagent_serial = getElement(document, "reagent_serial");
    k_plazma_date = QDate::fromString(getElement(document, "k_plazma_date"), "yyyyMMdd");
    k_plazma_serial = getElement(document, "k_plazma_serial");
    fibrinogen_k_plazma = getElement(document, "fibrinogen_k_plazma").toDouble();
    time_k_plazma = getElement(document, "time_k_plazma").toDouble();
    fibrinogen_200_plazma = getElement(document, "fibrinogen_200_plazma").toDouble();
    time_200_plazma = getElement(document, "time_200_plazma").toDouble();
    fibrinogen_50_plazma = getElement(document, "fibrinogen_50_plazma").toDouble();
    time_50_plazma = getElement(document, "time_50_plazma").toDouble();
    fibrinogen_25_plazma = getElement(document, "fibrinogen_25_plazma").toDouble();
    time_25_plazma = getElement(document, "time_25_plazma").toDouble();
}

CalibrationKo3::~CalibrationKo3()
{
    //qDebug() << name << "~CalibrationKo3()";
    save();
}

void CalibrationKo3::save()
{
    Calibration::save();
    setElement(document, "reagent_date", reagent_date.toString("yyyyMMdd"));
    setElement(document, "reagent_serial", reagent_serial);

    setElement(document, "k_plazma_date", k_plazma_date.toString("yyyyMMdd"));
    setElement(document, "k_plazma_serial", k_plazma_serial);

    setElement(document, "fibrinogen_k_plazma", QString::number(fibrinogen_k_plazma));
    setElement(document, "time_k_plazma", QString::number(time_k_plazma));

    setElement(document, "fibrinogen_200_plazma", QString::number(fibrinogen_200_plazma));
    setElement(document, "time_200_plazma", QString::number(time_200_plazma));

    setElement(document, "fibrinogen_50_plazma", QString::number(fibrinogen_50_plazma));
    setElement(document, "time_50_plazma", QString::number(time_50_plazma));

    setElement(document, "fibrinogen_25_plazma", QString::number(fibrinogen_25_plazma));
    setElement(document, "time_25_plazma", QString::number(time_25_plazma));

    Creator::writeFile(name, document);
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
        Creator::readFile(name, document);
    }
    else {
        createElements();
    }
    load();
}

CalibrationKo4::CalibrationKo4(QString name)
    : Calibration(name)
{
    if( QFile::exists(name  + QString(".xml")) ) {
        Creator::readFile(name, document);
    }
    else {
        createElements();
    }
    load();
}


void CalibrationKo4::createElements()
{
    document = Creator::createCalibration(name);
    QDomElement calibration = document.firstChildElement();
    calibration.appendChild(document.createElement("date"));
    calibration.appendChild(document.createElement("reagent_serial"));
    calibration.appendChild(document.createElement("reagent_date"));
    calibration.appendChild(document.createElement("k_plazma_serial"));
    calibration.appendChild(document.createElement("k_plazma_date"));
    calibration.appendChild(document.createElement("activity"));
    calibration.appendChild(document.createElement("tv1"));
    calibration.appendChild(document.createElement("tv2"));
    calibration.appendChild(document.createElement("tv3"));
    calibration.appendChild(document.createElement("tv4"));

    QDomElement write_time = document.createElement("write_time");
    write_time.setAttribute("Value", "10");
    calibration.appendChild(write_time);
    QDomElement incube_time = document.createElement("incube_time");
    incube_time.setAttribute("Value", "3");
    calibration.appendChild(incube_time);

    Creator::writeFile(name, document);
}

double CalibrationKo4::getTv4() const
{
    return tv4;
}

void CalibrationKo4::setTv4(double value)
{
    tv4 = value;
}

double CalibrationKo4::getTv3() const
{
    return tv3;
}

void CalibrationKo4::setTv3(double value)
{
    tv3 = value;
}

double CalibrationKo4::getTv2() const
{
    return tv2;
}

void CalibrationKo4::setTv2(double value)
{
    tv2 = value;
}

double CalibrationKo4::getTv1() const
{
    return tv1;
}

void CalibrationKo4::setTv1(double value)
{
    tv1 = value;
}

void CalibrationKo4::load()
{
    Calibration::load();
    reagent_date = QDate::fromString(getElement(document, "reagent_date"), "yyyyMMdd");
    reagent_serial = getElement(document, "reagent_serial");
    k_plazma_date = QDate::fromString(getElement(document, "k_plazma_date"), "yyyyMMdd");
    k_plazma_serial = getElement(document, "k_plazma_serial");
    activity = getElement(document, "activity").toDouble();
    tv1 = getElement(document, "tv1").toDouble();
    tv2 = getElement(document, "tv2").toDouble();
    tv3 = getElement(document, "tv3").toDouble();
    tv4 = getElement(document, "tv4").toDouble();
}

CalibrationKo4::~CalibrationKo4()
{
    //qDebug() << name << "~CalibrationKo4()";
    save();
}

void CalibrationKo4::save()
{
    Calibration::save();
    setElement(document, "reagent_date", reagent_date.toString("yyyyMMdd"));
    setElement(document, "k_plazma_date", k_plazma_date.toString("yyyyMMdd"));
    setElement(document, "reagent_serial", reagent_serial);
    setElement(document, "k_plazma_serial", k_plazma_serial);
    setElement(document, "activity", QString::number(activity));
    setElement(document, "tv1", QString::number(tv1));
    setElement(document, "tv2", QString::number(tv2));
    setElement(document, "tv3", QString::number(tv3));
    setElement(document, "tv4", QString::number(tv4));
    Creator::writeFile(name, document);
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

double CalibrationKo4::getActivity() const
{
    return activity;
}

void CalibrationKo4::setActivity(const double &value)
{
    activity = value;
}

CalibrationKo5::CalibrationKo5(QObject *parent) : Calibration("calibrationKo5", parent)
{
    if( QFile::exists(name  + QString(".xml")) ) {
        Creator::readFile(name, document);
    }
    else {
        document = Creator::createCalibration(name);
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

        Creator::writeFile(name, document);
    }
    load();
}

void CalibrationKo5::load()
{
    Calibration::load();
    reagent_date = QDate::fromString(getElement(document, "reagent_date"), "yyyyMMdd");
    reagent_serial = getElement(document, "reagent_serial");
    tromboplastin_date = QDate::fromString(getElement(document, "tromboplastin_date"), "yyyyMMdd");
    tromboplastin_serial = getElement(document, "tromboplastin_serial");
    k_plazma_date = QDate::fromString(getElement(document, "k_plazma_date"), "yyyyMMdd");
    k_plazma_serial = getElement(document, "k_plazma_serial");
    k_protrombine_index = getElement(document, "k_protrombine_index").toDouble();
    k_protrombine_otn = getElement(document, "k_protrombine_otn").toDouble();
    protrombine_k_Kvik = getElement(document, "protrombine_k_Kvik").toDouble();
    time_k_Kvik = getElement(document, "time_k_Kvik").toDouble();
    protrombine_50_Kvik = getElement(document, "protrombine_50_Kvik").toDouble();
    time_50_Kvik = getElement(document, "time_50_Kvik").toDouble();
    protrombine_25_Kvik = getElement(document, "protrombine_25_Kvik").toDouble();
    time_25_Kvik = getElement(document, "time_25_Kvik").toDouble();
    protrombine_12_Kvik = getElement(document, "protrombine_12_Kvik").toDouble();
    time_12_Kvik = getElement(document, "time_12_Kvik").toDouble();
    protrombine_index = getElement(document, "protrombine_index").toDouble();
    protrombine_otn = getElement(document, "protrombine_otn").toDouble();
}

CalibrationKo5::~CalibrationKo5()
{
    //qDebug() << name << "~CalibrationKo5()";
    save();
}

void CalibrationKo5::save()
{
    Calibration::save();
    setElement(document, "reagent_date", reagent_date.toString("yyyyMMdd"));
    setElement(document, "reagent_serial", reagent_serial);

    setElement(document, "tromboplastin_date", tromboplastin_date.toString("yyyyMMdd"));
    setElement(document, "tromboplastin_serial", tromboplastin_serial);

    setElement(document, "k_plazma_date", k_plazma_date.toString("yyyyMMdd"));
    setElement(document, "k_plazma_serial", k_plazma_serial);

    setElement(document, "k_protrombine_index", QString::number(k_protrombine_index));
    setElement(document, "k_protrombine_otn", QString::number(k_protrombine_otn));
    setElement(document, "protrombine_k_Kvik", QString::number(protrombine_k_Kvik));
    setElement(document, "time_k_Kvik", QString::number(time_k_Kvik));
    setElement(document, "protrombine_50_Kvik", QString::number(protrombine_50_Kvik));
    setElement(document, "time_50_Kvik", QString::number(time_50_Kvik));
    setElement(document, "protrombine_25_Kvik", QString::number(protrombine_25_Kvik));
    setElement(document, "time_25_Kvik", QString::number(time_25_Kvik));
    setElement(document, "protrombine_12_Kvik", QString::number(protrombine_12_Kvik));
    setElement(document, "time_12_Kvik", QString::number(time_12_Kvik));
    setElement(document, "protrombine_index", QString::number(protrombine_index));
    setElement(document, "protrombine_otn", QString::number(protrombine_otn));

    Creator::writeFile(name, document);
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
        Creator::readFile(name, document);
    }
    else {
        document = Creator::createCalibration(name);
        QDomElement calibration = document.firstChildElement();
        calibration.appendChild(document.createElement("date"));
        calibration.appendChild(document.createElement("trombotsit_serial"));
        calibration.appendChild(document.createElement("trombotsit_date"));

        calibration.appendChild(document.createElement("trombotsit_concentration"));

        QDomElement write_time = document.createElement("write_time");
        write_time.setAttribute("Value", "10");
        calibration.appendChild(write_time);

        QDomElement incube_time = document.createElement("incube_time");
        incube_time.setAttribute("Value", "1");
        calibration.appendChild(incube_time);

        QDomElement incube_time_2 = document.createElement("incube_time_2");
        incube_time_2.setAttribute("Value", "3");
        calibration.appendChild(incube_time_2);

        //выходные данные
        calibration.appendChild(document.createElement("BTP1"));
        calibration.appendChild(document.createElement("BTP2"));
        calibration.appendChild(document.createElement("BTP3"));
        calibration.appendChild(document.createElement("BTP4"));

        calibration.appendChild(document.createElement("OTP1"));
        calibration.appendChild(document.createElement("OTP2"));
        calibration.appendChild(document.createElement("OTP3"));
        calibration.appendChild(document.createElement("OTP4"));

        calibration.appendChild(document.createElement("ckA1"));
        calibration.appendChild(document.createElement("ckA2"));
        calibration.appendChild(document.createElement("ckA3"));
        calibration.appendChild(document.createElement("ckA4"));

        Creator::writeFile(name, document);
    }
    load();
}

void CalibrationAgr1::load()
{
    Calibration::load();
    trombotsit_date = QDate::fromString(getElement(document, "trombotsit_date"), "yyyyMMdd");
    trombotsit_serial = getElement(document, "trombotsit_serial");
    trombotsit_concentration = getElement(document, "trombotsit_concentration").toDouble();
    incube_time_2 = getElement(document, "incube_time_2").toDouble();
    btp1 = getElement(document, "BTP1").toDouble();
    btp2 = getElement(document, "BTP2").toDouble();
    btp3 = getElement(document, "BTP3").toDouble();
    btp4 = getElement(document, "BTP4").toDouble();
    otp1 = getElement(document, "OTP1").toDouble();
    otp2 = getElement(document, "OTP2").toDouble();
    otp3 = getElement(document, "OTP3").toDouble();
    otp4 = getElement(document, "OTP4").toDouble();
    ckA1 = getElement(document, "ckA1").toDouble();
    ckA2 = getElement(document, "ckA2").toDouble();
    ckA3 = getElement(document, "ckA3").toDouble();
    ckA4 = getElement(document, "ckA4").toDouble();
}

void CalibrationAgr1::save()
{
    Calibration::save();
    setElement(document, "trombotsit_date", trombotsit_date.toString("yyyyMMdd"));
    setElement(document, "trombotsit_serial", trombotsit_serial);
    setElement(document, "trombotsit_concentration", QString::number(trombotsit_concentration));
    setElement(document, "incube_time_2", QString::number(incube_time_2));

    setElement(document, "BTP1", QString::number(btp1));
    setElement(document, "BTP2", QString::number(btp2));
    setElement(document, "BTP3", QString::number(btp3));
    setElement(document, "BTP4", QString::number(btp4));

    setElement(document, "OTP1", QString::number(otp1));
    setElement(document, "OTP2", QString::number(otp2));
    setElement(document, "OTP3", QString::number(otp3));
    setElement(document, "OTP4", QString::number(otp4));

    setElement(document, "ckA1", QString::number(ckA1));
    setElement(document, "ckA2", QString::number(ckA2));
    setElement(document, "ckA3", QString::number(ckA3));
    setElement(document, "ckA4", QString::number(ckA4));

    Creator::writeFile(name, document);
}

CalibrationAgr1::~CalibrationAgr1()
{
    //qDebug() << name << "~CalibrationAgr1()";
    save();
}

QDate CalibrationAgr1::getTrombotsit_date() const
{
    return trombotsit_date;
}

void CalibrationAgr1::setTrombotsit_date(const QDate &value)
{
    trombotsit_date = value;
}

QString CalibrationAgr1::getTrombotsit_serial() const
{
    return trombotsit_serial;
}

void CalibrationAgr1::setTrombotsit_serial(const QString &value)
{
    trombotsit_serial = value;
}

double CalibrationAgr1::getTrombotsit_concentration() const
{
    return trombotsit_concentration;
}

void CalibrationAgr1::setTrombotsit_concentration(double value)
{
    trombotsit_concentration = value;
}

double CalibrationAgr1::getIncube_time_2() const
{
    return incube_time_2;
}

void CalibrationAgr1::setIncube_time_2(double value)
{
    incube_time_2 = value;
}

double CalibrationAgr1::getOTP4() const
{
    return otp4;
}

void CalibrationAgr1::setOTP4(double value)
{
    otp4 = value;
}

double CalibrationAgr1::getCkA4() const
{
    return ckA4;
}

void CalibrationAgr1::setCkA4(double value)
{
    ckA4 = value;
}

double CalibrationAgr1::getCkA3() const
{
    return ckA3;
}

void CalibrationAgr1::setCkA3(double value)
{
    ckA3 = value;
}

double CalibrationAgr1::getCkA2() const
{
    return ckA2;
}

void CalibrationAgr1::setCkA2(double value)
{
    ckA2 = value;
}

double CalibrationAgr1::getCkA1() const
{
    return ckA1;
}

void CalibrationAgr1::setCkA1(double value)
{
    ckA1 = value;
}

double CalibrationAgr1::getOTP3() const
{
    return otp3;
}

void CalibrationAgr1::setOTP3(double value)
{
    otp3 = value;
}

double CalibrationAgr1::getOTP2() const
{
    return otp2;
}

void CalibrationAgr1::setOTP2(double value)
{
    otp2 = value;
}

double CalibrationAgr1::getOTP1() const
{
    return otp1;
}

void CalibrationAgr1::setOTP1(double value)
{
    otp1 = value;
}

double CalibrationAgr1::getBTP4() const
{
    return btp4;
}

void CalibrationAgr1::setBTP4(double value)
{
    btp4 = value;
}

double CalibrationAgr1::getBTP3() const
{
    return btp3;
}

void CalibrationAgr1::setBTP3(double value)
{
    btp3 = value;
}

double CalibrationAgr1::getBTP2() const
{
    return btp2;
}

void CalibrationAgr1::setBTP2(double value)
{
    btp2 = value;
}

double CalibrationAgr1::getBTP1() const
{
    return btp1;
}

void CalibrationAgr1::setBTP1(double value)
{
    btp1 = value;
}

CalibrationAgr2::CalibrationAgr2(QObject *parent) : Calibration("calibrationAgr2", parent)
{
    if( QFile::exists(name  + QString(".xml")) ) {
        Creator::readFile(name, document);
    }
    else {
        document = Creator::createCalibration(name);
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
        calibration.appendChild(incube_time_2);

        calibration.appendChild(document.createElement("k_plazma_serial"));
        calibration.appendChild(document.createElement("k_plazma_date"));
        calibration.appendChild(document.createElement("k_plazma"));
        //выходные данные
        calibration.appendChild(document.createElement("BTP1"));
        calibration.appendChild(document.createElement("BTP2"));
        calibration.appendChild(document.createElement("BTP3"));
        calibration.appendChild(document.createElement("BTP4"));

        calibration.appendChild(document.createElement("OTP1"));
        calibration.appendChild(document.createElement("OTP2"));
        calibration.appendChild(document.createElement("OTP3"));
        calibration.appendChild(document.createElement("OTP4"));

        calibration.appendChild(document.createElement("c1"));
        calibration.appendChild(document.createElement("ck1"));

        calibration.appendChild(document.createElement("c2"));
        calibration.appendChild(document.createElement("ck2"));

        calibration.appendChild(document.createElement("c3"));
        calibration.appendChild(document.createElement("ck3"));

        calibration.appendChild(document.createElement("c4"));
        calibration.appendChild(document.createElement("ck4"));
        Creator::writeFile(name, document);
    }
    load();
}

void CalibrationAgr2::load()
{
    Calibration::load();
    reagent_date = QDate::fromString(getElement(document, "reagent_date"), "yyyyMMdd");
    k_plazma_date = QDate::fromString(getElement(document, "k_plazma_date"), "yyyyMMdd");
    reagent_serial = getElement(document, "reagent_serial");
    k_plazma_serial = getElement(document, "k_plazma_serial");
    incube_time_2 = getElement(document, "incube_time_2").toDouble();
    k_plazma = getElement(document, "k_plazma").toDouble();

    btp1 = getElement(document, "BTP1").toDouble();
    btp2 = getElement(document, "BTP2").toDouble();
    btp3 = getElement(document, "BTP3").toDouble();
    btp4 = getElement(document, "BTP4").toDouble();

    otp1 = getElement(document, "OTP1").toDouble();
    otp2 = getElement(document, "OTP2").toDouble();
    otp3 = getElement(document, "OTP3").toDouble();
    otp4 = getElement(document, "OTP4").toDouble();

    c1 = getElement(document, "c1").toDouble();
    ck1 = getElement(document, "ck1").toDouble();
    c2 = getElement(document, "c2").toDouble();
    ck2 = getElement(document, "ck2").toDouble();
    c3 = getElement(document, "c3").toDouble();
    ck3 = getElement(document, "ck3").toDouble();
    c4 = getElement(document, "c4").toDouble();
    ck4 = getElement(document, "ck4").toDouble();
}

CalibrationAgr2::~CalibrationAgr2()
{
    //qDebug() << name << "~CalibrationAgr2()";
    save();
}

void CalibrationAgr2::save()
{
    Calibration::save();
    setElement(document, "reagent_date", reagent_date.toString("yyyyMMdd"));
    setElement(document, "k_plazma_date", k_plazma_date.toString("yyyyMMdd"));

    setElement(document, "reagent_serial", reagent_serial);
    setElement(document, "k_plazma_serial", k_plazma_serial);

    setElement(document, "incube_time_2", QString::number(incube_time_2));

    setElement(document, "k_plazma", QString::number(k_plazma));

    setElement(document, "BTP1", QString::number(btp1));
    setElement(document, "BTP2", QString::number(btp2));
    setElement(document, "BTP3", QString::number(btp3));
    setElement(document, "BTP4", QString::number(btp4));

    setElement(document, "OTP1", QString::number(otp1));
    setElement(document, "OTP2", QString::number(otp2));
    setElement(document, "OTP3", QString::number(otp3));
    setElement(document, "OTP4", QString::number(otp4));

    setElement(document, "c1", QString::number(c1));
    setElement(document, "ck1", QString::number(ck1));
    setElement(document, "c2", QString::number(c2));
    setElement(document, "ck2", QString::number(ck2));
    setElement(document, "c3", QString::number(c3));
    setElement(document, "ck3", QString::number(ck3));
    setElement(document, "c4", QString::number(c4));
    setElement(document, "ck4", QString::number(ck4));

    Creator::writeFile(name, document);
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

double CalibrationAgr2::getIncube_time_2() const
{
    return incube_time_2;
}

void CalibrationAgr2::setIncube_time_2(double value)
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

double CalibrationAgr2::getOTP4() const
{
    return otp4;
}

void CalibrationAgr2::setOTP4(double value)
{
    otp4 = value;
}

double CalibrationAgr2::getOTP3() const
{
    return otp3;
}

void CalibrationAgr2::setOTP3(double value)
{
    otp3 = value;
}

double CalibrationAgr2::getOTP2() const
{
    return otp2;
}

void CalibrationAgr2::setOTP2(double value)
{
    otp2 = value;
}

double CalibrationAgr2::getOTP1() const
{
    return otp1;
}

void CalibrationAgr2::setOTP1(double value)
{
    otp1 = value;
}

double CalibrationAgr2::getBTP4() const
{
    return btp4;
}

void CalibrationAgr2::setBTP4(double value)
{
    btp4 = value;
}

double CalibrationAgr2::getBTP3() const
{
    return btp3;
}

void CalibrationAgr2::setBTP3(double value)
{
    btp3 = value;
}

double CalibrationAgr2::getBTP2() const
{
    return btp2;
}

void CalibrationAgr2::setBTP2(double value)
{
    btp2 = value;
}

double CalibrationAgr2::getBTP1() const
{
    return btp1;
}

void CalibrationAgr2::setBTP1(double value)
{
    btp1 = value;
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

CalibrationKo4_1::CalibrationKo4_1(QObject *parent) : CalibrationKo4("calibrationKo4_1")
{

}

CalibrationKo4_1::~CalibrationKo4_1()
{

}

CalibrationKo4_2::CalibrationKo4_2(QObject *parent) : CalibrationKo4("calibrationKo4_2")
{

}

CalibrationKo4_2::~CalibrationKo4_2()
{

}

CalibrationKo4_3::CalibrationKo4_3(QObject *parent) : CalibrationKo4("calibrationKo4_3")
{

}

CalibrationKo4_3::~CalibrationKo4_3()
{

}

QString TestKo1::print()
{
//    хх.хх.хх   хх-хх
//    Режим коагулометра
//    Время свертывания
//    Проба №                         Тсв, сек
//    xxxxxxxxxxxxx                     хx,x
//    xxxxxxxxxxxxx                     хx,x
//    xxxxxxxxxxxxx                     хx,x
//    xxxxxxxxxxxxx                     хx,x
//    {Сообщения об ошибках}
    QString str =
    QString("%1 г., %2\n").arg(getDate().toString("d MMMM yyyy")).arg(getTime().toString("hh-mm")) +
    QString("Режим коагулометра\nВремя свертывания\nПроба №\tТсв, сек\n");
    if (getK1()) str += QString("%1\t\t%2\n").arg(getNum1()).arg(getT1());
    if (getK2()) str += QString("%1\t\t%2\n").arg(getNum2()).arg(getT2());
    if (getK3()) str += QString("%1\t\t%2\n").arg(getNum3()).arg(getT3());
    if (getK4()) str += QString("%1\t\t%2\n").arg(getNum4()).arg(getT4());
    return str;
}

QString TestKo2::print()
{
//    хх.хх.хх   хх-хх
//    Режим коагулометра
//    АЧТВ
//    Результаты измерений:
//    Проба №                           Tсв,  сек       ОТН
//    xxxxxxxxxxxxx                     хx,x            хх,хх
//    xxxxxxxxxxxxx                     хx,x            хх,хх
//    xxxxxxxxxxxxx                     хx,x            хх,хх
//    xxxxxxxxxxxxx                     хx,x            хх,хх
//    {Сообщения об ошибках}
    QString str =
    QString("%1 г., %2\n").arg(getDate().toString("d MMMM yyyy")).arg(getTime().toString("hh-mm")) +
    QString("Режим коагулометра\nАЧТВ\nРезультаты измерений:\nПроба №\tТсв, сек\tОТН\n");
    if(getK1()) str += QString("%1\t%2\t%3\n").arg(getNum1()).arg("AЧТВ1").arg("ОТН1");
    if(getK2()) str += QString("%1\t%2\t%3\n").arg(getNum2()).arg("AЧТВ2").arg("ОТН2");
    if(getK3()) str += QString("%1\t%2\t%3\n").arg(getNum3()).arg("AЧТВ3").arg("ОТН3");
    if(getK4()) str += QString("%1\t%2\t%3\n").arg(getNum4()).arg("AЧТВ4").arg("ОТН4");
    return str;
}

QString TestKo3::print()
{
//    хх.хх.хх   хх-хх
//    Режим коагулометра
//    Фибриноген
//    Результаты измерений:
//    Проба №              С, г/л
//    xxxxxxxxxxxxx        хх,хх
//    xxxxxxxxxxxxx        хх,хх
//    xxxxxxxxxxxxx        хх,хх
//    xxxxxxxxxxxxx        хх,хх
    QString str =
    QString("%1 г., %2\n").arg(getDate().toString("d MMMM yyyy")).arg(getTime().toString("hh-mm")) +
    QString("Режим коагулометра\nФибриноген\nРезультаты измерений:\nПроба №\tТВ, сек\tОТН\n");
    if(getK1()) str += QString("%1\t%2\t%3\n").arg(getNum1()).arg("Фибриноген1").arg("ОТН1");
    if(getK2()) str += QString("%1\t%2\t%3\n").arg(getNum2()).arg("Фибриноген2").arg("ОТН2");
    if(getK3()) str += QString("%1\t%2\t%3\n").arg(getNum3()).arg("Фибриноген3").arg("ОТН3");
    if(getK4()) str += QString("%1\t%2\t%3\n").arg(getNum4()).arg("Фибриноген4").arg("ОТН4");
    return str;
}

QString TestKo4::print()
{
//    хх.хх.хх   хх-хх
//    Режим коагулометра
//      Тромбин
//    Результаты измерений:
//    Проба №                           TВ,  сек             ОТН
//    xxxxxxxxxxxxx                     хx,x                 хх,хх
//    xxxxxxxxxxxxx                     хx,x                 хх,хх
//    xxxxxxxxxxxxx                     хx,x                 хх,хх
//    xxxxxxxxxxxxx                     хx,x                 хх,хх
//    {Сообщения об ошибках}
    QString str =
    QString("%1 г., %2\n").arg(getDate().toString("d MMMM yyyy")).arg(getTime().toString("hh-mm")) +
    QString("Режим коагулометра\nТромбин\nРезультаты измерений:\nПроба №\tС, г/л\n");
    if(getK1()) str += QString("%1\t%2\n").arg(getNum1()).arg("Тромбин1");
    if(getK2()) str += QString("%1\t%2\n").arg(getNum2()).arg("Тромбин2");
    if(getK3()) str += QString("%1\t%2\n").arg(getNum3()).arg("Тромбин3");
    if(getK4()) str += QString("%1\t%2\n").arg(getNum4()).arg("Тромбин4");
    return str;
}

QString TestKo5::print()
{
    //    22.02.07   11-30
    //    Протромбиновый комплекс
//    Результаты измерений:
//    Проба №       ПВ, сек     ПИ, %     ПО         ПРкв, %
//    хxxxxxxxxxxxx хх,х        хх,х      хх,хх      хх,х
//    хxxxxxxxxxxxx хх,х        хх,х      хх,хх      хх,х
//    хxxxxxxxxxxxx хх,х        хх,х      хх,хх      хх,х
//    хxxxxxxxxxxxx хх,х        хх,х      хх,х х     хх,х
    QString str =
    QString("%1 г., %2\n").arg(getDate().toString("d MMMM yyyy")).arg(getTime().toString("hh-mm")) +
    QString("Режим агрегометра\nПротромбиновый комплекс\nРезультаты измерений:\nПроба №\tПВ, сек\tПИ, \%\tПО\tПРкв, \%\t");
    if(getK1()) str += QString("%1\t%2\t%3\t%4\t%5\n").arg(getNum1()).arg("ПВ1").arg("ПИ1").arg("ПО1").arg("ПРкв1");
    if(getK2()) str += QString("%1\t%2\t%3\t%4\t%5\n").arg(getNum2()).arg("ПВ2").arg("ПИ2").arg("ПО2").arg("ПРкв2");
    if(getK3()) str += QString("%1\t%2\t%3\t%4\t%5\n").arg(getNum3()).arg("ПВ3").arg("ПИ3").arg("ПО3").arg("ПРкв3");
    if(getK4()) str += QString("%1\t%2\t%3\t%4\t%5\n").arg(getNum4()).arg("ПВ4").arg("ПИ4").arg("ПО4").arg("ПРкв4");
    return str;
}

QString TestAgr1::print()
{
//    хх.хх.хх   хх-хх
//    Режим агрегометра
//    Параметры агрегации тромбоцитов
//    №пробы                СтА    СкА   С, тр/мкл
//    xxxxxxxxxxxxx         хх,х   хх,х  хх,х
//    xxxxxxxxxxxxx         хх,х   хх,х  хх,х
//    xxxxxxxxxxxxx         хх,х   хх,х  хх,х
//    xxxxxxxxxxxxx         хх,х   хх,х  хх,х
///   нужны графики
    QString str =
    QString("%1 г., %2\n").arg(getDate().toString("d MMMM yyyy")).arg(getTime().toString("hh-mm")) +
    QString("Режим агрегометра\nПараметры агрегации тромбоцитов\nРезультаты измерений:\nПроба №\tСтА\tСкА\tС, тр/мкл\t");
    if(getK1()) str += QString("%1\t%2\t%3\t%4\n").arg(getNum1()).arg("СтА1").arg("СкА1").arg("С1").arg("ПРкв1");
    if(getK2()) str += QString("%1\t%2\t%3\t%4\n").arg(getNum2()).arg("СтА2").arg("СкА2").arg("С2").arg("ПРкв2");
    if(getK3()) str += QString("%1\t%2\t%3\t%4\n").arg(getNum3()).arg("СтА3").arg("СкА3").arg("С3").arg("ПРкв3");
    if(getK4()) str += QString("%1\t%2\t%3\t%4\n").arg(getNum4()).arg("СтА4").arg("СкА4").arg("С4").arg("ПРкв4");
    return str;
}

double TestAgr1::getBtp1() const
{
    return btp1;
}

void TestAgr1::setBtp1(double value)
{
    btp1 = value;
}

double TestAgr1::getBtp2() const
{
    return btp2;
}

void TestAgr1::setBtp2(double value)
{
    btp2 = value;
}

double TestAgr1::getBtp3() const
{
    return btp3;
}

void TestAgr1::setBtp3(double value)
{
    btp3 = value;
}

double TestAgr1::getBtp4() const
{
    return btp4;
}

void TestAgr1::setBtp4(double value)
{
    btp4 = value;
}

double TestAgr1::getOtp1() const
{
    return otp1;
}

void TestAgr1::setOtp1(double value)
{
    otp1 = value;
}

double TestAgr1::getOtp2() const
{
    return otp2;
}

void TestAgr1::setOtp2(double value)
{
    otp2 = value;
}

double TestAgr1::getOtp3() const
{
    return otp3;
}

void TestAgr1::setOtp3(double value)
{
    otp3 = value;
}

double TestAgr1::getOtp4() const
{
    return otp4;
}

void TestAgr1::setOtp4(double value)
{
    otp4 = value;
}

QString TestAgr2::print()
{
    //    хх.хх.хх   хх-хх
    //    Режим агрегометра
    //    Определение активности ф-ра Виллебранда
//    Результаты измерений:
//    Проба №             Ск, %/мин       С, г/л
//    xxxxxxxxxxxxx       хх,х            хх,х
//    xxxxxxxxxxxxx       хх,х            хх,х
//    xxxxxxxxxxxxx       хх,х            хх,х
//    xxxxxxxxxxxxx       хх,х            хх,х
    QString str =
    QString("%1 года, %2\n").arg(getDate().toString("d MMMM yyyy")).arg(getTime().toString("hh-mm")) +
    QString("Режим агрегометра\nОпределение активности ф-ра Виллебранда\nРезультаты измерений:\nПроба №\tСк, \%/мин\tС, г/л\t");
    if(getK1()) str += QString("%1\t%2\t%3\n").arg(getNum1()).arg("Ск1").arg("С1");
    if(getK2()) str += QString("%1\t%2\t%3\n").arg(getNum2()).arg("Ск2").arg("С2");
    if(getK3()) str += QString("%1\t%2\t%3\n").arg(getNum3()).arg("Ск3").arg("С3");
    if(getK4()) str += QString("%1\t%2\t%3\n").arg(getNum4()).arg("Ск4").arg("С4");
    return str;
}


QString CalibrationKo1::print()
{
    return QString("Калибровка в режиме \"Время свертывания\" Не проводится");
}

QString CalibrationKo2::print()
{
//    хх.хх.хх   хх-хх
//    Режим коагулометра
//          АЧТВ
//    Результаты калибровки:
//    Реагенты: хххххх (до хх.хх.хххх)
//    Плазма «К»: хххххх (до хх.хх.хххх)
//    АЧТВ к/плазмы (измеренное среднее), сек: хх,х
//    Время инкубации, сек: ххх
    //// getDate().toString("ddMMyyyy").remove(QChar::Space, Qt::CaseInsensitive).isEmpty()
    QString str;
    if( !getDate().isNull() ) {
        str =
        QString("%1 г., %2\n").arg(getDate().toString("d MMMM yyyy")).arg(getTime().toString("hh-mm")) +
        QString("Режим коагулометра\nАЧТВ\nРезультаты калибровки:\n") +
        QString("Реагенты: %1\t(до %2)\n").arg(getReagent_serial()).arg(getReagent_date().toString("yyyyMMdd")) +
        QString("Плазма «К»: %1\t(до %2)\n").arg(getK_plazma_serial()).arg(getK_plazma_date().toString("yyyyMMdd"));
        double a4tv = (getA4tv_kp1() + getA4tv_kp2() + getA4tv_kp3() + getA4tv_kp4())/4;
        str += QString("АЧТВ к/плазмы (измеренное среднее), сек:  %1\n").arg(QString::number(a4tv)) +
        QString("Время инкубации, сек: %1\n").arg(QString::number(getIncube_time()));
    } else return QString("Калибровка не проводилась");
    return str;
}

QString CalibrationKo3::print()
{
//    хх.хх.хх   хх-хх
//    Режим коагулометра
//      Фибриноген
//    Результаты калибровки:
//    Реагенты: хххххх (до хх.хх.хххх)
//    Плазма «К»: хххххх (до хх.хх.хххх)
//    Фибриноген в к/плазме, г/л: хх,хх
//    Разведение,%  200     100      50      25
//    в частях,1+   4       9        19      39
//    Тсв.,сек      хх,х    хх,х     хх,х   хх,х
//    Время инкубации, сек: ххх
    QString str;
    if( !getDate().isNull() ) {
        str =
        QString("%1 г., %2\n").arg(getDate().toString("d MMMM yyyy")).arg(getTime().toString("hh-mm")) +
        QString("Режим коагулометра\nФибриноген\nРезультаты калибровки:\n") +
        QString("Реагенты: %1\t(до %2)\n").arg(getReagent_serial()).arg(getReagent_date().toString("yyyyMMdd")) +
        QString("Плазма «К»: %1\t(до %2)\n").arg(getK_plazma_serial()).arg(getK_plazma_date().toString("yyyyMMdd")) +
        QString("Фибриноген в к/плазме, г/л: %1\n").arg(getFibrinogen_k_plazma()) +
        QString("Разведение,%\t200\t100\t50\t25\n") +
        QString("в частях,1+\t4\t9\t19\t39\n");
        str += QString("Тсв, сек\t%1\t%2\t%3\t%4\n")
                .arg(QString::number(getFibrinogen_200_plazma()))
                .arg(QString::number(getFibrinogen_k_plazma()))
                .arg(QString::number(getFibrinogen_50_plazma()))
                .arg(QString::number(getFibrinogen_25_plazma()));
        str += QString("Время инкубации, сек: %1\n").arg(QString::number(getIncube_time()));
    } else return QString("Калибровка не проводилась");
    return str;
}

QString CalibrationKo4::print()
{
//    хх.хх.хх   хх-хх
//    Режим коагулометра
//      Тромбин
//    Результаты калибровки:
//    Реагенты: хххххх (до хх.хх.хххх)
//    Плазма «К»: хххххх (до хх.хх.хххх)
//    Тромбин к/плазмы (измеренное среднее), сек: хх,х
//    Время инкубации, сек: ххх
    QString str;
    if( !getDate().isNull() ) {
        str =
        QString("%1 г., %2\n").arg(getDate().toString("d MMMM yyyy")).arg(getTime().toString("hh-mm")) +
        QString("Режим коагулометра\nТромбин\nРезультаты калибровки:\n") +
        QString("Реагенты: %1\t(до %2)\n").arg(getReagent_serial()).arg(getReagent_date().toString("yyyyMMdd")) +
        QString("Плазма «К»: %1\t(до %2)\n").arg(getK_plazma_serial()).arg(getK_plazma_date().toString("yyyyMMdd"));
        double tv = (getTv1() + getTv2() + getTv3() + getTv4())/4;
        str += QString("Тромбин в к/плазме, г/л: %1\n").arg(QString::number(tv)) +
        QString("Время инкубации, сек: %1\n").arg(QString::number(getIncube_time())) +
        QString("Активность тромбина %1\n").arg(QString::number(getActivity()));
    } else return QString("Калибровка для активноти тромбина %1 не проводилась").arg(QString::number(getActivity()));
    return str;
}

QString CalibrationKo5::print()
{
//    22.02.07   12-00
//      Протромбиновый комплекс
//    Результаты калибровки:
//    Реагенты: хххххх (до хх.хх.хххх)
//    Протромбин по Квику п/калибр, %: хх
//    МИЧ:хх,хх
//    ПО п/калибр: хх,хх
//    Время инкубации, сек: ххх
//    Разведение в %:   100     50     25     12,5
//    Тсв, сек:         хх,х    хх,х   хх,х   хх,х
    QString str;
    if( !getDate().isNull() ) {
        str =
        QString("%1 г., %2\n").arg(getDate().toString("d MMMM yyyy")).arg(getTime().toString("hh-mm")) +
        QString("Режим коагулометра\nПротромбиновый комплекс\nРезультаты калибровки:\n") +
        QString("Реагенты: %1\t(до %2)\n").arg(getReagent_serial()).arg(getReagent_date().toString("yyyyMMdd")) +
        QString("Протромбин по Квику п/калибр, %: %1\t(до %2)\n").arg(getTromboplastin_serial()).arg(getTromboplastin_date().toString("yyyyMMdd")) +
        QString("МИЧ: %1\n").arg(getK_protrombine_index()) +
        QString("ПО п/калибр: %1\n").arg(getK_protrombine_otn()) +
        QString("Разведение,%\t100\t50\t25\t12,5\n") +
        QString("Тсв, сек\t%1\t%2\t%3\t%4\n")
                .arg(QString::number(getProtrombine_k_Kvik()))
                .arg(QString::number(getProtrombine_50_Kvik()))
                .arg(QString::number(getProtrombine_25_Kvik()))
                .arg(QString::number(getProtrombine_12_Kvik())) +
        QString("Время инкубации, сек: %1\n").arg(QString::number(getIncube_time()));
    } else return QString("Калибровка не проводилась");
    return str;
}

QString CalibrationAgr1::print()
{
    return QString("Калибровка в режиме \"Агрегации тромбоцитов\" не проводится");
}

QString CalibrationAgr2::print()
{
//    хх.хх.хх   хх-хх
//    Режим агрегометра
//    Определение активности ф-ра Виллебранда
//      Результаты калибровки:
//    Реагенты: хххххх (до хх.хх.хххх)
//    Плазма «К»: хххххх (до хх.хх.хххх)
//    Активность фактора Виллебранда контрольной плазмы, %: хх,х
//    Разведение, %: 100    50      25
//    Ск, %/мин:        хх,х  хх,х  хх,х
//    Время записи агрегатограмм, мин: хх
//    Время инкубации №1, сек: ххх
//    Время инкубации №2, сек: ххх
    QString str;
    if( !getDate().isNull() ) {
        str =
        QString("%1 г., %2\n").arg(getDate().toString("d MMMM yyyy")).arg(getTime().toString("hh-mm")) +
        QString("Режим коагулометра\nОпределение активности ф-ра Виллебранда\nРезультаты калибровки:\n") +
        QString("Реагенты: %1\t(до %2)\n").arg(getReagent_serial()).arg(getReagent_date().toString("yyyyMMdd")) +
        QString("Плазма «К»: %1\t(до %2)\n").arg(getK_plazma()).arg(getK_plazma_date().toString("yyyyMMdd")) +
        QString("Активность фактора Виллебранда контрольной плазмы, %: %1\n").arg(getC2()) +
        QString("Разведение,%\t200\t100\t50\t25\n");
        str += QString("Тсв, сек\t%1\t%2\t%3\t%4\n")
                .arg(QString::number(getCk1()))
                .arg(QString::number(getCk2()))
                .arg(QString::number(getCk3()))
                .arg(QString::number(getCk4()));
        str += QString("Время инкубации №1, сек: %1\n").arg(QString::number(getIncube_time())) +
        QString("Время инкубации №2, сек: %1\n").arg(QString::number(getIncube_time_2()));
    } else return QString("Калибровка не проводилась");
    return str;
}


void TestAgr1::save()
{
    Test::save();
    setElement(document, "BTP1", QString::number(btp1));
    setElement(document, "BTP2", QString::number(btp2));
    setElement(document, "BTP3", QString::number(btp3));
    setElement(document, "BTP4", QString::number(btp4));

    setElement(document, "OTP1", QString::number(otp1));
    setElement(document, "OTP2", QString::number(otp2));
    setElement(document, "OTP3", QString::number(otp3));
    setElement(document, "OTP4", QString::number(otp4));
}

void TestAgr1::load()
{
    Test::load();
    btp1 = getElement(document, "BTP1").toDouble();
    btp2 = getElement(document, "BTP2").toDouble();
    btp3 = getElement(document, "BTP3").toDouble();
    btp4 = getElement(document, "BTP4").toDouble();

    otp1 = getElement(document, "OTP1").toDouble();
    otp2 = getElement(document, "OTP2").toDouble();
    otp3 = getElement(document, "OTP3").toDouble();
    otp4 = getElement(document, "OTP4").toDouble();
}
