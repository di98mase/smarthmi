#ifndef SITE_H
#define SITE_H

#include <QString>
#include <QDataStream>
#include <QTextStream>


class Site
{
public:
    Site();
    Site(QString sName, QString sIpAddress, QString sLang, QString sPin, QString sDescription);

    void setAllParameters(QString sName, QString sIpAddress, QString sLang, QString sPin, QString sDescription);
    QString getName (void);
    QString getIp(void);
    QString getDescription(void);
    QString getPin(void);
    QString getLang(void);
    QString getAll(void);

    bool operator== (const Site &s);

//private:
    QString siteName;
    QString siteIpAddress;
    QString siteLang;
    QString sitePin;
    QString siteDescription;

};

QDataStream &operator <<(QDataStream &out,const Site &aSite);
QDataStream &operator >>(QDataStream &in, Site &aSite);

QTextStream &operator <<(QTextStream &out,const Site &aSite);
QTextStream &operator >>(QTextStream &in, Site &aSite);


#endif // SITE_H
