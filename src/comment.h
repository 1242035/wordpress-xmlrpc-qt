/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#ifndef __COMMENT_H
#define __COMMENT_H
#include "userblog.h"

class Comment:public QObject
{
	Q_OBJECT
private:
	QString comment_id;
    QString parent;
    QString user_id;
    QString datecreated;
    QString status;
    QString content;
    QString link;
    QString post_id;
    QString post_title;
    QString author;
    QString author_url;
    QString author_email;
    QString author_ip;
    QString type;
    
    //common variable
    int size;
    QString tablename;
    Wordpress *Comment_wp;
    Database *Comment_db;
public:
	Comment();
	virtual ~Comment();
	//set
	void Comment_set_comment_id(QString comment_id);
	void Comment_set_parent(QString parent);
	void Comment_set_user_id(QString user_id);
	void Comment_set_date_created(QString datecreated);
	void Comment_set_status(QString status);
	void Comment_set_content(QString content);
	void Comment_set_link(QString link);
	void Comment_set_post_id(QString post_id);
	void Comment_set_post_title(QString post_title);
	void Comment_set_author(QString author);
	void Comment_set_author_url(QString author_url);
	void Comment_set_author_email(QString author_email);
	void Comment_set_author_ip(QString author_ip);
	void Comment_set_type(QString type);
	//get
	QString Comment_get_comment_id();
	QString Comment_get_parent();
	QString Comment_get_user_id();
	QString Comment_get_date_created();
	QString Comment_get_status();
	QString Comment_get_content();
	QString Comment_get_link();
	QString Comment_get_post_id();
	QString Comment_get_post_title();
	QString Comment_get_author();
	QString Comment_get_author_url();
	QString Comment_get_author_email();
	QString Comment_get_author_ip();
	QString Comment_get_type();
	
	//action
	void Comment_get_comment();
	void Comment_get_all_comment();
public slots:
	void Comment_get_ok(QVariant);
	void Comment_get_failed(int ,QString);
};
#endif
