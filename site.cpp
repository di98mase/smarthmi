#include "site.h"


Site::Site()
{

    siteName = "no name";
    siteIpAddress = "0.0.0.0";
    siteLang = "Lang0";
    sitePin = "0000";
    siteDescription = "No site description";

}

Site::Site(QString sName, QString sIpAddress, QString sLang, QString sPin, QString sDescription)
{

    siteName = sName;
    siteIpAddress = sIpAddress;
    siteLang = sLang;
    sitePin = sPin;
    siteDescription = sDescription;
}

void Site::setAllParameters(QString sName, QString sIpAddress, QString sLang, QString sPin, QString sDescription)
{
    siteName = sName;
    siteIpAddress = sIpAddress;
    siteLang = sLang;
    sitePin = sPin;
    siteDescription = sDescription;
}
QString Site::getName(void)
{
    return this->siteName;
}
QString Site::getIp(void)
{
    return this->siteIpAddress;
}
QString Site::getDescription(void)
{
    return this->siteDescription;
}
QString Site::getPin(void)
{
    return this->sitePin;
}
QString Site::getLang(void)
{
    return this->siteLang;
}
QString Site::getAll(void)
{
    const QString allInOneString = this->siteName + this->siteIpAddress + this->siteLang + this->sitePin + this->siteDescription;
    return allInOneString;
}

inline QDataStream &operator<< (QDataStream &stream, Site &aSite)
{
   return stream << aSite.getAll();
}

// Hur skulle man göra denna funktion om man har gjort medlemsvariablen private. dvs måste sättas via funktioner?
inline QDataStream &operator>> (QDataStream &stream, Site &aSite)
{
   return stream >> aSite.siteName >> aSite.siteIpAddress >> aSite.siteLang >> aSite.sitePin >> aSite.siteDescription;
}
