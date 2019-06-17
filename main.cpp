#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "backend.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    //Registra o tipo Backend na QML no pacote dado, com a versão dada e com o nome dado.
    //Esse mecanismo de registro é para o objetos que podem ser instanciados (não serve pra
    //singletons por ex).
    qmlRegisterType<Backend>("don.geronimo.backend",1,0, "Backend");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
