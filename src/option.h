/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#ifndef __OPTION_H
#define __OPTION_H
#include "userblog.h"
class Option:public QObject
{
	Q_OBJECT
        private:
	QString option_name;
	QString desc;
    QString value;
    bool readonly ;
    
    QString tablename;
    int size;
    Wordpress *Option_wp;
    Database *Option_db;
    public:
    Option();
    virtual ~Option();
    void Option_get_option();
    void Option_get_option_from_db(int id);
     
	void Option_set_desc(QString);
	void Option_set_value(QString);
	void Option_set_readonly(bool);
	void Option_set_name(QString);
	void Option_set_all(QString ,QString ,bool);
    QString Option_get_desc();
    QString Option_get_value();
    bool Option_get_readonly();
    QString Option_get_name();
   
    public slots:
    void Option_get_ok(QVariant);
    void Option_get_failed(int ,QString);

};
#endif
