#include "koagrxml.h"

QDomDocument createTestKo(QString name){
    QDomDocument document;
    QDomElement test = document.createElement(name);
    document.appendChild(test);
    test.appendChild(document.createElement("single"));
    test.appendChild(document.createElement("k1"));
    test.appendChild(document.createElement("k2"));
    test.appendChild(document.createElement("k3"));
    test.appendChild(document.createElement("k4"));
    test.appendChild(document.createElement("write_time"));
    test.appendChild(document.createElement("incube_time"));
    return document;
}

QDomDocument createTestAgr(QString name){
    QDomDocument document = createTestKo(name);
    QDomElement test = document.firstChildElement(name);
    test.appendChild(document.createElement("incube_time_2"));
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
    calibration.appendChild(document.createElement("trombine_time"));
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
    calibration.appendChild(document.createElement("incube_time"));
    calibration.appendChild(document.createElement("reagent_serial"));
    calibration.appendChild(document.createElement("reagent_data"));
    calibration.appendChild(document.createElement("k_concentration"));
    //выходные данные
    calibration.appendChild(document.createElement("level_0"));
    calibration.appendChild(document.createElement("level_100"));
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
    calibration.appendChild(document.createElement("incube_time"));
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

    writeFile(name, document);
    return document;
}

QDomDocument KoAgrXML::openTestKo1()
{
    QDomDocument doc;
    QString name("testKo1");
    readFile(name, doc);
    return doc;
}

QDomDocument KoAgrXML::openTestKo2()
{
    QDomDocument doc;
    QString name("testKo2");
    readFile(name, doc);
    return doc;
}

QDomDocument KoAgrXML::openTestKo3()
{
    QDomDocument doc;
    QString name("testKo3");
    readFile(name, doc);
    return doc;
}

QDomDocument KoAgrXML::openTestKo4()
{
    QDomDocument doc;
    QString name("testKo3");
    readFile(name, doc);
    return doc;
}

QDomDocument KoAgrXML::openTestKo5()
{
    QDomDocument doc;
    QString name("testKo5");
    readFile(name, doc);
    return doc;
}

QDomDocument KoAgrXML::openTestAgr1()
{
    QDomDocument doc;
    QString name("testAgr1");
    readFile(name, doc);
    return doc;
}

QDomDocument KoAgrXML::openTestAgr2()
{
    QDomDocument doc;
    QString name("testAgr2");
    readFile(name, doc);
    return doc;
}

QDomDocument KoAgrXML::openCalibrationKo2()
{
    QDomDocument doc;
    QString name("calibrationKo2");
    readFile(name, doc);
    return doc;
}

QDomDocument KoAgrXML::openCalibrationKo3()
{
    QDomDocument doc;
    QString name("calibrationKo3");
    readFile(name, doc);
    return doc;
}

QDomDocument KoAgrXML::openCalibrationKo4()
{
    QDomDocument doc;
    QString name("calibrationKo4");
    readFile(name, doc);
    return doc;
}

QDomDocument KoAgrXML::openCalibrationKo5()
{
    QDomDocument doc;
    QString name("calibrationKo5");
    readFile(name, doc);
    return doc;
}

QDomDocument KoAgrXML::openCalibrationAgr1()
{
    QDomDocument doc;
    QString name("calibrationAgr1");
    readFile(name, doc);
    return doc;
}

QDomDocument KoAgrXML::openCalibrationAgr2()
{
    QDomDocument doc;
    QString name("calibrationAgr2");
    readFile(name, doc);
    return doc;
}
