/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#include "category.h"
Category::Category()
{
		this->tablename = "categories";
		this->size = 7;
		this->Category_db = new Database();
		Userblog user;
		QString host = user.Userblog_get_blog_host();
		QString path = user.Userblog_get_blog_path();
		int port = user.Userblog_get_blog_port();
		QString blogid = user.Userblog_get_blog_id();
		QString username = user.Userblog_get_blog_username();
		QString pass = user.Userblog_get_blog_password();
		this->Category_wp = new Wordpress(host,path,port,username,pass);
		this->Category_wp->Base_set_blog_id(blogid);
		
		connect(this->Category_wp,SIGNAL(Wordpress_OK(QVariant)),this,SLOT(Category_map_from_result(QVariant)));
		connect(this->Category_wp,SIGNAL(Wordpress_FAILED(int ,QString)),this,SLOT(Category_map_from_error(int ,QString)));

}
Category::~Category(){
delete this->Category_wp;
delete this->Category_db;	
}
void Category::Category_set_id(QString categoryid){this->categoryid = categoryid;}
void Category::Category_set_parentid(QString parentid){this->parentid = parentid;}
void Category::Category_set_name(QString categoryname){this->categoryname = categoryname;}
void Category::Category_set_categorydescripton(QString categorydescription){
this->categorydescription = categorydescription;}
void Category::Category_set_description(QString description){this->description = description ;}
void Category::Category_set_htmlurl(QString htmlurl){this->htmlurl = htmlurl;}
void Category::Category_set_rssurl(QString rssurl){this->rssurl = rssurl ;}
void Category::Category_set_all(QString categoryid,QString parentid ,QString categoryname,\
                        QString categorydescription,QString description,QString htmlurl,QString rssurl){
this->categoryid = categoryid;
this->parentid = parentid;
this->categoryname = categoryname;
this->categorydescription = categorydescription;
this->description = description ;
this->htmlurl = htmlurl;
this->rssurl = rssurl;
}
QString Category::Category_get_id(){return this->categoryid ;}
QString Category::Category_get_parentid(){return this->parentid ;}
QString Category::Category_get_name(){return this->categoryname ;}
QString Category::Category_get_categorydescripton(){return this->categorydescription ;}
QString Category::Category_get_description(){return this->description ;}
QString Category::Category_get_htmlurl(){return this->htmlurl ;}
QString Category::Category_get_rssurl(){return this->rssurl ;}

QStringList Category::Category_map_to_qstringlist(){
QStringList list;
list<<this->categoryid<<this->parentid<<this->categoryname<<this->categorydescription \
<<this->description<<this->htmlurl<<this->rssurl;
return list;
}

void Category::Category_get_category()
{
	this->Category_wp->Wordpress_getcategories();
}
//slots
void Category::Category_map_from_error(int err_code,QString err_msg){
		QMessageBox::critical(NULL,"Error",QString::number(err_code) + " => " + err_msg);
}
void Category::Category_map_from_result(QVariant result){
	QList<QStringList> list;
	list = MVariant(result).get_qlistqstringlist();
	QStringList what;
	this->Category_db->Database_select(this->tablename);
	int id = this->Category_db->Database_num_rows();
	int i = 0;
	while(i < list.size()){
		QList<QStringList> sublist = list.mid(i,this->size);
		foreach(QStringList item,sublist){
			if(item.at(0).compare("categoryId") == 0){
				this->categoryid = item.at(1);
			}
			if(item.at(0).compare("parentId") == 0){
				this->parentid = item.at(1);
			}
			if(item.at(0).compare("categoryName") == 0){
				this->categoryname = item.at(1);
			}
			if(item.at(0).compare("categoryDescription") == 0){
				this->categorydescription = item.at(1);
			}
			if(item.at(0).compare("description") == 0){
				this->description = item.at(1);
			}
			if(item.at(0).compare("htmlUrl") == 0){
				this->htmlurl = item.at(1);
			}
			if(item.at(0).compare("rssurl") == 0){
				this->rssurl = item.at(1);
			}
			
	        }
	        id++;
	        what<<QString::number(id)<<this->categoryid<<this->parentid<<this->categoryname\
	        <<this->categorydescription<<this->description<<this->htmlurl<<this->rssurl;
        	this->Category_db->Database_insert(this->tablename,what);
	        what.clear();
	        i = i + this->size;
        }
}

