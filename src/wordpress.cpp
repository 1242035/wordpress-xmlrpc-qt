/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#include "wordpress.h"
#include <QMessageBox>
Wordpress::Wordpress():Base(){
connect(this,SIGNAL(Base_OK(int ,QVariant)),this,SLOT(Wordpress_ok(int ,QVariant)));
connect(this,SIGNAL(Base_FAILED(int ,int ,QString)),this,SLOT(Wordpress_failed(int ,int ,QString)));
//this->Wordpress_error_status = false;	
}
Wordpress::Wordpress(QString host,QString path ,int port ,QString username , QString password):
Base(host,path,port,username,password)
{
connect(this,SIGNAL(Base_OK(int ,QVariant)),this,SLOT(Wordpress_ok(int ,QVariant)));
connect(this,SIGNAL(Base_FAILED(int ,int ,QString)),this,SLOT(Wordpress_failed(int ,int ,QString)));
//this->Wordpress_error_status = false;
}
Wordpress::~Wordpress(){}
//wordpress class slots
void Wordpress::Wordpress_ok(int id ,QVariant result){
//this->Wordpress_error_status = false ;
Q_UNUSED(id);
emit Wordpress_OK(result);
}
void Wordpress::Wordpress_failed(int id,int error_code ,QString error_msg){
Q_UNUSED(id);
emit Wordpress_FAILED(error_code,error_msg);
}
void Wordpress::Wordpress_getpost(int post_id){
this->method = "wp.getPost";
this->params<<QString::number(post_id);
this->Base_sent_request(this->method,this->params);
}
void Wordpress::Wordpress_getpost(int post_id,QStringList fields){
this->method = "wp.getPost";
this->params<<QString::number(post_id);
for(int i = 0 ; i<fields.size() ;i++){
this->params<<fields.at(i);
}
this->Base_sent_request(this->method,this->params);
}
void Wordpress::Wordpress_getposts(){
this->method = "wp.getPosts";
this->Base_sent_request(this->method);
}
void Wordpress::Wordpress_getposts(QStringList filter){
this->method = "wp.getPosts";
for(int i = 0 ; i<filter.size() ;i++){
this->params<<filter.at(i);
}
this->Base_sent_request(this->method,this->params);
}
void Wordpress::Wordpress_getposts(QStringList filter ,QStringList fields){
this->method = "wp.getPosts";
for(int i = 0 ; i<filter.size() ;i++){
this->params<<filter.at(i);
}
for(int i = 0 ; i<fields.size() ;i++){
this->params<<fields.at(i);
}
this->Base_sent_request(this->method,this->params);
}
void Wordpress::Wordpress_newpost(QStringList content){
this->method = "wp.newPost";
for(int i = 0 ; i<content.size() ;i++){
this->params<<content.at(i);
}
this->Base_sent_request(this->method,this->params);
}
void Wordpress::Wordpress_editpost(int post_id ,QStringList content){
this->method = "wp.editPost";
this->params<<QString::number(post_id);
for(int i = 0 ; i<content.size() ;i++){
this->params<<content.at(i);
}
this->Base_sent_request(this->method,this->params);
}
void Wordpress::Wordpress_deletepost(int post_id){
this->method = "wp.deletePost";
this->params<<QString::number(post_id);
this->Base_sent_request(this->method,this->params);
}

void Wordpress::Wordpress_getposttype(QString post_type_name){
this->method = "wp.getPostType";
this->params<<post_type_name;
this->Base_sent_request(this->method,this->params);
}
void Wordpress::Wordpress_getposttype(QString post_type_name ,QStringList fields){
this->method = "wp.getPostType";
this->params<<post_type_name;
for(int i = 0 ; i<fields.size() ;i++){
this->params<<fields.at(i);
}
this->Base_sent_request(this->method,this->params);
}

void Wordpress::Wordpress_getposttypes(){
this->method = "wp.getPostTypes";
this->Base_sent_request(this->method,this->params);
}
void Wordpress::Wordpress_getposttypes(QStringList filter ){
this->method = "wp.getPostTypes";
for(int i = 0 ; i<filter.size() ;i++){
this->params<<filter.at(i);
}
this->Base_sent_request(this->method,this->params);
}
void Wordpress::Wordpress_getposttypes(QStringList filter ,QStringList fields){
this->method = "wp.getPostTypes";
for(int i = 0 ; i<filter.size() ;i++){
this->params<<filter.at(i);
}
for(int i = 0 ; i<fields.size() ;i++){
this->params<<fields.at(i);
}
this->Base_sent_request(this->method,this->params);
}

void Wordpress::Wordpress_getpostformats(){
this->method = "wp.getPostFormats";
this->Base_sent_request(this->method);
}
void Wordpress::Wordpress_getpostformats(QStringList filter){
this->method = "wp.getPostFormats";
for(int i = 0 ; i<filter.size() ;i++){
this->params<<filter.at(i);
}
this->Base_sent_request(this->method,this->params);
}


void Wordpress::Wordpress_getpoststatuslist(){
this->method = "wp.getPostStatusList";
this->Base_sent_request(this->method);
} 


void Wordpress::Wordpress_gettaxonomy(QString taxonomy){
this->method = "wp.getTaxonomy";
this->params<<taxonomy;
this->Base_sent_request(this->method,this->params);
}


void Wordpress::Wordpress_gettaxonomies(){
this->method = "wp.getTaxonomies";
this->Base_sent_request(this->method);
}

void Wordpress::Wordpress_getterm(QString taxonomy ,int term_id){
this->method = "wp.getTerm";
this->params<<taxonomy<<QString::number(term_id);
this->Base_sent_request(this->method,this->params);
}
void Wordpress::Wordpress_getterms(QString taxonomy){
this->method = "wp.getTerms";
this->params<<taxonomy;
this->Base_sent_request(this->method,this->params);
}
/*void Wordpress::Wordpress_getallterms(QStringList taxonomy){
this->method = "wp.getTerms";
foreach(QString item,taxonomy){
	this->params<<item;
}
this->Base_sent_request(this->method,this->params);
}*/
void Wordpress::Wordpress_getterms(QString taxonomy ,QStringList filter){
//thieu tham so
this->method = "wp.getTerms";
this->params<<taxonomy;
for(int i = 0 ;i< filter.size() ; i++){
this->params<<filter.at(i);
}
this->Base_sent_request(this->method,this->params);
}
void Wordpress::Wordpress_newterm(QStringList content){
this->method = "wp.newTerm";
for(int i = 0; i< content.size() ; i++){
this->params<<content.at(i);
}
this->Base_sent_request(this->method,this->params);
}

void Wordpress::Wordpress_editterm(int term_id ,QStringList content){
this->method = "wp.editTerm";
this->params<<QString::number(term_id);
for(int i = 0; i< content.size() ; i++){
this->params<<content.at(i);
}
this->Base_sent_request(this->method,this->params);
}
void Wordpress::Wordpress_deleteterm(QString taxonomy ,int term_id){
this->method = "wp.deleteTerm";
this->params<<taxonomy<<QString::number(term_id);
this->Base_sent_request(this->method,this->params);
} 
void Wordpress::Wordpress_getmediaitem(int attachment_id){
this->method = "wp.getMediaItem";
this->params<<QString::number(attachment_id);
this->Base_sent_request(this->method,this->params);
}
void Wordpress::Wordpress_getmedialibrary(){
this->method = "wp.getMediaLibrary";
this->Base_sent_request(this->method);
}
void Wordpress::Wordpress_getmedialibrary(QStringList filter){
this->method = "wp.getMediaLibrary";
for(int i = 0 ;i < filter.size() ; i++){
this->params<<filter.at(i);
}
this->Base_sent_request(this->method,this->params);
}
void Wordpress::Wordpress_uploadfile(QStringList data){
this->method = "wp.uploadFile";
for(int i = 0 ;i < data.size() ; i++){
this->params<<data.at(i);
}
this->Base_sent_request(this->method,this->params);

} 
void Wordpress::Wordpress_getcommentcount(int post_id){
this->method = "wp.getCommentCount";
this->params<<QString::number(post_id);
this->Base_sent_request(this->method,this->params);

}
void Wordpress::Wordpress_getcomment(int comment_id){
this->method = "wp.getComment";
this->params<<QString::number(comment_id);
this->Base_sent_request(this->method,this->params);
}

void Wordpress::Wordpress_getcomments(QStringList filter){
this->method = "wp.getComments";
for(int i = 0 ;i < filter.size() ; i++){
this->params<<filter.at(i);
}
this->Base_sent_request(this->method,this->params);
}

void Wordpress::Wordpress_newcomment(int post_id,QStringList comment){
this->method = "wp.newComment";
this->params<<QString::number(post_id);
for(int i = 0 ;i < comment.size() ; i++){
this->params<<comment.at(i);
}
this->Base_sent_request(this->method,this->params);
}
void Wordpress::Wordpress_editcomment(int comment_id ,QStringList comment){
this->method = "wp.editComment";
this->params<<QString::number(comment_id);
for(int i = 0 ;i < comment.size() ; i++){
this->params<<comment.at(i);
}
this->Base_sent_request(this->method,this->params);
}


void Wordpress::Wordpress_deletecomment(int comment_id){
this->method = "wp.deleteComment";
this->params<<QString::number(comment_id);
this->Base_sent_request(this->method,this->params);
}


void Wordpress::Wordpress_getcommentstatuslist(){
this->method = "wp.getCommentStatusList";
this->Base_sent_request(this->method);

} 

void Wordpress::Wordpress_getoptions(){
this->method = "wp.getOptions";
this->Base_sent_request(this->method);
}
void Wordpress::Wordpress_getoptions(QStringList option){
this->method = "wp.getOptions";
for(int i = 0;i < option.size() ;i++){
this->params<<option.at(i);
}
this->Base_sent_request(this->method,this->params);
}



void Wordpress::Wordpress_setoptions(){
this->method = "wp.setOptions";
this->Base_sent_request(this->method);
}
void Wordpress::Wordpress_setoptions(QStringList option){
this->method = "wp.setOptions";
for(int i = 0;i < option.size() ;i++){
this->params<<option.at(i);
}
this->Base_sent_request(this->method,this->params);
} 


void Wordpress::Wordpress_getusersblogs(){
this->method = "wp.getUsersBlogs";
this->Base_sent_request(this->method);
}

void Wordpress::Wordpress_getuser(int user_id){
this->method = "wp.getUser";
this->params<<QString::number(user_id);
this->Base_sent_request(this->method,this->params);
}
void Wordpress::Wordpress_getuser(int user_id,QStringList feilds){
this->method = "wp.getUser";
this->params<<QString::number(user_id);
for(int i = 0;i < feilds.size() ;i++){
this->params<<feilds.at(i);
}
this->Base_sent_request(this->method,this->params);
}

void Wordpress::Wordpress_getusers(){
this->method = "wp.getUsers";
this->Base_sent_request(this->method);
}
void Wordpress::Wordpress_getusers(QStringList filter){
this->method = "wp.getUsers";
for(int i = 0;i < filter.size() ;i++){
this->params<<filter.at(i);
}
this->Base_sent_request(this->method,this->params);
}
void Wordpress::Wordpress_getprofile(){
this->method = "wp.getProfile";
this->Base_sent_request(this->method);
}
void Wordpress::Wordpress_getprofile(QStringList feilds){
this->method = "wp.getProfile";
for(int i = 0;i < feilds.size() ;i++){
this->params<<feilds.at(i);
}
this->Base_sent_request(this->method,this->params);

}


void Wordpress::Wordpress_editprofile(QStringList content){
this->method = "wp.editProfile";
for(int i = 0;i < content.size() ;i++){
this->params<<content.at(i);
}
this->Base_sent_request(this->method,this->params);
}

void Wordpress::Wordpress_getauthors(){
this->method = "wp.getAuthors";
this->Base_sent_request(this->method);

} 


void Wordpress::Wordpress_getcategories(){
this->method = "wp.getCategories";
this->Base_sent_request(this->method);
}

void Wordpress::Wordpress_suggestcategories(QString category ,int max_results){
this->method = "wp.suggestCategories";
this->params<<category<<QString::number(max_results);
this->Base_sent_request(this->method,this->params);

}

void Wordpress::Wordpress_newcategory(QStringList category){
this->method = "wp.newCategory";
for (int i = 0; i < category.size(); ++i){
          this->params<<category.at(i).toLocal8Bit().constData();
}
this->Base_sent_request(this->method,this->params);

}
void Wordpress::Wordpress_deletecategory(int category_id){
this->method = "wp.deleteCategory";
this->params<<QString::number(category_id);
this->Base_sent_request(this->method,this->params);
} 

void Wordpress::Wordpress_gettags(){
this->method = "wp.getTags";
this->Base_sent_request(this->method);
} 
void Wordpress::Wordpress_getpage(int page_id){
this->method = "wp.getPage";
this->params<<QString::number(page_id);
this->Base_sent_request(this->method,this->params);
}
void Wordpress::Wordpress_getpages(){
this->method = "wp.getPages";
this->Base_sent_request(this->method);

}
void Wordpress::Wordpress_getpages(int max_pages = 100){
this->method = "wp.getPages";
this->params<<QString::number(max_pages);
this->Base_sent_request(this->method,this->params);
}

void Wordpress::Wordpress_getpagelist(){
this->method = "wp.getPageList";
this->Base_sent_request(this->method);
}

//chua lam
void Wordpress::Wordpress_newpage(){}

void Wordpress::Wordpress_editpage(int post_id,QStringList content ,bool publish){
this->method = "wp.editPage";
this->params<<QString::number(post_id);
for(int i = 0 ;i <content.size() ;i++){
        this->params<<content.at(i).toLocal8Bit().constData();
}
this->params<<QString::number(publish);
this->Base_sent_request(this->method,this->params);
}
void Wordpress::Wordpress_deletepage(int page_id){
this->params<<QString::number(page_id);
this->method = "wp.getPageStatusList";
this->Base_sent_request(this->method,this->params);
}


void Wordpress::Wordpress_getpagestatuslist(){
this->method = "wp.getPageStatusList";
this->Base_sent_request(this->method);
}

void Wordpress::Wordpress_getpagetemplates(){
this->method = "wp.getPageTemplates";
this->Base_sent_request(this->method);
}
