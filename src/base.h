/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#ifndef __BaseSE_H
#define __BaseSE_H
#include "inc/client.h"
#include "inc/debug.h"
#include <QTextStream>
#include <QMessageBox>
using namespace xmlrpc;
class Base:public QObject
{
        Q_OBJECT
        public :
                Base();
                Base(QString host,QString path ,int port ,QString username , QString password);
                virtual ~Base();
                void Base_init();
                void Base_sent_request(QString ,QStringList);
                void Base_sent_request(QString);
                void Base_set_host(QString host);
                void Base_set_path(QString path);
                void Base_set_port(int port);
                void Base_set_username(QString username);
                void Base_set_password(QString password);
                void Base_set_blog_id(QString blogid);
                void Base_set_blog_name(QString blogname);
        public slots:
                void Base_process_result( int id, QVariant res );
                void Base_process_failed( int id, int errcode,QString errstring);
        signals:
                void Base_OK(int id ,QVariant res);
                void Base_FAILED(int id, int errcode,QString errstring);
        private:
                xmlrpc::Client *Base_cl;
                QString Base_username;
                QString Base_password;
                QString Base_blog_id;
                QString Base_blog_name;
                QString Base_host;
                int Base_port;
                QString Base_path;
                QVariant Base_result;
                QStringList Base_params;
      
};
#endif
