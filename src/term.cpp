/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#include "term.h"

Term::Term(){
	Userblog user;
	QString host = user.Userblog_get_blog_host();
	QString path = user.Userblog_get_blog_path();
	int port = user.Userblog_get_blog_port();
	QString blogid = user.Userblog_get_blog_id();
	QString username = user.Userblog_get_blog_username();
	QString pass = user.Userblog_get_blog_password();
	this->tablename = "term";
	this->Term_db = new Database();
	this->Term_wp = new Wordpress(host,path,port,username,pass);
	this->Term_wp->Base_set_blog_id(blogid);
	//class have 14 variable
	this->size = 9;
	connect(this->Term_wp,SIGNAL(Wordpress_OK(QVariant)),this,SLOT(Term_get_term_ok(QVariant)));
	connect(this->Term_wp,SIGNAL(Wordpress_FAILED(int ,QString)),this,SLOT(Term_get_term_failed(int ,QString)));	
}
Term::~Term(){
		delete this->Term_wp;
		delete this->Term_db;
}
void Term::Term_get_term_ok(QVariant result){
	QList<QStringList> list = MVariant(result).get_qlistqstringlist();
	//QStringList what;
	this->Term_db->Database_select(this->tablename);
	//int id = this->Term_db->Database_num_rows();
	int i = 0;
	while(i < list.size()){
		QList<QStringList> sublist = list.mid(i,this->size);
		foreach(QStringList item,sublist){
			if(item.at(0).compare("count") == 0){
				this->count = item.at(1).toInt();
			}
			if(item.at(0).compare("description") == 0){
				this->description = item.at(1);
			}
			if(item.at(0).compare("name") == 0){
				this->name = item.at(1);
			}
			if(item.at(0).compare("parent") == 0){
				this->parent = item.at(1);
			}
			if(item.at(0).compare("slug") == 0){
				this->slug = item.at(1);
			}
			if(item.at(0).compare("taxonomy") == 0){
				this->taxonomy = item.at(1);
			}
			if(item.at(0).compare("term_group") == 0){
				this->term_group = item.at(1);
			}
			if(item.at(0).compare("term_id") == 0){
				this->term_id = item.at(1);
			}
			if(item.at(0).compare("term_taxonomy_id") == 0){
				this->term_taxonomy_id = item.at(1);
			}
		}
		this->Term_insert_db();
		i = i + this->size;
	}
}
void Term::Term_get_term_failed(int code ,QString msg){
		QMessageBox::critical(NULL,"Error",QString::number(code) + " : "+ msg);
}
	
QString Term::Term_get_term_id(){return this->term_id ;}
QString Term::Term_get_name(){return this->name ;}
QString Term::Term_get_slug(){return this->slug ;}
QString Term::Term_get_term_group(){return this->term_group ;}
QString Term::Term_get_term_taxonomy_id(){return this->term_taxonomy_id ;}
QString Term::Term_get_taxonomy(){return this->taxonomy ;}
QString Term::Term_get_decription(){return this->description ;}
QString Term::Term_get_parent(){return this->parent ;}
int Term::Term_get_count(){return this->count ;}
	
void Term::Term_set_term_id(QString term_id){this->term_id = term_id ;}
void Term::Term_set_name(QString name){this->name = name ;}
void Term::Term_set_slug(QString slug){this->slug = slug ;}
void Term::Term_set_term_group(QString term_group){this->term_group = term_group ;}
void Term::Term_set_term_taxonomy_id(QString term_taxonomy_id){this->term_taxonomy_id = term_taxonomy_id ;}
void Term::Term_set_taxonomy(QString taxonomy){this->taxonomy = taxonomy ;}
void Term::Term_set_decription(QString description){this->description = description ;}
void Term::Term_set_parent(QString parent){this->parent = parent ;}
void Term::Term_set_count(int count){this->count = count ;}
	
void Term::Term_insert_db(){
	QStringList what;
	this->Term_db->Database_select(this->tablename);
	int id = this->Term_db->Database_num_rows();
	id = id+1;
	what<<QString::number(id)<<this->term_id<<this->name<<this->slug \
	<<this->term_group<<this->term_taxonomy_id<<this->taxonomy \
	<<this->description<<this->parent<<QString::number(this->count);
	this->Term_db->Database_insert(this->tablename,what);	
}

void Term::Term_get_terms()
{
	QString tb_taxonomy = "taxonomy";
	this->Term_db->Database_select(tb_taxonomy);
	QStringList taxonomy = this->Term_db->Database_fetch_col_name("name");
	foreach(QString item ,taxonomy){
		this->Term_wp->Wordpress_getterms(item);
	}
}
