#include "koagrxml.h"
//#include "typeinfo"
#define R_VAL 10
#define ROUND(x) ( round(x * 100) / 100 )

Creator::Creator(QObject *parent) : QObject(parent)
{
    dir = Creator::getXMLDir();
    QDir::setCurrent(dir.path());
}

int Creator::writeFile()
{
    QFile file(name + QString(".xml"));
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Faild to open file for write";
        return -1;
    } else {
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        stream << document.toString();
        stream.flush();
        file.close();
    }
    file.close();
    return 0;
}

int Creator::readFile()
{
    QString errstr;
    QFile file(name + QString(".xml"));
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Faild to open file for read";
        return -1;
    } else {
        if(!document.setContent(&file, &errstr)) {
            qDebug() << "Failed to load document: " << errstr;
            return -2;
        }
        file.close();
    }
    file.close();
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
    }
    if(!dir.cd("XML"))
    {
        if(dir.mkdir("XML")) dir.cd("XML");
    }
    return dir;
}

QString Creator::getText() const
{
    return document.toString();
}

QDomDocument Creator::getDoc() const
{
    return document;
}

QString Creator::getName() const
{
    return name;
}

void Creator::ListElement(QString tagname, QString attribute)
{
    QDomElement root = document.documentElement();
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

QString Creator::getElement(QString tagname, QString attribute)
{
    QDomNodeList items = document.elementsByTagName(tagname);
    QDomNode itemnode = items.at(0);
    if( itemnode.isElement()) {
        QDomElement itemelement = itemnode.toElement();
        return itemelement.attribute(attribute);
    } else return QString("not find!");
}

void Creator::setElement(QString tagname, QString value, QString attribute)
{
    QDomNodeList items = document.elementsByTagName(tagname);
    QDomNode itemnode = items.at(0);
    if( itemnode.isElement()) {
        QDomElement itemelement = itemnode.toElement();
        itemelement.setAttribute(attribute, value);
    }
}

Test::Test(QString n, QObject *parent) : Creator(parent)
{
    name = n;
}

QDomDocument Test::createTest(const QString &name)
{
    QDomElement test = document.createElement(name);
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
    document.appendChild(test);

    return document;
}

void Test::load()
{
    Creator::readFile();
    k1 = getElement("k1").toInt();
    num1 = getElement("k1", "Num");
    t1 = getElement("k1", "t1").toDouble();

    k2 = getElement("k2").toInt();
    num2 = getElement("k2", "Num");
    t2 = getElement("k2", "t2").toDouble();

    k3 = getElement("k3").toInt();
    num3 = getElement("k3", "Num");
    t3 = getElement("k3", "t3").toDouble();

    k4 = getElement("k4").toInt();
    num4 = getElement("k4", "Num");
    t4 = getElement("k4", "t4").toDouble();

    single = getElement("single").toInt();
    date = QDate::fromString(getElement("date"), "yyyyMMdd");
    time = QTime::fromString(getElement("time"), "hhmm");
}

Test::~Test()
{
    save();
}

void Test::create(Test *c)
{
    if( QFile::exists(name  + QString(".xml")) ) {
        c->load();
    }
    else {
        c->createTest(name);
        Creator::writeFile();
    }
}

void Test::save()
{
    setElement("k1", QString("%1").arg(k1));
    setElement("k1", num1, "Num");
    setElement("k1", QString::number(t1), "t1");

    setElement("k2", QString("%1").arg(k2));
    setElement("k2", num2, "Num");
    setElement("k2", QString::number(t2), "t2");

    setElement("k3", QString("%1").arg(k3));
    setElement("k3", num3, "Num");
    setElement("k3", QString::number(t3), "t3");

    setElement("k4", QString("%1").arg(k4));
    setElement("k4", num4, "Num");
    setElement("k4", QString::number(t4), "t4");

    setElement("single", QString("%1").arg(single));
    setElement("date", date.toString("yyyyMMdd"));
    setElement("time", time.toString("hhmm"));
    Creator::writeFile();
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

//double Test::getIncubeTime()
//{
//    c_ko->load();
//    return c_ko->getIncube_time();
//}

//double Test::getWriteTime()
//{
//    c_ko->load();
//    return c_ko->getWrite_time();
//}

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
    create(this);
}

TestKo1::~TestKo1()
{
}

TestKo2::TestKo2(QObject *parent)
    : Test("testKo2_1", parent)
{
    create(this);
}

TestKo2::TestKo2(WithoutCalibration, QObject *parent)
    : Test("testKo2_2", parent)
{
    create(this);
}

TestKo2::~TestKo2()
{
    save();
}

void TestKo2::save()
{
    setElement("date", date.toString("yyyyMMdd"));
    setElement("reagent_date", reagent_date.toString("yyyyMMdd"));
    setElement("reagent_serial", reagent_serial);
    setElement("write_time", QString::number(write_time));
    setElement("incube_time", QString::number(incube_time));
    setElement("a4tv_kp", QString::number(a4tv_kp));
    Test::save();
}

void TestKo2::load()
{
    date = QDate::fromString(getElement("date"), "yyyyMMdd");
    reagent_date = QDate::fromString(getElement("reagent_date"), "yyyyMMdd");
    reagent_serial = getElement("reagent_serial");
    write_time = getElement("write_time").toDouble();
    incube_time = getElement("incube_time").toDouble();
    a4tv_kp = getElement("a4tv_kp").toDouble();
    Test::load();
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
    : Test("testKo3", parent)
{
    create(this);
}

TestKo3::~TestKo3()
{
    save();
}

TestKo4::TestKo4(QObject *parent)
    : Test("testKo4_1", parent)
{
    create(this);
}

TestKo4::TestKo4(WithoutCalibration, QObject *parent) : Test("testKo4_2", parent)
{
    create(this);
}

TestKo4::~TestKo4()
{
    save();
}

void TestKo4::save()
{
    setElement("date", date.toString("yyyyMMdd"));
    setElement("reagent_date", reagent_date.toString("yyyyMMdd"));
    setElement("reagent_serial", reagent_serial);
    setElement("write_time", QString::number(write_time));
    setElement("incube_time", QString::number(incube_time));
    setElement("activity", QString::number(activity));
    setElement("trombine_time", QString::number(trombine_time));
    Test::save();
}

void TestKo4::load()
{
    date = QDate::fromString(getElement("date"), "yyyyMMdd");
    reagent_date = QDate::fromString(getElement("reagent_date"), "yyyyMMdd");
    reagent_serial = getElement("reagent_serial");
    write_time = getElement("write_time").toDouble();
    incube_time = getElement("incube_time").toDouble();
    activity = getElement("activity").toInt();
    trombine_time = getElement("trombine_time").toDouble();
    Test::load();
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
    : Test("testKo5", parent)
{
    create(this);
}

TestKo5::~TestKo5()
{
    save();
}

TestAgr1::TestAgr1(QObject *parent)
    : Test("testAgr1", parent)
{
    create(this);
}

TestAgr1::~TestAgr1()
{
    save();
}

//double TestAgr1::getIncubeTime1()
//{
//    return incube_time1;
//}

//double TestAgr1::getIncubeTime2()
//{
//    return incube_time2;
////    CalibrationAgr1* obj = qobject_cast<CalibrationAgr1*>(c_ko);
////    if(!obj) {
////        qDebug() << "errore at TestAgr1::getIncubeTime2() - qobject_cast is null";
////        return 0;
////    }
////    obj->load();
////    return obj->getIncube_time_2();
//////    CalibrationAgr1 *obj;
//////    if(typeid(c_ko) == typeid(CalibrationAgr1))
//////        obj = dynamic_cast<CalibrationAgr1*>(c_ko);
//////    obj->load();
//    ////    return obj->getIncubeTime2();
//}

//double TestAgr1::getWriteTime()
//{
//    return write_time;
//}

TestAgr2::TestAgr2(QObject *parent)
    : Test("testAgr2", parent)
{
    create(this);
}

TestAgr2::~TestAgr2()
{
    save();
}

Calibration::Calibration(QString n, QObject *parent) : Creator(parent)
{
    name = n;
}

QDomDocument Calibration::createCalibration(const QString &name)
{
    QDomElement calibration = document.createElement(name);
    calibration.appendChild(document.createElement("date"));
    calibration.appendChild(document.createElement("time"));
    QDomElement write_time = document.createElement("write_time");
    write_time.setAttribute("Value", "10");
    calibration.appendChild(write_time);

    QDomElement incube_time = document.createElement("incube_time");
    incube_time.setAttribute("Value", "1");
    calibration.appendChild(incube_time);

    document.appendChild(calibration);
    return document;
}

void Calibration::create(Calibration *c)
{
    if( QFile::exists(name  + QString(".xml")) ) {
        c->load();
    }
    else {
        c->createCalibration(name);
        Creator::writeFile();
    }
}

void Calibration::load()
{
    Creator::readFile();
    date = QDate::fromString(getElement("date"), "yyyyMMdd");
    time = QTime::fromString(getElement("time"), "hhmm");
    write_time = getElement("write_time").toDouble();
    incube_time = getElement("incube_time").toDouble();
}

Calibration::~Calibration()
{
    save();
}

void Calibration::save()
{
    QDir::setCurrent(dir.path());
    setElement("date", date.toString("yyyyMMdd"));
    setElement("time", time.toString("hhmm"));
    setElement("write_time", QString::number(write_time));
    setElement("incube_time", QString::number(incube_time));
    Creator::writeFile();
}

void Calibration::setIncube_time(const double value)
{
    incube_time = value;
}

QTime Calibration::getTime() const
{
    return time;
}

void Calibration::setTime(const QTime &value)
{
    time = value;
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
    create(this);
}

CalibrationKo1::~CalibrationKo1()
{
    save();
}

CalibrationKo2::CalibrationKo2(QObject *parent)
    : Calibration("calibrationKo2", parent)
{
    create(this);
}

void CalibrationKo2::load()
{
    Calibration::load();
    reagent_date = QDate::fromString(getElement("reagent_date"), "yyyyMMdd");
    reagent_serial = getElement("reagent_serial");
    k_plazma_date = QDate::fromString(getElement("k_plazma_date"), "yyyyMMdd");
    k_plazma_serial = getElement("k_plazma_serial");
    k_plazma_a4tv = getElement("k_plazma_a4tv").toDouble();
    a4tv_kp1 = getElement("a4tv_kp1").toDouble();
    a4tv_kp2 = getElement("a4tv_kp2").toDouble();
    a4tv_kp3 = getElement("a4tv_kp3").toDouble();
    a4tv_kp4 = getElement("a4tv_kp4").toDouble();
}

CalibrationKo2::~CalibrationKo2()
{
    save();
}

void CalibrationKo2::save()
{
    setElement("reagent_date", reagent_date.toString("yyyyMMdd"));
    setElement("reagent_serial", reagent_serial);
    setElement("k_plazma_date", k_plazma_date.toString("yyyyMMdd"));
    setElement("k_plazma_serial", k_plazma_serial);
    setElement("k_plazma_a4tv", QString::number(k_plazma_a4tv));
    setElement("a4tv_kp1", QString::number(a4tv_kp1));
    setElement("a4tv_kp2", QString::number(a4tv_kp2));
    setElement("a4tv_kp3", QString::number(a4tv_kp3));
    setElement("a4tv_kp4", QString::number(a4tv_kp4));
    Calibration::save();
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
    create(this);
}

void CalibrationKo3::load()
{
    Calibration::load();
    reagent_date = QDate::fromString(getElement("reagent_date"), "yyyyMMdd");
    reagent_serial = getElement("reagent_serial");
    k_plazma_date = QDate::fromString(getElement("k_plazma_date"), "yyyyMMdd");
    k_plazma_serial = getElement("k_plazma_serial");
    fibrinogen_k_plazma = getElement("fibrinogen_k_plazma").toDouble();
    time_k_plazma = getElement("time_k_plazma").toDouble();
    fibrinogen_200_plazma = getElement("fibrinogen_200_plazma").toDouble();
    time_200_plazma = getElement("time_200_plazma").toDouble();
    fibrinogen_50_plazma = getElement("fibrinogen_50_plazma").toDouble();
    time_50_plazma = getElement("time_50_plazma").toDouble();
    fibrinogen_25_plazma = getElement("fibrinogen_25_plazma").toDouble();
    time_25_plazma = getElement("time_25_plazma").toDouble();
}

CalibrationKo3::~CalibrationKo3()
{
    save();
}

void CalibrationKo3::save()
{
    setElement("reagent_date", reagent_date.toString("yyyyMMdd"));
    setElement("reagent_serial", reagent_serial);

    setElement("k_plazma_date", k_plazma_date.toString("yyyyMMdd"));
    setElement("k_plazma_serial", k_plazma_serial);

    setElement("fibrinogen_k_plazma", QString::number(fibrinogen_k_plazma));
    setElement("time_k_plazma", QString::number(time_k_plazma));

    setElement("fibrinogen_200_plazma", QString::number(fibrinogen_200_plazma));
    setElement("time_200_plazma", QString::number(time_200_plazma));

    setElement("fibrinogen_50_plazma", QString::number(fibrinogen_50_plazma));
    setElement("time_50_plazma", QString::number(time_50_plazma));

    setElement("fibrinogen_25_plazma", QString::number(fibrinogen_25_plazma));
    setElement("time_25_plazma", QString::number(time_25_plazma));
    Calibration::save();
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
    create(this);
}

CalibrationKo4::CalibrationKo4(QString name, QObject *parent)
    : Calibration(name, parent)
{
    create(this);
}


QDomDocument CalibrationKo4::createCalibration(const QString &name)
{
    document = Calibration::createCalibration(name);
    QDomElement calibration = document.firstChildElement();
    calibration.appendChild(document.createElement("reagent_serial"));
    calibration.appendChild(document.createElement("reagent_date"));
    calibration.appendChild(document.createElement("k_plazma_serial"));
    calibration.appendChild(document.createElement("k_plazma_date"));
    calibration.appendChild(document.createElement("activity"));
    calibration.appendChild(document.createElement("tv1"));
    calibration.appendChild(document.createElement("tv2"));
    calibration.appendChild(document.createElement("tv3"));
    calibration.appendChild(document.createElement("tv4"));
    return document;
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
    reagent_date = QDate::fromString(getElement("reagent_date"), "yyyyMMdd");
    reagent_serial = getElement("reagent_serial");
    k_plazma_date = QDate::fromString(getElement("k_plazma_date"), "yyyyMMdd");
    k_plazma_serial = getElement("k_plazma_serial");
    activity = getElement("activity").toDouble();
    tv1 = getElement("tv1").toDouble();
    tv2 = getElement("tv2").toDouble();
    tv3 = getElement("tv3").toDouble();
    tv4 = getElement("tv4").toDouble();
}

CalibrationKo4::~CalibrationKo4()
{
    save();
}

void CalibrationKo4::save()
{
    setElement("reagent_date", reagent_date.toString("yyyyMMdd"));
    setElement("k_plazma_date", k_plazma_date.toString("yyyyMMdd"));
    setElement("reagent_serial", reagent_serial);
    setElement("k_plazma_serial", k_plazma_serial);
    setElement("activity", QString::number(activity));
    setElement("tv1", QString::number(tv1));
    setElement("tv2", QString::number(tv2));
    setElement("tv3", QString::number(tv3));
    setElement("tv4", QString::number(tv4));
    Calibration::save();
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

CalibrationKo5::CalibrationKo5(QObject *parent)
    : Calibration("calibrationKo5", parent)
{
    create(this);
}

void CalibrationKo5::load()
{
    Calibration::load();
    reagent_date = QDate::fromString(getElement("reagent_date"), "yyyyMMdd");
    reagent_serial = getElement("reagent_serial");
    tromboplastin_date = QDate::fromString(getElement("tromboplastin_date"), "yyyyMMdd");
    tromboplastin_serial = getElement("tromboplastin_serial");
    k_plazma_date = QDate::fromString(getElement("k_plazma_date"), "yyyyMMdd");
    k_plazma_serial = getElement("k_plazma_serial");
    k_protrombine_index = getElement("k_protrombine_index").toDouble();
    k_protrombine_otn = getElement("k_protrombine_otn").toDouble();
    protrombine_k_Kvik = getElement("protrombine_k_Kvik").toDouble();
    time_k_Kvik = getElement("time_k_Kvik").toDouble();
    protrombine_50_Kvik = getElement("protrombine_50_Kvik").toDouble();
    time_50_Kvik = getElement("time_50_Kvik").toDouble();
    protrombine_25_Kvik = getElement("protrombine_25_Kvik").toDouble();
    time_25_Kvik = getElement("time_25_Kvik").toDouble();
    protrombine_12_Kvik = getElement("protrombine_12_Kvik").toDouble();
    time_12_Kvik = getElement("time_12_Kvik").toDouble();
    protrombine_index = getElement("protrombine_index").toDouble();
    protrombine_otn = getElement("protrombine_otn").toDouble();
}

CalibrationKo5::~CalibrationKo5()
{
    save();
}

void CalibrationKo5::save()
{
    setElement("reagent_date",  reagent_date.toString("yyyyMMdd"));
    setElement("reagent_serial", reagent_serial);

    setElement("tromboplastin_date", tromboplastin_date.toString("yyyyMMdd"));
    setElement("tromboplastin_serial", tromboplastin_serial);

    setElement("k_plazma_date", k_plazma_date.toString("yyyyMMdd"));
    setElement("k_plazma_serial", k_plazma_serial);

    setElement("k_protrombine_index", QString::number(k_protrombine_index));
    setElement("k_protrombine_otn", QString::number(k_protrombine_otn));
    setElement("protrombine_k_Kvik", QString::number(protrombine_k_Kvik));
    setElement("time_k_Kvik", QString::number(time_k_Kvik));
    setElement("protrombine_50_Kvik", QString::number(protrombine_50_Kvik));
    setElement("time_50_Kvik", QString::number(time_50_Kvik));
    setElement("protrombine_25_Kvik", QString::number(protrombine_25_Kvik));
    setElement("time_25_Kvik", QString::number(time_25_Kvik));
    setElement("protrombine_12_Kvik", QString::number(protrombine_12_Kvik));
    setElement("time_12_Kvik", QString::number(time_12_Kvik));
    setElement("protrombine_index", QString::number(protrombine_index));
    setElement("protrombine_otn", QString::number(protrombine_otn));
    Calibration::save();
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
    create(this);
}

void CalibrationAgr1::load()
{
    Calibration::load();
    trombotsit_date = QDate::fromString(getElement("trombotsit_date"), "yyyyMMdd");
    trombotsit_serial = getElement("trombotsit_serial");
    trombotsit_concentration = getElement("trombotsit_concentration").toDouble();
    incube_time_2 = getElement("incube_time_2").toDouble();
    btp1 = getElement("BTP1").toDouble();
    btp2 = getElement("BTP2").toDouble();
    btp3 = getElement("BTP3").toDouble();
    btp4 = getElement("BTP4").toDouble();
    otp1 = getElement("OTP1").toDouble();
    otp2 = getElement("OTP2").toDouble();
    otp3 = getElement("OTP3").toDouble();
    otp4 = getElement("OTP4").toDouble();
    ckA1 = getElement("ckA1").toDouble();
    ckA2 = getElement("ckA2").toDouble();
    ckA3 = getElement("ckA3").toDouble();
    ckA4 = getElement("ckA4").toDouble();
}

void CalibrationAgr1::save()
{
    setElement("trombotsit_date", trombotsit_date.toString("yyyyMMdd"));
    setElement("trombotsit_serial", trombotsit_serial);
    setElement("trombotsit_concentration", QString::number(trombotsit_concentration));
    setElement("incube_time_2", QString::number(incube_time_2));

    setElement("BTP1", QString::number(btp1));
    setElement("BTP2", QString::number(btp2));
    setElement("BTP3", QString::number(btp3));
    setElement("BTP4", QString::number(btp4));

    setElement("OTP1", QString::number(otp1));
    setElement("OTP2", QString::number(otp2));
    setElement("OTP3", QString::number(otp3));
    setElement("OTP4", QString::number(otp4));

    setElement("ckA1", QString::number(ckA1));
    setElement("ckA2", QString::number(ckA2));
    setElement("ckA3", QString::number(ckA3));
    setElement("ckA4", QString::number(ckA4));
    Calibration::save();
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
    create(this);
}

void CalibrationAgr2::load()
{
    Calibration::load();
    reagent_date = QDate::fromString(getElement("reagent_date"), "yyyyMMdd");
    k_plazma_date = QDate::fromString(getElement("k_plazma_date"), "yyyyMMdd");
    reagent_serial = getElement("reagent_serial");
    k_plazma_serial = getElement("k_plazma_serial");
    incube_time_2 = getElement("incube_time_2").toDouble();
    k_plazma = getElement("k_plazma").toDouble();

    btp1 = getElement("BTP1").toDouble();
    btp2 = getElement("BTP2").toDouble();
    btp3 = getElement("BTP3").toDouble();
    btp4 = getElement("BTP4").toDouble();

    otp1 = getElement("OTP1").toDouble();
    otp2 = getElement("OTP2").toDouble();
    otp3 = getElement("OTP3").toDouble();
    otp4 = getElement("OTP4").toDouble();

    c1 = getElement("c1").toDouble();
    ck1 = getElement("ck1").toDouble();
    c2 = getElement("c2").toDouble();
    ck2 = getElement("ck2").toDouble();
    c3 = getElement("c3").toDouble();
    ck3 = getElement("ck3").toDouble();
    c4 = getElement("c4").toDouble();
    ck4 = getElement("ck4").toDouble();
}

CalibrationAgr2::~CalibrationAgr2()
{
    //qDebug() << name << "~CalibrationAgr2()";
    save();
}

void CalibrationAgr2::save()
{
    Calibration::save();
    setElement("reagent_date", reagent_date.toString("yyyyMMdd"));
    setElement("k_plazma_date", k_plazma_date.toString("yyyyMMdd"));

    setElement("reagent_serial", reagent_serial);
    setElement("k_plazma_serial", k_plazma_serial);

    setElement("incube_time_2", QString::number(incube_time_2));

    setElement("k_plazma", QString::number(k_plazma));

    setElement("BTP1", QString::number(btp1));
    setElement("BTP2", QString::number(btp2));
    setElement("BTP3", QString::number(btp3));
    setElement("BTP4", QString::number(btp4));

    setElement("OTP1", QString::number(otp1));
    setElement("OTP2", QString::number(otp2));
    setElement("OTP3", QString::number(otp3));
    setElement("OTP4", QString::number(otp4));

    setElement("c1", QString::number(c1));
    setElement("ck1", QString::number(ck1));
    setElement("c2", QString::number(c2));
    setElement("ck2", QString::number(ck2));
    setElement("c3", QString::number(c3));
    setElement("ck3", QString::number(ck3));
    setElement("c4", QString::number(c4));
    setElement("ck4", QString::number(ck4));

    Creator::writeFile();
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
    if (getK1()) str += QString("%1\t\t%2\n")
            .arg(getNum1())
            .arg(ROUND(getT1()));
    if (getK2()) str += QString("%1\t\t%2\n")
            .arg(getNum2())
            .arg(ROUND(getT2()));
    if (getK3()) str += QString("%1\t\t%2\n")
            .arg(getNum3())
            .arg(ROUND(getT3()));
    if (getK4()) str += QString("%1\t\t%2\n")
            .arg(getNum4())
            .arg(ROUND(getT4()));
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
    if(getK1()) str += QString("%1\t%2\t%3\n")
            .arg(getNum1())
            .arg(ROUND(getT1()))
            .arg(ROUND(getT1()/getA4tv_kp()));
    if(getK2()) str += QString("%1\t%2\t%3\n")
            .arg(getNum2())
            .arg(ROUND(getT2()))
            .arg(ROUND(getT2()/getA4tv_kp()));
    if(getK3()) str += QString("%1\t%2\t%3\n")
            .arg(getNum3())
            .arg(ROUND(getT3()))
            .arg(ROUND(getT3()/getA4tv_kp()));
    if(getK4()) str += QString("%1\t%2\t%3\n")
            .arg(getNum4())
            .arg(ROUND(getT4()))
            .arg(ROUND(getT4()/getA4tv_kp()));
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
    if(getK1()) str += QString("%1\t%2\n").arg(getNum1()).arg(ROUND(getT1()));
    if(getK2()) str += QString("%1\t%2\n").arg(getNum2()).arg(ROUND(getT2()));
    if(getK3()) str += QString("%1\t%2\n").arg(getNum3()).arg(ROUND(getT3()));
    if(getK4()) str += QString("%1\t%2\n").arg(getNum4()).arg(ROUND(getT4()));
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
    if(getK1()) str += QString("%1\t%2\n").arg(getNum1()).arg(ROUND(getT1()));
    if(getK2()) str += QString("%1\t%2\n").arg(getNum2()).arg(ROUND(getT2()));
    if(getK3()) str += QString("%1\t%2\n").arg(getNum3()).arg(ROUND(getT3()));
    if(getK4()) str += QString("%1\t%2\n").arg(getNum4()).arg(ROUND(getT4()));
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

QString TestAgr1::getInductor() const
{
    return inductor;
}

void TestAgr1::setInductor(const QString &value)
{
    inductor = value;
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
    if(getK1()) str += QString("%1\t%2\t%3\n").arg(getNum1()).arg(ROUND(getT1())).arg("С1");
    if(getK2()) str += QString("%1\t%2\t%3\n").arg(getNum2()).arg(ROUND(getT2())).arg("С2");
    if(getK3()) str += QString("%1\t%2\t%3\n").arg(getNum3()).arg(ROUND(getT3())).arg("С3");
    if(getK4()) str += QString("%1\t%2\t%3\n").arg(getNum4()).arg(ROUND(getT4())).arg("С4");
    return str;
}

QString TestAgr2::getInductor() const
{
    return inductor;
}

void TestAgr2::setInductor(const QString &value)
{
    inductor = value;
}

double TestAgr2::getBtp1() const
{
    return btp1;
}

void TestAgr2::setBtp1(double value)
{
    btp1 = value;
}

double TestAgr2::getBtp2() const
{
    return btp2;
}

void TestAgr2::setBtp2(double value)
{
    btp2 = value;
}

double TestAgr2::getBtp3() const
{
    return btp3;
}

void TestAgr2::setBtp3(double value)
{
    btp3 = value;
}

double TestAgr2::getBtp4() const
{
    return btp4;
}

void TestAgr2::setBtp4(double value)
{
    btp4 = value;
}

double TestAgr2::getOtp1() const
{
    return otp1;
}

void TestAgr2::setOtp1(double value)
{
    otp1 = value;
}

double TestAgr2::getOtp2() const
{
    return otp2;
}

void TestAgr2::setOtp2(double value)
{
    otp2 = value;
}

double TestAgr2::getOtp3() const
{
    return otp3;
}

void TestAgr2::setOtp3(double value)
{
    otp3 = value;
}

double TestAgr2::getOtp4() const
{
    return otp4;
}

void TestAgr2::setOtp4(double value)
{
    otp4 = value;
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
        a4tv = ROUND(a4tv);
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
        QString("Реагенты: %1\t(до %2)\n").arg(getReagent_serial()).arg(getReagent_date().toString("dd.MM.yyyy")) +
        QString("Плазма «К»: %1\t(до %2)\n").arg(getK_plazma_serial()).arg(getK_plazma_date().toString("dd.MM.yyyy")) +
        QString("Фибриноген в к/плазме, г/л: %1\n").arg(getFibrinogen_k_plazma()) +
        QString("Разведение,%\t200\t100\t50\t25\n") +
        QString("в частях,1+\t4\t9\t19\t39\n");

        double t1 = getTime_200_plazma();
        double t2 = getTime_k_plazma();
        double t3 = getTime_50_plazma();
        double t4 = getTime_25_plazma();
        t1 = ROUND(t1);
        t2 = ROUND(t2);
        t3 = ROUND(t3);
        t4 = ROUND(t4);
        str += QString("Тсв, сек\t%1\t%2\t%3\t%4\n").arg(t1).arg(t2).arg(t3).arg(t4);
        str += QString("Время инкубации, сек: %1\n").arg(getIncube_time());
        if( (t1 >= t2*1.2) && (t2 >= t3*1.2) && (t3 >= t4*1.2) ) ;
        else str += QString("Ошибка: Нет соответствия критерию возрастания\n");
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
        str += QString("Тромбин в к/плазме, г/л: %1\n").arg(QString::number(ROUND(tv))) +
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
                .arg(QString::number(ROUND(getProtrombine_k_Kvik())))
                .arg(QString::number(ROUND(getProtrombine_50_Kvik())))
                .arg(QString::number(ROUND(getProtrombine_25_Kvik())))
                .arg(QString::number(ROUND(getProtrombine_12_Kvik()))) +
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
//    Разведение, %: 100    50     25  12.5
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
        QString("Разведение,%\t100\t50\t25\t12.5\n");
        str += QString("Тсв, сек\t%1\t%2\t%3\t%4\n")
                .arg(QString::number(ROUND(getCk1())))
                .arg(QString::number(ROUND(getCk2())))
                .arg(QString::number(ROUND(getCk3())))
                .arg(QString::number(ROUND(getCk4())));
        str += QString("Время инкубации №1, сек: %1\n").arg(QString::number(getIncube_time())) +
        QString("Время инкубации №2, сек: %1\n").arg(QString::number(getIncube_time_2()));
    } else return QString("Калибровка не проводилась");
    return str;
}


void TestAgr1::save()
{
    setElement("BTP1", inductor);
    setElement("BTP1", QString::number(btp1));
    setElement("BTP2", QString::number(btp2));
    setElement("BTP3", QString::number(btp3));
    setElement("BTP4", QString::number(btp4));

    setElement("OTP1", QString::number(otp1));
    setElement("OTP2", QString::number(otp2));
    setElement("OTP3", QString::number(otp3));
    setElement("OTP4", QString::number(otp4));
    Test::save();
}

void TestAgr1::load()
{
    inductor = getElement("inductor");
    btp1 = getElement("BTP1").toDouble();
    btp2 = getElement("BTP2").toDouble();
    btp3 = getElement("BTP3").toDouble();
    btp4 = getElement("BTP4").toDouble();

    otp1 = getElement("OTP1").toDouble();
    otp2 = getElement("OTP2").toDouble();
    otp3 = getElement("OTP3").toDouble();
    otp4 = getElement("OTP4").toDouble();
    Test::load();
}


QDomDocument TestKo2::createTest(const QString &name)
{
    Test::createTest(name);
    QDomElement calibration = document.firstChildElement();
    calibration.appendChild(document.createElement("reagent_serial"));
    calibration.appendChild(document.createElement("reagent_date"));
    calibration.appendChild(document.createElement("a4tv_kp"));

    QDomElement write_time = document.createElement("write_time");
    write_time.setAttribute("Value", "10");
    calibration.appendChild(write_time);

    QDomElement incube_time = document.createElement("incube_time");
    incube_time.setAttribute("Value", "3");
    calibration.appendChild(incube_time);
    document.appendChild(calibration);
    return document;
}

QDomDocument TestKo4::createTest(const QString &name)
{
    Test::createTest(name);
    QDomElement calibration = document.firstChildElement();
    calibration.appendChild(document.createElement("reagent_serial"));
    calibration.appendChild(document.createElement("reagent_date"));
    calibration.appendChild(document.createElement("activity"));
    calibration.appendChild(document.createElement("trombine_time"));
    document.appendChild(calibration);
    return document;
}

QDomDocument TestAgr1::createTest(const QString &name)
{
    Test::createTest(name);
    QDomElement calibration = document.firstChildElement();
    calibration.appendChild(document.createElement("inductor"));
    //выходные данные
    calibration.appendChild(document.createElement("BTP1"));
    calibration.appendChild(document.createElement("BTP2"));
    calibration.appendChild(document.createElement("BTP3"));
    calibration.appendChild(document.createElement("BTP4"));

    calibration.appendChild(document.createElement("OTP1"));
    calibration.appendChild(document.createElement("OTP2"));
    calibration.appendChild(document.createElement("OTP3"));
    calibration.appendChild(document.createElement("OTP4"));
    document.appendChild(calibration);
    return document;
}

QDomDocument TestAgr2::createTest(const QString &name)
{
    Test::createTest(name);
    QDomElement calibration = document.firstChildElement();
    calibration.appendChild(document.createElement("inductor"));
    //выходные данные
    calibration.appendChild(document.createElement("BTP1"));
    calibration.appendChild(document.createElement("BTP2"));
    calibration.appendChild(document.createElement("BTP3"));
    calibration.appendChild(document.createElement("BTP4"));

    calibration.appendChild(document.createElement("OTP1"));
    calibration.appendChild(document.createElement("OTP2"));
    calibration.appendChild(document.createElement("OTP3"));
    calibration.appendChild(document.createElement("OTP4"));

    return document;
}

void TestAgr2::save()
{
    setElement("BTP1", inductor);
    setElement("BTP1", QString::number(btp1));
    setElement("BTP2", QString::number(btp2));
    setElement("BTP3", QString::number(btp3));
    setElement("BTP4", QString::number(btp4));

    setElement("OTP1", QString::number(otp1));
    setElement("OTP2", QString::number(otp2));
    setElement("OTP3", QString::number(otp3));
    setElement("OTP4", QString::number(otp4));
    Test::save();
}

void TestAgr2::load()
{  
    inductor = getElement("inductor");
    btp1 = getElement("BTP1").toDouble();
    btp2 = getElement("BTP2").toDouble();
    btp3 = getElement("BTP3").toDouble();
    btp4 = getElement("BTP4").toDouble();

    otp1 = getElement("OTP1").toDouble();
    otp2 = getElement("OTP2").toDouble();
    otp3 = getElement("OTP3").toDouble();
    otp4 = getElement("OTP4").toDouble();
    Test::load();
}

QDomDocument CalibrationKo2::createCalibration(const QString &name)
{
    Calibration::createCalibration(name);
    QDomElement calibration = document.firstChildElement();
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
    document.appendChild(calibration);
    return document;
}

QDomDocument CalibrationKo3::createCalibration(const QString &name)
{
    Calibration::createCalibration(name);
    QDomElement calibration = document.firstChildElement();
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
    document.appendChild(calibration);
    return document;
}

QDomDocument CalibrationKo5::createCalibration(const QString &name)
{
    Calibration::createCalibration(name);
    QDomElement calibration = document.firstChildElement();
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
    return document;
}

QDomDocument CalibrationAgr1::createCalibration(const QString &name)
{
    document = Calibration::createCalibration(name);
    QDomElement calibration = document.firstChildElement();
    calibration.appendChild(document.createElement("trombotsit_serial"));
    calibration.appendChild(document.createElement("trombotsit_date"));

    calibration.appendChild(document.createElement("trombotsit_concentration"));

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
    return document;
}

QDomDocument CalibrationAgr2::createCalibration(const QString &name)
{
    document = Calibration::createCalibration(name);
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
    document.appendChild(calibration);
    return document;
}
