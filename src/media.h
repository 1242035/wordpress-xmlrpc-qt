/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#ifndef __MEDIA_H
#define __MEDIA_H
#include "userblog.h"
class Media:public QObject
{
	Q_OBJECT
	private:
	QString datecreatedgmt;
    QString parent;
    QString link;
    QString thumbnail;
    QString title;
    QString caption;
    QString description;
    QString metadata;
    QString attachmentid;
    
    int size;
    QString tablename;
    Wordpress *Media_wp;
    Database *Media_db;
	public:
	Media();
	~Media();
	void Media_set_date_created_gmt(QString datecreatedgmt);
	void Media_set_parent(QString parent);
	void Media_set_link(QString link);
	void Media_set_thumbnail(QString thumbnail);
	void Media_set_title(QString title);
	void Media_set_caption(QString caption);
	void Media_set_description(QString description);
	void Media_set_metadata(QString metadata);
	void Media_set_attachmentid(QString attachmentid);
	
	QString Media_get_date_created_gmt();
	QString Media_get_parent();
	QString Media_get_link();
	QString Media_get_thumbnail();
	QString Media_get_title();
	QString Media_get_caption();
	QString Media_get_description();
	QString Media_get_metadata();
	QString Media_get_attachmentid();
	
	void Media_get_media();
	public slots:
	void Media_get_media_ok(QVariant);
	void Media_get_media_failed(int ,QString);
};
#endif
