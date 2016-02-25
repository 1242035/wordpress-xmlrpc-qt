/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#ifndef __WORDPRESS_H
#define __WORDPRESS_H
#include <QUiLoader>
#include "base.h"
#include "database.h"
#include "inc/debug.h"
class Wordpress :  public Base
{
 Q_OBJECT
        public :
        Wordpress();
        Wordpress(QString host,QString path ,int port ,QString username , QString password);
        virtual ~Wordpress();

        //void Wordpress_insert_db();
        void Wordpress_getpost(int post_id);
        void Wordpress_getpost(int post_id,QStringList fields);
        void Wordpress_getposts();
        void Wordpress_getposts(QStringList filter);
        void Wordpress_getposts(QStringList filter ,QStringList fields);
        void Wordpress_newpost(QStringList content);
        void Wordpress_editpost(int post_id ,QStringList content);
        void Wordpress_deletepost(int post_id);
        void Wordpress_getposttype(QString post_type_name);
        void Wordpress_getposttype(QString post_type_name ,QStringList fields);
        void Wordpress_getposttypes();
        void Wordpress_getposttypes(QStringList filter );
        void Wordpress_getposttypes(QStringList filter ,QStringList fields);
        void Wordpress_getpostformats();
        void Wordpress_getpostformats(QStringList filter);
        void Wordpress_getpoststatuslist(); 
    //Taxonomies (for categories, tags, and custom taxonomies) - Added in WordPress 3.4
        void Wordpress_gettaxonomy(QString taxonomy);
        void Wordpress_gettaxonomies();
        void Wordpress_getterm(QString taxonomy ,int term_id);
        void Wordpress_getterms(QString taxonomy);
        //void Wordpress_getallterms(QStringList taxonomy);
        void Wordpress_getterms(QString taxonomy ,QStringList filter);
        void Wordpress_newterm(QStringList content);
        void Wordpress_editterm(int term_id ,QStringList content);
        void Wordpress_deleteterm(QString taxonomy ,int term_id); 
    //Media - Added in WordPress 3.1
        void Wordpress_getmediaitem(int attachment_id);
        void Wordpress_getmedialibrary();
        void Wordpress_getmedialibrary(QStringList filter);
        void Wordpress_uploadfile(QStringList data); 
    //Comments - Added in WordPress 2.7
        void Wordpress_getcommentcount(int post_id);
        void Wordpress_getcomment(int comment_id);
        void Wordpress_getcomments(QStringList filter);
        void Wordpress_newcomment(int post_id,QStringList comment);
        void Wordpress_editcomment(int comment_id ,QStringList comment);
        void Wordpress_deletecomment(int comment_id);
        void Wordpress_getcommentstatuslist(); 
    //Options - Added in WordPress 2.6
        void Wordpress_getoptions();
        void Wordpress_getoptions(QStringList option);
        void Wordpress_setoptions(); 
        void Wordpress_setoptions(QStringList option); 
    //Users
        void Wordpress_getusersblogs();
        void Wordpress_getuser(int user_id);
        void Wordpress_getuser(int user_id,QStringList feilds);
        void Wordpress_getusers();
        void Wordpress_getusers(QStringList filter);
        void Wordpress_getprofile();
        void Wordpress_getprofile(QStringList feilds);
        void Wordpress_editprofile(QStringList content);
        void Wordpress_getauthors(); 

    //Obsolete Components
    //Categories - use Taxonomies instead, with taxonomy='category'
        void Wordpress_getcategories();
        void Wordpress_suggestcategories(QString category ,int max_results);
        void Wordpress_newcategory(QStringList category);
        void Wordpress_deletecategory(int category_id); 
    //Tags - use Taxonomies instead, with taxonomy='post_tag'
        void Wordpress_gettags(); 
    //Pages - use Posts instead, with post_type='page'
        void Wordpress_getpage(int page_id);
        void Wordpress_getpages();
        void Wordpress_getpages(int max_pages);
        void Wordpress_getpagelist();
        void Wordpress_newpage();
        void Wordpress_editpage(int post_id,QStringList content ,bool publish);
        void Wordpress_deletepage(int page_id);
        void Wordpress_getpagestatuslist();
        void Wordpress_getpagetemplates();

        QString Wordpress_get_method();
        //QList<QStringList> Wordpress_get_result();
        //bool Wordpress_is_error();
        //int Wordpress_get_error_code();
        //QString Wordpress_get_error_message();
        //void Wordpress_map_result(QVariant);
        //QList<QStringList> Wordpress_parse_result(QVariant result);
        //QList<QStringList> Wordpress_parse_qvariantlist(QVariant params);
        //QList<QStringList> Wordpress_parse_qvariantmap(QVariant params);
        public slots:
        void Wordpress_ok(int ,QVariant);
        void Wordpress_failed(int ,int,QString);
        signals:
        //how to check signal emited to get result
        void Wordpress_OK(QVariant);
        void Wordpress_FAILED(int ,QString);
        private: 
        bool Wordpress_error_status;
        int Wordpress_error_code;
        QString Wordpress_error_msg;
        QStringList params;
        QString method;
       // QList<QStringList> Wordpress_result;
        //QList<QMap
};
#endif
