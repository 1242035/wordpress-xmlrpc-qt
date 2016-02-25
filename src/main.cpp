/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#include <QApplication>
#include "wordpress.h"
#include "tag.h"
#include "userblog.h"
#include "option.h"
#include "comment.h"
#include "category.h"
#include "user.h"
#include "media.h"
#include "taxonomy.h"
#include "post.h"
#include "term.h"
//using namespace std;
int main ( int argc ,char **argv)
{

QApplication app(argc ,argv);
Term term;
term.Term_get_terms();
//Post post;
//post.Post_get_posts();
//Taxonomy t;
//t.Taxonomy_get_taxonomy();

//Media m;
//m.Media_get_media();
//User u;
//u.User_get_users();

//Category c;
//c.Category_get_category();
//Tag tag;
//tag.Tag_get_tag();

//Userblog user;
//user.Userblog_add_new();

//Comment cm;
//cm.Comment_get_all_comment();

//Option option;
//option.Option_get_option();
return app.exec();
}
