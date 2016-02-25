/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#include "userblog.h"
Userblog::Userblog()
{
	this->Userblog_db = new Database();
	this->Userblog_wp = new Wordpress();
	connect(this->Userblog_wp,SIGNAL(Wordpress_OK(QVariant)),this,SLOT(Userblog_get_users_blogs_ok(QVariant)));
	connect(this->Userblog_wp,SIGNAL(Wordpress_FAILED(int ,QString)),this,SLOT(Userblog_get_users_blogs_failed(int ,QString)));
	this->Userblog_tablename = "userblog";
	this->Userblog_port = 80;
	this->Userblog_select_follow_id(1);
}
Userblog::~Userblog()
{
	delete this->Userblog_db;
	delete this->Userblog_wp;
}
void Userblog::Userblog_select_follow_id(int id){
        QStringList what;
	QStringList where;
	where<<"id = "+QString::number(id);
	 if(this->Userblog_db->Database_select(this->Userblog_tablename,what,where)){
		if(this->Userblog_db->Database_num_rows() == 0){
			QMessageBox::information(NULL,"Infomation","There no tag on database");
        	}else{
        		QStringList list = this->Userblog_db->Database_fetch_row(0);
			//0 is id
			this->Userblog_blogid = list.at(1);
			this->Userblog_blogname = list.at(2);
			this->Userblog_url = list.at(3);
			this->Userblog_xmlrpc = list.at(4);
			if(list.at(5).compare("1") == 0){
        			this->Userblog_isadmin = true;
			}else{
        			this->Userblog_isadmin = false;;
			}
			this->Userblog_username = list.at(6);
			this->Userblog_password = this->Userblog_base64_decode(list.at(7));
			this->Userblog_port = list.at(8).toInt();
		}
	 }else{
		 QMessageBox::critical(NULL,"Error","Database failed ,please try again !");
	 }	
}
QString Userblog::Userblog_get_blog_id(){return this->Userblog_blogid ;}
QString Userblog::Userblog_get_blog_name(){return this->Userblog_blogname ;}
QString Userblog::Userblog_get_blog_host(){return this->Userblog_url ;}
QString Userblog::Userblog_get_blog_path(){return this->Userblog_xmlrpc ;}
bool Userblog::Userblog_get_blog_is_admin(){return this->Userblog_isadmin ;}
QString Userblog::Userblog_get_blog_username(){return this->Userblog_username ;}
QString Userblog::Userblog_get_blog_password(){return this->Userblog_password ;}
int Userblog::Userblog_get_blog_port(){return this->Userblog_port ;}
void Userblog::Userblog_get_users_blogs_ok(QVariant result){
	QList<QStringList> list;
	list = MVariant(result).get_qlistqstringlist();
	QList<QVariant> items;
	foreach(QStringList item ,list){
		#if(XMLRPC_DEBUG)
		qDebug()<<"\n ITEM : "<<item<<" LINE: "<<__LINE__<<" FILE :"<<__FILE__;
		#endif
		if(item.at(0).compare("blogid") == 0){
			this->Userblog_blogid = item.at(1);
		}
		if(item.at(0).compare("blogName") == 0){
			this->Userblog_blogname = item.at(1);
		}
		if(item.at(0).compare("isAdmin") == 0){
			if(item.at(1).compare("true") == 0){
				this->Userblog_isadmin = true;
			}else{
				this->Userblog_isadmin = false;;
			}
		}
	}
	//count database
	QStringList what;
	this->Userblog_db->Database_select(this->Userblog_tablename);
	int id = this->Userblog_db->Database_num_rows();
	what<<QString::number(id+1)<<this->Userblog_blogid<<this->Userblog_blogname \
	<<this->Userblog_url<<this->Userblog_xmlrpc<<QString::number(this->Userblog_isadmin) \
	<<this->Userblog_username<<this->Userblog_base64_encode(this->Userblog_password) \
	<<QString::number(this->Userblog_port);
	this->Userblog_db->Database_insert(this->Userblog_tablename,what);	
}
void Userblog::Userblog_get_users_blogs_failed(int code ,QString msg){
	QMessageBox::critical(NULL,"Error",QString::number(code) + " => " + msg);
}
void Userblog::Userblog_add_new()
{
	//here add new blog
	//must get username ,password ,host ,path,port
	this->Userblog_url = "wordpress.lc";
	this->Userblog_xmlrpc = "/xmlrpc.php";
	this->Userblog_username = "pndhainam";
	this->Userblog_password = "143007444";
	this->Userblog_port = 80;
	this->Userblog_wp->Base_set_host(this->Userblog_url);
	this->Userblog_wp->Base_set_path(this->Userblog_xmlrpc);
	this->Userblog_wp->Base_set_port(this->Userblog_port);
	this->Userblog_wp->Base_set_username(this->Userblog_username);
	this->Userblog_wp->Base_set_password(this->Userblog_password);
	this->Userblog_wp->Base_init();
	this->Userblog_wp->Wordpress_getusersblogs();
}
QString Userblog::Userblog_base64_encode(QString string){
    QByteArray ba;
    ba.append(string);
    return ba.toBase64();
}
QString Userblog::Userblog_base64_decode(QString string){
    QByteArray ba;
    ba.append(string);
    return QByteArray::fromBase64(ba);
}
