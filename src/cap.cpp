/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#include "cap.h"
Cap::Cap(){
this->size = 4;
this->tablename = "cap";
this->Cap_db = new Database();	
}
Cap::~Cap(){
delete this->Cap_db;	
}
QString Cap::Cap_get_manage_terms(){return this->manage_terms ;}
QString Cap::Cap_get_edit_terms(){return this->edit_terms ;}
QString Cap::Cap_get_delete_terms(){return this->delete_terms ;}
QString Cap::Cap_get_assign_terms(){return this->assign_terms ;}
void Cap::Cap_set_manage_terms(QString manage_terms){this->manage_terms = manage_terms ;}
void Cap::Cap_set_edit_terms(QString edit_terms){this->edit_terms = edit_terms ;}
void Cap::Cap_set_delete_terms(QString delete_terms){this->delete_terms = delete_terms ;}
void Cap::Cap_set_assign_terms(QString assign_terms){this->assign_terms = assign_terms ;}
	
	//get size
int Cap::Cap_get_size(){return this->size ;}
void Cap::Cap_insert_db(){
	QStringList what;
	this->Cap_db->Database_select(this->tablename);
	int id = this->Cap_db->Database_num_rows();
	what<<QString::number(id++)<<this->manage_terms<<this->edit_terms \
	<<this->delete_terms<<this->assign_terms;
	this->Cap_db->Database_insert(this->tablename,what);
}

int Cap::Cap_get_id()
{
	this->Cap_db->Database_select(this->tablename);
	return this->Cap_db->Database_num_rows();
}
