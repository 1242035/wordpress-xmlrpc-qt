/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#ifndef __CATEGORIES_H
#define __CATEGORIES_H
#include "userblog.h"
class Category: public QObject
{
Q_OBJECT
private:
    QString categoryid;
    QString parentid;
    QString categoryname;
    QString categorydescription;
    QString description;// Name of the category, equivalent to categoryName.
    QString htmlurl;
    QString rssurl;
    
    int size ;
    int type;
    Wordpress *Category_wp;
    Database *Category_db;
    QString tablename;
public:
Category();
virtual ~Category();
void Category_set_id(QString categoryid);
void Category_set_parentid(QString parentid);
void Category_set_name(QString categoryname);
void Category_set_categorydescripton(QString categorydescription);
void Category_set_description(QString description);
void Category_set_htmlurl(QString htmlurl);
void Category_set_rssurl(QString rssurl);
void Category_set_all(QString categoryid,QString parentid ,QString categoryname,\
                        QString categorydescription,QString description,QString htmlurl,QString rssurl);
QString Category_get_id();
QString Category_get_parentid();
QString Category_get_name();
QString Category_get_categorydescripton();
QString Category_get_description();
QString Category_get_htmlurl();
QString Category_get_rssurl();
QStringList Category_map_to_qstringlist();

void Category_get_category();
public slots:
void Category_map_from_error(int ,QString);
void Category_map_from_result(QVariant );

};
#endif
