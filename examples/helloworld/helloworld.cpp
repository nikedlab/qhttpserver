#include "helloworld.h"

#include <QCoreApplication>

#include <qhttpserver.h>
#include <qhttprequest.h>
#include <qhttpresponse.h>

#include <QFile>

/// HelloWorld

HelloWorld::HelloWorld()
{
    QSslConfiguration sslConf;
    sslConf.setLocalCertificate(loadCertificate());
    sslConf.setPrivateKey(loadKey());
    QHttpServer *server = new QHttpServer(sslConf, this);
    connect(server, SIGNAL(newRequest(QHttpRequest*, QHttpResponse*)), this, SLOT(handleRequest(QHttpRequest*, QHttpResponse*)));

    server->listen(QHostAddress::Any, 21185);
}

void HelloWorld::handleRequest(QHttpRequest *req, QHttpResponse *resp)
{
    Q_UNUSED(req);
    QByteArray body = "Hello World";
    resp->setHeader("Content-Length", QString::number(body.size()));
    resp->writeHead(200);
    resp->end(body);
}

/// main

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    HelloWorld hello;
    app.exec();
}

QSslCertificate HelloWorld::loadCertificate() {
    QString certContent = getFileContent(":/server.crt");
    return QSslCertificate(certContent.toUtf8(), QSsl::Pem);
}

QSslKey HelloWorld::loadKey() {
    QString keyContent = getFileContent(":/server.key");
    return QSslKey(keyContent.toUtf8(), QSsl::Rsa, QSsl::Pem);
}

QString HelloWorld::getFileContent(QString path)
{
    QFile file(path);
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        qCritical() << "Can't load SSL file: " << path;
    }

    QTextStream in(&file);
    QString text = in.readAll();
    file.close();
    return text;
}
