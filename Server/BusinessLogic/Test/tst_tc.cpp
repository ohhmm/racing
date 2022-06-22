#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class TC : public QObject
{
    Q_OBJECT

public:
    TC();
    ~TC();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

TC::TC()
{

}

TC::~TC()
{

}

void TC::initTestCase()
{

}

void TC::cleanupTestCase()
{

}

void TC::test_case1()
{

}

QTEST_MAIN(TC)

#include "tst_tc.moc"
