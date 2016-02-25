/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#include "media.h"

Media::Media(){
	this->tablename = "media";
	this->size = 9;
	this->Media_db = new Database();
	Userblog user;
	QString host = user.Userblog_get_blog_host();
	QString path = user.Userblog_get_blog_path();
	int port = user.Userblog_get_blog_port();
	QString blogid = user.Userblog_get_blog_id();
	QString username = user.Userblog_get_blog_username();
	QString pass = user.Userblog_get_blog_password();
	this->Media_wp = new Wordpress(host,path,port,username,pass);
	this->Media_wp->Base_set_blog_id(blogid);
		
	connect(this->Media_wp,SIGNAL(Wordpress_OK(QVariant)),this,SLOT(Media_get_media_ok(QVariant)));
	connect(this->Media_wp,SIGNAL(Wordpress_FAILED(int ,QString)),this,SLOT(Media_get_media_failed(int ,QString)));	
}
Media::~Media(){
delete this->Media_wp;
delete this->Media_db;	
}

void Media::Media_set_date_created_gmt(QString datecreatedgmt){this->datecreatedgmt = datecreatedgmt ;}
void Media::Media_set_parent(QString parent){this->parent = parent ;}
void Media::Media_set_link(QString link){this->link = link ;}
void Media::Media_set_thumbnail(QString thumbnail){this->thumbnail = thumbnail ;}
void Media::Media_set_title(QString title){this->title = title ;}
void Media::Media_set_caption(QString caption){this->caption = caption ;}
void Media::Media_set_description(QString description){this->description = description ;}
void Media::Media_set_metadata(QString metadata){this->metadata = metadata ;}
void Media::Media_set_attachmentid(QString attachmentid){this->attachmentid = attachmentid ;}
	
QString Media::Media_get_date_created_gmt(){return this->datecreatedgmt ;}
QString Media::Media_get_parent(){return this->parent ;}
QString Media::Media_get_link(){return this->link ;}
QString Media::Media_get_thumbnail(){return this->thumbnail ;}
QString Media::Media_get_title(){return this->title ;}
QString Media::Media_get_caption(){return this->caption ;}
QString Media::Media_get_description(){return this->description ;}
QString Media::Media_get_metadata(){return this->metadata ;}
QString Media::Media_get_attachmentid(){return this->attachmentid ;}
	
void Media::Media_get_media(){
QStringList filter;
this->Media_wp->Wordpress_getmedialibrary(filter);	
}
void Media::Media_get_media_failed(int code ,QString msg){
		QMessageBox::critical(NULL,"Error",QString::number(code) + " => " + msg);	
}
void Media::Media_get_media_ok(QVariant result){
	QList<QStringList> list ;
	list = MVariant(result).get_qlistqstringlist();
	QStringList what;
	this->Media_db->Database_select(this->tablename);
	int id = this->Media_db->Database_num_rows();
	int i = 0;
	while(i < list.size()){
		QList<QStringList> sublist = list.mid(i,this->size);
		foreach(QStringList item,sublist){
			if(item.at(0).compare("date_created_gmt") == 0){
				this->datecreatedgmt = item.at(1);
			}
			if(item.at(0).compare("parent") == 0){
				this->parent = item.at(1);
			}
			if(item.at(0).compare("link") == 0){
				this->link = item.at(1);
			}
			if(item.at(0).compare("thumbnail") == 0){
				this->thumbnail = item.at(1);
			}
			if(item.at(0).compare("title") == 0){
				this->title = item.at(1);
			}
			if(item.at(0).compare("caption") == 0){
				this->caption = item.at(1);
			}
			if(item.at(0).compare("description") == 0){
				this->description = item.at(1);
			}
			if(item.at(0).compare("metadata") == 0){
				this->metadata = item.at(1);
			}
			if(item.at(0).compare("attachment_id") == 0){
				this->attachmentid = item.at(1);
			}
			
		}
		id++;
		what<<QString::number(id)<<this->datecreatedgmt<<this->parent<<this->link\
		<<this->thumbnail<<this->title<<this->caption<<this->description \
		<<this->metadata<<this->attachmentid;
		this->Media_db->Database_insert(this->tablename,what);
		what.clear();
		i = i + this->size;
	}
}
	
