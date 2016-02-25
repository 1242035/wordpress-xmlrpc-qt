/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#ifndef __TAGS_H
#define __TAGS_H
#include "userblog.h"
class Tag:public QObject
{
	Q_OBJECT
private :
    int tag_id;
    QString name;
    QString slug;
    int count;
    QString html_url;
    QString rss_url;
    
    int size;
    Database *Tag_db;
    Wordpress *Tag_wp;
     QString tablename;
public :
        Tag();
        virtual ~Tag();
        void Tag_set_id(int id);
        void Tag_set_name(QString name);
        void Tag_set_slug(QString slug);
        void Tag_set_count(int count);
        void Tag_set_html_url(QString htmlurl);
        void Tag_set_rss_url(QString rssurl);
        void Tag_set_all(int id ,QString name ,QString slug ,int count ,QString htmlurl ,QString rssurl);
        int Tag_get_id();
        QString Tag_get_name();
        QString Tag_get_slug();
        int Tag_get_count();
        QString Tag_get_html_url();
        QString Tag_get_rss_url();
        QStringList Tag_map_to_qstringlist();
        void Tag_get_tag();
        void Tag_get_tag_from_db(int id);
public slots:
void Tag_get_ok(QVariant);
void Tag_get_failed(int ,QString);
};

#endif
