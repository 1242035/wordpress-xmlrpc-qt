/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#include "post.h"
Post::Post(){
	Userblog user;
	QString host = user.Userblog_get_blog_host();
	QString path = user.Userblog_get_blog_path();
	int port = user.Userblog_get_blog_port();
	QString blogid = user.Userblog_get_blog_id();
	QString username = user.Userblog_get_blog_username();
	QString pass = user.Userblog_get_blog_password();
	this->tablename = "post";
	this->Post_db = new Database();
	this->Post_wp = new Wordpress(host,path,port,username,pass);
	this->Post_wp->Base_set_blog_id(blogid);
	//class have 14 variable
	this->size = 26;
	connect(this->Post_wp,SIGNAL(Wordpress_OK(QVariant)),this,SLOT(Post_get_post_ok(QVariant)));
	connect(this->Post_wp,SIGNAL(Wordpress_FAILED(int ,QString)),this,SLOT(Post_get_post_failed(int ,QString)));

}
Post::~Post(){
		delete this->Post_wp;
		delete this->Post_db;
}
void Post::Post_get_post(int post_id){
		this->Post_wp->Wordpress_getpost(post_id);
}
void Post::Post_get_posts(){
		this->Post_wp->Wordpress_getposts();
}

void Post::Post_get_post_ok(QVariant result){
		QList<QStringList> list;
		list = MVariant(result).get_qlistqstringlist();
		qDebug()<<"\nPost GET_RESULT:"<<list;
}
void Post::Post_get_post_failed(int code,QString msg){
		QMessageBox::critical(NULL,"Error",QString::number(code) + " : " + msg);
}
