/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#ifndef __POST_H
#define __POST_H
#include "userblog.h"
#include "media.h"
#include "term.h"
#include "enclosure.h"
#include "postcustomfield.h"

class Post:public QObject
{
	Q_OBJECT
    private:
        QString post_id;
        QString post_title;
        QDateTime post_date;
        QDateTime post_date_gmt;
        QDateTime post_modified;
        QDateTime post_modified_gmt;
        QString post_status;
        QString post_type;
        QString post_format;
        QString post_name;
        QString post_author;
        QString post_password;
        QString post_excerpt;
        QString post_content;
        QString post_parent;
        QString post_mime_type;
        QString link;
        QString guid;
        int menu_order;
        QString comment_status;
        QString ping_status;
        bool sticky;
        Media post_thumbnail;
        Term *terms;//array
        Postcustomfield *custom_fields;//array 
        Enclosure enclosure;
        
        int size;
        QString tablename;
        Wordpress *Post_wp;
        Database *Post_db;
        
        public:
        Post();
        virtual ~Post();
        void Post_get_post(int post_id);
        void Post_get_posts();
		public slots:
		void Post_get_post_ok(QVariant);
		void Post_get_post_failed(int ,QString);
};
#endif
