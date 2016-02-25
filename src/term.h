/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#ifndef __TERM_H
#define __TERM_H
#include "userblog.h"

class Term:public QObject
{
	Q_OBJECT
	private:
	QString term_id;
    QString name;
    QString slug;
    QString term_group;
    QString term_taxonomy_id;
    QString taxonomy;
    QString description;
    QString parent;
    int count;
    
    int size;
    QString tablename;
    Wordpress *Term_wp;
    Database *Term_db;
    public slots: 
		void Term_get_term_ok(QVariant);
		void Term_get_term_failed(int ,QString);
	public :
		Term();
		virtual ~Term();
	QString Term_get_term_id();
	QString Term_get_name();
	QString Term_get_slug();
	QString Term_get_term_group();
	QString Term_get_term_taxonomy_id();
	QString Term_get_taxonomy();
	QString Term_get_decription();
	QString Term_get_parent();
	int Term_get_count();
	
	void Term_set_term_id(QString term_id);
	void Term_set_name(QString name);
	void Term_set_slug(QString slug);
	void Term_set_term_group(QString term_group);
	void Term_set_term_taxonomy_id(QString term_taconomy_id);
	void Term_set_taxonomy(QString taxonomy);
	void Term_set_decription(QString description);
	void Term_set_parent(QString parent);
	void Term_set_count(int count);
	
	void Term_get_terms();
	void Term_insert_db();
};
#endif
