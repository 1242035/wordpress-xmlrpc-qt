/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#ifndef __MYAPP_H
#define __MYAPP_H
#include "../ui_frmmain.h"
#include "wordpress.h"
#include "addblog.h"
#include "inc/debug.h"
class Myapp :  public  QMainWindow 
{
 Q_OBJECT
        public :
                Myapp(QString host,QString path ,int port ,QString username , QString password,QWidget *parent = 0);
                virtual ~Myapp();
                void MA_run(int MA_ui_id);
        public slots:
               // void WP_success(QVariant);
                //void WP_failt(int ,QString);
                
                //void action_exit();
                void MA_add_blog();
                void MA_delete_blog();
                void MA_help();
                void MA_close();

                void MA_post();
        private:
                Wordpress *WP;
                QStringList MA_ui_list;


};
#endif
