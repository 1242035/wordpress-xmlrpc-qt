/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#ifndef __CAP_H
#define __CAP_H
#include "userblog.h"

class Cap
{
	private:
	QString manage_terms;
    QString edit_terms;
    QString delete_terms;
    QString assign_terms;
	
	QString tablename;
	int size;
	Database *Cap_db;
	public:
	Cap();
	virtual ~Cap();
	QString Cap_get_manage_terms();
	QString Cap_get_edit_terms();
	QString Cap_get_delete_terms();
	QString Cap_get_assign_terms();
	void Cap_set_manage_terms(QString manage_terms);
	void Cap_set_edit_terms(QString edit_terms);
	void Cap_set_delete_terms(QString delete_terms);
	void Cap_set_assign_terms(QString assign_terms);
	
	//get size
	int Cap_get_size();
	void Cap_insert_db();
	int Cap_get_id();
};
#endif
