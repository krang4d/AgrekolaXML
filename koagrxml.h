#ifndef KOAGRXML_H
#define KOAGRXML_H

#include <QtXml>
#include <QDebug>
#include <QFile>
#include <QDate>
#include <QObject>
#include <QDir>

class Calibration;

class Creator
{
public:
    Creator() = delete;
    static QDomDocument createTest(QString name);
    static QDomDocument createCalibration(QString name);
    //static QDomDocument createTestAgr(QString name);
    static int writeFile(QString name, QDomDocument doc);
    static int readFile(QString name, QDomDocument &doc);

    static QDir getXMLDir();
};

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QString n, Calibration *c, QObject *parent = 0);
    virtual ~Test();
    void setK1(const int value);
    int getK1() const;
    void setK2(const int value);
    int getK2() const;
    void setK3(const int value);
    int getK3() const;
    void setK4(const int value);
    int getK4() const;
    void setSingle(const int value);
    int getSingle() const;

    QString getNum1() const;
    void setNum1(const QString &value);
    QString getNum2() const;
    void setNum2(const QString &value);
    QString getNum3() const;
    void setNum3(const QString &value);
    QString getNum4() const;
    void setNum4(const QString &value);

    QDate getDate() const;
    void setDate(const QDate &value);

    double getT1() const;
    void setT1(double value);
    double getT2() const;
    void setT2(double value);
    double getT3() const;
    void setT3(double value);
    double getT4() const;
    void setT4(double value);

    virtual double getIncubeTime();
    virtual double getWriteTime();
    virtual void save();
    virtual void load();

    QString getText() const;
    virtual QString print() = 0;

    void ListElement(QDomElement root, QString tagname, QString attribute);
    QString getElement(QDomDocument root, QString tagname, QString attribute = "Value");
    void setElement(QDomDocument &root, QString tagname, QString value, QString attribute = "Value");

protected:
    QDomDocument getDoc() const;
    QString getName() const;

protected:
    QDomDocument document;
    QString name;
    QDir dir;
    QDate date;

    int k1, k2, k3, k4, single;
    QString num1, num2, num3, num4;

    Calibration *c_ko;

private:
    double t1, t2, t3, t4;
};

class TestKo1 : public Test
{
    Q_OBJECT
public:
    explicit TestKo1(QObject *parent = 0);
    virtual ~TestKo1();

    // Test interface
public:
    QString print() override;
};

class WithoutCalibration {

};

class TestKo2 : public Test
{
    Q_OBJECT
public:
    explicit TestKo2(QObject *parent = 0);
    explicit TestKo2(WithoutCalibration, QObject *parent = 0);
    ~TestKo2();

    QDate getDate() const;
    void setDate(const QDate &value);
    QDate getReagent_date() const;
    void setReagent_date(const QDate &value);
    QString getReagent_serial() const;
    void setReagent_serial(const QString &value);
    double getWrite_time() const;
    void setWrite_time(double value);
    double getIncube_time() const;
    void setIncube_time(double value);
    double getA4tv_kp() const;
    void setA4tv_kp(double value);

    // Test interface
public:
    double getIncubeTime() override;
    double getWriteTime() override;
    void save() override;
    void load() override;
    QString print() override;

private:
    QDate date;
    QDate reagent_date;
    QString reagent_serial;
    double write_time, incube_time, a4tv_kp;
};

class TestKo3 : public Test
{
    Q_OBJECT
public:
    explicit TestKo3(QObject *parent = 0);
    ~TestKo3();

    // Test interface
public:
    QString print() override;
};

class TestKo4 : public Test
{
    Q_OBJECT
public:
    explicit TestKo4(QObject *parent = 0);
    explicit TestKo4(WithoutCalibration, QObject *parent = 0);
    ~TestKo4();

    QDate getDate() const;
    void setDate(const QDate &value);
    QDate getReagent_date() const;
    void setReagent_date(const QDate &value);
    QString getReagent_serial() const;
    void setReagent_serial(const QString &value);
    double getWrite_time() const;
    void setWrite_time(double value);
    double getIncube_time() const;
    void setIncube_time(double value);

    double getActivity() const;
    void setActivity(double value);

    double getTrombine_time() const;
    void setTrombine_time(double value);

    // Test interface
public:
    double getIncubeTime() override;
    double getWriteTime() override;
    void save() override;
    void load() override;
    QString print() override;

private:
    QDate date;
    QDate reagent_date;
    QString reagent_serial;
    double write_time, incube_time, activity, trombine_time;
};

class TestKo5 : public Test
{
    Q_OBJECT
public:
    explicit TestKo5(QObject *parent = 0);
    ~TestKo5();

    // Test interface
public:
    QString print() override;
};

class TestAgr1 : public Test
{
    Q_OBJECT
public:
    explicit TestAgr1(QObject *parent = 0);
    ~TestAgr1();

    double getIncubeTime2();

    // Test interface
public:
    QString print() override;
};

class TestAgr2 : public Test
{
    Q_OBJECT
public:
    explicit TestAgr2(QObject *parent = 0);
    ~TestAgr2();

    double getIncubeTime2();

    // Test interface
public:
    QString print() override;
};

class Calibration : public QObject
{
    Q_OBJECT
public:
    explicit Calibration(QString n, QObject *parent = 0);
    virtual ~Calibration();
    virtual void ListElement(QDomElement root, QString tagname, QString attribute);
    virtual QString getElement(QDomDocument root, QString tagname, QString attribute = "Value");
    virtual void setElement(QDomDocument &root, QString tagname, QString value, QString attribute = "Value");
    virtual void save();
    virtual void load();
    virtual QDate getDate() const;
    virtual void setDate(const QDate &value);
    double getWrite_time() const;
    void setWrite_time(const double value);
    double getIncube_time() const;
    void setIncube_time(const double value);
    bool getK1() const;
    void setK1(bool value);
    bool getK2() const;
    void setK2(bool value);
    bool getK3() const;
    void setK3(bool value);
    bool getK4() const;
    void setK4(bool value);

    virtual QString print() = 0;

protected:
    QDomDocument getDoc() const;
    QString getName() const;

protected:
    QDomDocument document;
    QString name;
    QDir dir;

private:
    QDate date;
    double write_time, incube_time;
    bool k1, k2, k3, k4;
};

class CalibrationKo1 : public Calibration
{
    Q_OBJECT
public:
    explicit CalibrationKo1(QObject *parent = 0);
    virtual ~CalibrationKo1();

    // Calibration interface
public:
    QString print() override;
};

class CalibrationKo2 : public Calibration
{
    Q_OBJECT
public:
    explicit CalibrationKo2(QObject *parent = 0);
    ~CalibrationKo2();

    QDate getReagent_date() const;
    void setReagent_date(const QDate &value);
    QDate getK_plazma_date() const;
    void setK_plazma_date(const QDate &value);
    QString getReagent_serial() const;
    void setReagent_serial(const QString &value);
    QString getK_plazma_serial() const;
    void setK_plazma_serial(const QString &value);
    double getA4tv_kp1() const;
    void setA4tv_kp1(double value);
    double getA4tv_kp2() const;
    void setA4tv_kp2(double value);
    double getA4tv_kp3() const;
    void setA4tv_kp3(double value);
    double getA4tv_kp4() const;
    void setA4tv_kp4(double value);
    double getK_plazma_a4tv() const;
    void setK_plazma_a4tv(double value);

private:
    //входные
    QDate reagent_date, k_plazma_date;
    QString reagent_serial, k_plazma_serial;
    double k_plazma_a4tv;
    //выходные
    double a4tv_kp1;
    double a4tv_kp2;
    double a4tv_kp3;
    double a4tv_kp4;

    // Calibration interface
public:
    void save() override;
    void load() override;
    QString print() override;
};

class CalibrationKo3 : public Calibration
{
    Q_OBJECT
public:
    explicit CalibrationKo3(QObject *parent = 0);
    ~CalibrationKo3();

    QDate getReagent_date() const;
    void setReagent_date(const QDate &value);
    QString getReagent_serial() const;
    void setReagent_serial(const QString &value);
    QDate getK_plazma_date() const;
    void setK_plazma_date(const QDate &value);
    QString getK_plazma_serial() const;
    void setK_plazma_serial(const QString &value);
    double getFibrinogen_k_plazma() const;
    void setFibrinogen_k_plazma(double value);
    double getTime_k_plazma() const;
    void setTime_k_plazma(double value);
    double getFibrinogen_200_plazma() const;
    void setFibrinogen_200_plazma(double value);
    double getTime_200_plazma() const;
    void setTime_200_plazma(double value);
    double getFibrinogen_50_plazma() const;
    void setFibrinogen_50_plazma(double value);
    double getTime_50_plazma() const;
    void setTime_50_plazma(double value);
    double getFibrinogen_25_plazma() const;
    void setFibrinogen_25_plazma(double value);
    double getTime_25_plazma() const;
    void setTime_25_plazma(double value);

private:
    QDate reagent_date, k_plazma_date;
    QString reagent_serial, k_plazma_serial;

    double fibrinogen_k_plazma, time_k_plazma;
    double fibrinogen_200_plazma, time_200_plazma;
    double fibrinogen_50_plazma, time_50_plazma;
    double fibrinogen_25_plazma, time_25_plazma;

    // Calibration interface
public:
    void save() override;
    void load() override;
    QString print() override;
};

class CalibrationKo4 : public Calibration
{
    Q_OBJECT
public:
    explicit CalibrationKo4(QObject *parent = 0);
    CalibrationKo4(QString name);
    virtual ~CalibrationKo4();

    QDate getReagent_date() const;
    void setReagent_date(const QDate &value);
    QString getReagent_serial() const;
    void setReagent_serial(const QString &value);
    QDate getK_plazma_date() const;
    void setK_plazma_date(const QDate &value);
    QString getK_plazma_serial() const;
    void setK_plazma_serial(const QString &value);

    double getTv1() const;
    void setTv1(double value);
    double getTv2() const;
    void setTv2(double value);
    double getTv3() const;
    void setTv3(double value);
    double getTv4() const;
    void setTv4(double value);
    int getActivity() const;
    void setActivity(const int &value);

    void save() override;
    void load() override;
    virtual QString print() override;

protected:
    void createElements();

private:
    QDate reagent_date, k_plazma_date;
    QString reagent_serial, k_plazma_serial;
    int activity; //активносит тромбина
    double tv1, tv2, tv3, tv4;
};

class CalibrationKo4_1 : public CalibrationKo4
{
    Q_OBJECT
public:
    explicit CalibrationKo4_1(QObject *parent = 0);
    ~CalibrationKo4_1();
};

class CalibrationKo4_2 : public CalibrationKo4
{
    Q_OBJECT
public:
    explicit CalibrationKo4_2(QObject *parent = 0);
    ~CalibrationKo4_2();
};

class CalibrationKo4_3 : public CalibrationKo4
{
    Q_OBJECT
public:
    explicit CalibrationKo4_3(QObject *parent = 0);
    ~CalibrationKo4_3();
};

class CalibrationKo5 : public Calibration
{
    Q_OBJECT
public:
    explicit CalibrationKo5(QObject *parent = 0);
    ~CalibrationKo5();

    QDate getReagent_date() const;
    void setReagent_date(const QDate &value);
    QString getReagent_serial() const;
    void setReagent_serial(const QString &value);
    QDate getTromboplastin_date() const;
    void setTromboplastin_date(const QDate &value);
    QDate getK_plazma_date() const;
    void setK_plazma_date(const QDate &value);
    QString getTromboplastin_serial() const;
    void setTromboplastin_serial(const QString &value);
    QString getK_plazma_serial() const;
    void setK_plazma_serial(const QString &value);
    double getK_protrombine_index() const;
    void setK_protrombine_index(double value);
    double getK_protrombine_otn() const;
    void setK_protrombine_otn(double value);
    double getProtrombine_k_Kvik() const;
    void setProtrombine_k_Kvik(double value);
    double getTime_k_Kvik() const;
    void setTime_k_Kvik(double value);
    double getProtrombine_50_Kvik() const;
    void setProtrombine_50_Kvik(double value);
    double getTime_50_Kvik() const;
    void setTime_50_Kvik(double value);
    double getProtrombine_25_Kvik() const;
    void setProtrombine_25_Kvik(double value);
    double getTime_25_Kvik() const;
    void setTime_25_Kvik(double value);
    double getProtrombine_12_Kvik() const;
    void setProtrombine_12_Kvik(double value);
    double getTime_12_Kvik() const;
    void setTime_12_Kvik(double value);
    double getProtrombine_index() const;
    void setProtrombine_index(double value);
    double getProtrombine_otn() const;
    void setProtrombine_otn(double value);

private:
    QDate reagent_date, tromboplastin_date, k_plazma_date;
    QString reagent_serial, tromboplastin_serial, k_plazma_serial;
    double k_protrombine_index, k_protrombine_otn;
    double protrombine_k_Kvik, time_k_Kvik;
    double protrombine_50_Kvik, time_50_Kvik;
    double protrombine_25_Kvik, time_25_Kvik;
    double protrombine_12_Kvik, time_12_Kvik;
    double protrombine_index, protrombine_otn;

    // Calibration interface
public:
    void save() override;
    void load() override;
    QString print() override;
};

class CalibrationAgr1 : public Calibration
{
    Q_OBJECT
public:
    explicit CalibrationAgr1(QObject *parent = 0);
    ~CalibrationAgr1();

    QDate getTrombotsit_date() const;
    void setTrombotsit_date(const QDate &value);
    QString getTrombotsit_serial() const;
    void setTrombotsit_serial(const QString &value);
    double getTrombotsit_concentration() const;
    void setTrombotsit_concentration(double value);
    double getIncube_time_2() const;
    void setIncube_time_2(double value);
    double getBTP1() const;
    void setBTP1(double value);
    double getBTP2() const;
    void setBTP2(double value);
    double getBTP3() const;
    void setBTP3(double value);
    double getBTP4() const;
    void setBTP4(double value);
    double getOTP1() const;
    void setOTP1(double value);
    double getOTP2() const;
    void setOTP2(double value);
    double getOTP3() const;
    void setOTP3(double value);
    double getOTP4() const;
    void setOTP4(double value);
    double getCkA1() const;
    void setCkA1(double value);
    double getCkA2() const;
    void setCkA2(double value);
    double getCkA3() const;
    void setCkA3(double value);
    double getCkA4() const;
    void setCkA4(double value);

private:
    QDate trombotsit_date;
    QString trombotsit_serial;
    double trombotsit_concentration;
    double incube_time_2;
    double ckA1, ckA2, ckA3, ckA4;
    double btp1, btp2, btp3, btp4;
    double otp1, otp2, otp3, otp4;

    // Calibration interface
public:
    void save() override;
    void load() override;
    QString print() override;
};

class CalibrationAgr2 : public Calibration
{
    Q_OBJECT
public:
    explicit CalibrationAgr2(QObject *parent = 0);
    ~CalibrationAgr2();

    QDate getReagent_date() const;
    void setReagent_date(const QDate &value);
    QDate getK_plazma_date() const;
    void setK_plazma_date(const QDate &value);
    double getIncube_time_2() const;
    void setIncube_time_2(double value);
    QString getReagent_serial() const;
    void setReagent_serial(const QString &value);
    QString getK_plazma_serial() const;
    void setK_plazma_serial(const QString &value);
    double getK_plazma() const;
    void setK_plazma(double value);
    double getBTP1() const;
    void setBTP1(double value);
    double getBTP2() const;
    void setBTP2(double value);
    double getBTP3() const;
    void setBTP3(double value);
    double getBTP4() const;
    void setBTP4(double value);
    double getOTP1() const;
    void setOTP1(double value);
    double getOTP2() const;
    void setOTP2(double value);
    double getOTP3() const;
    void setOTP3(double value);
    double getOTP4() const;
    void setOTP4(double value);
    double getC1() const;
    void setC1(double value);
    double getCk1() const;
    void setCk1(double value);
    double getC2() const;
    void setC2(double value);
    double getCk2() const;
    void setCk2(double value);
    double getC3() const;
    void setC3(double value);
    double getCk3() const;
    void setCk3(double value);
    double getC4() const;
    void setC4(double value);
    double getCk4() const;
    void setCk4(double value);

private:
    QDate reagent_date, k_plazma_date;
    QString reagent_serial, k_plazma_serial;

    double incube_time_2;
    double k_plazma;
    double c1, ck1, c2, ck2, c3, ck3, c4, ck4;
    double btp1, btp2, btp3, btp4;
    double otp1, otp2, otp3, otp4;

    // Calibration interface
public:
    void save() override;
    void load() override;
    QString print() override;
};
#endif // KOAGRXML_H
