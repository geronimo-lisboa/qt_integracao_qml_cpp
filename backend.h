#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
//Os objetos que serão usados dentro da QML devem ser todos herdeiros de QObject
class Backend : public QObject
{
    Q_OBJECT
    //É através de properties que a QML enxerga valores e lida com as mudanças nos valores via property binding
    Q_PROPERTY(QString userName //nome da propriedade
               READ userName //função que retorna o valor
               WRITE setUserName //função que seta o valor
               NOTIFY userNameChanged)//nome do signal que notifica alteração pro property binding
public:
    explicit Backend(QObject *parent = nullptr);
    QString userName();
    void setUserName(const QString &userName);
    //Com o Q_INVOKABLE essa função pode ser chamada do mundo da QML
    Q_INVOKABLE void printSomethingInConsole();
signals:
    void userNameChanged();

public slots:

private:
    QString m_userName;
};

#endif // BACKEND_H
