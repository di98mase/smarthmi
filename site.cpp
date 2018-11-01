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

QDataStream &operator <<(QDataStream &out,const Site &aSite)
{
    out << aSite.siteName << aSite.siteIpAddress << aSite.siteLang << aSite.sitePin << aSite.siteDescription;
    return out;
}

QDataStream &operator >>(QDataStream &in, Site &aSite)
{
    //QString sName,sIp,sDesc,sLang,sPin;

    in >> aSite.siteName;
    in >> aSite.siteIpAddress;
    in >> aSite.siteLang;
    in >> aSite.sitePin;
    in >> aSite.siteDescription;
    //aSite = Site(sName, sIp, sLang, sPin, sDesc);
    return in;
}

QTextStream &operator <<(QTextStream &out,const Site &aSite)
{
   out << aSite.siteName << aSite.siteIpAddress << aSite.siteLang << aSite.sitePin << aSite.siteDescription << endl;
   return out;
}

QTextStream &operator >>(QTextStream &in, Site &aSite)
{
    QString sName;
    QString sIp;
    QString sDesc;
    QString sLang;
    QString sPin;

    in >> sName << sIp << sLang << sPin << sDesc;
    aSite = Site(sName, sIp, sLang, sPin, sDesc);
    return in;

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

bool Site::operator== (const Site &s)
{
  bool areEqual=false;
  if ( siteDescription == s.siteDescription &&
       siteIpAddress == s.siteIpAddress &&
       sitePin == s.sitePin &&
       siteLang == s.siteLang &&
       siteDescription == s.siteDescription)
  {
      areEqual = true;
  }
  return areEqual;
}
