/*
 *	@Package : WODPRESS XMLRPC 
 *  @Author : Pham Van Diep
 * 	@Contact : pndhainam@hotmail.com
 */

#ifndef __ADDBLOG_H
#define __ADDBLOG_H
#include "../ui_dlgaddblog.h"
#include "database.h"
#include "base.h"
#include "inc/debug.h"
class Addblog:public QDialog
{
Q_OBJECT
        public:
                Addblog(QWidget *parent = 0);
        public slots:
                void add();
                void cancel();
        private :
                Ui::dlg_add_blog ui;
                Database *db;

};

#endif
