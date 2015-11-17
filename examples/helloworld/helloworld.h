#include "qhttpserverfwd.h"

#include <QObject>
#include <QSslCertificate>
#include <QSslKey>
#include <QSslConfiguration>

/// HelloWorld

class HelloWorld : public QObject
{
    Q_OBJECT

public:
    HelloWorld();

private:
    QSslCertificate loadCertificate();
    QSslKey loadKey();
    QString getFileContent(QString path);
    QSslConfiguration *sslConf;

private slots:
    void handleRequest(QHttpRequest *req, QHttpResponse *resp);
};
