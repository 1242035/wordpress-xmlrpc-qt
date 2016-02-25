/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#include "page.h"
Page::Page(QString host,QString path ,int port ,QString username , QString password)
:Wordpress(host, path , port , username , password)
{
this->category = new Category();
this->custom_fields = new Postcustomfield();
connect(this,SIGNAL(Wordpress_OK()),this,SLOT(Page_map_from_result()));
connect(this,SIGNAL(Wordpress_FAILED()),this,SLOT(Page_map_from_error()));
}
Page::~Page(){
delete this->category;
delete this->custom_fields;
}
//set
void Page::Page_set_id(int id){this->page_id = id ;}
void Page::Page_set_title(QString title){this->title = title ;}
void Page::Page_set_date_created(QDateTime datecreated){this->date_created = datecreated ;}
void Page::Page_set_date_created_gmt(QDateTime datecreatedgmt){this->date_created_gmt = datecreatedgmt ;}
void Page::Page_set_status(QString status){this->status = status ;}
void Page::Page_set_slug(QString slug){this->slug = slug ;}
void Page::Page_set_user_id(int userid){this->user_id = userid ;}
void Page::Page_set_author_id(QString author_id){this->author_id = author_id ;}
void Page::Page_set_author(QString author){this->author = author ;}
void Page::Page_set_author_display_name(QString authordisplayname){this->author_display_name = authordisplayname ;}
void Page::Page_set_password(QString password){this->password = password ;}
void Page::Page_set_excerpt(QString excerpt){this->excerpt = excerpt ;}
void Page::Page_set_description(QString description){this->description = description ;}
void Page::Page_set_text_more(QString textmore){this->text_more = textmore ;}
void Page::Page_set_permalink(QString permalink){this->permalink = permalink ;}
void Page::Page_set_mt_allow_comments(int mt_allow_comments){this->mt_allow_comments = mt_allow_comments ;}
void Page::Page_set_mt_allow_pings(int mt_allow_pings){this->mt_allow_pings = mt_allow_pings ;}
void Page::Page_set_parent_id(int parent_id){this->parent_id = parent_id;}
void Page::Page_set_parent_title(QString parent_title){this->parent_title = parent_title ;}
void Page::Page_set_order(int page_order){this->order = page_order ;}
void Page::Page_set_template(QString page_template){this->page_template = page_template ;}
void Page::Page_set_category(Category *category){this->category = category ;}
void Page::Page_set_custom_fields(Postcustomfield *custom_fields){this->custom_fields = custom_fields ;}
//get
int Page::Page_get_id(){return this->page_id ;}
QString Page::Page_get_title(){return this->title ;}
QDateTime Page::Page_get_date_created(){return this->date_created ;}
QDateTime Page::Page_get_date_created_gmt(){return this->date_created_gmt ;}
QString Page::Page_get_status(){return this->status ;}
QString Page::Page_get_slug(){return this->slug ;}
int Page::Page_get_user_id(){return this->user_id ;}
QString Page::Page_get_author_id(){return this->author_id ;}
QString Page::Page_get_author(){return this->author ;}
QString Page::Page_get_author_display_name(){return this->author_display_name ;}
QString Page::Page_get_password(){return this->password ;}
QString Page::Page_get_excerpt(){return this->excerpt ;}
QString Page::Page_get_description(){return this->description ;}
QString Page::Page_get_text_more(){return this->text_more ;}
QString Page::Page_get_permalink(){return this->permalink ;}
int Page::Page_get_mt_allow_comments(){return this->mt_allow_comments ;}
int Page::Page_get_mt_allow_pings(){return this->mt_allow_pings ;}
int Page::Page_get_parent_id(){return this->parent_id ;}
QString Page::Page_get_parent_title(){return this->parent_title ;}
int Page::Page_get_order(){return this->order ;}
QString Page::Page_get_template(){return this->page_template ;}
Category* Page::Page_get_category(){return this->category ;}
Postcustomfield* Page::Page_get_custom_fields(){return this->custom_fields ;}

QStringList Page::Page_map_to_qstringlist(){
QStringList str_list;
str_list<<QString::number(this->page_id)<<this->title<<this->date_created.toString() \
<<this->date_created_gmt.toString()<<this->status<<this->slug<<QString::number(this->user_id) \
<<this->author_id<<this->author<<this->author_display_name<<this->password<<this->excerpt \
<<this->description<<this->text_more<<this->permalink<<QString::number(this->mt_allow_comments) \
<<QString::number(this->mt_allow_pings)<<QString::number(this->parent_id)<<this->parent_title \
<<QString::number(this->order)<<this->page_template \
<<this->category->Category_map_to_qstringlist() \
<<this->custom_fields->Postcustomfield_map_to_qstringlist();
return str_list;
}

//slot
void Page::Page_map_from_result(){}
void Page::Page_map_from_error(){}


