#ifndef SITE_H
#define SITE_H

#include <QString>
#include <QDataStream>


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

//private:
    QString siteName;
    QString siteIpAddress;
    QString siteLang;
    QString sitePin;
    QString siteDescription;

};

#endif // SITE_H
